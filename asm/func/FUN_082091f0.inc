	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov sl, r0
	movs r1, #0x20
	adds r1, r1, r6
	mov r8, r1
	movs r2, #0
	mov sb, r2
	ldr r0, _0820921C @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r3, #0xb5
	lsls r3, r3, #1
	adds r0, r6, r3
	b _082094D8
	.align 2, 0
_0820921C: .4byte 0x03002B4C
_08209220:
	ldr r0, _08209254 @ =0x03002B4C
	ldr r0, [r0]
	mov r7, sb
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sl
	adds r0, #8
	adds r0, r0, r1
	ldr r7, [r0]
	mov r0, sl
	adds r1, r7, #0
	bl MsgQueue_BeginWait
	ldrb r0, [r7, #6]
	cmp r0, #0x29
	bls _08209248
	b _082094CA
_08209248:
	lsls r0, r0, #2
	ldr r1, _08209258 @ =_0820925C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08209254: .4byte 0x03002B4C
_08209258: .4byte _0820925C
_0820925C: @ jump table
	.4byte _08209304 @ case 0
	.4byte _0820930E @ case 1
	.4byte _08209326 @ case 2
	.4byte _08209382 @ case 3
	.4byte _082094CA @ case 4
	.4byte _082094CA @ case 5
	.4byte _082094CA @ case 6
	.4byte _082094CA @ case 7
	.4byte _082094CA @ case 8
	.4byte _082094CA @ case 9
	.4byte _0820949E @ case 10
	.4byte _082094CA @ case 11
	.4byte _082094CA @ case 12
	.4byte _082094CA @ case 13
	.4byte _082094CA @ case 14
	.4byte _082094CA @ case 15
	.4byte _082094CA @ case 16
	.4byte _082094CA @ case 17
	.4byte _082094CA @ case 18
	.4byte _082094CA @ case 19
	.4byte _0820933C @ case 20
	.4byte _082093C8 @ case 21
	.4byte _082093DE @ case 22
	.4byte _082093F4 @ case 23
	.4byte _0820940A @ case 24
	.4byte _0820940E @ case 25
	.4byte _08209424 @ case 26
	.4byte _0820944C @ case 27
	.4byte _08209488 @ case 28
	.4byte _0820948C @ case 29
	.4byte _082094CA @ case 30
	.4byte _082094CA @ case 31
	.4byte _082094CA @ case 32
	.4byte _082094CA @ case 33
	.4byte _082094CA @ case 34
	.4byte _082094CA @ case 35
	.4byte _082094CA @ case 36
	.4byte _082094CA @ case 37
	.4byte _082094CA @ case 38
	.4byte _082094CA @ case 39
	.4byte _082094CA @ case 40
	.4byte _082094B2 @ case 41
_08209304:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r0, [r6, #4]
	b _08209496
_0820930E:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #1
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	strb r0, [r6, #8]
	b _082094CA
_08209326:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #3
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _08209498
_0820933C:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #0x1b]
	movs r0, #2
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _08209498
_08209382:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #0x1b]
	movs r0, #0x10
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _08209498
_082093C8:
	movs r0, #0x11
	movs r1, #0
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	movs r0, #1
	strb r0, [r6, #8]
	mov r7, r8
	strh r1, [r7, #0x16]
	b _082094CA
_082093DE:
	movs r0, #0x14
	movs r1, #0
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	movs r0, #1
	strb r0, [r6, #8]
	mov r0, r8
	strh r1, [r0, #0x16]
	b _082094CA
_082093F4:
	movs r0, #0x12
	movs r1, #0
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	movs r0, #1
	strb r0, [r6, #8]
	mov r1, r8
	strh r0, [r1, #0x16]
	b _082094CA
_0820940A:
	movs r1, #0x13
	b _0820948E
_0820940E:
	movs r0, #0x14
	movs r1, #0
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	movs r0, #1
	strb r0, [r6, #8]
	mov r2, r8
	strh r0, [r2, #0x16]
	b _082094CA
_08209424:
	ldrh r1, [r7, #8]
	adds r0, r6, #0
	adds r0, #0x54
	movs r2, #0
	movs r3, #0
	strh r1, [r0]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	movs r0, #0x15
	strb r2, [r6, #2]
	strb r2, [r6, #3]
	strb r0, [r6, #4]
	str r3, [r6, #0x14]
	b _08209498
_0820944C:
	ldrh r0, [r7, #8]
	movs r2, #0
	movs r3, #0
	mov r1, r8
	strh r0, [r1, #0x10]
	ldrh r0, [r7, #0xa]
	strh r0, [r1, #0x12]
	ldrh r0, [r7, #0xc]
	strh r0, [r1, #0x14]
	ldrh r1, [r7, #0xe]
	adds r0, r6, #0
	adds r0, #0x54
	strh r1, [r0]
	ldrh r0, [r7, #0x10]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0x12]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	ldrh r0, [r7, #0x14]
	mov r7, r8
	strh r0, [r7, #0xe]
	movs r0, #0x16
	strb r2, [r6, #2]
	strb r2, [r6, #3]
	strb r0, [r6, #4]
	str r3, [r6, #0x14]
	b _08209498
_08209488:
	movs r1, #0x17
	b _0820948E
_0820948C:
	movs r1, #0x18
_0820948E:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r1, [r6, #4]
_08209496:
	str r0, [r6, #0x14]
_08209498:
	movs r0, #1
	strb r0, [r6, #8]
	b _082094CA
_0820949E:
	movs r0, #8
	ldrsh r1, [r7, r0]
	movs r3, #0xa
	ldrsh r2, [r7, r3]
	movs r0, #0xc
	ldrsh r3, [r7, r0]
	adds r0, r6, #0
	bl FUN_080415cc
	b _082094CA
_082094B2:
	ldrh r1, [r7, #8]
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x66
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x68
	strh r1, [r0]
_082094CA:
	movs r1, #1
	add sb, r1
	ldr r0, _082094F4 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sl
	adds r0, #6
_082094D8:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp sb, r0
	bge _082094E4
	b _08209220
_082094E4:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082094F4: .4byte 0x03002B4C
