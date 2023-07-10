#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "the3.h"

int length(char* str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        
    }
    return i;
}
void addNode(Cache* cache,Media new_media,char* domain)
{
        DomainFreqNode* new_freq_node;
        int i;
        CacheNode* new_node;
        new_node = malloc(sizeof(struct CacheNode));
        new_node->prev = NULL;
        
        new_node->media.name = malloc((length(new_media.name)+1)*sizeof(char));
        new_node->media.size = new_media.size;
        for(i=0;new_media.name[i]!='\0';i++)
        {
                new_node->media.name[i] = new_media.name[i];
        }
        new_node->media.name[i] = '\0';
        new_node->domainFreqList = malloc(sizeof(struct DomainFreqList));
        new_freq_node = malloc(sizeof(struct DomainFreqNode));
        new_freq_node->name = malloc((length(domain)+1)*sizeof(char));
        for(i=0;domain[i]!='\0';i++)
        {
                new_freq_node->name[i] = domain[i];
        }
        new_freq_node->name[i] = '\0';
        new_freq_node->freq=1;
        new_freq_node->prev = NULL;
        new_freq_node->next = NULL;
        new_node->domainFreqList->head = new_freq_node;
        new_node->domainFreqList->tail = new_freq_node;
        if(cache->mediaCount!=0){
            new_node->next = cache->head;
            cache->head->prev = new_node;
            cache->head = new_node;
            cache->currentSize += new_media.size;
            cache->mediaCount++;
            }
        else
        {
            cache->head = new_node;
            cache->tail = new_node;
            new_node->next = NULL;
            new_node->prev = NULL;
            cache->currentSize += new_media.size;
            cache->mediaCount++;
            
        }
}


void domainSort(DomainFreqList* list)
{
    DomainFreqNode *curr = list->head;
    char* temp;
    int temp_freq,i=0;
    int changed=1;
    if(curr->next){
    while(changed)
    {
        curr = list->head;
        changed=0;
        while(curr->next!=NULL)
        {
            if(curr->freq < curr->next->freq)
            {
                changed = 1;
                temp = malloc((length(curr->name)+1)*sizeof(char));
                for(i=0;i<curr->name[i];i++)
                {
                    temp[i] = curr->name[i];
                }
                temp[i] = '\0';
                curr->name = malloc((length(curr->next->name)+1)*sizeof(char));
                for(i=0;i<curr->next->name[i];i++)
                {
                    curr->name[i] = curr->next->name[i];
                }
                curr->name[i] = '\0';
                curr->next->name = malloc((1+length(temp))*sizeof(char));
                for(i=0;i<temp[i];i++)
                {
                    curr->next->name[i] = temp[i];
                }
                curr->next->name[i] = '\0';
                temp_freq = curr->freq;
                curr->freq = curr->next->freq;
                curr->next->freq = temp_freq;
                
                
            }
            else if(curr->freq == curr->next->freq)
            {
                if(strcmp(curr->name,curr->next->name)>0)
                {
                    changed = 1;
                temp = malloc((length(curr->name)+1)*sizeof(char));
                for(i=0;i<curr->name[i];i++)
                {
                    temp[i] = curr->name[i];
                }
                temp[i] = '\0';
                curr->name = malloc((length(curr->next->name)+1)*sizeof(char));
                for(i=0;i<curr->next->name[i];i++)
                {
                    curr->name[i] = curr->next->name[i];
                }
                curr->name[i] = '\0';
                curr->next->name = malloc((1+length(temp))*sizeof(char));
                for(i=0;i<temp[i];i++)
                {
                    curr->next->name[i] = temp[i];
                }
                curr->next->name[i] = '\0';
                temp_freq = curr->freq;
                curr->freq = curr->next->freq;
                curr->next->freq = temp_freq;
                }
            }
            curr = curr->next;
        }
        
    }
    }
}

