//
//  ViewController.m
//  learnText
//
//  Created by mc on 2019/10/30.
//  Copyright © 2019 mc. All rights reserved.
//

#import "ViewController.h"
#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>
#import <MediaPlayer/MediaPlayer.h>
#import <AVKit/AVKit.h>
#include "Node.hpp"

@interface ViewController ()<AVAudioPlayerDelegate>
@property(nonatomic, copy) NSString *str;
@property(nonatomic, strong) MPMoviePlayerController *moviePlayer;
@property(nonatomic, strong) AVPlayerViewController *avplayer;
@property(nonatomic, strong) AVPlayer *player;

@property(nonatomic, copy) NSString *aString;
@property(nonatomic, copy) NSMutableString *aMutableString;

@end


@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    //Thread 1: EXC_BAD_INSTRUCTION (code=EXC_I386_INVOP, subcode=0x0)
//    dispatch_sync(dispatch_get_main_queue(), ^{
//        NSLog(@"momo run");
//    });
    NodeClass::creatListNote();
    self.aString = @"aaaaaa";
    NSLog(@"aString----------%p",self.aString);
    NSString *a = [self.aString copy];
    NSLog(@"a----------------%p=====%p",a,&a);
    NSMutableString *aa = [self.aString mutableCopy];
    [aa appendFormat:@"cc"];
    NSLog(@"aa---------------%p=====%p",aa,&aa);
    self.aMutableString = [[[NSMutableString alloc] initWithString:@"bbbbbb"] mutableCopy];// [NSMutableString stringWithString:@"bbbbbbb"];
    NSLog(@"aMutableString----%p",self.aMutableString);
    NSString *aaa = [self.aMutableString copy];//不可变
    NSLog(@"aaa---------------%p=====%p",aaa,&aaa);
    
    NSMutableString *aaaa = [self.aMutableString mutableCopy];//可变的
    NSLog(@"aaaa--------------%p=====%p",aaaa,&aaaa);
    NSLog(@"hash====%tu",[aaaa hash]);
    
    // Do any additional setup after loading the view.
//    pthread_t
//
//    NSOperation *op = [[NSOperation alloc] init];
//    [op cancel];
//    [op isFinished];
//    op.dependencies;
//    int i = findSec(@[@1,@2,@3], 3);
//    NSLog(@"%d",i);
    self.view.backgroundColor = [UIColor redColor];
    NSString *str = [NSString stringWithFormat:@"%@",@"123"];
    self.str = str;
    NSLog(@"%@",str);
}


//////AudioToolBox.FrameWork
//- (void)audioTool {
//    SystemSoundID soundID = 0;
//    NSURL *url = [NSURL URLWithString:@""];
//    AudioServicesCreateSystemSoundID((__bridge CFURLRef)(url), &soundID);
////    AudioServicesAddSystemSoundCompletion(<#SystemSoundID inSystemSoundID#>, <#CFRunLoopRef  _Nullable inRunLoop#>, <#CFStringRef  _Nullable inRunLoopMode#>, <#AudioServicesSystemSoundCompletionProc  _Nonnull inCompletionRoutine#>, <#void * _Nullable inClientData#>)
//    AudioServicesPlaySystemSound(soundID);//播放音效
//    AudioServicesPlayAlertSound(soundID);//播放震动加音效
//}
//
/////AVAudioPlayer
//- (void)audioPlayer {
//    NSError *error;
//    //只支持本地路径
//    AVAudioPlayer *player = [[AVAudioPlayer alloc] initWithContentsOfURL:[NSURL URLWithString:@""] error:&error];
//    BOOL isprepared = [player prepareToPlay];
//    BOOL isPlay = [player play];
//    player.delegate = self;
//}
//
//- (void)audioPlayerDidFinishPlaying:(AVAudioPlayer *)player successfully:(BOOL)flag {
//    //音频播放完成
//}
//- (void)audioPlayerDecodeErrorDidOccur:(AVAudioPlayer *)player error:(NSError *)error {
//    //音频解码错误
//}
//
//- (void)avPlayer {
////    self.player addPeriodicTimeObserverForInterval:<#(CMTime)#> queue:<#(nullable dispatch_queue_t)#> usingBlock:<#^(CMTime time)block#>
//}
@end