/*
    Create a cache by reading inputs from stdin
*/
Cache* createCache()
{
	int max_size,file_num,i=0,j=0,k=0,size_counter=0;
    struct Cache* new_cache;
    struct CacheNode* new_node; 
    char new_line[1000];
    char* token;
	struct CacheNode* previous_item;
    struct DomainFreqNode* new_freq_node;
	struct DomainFreqNode* prev_freq_node;
	scanf("%d %d\n",&max_size,&file_num);
    new_cache = malloc(sizeof(struct Cache));

    	for(i=0;i<file_num;i++)
    	{
        	fgets(new_line,1000,stdin);
		new_node = malloc(sizeof(struct CacheNode));
        	token = strtok(new_line," ");
    		j=0;
    	
    		new_node->domainFreqList = malloc(sizeof(struct DomainFreqList));
    		while(token!=NULL)
    		{
    			if(j==0)
    			{
    			    new_node->media.name = malloc((length(token)+1)*sizeof(char));
    				for(k=0;token[k]!='\0';k++)
                        {       
                            new_node->media.name[k] = token[k];
                        }
                    new_node->media.name[k] = '\0';
                
    			}
    			else if(j==1)
    			{
    			    size_counter += atoi(token);   
    				new_node->media.size = atoi(token);   
    			}
    			else if(j>1)                          
    			{
    				if(j%2==0)               
    				{		
    					new_freq_node = malloc(sizeof(struct DomainFreqNode));
    					new_freq_node->name = malloc((length(token)+1)*sizeof(char));
    					for(k=0;token[k]!='\0';k++)
                        {       
                            new_freq_node->name[k] = token[k];
                        }
                        new_freq_node->name[k] = '\0';

    				}
    				else
    				{
    					if(j==3)
    					{
    						new_freq_node->freq = atoi(token);
    						new_freq_node->prev = NULL;
    						new_node->domainFreqList->head = new_freq_node;
    						prev_freq_node = new_freq_node;
    					}
    					
    					else
    					{
    						new_freq_node->freq = atoi(token);
    						new_freq_node->prev = prev_freq_node;
    						prev_freq_node->next = new_freq_node;
    						prev_freq_node = new_freq_node;
    					}
    				}
    			}
    			token = strtok(NULL," ");
    			j++;
    		}
    		
    		new_freq_node->next=NULL;
    		new_node->domainFreqList->tail = new_freq_node;
    		if(i==0)
    		{
			new_node->prev = NULL;
    			new_cache->head = new_node;
			previous_item = new_node;
    
    		}
    		else if(i==file_num-1)
    		{
    			new_node->next = NULL;
    			new_node->prev = previous_item;
    			new_cache->tail = new_node;
			previous_item->next = new_node;
			previous_item = new_node;
    		}
		else
		{
		    new_node->prev = previous_item;
			previous_item->next = new_node;
			previous_item = new_node;
		}
		domainSort(new_node->domainFreqList);
		
            
    	}
	new_cache->currentSize = size_counter;
    	new_cache->mediaCount = file_num;
	new_cache->cacheLimit = max_size;
        return new_cache;
}

/*
    Prints cache information and its contents
*/
void printCache(Cache* cache)
{
    CacheNode* curr = cache->head;
        DomainFreqNode* item;
        if(cache->mediaCount == 0)
        {
                printf("The Cache is Empty\n");
        }
        else
        {
                printf("-------------- Cache Information --------------\n");
                printf("Cache Limit: %d KB\n",cache->cacheLimit);
                printf("Current Size: %d KB\n",cache->currentSize);
                printf("Media Count: %d\n",cache->mediaCount);
                printf("Cache Media Info:\n");
                for(;curr!=NULL;curr = curr->next)
                {
                        printf("\tName: %s\tSize: %d KB\n",curr->media.name,curr->media.size);
                        printf("\t------- Media Domain Frequencies -------\n");
                        item = curr->domainFreqList->head;
                        for(;item!=NULL;item = item->next)
                        {
                                printf("\t\tName: %s\tFreq: %d\n",item->name,item->freq);
                        }
                        printf("\t----------------------------------------\n");
                }
                printf("----------------------------------------------\n");
        }

}


/*
    Adds media to the cache
*/
CacheNode* addMediaRequest(Cache* cache, Media media, char* domain)
{
    int flag = 0;
    int flag2 = 0;
    int i;
    CacheNode* last=cache->tail;
    int last_size;
    CacheNode* changed_node;
    DomainFreqNode* freq_node;
    CacheNode* curr = cache->head;
    DomainFreqNode* new_domain;
    
    
    for(;curr!=NULL;curr = curr->next)
    {
            if(strcmp(curr->media.name,media.name)==0)
            {
                    changed_node = curr;
                    flag = 1;
                    break;
            }
    }
    if(flag==0)
    {
            addNode(cache,media,domain);
            if(cache->currentSize > cache->cacheLimit)
        {
                while(cache->currentSize>cache->cacheLimit)
                {
                        last_size = last->media.size;
                        cache->tail = cache->tail->prev;
                        cache->tail->next = NULL;
                        freq_node = last->domainFreqList->head;
                        for(;freq_node!=NULL;freq_node = freq_node->next)
                        {
                                free(freq_node->name);
                                free(freq_node);

                        }
                        free(last->media.name);
                        free(last);
                        cache->mediaCount--;
                        cache->currentSize -= last_size;
                        last = cache->tail;
                }
        }

    }
    else
    {
                if(changed_node==cache->head)
                {
                        for(freq_node=changed_node->domainFreqList->head;freq_node!=NULL;freq_node=freq_node->next)
                        {
                                if(strcmp(freq_node->name,domain)==0)
                                {
                                        flag2=1;
                                        freq_node->freq++;
                                        break;
                                }
                        }
                        if(flag2==0)
                        {
                            new_domain = malloc(sizeof(struct DomainFreqNode));
                            new_domain->name = malloc((length(domain)+1)*sizeof(char));
                            for(i=0;domain[i]!='\0';i++)
                            {
                                new_domain->name[i] = domain[i];
                            }
                            new_domain->name[i] = '\0';
                            new_domain->freq=1;
                            changed_node->domainFreqList->tail->next = new_domain;
                            new_domain->next = NULL;
                            new_domain->prev = changed_node->domainFreqList->tail;
                            changed_node->domainFreqList->tail = new_domain;
                        }
                        domainSort(changed_node->domainFreqList);
                }
                else
                {
                        if(changed_node->next!=NULL)
                        {

                                changed_node->prev->next = changed_node->next;
                                changed_node->next->prev = changed_node->prev;
                        }
                        else
                        {
                                changed_node->prev->next = NULL;
                                cache->tail = changed_node->prev;
                        }
                        changed_node->next = cache->head;
                        changed_node->prev=NULL;
                        cache->head->prev = changed_node;
                        cache->head = changed_node;
                        for(freq_node=changed_node->domainFreqList->head;freq_node!=NULL;freq_node=freq_node->next)
                        {
                                if(strcmp(freq_node->name,domain)==0)
                                {
                                        flag2=1;
                                        freq_node->freq++;
                                        break;
                                }
                        }
                        if(flag2==0)
                        {
                            new_domain = malloc(sizeof(struct DomainFreqNode));
                            new_domain->name = malloc((length(domain)+1)*sizeof(char));
                            for(i=0;domain[i]!='\0';i++)
                            {
                                new_domain->name[i] = domain[i];
                            }
                            new_domain->name[i] = '\0';
                            new_domain->freq=1;
                            changed_node->domainFreqList->tail->next = new_domain;
                            new_domain->next = NULL;
                            new_domain->prev = changed_node->domainFreqList->tail;
                            changed_node->domainFreqList->tail = new_domain;
                        }
                        domainSort(changed_node->domainFreqList);

                }

    }
 


    return NULL;
}

/*
    Finds the corresponding media's node in the cache
    Return NULL if it is not found
*/
CacheNode* findMedia(Cache* cache, char* name)
{
        CacheNode* curr = cache->head;
        for(;curr!=NULL;curr=curr->next)
        {
                if(strcmp(curr->media.name,name)==0) return curr;
        }

}

/*
    Finds a media from its name and deletes it's node from the cache
    Do not do anything if media is not found
*/
void deleteMedia(Cache* cache, char* name)
{
        CacheNode* dead = findMedia(cache,name);
        DomainFreqNode* curr;
        if(dead)
        {

                if(dead == cache->head && dead != cache->tail)
                {
                        cache->head = dead->next;
                        dead->next->prev = NULL;
                }
                else if(dead == cache->tail && dead != cache->head)
                {
                        cache->tail = dead->prev;
                        dead->prev->next = NULL;
                }
                else if (dead == cache->head && dead == cache->tail)
                {
                        cache->head = NULL;
                        cache->tail = NULL;
                }
                else
                {
                        dead->prev->next = dead->next;
                        dead->next->prev = dead->prev;
                }


                cache->mediaCount--;
                cache->currentSize -= dead->media.size;
                for(curr = dead->domainFreqList->head;curr!=NULL;curr=curr->next)
                {
                        free(curr->name);
                        free(curr);
                }
                free(dead->domainFreqList);
                free(dead->media.name);
                free(dead);
        }
        return;

}

