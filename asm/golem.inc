	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08115324
FUN_08115324: @ 0x08115324
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	mov ip, r2
	ldr r7, [sp, #0x14]
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r6, [r0]
	movs r5, #0x1c
	ldrsh r2, [r1, r5]
	movs r5, #8
	ldrsh r0, [r4, r5]
	subs r2, r2, r0
	movs r0, #0x20
	ldrsh r1, [r1, r0]
	movs r5, #0xc
	ldrsh r0, [r4, r5]
	subs r1, r1, r0
	adds r0, r2, #0
	cmp r2, #0
	bge _08115350
	rsbs r0, r2, #0
_08115350:
	cmp r0, ip
	bhi _081153C4
	adds r0, r1, #0
	cmp r1, #0
	bge _0811535C
	rsbs r0, r1, #0
_0811535C:
	cmp r0, r3
	bhi _081153C4
	adds r3, r2, #0
	cmp r2, #0
	bge _08115368
	rsbs r3, r2, #0
_08115368:
	adds r0, r1, #0
	cmp r1, #0
	bge _08115370
	rsbs r0, r1, #0
_08115370:
	cmp r3, r0
	ble _08115378
	movs r1, #0
	b _0811537A
_08115378:
	movs r2, #0
_0811537A:
	adds r0, r2, #0
	bl FUN_0823785c
	ldr r1, _081153BC @ =0x000006C2
	adds r2, r6, r1
	strb r0, [r2]
	ldr r3, _081153C0 @ =0x085B0A08
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r7, r0
	asrs r0, r0, #0x10
	ldrh r1, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	asrs r0, r0, #0x10
	ldrh r5, [r4, #0x14]
	adds r0, r0, r5
	strh r0, [r4, #0x14]
	movs r0, #1
	b _0811543C
	.align 2, 0
_081153BC: .4byte 0x000006C2
_081153C0: .4byte 0x085B0A08
_081153C4:
	cmp r2, #0
	bne _081153CC
	cmp r1, #0
	beq _0811543A
_081153CC:
	adds r3, r2, #0
	cmp r2, #0
	bge _081153D4
	rsbs r3, r2, #0
_081153D4:
	adds r0, r1, #0
	cmp r1, #0
	bge _081153DC
	rsbs r0, r1, #0
_081153DC:
	cmp r3, r0
	ble _081153E4
	movs r1, #0
	b _081153E6
_081153E4:
	movs r2, #0
_081153E6:
	adds r0, r2, #0
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, _08115404 @ =0x000006C2
	adds r5, r6, r0
	ldrb r1, [r5]
	cmp r3, r1
	beq _08115408
	strb r3, [r4, #5]
	strb r3, [r5]
	movs r0, #1
	b _0811543C
	.align 2, 0
_08115404: .4byte 0x000006C2
_08115408:
	ldr r2, _08115444 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	asrs r0, r0, #0x10
	ldrh r1, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	asrs r0, r0, #0x10
	ldrh r1, [r4, #0x14]
	adds r0, r0, r1
	strh r0, [r4, #0x14]
	strb r3, [r4, #5]
	strb r3, [r5]
_0811543A:
	movs r0, #0
_0811543C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08115444: .4byte 0x085B0A08

	thumb_func_start FUN_08115448
FUN_08115448: @ 0x08115448
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	mov r8, r1
	movs r7, #1
	rsbs r7, r7, #0
	cmp r2, #1
	beq _08115474
	cmp r2, #1
	bgt _08115464
	cmp r2, #0
	beq _0811546E
	b _0811549C
_08115464:
	cmp r2, #2
	beq _08115488
	cmp r2, #3
	beq _0811548E
	b _0811549C
_0811546E:
	adds r4, #1
	movs r7, #2
	b _0811549C
_08115474:
	ldr r0, _08115484 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	b _0811549A
	.align 2, 0
_08115484: .4byte 0x030046A4
_08115488:
	subs r4, #1
	movs r7, #2
	b _0811549C
_0811548E:
	ldr r0, _081154AC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
_0811549A:
	movs r7, #1
_0811549C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081154B0
	adds r0, #4
	b _081154BC
	.align 2, 0
_081154AC: .4byte 0x030046A4
_081154B0:
	ldr r0, _081154D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081154BC:
	ldrb r0, [r0]
	movs r5, #0xf
	ands r5, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081154D8
	adds r0, #4
	b _081154E4
	.align 2, 0
_081154D4: .4byte 0x030046A4
_081154D8:
	ldr r0, _081154F8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081154E4:
	ldrb r0, [r0]
	lsrs r6, r0, #4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081154FC
	adds r0, #4
	b _08115508
	.align 2, 0
_081154F8: .4byte 0x030046A4
_081154FC:
	ldr r0, _08115518 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08115508:
	ldrh r0, [r0, #2]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0811551C
	cmp r5, r8
	bge _08115538
	b _08115544
	.align 2, 0
_08115518: .4byte 0x030046A4
_0811551C:
	mov r0, r8
	subs r1, r5, r0
	cmp r1, #1
	bne _08115528
	cmp r6, r7
	beq _08115540
_08115528:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08115534
	cmp r6, r7
	beq _08115540
_08115534:
	cmp r1, #0
	ble _0811553C
_08115538:
	movs r0, #1
	b _08115546
_0811553C:
	cmp r1, #0
	blt _08115544
_08115540:
	movs r0, #0
	b _08115546
_08115544:
	movs r0, #2
_08115546:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08115550
FUN_08115550: @ 0x08115550
	push {lr}
	adds r2, r0, #0
	cmp r1, #1
	beq _08115572
	cmp r1, #1
	bgt _08115562
	cmp r1, #0
	beq _0811556C
	b _08115598
_08115562:
	cmp r1, #2
	beq _08115578
	cmp r1, #3
	beq _0811558C
	b _08115598
_0811556C:
	ldrh r0, [r2]
	adds r0, #0xff
	b _0811557C
_08115572:
	ldrh r0, [r2, #4]
	adds r0, #0xff
	b _08115590
_08115578:
	ldrh r0, [r2]
	subs r0, #0xff
_0811557C:
	ldr r1, _08115588 @ =0xFFFFFF00
	ands r0, r1
	adds r0, #0x80
	strh r0, [r2]
	b _08115598
	.align 2, 0
_08115588: .4byte 0xFFFFFF00
_0811558C:
	ldrh r0, [r2, #4]
	subs r0, #0xff
_08115590:
	ldr r1, _0811559C @ =0xFFFFFF00
	ands r0, r1
	adds r0, #0x80
	strh r0, [r2, #4]
_08115598:
	pop {r0}
	bx r0
	.align 2, 0
_0811559C: .4byte 0xFFFFFF00

	thumb_func_start FUN_081155a0
FUN_081155a0: @ 0x081155A0
	ldrh r3, [r0]
	ldr r2, _081155C0 @ =0xFFFFFF00
	adds r1, r2, #0
	ands r1, r3
	adds r1, #0x80
	strh r1, [r0]
	ldrh r3, [r0, #2]
	adds r1, r2, #0
	ands r1, r3
	adds r1, #0x80
	strh r1, [r0, #2]
	ldrh r1, [r0, #4]
	ands r2, r1
	adds r2, #0x80
	strh r2, [r0, #4]
	bx lr
	.align 2, 0
_081155C0: .4byte 0xFFFFFF00

	thumb_func_start FUN_081155c4
FUN_081155c4: @ 0x081155C4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r0, #0
	mov sb, r6
	mov r8, r6
	ldr r0, _08115630 @ =0x000004A4
	adds r4, r6, r0
	ldr r0, [r4]
	adds r1, r6, #0
	adds r1, #8
	movs r3, #0xda
	lsls r3, r3, #3
	adds r2, r6, r3
	bl FUN_08235f40
	adds r1, r0, #0
	cmp r1, #0
	bne _081155F0
	b _08115780
_081155F0:
	ldr r1, [r4]
	movs r4, #0x1c
	ldrsh r2, [r1, r4]
	movs r5, #8
	ldrsh r0, [r6, r5]
	subs r7, r2, r0
	movs r0, #0x20
	ldrsh r2, [r1, r0]
	movs r3, #0xc
	ldrsh r0, [r6, r3]
	subs r2, r2, r0
	ldrh r0, [r1, #0x1c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _0811562A
	cmp r1, #0
	blt _0811562A
	ldr r0, _08115634 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _0811562A
	ldr r0, _08115638 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811563C
_0811562A:
	movs r4, #0
	mov ip, r4
	b _0811564C
	.align 2, 0
_08115630: .4byte 0x000004A4
_08115634: .4byte 0x030046A8
_08115638: .4byte 0x030046AC
_0811563C:
	ldr r0, _08115678 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r3
	mov ip, r0
_0811564C:
	mov r5, r8
	ldrh r1, [r5, #8]
	lsls r0, r1, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r5, #0xc]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	adds r5, r1, #0
	cmp r4, #0
	blt _08115674
	cmp r3, #0
	blt _08115674
	ldr r0, _0811567C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _08115674
	ldr r0, _08115680 @ =0x030046AC
	ldr r0, [r0]
	cmp r3, r0
	blo _08115684
_08115674:
	movs r0, #0
	b _08115692
	.align 2, 0
_08115678: .4byte 0x030046A4
_0811567C: .4byte 0x030046A8
_08115680: .4byte 0x030046AC
_08115684:
	ldr r0, _081156BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r3, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r4
_08115692:
	cmp ip, r0
	beq _081156DA
	adds r1, r7, #0
	cmp r7, #0
	bge _0811569E
	rsbs r1, r7, #0
_0811569E:
	adds r0, r2, #0
	cmp r2, #0
	bge _081156A6
	rsbs r0, r2, #0
_081156A6:
	cmp r1, r0
	bge _081156C8
	ldr r0, _081156C0 @ =0x000004A4
	add r0, sb
	ldr r1, [r0]
	ldr r0, _081156C4 @ =0xFFFFFF00
	ands r0, r5
	adds r0, #0x80
	strh r0, [r1, #0x1c]
	b _081156DA
	.align 2, 0
_081156BC: .4byte 0x030046A4
_081156C0: .4byte 0x000004A4
_081156C4: .4byte 0xFFFFFF00
_081156C8:
	ldr r0, _08115774 @ =0x000004A4
	add r0, sb
	ldr r2, [r0]
	mov r0, r8
	ldrh r1, [r0, #0xc]
	ldr r0, _08115778 @ =0xFFFFFF00
	ands r0, r1
	adds r0, #0x80
	strh r0, [r2, #0x20]
_081156DA:
	ldr r5, _08115774 @ =0x000004A4
	add r5, sb
	ldr r2, [r5]
	movs r3, #0x1c
	ldrsh r1, [r2, r3]
	mov r4, r8
	movs r3, #8
	ldrsh r0, [r4, r3]
	subs r7, r1, r0
	movs r4, #0x20
	ldrsh r1, [r2, r4]
	mov r2, r8
	movs r3, #0xc
	ldrsh r0, [r2, r3]
	subs r2, r1, r0
	adds r0, r7, #0
	adds r1, r2, #0
	bl FUN_0823785c
	ldr r4, _0811577C @ =0x000006C2
	adds r7, r6, r4
	strb r0, [r7]
	ldrb r0, [r7]
	adds r0, #0x20
	movs r6, #0xff
	ands r0, r6
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r7]
	mov r4, sp
	mov r3, sb
	adds r3, #8
	ldr r0, [r5]
	adds r2, r0, #0
	adds r2, #0x1c
	ldrh r0, [r0, #0x1c]
	mov r5, sb
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl FUN_0823785c
	adds r2, r0, #0
	adds r0, #0x20
	ands r0, r6
	asrs r2, r0, #6
	mov r0, sp
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r5, #4
	ldrsh r0, [r4, r5]
	cmn r1, r0
	beq _08115786
	ldrb r0, [r7]
	lsrs r0, r0, #6
	cmp r2, r0
	beq _08115786
	mov r0, sb
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08115786
	.align 2, 0
_08115774: .4byte 0x000004A4
_08115778: .4byte 0xFFFFFF00
_0811577C: .4byte 0x000006C2
_08115780:
	ldr r2, _08115798 @ =0x000006B4
	adds r0, r6, r2
	strh r1, [r0]
_08115786:
	movs r0, #1
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08115798: .4byte 0x000006B4

	thumb_func_start FUN_0811579c
FUN_0811579c: @ 0x0811579C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r5, [r0]
	ands r5, r1
	cmp r5, #0
	beq _08115804
	ldr r3, _081157F8 @ =0x000001DF
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _081157C8
	movs r0, #4
	ldr r6, _081157FC @ =0x00000222
	adds r2, r4, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081157C8:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r3, #0x93
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r1, [r0]
	ldr r6, _08115800 @ =0x0000024E
	adds r0, r4, r6
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0811585C
	adds r0, r4, #0
	bl FUN_08115ce0
	b _0811584C
	.align 2, 0
_081157F8: .4byte 0x000001DF
_081157FC: .4byte 0x00000222
_08115800: .4byte 0x0000024E
_08115804:
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	ldr r3, _08115864 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	ldr r6, _08115868 @ =0x0000046A
	adds r0, r4, r6
	strb r5, [r0]
	adds r2, #0x1c
	adds r0, r4, r2
	str r5, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r1, [r0]
	ldr r3, _0811586C @ =FUN_080e48d0
	movs r2, #0x10
	adds r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _08115870 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r6, #0xe6
	adds r0, r4, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r5, [r0]
_0811584C:
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0811585C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08115864: .4byte 0x00000469
_08115868: .4byte 0x0000046A
_0811586C: .4byte FUN_080e48d0
_08115870: .4byte 0x0000046B

	thumb_func_start FUN_08115874
FUN_08115874: @ 0x08115874
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08115894
	b _08115AEC
_08115894:
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r7, _08115960 @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _08115964 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r2, [r0]
	ldr r3, _08115968 @ =FUN_080e6794
	movs r1, #0xe
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _0811596C @ =0x0000046B
	adds r0, r5, r2
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r7, #0
	strh r4, [r0]
	movs r3, #0x80
	mov ip, r3
	ldrh r0, [r6]
	ands r0, r3
	cmp r0, #0
	beq _08115988
	ldr r4, _08115970 @ =0x00000482
	adds r1, r5, r4
	movs r0, #2
	strh r0, [r1]
	movs r0, #4
	ldr r1, _08115974 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, [r0]
	movs r4, #0xc
	mov r8, r4
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r5, r0
	ldr r4, _08115978 @ =0x00000554
	adds r0, r5, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _0811597C @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _08115980 @ =0x00000552
	adds r0, r5, r3
	mov r4, r8
	strb r4, [r0]
	ldrh r0, [r6]
	mov r6, ip
	ands r0, r6
	cmp r0, #0
	beq _081159CC
	ldr r7, _08115984 @ =0x0000024E
	adds r2, r5, r7
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r5, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _081159CC
	strh r1, [r2]
	b _081159CC
	.align 2, 0
_08115960: .4byte 0x00000469
_08115964: .4byte 0x0000046A
_08115968: .4byte FUN_080e6794
_0811596C: .4byte 0x0000046B
_08115970: .4byte 0x00000482
_08115974: .4byte 0x00000222
_08115978: .4byte 0x00000554
_0811597C: .4byte 0x00000551
_08115980: .4byte 0x00000552
_08115984: .4byte 0x0000024E
_08115988:
	movs r2, #0x10
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08115A08 @ =0x00000482
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r5, r6
	subs r6, #4
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _08115A0C @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _08115A10 @ =0x00000552
	adds r0, r5, r3
	strb r4, [r0]
_081159CC:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r6, [r0]
	adds r2, r5, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08115A04
	cmp r1, #0
	blt _08115A04
	ldr r0, _08115A14 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08115A04
	ldr r0, _08115A18 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08115A1C
_08115A04:
	movs r4, #0
	b _08115A2A
	.align 2, 0
_08115A08: .4byte 0x00000482
_08115A0C: .4byte 0x00000551
_08115A10: .4byte 0x00000552
_08115A14: .4byte 0x030046A8
_08115A18: .4byte 0x030046AC
_08115A1C:
	ldr r0, _08115A3C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08115A2A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08115A40
	adds r0, #4
	b _08115A4C
	.align 2, 0
_08115A3C: .4byte 0x030046A4
_08115A40:
	ldr r0, _08115A60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08115A4C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08115A64
	cmp r3, #2
	beq _08115A68
	b _08115A6C
	.align 2, 0
_08115A60: .4byte 0x030046A4
_08115A64:
	ldrb r0, [r6, #4]
	b _08115A6A
_08115A68:
	ldrb r0, [r6]
_08115A6A:
	subs r2, r2, r0
_08115A6C:
	movs r1, #0
	strh r2, [r6, #2]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r0, [r0]
	strh r1, [r0, #6]
	ldr r7, _08115AA8 @ =0x000004A4
	adds r0, r5, r7
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08115AAC
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _08115AD2
	.align 2, 0
_08115AA8: .4byte 0x000004A4
_08115AAC:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08115ACC
	cmp r0, #2
	beq _08115AC8
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08115AC8:
	movs r0, #1
	b _08115ADC
_08115ACC:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_08115AD2:
	ldr r1, _08115AF8 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08115ADC:
	cmp r0, #0
	bne _08115AEC
	ldr r4, _08115AFC @ =0x000005C4
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_08115AEC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08115AF8: .4byte 0xFFFFFDFF
_08115AFC: .4byte 0x000005C4

	thumb_func_start FUN_08115b00
FUN_08115b00: @ 0x08115B00
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08115B38
	cmp r1, #0
	blt _08115B38
	ldr r0, _08115B3C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08115B38
	ldr r0, _08115B40 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08115B44
_08115B38:
	movs r4, #0
	b _08115B52
	.align 2, 0
_08115B3C: .4byte 0x030046A8
_08115B40: .4byte 0x030046AC
_08115B44:
	ldr r0, _08115B64 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08115B52:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08115B68
	adds r0, #4
	b _08115B74
	.align 2, 0
_08115B64: .4byte 0x030046A4
_08115B68:
	ldr r0, _08115BB4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08115B74:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _08115BAE
	ldr r1, _08115BB8 @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	adds r1, r5, #0
	adds r1, #8
	movs r2, #0xec
	lsls r2, r2, #1
	adds r4, r5, r2
	ldr r2, [r4]
	adds r2, #8
	bl FUN_0823599c
	cmp r0, #0
	beq _08115BAE
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r4]
	ldr r2, [r1, #0xc]
	ldr r1, [r1, #8]
	str r1, [r0]
	str r2, [r0, #4]
	bl FUN_081155a0
_08115BAE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08115BB4: .4byte 0x030046A4
_08115BB8: .4byte 0x000004A4

	thumb_func_start FUN_08115bbc
FUN_08115bbc: @ 0x08115BBC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08115BEE
	cmp r1, #0
	blt _08115BEE
	ldr r0, _08115BF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08115BEE
	ldr r0, _08115BF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08115BFC
_08115BEE:
	movs r4, #0
	b _08115C0A
	.align 2, 0
_08115BF4: .4byte 0x030046A8
_08115BF8: .4byte 0x030046AC
_08115BFC:
	ldr r0, _08115C1C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08115C0A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08115C20
	adds r0, #4
	b _08115C2C
	.align 2, 0
_08115C1C: .4byte 0x030046A4
_08115C20:
	ldr r0, _08115C70 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08115C2C:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _08115C6A
	ldr r1, _08115C74 @ =0x000004A4
	adds r0, r6, r1
	ldr r0, [r0]
	adds r1, r6, #0
	adds r1, #8
	adds r2, r5, #0
	bl FUN_0823599c
	cmp r0, #0
	beq _08115C6A
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r5]
	ldr r2, [r5, #4]
	str r1, [r0]
	str r2, [r0, #4]
	bl FUN_081155a0
	movs r2, #0x80
	lsls r2, r2, #0xc
	ldr r0, _08115C78 @ =0x0000065C
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08115C6A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08115C70: .4byte 0x030046A4
_08115C74: .4byte 0x000004A4
_08115C78: .4byte 0x0000065C

	thumb_func_start FUN_08115c7c
FUN_08115c7c: @ 0x08115C7C
	push {lr}
	adds r2, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r3, _08115C9C @ =0x0000065C
	adds r0, r0, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08115CA0
	movs r0, #1
	b _08115CA2
	.align 2, 0
_08115C9C: .4byte 0x0000065C
_08115CA0:
	movs r0, #0
_08115CA2:
	cmp r0, #0
	bne _08115CD6
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08115CD6
	ldr r0, _08115CDC @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08115CD6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08115CD6
	adds r0, r2, #0
	bl FUN_08115b00
_08115CD6:
	pop {r0}
	bx r0
	.align 2, 0
_08115CDC: .4byte 0x03002BE0

	thumb_func_start FUN_08115ce0
FUN_08115ce0: @ 0x08115CE0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08115D44 @ =0x0825200C
	movs r2, #0x86
	lsls r2, r2, #2
	bl FUN_080e6768
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08115D48 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	ldr r5, _08115D4C @ =0x0000046A
	adds r0, r4, r5
	strb r2, [r0]
	ldr r1, _08115D50 @ =0x00000484
	adds r0, r4, r1
	str r2, [r0]
	adds r3, #3
	adds r0, r4, r3
	movs r1, #1
	strb r1, [r0]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r4, r5
	ldr r3, [r0]
	ldr r5, _08115D54 @ =0x0000046D
	adds r0, r4, r5
	strb r1, [r0]
	subs r5, #2
	adds r0, r4, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r4, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r4, r4, r3
	strh r2, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08115D44: .4byte 0x0825200C
_08115D48: .4byte 0x00000469
_08115D4C: .4byte 0x0000046A
_08115D50: .4byte 0x00000484
_08115D54: .4byte 0x0000046D

	thumb_func_start FUN_08115d58
FUN_08115d58: @ 0x08115D58
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xb
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #6
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #7
	movs r2, #5
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #6
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #7
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #8
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08115dd8
FUN_08115dd8: @ 0x08115DD8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r5, #0
	strb r5, [r0]
	ldr r1, _08115EC4 @ =0x0000065C
	adds r0, r4, r1
	str r5, [r0]
	adds r2, #0x58
	adds r0, r4, r2
	str r5, [r0]
	adds r1, #0x5a
	adds r0, r4, r1
	movs r1, #0
	strh r5, [r0]
	adds r2, #4
	adds r0, r4, r2
	strh r5, [r0]
	adds r2, #4
	adds r0, r4, r2
	strh r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #8
	bl ClearMemory
	movs r2, #0xda
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r1, #8
	bl ClearMemory
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #8
	bl ClearMemory
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r1, #8
	bl ClearMemory
	movs r1, #0xdc
	lsls r1, r1, #3
	adds r0, r4, r1
	strh r5, [r0]
	ldr r2, _08115EC8 @ =0x000006E2
	adds r4, r4, r2
	strh r5, [r4]
	adds r0, r6, #0
	bl FUN_080e6204
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08115ECC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08115ED4
	.align 2, 0
_08115EC4: .4byte 0x0000065C
_08115EC8: .4byte 0x000006E2
_08115ECC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08115ED4:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08115EF8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08115F00
_08115EF8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08115F00:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08115F38 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08115F70
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08115F3C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08115F30
	ldrb r0, [r4, #5]
_08115F30:
	subs r0, #1
	strh r0, [r4, #8]
	b _08115F4C
	.align 2, 0
_08115F38: .4byte 0x0000FFFF
_08115F3C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08115F4C
	strh r1, [r4, #8]
_08115F4C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08115F70
	movs r0, #1
	strb r0, [r4, #7]
_08115F70:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08115f78
FUN_08115f78: @ 0x08115F78
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #3
	rsbs r2, r2, #0
	ldr r1, [r0]
	ands r1, r2
	str r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08115f8c
FUN_08115f8c: @ 0x08115F8C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r4, _08115FB0 @ =0x00000256
	adds r0, r5, r4
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08115FB4
	adds r0, #4
	b _08115FC0
	.align 2, 0
_08115FB0: .4byte 0x00000256
_08115FB4:
	ldr r0, _08115FE0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08115FC0:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #0
	beq _08116002
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq _08115FEC
	cmp r0, #1
	bgt _08115FE4
	cmp r0, #0
	beq _08115FF4
	b _08115FFA
	.align 2, 0
_08115FE0: .4byte 0x030046A4
_08115FE4:
	cmp r0, #3
	beq _08115FEC
	cmp r0, #5
	bne _08115FFA
_08115FEC:
	movs r2, #0xa0
	lsls r2, r2, #1
	movs r3, #0xb
	b _08116036
_08115FF4:
	movs r2, #0xa0
	movs r3, #5
	b _08116036
_08115FFA:
	movs r2, #0x80
	lsls r2, r2, #1
	movs r3, #8
	b _08116036
_08116002:
	movs r4, #0x90
	lsls r4, r4, #3
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, #1
	beq _08116020
	cmp r0, #1
	bgt _08116018
	cmp r0, #0
	beq _08116028
	b _08116030
_08116018:
	cmp r0, #3
	beq _08116020
	cmp r0, #5
	bne _08116030
_08116020:
	movs r2, #0xe0
	lsls r2, r2, #1
	movs r3, #0x16
	b _08116036
_08116028:
	movs r2, #0xa0
	lsls r2, r2, #1
	movs r3, #0xa
	b _08116036
_08116030:
	movs r2, #0xc0
	lsls r2, r2, #1
	movs r3, #0x10
_08116036:
	ldr r0, _0811604C @ =0x000006B6
	adds r1, r6, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, r2
	bge _08116050
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	b _08116052
	.align 2, 0
_0811604C: .4byte 0x000006B6
_08116050:
	strh r2, [r1]
_08116052:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08116058
FUN_08116058: @ 0x08116058
	push {lr}
	adds r2, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08116082
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r1, [r0]
	adds r0, r2, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _08116084
_08116082:
	movs r0, #0
_08116084:
	pop {r1}
	bx r1

	thumb_func_start FUN_08116088
FUN_08116088: @ 0x08116088
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	adds r4, r3, #0
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	bne _081160D8
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r3, #8]
	cmp r0, #7
	bhi _081160BC
	ldr r0, _081160B8 @ =0x085AD5F8
	ldrh r1, [r3, #8]
	b _081160CC
	.align 2, 0
_081160B8: .4byte 0x085AD5F8
_081160BC:
	subs r0, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _081160D8
	ldr r0, _081160D4 @ =0x085AD5F8
	ldrh r1, [r4, #8]
	subs r1, #8
_081160CC:
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	b _081160DA
	.align 2, 0
_081160D4: .4byte 0x085AD5F8
_081160D8:
	movs r0, #0
_081160DA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081160e0
FUN_081160e0: @ 0x081160E0
	push {lr}
	adds r2, r0, #0
	ldr r1, _0811612C @ =0x00000553
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #9
	beq _08116126
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08116126
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, _08116130 @ =0x00FFFFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	beq _08116126
	adds r3, #0x4c
	adds r0, r2, r3
	ldr r1, [r0]
	ldr r0, _08116134 @ =0x0000065C
	adds r1, r1, r0
	ldr r2, _08116138 @ =0xFFF7FFFF
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_08116126:
	pop {r0}
	bx r0
	.align 2, 0
_0811612C: .4byte 0x00000553
_08116130: .4byte 0x00FFFFFF
_08116134: .4byte 0x0000065C
_08116138: .4byte 0xFFF7FFFF

	thumb_func_start FUN_0811613c
FUN_0811613c: @ 0x0811613C
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x28
	mov r8, r0
	ldr r4, _081161C0 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	movs r5, #0x40
	orrs r0, r5
	ldr r1, _081161C4 @ =0x0000FFFF
	mov sb, r1
	ands r0, r1
	movs r6, #0x80
	lsls r6, r6, #0x10
	orrs r0, r6
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r4
	orrs r0, r5
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _081161C8 @ =FUN_08116628
	mov r0, r8
	str r0, [sp]
	add r1, sp, #8
	bl FUN_080e3834
	ldr r0, [sp, #0x18]
	ands r0, r4
	orrs r0, r5
	mov r1, sb
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r5
	str r0, [r1, #4]
	str r6, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _081161CC @ =FUN_08116350
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	bl FUN_080e3984
	add sp, #0x28
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081161C0: .4byte 0xFFFF0000
_081161C4: .4byte 0x0000FFFF
_081161C8: .4byte FUN_08116628
_081161CC: .4byte FUN_08116350

	thumb_func_start FUN_081161d0
FUN_081161d0: @ 0x081161D0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081161EC
	b _08116344
_081161EC:
	ldr r0, _08116250 @ =0x0000A027
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _081161FE
	b _08116344
_081161FE:
	movs r2, #0x10
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _0811625C
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r1, #0x20
	strh r1, [r0, #0xa]
	ldr r1, _08116254 @ =0x00002001
	strh r1, [r0, #6]
	movs r4, #0x8a
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	movs r3, #0x8c
	lsls r3, r3, #2
	adds r2, r6, r3
	ldrh r2, [r2]
	adds r4, #0x1c
	adds r3, r6, r4
	ldr r3, [r3]
	ldr r4, _08116258 @ =0x00200004
	orrs r3, r4
	str r3, [sp]
	movs r4, #0x8e
	lsls r4, r4, #2
	adds r3, r6, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	movs r0, #0x80
	lsls r0, r0, #7
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r6, r1
	b _081162F8
	.align 2, 0
_08116250: .4byte 0x0000A027
_08116254: .4byte 0x00002001
_08116258: .4byte 0x00200004
_0811625C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	cmp r1, #0
	beq _08116310
	ldr r2, _08116278 @ =0x000006B6
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _0811627C
	asrs r0, r0, #5
	b _08116282
	.align 2, 0
_08116278: .4byte 0x000006B6
_0811627C:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_08116282:
	adds r5, r0, #0
	cmp r5, #0x14
	ble _0811628C
	movs r5, #0x14
	b _08116292
_0811628C:
	cmp r5, #9
	bgt _08116292
	movs r5, #0xa
_08116292:
	ldr r4, _08116300 @ =0x00000226
	adds r0, r6, r4
	ldrh r0, [r0]
	muls r0, r5, r0
	movs r1, #0xa
	bl Div
	adds r4, r0, #0
	ldr r1, _08116304 @ =0x0000022E
	adds r0, r6, r1
	ldrh r1, [r0]
	asrs r0, r5, #1
	muls r0, r1, r0
	movs r1, #0xa
	bl Div
	adds r2, r0, #0
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r1, _08116308 @ =0x00002301
	movs r3, #0
	strh r1, [r0, #6]
	strh r3, [r0, #0xa]
	movs r3, #0x90
	lsls r3, r3, #2
	adds r1, r6, r3
	ldr r1, [r1]
	movs r3, #0x80
	lsls r3, r3, #0xb
	orrs r1, r3
	str r1, [sp]
	ldr r3, _0811630C @ =0x00000236
	adds r1, r6, r3
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r4, #0
	movs r3, #0x80
	bl FUN_082364f8
	adds r2, r6, #0
	adds r2, #0x7c
	movs r1, #1
	ldr r0, [r2, #4]
	orrs r0, r1
	str r0, [r2, #4]
	movs r0, #0x80
	lsls r0, r0, #7
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r2, r6, r4
_081162F8:
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _08116344
	.align 2, 0
_08116300: .4byte 0x00000226
_08116304: .4byte 0x0000022E
_08116308: .4byte 0x00002301
_0811630C: .4byte 0x00000236
_08116310:
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, _0811634C @ =0x00002001
	strh r1, [r0, #6]
	strh r2, [r0, #0xa]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r6, r2
	ldrh r1, [r1]
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r2, r6, r3
	ldrh r2, [r2]
	movs r4, #0x8f
	lsls r4, r4, #2
	adds r3, r6, r4
	ldr r3, [r3]
	str r3, [sp]
	subs r4, #8
	adds r3, r6, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
_08116344:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0811634C: .4byte 0x00002001

	thumb_func_start FUN_08116350
FUN_08116350: @ 0x08116350
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov sb, r0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r7, r5, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811637A
	b _08116616
_0811637A:
	mov r2, sb
	ldr r0, [r2, #0x24]
	ldr r1, [r2, #0x28]
	str r0, [sp]
	str r1, [sp, #4]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _081163B4
	cmp r0, #1
	bgt _0811639C
	cmp r0, #0
	beq _081163A6
	b _081163FC
_0811639C:
	cmp r0, #2
	beq _081163C4
	cmp r0, #3
	beq _081163E4
	b _081163FC
_081163A6:
	mov r0, sp
	ldrh r1, [r0]
	ldr r3, _081163B0 @ =0xFFFFFF00
	adds r1, r1, r3
	b _081163CE
	.align 2, 0
_081163B0: .4byte 0xFFFFFF00
_081163B4:
	mov r0, sp
	ldrh r1, [r0, #4]
	ldr r0, _081163C0 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081163EE
	.align 2, 0
_081163C0: .4byte 0xFFFFFF00
_081163C4:
	mov r0, sp
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081163CE:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081163E0 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	b _081163FC
	.align 2, 0
_081163E0: .4byte 0xFFFF0000
_081163E4:
	mov r0, sp
	ldrh r1, [r0, #4]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r1, r3
_081163EE:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0811647C @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
_081163FC:
	add r2, sp, #8
	mov r4, sp
	adds r3, r6, #0
	adds r3, #0x24
	ldrh r0, [r6, #0x24]
	mov r1, sp
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	mov r1, sb
	adds r1, #0x42
	strb r0, [r1]
	ldrh r1, [r6, #0xa]
	movs r4, #0xf
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _0811643E
	b _081165E8
_0811643E:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08116452
	b _08116598
_08116452:
	ldr r3, _08116480 @ =0x00000553
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0x28
	beq _081164BE
	ldrb r2, [r7, #5]
	ldr r0, [r6, #0x4c]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081164B4
	adds r1, r2, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _08116484
	asrs r0, r1, #6
	b _0811648A
	.align 2, 0
_0811647C: .4byte 0xFFFF0000
_08116480: .4byte 0x00000553
_08116484:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0811648A:
	adds r2, r0, #0
	adds r0, r6, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081164A2
	asrs r0, r1, #6
	b _081164A8
_081164A2:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081164A8:
	subs r0, r2, r0
	cmp r0, #0
	bge _081164B0
	rsbs r0, r0, #0
_081164B0:
	cmp r0, #2
	bne _081164B8
_081164B4:
	movs r0, #1
	b _081164BA
_081164B8:
	movs r0, #0
_081164BA:
	cmp r0, #0
	beq _08116524
_081164BE:
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081164EC
	ldrh r1, [r6, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081164EC
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _0811651C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081164EC:
	ldr r1, _08116520 @ =0x000006BC
	add r1, r8
	ldrh r0, [r1]
	adds r0, #0xc8
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xc8
	lsls r2, r2, #1
	cmp r0, r2
	bls _08116504
	strh r2, [r1]
_08116504:
	adds r2, r6, #0
	adds r2, #0x46
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	ldrh r1, [r6, #4]
	movs r0, #0xcd
	lsls r0, r0, #3
	add r0, r8
	strh r1, [r0]
	b _08116616
	.align 2, 0
_0811651C: .4byte 0xFEFFFFFF
_08116520: .4byte 0x000006BC
_08116524:
	ldr r0, _08116538 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811653C
	movs r0, #1
	b _0811653E
	.align 2, 0
_08116538: .4byte 0x030047A4
_0811653C:
	movs r0, #0
_0811653E:
	cmp r0, #0
	beq _08116574
	ldrh r1, [r6, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08116550
	movs r2, #0
	b _08116568
_08116550:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0811655C
	movs r2, #1
	b _08116568
_0811655C:
	movs r0, #4
	ands r0, r1
	movs r2, #3
	cmp r0, #0
	beq _08116568
	movs r2, #2
_08116568:
	ldr r1, _08116570 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	b _08116576
	.align 2, 0
_08116570: .4byte 0x03002BE0
_08116574:
	ldr r0, _08116590 @ =0x03002BE0
_08116576:
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08116616
	ldr r1, _08116594 @ =0x000006BC
	add r1, r8
	movs r0, #0xc8
	lsls r0, r0, #1
	strh r0, [r1]
	b _08116616
	.align 2, 0
_08116590: .4byte 0x03002BE0
_08116594: .4byte 0x000006BC
_08116598:
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081165C6
	ldrh r1, [r6, #0xa]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _081165C6
	movs r2, #0xea
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r5, r3
	ldr r1, _081165E0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081165C6:
	ldr r1, _081165E4 @ =0x000006BC
	add r1, r8
	ldrh r0, [r1]
	adds r0, #0xc8
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xc8
	lsls r2, r2, #1
	cmp r0, r2
	bls _08116616
	strh r2, [r1]
	b _08116616
	.align 2, 0
_081165E0: .4byte 0xFEFFFFFF
_081165E4: .4byte 0x000006BC
_081165E8:
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08116616
	ldrh r1, [r6, #0xa]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08116616
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _08116624 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08116616:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08116624: .4byte 0xFEFFFFFF

	thumb_func_start FUN_08116628
FUN_08116628: @ 0x08116628
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0811664A
	b _08116CD0
_0811664A:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08116674
	ldr r3, _08116670 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08116662
	b _08116CD0
_08116662:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _08116CD0
	.align 2, 0
_08116670: .4byte 0x0000048C
_08116674:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _08116684
	b _08116CD0
_08116684:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _08116694
	b _081169A0
_08116694:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _081166A6
	b _08116CD0
_081166A6:
	ldr r2, _08116738 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081166BA
	b _08116CD0
_081166BA:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081166C8
	b _08116CD0
_081166C8:
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _081166E0
	b _08116828
_081166E0:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08116748
	ands r3, r1
	cmp r3, #0
	beq _08116748
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08116706
	rsbs r1, r1, #0
_08116706:
	cmp r1, #0x20
	bgt _08116748
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _0811673C @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _08116740 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08116744 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _08116CD0
	.align 2, 0
_08116738: .4byte 0x0000A007
_0811673C: .4byte 0x000004BE
_08116740: .4byte 0x0000048C
_08116744: .4byte 0x0000044E
_08116748:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _08116770 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08116778
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08116774 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081167E6
	.align 2, 0
_08116770: .4byte 0x0000048A
_08116774: .4byte 0x03002BE0
_08116778:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08116794
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08116790 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081167E6
	.align 2, 0
_08116790: .4byte 0x03002BE0
_08116794:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081167B0
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081167AC @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081167E6
	.align 2, 0
_081167AC: .4byte 0x03002BE0
_081167B0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081167CC
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081167C8 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081167E6
	.align 2, 0
_081167C8: .4byte 0x03002BE0
_081167CC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081167DE
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081167E6
_081167DE:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081167E8
_081167E6:
	movs r3, #1
_081167E8:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _0811681C @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _0811680A
	b _08116960
_0811680A:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08116820
	movs r0, #1
	b _08116822
	.align 2, 0
_0811681C: .4byte 0x0000049C
_08116820:
	movs r0, #0
_08116822:
	cmp r0, #0
	bne _08116906
	b _0811691C
_08116828:
	strh r2, [r7, #0x3e]
	ldr r1, _08116850 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08116858
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08116854 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081168C6
	.align 2, 0
_08116850: .4byte 0x0000048A
_08116854: .4byte 0x03002BE0
_08116858:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08116874
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08116870 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081168C6
	.align 2, 0
_08116870: .4byte 0x03002BE0
_08116874:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08116890
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0811688C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081168C6
	.align 2, 0
_0811688C: .4byte 0x03002BE0
_08116890:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081168AC
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081168A8 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081168C6
	.align 2, 0
_081168A8: .4byte 0x03002BE0
_081168AC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081168BE
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081168C6
_081168BE:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081168C8
_081168C6:
	movs r3, #1
_081168C8:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _081168FC @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _08116960
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08116900
	movs r0, #1
	b _08116902
	.align 2, 0
_081168FC: .4byte 0x0000049C
_08116900:
	movs r0, #0
_08116902:
	cmp r0, #0
	beq _0811691C
_08116906:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08116918 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08116928
	.align 2, 0
_08116918: .4byte 0x03002BE0
_0811691C:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08116960
_08116928:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_08116960:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0811698C
	ldr r5, _08116998 @ =0x0000024E
	adds r2, r6, r5
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0811698C
	strh r1, [r2]
_0811698C:
	ldr r5, _0811699C @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _08116CD0
	.align 2, 0
_08116998: .4byte 0x0000024E
_0811699C: .4byte 0x0000048C
_081169A0:
	ldr r0, _081169B4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081169B8
	movs r0, #1
	b _081169BA
	.align 2, 0
_081169B4: .4byte 0x030047A4
_081169B8:
	movs r0, #0
_081169BA:
	cmp r0, #0
	beq _081169C8
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236640
	b _081169D0
_081169C8:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236524
_081169D0:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08116A08 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08116A0C @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _081169FE
	cmp r2, #0x17
	bne _08116A10
_081169FE:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _08116A32
	.align 2, 0
_08116A08: .4byte 0x0000048C
_08116A0C: .4byte 0x000001DF
_08116A10:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _081169FE
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08116A60 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08116A32
	movs r1, #0
_08116A32:
	adds r0, r7, #0
	adds r0, #0x40
	strh r1, [r0]
	mov sb, r0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08116A6E
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _08116A64
	asrs r0, r0, #1
	b _08116A6A
	.align 2, 0
_08116A60: .4byte 0x00000187
_08116A64:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08116A6A:
	mov r2, sb
	strh r0, [r2]
_08116A6E:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08116A8C
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08116A88 @ =0x000001DD
	adds r1, r6, r4
	b _08116B00
	.align 2, 0
_08116A88: .4byte 0x000001DD
_08116A8C:
	mov r4, sp
	mov r3, r8
	adds r3, #0xc
	adds r2, r7, #0
	adds r2, #0xc
	ldrh r0, [r7, #0xc]
	mov r5, r8
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _08116AEC
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08116AEC
	ldr r2, _08116ADC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08116AE0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08116AE4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08116AE8 @ =0x000001DD
	adds r1, r6, r4
	b _08116B00
	.align 2, 0
_08116ADC: .4byte 0x030046B8
_08116AE0: .4byte 0x000003FF
_08116AE4: .4byte 0x0203B400
_08116AE8: .4byte 0x000001DD
_08116AEC:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _08116B20 @ =0x000001DD
	adds r1, r6, r3
_08116B00:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08116B28
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08116B24 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08116B96
	.align 2, 0
_08116B20: .4byte 0x000001DD
_08116B24: .4byte 0x03002BE0
_08116B28:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08116B44
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08116B40 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08116B96
	.align 2, 0
_08116B40: .4byte 0x03002BE0
_08116B44:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08116B60
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08116B5C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08116B96
	.align 2, 0
_08116B5C: .4byte 0x03002BE0
_08116B60:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08116B7C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08116B78 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08116B96
	.align 2, 0
_08116B78: .4byte 0x03002BE0
_08116B7C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08116B8E
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _08116B96
_08116B8E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08116B98
_08116B96:
	movs r3, #1
_08116B98:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _08116BCC @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _08116C34
	movs r1, #2
	ldr r2, _08116BD0 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08116BD4
	movs r0, #1
	b _08116BD6
	.align 2, 0
_08116BCC: .4byte 0x0000049C
_08116BD0: .4byte 0x00000474
_08116BD4:
	movs r0, #0
_08116BD6:
	cmp r0, #0
	beq _08116BF0
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08116BEC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08116BFC
	.align 2, 0
_08116BEC: .4byte 0x03002BE0
_08116BF0:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08116C34
_08116BFC:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_08116C34:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08116C68
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08116C68
	ldr r0, _08116C80 @ =0x0000024E
	adds r2, r6, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _08116C68
	strh r1, [r2]
_08116C68:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _08116C84 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _08116C88 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08116C8C
	movs r0, #1
	b _08116C8E
	.align 2, 0
_08116C80: .4byte 0x0000024E
_08116C84: .4byte 0x030046A0
_08116C88: .4byte 0x00000934
_08116C8C:
	movs r0, #0
_08116C8E:
	ldr r1, _08116CE0 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _08116CA6
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_08116CA6:
	adds r0, r6, #0
	bl FUN_080e64e4
	ldrh r0, [r7, #0x3e]
	strh r0, [r4]
	movs r4, #0xc4
	lsls r4, r4, #1
	adds r1, r6, r4
	mov r5, r8
	ldrh r0, [r5, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08116CD0:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08116CE0: .4byte 0x0000048A

	thumb_func_start FUN_08116ce4
FUN_08116ce4: @ 0x08116CE4
	push {lr}
	adds r2, r0, #0
	ldr r0, _08116D04 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08116CF6
	movs r0, #0
	strb r0, [r1]
_08116CF6:
	adds r0, r2, #0
	movs r1, #1
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_08116D04: .4byte 0x0000046D

	thumb_func_start FUN_08116d08
FUN_08116d08: @ 0x08116D08
	push {lr}
	adds r2, r0, #0
	ldr r0, _08116D28 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08116D1A
	movs r0, #0
	strb r0, [r1]
_08116D1A:
	adds r0, r2, #0
	movs r1, #0
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_08116D28: .4byte 0x0000046D

	thumb_func_start FUN_08116d2c
FUN_08116d2c: @ 0x08116D2C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r5
	ldr r0, _08116D4C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08116D50
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08116D52
	.align 2, 0
_08116D4C: .4byte 0x0000046D
_08116D50:
	movs r0, #0
_08116D52:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	bne _08116D60
	b _081171FA
_08116D60:
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r2, r0, #1
	ands r2, r1
	ldr r3, _08116DB0 @ =0x0000046A
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #6
	beq _08116DB4
	movs r1, #0x90
	lsls r1, r1, #3
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _08116DB4
	mov r1, r8
	ldr r0, [r1, #0x24]
	ldr r0, [r0, #8]
	ldrh r0, [r0, #4]
	lsrs r1, r0, #0xc
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	b _08116DBC
	.align 2, 0
_08116DB0: .4byte 0x0000046A
_08116DB4:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
_08116DBC:
	cmp r1, #0
	blt _08116DC4
	asrs r0, r1, #1
	b _08116DCA
_08116DC4:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08116DCA:
	cmp r2, r0
	bne _08116E36
	ldr r2, _08116E1C @ =0x0000046B
	adds r0, r5, r2
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08116E2C
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _08116E20 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _08116E24 @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _08116E28 @ =0x000005BC
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #0x1b
	adds r3, #1
	b _0811735C
	.align 2, 0
_08116E1C: .4byte 0x0000046B
_08116E20: .4byte 0x00000469
_08116E24: .4byte 0x0000046A
_08116E28: .4byte 0x000005BC
_08116E2C:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	b _081173C0
_08116E36:
	cmp r2, #1
	beq _08116F14
	cmp r2, #1
	bgt _08116E44
	cmp r2, #0
	beq _08116E52
	b _081171F2
_08116E44:
	cmp r2, #2
	bne _08116E4A
	b _08116FE4
_08116E4A:
	cmp r2, #3
	bne _08116E50
	b _081170D0
_08116E50:
	b _081171F2
_08116E52:
	subs r0, r1, #2
	cmp r0, #3
	bhi _08116EA4
	movs r2, #2
	ldr r3, _08116E78 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _08116E80
	ldr r1, _08116E7C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	b _081170F2
	.align 2, 0
_08116E78: .4byte 0x0000025D
_08116E7C: .4byte 0x000004B7
_08116E80:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #3
	ldr r3, _08116E9C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08116EA0 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #3
	beq _08116E9A
	b _0811712E
_08116E9A:
	b _0811711E
	.align 2, 0
_08116E9C: .4byte 0x000004B7
_08116EA0: .4byte 0x0000046E
_08116EA4:
	movs r1, #2
	ldr r2, _08116ECC @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08116ED4
	ldr r3, _08116ED0 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	b _08116EFA
	.align 2, 0
_08116ECC: .4byte 0x0000025D
_08116ED0: .4byte 0x000004B7
_08116ED4:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r2, _08116F0C @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #2
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_08116EFA:
	ldr r3, _08116F10 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	b _081171EA
	.align 2, 0
_08116F0C: .4byte 0x000004B7
_08116F10: .4byte 0x0000046E
_08116F14:
	subs r0, r1, #4
	cmp r0, #3
	bhi _08116F74
	movs r2, #2
	ldr r1, _08116F3C @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _08116F44
	ldr r1, _08116F40 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #2
	b _081170F2
	.align 2, 0
_08116F3C: .4byte 0x0000025D
_08116F40: .4byte 0x000004B7
_08116F44:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #4
	ldr r3, _08116F6C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08116F70 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #4
	beq _08116F5E
	b _0811712E
_08116F5E:
	ldrb r0, [r6]
	cmp r0, #0
	beq _08116F66
	b _0811712E
_08116F66:
	ldr r0, [r4, #8]
	ands r0, r2
	b _0811712A
	.align 2, 0
_08116F6C: .4byte 0x000004B7
_08116F70: .4byte 0x0000046E
_08116F74:
	movs r1, #2
	ldr r2, _08116F9C @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08116FA4
	ldr r3, _08116FA0 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #2
	movs r3, #1
	bl FUN_08236fac
	b _08116FCC
	.align 2, 0
_08116F9C: .4byte 0x0000025D
_08116FA0: .4byte 0x000004B7
_08116FA4:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #3
	ldr r2, _08116FDC @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #3
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_08116FCC:
	ldr r3, _08116FE0 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	b _081171EA
	.align 2, 0
_08116FDC: .4byte 0x000004B7
_08116FE0: .4byte 0x0000046E
_08116FE4:
	subs r0, r1, #1
	cmp r0, #4
	bls _08117060
	movs r1, #2
	ldr r2, _08117014 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0811701C
	ldr r3, _08117018 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #5
	str r2, [sp]
	movs r2, #2
	movs r3, #1
	bl FUN_08236fac
	b _08117042
	.align 2, 0
_08117014: .4byte 0x0000025D
_08117018: .4byte 0x000004B7
_0811701C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #3
	ldr r2, _08117058 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #3
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #8]
_08117042:
	ldr r3, _0811705C @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	b _08117158
	.align 2, 0
_08117058: .4byte 0x000004B7
_0811705C: .4byte 0x0000046E
_08117060:
	movs r2, #4
	ldr r1, _08117088 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08117090
	ldr r3, _0811708C @ =0x000004B7
	adds r1, r5, r3
	movs r0, #2
	strb r0, [r1]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r2, [sp]
	movs r2, #2
	movs r3, #2
	bl FUN_08236fac
	b _081170B6
	.align 2, 0
_08117088: .4byte 0x0000025D
_0811708C: .4byte 0x000004B7
_08117090:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r1, _081170C8 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #4
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081170B6:
	ldr r2, _081170CC @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r5, r3
	b _081171EA
	.align 2, 0
_081170C8: .4byte 0x000004B7
_081170CC: .4byte 0x0000046E
_081170D0:
	cmp r1, #3
	bhi _08117168
	movs r2, #2
	ldr r1, _081170FC @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _08117108
	ldr r1, _08117100 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
_081170F2:
	bl FUN_08236fac
	ldr r2, _08117104 @ =0x0000046E
	adds r6, r5, r2
	b _0811714A
	.align 2, 0
_081170FC: .4byte 0x0000025D
_08117100: .4byte 0x000004B7
_08117104: .4byte 0x0000046E
_08117108:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r3, _08117160 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08117164 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #2
	bne _0811712E
_0811711E:
	ldrb r0, [r6]
	cmp r0, #0
	bne _0811712E
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
_0811712A:
	cmp r0, #0
	beq _0811714E
_0811712E:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_0811714A:
	movs r0, #0
	strb r0, [r6]
_0811714E:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
_08117158:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081171F2
	.align 2, 0
_08117160: .4byte 0x000004B7
_08117164: .4byte 0x0000046E
_08117168:
	movs r2, #2
	ldr r1, _08117194 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081171A0
	ldr r3, _08117198 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #2
	movs r3, #1
	bl FUN_08236fac
	ldr r0, _0811719C @ =0x0000046E
	adds r6, r5, r0
	b _081171E0
	.align 2, 0
_08117194: .4byte 0x0000025D
_08117198: .4byte 0x000004B7
_0811719C: .4byte 0x0000046E
_081171A0:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #3
	ldr r1, _0811722C @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08117230 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #3
	bne _081171C8
	ldrb r0, [r6]
	cmp r0, #0
	bne _081171C8
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081171E4
_081171C8:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r4, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
_081171E0:
	movs r0, #0
	strb r0, [r6]
_081171E4:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r5, r1
_081171EA:
	ldr r1, _08117234 @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081171F2:
	ldr r2, _08117230 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_081171FA:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	bne _0811725C
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r1, r0, #5
	adds r0, r1, #0
	mov r3, r8
	ldrb r2, [r3, #5]
	subs r0, r2, r0
	cmp r0, #0
	bge _08117222
	rsbs r0, r0, #0
_08117222:
	cmp r0, #0x16
	bgt _08117238
	mov r0, r8
	strb r1, [r0, #5]
	b _0811725C
	.align 2, 0
_0811722C: .4byte 0x000004B7
_08117230: .4byte 0x0000046E
_08117234: .4byte 0xFFFEFFFF
_08117238:
	movs r1, #0x80
	lsls r1, r1, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08117254
	adds r0, r2, #0
	adds r0, #0x16
	mov r1, r8
	strb r0, [r1, #5]
	b _0811725C
_08117254:
	adds r0, r2, #0
	subs r0, #0x16
	mov r2, r8
	strb r0, [r2, #5]
_0811725C:
	ldr r1, _08117274 @ =0x0000A02F
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0811727C
	ldr r0, _08117278 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0811728C
	.align 2, 0
_08117274: .4byte 0x0000A02F
_08117278: .4byte 0x00000482
_0811727C:
	ldr r1, _081172B0 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0811728C
	movs r0, #1
	strh r0, [r2]
_0811728C:
	ldr r3, _081172B4 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081172B8
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _081172D0
	.align 2, 0
_081172B0: .4byte 0x00000482
_081172B4: .4byte 0x0000025D
_081172B8:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_081172D0:
	ldr r1, _08117380 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081173C0
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r3, #0xee
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r1, r1, r0
	cmp r1, #0
	bge _081172FA
	rsbs r1, r1, #0
_081172FA:
	cmp r1, #0
	bgt _08117390
	ldr r1, _08117384 @ =0x0000046B
	adds r0, r5, r1
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r7, #3
	ands r0, r7
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081173C0
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r7, [r0]
	adds r1, #0x69
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _08117388 @ =0x0000046A
	adds r0, r5, r2
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _0811738C @ =0x000005BC
	adds r0, r5, r2
	ldr r2, [r0]
	movs r1, #0x1b
	subs r3, #0x17
_0811735C:
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	b _081173C0
	.align 2, 0
_08117380: .4byte 0x0000046E
_08117384: .4byte 0x0000046B
_08117388: .4byte 0x0000046A
_0811738C: .4byte 0x000005BC
_08117390:
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _081173D0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081173D4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_081173C0:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081173D0: .4byte 0x0000046D
_081173D4: .4byte 0x0000046B

	thumb_func_start FUN_081173d8
FUN_081173d8: @ 0x081173D8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	movs r2, #1
	ldr r1, _081173F4 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081173F8
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08117402
	.align 2, 0
_081173F4: .4byte 0x0000025D
_081173F8:
	ldr r1, [r4, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_08117402:
	ldr r1, _08117418 @ =0x0000046D
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _0811741C
	movs r0, #0
	strb r0, [r6]
	movs r0, #1
	b _0811741E
	.align 2, 0
_08117418: .4byte 0x0000046D
_0811741C:
	movs r0, #0
_0811741E:
	adds r5, r0, #0
	cmp r5, #0
	beq _08117430
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r4, r3
	bl FUN_080136b4
	b _08117472
_08117430:
	cmp r3, #0x1a
	ble _0811746C
	adds r0, r4, #0
	movs r1, #7
	bl FUN_080ef86c
	ldr r2, _08117464 @ =FUN_0811747c
	movs r1, #0xd
	movs r0, #1
	strb r0, [r6]
	ldr r3, _08117468 @ =0x0000046B
	adds r0, r4, r3
	strb r5, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r5, [r0]
	b _08117472
	.align 2, 0
_08117464: .4byte FUN_0811747c
_08117468: .4byte 0x0000046B
_0811746C:
	ldr r1, _08117478 @ =0x0000046E
	adds r0, r4, r1
	strb r5, [r0]
_08117472:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08117478: .4byte 0x0000046E

	thumb_func_start FUN_0811747c
FUN_0811747c: @ 0x0811747C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08117494 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08117498
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811749A
	.align 2, 0
_08117494: .4byte 0x0000046D
_08117498:
	movs r0, #0
_0811749A:
	cmp r0, #0
	beq _081174E6
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_08013698
	ldr r2, _081174C0 @ =0x0000025D
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081174C4
	ldr r2, [r6, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081174D2
	.align 2, 0
_081174C0: .4byte 0x0000025D
_081174C4:
	ldr r0, [r6, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_081174D2:
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x3c
	strh r0, [r1]
_081174E6:
	ldr r1, _08117684 @ =0x0000046E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081174F2
	b _0811767E
_081174F2:
	adds r0, r6, #0
	bl FUN_08115dd8
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, _08117688 @ =0x0000055C
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r6, r0
	adds r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _0811768C @ =0x00000564
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r4, #0
	strb r0, [r6, #5]
	adds r2, #5
	adds r0, r6, r2
	ldrb r1, [r0]
	subs r2, #0xfd
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _08117690 @ =0x00000566
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _08117694 @ =0x00000567
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r1, r6, r0
	adds r2, #0xfe
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _08117698 @ =0x0000056C
	adds r0, r6, r1
	ldrb r1, [r0]
	subs r2, #0x15
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _0811769C @ =0x00000572
	adds r0, r6, r1
	ldrh r1, [r0]
	subs r2, #0xdf
	adds r0, r6, r2
	movs r5, #0
	strh r1, [r0]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	subs r2, #0x3a
	adds r0, r6, r2
	strh r1, [r0]
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, #0x9e
	adds r0, r6, r2
	strh r4, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r2, _081176A0 @ =0x0000046B
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _081176A4 @ =0x0000046C
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r5, [r0]
	ldr r2, _081176A8 @ =0x0000024E
	adds r0, r6, r2
	strh r4, [r0]
	subs r2, #0xbc
	adds r0, r6, r2
	strh r4, [r0]
	ldr r2, _081176AC @ =0x00000544
	adds r0, r6, r2
	strh r4, [r0]
	subs r2, #0xde
	adds r0, r6, r2
	strh r4, [r0]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r0, r6, r2
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r4, [r0]
	adds r2, #5
	adds r0, r6, r2
	strb r5, [r0]
	adds r2, #0x3f
	adds r0, r6, r2
	strb r5, [r0]
	ldr r2, _081176B0 @ =0x00000482
	adds r0, r6, r2
	strh r1, [r0]
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	adds r2, #0x1a
	adds r0, r6, r2
	str r4, [r0]
	adds r1, #8
	adds r0, r6, r1
	str r4, [r0]
	subs r2, #0x10
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #0x1e
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r5, [r0]
	subs r1, #0x30
	adds r0, r6, r1
	strb r5, [r0]
	subs r2, #0x35
	adds r0, r6, r2
	movs r1, #8
	bl ClearMemory
	ldr r1, _081176B4 @ =0x00000464
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0x8c
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r4, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r1, _081176B8 @ =0x08251FF4
	adds r0, r6, #0
	ldr r2, _081176BC @ =0x00000982
	bl FUN_080e6768
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _081176C0 @ =0x00000541
	adds r0, r6, r1
	strb r5, [r0]
	adds r2, #2
	adds r1, r6, r2
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	adds r2, #0xa
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #5
	adds r0, r6, r1
	strb r5, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r5, [r0]
	adds r0, r6, #0
	bl FUN_080eeee0
_0811767E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08117684: .4byte 0x0000046E
_08117688: .4byte 0x0000055C
_0811768C: .4byte 0x00000564
_08117690: .4byte 0x00000566
_08117694: .4byte 0x00000567
_08117698: .4byte 0x0000056C
_0811769C: .4byte 0x00000572
_081176A0: .4byte 0x0000046B
_081176A4: .4byte 0x0000046C
_081176A8: .4byte 0x0000024E
_081176AC: .4byte 0x00000544
_081176B0: .4byte 0x00000482
_081176B4: .4byte 0x00000464
_081176B8: .4byte 0x08251FF4
_081176BC: .4byte 0x00000982
_081176C0: .4byte 0x00000541

	thumb_func_start FUN_081176c4
FUN_081176c4: @ 0x081176C4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _081176DC @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081176E0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081176E2
	.align 2, 0
_081176DC: .4byte 0x0000046D
_081176E0:
	movs r0, #0
_081176E2:
	cmp r0, #0
	beq _08117704
	adds r0, r5, #0
	movs r1, #6
	bl FUN_080ef86c
	movs r0, #2
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _08117704
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
_08117704:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Mod
	cmp r0, #0
	bne _08117720
	ldr r2, _0811776C @ =0x000001DF
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080e5718
_08117720:
	ldr r1, _08117770 @ =0x00000466
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _08117766
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _08117766
	ldr r3, _08117774 @ =FUN_08117780
	movs r2, #6
	ldr r0, _08117778 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0811777C @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
_08117766:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0811776C: .4byte 0x000001DF
_08117770: .4byte 0x00000466
_08117774: .4byte FUN_08117780
_08117778: .4byte 0x0000046D
_0811777C: .4byte 0x0000046B

	thumb_func_start FUN_08117780
FUN_08117780: @ 0x08117780
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08117798 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811779C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811779E
	.align 2, 0
_08117798: .4byte 0x0000046D
_0811779C:
	movs r0, #0
_0811779E:
	cmp r0, #0
	beq _081177BA
	adds r0, r4, #0
	movs r1, #7
	bl FUN_080ef86c
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_081177BA:
	cmp r5, #0x28
	bne _081177CC
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081177CC:
	ldr r1, _081177E8 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081177E2
	cmp r5, #0x78
	ble _081177E2
	ldr r0, _081177EC @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081177E2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081177E8: .4byte 0x0000046E
_081177EC: .4byte 0x0000046B

	thumb_func_start FUN_081177f0
FUN_081177f0: @ 0x081177F0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r0, _0811780C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08117810
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08117812
	.align 2, 0
_0811780C: .4byte 0x0000046D
_08117810:
	movs r0, #0
_08117812:
	cmp r0, #0
	beq _08117826
	adds r0, r4, #0
	movs r1, #0xf
	bl FUN_080ef86c
	ldr r0, _08117838 @ =0x0000046E
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_08117826:
	ldrh r0, [r5, #8]
	cmp r0, #1
	bne _08117830
	movs r0, #0
	strh r0, [r5, #0xe]
_08117830:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08117838: .4byte 0x0000046E

	thumb_func_start FUN_0811783c
FUN_0811783c: @ 0x0811783C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08117854 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08117858
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811785A
	.align 2, 0
_08117854: .4byte 0x0000046D
_08117858:
	movs r0, #0
_0811785A:
	cmp r0, #0
	beq _08117876
	adds r0, r5, #0
	movs r1, #0xf
	bl FUN_080ef86c
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08117876:
	ldr r1, _081178B0 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081178A8
	ldr r4, _081178B4 @ =FUN_081178c0
	movs r3, #0x21
	ldr r0, _081178B8 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081178BC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_081178A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081178B0: .4byte 0x0000046E
_081178B4: .4byte FUN_081178c0
_081178B8: .4byte 0x0000046D
_081178BC: .4byte 0x0000046B

	thumb_func_start FUN_081178c0
FUN_081178c0: @ 0x081178C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	str r1, [sp, #8]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _081178EC @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081178F0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081178F2
	.align 2, 0
_081178EC: .4byte 0x0000046D
_081178F0:
	movs r0, #0
_081178F2:
	cmp r0, #0
	beq _081179D0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #1
	beq _0811791C
	cmp r0, #1
	bgt _08117914
	cmp r0, #0
	beq _08117978
	b _081179C8
_08117914:
	cmp r0, #3
	beq _0811791C
	cmp r0, #5
	bne _081179C8
_0811791C:
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r0, _08117934 @ =0x0000065C
	adds r1, r1, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _08117938
	movs r0, #1
	b _0811793A
	.align 2, 0
_08117934: .4byte 0x0000065C
_08117938:
	movs r0, #0
_0811793A:
	cmp r0, #0
	beq _0811794C
_0811793E:
	ldr r1, _08117948 @ =0xFFFFF7FF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081179C8
	.align 2, 0
_08117948: .4byte 0xFFFFF7FF
_0811794C:
	ldr r2, _0811796C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08117970 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08117974 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r1, r0, #0
	adds r1, #0x1e
	b _081179CA
	.align 2, 0
_0811796C: .4byte 0x030046B8
_08117970: .4byte 0x000003FF
_08117974: .4byte 0x0203B400
_08117978:
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r0, _08117990 @ =0x0000065C
	adds r1, r1, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _08117994
	movs r0, #1
	b _08117996
	.align 2, 0
_08117990: .4byte 0x0000065C
_08117994:
	movs r0, #0
_08117996:
	cmp r0, #0
	bne _0811793E
	ldr r2, _081179BC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081179C0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081179C4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #4
	adds r1, r0, #0
	adds r1, #0x32
	b _081179CA
	.align 2, 0
_081179BC: .4byte 0x030046B8
_081179C0: .4byte 0x000003FF
_081179C4: .4byte 0x0203B400
_081179C8:
	movs r1, #0
_081179CA:
	ldr r0, _08117A20 @ =0x000006BE
	add r0, sb
	strh r1, [r0]
_081179D0:
	mov r4, sp
	adds r4, #5
	adds r0, r5, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_080e5d44
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _08117A24 @ =0x085AD608
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _08117A28 @ =0x0000025D
	adds r0, r5, r1
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #0
	bne _08117A34
	ldr r2, _08117A2C @ =0x000004B7
	adds r0, r5, r2
	mov r1, ip
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #8
	bl FUN_08236fac
	ldr r2, _08117A30 @ =0x0000046E
	adds r7, r5, r2
	b _08117AB6
	.align 2, 0
_08117A20: .4byte 0x000006BE
_08117A24: .4byte 0x085AD608
_08117A28: .4byte 0x0000025D
_08117A2C: .4byte 0x000004B7
_08117A30: .4byte 0x0000046E
_08117A34:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r3, #8
	mov ip, r3
	ldr r1, _08117AA4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r0, _08117AA8 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, ip
	bne _08117A70
	ldrb r0, [r7]
	cmp r0, #0
	bne _08117A70
	cmp r4, #1
	bne _08117A62
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08117ABA
_08117A62:
	cmp r4, #0
	bne _08117A70
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08117ABA
_08117A70:
	mov r1, ip
	strb r1, [r2]
	movs r2, #4
	mov r8, r2
	adds r0, r4, #0
	ands r0, r2
	movs r3, #4
	cmp r0, #0
	beq _08117A84
	movs r3, #6
_08117A84:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	mov r2, ip
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08117AAC
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _08117AB4
	.align 2, 0
_08117AA4: .4byte 0x000004B7
_08117AA8: .4byte 0x0000046E
_08117AAC:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08117AB4:
	str r0, [r6, #8]
_08117AB6:
	movs r0, #0
	strb r0, [r7]
_08117ABA:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r3, r5, r2
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r2, _08117B00 @ =0x000006B6
	add r2, sb
	ldrh r4, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _08117B04 @ =0x0000017F
	cmp r1, r0
	bgt _08117AE0
	adds r0, r4, #0
	adds r0, #0x10
	strh r0, [r2]
_08117AE0:
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	ldr r2, _08117B08 @ =0x00000482
	adds r1, r5, r2
	strh r0, [r1]
	ldr r1, _08117B0C @ =0x0000A02F
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08117B10
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08117B20
	.align 2, 0
_08117B00: .4byte 0x000006B6
_08117B04: .4byte 0x0000017F
_08117B08: .4byte 0x00000482
_08117B0C: .4byte 0x0000A02F
_08117B10:
	ldr r1, _08117B44 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08117B20
	movs r0, #1
	strh r0, [r2]
_08117B20:
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _08117B48
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _08117B60
	.align 2, 0
_08117B44: .4byte 0x00000482
_08117B48:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_08117B60:
	ldr r0, _08117B8C @ =0x000006BE
	add r0, sb
	ldr r2, [sp, #8]
	ldrh r0, [r0]
	cmp r2, r0
	ble _08117B7C
	ldr r0, _08117B90 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080e81dc
_08117B7C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08117B8C: .4byte 0x000006BE
_08117B90: .4byte 0x0000046B

	thumb_func_start FUN_08117b94
FUN_08117b94: @ 0x08117B94
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r6, r0, #0
	mov sl, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	mov sb, r6
	ldr r1, _08117BC4 @ =0x0000046D
	add r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	beq _08117BC8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08117BCA
	.align 2, 0
_08117BC4: .4byte 0x0000046D
_08117BC8:
	movs r0, #0
_08117BCA:
	cmp r0, #0
	beq _08117BD6
	ldr r2, _08117C38 @ =0x0000046E
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
_08117BD6:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r5, r6, r1
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	mov r4, sp
	adds r4, #9
	adds r0, r6, #0
	add r1, sp, #8
	adds r2, r4, #0
	bl FUN_080e5d44
	add r0, sp, #8
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _08117C3C @ =0x085AD608
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _08117C40 @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	str r5, [sp, #0x24]
	str r0, [sp, #0x20]
	cmp r1, #0
	bne _08117C48
	ldr r2, _08117C44 @ =0x000004B7
	adds r0, r6, r2
	mov r1, ip
	strb r1, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #8
	bl FUN_08236fac
	ldr r2, _08117C38 @ =0x0000046E
	adds r7, r6, r2
	b _08117CCA
	.align 2, 0
_08117C38: .4byte 0x0000046E
_08117C3C: .4byte 0x085AD608
_08117C40: .4byte 0x0000025D
_08117C44: .4byte 0x000004B7
_08117C48:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r3, #8
	mov ip, r3
	ldr r1, _08117CB8 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r0, _08117CBC @ =0x0000046E
	adds r7, r6, r0
	cmp r1, ip
	bne _08117C84
	ldrb r0, [r7]
	cmp r0, #0
	bne _08117C84
	cmp r4, #1
	bne _08117C76
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08117CCE
_08117C76:
	cmp r4, #0
	bne _08117C84
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08117CCE
_08117C84:
	mov r1, ip
	strb r1, [r2]
	movs r2, #4
	mov r8, r2
	adds r0, r4, #0
	ands r0, r2
	movs r3, #4
	cmp r0, #0
	beq _08117C98
	movs r3, #6
_08117C98:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	mov r2, ip
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08117CC0
	ldr r0, [r5, #8]
	mov r1, r8
	orrs r0, r1
	b _08117CC8
	.align 2, 0
_08117CB8: .4byte 0x000004B7
_08117CBC: .4byte 0x0000046E
_08117CC0:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08117CC8:
	str r0, [r5, #8]
_08117CCA:
	movs r0, #0
	strb r0, [r7]
_08117CCE:
	ldr r2, [sp, #0x1c]
	ldr r1, _08117CF8 @ =0x000006B6
	adds r0, r2, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	ldr r2, _08117CFC @ =0x00000482
	adds r1, r6, r2
	strh r0, [r1]
	ldr r1, _08117D00 @ =0x0000A02F
	ldr r2, [sp, #0x24]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08117D04
	ldr r0, _08117CFC @ =0x00000482
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08117D14
	.align 2, 0
_08117CF8: .4byte 0x000006B6
_08117CFC: .4byte 0x00000482
_08117D00: .4byte 0x0000A02F
_08117D04:
	ldr r1, _08117D38 @ =0x00000482
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08117D14
	movs r0, #1
	strh r0, [r2]
_08117D14:
	ldr r1, [sp, #0x20]
	ldrb r0, [r1]
	cmp r0, #0
	bne _08117D3C
	ldr r4, [r6, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _08117D54
	.align 2, 0
_08117D38: .4byte 0x00000482
_08117D3C:
	ldr r4, [r6, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_08117D54:
	movs r6, #3
	mov r2, sl
	ands r2, r6
	cmp r2, #0
	bne _08117DA6
	mov r1, sb
	ldrh r0, [r1, #0x10]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	ldr r4, _08117DB8 @ =0xFFFF0000
	ldr r5, _08117DBC @ =0x0000FFFF
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	ldrh r2, [r1, #0x14]
	rsbs r2, r2, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r1, sp, #0xc
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r1, #4]
	ldr r0, [sp, #0x14]
	ands r0, r4
	movs r3, #0x20
	orrs r0, r3
	ands r0, r5
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r4
	orrs r0, r3
	str r0, [r2, #4]
	mov r0, sb
	adds r0, #8
	str r6, [sp]
	movs r3, #4
	str r3, [sp, #4]
	movs r3, #1
	bl FUN_080dbcec
_08117DA6:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08117DB8: .4byte 0xFFFF0000
_08117DBC: .4byte 0x0000FFFF

	thumb_func_start FUN_08117dc0
FUN_08117dc0: @ 0x08117DC0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _08117DDC @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08117DE0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08117DE2
	.align 2, 0
_08117DDC: .4byte 0x0000046D
_08117DE0:
	movs r0, #0
_08117DE2:
	cmp r0, #0
	beq _08117EBE
	mov r4, sp
	adds r4, #5
	adds r0, r5, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_080e5d44
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r1, [r4]
	movs r0, #4
	movs r2, #7
	adds r4, r1, #0
	orrs r4, r0
	ldr r1, _08117E28 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08117E34
	ldr r1, _08117E2C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _08117E30 @ =0x0000046E
	adds r7, r5, r0
	b _08117EB2
	.align 2, 0
_08117E28: .4byte 0x0000025D
_08117E2C: .4byte 0x000004B7
_08117E30: .4byte 0x0000046E
_08117E34:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r3, #7
	ldr r1, _08117EA0 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08117EA4 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _08117E6E
	ldrb r0, [r7]
	cmp r0, #0
	bne _08117E6E
	cmp r4, #1
	bne _08117E60
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08117EB6
_08117E60:
	cmp r4, #0
	bne _08117E6E
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08117EB6
_08117E6E:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08117E80
	movs r3, #6
_08117E80:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08117EA8
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _08117EB0
	.align 2, 0
_08117EA0: .4byte 0x000004B7
_08117EA4: .4byte 0x0000046E
_08117EA8:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08117EB0:
	str r0, [r6, #8]
_08117EB2:
	movs r0, #0
	strb r0, [r7]
_08117EB6:
	ldr r0, _08117EEC @ =0x0000046E
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
_08117EBE:
	ldr r1, _08117EEC @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08117EDE
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, _08117EF0 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _08117EF4 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08117EDE:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08117EEC: .4byte 0x0000046E
_08117EF0: .4byte 0xFFFFFEFF
_08117EF4: .4byte 0x0000046B

	thumb_func_start FUN_08117ef8
FUN_08117ef8: @ 0x08117EF8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	mov sl, r6
	ldr r2, _08117F24 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08117F28
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08117F2A
	.align 2, 0
_08117F24: .4byte 0x0000046D
_08117F28:
	movs r0, #0
_08117F2A:
	cmp r0, #0
	beq _08117F72
	ldr r3, _08117FD4 @ =0x0000046B
	adds r0, r6, r3
	movs r1, #0
	strb r1, [r0]
	ldr r7, _08117FD8 @ =0x0000046E
	adds r0, r6, r7
	strb r1, [r0]
	ldr r0, _08117FDC @ =0x000006C1
	add r0, r8
	strb r1, [r0]
	ldr r0, _08117FE0 @ =0x000006C4
	add r0, r8
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	movs r0, #0xd8
	lsls r0, r0, #3
	add r0, r8
	strb r1, [r0]
	movs r0, #0xda
	lsls r0, r0, #3
	add r0, r8
	mov r3, sl
	ldr r1, [r3, #8]
	ldr r2, [r3, #0xc]
	str r1, [r0]
	str r2, [r0, #4]
	bl FUN_081155a0
_08117F72:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r5, r6, r7
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	mov r4, sp
	adds r4, #5
	adds r0, r6, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_080e5d44
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _08117FE4 @ =0x085AD608
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov sb, r0
	orrs r4, r2
	ldr r1, _08117FE8 @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	str r5, [sp, #0x2c]
	str r0, [sp, #0x30]
	cmp r1, #0
	bne _08117FF0
	ldr r2, _08117FEC @ =0x000004B7
	adds r0, r6, r2
	mov r7, sb
	strb r7, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #8
	bl FUN_08236fac
	ldr r0, _08117FD8 @ =0x0000046E
	adds r7, r6, r0
	b _08118072
	.align 2, 0
_08117FD4: .4byte 0x0000046B
_08117FD8: .4byte 0x0000046E
_08117FDC: .4byte 0x000006C1
_08117FE0: .4byte 0x000006C4
_08117FE4: .4byte 0x085AD608
_08117FE8: .4byte 0x0000025D
_08117FEC: .4byte 0x000004B7
_08117FF0:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r3, #8
	mov sb, r3
	ldr r1, _08118060 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r3, _08118064 @ =0x0000046E
	adds r7, r6, r3
	cmp r1, sb
	bne _0811802C
	ldrb r0, [r7]
	cmp r0, #0
	bne _0811802C
	cmp r4, #1
	bne _0811801E
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08118076
_0811801E:
	cmp r4, #0
	bne _0811802C
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08118076
_0811802C:
	mov r0, sb
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #4
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0811803E
	movs r3, #6
_0811803E:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	mov r2, sb
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08118068
	ldr r0, [r5, #8]
	movs r2, #4
	orrs r0, r2
	b _08118070
	.align 2, 0
_08118060: .4byte 0x000004B7
_08118064: .4byte 0x0000046E
_08118068:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08118070:
	str r0, [r5, #8]
_08118072:
	movs r0, #0
	strb r0, [r7]
_08118076:
	ldr r3, _0811809C @ =0x000006C1
	add r3, r8
	ldrb r2, [r3]
	cmp r2, #0
	beq _08118082
	b _081181A8
_08118082:
	ldr r1, _081180A0 @ =0x000006B6
	add r1, r8
	ldrh r0, [r1]
	subs r0, #0x28
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081180A4
	movs r0, #1
	strb r0, [r3]
	strh r2, [r1]
	b _081183C0
	.align 2, 0
_0811809C: .4byte 0x000006C1
_081180A0: .4byte 0x000006B6
_081180A4:
	movs r3, #0
	ldrsh r5, [r1, r3]
	ldr r4, _08118144 @ =0x085B0A08
	ldr r0, _08118148 @ =0x000006C5
	add r0, r8
	ldrb r2, [r0]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r7, #0
	ldrsh r0, [r0, r7]
	adds r1, r5, #0
	muls r1, r0, r1
	lsrs r1, r1, #0x10
	ldr r3, _0811814C @ =0xFFFF0000
	adds r0, r3, #0
	ldr r7, [sp, #0x20]
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #0x20]
	lsls r2, r2, #1
	adds r2, r2, r4
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r1, r5, #0
	muls r1, r0, r1
	lsrs r1, r1, #0x10
	adds r0, r3, #0
	ldr r2, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r2, sp, #8
	mov r7, sp
	ldrh r0, [r7, #0x20]
	ldrh r1, [r2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #8]
	ldrh r0, [r7, #0x24]
	ldrh r7, [r2, #4]
	adds r0, r0, r7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r2, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r2, #4]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _0811813E
	cmp r1, #0
	blt _0811813E
	ldr r0, _08118150 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _0811813E
	ldr r0, _08118154 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08118158
_0811813E:
	movs r1, #0
	b _08118166
	.align 2, 0
_08118144: .4byte 0x085B0A08
_08118148: .4byte 0x000006C5
_0811814C: .4byte 0xFFFF0000
_08118150: .4byte 0x030046A8
_08118154: .4byte 0x030046AC
_08118158:
	ldr r0, _08118184 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r3
_08118166:
	ldr r2, _08118188 @ =0x00000256
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, r1
	beq _08118194
	ldr r1, _0811818C @ =0x000006B6
	add r1, r8
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08118190 @ =0x000006C1
	add r1, r8
	movs r0, #1
	strb r0, [r1]
	b _08118340
	.align 2, 0
_08118184: .4byte 0x030046A4
_08118188: .4byte 0x00000256
_0811818C: .4byte 0x000006B6
_08118190: .4byte 0x000006C1
_08118194:
	mov r3, sp
	ldrh r0, [r3, #0x20]
	ldrh r7, [r6, #0x10]
	adds r0, r0, r7
	strh r0, [r6, #0x10]
	ldrh r0, [r3, #0x24]
	ldrh r1, [r6, #0x14]
	adds r0, r0, r1
	strh r0, [r6, #0x14]
	b _08118340
_081181A8:
	cmp r2, #1
	beq _081181AE
	b _081182DC
_081181AE:
	ldr r2, _081181F4 @ =0x00000256
	adds r0, r6, r2
	ldrh r5, [r0]
	add r7, sp, #0x10
	ldr r3, _081181F8 @ =0x030046A4
	mov sb, r3
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, sb
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	str r0, [sp, #0x28]
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r7]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	adds r4, r7, #0
	cmp r0, #0
	beq _081181FC
	adds r0, #4
	b _08118208
	.align 2, 0
_081181F4: .4byte 0x00000256
_081181F8: .4byte 0x030046A4
_081181FC:
	mov r3, sb
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08118208:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r7, #2]
	ldr r1, [sp, #0x28]
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r7, #4]
	add r2, sp, #0x18
	adds r3, r6, #0
	adds r3, #8
	add r0, sp, #0x10
	ldrh r0, [r0]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r4, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	ldr r0, _08118250 @ =0x000006C5
	add r0, r8
	ldrb r0, [r0]
	lsrs r0, r0, #6
	cmp r0, #1
	beq _0811828A
	cmp r0, #1
	bgt _08118254
	cmp r0, #0
	beq _0811825E
	b _081182B4
	.align 2, 0
_08118250: .4byte 0x000006C5
_08118254:
	cmp r0, #2
	beq _0811825E
	cmp r0, #3
	beq _0811828A
	b _081182B4
_0811825E:
	movs r0, #0
	strh r0, [r2, #4]
	add r0, sp, #0x18
	ldrh r3, [r0]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #8
	ble _08118276
	movs r0, #8
	mov r1, sl
	strh r0, [r1, #0x10]
	b _081182B4
_08118276:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08118284
	mov r3, sl
	strh r1, [r3, #0x10]
	b _081182B4
_08118284:
	mov r7, sl
	strh r3, [r7, #0x10]
	b _081182B4
_0811828A:
	movs r0, #0
	strh r0, [r2]
	add r0, sp, #0x18
	ldrh r3, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #8
	ble _081182A2
	movs r0, #8
	mov r3, sl
	strh r0, [r3, #0x14]
	b _081182B4
_081182A2:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r0, r1
	bge _081182B0
	mov r7, sl
	strh r1, [r7, #0x14]
	b _081182B4
_081182B0:
	mov r0, sl
	strh r3, [r0, #0x14]
_081182B4:
	movs r1, #0
	ldrsh r0, [r2, r1]
	add r1, sp, #0x18
	movs r2, #4
	ldrsh r1, [r1, r2]
	adds r2, r0, r1
	cmp r2, #0
	bne _08118340
	ldr r0, _081182D4 @ =0x000006C1
	add r0, r8
	movs r1, #2
	strb r1, [r0]
	ldr r0, _081182D8 @ =0x000006C3
	add r0, r8
	strb r2, [r0]
	b _081183C0
	.align 2, 0
_081182D4: .4byte 0x000006C1
_081182D8: .4byte 0x000006C3
_081182DC:
	ldr r4, _0811832C @ =0x000006C3
	add r4, r8
	ldrb r0, [r4]
	adds r0, #1
	movs r5, #0
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _08118340
	movs r2, #0xda
	lsls r2, r2, #3
	add r2, r8
	movs r0, #0xd9
	lsls r0, r0, #3
	add r0, r8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, r8
	bl FUN_081155c4
	ldr r2, _08118330 @ =0x000006C2
	add r2, r8
	ldrb r1, [r2]
	ldr r0, _08118334 @ =0x000006C4
	add r0, r8
	strb r1, [r0]
	ldrb r0, [r2]
	strb r0, [r6, #5]
	ldr r3, _08118338 @ =0x0000046B
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	strb r5, [r4]
	ldr r0, _0811833C @ =0x000006B6
	add r0, r8
	strh r5, [r0]
	b _081183C0
	.align 2, 0
_0811832C: .4byte 0x000006C3
_08118330: .4byte 0x000006C2
_08118334: .4byte 0x000006C4
_08118338: .4byte 0x0000046B
_0811833C: .4byte 0x000006B6
_08118340:
	movs r0, #0xd7
	lsls r0, r0, #3
	add r0, r8
	ldrh r0, [r0]
	lsrs r0, r0, #7
	ldr r7, _08118368 @ =0x00000482
	adds r1, r6, r7
	strh r0, [r1]
	ldr r1, _0811836C @ =0x0000A02F
	ldr r2, [sp, #0x2c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08118370
	adds r3, r7, #0
	adds r1, r6, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08118380
	.align 2, 0
_08118368: .4byte 0x00000482
_0811836C: .4byte 0x0000A02F
_08118370:
	ldr r7, _081183A4 @ =0x00000482
	adds r0, r6, r7
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08118380
	movs r0, #1
	strh r0, [r2]
_08118380:
	ldr r1, [sp, #0x30]
	ldrb r0, [r1]
	cmp r0, #0
	bne _081183A8
	ldr r4, [r6, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _081183C0
	.align 2, 0
_081183A4: .4byte 0x00000482
_081183A8:
	ldr r4, [r6, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_081183C0:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081183d0
FUN_081183d0: @ 0x081183D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r5, r0, #0
	mov sb, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	str r5, [sp, #0x1c]
	ldr r2, _08118400 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08118404
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08118406
	.align 2, 0
_08118400: .4byte 0x0000046D
_08118404:
	movs r0, #0
_08118406:
	cmp r0, #0
	beq _0811841A
	ldr r3, _0811846C @ =0x0000046E
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	movs r0, #0xcd
	lsls r0, r0, #3
	add r0, sl
	strh r1, [r0]
_0811841A:
	mov r4, sp
	adds r4, #9
	adds r0, r5, #0
	add r1, sp, #8
	adds r2, r4, #0
	bl FUN_080e5d44
	add r0, sp, #8
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _08118470 @ =0x085AD608
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _08118474 @ =0x0000025D
	adds r0, r5, r1
	ldrb r1, [r0]
	str r0, [sp, #0x20]
	cmp r1, #0
	bne _0811847C
	ldr r2, _08118478 @ =0x000004B7
	adds r0, r5, r2
	mov r1, ip
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #8
	bl FUN_08236fac
	ldr r2, _0811846C @ =0x0000046E
	adds r7, r5, r2
	b _081184FE
	.align 2, 0
_0811846C: .4byte 0x0000046E
_08118470: .4byte 0x085AD608
_08118474: .4byte 0x0000025D
_08118478: .4byte 0x000004B7
_0811847C:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r3, #8
	mov ip, r3
	ldr r3, _081184EC @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r0, _081184F0 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, ip
	bne _081184B8
	ldrb r0, [r7]
	cmp r0, #0
	bne _081184B8
	cmp r4, #1
	bne _081184AA
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08118502
_081184AA:
	cmp r4, #0
	bne _081184B8
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08118502
_081184B8:
	mov r1, ip
	strb r1, [r2]
	movs r2, #4
	mov r8, r2
	adds r0, r4, #0
	ands r0, r2
	movs r3, #4
	cmp r0, #0
	beq _081184CC
	movs r3, #6
_081184CC:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	mov r2, ip
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081184F4
	ldr r0, [r6, #8]
	mov r3, r8
	orrs r0, r3
	b _081184FC
	.align 2, 0
_081184EC: .4byte 0x000004B7
_081184F0: .4byte 0x0000046E
_081184F4:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081184FC:
	str r0, [r6, #8]
_081184FE:
	movs r0, #0
	strb r0, [r7]
_08118502:
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #3
	mov r1, sb
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	bne _081185EE
	ldr r2, _08118560 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08118564 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08118568 @ =0x0203B400
	adds r0, r0, r3
	movs r1, #0xff
	ldrb r4, [r0]
	ldr r3, _0811856C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	adds r6, r2, #0
	cmp r0, #0
	blt _08118570
	asrs r0, r1, #0x18
	b _08118576
	.align 2, 0
_08118560: .4byte 0x030046B8
_08118564: .4byte 0x000003FF
_08118568: .4byte 0x0203B400
_0811856C: .4byte 0x085B0A08
_08118570:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08118576:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r2, r0, #0x10
	asrs r0, r2, #0x10
	cmp r0, #0
	blt _08118598
	asrs r0, r2, #0x18
	b _0811859E
_08118598:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0811859E:
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _08118624 @ =0xFFFF0000
	add r1, sp, #0xc
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	ldr r0, [sp, #0x14]
	ands r0, r3
	movs r4, #0x30
	orrs r0, r4
	ldr r2, _08118628 @ =0x0000FFFF
	ands r0, r2
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	ldr r0, [r6]
	adds r0, #1
	ldr r3, _0811862C @ =0x000003FF
	ands r0, r3
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _08118630 @ =0x0203B400
	adds r0, r0, r3
	ldrh r3, [r0]
	movs r0, #1
	ands r3, r0
	adds r3, #2
	ldr r0, [sp, #0x1c]
	adds r0, #8
	str r3, [sp]
	movs r3, #4
	str r3, [sp, #4]
	movs r3, #2
	bl FUN_080dbcec
_081185EE:
	ldr r2, _08118634 @ =0x000006B6
	add r2, sl
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _08118638 @ =0x0000017F
	cmp r1, r0
	bgt _08118604
	adds r0, r3, #0
	adds r0, #0x10
	strh r0, [r2]
_08118604:
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	ldr r2, _0811863C @ =0x00000482
	adds r1, r5, r2
	strh r0, [r1]
	ldr r1, _08118640 @ =0x0000A02F
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _08118644
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08118654
	.align 2, 0
_08118624: .4byte 0xFFFF0000
_08118628: .4byte 0x0000FFFF
_0811862C: .4byte 0x000003FF
_08118630: .4byte 0x0203B400
_08118634: .4byte 0x000006B6
_08118638: .4byte 0x0000017F
_0811863C: .4byte 0x00000482
_08118640: .4byte 0x0000A02F
_08118644:
	ldr r3, _08118678 @ =0x00000482
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08118654
	movs r0, #1
	strh r0, [r2]
_08118654:
	ldr r1, [sp, #0x20]
	ldrb r0, [r1]
	cmp r0, #0
	bne _0811867C
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _08118694
	.align 2, 0
_08118678: .4byte 0x00000482
_0811867C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_08118694:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081186a4
FUN_081186a4: @ 0x081186A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r7, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x2c]
	mov sl, r7
	ldr r2, _081186D4 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081186D8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081186DA
	.align 2, 0
_081186D4: .4byte 0x0000046D
_081186D8:
	movs r0, #0
_081186DA:
	cmp r0, #0
	beq _081186E6
	adds r0, r7, #0
	movs r1, #4
	bl FUN_080e81dc
_081186E6:
	adds r0, r7, #0
	movs r1, #0x10
	bl FUN_080ef86c
	movs r6, #0x20
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	adds r0, r6, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #6
	subs r3, #0xa
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, [sp, #0x2c]
	ldr r1, _081187E4 @ =0x000006B6
	adds r3, r0, r1
	movs r0, #0
	ldrsh r2, [r3, r0]
	ldr r4, _081187E8 @ =0x085B0A08
	mov r1, sl
	ldrb r0, [r1, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	asrs r0, r0, #0x10
	ldrh r2, [r7, #0x10]
	adds r0, r0, r2
	strh r0, [r7, #0x10]
	movs r0, #0
	ldrsh r1, [r3, r0]
	mov r2, sl
	ldrb r0, [r2, #5]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	asrs r0, r0, #0x10
	ldrh r1, [r7, #0x14]
	adds r0, r0, r1
	strh r0, [r7, #0x14]
	movs r4, #3
	ands r5, r4
	cmp r5, #0
	bne _081187AC
	ldrh r0, [r2, #0x10]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	ldr r3, _081187EC @ =0xFFFF0000
	ldr r2, _081187F0 @ =0x0000FFFF
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	mov r5, sl
	ldrh r0, [r5, #0x14]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r6
	ands r0, r2
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r6
	str r0, [r2, #4]
	mov r0, sl
	adds r0, #8
	str r4, [sp]
	movs r1, #4
	str r1, [sp, #4]
	add r1, sp, #0xc
	movs r3, #1
	bl FUN_080dbcec
_081187AC:
	adds r0, r7, #0
	adds r0, #0x8c
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081187BC
	b _0811899E
_081187BC:
	ldr r0, [sp, #0x2c]
	movs r2, #0xdc
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r3, [sp, #0x2c]
	ldr r5, _081187F4 @ =0x000006E2
	adds r1, r3, r5
	movs r0, #0x14
	strh r0, [r1]
	mov r1, sl
	movs r2, #0x14
	ldrsh r0, [r1, r2]
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _081187F8
	asrs r0, r1, #0x12
	b _081187FE
	.align 2, 0
_081187E4: .4byte 0x000006B6
_081187E8: .4byte 0x085B0A08
_081187EC: .4byte 0xFFFF0000
_081187F0: .4byte 0x0000FFFF
_081187F4: .4byte 0x000006E2
_081187F8:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081187FE:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08118844 @ =0xFFFF0000
	ldr r2, [sp, #0x1c]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0x1c]
	ldr r3, _08118848 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0811884C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r5, _08118850 @ =0x0203B400
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #0x10
	ldr r0, _08118854 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	mov r1, sl
	movs r2, #0x10
	ldrsh r0, [r1, r2]
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	mov ip, r3
	cmp r0, #0
	blt _08118858
	asrs r0, r1, #0x12
	b _0811885E
	.align 2, 0
_08118844: .4byte 0xFFFF0000
_08118848: .4byte 0x030046B8
_0811884C: .4byte 0x000003FF
_08118850: .4byte 0x0203B400
_08118854: .4byte 0x0000FFFF
_08118858:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0811885E:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _08118924 @ =0xFFFF0000
	mov r8, r3
	add r5, sp, #0x1c
	mov sb, r5
	ldr r0, [r5, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r5, #4]
	ldr r6, _08118928 @ =0x0203B400
	mov r0, ip
	ldr r2, [r0]
	adds r2, #1
	ldr r4, _0811892C @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #0xf
	ldr r0, [sp, #0x24]
	mov r5, r8
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0x24]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0xf
	lsls r1, r1, #0x10
	ldr r3, _08118930 @ =0x0000FFFF
	ldr r0, [sp, #0x24]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x24]
	adds r2, #1
	ands r2, r4
	mov r1, ip
	str r2, [r1]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r1, [r2]
	movs r2, #3
	ands r1, r2
	adds r1, #0xf
	add r5, sp, #0x24
	ldr r0, [r5, #4]
	mov r3, r8
	ands r0, r3
	orrs r0, r1
	str r0, [r5, #4]
	mov r1, ip
	ldr r0, [r1]
	adds r0, #1
	ands r0, r4
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r4, [r0]
	movs r0, #3
	ands r4, r0
	adds r4, #4
	adds r0, r7, #0
	bl FUN_080f8abc
	adds r1, r0, #0
	mov r2, sl
	adds r2, #8
	str r5, [sp]
	movs r0, #0x2d
	str r0, [sp, #4]
	movs r0, #0x1f
	str r0, [sp, #8]
	adds r0, r4, #0
	mov r3, sb
	bl FUN_08014730
	adds r0, r7, #0
	movs r1, #5
	bl FUN_080e81dc
	ldr r2, [sp, #0x2c]
	movs r3, #0xcd
	lsls r3, r3, #3
	adds r0, r2, r3
	ldrh r4, [r0]
	cmp r4, #0
	beq _08118938
	ldr r5, _08118934 @ =0x0000046B
	adds r1, r7, r5
	movs r0, #1
	strb r0, [r1]
	b _0811899E
	.align 2, 0
_08118924: .4byte 0xFFFF0000
_08118928: .4byte 0x0203B400
_0811892C: .4byte 0x000003FF
_08118930: .4byte 0x0000FFFF
_08118934: .4byte 0x0000046B
_08118938:
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r3, #0
	movs r0, #0xb4
	strh r0, [r1]
	movs r2, #1
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r5, #3
	strb r5, [r0]
	adds r1, #1
	adds r0, r7, r1
	strb r3, [r0]
	ldr r5, _081189B0 @ =0x0000046A
	adds r0, r7, r5
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r4, [r0]
	adds r5, #2
	adds r0, r7, r5
	strb r2, [r0]
	ldr r1, _081189B4 @ =0x00000594
	adds r0, r7, r1
	ldr r1, [r0]
	adds r5, #1
	adds r0, r7, r5
	strb r2, [r0]
	ldr r2, _081189B8 @ =0x0000046B
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _081189BC @ =0x00000553
	adds r0, r7, r3
	movs r5, #7
	strb r5, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r1, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r4, [r0]
_0811899E:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081189B0: .4byte 0x0000046A
_081189B4: .4byte 0x00000594
_081189B8: .4byte 0x0000046B
_081189BC: .4byte 0x00000553

	thumb_func_start FUN_081189c0
FUN_081189c0: @ 0x081189C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	mov sb, r6
	ldr r2, _081189EC @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081189F0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081189F2
	.align 2, 0
_081189EC: .4byte 0x0000046D
_081189F0:
	movs r0, #0
_081189F2:
	cmp r0, #0
	beq _08118A34
	ldr r3, _08118AA8 @ =0x0000046E
	adds r0, r6, r3
	movs r1, #0
	strb r1, [r0]
	ldr r5, _08118AAC @ =0x000006C1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _08118AB0 @ =0x000006C2
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	movs r2, #0xd8
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	movs r3, #0xda
	lsls r3, r3, #3
	adds r0, r7, r3
	mov r5, sb
	ldr r1, [r5, #8]
	ldr r2, [r5, #0xc]
	str r1, [r0]
	str r2, [r0, #4]
	bl FUN_081155a0
_08118A34:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r5, r6, r1
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r4, sp
	adds r4, #5
	adds r0, r6, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_080e5d44
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _08118AB4 @ =0x085AD608
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _08118AB8 @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	str r5, [sp, #0x10]
	str r0, [sp, #0x14]
	cmp r1, #0
	bne _08118AC0
	ldr r2, _08118ABC @ =0x000004B7
	adds r0, r6, r2
	mov r5, ip
	strb r5, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #8
	bl FUN_08236fac
	ldr r0, _08118AA8 @ =0x0000046E
	adds r0, r0, r6
	mov r8, r0
	b _08118B46
	.align 2, 0
_08118AA8: .4byte 0x0000046E
_08118AAC: .4byte 0x000006C1
_08118AB0: .4byte 0x000006C2
_08118AB4: .4byte 0x085AD608
_08118AB8: .4byte 0x0000025D
_08118ABC: .4byte 0x000004B7
_08118AC0:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r3, #8
	mov ip, r3
	ldr r1, _08118B34 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r3, _08118B38 @ =0x0000046E
	adds r3, r3, r6
	mov r8, r3
	cmp r1, ip
	bne _08118AFE
	ldrb r0, [r3]
	cmp r0, #0
	bne _08118AFE
	cmp r4, #1
	bne _08118AF0
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08118B4C
_08118AF0:
	cmp r4, #0
	bne _08118AFE
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08118B4C
_08118AFE:
	mov r0, ip
	strb r0, [r2]
	movs r1, #4
	mov sl, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08118B12
	movs r3, #6
_08118B12:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	mov r2, ip
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08118B3C
	ldr r0, [r5, #8]
	mov r2, sl
	orrs r0, r2
	b _08118B44
	.align 2, 0
_08118B34: .4byte 0x000004B7
_08118B38: .4byte 0x0000046E
_08118B3C:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08118B44:
	str r0, [r5, #8]
_08118B46:
	movs r0, #0
	mov r3, r8
	strb r0, [r3]
_08118B4C:
	ldr r5, _08118B6C @ =0x000006C1
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _08118C0C
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq _08118B78
	cmp r0, #1
	bgt _08118B70
	cmp r0, #0
	beq _08118B88
	b _08118B98
	.align 2, 0
_08118B6C: .4byte 0x000006C1
_08118B70:
	cmp r0, #3
	beq _08118B78
	cmp r0, #5
	bne _08118B98
_08118B78:
	ldr r2, _08118B84 @ =0x000006B6
	adds r1, r7, r2
	ldrh r0, [r1]
	subs r0, #0xc0
	b _08118BA0
	.align 2, 0
_08118B84: .4byte 0x000006B6
_08118B88:
	ldr r3, _08118B94 @ =0x000006B6
	adds r1, r7, r3
	ldrh r0, [r1]
	subs r0, #0x40
	b _08118BA0
	.align 2, 0
_08118B94: .4byte 0x000006B6
_08118B98:
	ldr r5, _08118BBC @ =0x000006B6
	adds r1, r7, r5
	ldrh r0, [r1]
	subs r0, #0x80
_08118BA0:
	strh r0, [r1]
	ldr r0, _08118BBC @ =0x000006B6
	adds r5, r7, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _08118BC4
	ldr r2, _08118BC0 @ =0x000006C1
	adds r0, r7, r2
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	strh r2, [r5]
	b _08118D8C
	.align 2, 0
_08118BBC: .4byte 0x000006B6
_08118BC0: .4byte 0x000006C1
_08118BC4:
	movs r0, #0
	ldrsh r3, [r5, r0]
	ldr r4, _08118C04 @ =0x085B0A08
	ldr r1, _08118C08 @ =0x000006C2
	adds r2, r7, r1
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	asrs r0, r0, #0x10
	ldrh r3, [r6, #0x10]
	adds r0, r0, r3
	strh r0, [r6, #0x10]
	movs r0, #0
	ldrsh r1, [r5, r0]
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	asrs r0, r0, #0x10
	ldrh r3, [r6, #0x14]
	adds r0, r0, r3
	strh r0, [r6, #0x14]
	b _08118D0C
	.align 2, 0
_08118C04: .4byte 0x085B0A08
_08118C08: .4byte 0x000006C2
_08118C0C:
	cmp r0, #1
	bne _08118CD8
	add r3, sp, #8
	mov r4, sb
	adds r4, #8
	movs r5, #0xda
	lsls r5, r5, #3
	adds r2, r7, r5
	ldrh r0, [r2]
	mov r5, sb
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r1, _08118C4C @ =0x000006C5
	adds r0, r7, r1
	ldrb r0, [r0]
	lsrs r0, r0, #6
	cmp r0, #1
	beq _08118C86
	cmp r0, #1
	bgt _08118C50
	cmp r0, #0
	beq _08118C5A
	b _08118CB0
	.align 2, 0
_08118C4C: .4byte 0x000006C5
_08118C50:
	cmp r0, #2
	beq _08118C5A
	cmp r0, #3
	beq _08118C86
	b _08118CB0
_08118C5A:
	movs r0, #0
	strh r0, [r3, #4]
	add r0, sp, #8
	ldrh r2, [r0]
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #8
	ble _08118C72
	movs r0, #8
	mov r1, sb
	strh r0, [r1, #0x10]
	b _08118CB0
_08118C72:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08118C80
	mov r2, sb
	strh r1, [r2, #0x10]
	b _08118CB0
_08118C80:
	mov r5, sb
	strh r2, [r5, #0x10]
	b _08118CB0
_08118C86:
	movs r0, #0
	strh r0, [r3]
	add r0, sp, #8
	ldrh r2, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #8
	ble _08118C9E
	movs r0, #8
	mov r2, sb
	strh r0, [r2, #0x14]
	b _08118CB0
_08118C9E:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08118CAC
	mov r5, sb
	strh r1, [r5, #0x14]
	b _08118CB0
_08118CAC:
	mov r0, sb
	strh r2, [r0, #0x14]
_08118CB0:
	movs r1, #0
	ldrsh r0, [r3, r1]
	add r1, sp, #8
	movs r2, #4
	ldrsh r1, [r1, r2]
	adds r3, r0, r1
	cmp r3, #0
	bne _08118D0C
	ldr r5, _08118CD0 @ =0x000006C1
	adds r0, r7, r5
	movs r1, #2
	strb r1, [r0]
	ldr r1, _08118CD4 @ =0x000006C3
	adds r0, r7, r1
	strb r3, [r0]
	b _08118D8C
	.align 2, 0
_08118CD0: .4byte 0x000006C1
_08118CD4: .4byte 0x000006C3
_08118CD8:
	ldr r3, _08118D00 @ =0x000006C3
	adds r2, r7, r3
	ldrb r0, [r2]
	adds r0, #1
	movs r3, #0
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _08118D0C
	ldr r5, _08118D04 @ =0x0000046B
	adds r0, r6, r5
	movs r1, #1
	strb r1, [r0]
	strb r3, [r2]
	ldr r1, _08118D08 @ =0x000006B6
	adds r0, r7, r1
	strh r3, [r0]
	b _08118D8C
	.align 2, 0
_08118D00: .4byte 0x000006C3
_08118D04: .4byte 0x0000046B
_08118D08: .4byte 0x000006B6
_08118D0C:
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	lsrs r0, r0, #7
	ldr r3, _08118D34 @ =0x00000482
	adds r1, r6, r3
	strh r0, [r1]
	ldr r1, _08118D38 @ =0x0000A02F
	ldr r5, [sp, #0x10]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08118D3C
	adds r1, r6, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08118D4C
	.align 2, 0
_08118D34: .4byte 0x00000482
_08118D38: .4byte 0x0000A02F
_08118D3C:
	ldr r1, _08118D70 @ =0x00000482
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08118D4C
	movs r0, #1
	strh r0, [r2]
_08118D4C:
	ldr r3, [sp, #0x14]
	ldrb r0, [r3]
	cmp r0, #0
	bne _08118D74
	ldr r4, [r6, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _08118D8C
	.align 2, 0
_08118D70: .4byte 0x00000482
_08118D74:
	ldr r4, [r6, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_08118D8C:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08118d9c
FUN_08118d9c: @ 0x08118D9C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	mov sl, r6
	ldr r2, _08118DC8 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08118DCC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08118DCE
	.align 2, 0
_08118DC8: .4byte 0x0000046D
_08118DCC:
	movs r0, #0
_08118DCE:
	cmp r0, #0
	bne _08118DD4
	b _08118ED8
_08118DD4:
	ldrb r5, [r6, #5]
	ldr r0, _08118E30 @ =0x000006C5
	add r0, r8
	ldrb r0, [r0]
	strb r0, [r6, #5]
	mov r4, sp
	adds r4, #5
	adds r0, r6, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_080e5d44
	strb r5, [r6, #5]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _08118E34 @ =0x085AD608
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _08118E38 @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08118E44
	ldr r2, _08118E3C @ =0x000004B7
	adds r0, r6, r2
	mov r1, ip
	strb r1, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #8
	bl FUN_08236fac
	ldr r2, _08118E40 @ =0x0000046E
	adds r7, r6, r2
	b _08118EC6
	.align 2, 0
_08118E30: .4byte 0x000006C5
_08118E34: .4byte 0x085AD608
_08118E38: .4byte 0x0000025D
_08118E3C: .4byte 0x000004B7
_08118E40: .4byte 0x0000046E
_08118E44:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r3, #8
	mov ip, r3
	ldr r3, _08118EB4 @ =0x000004B7
	adds r0, r6, r3
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r0, _08118EB8 @ =0x0000046E
	adds r7, r6, r0
	cmp r1, ip
	bne _08118E80
	ldrb r0, [r7]
	cmp r0, #0
	bne _08118E80
	cmp r4, #1
	bne _08118E72
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08118ECA
_08118E72:
	cmp r4, #0
	bne _08118E80
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08118ECA
_08118E80:
	mov r1, ip
	strb r1, [r2]
	movs r2, #4
	mov sb, r2
	adds r0, r4, #0
	ands r0, r2
	movs r3, #4
	cmp r0, #0
	beq _08118E94
	movs r3, #6
_08118E94:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	mov r2, ip
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08118EBC
	ldr r0, [r5, #8]
	mov r3, sb
	orrs r0, r3
	b _08118EC4
	.align 2, 0
_08118EB4: .4byte 0x000004B7
_08118EB8: .4byte 0x0000046E
_08118EBC:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08118EC4:
	str r0, [r5, #8]
_08118EC6:
	movs r0, #0
	strb r0, [r7]
_08118ECA:
	ldr r1, _08118F20 @ =0x0000046E
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, _08118F24 @ =0x000006C3
	add r0, r8
	strb r1, [r0]
_08118ED8:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _08118F28 @ =0x085B0A08
	ldr r0, _08118F2C @ =0x000006C5
	add r0, r8
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, _08118F30 @ =0x000006B6
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08118F34
	asrs r0, r0, #0x10
	b _08118F3A
	.align 2, 0
_08118F20: .4byte 0x0000046E
_08118F24: .4byte 0x000006C3
_08118F28: .4byte 0x085B0A08
_08118F2C: .4byte 0x000006C5
_08118F30: .4byte 0x000006B6
_08118F34:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_08118F3A:
	adds r3, r0, #0
	ldr r0, _08118F5C @ =0x000006C5
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08118F60 @ =0x000006B6
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _08118F64
	asrs r0, r0, #0x10
	b _08118F6A
	.align 2, 0
_08118F5C: .4byte 0x000006C5
_08118F60: .4byte 0x000006B6
_08118F64:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_08118F6A:
	adds r2, r3, #0
	cmp r3, #0
	bge _08118F72
	rsbs r2, r3, #0
_08118F72:
	adds r1, r0, #0
	cmp r0, #0
	bge _08118F7A
	rsbs r1, r0, #0
_08118F7A:
	cmp r2, r1
	bge _08118F84
	mov r3, sl
	strh r0, [r3, #0x14]
	b _08118F88
_08118F84:
	mov r0, sl
	strh r3, [r0, #0x10]
_08118F88:
	ldr r2, _08118FB8 @ =0x000006B6
	add r2, r8
	ldrh r1, [r2]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bgt _08118FC4
	movs r3, #0
	strh r3, [r2]
	ldr r1, _08118FBC @ =0x000006C3
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bls _08118FCA
	ldr r0, _08118FC0 @ =0x0000046B
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	strh r3, [r2]
	b _08118FCA
	.align 2, 0
_08118FB8: .4byte 0x000006B6
_08118FBC: .4byte 0x000006C3
_08118FC0: .4byte 0x0000046B
_08118FC4:
	adds r0, r1, #0
	subs r0, #0x10
	strh r0, [r2]
_08118FCA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08118fdc
FUN_08118fdc: @ 0x08118FDC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r2, _08119008 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811900C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811900E
	.align 2, 0
_08119008: .4byte 0x0000046D
_0811900C:
	movs r0, #0
_0811900E:
	cmp r0, #0
	beq _08119022
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r3, _081190D4 @ =0x0000046E
	adds r1, r4, r3
	movs r0, #0
	strb r0, [r1]
_08119022:
	cmp r6, #0x3c
	bgt _08119028
	b _08119190
_08119028:
	ldr r6, _081190D4 @ =0x0000046E
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _08119034
	b _081191AC
_08119034:
	ldr r1, _081190D8 @ =0x0000046B
	adds r0, r4, r1
	movs r6, #0
	movs r7, #1
	strb r7, [r0]
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _081190F4
	ldr r3, _081190DC @ =0x000004A4
	adds r0, r4, r3
	ldr r0, [r0]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl FUN_080e6304
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r3, _081190E0 @ =0x0000046D
	adds r0, r4, r3
	strb r7, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r1, #0
	strh r6, [r0]
	movs r2, #0xc
	subs r3, #0xeb
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _081190E4 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _081190E8 @ =0x00000484
	adds r0, r4, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	movs r0, #4
	ldr r6, _081190EC @ =0x00000222
	adds r2, r4, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _081190F0 @ =0x00000482
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1]
	b _081191AC
	.align 2, 0
_081190D4: .4byte 0x0000046E
_081190D8: .4byte 0x0000046B
_081190DC: .4byte 0x000004A4
_081190E0: .4byte 0x0000046D
_081190E4: .4byte 0x0000046A
_081190E8: .4byte 0x00000484
_081190EC: .4byte 0x00000222
_081190F0: .4byte 0x00000482
_081190F4:
	movs r0, #0xd1
	lsls r0, r0, #3
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08119178 @ =0x0000068C
	add r0, r8
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl FUN_080e6304
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r1, _0811917C @ =FUN_080e48d0
	movs r3, #0x10
	ldr r6, _08119180 @ =0x0000046D
	adds r0, r4, r6
	strb r7, [r0]
	ldr r2, _08119184 @ =0x0000046B
	adds r0, r4, r2
	strb r5, [r0]
	adds r6, #0xe6
	adds r0, r4, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r1, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r4, r6
	movs r2, #0
	strh r5, [r0]
	movs r1, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r2, [r0]
	adds r6, #1
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _08119188 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _0811918C @ =0x00000484
	adds r0, r4, r2
	str r5, [r0]
	adds r6, #3
	adds r0, r4, r6
	strb r7, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	movs r2, #0x81
	lsls r2, r2, #2
	adds r1, r4, r2
	adds r0, r4, #0
	bl FUN_08115bbc
	b _081191AC
	.align 2, 0
_08119178: .4byte 0x0000068C
_0811917C: .4byte FUN_080e48d0
_08119180: .4byte 0x0000046D
_08119184: .4byte 0x0000046B
_08119188: .4byte 0x0000046A
_0811918C: .4byte 0x00000484
_08119190:
	ldrh r0, [r5, #8]
	cmp r0, #2
	bne _081191AC
	ldrh r1, [r5, #0xe]
	ldrb r2, [r5, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _081191AC
	cmp r2, #1
	beq _081191AC
	movs r0, #0
	strh r0, [r5, #0xe]
_081191AC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081191b8
FUN_081191b8: @ 0x081191B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r7, r0, #0
	adds r5, r1, #0
	ldr r0, [r7, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	ldr r0, _081191E0 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081191E4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081191E6
	.align 2, 0
_081191E0: .4byte 0x0000046D
_081191E4:
	movs r0, #0
_081191E6:
	cmp r0, #0
	beq _081191F2
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_081191F2:
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	cmp r5, #0x13
	bgt _0811921E
	ldrh r3, [r4, #8]
	cmp r3, #0
	bne _0811921E
	ldrh r1, [r4, #0xe]
	ldrb r2, [r4, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _0811921E
	cmp r2, #1
	beq _0811921E
	strh r3, [r4, #0xe]
_0811921E:
	ldr r2, _08119310 @ =0x0000046E
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0811922C
	bl _08119A0C
_0811922C:
	ldr r3, _08119314 @ =0x0000046B
	adds r0, r7, r3
	movs r4, #0
	movs r5, #1
	strb r5, [r0]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r0, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #8]
	strb r0, [r1]
	ldr r2, _08119318 @ =0x00000469
	adds r2, r7, r2
	str r2, [sp, #0xc]
	strb r5, [r2]
	ldr r3, _0811931C @ =0x0000046A
	adds r3, r7, r3
	str r3, [sp, #0x10]
	strb r4, [r3]
	ldr r5, _08119320 @ =0x00000484
	adds r5, r5, r7
	mov ip, r5
	str r4, [r5]
	ldr r0, _08119324 @ =0x0000046C
	adds r0, r0, r7
	mov sl, r0
	movs r1, #1
	strb r1, [r0]
	ldr r1, _08119328 @ =FUN_080e6794
	movs r0, #0xe
	ldr r2, _0811932C @ =0x0000046D
	adds r3, r7, r2
	movs r5, #1
	strb r5, [r3]
	subs r2, #2
	adds r2, r2, r7
	mov sb, r2
	strb r4, [r2]
	ldr r5, _08119330 @ =0x00000553
	adds r5, r5, r7
	mov r8, r5
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r6, r7, r0
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	strh r4, [r5]
	movs r0, #0x80
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	str r3, [sp, #0x2c]
	ldr r0, [sp, #8]
	str r0, [sp, #0x18]
	ldr r3, [sp, #0xc]
	str r3, [sp, #0x1c]
	ldr r4, [sp, #0x10]
	str r4, [sp, #0x20]
	mov r0, ip
	str r0, [sp, #0x34]
	mov r3, sl
	str r3, [sp, #0x28]
	mov r4, sb
	str r4, [sp, #0x24]
	mov r0, r8
	str r0, [sp, #0x4c]
	str r6, [sp, #0x54]
	str r5, [sp, #0x50]
	mov sl, r2
	cmp r1, #0
	bne _081192CE
	b _0811987C
_081192CE:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r3, r7, r1
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _0811930A
	cmp r1, #0
	blt _0811930A
	ldr r0, _08119334 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0811930A
	ldr r0, _08119338 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811933C
_0811930A:
	movs r4, #0
	b _0811934A
	.align 2, 0
_08119310: .4byte 0x0000046E
_08119314: .4byte 0x0000046B
_08119318: .4byte 0x00000469
_0811931C: .4byte 0x0000046A
_08119320: .4byte 0x00000484
_08119324: .4byte 0x0000046C
_08119328: .4byte FUN_080e6794
_0811932C: .4byte 0x0000046D
_08119330: .4byte 0x00000553
_08119334: .4byte 0x030046A8
_08119338: .4byte 0x030046AC
_0811933C:
	ldr r0, _0811935C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0811934A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08119360
	adds r0, #4
	b _0811936C
	.align 2, 0
_0811935C: .4byte 0x030046A4
_08119360:
	ldr r0, _08119380 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811936C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08119384
	cmp r2, #2
	beq _08119388
	b _0811938C
	.align 2, 0
_08119380: .4byte 0x030046A4
_08119384:
	ldrb r0, [r5, #4]
	b _0811938A
_08119388:
	ldrb r0, [r5]
_0811938A:
	subs r1, r1, r0
_0811938C:
	strh r1, [r5, #2]
	ldr r0, _081193A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081193A4
	movs r0, #1
	b _081193A6
	.align 2, 0
_081193A0: .4byte 0x030047A4
_081193A4:
	movs r0, #0
_081193A6:
	cmp r0, #0
	beq _081193E4
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _081193C6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081193C2
	adds r2, r0, #0
_081193C2:
	cmp r2, #0
	bge _081193D0
_081193C6:
	ldr r3, _081193CC @ =0x000005C4
	adds r0, r7, r3
	b _08119824
	.align 2, 0
_081193CC: .4byte 0x000005C4
_081193D0:
	ldr r1, _081193E0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811942C
	.align 2, 0
_081193E0: .4byte 0x03002BE0
_081193E4:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08119410
	cmp r1, #0
	blt _08119410
	ldr r0, _08119414 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08119410
	ldr r0, _08119418 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811941C
_08119410:
	movs r5, #0
	b _0811942A
	.align 2, 0
_08119414: .4byte 0x030046A8
_08119418: .4byte 0x030046AC
_0811941C:
	ldr r0, _08119464 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811942A:
	movs r2, #0
_0811942C:
	ldr r1, _08119468 @ =0x00000256
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811944C
	ldr r1, _0811946C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811944C
	b _08119764
_0811944C:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08119470
	movs r0, #0
	b _0811983A
	.align 2, 0
_08119464: .4byte 0x030046A4
_08119468: .4byte 0x00000256
_0811946C: .4byte 0x03002BE0
_08119470:
	ldr r3, _081194CC @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _081194D0
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x2c]
	strb r2, [r3]
	ldr r3, [sp, #0x24]
	strb r5, [r3]
	ldr r3, [sp, #0x4c]
	strb r0, [r3]
	ldr r0, [sp, #0x54]
	str r1, [r0]
	ldr r1, [sp, #0x50]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x18]
	strb r5, [r3]
	ldr r1, [sp, #0x1c]
	strb r5, [r1]
	ldr r3, [sp, #0x20]
	strb r0, [r3]
	ldr r5, [sp, #0x34]
	str r4, [r5]
	ldr r0, [sp, #0x28]
	strb r2, [r0]
	b _0811961E
	.align 2, 0
_081194CC: .4byte 0x00000222
_081194D0:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x2c]
	strb r0, [r2]
	ldr r4, [sp, #0x24]
	strb r5, [r4]
	ldr r2, [sp, #0x4c]
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	str r1, [r4]
	ldr r1, [sp, #0x50]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x18]
	strb r5, [r2]
	ldr r4, [sp, #0x1c]
	strb r5, [r4]
	ldr r5, [sp, #0x20]
	strb r1, [r5]
	ldr r1, [sp, #0x34]
	str r3, [r1]
	ldr r2, [sp, #0x28]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08119534
	cmp r1, #0
	blt _08119534
	ldr r0, _08119538 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08119534
	ldr r0, _0811953C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08119540
_08119534:
	movs r4, #0
	b _0811954E
	.align 2, 0
_08119538: .4byte 0x030046A8
_0811953C: .4byte 0x030046AC
_08119540:
	ldr r0, _08119560 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811954E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08119564
	adds r0, #4
	b _08119570
	.align 2, 0
_08119560: .4byte 0x030046A4
_08119564:
	ldr r0, _08119584 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08119570:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08119588
	cmp r2, #2
	beq _0811958C
	b _08119590
	.align 2, 0
_08119584: .4byte 0x030046A4
_08119588:
	ldrb r0, [r5, #4]
	b _0811958E
_0811958C:
	ldrb r0, [r5]
_0811958E:
	subs r1, r1, r0
_08119590:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081195B8
	cmp r1, #0
	blt _081195B8
	ldr r0, _081195BC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081195B8
	ldr r0, _081195C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081195C4
_081195B8:
	movs r4, #0
	b _081195D2
	.align 2, 0
_081195BC: .4byte 0x030046A8
_081195C0: .4byte 0x030046AC
_081195C4:
	ldr r0, _081195E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081195D2:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081195E8
	adds r0, #4
	b _081195F4
	.align 2, 0
_081195E4: .4byte 0x030046A4
_081195E8:
	ldr r0, _08119608 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081195F4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811960C
	cmp r3, #2
	beq _08119610
	b _08119614
	.align 2, 0
_08119608: .4byte 0x030046A4
_0811960C:
	ldrb r0, [r5, #4]
	b _08119612
_08119610:
	ldrb r0, [r5]
_08119612:
	subs r2, r2, r0
_08119614:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_0811961E:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x30]
	cmp r0, #0
	bne _08119728
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08119648
	movs r0, #1
	b _0811964A
_08119648:
	movs r0, #0
_0811964A:
	ldr r3, _08119738 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x30]
	cmp r0, #0
	bne _08119728
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _0811973C @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _08119740 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x40]
	ldr r2, _08119744 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x44]
	ldr r4, _08119748 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x48]
	ldr r5, _0811974C @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x38]
	ldr r0, _08119750 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x58]
	ldr r1, _08119754 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	ldr r6, _08119758 @ =0x0203B400
	ldr r1, _0811975C @ =0x030046B8
	ldr r5, _08119760 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_0811969A:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _081196B8
	adds r3, #1
	cmp r3, #3
	ble _0811969A
	mov r0, r8
_081196B8:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x4c]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x18]
	ldrb r0, [r4]
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r1, [sp, #0x1c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x44]
	strb r0, [r2]
	ldr r4, [sp, #0x20]
	ldrb r0, [r4]
	ldr r5, [sp, #0x48]
	strb r0, [r5]
	mov r0, sp
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #0x38]
	strb r1, [r0]
	ldr r4, [sp, #0x58]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x2c]
	strb r1, [r5]
	ldr r4, [sp, #0x24]
	strb r3, [r4]
	ldr r5, [sp, #0x4c]
	strb r0, [r5]
	ldr r0, [sp, #0x54]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x50]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	ldr r0, [sp, #0x1c]
	strb r1, [r0]
	ldr r4, [sp, #0x20]
	strb r2, [r4]
	ldr r5, [sp, #0x34]
	str r3, [r5]
	ldr r0, [sp, #0x28]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x3c]
	strb r0, [r1]
_08119728:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r2, [sp, #0x30]
	strh r0, [r2]
	movs r0, #0
	b _0811983A
	.align 2, 0
_08119738: .4byte 0x00000482
_0811973C: .4byte 0x0000054F
_08119740: .4byte 0x0000054C
_08119744: .4byte 0x0000054D
_08119748: .4byte 0x0000054E
_0811974C: .4byte 0x00000541
_08119750: .4byte 0x000005BC
_08119754: .4byte 0x00000542
_08119758: .4byte 0x0203B400
_0811975C: .4byte 0x030046B8
_08119760: .4byte 0x000003FF
_08119764:
	mov sb, sp
	ldr r6, _081197A0 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081197A4
	adds r0, #4
	b _081197AE
	.align 2, 0
_081197A0: .4byte 0x030046A4
_081197A4:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081197AE:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r5, _081197E8 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081197F0
	ldr r0, _081197EC @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811981A
	.align 2, 0
_081197E8: .4byte 0x000004A4
_081197EC: .4byte 0xFFFFFDFF
_081197F0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08119810
	cmp r0, #2
	beq _0811980C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811980C:
	movs r0, #1
	b _0811981C
_08119810:
	ldr r0, _08119830 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0811981A:
	movs r0, #0
_0811981C:
	cmp r0, #0
	bne _08119838
	ldr r4, _08119834 @ =0x000005C4
	adds r0, r7, r4
_08119824:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0811983A
	.align 2, 0
_08119830: .4byte 0xFFFFFDFF
_08119834: .4byte 0x000005C4
_08119838:
	movs r0, #1
_0811983A:
	cmp r0, #0
	bne _08119840
	b _08119A0C
_08119840:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	subs r5, #0x64
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08119874 @ =0x00000551
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _08119878 @ =0x00000552
	adds r0, r7, r3
	strb r4, [r0]
	b _08119A0C
	.align 2, 0
_08119874: .4byte 0x00000551
_08119878: .4byte 0x00000552
_0811987C:
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x28
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081198FC @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _08119900 @ =0x00000482
	adds r0, r7, r1
	movs r2, #1
	strh r2, [r0]
	subs r3, #0xa9
	adds r0, r7, r3
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081198F8
	cmp r1, #0
	blt _081198F8
	ldr r0, _08119904 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081198F8
	ldr r0, _08119908 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811990C
_081198F8:
	movs r4, #0
	b _0811991A
	.align 2, 0
_081198FC: .4byte 0x00000551
_08119900: .4byte 0x00000482
_08119904: .4byte 0x030046A8
_08119908: .4byte 0x030046AC
_0811990C:
	ldr r0, _0811992C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811991A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08119930
	adds r0, #4
	b _0811993C
	.align 2, 0
_0811992C: .4byte 0x030046A4
_08119930:
	ldr r0, _08119950 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811993C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08119954
	cmp r2, #2
	beq _08119958
	b _0811995C
	.align 2, 0
_08119950: .4byte 0x030046A4
_08119954:
	ldrb r0, [r5, #4]
	b _0811995A
_08119958:
	ldrb r0, [r5]
_0811995A:
	subs r1, r1, r0
_0811995C:
	strh r1, [r5, #2]
	ldr r4, _0811998C @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08119994
	ldr r0, _08119990 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081199BE
	.align 2, 0
_0811998C: .4byte 0x000004A4
_08119990: .4byte 0xFFFFFDFF
_08119994:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081199B4
	cmp r0, #2
	beq _081199B0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081199B0:
	movs r0, #1
	b _081199C0
_081199B4:
	ldr r0, _081199F8 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081199BE:
	movs r0, #0
_081199C0:
	adds r3, r0, #0
	cmp r3, #0
	bne _08119A00
	ldr r0, _081199FC @ =FUN_080e48d0
	movs r2, #1
	ldr r4, [sp, #0x2c]
	strb r2, [r4]
	ldr r5, [sp, #0x24]
	strb r3, [r5]
	ldr r1, [sp, #0x4c]
	strb r3, [r1]
	ldr r4, [sp, #0x54]
	str r0, [r4]
	movs r1, #0
	ldr r5, [sp, #0x50]
	strh r3, [r5]
	movs r0, #3
	ldr r4, [sp, #0x18]
	strb r0, [r4]
	ldr r5, [sp, #0x1c]
	strb r1, [r5]
	ldr r0, [sp, #0x20]
	strb r1, [r0]
	ldr r1, [sp, #0x34]
	str r3, [r1]
	ldr r3, [sp, #0x28]
	strb r2, [r3]
	b _08119A0C
	.align 2, 0
_081199F8: .4byte 0xFFFFFDFF
_081199FC: .4byte FUN_080e48d0
_08119A00:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_08119A0C:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08119a1c
FUN_08119a1c: @ 0x08119A1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xbc
	adds r7, r0, #0
	ldr r0, _08119A3C @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08119A40
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08119A42
	.align 2, 0
_08119A3C: .4byte 0x0000046D
_08119A40:
	movs r0, #0
_08119A42:
	cmp r0, #0
	beq _08119A76
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08119A64
	ldr r0, _08119AA8 @ =0x0000018B
	bl PlaySound_082406e0
_08119A64:
	movs r0, #0x20
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	ldr r1, _08119AAC @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r2]
_08119A76:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x83
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _08119AB0
	asrs r0, r0, #2
	b _08119AB6
	.align 2, 0
_08119AA8: .4byte 0x0000018B
_08119AAC: .4byte 0xFFFFFEFF
_08119AB0:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08119AB6:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _08119AD6
	asrs r0, r0, #2
	b _08119ADC
_08119AD6:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08119ADC:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _08119AE6
	movs r3, #0xc8
	b _08119AF0
_08119AE6:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _08119AF0
	adds r3, r0, #0
_08119AF0:
	cmp r2, #0xc8
	ble _08119AF8
	movs r2, #0xc8
	b _08119B02
_08119AF8:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _08119B02
	adds r2, r0, #0
_08119B02:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _08119B26
	cmp r2, #0
	bne _08119B26
	movs r0, #1
	b _08119B28
_08119B26:
	movs r0, #0
_08119B28:
	cmp r0, #0
	bne _08119B30
	bl FUN_0811aa44
_08119B30:
	ldr r6, _08119BBC @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _08119B3E
	bl FUN_0811aa44
_08119B3E:
	ldr r1, _08119BC0 @ =0x0000046B
	adds r0, r7, r1
	movs r6, #0
	movs r5, #1
	strb r5, [r0]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	movs r3, #0x21
	rsbs r3, r3, #0
	ldrh r0, [r2]
	ands r3, r0
	movs r4, #0
	strh r3, [r2]
	adds r1, #0x31
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ands r0, r1
	str r2, [sp, #0x98]
	cmp r0, #0
	beq _08119BD8
	ldr r2, _08119BC4 @ =0x00000594
	adds r0, r7, r2
	ldr r2, [r0]
	movs r1, #7
	ldr r3, _08119BC8 @ =0x0000046D
	adds r0, r7, r3
	strb r5, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r6, [r0]
	movs r1, #3
	subs r3, #0xeb
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _08119BCC @ =0x00000469
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _08119BD0 @ =0x0000046A
	adds r0, r7, r2
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r7, r3
	str r6, [r0]
	ldr r4, _08119BD4 @ =0x0000046C
	adds r0, r7, r4
	strb r5, [r0]
	bl _0811AA54
	.align 2, 0
_08119BBC: .4byte 0x0000046E
_08119BC0: .4byte 0x0000046B
_08119BC4: .4byte 0x00000594
_08119BC8: .4byte 0x0000046D
_08119BCC: .4byte 0x00000469
_08119BD0: .4byte 0x0000046A
_08119BD4: .4byte 0x0000046C
_08119BD8:
	movs r2, #0x80
	adds r0, r3, #0
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _08119BE8
	b _0811A308
_08119BE8:
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #4
	ldr r6, _08119C50 @ =0x00000222
	adds r3, r7, r6
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _08119C54 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r4, r7, r1
	ldr r6, [r4]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xac]
	str r4, [sp, #0x94]
	str r2, [sp, #0x70]
	cmp r5, #0
	blt _08119C4C
	cmp r1, #0
	blt _08119C4C
	ldr r0, _08119C58 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08119C4C
	ldr r0, _08119C5C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08119C60
_08119C4C:
	movs r4, #0
	b _08119C6E
	.align 2, 0
_08119C50: .4byte 0x00000222
_08119C54: .4byte 0x03002BE0
_08119C58: .4byte 0x030046A8
_08119C5C: .4byte 0x030046AC
_08119C60:
	ldr r0, _08119C80 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_08119C6E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08119C84
	adds r0, #4
	b _08119C90
	.align 2, 0
_08119C80: .4byte 0x030046A4
_08119C84:
	ldr r0, _08119CA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08119C90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08119CA8
	cmp r2, #2
	beq _08119CAC
	b _08119CB0
	.align 2, 0
_08119CA4: .4byte 0x030046A4
_08119CA8:
	ldrb r0, [r6, #4]
	b _08119CAE
_08119CAC:
	ldrb r0, [r6]
_08119CAE:
	subs r1, r1, r0
_08119CB0:
	strh r1, [r6, #2]
	ldr r0, _08119CC4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08119CC8
	movs r0, #1
	b _08119CCA
	.align 2, 0
_08119CC4: .4byte 0x030047A4
_08119CC8:
	movs r0, #0
_08119CCA:
	cmp r0, #0
	beq _08119D08
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _08119CEA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08119CE6
	adds r2, r0, #0
_08119CE6:
	cmp r2, #0
	bge _08119CF4
_08119CEA:
	ldr r3, _08119CF0 @ =0x000005C4
	adds r0, r7, r3
	b _0811A218
	.align 2, 0
_08119CF0: .4byte 0x000005C4
_08119CF4:
	ldr r1, _08119D04 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08119D50
	.align 2, 0
_08119D04: .4byte 0x03002BE0
_08119D08:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08119D34
	cmp r1, #0
	blt _08119D34
	ldr r0, _08119D38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08119D34
	ldr r0, _08119D3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08119D40
_08119D34:
	movs r5, #0
	b _08119D4E
	.align 2, 0
_08119D38: .4byte 0x030046A8
_08119D3C: .4byte 0x030046AC
_08119D40:
	ldr r0, _08119D88 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08119D4E:
	movs r2, #0
_08119D50:
	ldr r6, _08119D8C @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _08119D70
	ldr r1, _08119D90 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08119D70
	b _0811A158
_08119D70:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x98]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _08119D94
	movs r0, #0
	b _0811A22E
	.align 2, 0
_08119D88: .4byte 0x030046A4
_08119D8C: .4byte 0x00000256
_08119D90: .4byte 0x03002BE0
_08119D94:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r3, [sp, #0xac]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r1, #0x80
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08119E48
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _08119E34 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x10]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _08119E38 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x14]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x18]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r6, r7
	mov r8, r6
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	mov r1, sb
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _08119E3C @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _08119E40 @ =0x00000484
	adds r1, r7, r0
	mov r6, sb
	str r6, [r1]
	ldr r6, _08119E44 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x10]
	str r6, [sp, #0x88]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x80]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0xa8]
	mov r6, r8
	str r6, [sp, #0xb0]
	str r5, [sp, #0x9c]
	str r4, [sp, #0x74]
	str r3, [sp, #0x78]
	str r2, [sp, #0x7c]
	str r1, [sp, #0x90]
	str r0, [sp, #0x84]
	b _0811A016
	.align 2, 0
_08119E34: .4byte 0x0000046D
_08119E38: .4byte 0x0000046B
_08119E3C: .4byte 0x00000469
_08119E40: .4byte 0x00000484
_08119E44: .4byte 0x0000046C
_08119E48:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _08119F08 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	strb r0, [r3]
	ldr r4, _08119F0C @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x20]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _08119F10 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x24]
	strb r0, [r6]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x28]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x2c]
	strh r2, [r4]
	movs r1, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x30]
	movs r6, #0
	strb r6, [r5]
	ldr r3, _08119F14 @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _08119F18 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _08119F1C @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x94]
	ldr r0, [r0]
	str r0, [sp, #0x34]
	ldr r1, [sp, #0x70]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x34]
	strh r1, [r6]
	ldr r6, [sp, #0x70]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x34]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x88]
	ldr r6, [sp, #0x20]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0xa8]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0xb0]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x9c]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0x74]
	str r5, [sp, #0x78]
	str r4, [sp, #0x7c]
	str r3, [sp, #0x90]
	str r2, [sp, #0x84]
	mov r0, ip
	cmp r0, #0
	blt _08119F04
	cmp r1, #0
	blt _08119F04
	ldr r0, _08119F20 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _08119F04
	ldr r0, _08119F24 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08119F28
_08119F04:
	movs r4, #0
	b _08119F38
	.align 2, 0
_08119F08: .4byte 0x0000046D
_08119F0C: .4byte 0x0000046B
_08119F10: .4byte 0x00000553
_08119F14: .4byte 0x00000469
_08119F18: .4byte 0x0000046A
_08119F1C: .4byte 0x00000484
_08119F20: .4byte 0x030046A8
_08119F24: .4byte 0x030046AC
_08119F28:
	ldr r0, _08119F48 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_08119F38:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08119F4C
	adds r0, #4
	b _08119F58
	.align 2, 0
_08119F48: .4byte 0x030046A4
_08119F4C:
	ldr r0, _08119F6C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08119F58:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08119F70
	cmp r2, #2
	beq _08119F76
	b _08119F7C
	.align 2, 0
_08119F6C: .4byte 0x030046A4
_08119F70:
	ldr r2, [sp, #0x34]
	ldrb r0, [r2, #4]
	b _08119F7A
_08119F76:
	ldr r3, [sp, #0x34]
	ldrb r0, [r3]
_08119F7A:
	subs r1, r1, r0
_08119F7C:
	ldr r4, [sp, #0x34]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x94]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08119FA8
	cmp r1, #0
	blt _08119FA8
	ldr r0, _08119FAC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08119FA8
	ldr r0, _08119FB0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08119FB4
_08119FA8:
	movs r4, #0
	b _08119FC2
	.align 2, 0
_08119FAC: .4byte 0x030046A8
_08119FB0: .4byte 0x030046AC
_08119FB4:
	ldr r0, _08119FD8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08119FC2:
	ldr r6, [sp, #0x94]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08119FDC
	adds r0, #4
	b _08119FE8
	.align 2, 0
_08119FD8: .4byte 0x030046A4
_08119FDC:
	ldr r0, _08119FFC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08119FE8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811A000
	cmp r3, #2
	beq _0811A004
	b _0811A008
	.align 2, 0
_08119FFC: .4byte 0x030046A4
_0811A000:
	ldrb r0, [r5, #4]
	b _0811A006
_0811A004:
	ldrb r0, [r5]
_0811A006:
	subs r2, r2, r0
_0811A008:
	ldr r1, [sp, #0x94]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x94]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0811A016:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x38]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _0811A040 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	cmp r0, #0
	bne _0811A120
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0811A044
	movs r0, #1
	b _0811A046
	.align 2, 0
_0811A040: .4byte 0x00000482
_0811A044:
	movs r0, #0
_0811A046:
	ldr r1, _0811A130 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	cmp r0, #0
	bne _0811A120
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r0, _0811A134 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0811A138 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _0811A13C @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r0, _0811A140 @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0811A144 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb4]
	ldr r2, _0811A148 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa0]
	ldr r1, _0811A14C @ =0x030046B8
	adds r2, r4, #0
_0811A08E:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0811A150 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0811A154 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0811A0B2
	adds r3, #1
	cmp r3, #3
	ble _0811A08E
	adds r0, r4, #0
_0811A0B2:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb0]
	ldr r0, [r1]
	ldr r2, [sp, #0xb8]
	str r0, [r2]
	ldr r4, [sp, #0xa8]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x74]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa4]
	strb r0, [r6]
	add r0, sp, #0x38
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x88]
	strb r1, [r4]
	ldr r5, [sp, #0x80]
	strb r3, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	ldr r0, [sp, #0xb0]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x9c]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x74]
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	strb r1, [r6]
	ldr r0, [sp, #0x7c]
	strb r2, [r0]
	ldr r2, [sp, #0x90]
	str r3, [r2]
	ldr r3, [sp, #0x84]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa0]
	strb r0, [r4]
_0811A120:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x8c]
	strh r0, [r5]
	movs r0, #0
	b _0811A22E
	.align 2, 0
_0811A130: .4byte 0x00000482
_0811A134: .4byte 0x0000054F
_0811A138: .4byte 0x0000054C
_0811A13C: .4byte 0x0000054E
_0811A140: .4byte 0x00000541
_0811A144: .4byte 0x000005BC
_0811A148: .4byte 0x00000542
_0811A14C: .4byte 0x030046B8
_0811A150: .4byte 0x000003FF
_0811A154: .4byte 0x0203B400
_0811A158:
	mov sb, sp
	ldr r6, _0811A194 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811A198
	adds r0, #4
	b _0811A1A2
	.align 2, 0
_0811A194: .4byte 0x030046A4
_0811A198:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811A1A2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _0811A1DC @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _0811A1E4
	ldr r0, _0811A1E0 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811A20E
	.align 2, 0
_0811A1DC: .4byte 0x000004A4
_0811A1E0: .4byte 0xFFFFFDFF
_0811A1E4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0811A204
	cmp r0, #2
	beq _0811A200
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811A200:
	movs r0, #1
	b _0811A210
_0811A204:
	ldr r0, _0811A224 @ =0xFFFFFDFF
	ldr r3, [sp, #0x98]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0811A20E:
	movs r0, #0
_0811A210:
	cmp r0, #0
	bne _0811A22C
	ldr r4, _0811A228 @ =0x000005C4
	adds r0, r7, r4
_0811A218:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0811A22E
	.align 2, 0
_0811A224: .4byte 0xFFFFFDFF
_0811A228: .4byte 0x000005C4
_0811A22C:
	movs r0, #1
_0811A22E:
	cmp r0, #0
	bne _0811A29E
	ldr r5, _0811A264 @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0811A26C
	ldr r0, _0811A268 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811A296
	.align 2, 0
_0811A264: .4byte 0x000004A4
_0811A268: .4byte 0xFFFFFDFF
_0811A26C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0811A28C
	cmp r0, #2
	beq _0811A288
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811A288:
	movs r0, #1
	b _0811A298
_0811A28C:
	ldr r0, _0811A2F4 @ =0xFFFFFDFF
	ldr r3, [sp, #0x98]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0811A296:
	movs r0, #0
_0811A298:
	cmp r0, #0
	bne _0811A29E
	b _0811A9BC
_0811A29E:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _0811A2F8 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _0811A2FC @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811A300 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _0811A304 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _0811AA54
	.align 2, 0
_0811A2F4: .4byte 0xFFFFFDFF
_0811A2F8: .4byte 0x0000046D
_0811A2FC: .4byte 0x0000046B
_0811A300: .4byte 0x0000046A
_0811A304: .4byte 0x00000484
_0811A308:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _0811A36C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x90
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	strh r3, [r0, #6]
	adds r3, r7, r1
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x94]
	str r2, [sp, #0x70]
	cmp r5, #0
	blt _0811A366
	cmp r1, #0
	blt _0811A366
	ldr r0, _0811A370 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0811A366
	ldr r0, _0811A374 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811A378
_0811A366:
	movs r4, #0
	b _0811A386
	.align 2, 0
_0811A36C: .4byte 0x03002BE0
_0811A370: .4byte 0x030046A8
_0811A374: .4byte 0x030046AC
_0811A378:
	ldr r0, _0811A398 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0811A386:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811A39C
	adds r0, #4
	b _0811A3A8
	.align 2, 0
_0811A398: .4byte 0x030046A4
_0811A39C:
	ldr r0, _0811A3BC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811A3A8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811A3C0
	cmp r2, #2
	beq _0811A3C4
	b _0811A3C8
	.align 2, 0
_0811A3BC: .4byte 0x030046A4
_0811A3C0:
	ldrb r0, [r6, #4]
	b _0811A3C6
_0811A3C4:
	ldrb r0, [r6]
_0811A3C6:
	subs r1, r1, r0
_0811A3C8:
	strh r1, [r6, #2]
	ldr r0, _0811A3DC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811A3E0
	movs r0, #1
	b _0811A3E2
	.align 2, 0
_0811A3DC: .4byte 0x030047A4
_0811A3E0:
	movs r0, #0
_0811A3E2:
	cmp r0, #0
	beq _0811A418
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	bne _0811A3F4
	b _0811A934
_0811A3F4:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811A400
	adds r2, r0, #0
_0811A400:
	cmp r2, #0
	bge _0811A406
	b _0811A934
_0811A406:
	ldr r1, _0811A414 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811A460
	.align 2, 0
_0811A414: .4byte 0x03002BE0
_0811A418:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811A444
	cmp r1, #0
	blt _0811A444
	ldr r0, _0811A448 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811A444
	ldr r0, _0811A44C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811A450
_0811A444:
	movs r5, #0
	b _0811A45E
	.align 2, 0
_0811A448: .4byte 0x030046A8
_0811A44C: .4byte 0x030046AC
_0811A450:
	ldr r0, _0811A498 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811A45E:
	movs r2, #0
_0811A460:
	ldr r6, _0811A49C @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811A480
	ldr r1, _0811A4A0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811A480
	b _0811A874
_0811A480:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x98]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x3c]
	cmp r0, #0
	beq _0811A4A4
	movs r0, #0
	b _0811A94E
	.align 2, 0
_0811A498: .4byte 0x030046A4
_0811A49C: .4byte 0x00000256
_0811A4A0: .4byte 0x03002BE0
_0811A4A4:
	ldr r3, _0811A548 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xac]
	cmp r6, #0
	beq _0811A560
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _0811A54C @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x40]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _0811A550 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x44]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x48]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	mov r1, sp
	ldrh r1, [r1, #0x3c]
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _0811A554 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0811A558 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x3c]
	str r6, [r1]
	ldr r6, _0811A55C @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x40]
	str r6, [sp, #0x88]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x80]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0xa8]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0xb0]
	str r5, [sp, #0x9c]
	str r4, [sp, #0x74]
	str r3, [sp, #0x78]
	str r2, [sp, #0x7c]
	str r1, [sp, #0x90]
	str r0, [sp, #0x84]
	b _0811A732
	.align 2, 0
_0811A548: .4byte 0x00000222
_0811A54C: .4byte 0x0000046D
_0811A550: .4byte 0x0000046B
_0811A554: .4byte 0x00000469
_0811A558: .4byte 0x00000484
_0811A55C: .4byte 0x0000046C
_0811A560:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0811A624 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x50]
	strb r0, [r2]
	ldr r3, _0811A628 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x54]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0811A62C @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x58]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x60]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x64]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _0811A630 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _0811A634 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _0811A638 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x94]
	ldr r0, [r0]
	str r0, [sp, #0x68]
	ldr r1, [sp, #0x70]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x68]
	strh r1, [r6]
	ldr r6, [sp, #0x70]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x68]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x50]
	str r0, [sp, #0x88]
	ldr r6, [sp, #0x54]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0xa8]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0xb0]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0x9c]
	ldr r6, [sp, #0x64]
	str r6, [sp, #0x74]
	str r5, [sp, #0x78]
	str r4, [sp, #0x7c]
	str r3, [sp, #0x90]
	str r2, [sp, #0x84]
	mov r0, sl
	cmp r0, #0
	blt _0811A61E
	cmp r1, #0
	blt _0811A61E
	ldr r0, _0811A63C @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _0811A61E
	ldr r0, _0811A640 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811A644
_0811A61E:
	movs r4, #0
	b _0811A654
	.align 2, 0
_0811A624: .4byte 0x0000046D
_0811A628: .4byte 0x0000046B
_0811A62C: .4byte 0x00000553
_0811A630: .4byte 0x00000469
_0811A634: .4byte 0x00000484
_0811A638: .4byte 0x0000046C
_0811A63C: .4byte 0x030046A8
_0811A640: .4byte 0x030046AC
_0811A644:
	ldr r0, _0811A664 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_0811A654:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811A668
	adds r0, #4
	b _0811A674
	.align 2, 0
_0811A664: .4byte 0x030046A4
_0811A668:
	ldr r0, _0811A688 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811A674:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811A68C
	cmp r2, #2
	beq _0811A692
	b _0811A698
	.align 2, 0
_0811A688: .4byte 0x030046A4
_0811A68C:
	ldr r2, [sp, #0x68]
	ldrb r0, [r2, #4]
	b _0811A696
_0811A692:
	ldr r3, [sp, #0x68]
	ldrb r0, [r3]
_0811A696:
	subs r1, r1, r0
_0811A698:
	ldr r4, [sp, #0x68]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x94]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811A6C4
	cmp r1, #0
	blt _0811A6C4
	ldr r0, _0811A6C8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811A6C4
	ldr r0, _0811A6CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811A6D0
_0811A6C4:
	movs r4, #0
	b _0811A6DE
	.align 2, 0
_0811A6C8: .4byte 0x030046A8
_0811A6CC: .4byte 0x030046AC
_0811A6D0:
	ldr r0, _0811A6F4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811A6DE:
	ldr r6, [sp, #0x94]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811A6F8
	adds r0, #4
	b _0811A704
	.align 2, 0
_0811A6F4: .4byte 0x030046A4
_0811A6F8:
	ldr r0, _0811A718 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811A704:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811A71C
	cmp r3, #2
	beq _0811A720
	b _0811A724
	.align 2, 0
_0811A718: .4byte 0x030046A4
_0811A71C:
	ldrb r0, [r5, #4]
	b _0811A722
_0811A720:
	ldrb r0, [r5]
_0811A722:
	subs r2, r2, r0
_0811A724:
	ldr r1, [sp, #0x94]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x94]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0811A732:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x6c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _0811A75C @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	cmp r0, #0
	bne _0811A83C
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0811A760
	movs r0, #1
	b _0811A762
	.align 2, 0
_0811A75C: .4byte 0x00000482
_0811A760:
	movs r0, #0
_0811A762:
	ldr r1, _0811A84C @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	cmp r0, #0
	bne _0811A83C
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r0, _0811A850 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0811A854 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _0811A858 @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r0, _0811A85C @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0811A860 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb4]
	ldr r2, _0811A864 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa0]
	ldr r1, _0811A868 @ =0x030046B8
	adds r2, r4, #0
_0811A7AA:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0811A86C @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0811A870 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0811A7CE
	adds r3, #1
	cmp r3, #3
	ble _0811A7AA
	adds r0, r4, #0
_0811A7CE:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb0]
	ldr r0, [r1]
	ldr r2, [sp, #0xb8]
	str r0, [r2]
	ldr r4, [sp, #0xa8]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x74]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa4]
	strb r0, [r6]
	add r0, sp, #0x6c
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x88]
	strb r1, [r4]
	ldr r5, [sp, #0x80]
	strb r3, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	ldr r0, [sp, #0xb0]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x9c]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x74]
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	strb r1, [r6]
	ldr r0, [sp, #0x7c]
	strb r2, [r0]
	ldr r2, [sp, #0x90]
	str r3, [r2]
	ldr r3, [sp, #0x84]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa0]
	strb r0, [r4]
_0811A83C:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x8c]
	strh r0, [r5]
	movs r0, #0
	b _0811A94E
	.align 2, 0
_0811A84C: .4byte 0x00000482
_0811A850: .4byte 0x0000054F
_0811A854: .4byte 0x0000054C
_0811A858: .4byte 0x0000054E
_0811A85C: .4byte 0x00000541
_0811A860: .4byte 0x000005BC
_0811A864: .4byte 0x00000542
_0811A868: .4byte 0x030046B8
_0811A86C: .4byte 0x000003FF
_0811A870: .4byte 0x0203B400
_0811A874:
	add r6, sp, #8
	ldr r0, _0811A8B4 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _0811A8B8
	adds r0, #4
	b _0811A8C4
	.align 2, 0
_0811A8B4: .4byte 0x030046A4
_0811A8B8:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811A8C4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0811A8FC @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _0811A904
	ldr r0, _0811A900 @ =0xFFFFFDFF
	ldr r6, [sp, #0x98]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _0811A92E
	.align 2, 0
_0811A8FC: .4byte 0x000004A4
_0811A900: .4byte 0xFFFFFDFF
_0811A904:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _0811A924
	cmp r0, #2
	beq _0811A920
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811A920:
	movs r0, #1
	b _0811A930
_0811A924:
	ldr r0, _0811A944 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0811A92E:
	movs r0, #0
_0811A930:
	cmp r0, #0
	bne _0811A94C
_0811A934:
	ldr r3, _0811A948 @ =0x000005C4
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0811A94E
	.align 2, 0
_0811A944: .4byte 0xFFFFFDFF
_0811A948: .4byte 0x000005C4
_0811A94C:
	movs r0, #1
_0811A94E:
	cmp r0, #0
	bne _0811A9D4
	ldr r4, _0811A984 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0811A98C
	ldr r0, _0811A988 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811A9B6
	.align 2, 0
_0811A984: .4byte 0x000004A4
_0811A988: .4byte 0xFFFFFDFF
_0811A98C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0811A9AC
	cmp r0, #2
	beq _0811A9A8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811A9A8:
	movs r0, #1
	b _0811A9B8
_0811A9AC:
	ldr r0, _0811A9CC @ =0xFFFFFDFF
	ldr r3, [sp, #0x98]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0811A9B6:
	movs r0, #0
_0811A9B8:
	cmp r0, #0
	bne _0811A9D4
_0811A9BC:
	ldr r4, _0811A9D0 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0811AA54
	.align 2, 0
_0811A9CC: .4byte 0xFFFFFDFF
_0811A9D0: .4byte 0x000005C4
_0811A9D4:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _0811AA30 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _0811AA34 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _0811AA38 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811AA3C @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _0811AA40 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
	b _0811AA54
	.align 2, 0
_0811AA30: .4byte 0x0000046D
_0811AA34: .4byte 0x0000046B
_0811AA38: .4byte 0x00000469
_0811AA3C: .4byte 0x0000046A
_0811AA40: .4byte 0x00000484

	thumb_func_start FUN_0811aa44
FUN_0811aa44: @ 0x0811AA44
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0811AA54:
	add sp, #0xbc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0811aa64
FUN_0811aa64: @ 0x0811AA64
	bx lr
	.align 2, 0

	thumb_func_start FUN_0811aa68
FUN_0811aa68: @ 0x0811AA68
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r7, r0, #0
	ldr r0, _0811AA88 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811AA8C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811AA8E
	.align 2, 0
_0811AA88: .4byte 0x0000046D
_0811AA8C:
	movs r0, #0
_0811AA8E:
	cmp r0, #0
	beq _0811AB04
	adds r0, r7, #0
	movs r1, #0xa
	bl FUN_080ef86c
	ldr r1, _0811ABAC @ =0x0000046E
	adds r0, r7, r1
	movs r4, #0
	strb r4, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r7, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r7, #0
	movs r1, #4
	bl FUN_080e64b4
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _0811ABB0 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _0811ABB4 @ =0x0000021E
	adds r0, r7, r1
	strh r4, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r4, [r0]
	adds r5, #0x8a
	adds r0, r7, r5
	strh r4, [r0]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_080e81dc
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_0811AB04:
	adds r0, r7, #0
	bl FUN_080e499c
	ldr r1, _0811ABAC @ =0x0000046E
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0811AB16
	b _0811AE1E
_0811AB16:
	ldr r2, _0811ABB8 @ =0x0000046B
	adds r0, r7, r2
	movs r5, #1
	strb r5, [r0]
	adds r0, r7, #0
	bl FUN_080e6658
	movs r0, #0xcd
	lsls r0, r0, #1
	adds r2, r7, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _0811AB82
	movs r1, #8
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x10]
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x14]
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x18]
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	adds r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x20]
	adds r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldrh r0, [r7]
	str r0, [sp, #0x2c]
	ldr r1, _0811ABBC @ =0xFFFF0000
	ldr r0, [sp, #0x30]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x30]
	add r1, sp, #0x30
	add r0, sp, #0x10
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_0811AB82:
	ldr r1, _0811ABC0 @ =0x000001DF
	adds r4, r7, r1
	ldrb r0, [r4]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	str r4, [sp, #0x40]
	cmp r3, #0x1f
	bgt _0811ABC8
	ldr r0, _0811ABC4 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r1, r5, #0
	lsls r1, r3
	b _0811ABDA
	.align 2, 0
_0811ABAC: .4byte 0x0000046E
_0811ABB0: .4byte 0xFFFEBE3F
_0811ABB4: .4byte 0x0000021E
_0811ABB8: .4byte 0x0000046B
_0811ABBC: .4byte 0xFFFF0000
_0811ABC0: .4byte 0x000001DF
_0811ABC4: .4byte 0x030046A0
_0811ABC8:
	ldr r0, _0811ADDC @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r5, #0
	lsls r1, r0
_0811ABDA:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0811ABF4
	b _0811AD70
_0811ABF4:
	ldr r2, _0811ADE0 @ =0xFFFF0000
	ldr r0, [sp, #0x38]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _0811ADE4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x38]
	add r5, sp, #0x38
	ldr r0, [r5, #4]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	str r0, [r5, #4]
	ldr r4, _0811ADE8 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0811ADEC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0811ADF0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r6, r7, #0
	adds r6, #8
	movs r2, #4
	str r2, [sp]
	movs r0, #0x14
	mov sb, r0
	str r0, [sp, #4]
	movs r2, #2
	mov r8, r2
	str r2, [sp, #8]
	movs r0, #1
	mov sl, r0
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x20
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0811ADEC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0811ADF0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r2, #4
	str r2, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x40
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0811ADEC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0811ADF0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r2, #4
	str r2, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x5e
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0811ADEC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0811ADF0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r2, #4
	str r2, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x80
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0811ADEC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0811ADF0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r2, #4
	str r2, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xc4
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0811ADEC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0811ADF0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r2, #4
	str r2, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xf0
	bl FUN_080ddcc8
	ldr r1, [sp, #0x40]
	ldrb r4, [r1]
	cmp r4, #4
	beq _0811AD6A
	cmp r4, #1
	beq _0811AD6A
	cmp r4, #5
	beq _0811AD6A
	cmp r4, #7
	beq _0811AD6A
	cmp r4, #6
	beq _0811AD6A
	cmp r4, #0x18
	bne _0811AD70
_0811AD6A:
	movs r0, #0xe5
	bl PlaySound_082406e0
_0811AD70:
	ldr r3, _0811ADF4 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r5, _0811ADF8 @ =0x0000046D
	adds r0, r7, r5
	movs r1, #0
	movs r4, #1
	strb r4, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r1, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r3, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r2, #0
	strh r1, [r0]
	movs r3, #2
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	strb r4, [r0]
	adds r5, #1
	adds r0, r7, r5
	strb r2, [r0]
	ldr r2, _0811ADFC @ =0x0000046A
	adds r0, r7, r2
	strb r3, [r0]
	adds r5, #0x1b
	adds r0, r7, r5
	str r1, [r0]
	ldr r1, _0811AE00 @ =0x0000046C
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r7, r2
	bl FUN_080136b4
	ldr r5, _0811AE04 @ =0x0000025D
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _0811AE08
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	b _0811AE12
	.align 2, 0
_0811ADDC: .4byte 0x030046A0
_0811ADE0: .4byte 0xFFFF0000
_0811ADE4: .4byte 0x0000FFFF
_0811ADE8: .4byte 0x030046B8
_0811ADEC: .4byte 0x000003FF
_0811ADF0: .4byte 0x0203B400
_0811ADF4: .4byte FUN_080e48d0
_0811ADF8: .4byte 0x0000046D
_0811ADFC: .4byte 0x0000046A
_0811AE00: .4byte 0x0000046C
_0811AE04: .4byte 0x0000025D
_0811AE08:
	ldr r1, [r7, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r4
	str r0, [r1, #8]
_0811AE12:
	adds r0, r7, #0
	bl FUN_080f8ae0
	adds r0, r7, #0
	bl FUN_080e8360
_0811AE1E:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0811ae30
FUN_0811ae30: @ 0x0811AE30
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14c
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x20]
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r3, _0811AF10 @ =0x0000065C
	adds r1, r0, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r4, r4, r7
	mov r8, r4
	ldr r5, _0811AF14 @ =0xFEFFFFFF
	mov sl, r5
	ldr r0, [r4]
	ands r0, r5
	str r0, [r4]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_080e81dc
	movs r0, #0x80
	lsls r0, r0, #6
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r6, r7, r1
	ldrh r2, [r6]
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _0811AE86
	b _0811B5F0
_0811AE86:
	ldr r2, _0811AF18 @ =0x000001DD
	adds r0, r7, r2
	ldrb r0, [r0]
	adds r0, #0x80
	movs r4, #0
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, _0811AF1C @ =0xFFFFDFDF
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r3, _0811AF20 @ =0x00000544
	adds r1, r7, r3
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	strh r4, [r0, #6]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _0811AF24 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r3, r7, r6
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x144]
	str r2, [sp, #0x110]
	cmp r5, #0
	blt _0811AF0A
	cmp r1, #0
	blt _0811AF0A
	ldr r0, _0811AF28 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0811AF0A
	ldr r0, _0811AF2C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811AF30
_0811AF0A:
	movs r4, #0
	b _0811AF3E
	.align 2, 0
_0811AF10: .4byte 0x0000065C
_0811AF14: .4byte 0xFEFFFFFF
_0811AF18: .4byte 0x000001DD
_0811AF1C: .4byte 0xFFFFDFDF
_0811AF20: .4byte 0x00000544
_0811AF24: .4byte 0x03002BE0
_0811AF28: .4byte 0x030046A8
_0811AF2C: .4byte 0x030046AC
_0811AF30:
	ldr r0, _0811AF50 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0811AF3E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811AF54
	adds r0, #4
	b _0811AF60
	.align 2, 0
_0811AF50: .4byte 0x030046A4
_0811AF54:
	ldr r0, _0811AF74 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811AF60:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811AF78
	cmp r2, #2
	beq _0811AF7C
	b _0811AF80
	.align 2, 0
_0811AF74: .4byte 0x030046A4
_0811AF78:
	ldrb r0, [r6, #4]
	b _0811AF7E
_0811AF7C:
	ldrb r0, [r6]
_0811AF7E:
	subs r1, r1, r0
_0811AF80:
	strh r1, [r6, #2]
	ldr r0, _0811AF94 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811AF98
	movs r0, #1
	b _0811AF9A
	.align 2, 0
_0811AF94: .4byte 0x030047A4
_0811AF98:
	movs r0, #0
_0811AF9A:
	cmp r0, #0
	beq _0811AFD8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0811AFBA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811AFB6
	adds r2, r0, #0
_0811AFB6:
	cmp r2, #0
	bge _0811AFC4
_0811AFBA:
	ldr r2, _0811AFC0 @ =0x000005C4
	adds r0, r7, r2
	b _0811B4F4
	.align 2, 0
_0811AFC0: .4byte 0x000005C4
_0811AFC4:
	ldr r1, _0811AFD4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811B020
	.align 2, 0
_0811AFD4: .4byte 0x03002BE0
_0811AFD8:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811B004
	cmp r1, #0
	blt _0811B004
	ldr r0, _0811B008 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811B004
	ldr r0, _0811B00C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811B010
_0811B004:
	movs r5, #0
	b _0811B01E
	.align 2, 0
_0811B008: .4byte 0x030046A8
_0811B00C: .4byte 0x030046AC
_0811B010:
	ldr r0, _0811B060 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811B01E:
	movs r2, #0
_0811B020:
	ldr r4, _0811B064 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811B040
	ldr r1, _0811B068 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811B040
	b _0811B438
_0811B040:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x24]
	str r2, [sp, #0x118]
	cmp r1, #0
	beq _0811B06C
	movs r0, #0
	b _0811B50A
	.align 2, 0
_0811B060: .4byte 0x030046A4
_0811B064: .4byte 0x00000256
_0811B068: .4byte 0x03002BE0
_0811B06C:
	ldr r6, _0811B110 @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x118]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0x120]
	cmp r6, #0
	beq _0811B124
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _0811B114 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x28]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _0811B118 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x30]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x34]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sp
	ldrh r0, [r0, #0x24]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _0811B11C @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0811B120 @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x24]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0x138]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0x130]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0x104]
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x108]
	str r5, [sp, #0x11c]
	str r4, [sp, #0x124]
	str r3, [sp, #0x128]
	str r2, [sp, #0x12c]
	str r1, [sp, #0x140]
	str r0, [sp, #0x134]
	b _0811B2F6
	.align 2, 0
_0811B110: .4byte 0x00000222
_0811B114: .4byte 0x0000046D
_0811B118: .4byte 0x0000046B
_0811B11C: .4byte 0x00000469
_0811B120: .4byte 0x00000484
_0811B124:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0811B1E8 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x38]
	strb r0, [r2]
	ldr r3, _0811B1EC @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x3c]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0811B1F0 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x40]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x44]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x48]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _0811B1F4 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _0811B1F8 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _0811B1FC @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x144]
	ldr r0, [r0]
	str r0, [sp, #0x50]
	ldr r1, [sp, #0x110]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x50]
	strh r1, [r6]
	ldr r6, [sp, #0x110]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x50]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x138]
	ldr r6, [sp, #0x3c]
	str r6, [sp, #0x130]
	ldr r0, [sp, #0x40]
	str r0, [sp, #0x104]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x108]
	ldr r0, [sp, #0x48]
	str r0, [sp, #0x11c]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0x124]
	str r5, [sp, #0x128]
	str r4, [sp, #0x12c]
	str r3, [sp, #0x140]
	str r2, [sp, #0x134]
	mov r0, sb
	cmp r0, #0
	blt _0811B1E2
	cmp r1, #0
	blt _0811B1E2
	ldr r0, _0811B200 @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _0811B1E2
	ldr r0, _0811B204 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811B208
_0811B1E2:
	movs r4, #0
	b _0811B218
	.align 2, 0
_0811B1E8: .4byte 0x0000046D
_0811B1EC: .4byte 0x0000046B
_0811B1F0: .4byte 0x00000553
_0811B1F4: .4byte 0x00000469
_0811B1F8: .4byte 0x00000484
_0811B1FC: .4byte 0x0000046C
_0811B200: .4byte 0x030046A8
_0811B204: .4byte 0x030046AC
_0811B208:
	ldr r0, _0811B228 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_0811B218:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811B22C
	adds r0, #4
	b _0811B238
	.align 2, 0
_0811B228: .4byte 0x030046A4
_0811B22C:
	ldr r0, _0811B24C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811B238:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811B250
	cmp r2, #2
	beq _0811B256
	b _0811B25C
	.align 2, 0
_0811B24C: .4byte 0x030046A4
_0811B250:
	ldr r2, [sp, #0x50]
	ldrb r0, [r2, #4]
	b _0811B25A
_0811B256:
	ldr r3, [sp, #0x50]
	ldrb r0, [r3]
_0811B25A:
	subs r1, r1, r0
_0811B25C:
	ldr r4, [sp, #0x50]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x144]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811B288
	cmp r1, #0
	blt _0811B288
	ldr r0, _0811B28C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811B288
	ldr r0, _0811B290 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811B294
_0811B288:
	movs r4, #0
	b _0811B2A2
	.align 2, 0
_0811B28C: .4byte 0x030046A8
_0811B290: .4byte 0x030046AC
_0811B294:
	ldr r0, _0811B2B8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811B2A2:
	ldr r6, [sp, #0x144]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811B2BC
	adds r0, #4
	b _0811B2C8
	.align 2, 0
_0811B2B8: .4byte 0x030046A4
_0811B2BC:
	ldr r0, _0811B2DC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811B2C8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811B2E0
	cmp r3, #2
	beq _0811B2E4
	b _0811B2E8
	.align 2, 0
_0811B2DC: .4byte 0x030046A4
_0811B2E0:
	ldrb r0, [r5, #4]
	b _0811B2E6
_0811B2E4:
	ldrb r0, [r5]
_0811B2E6:
	subs r2, r2, r0
_0811B2E8:
	ldr r1, [sp, #0x144]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x144]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0811B2F6:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x54]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x118]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _0811B320 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x13c]
	cmp r0, #0
	bne _0811B3FE
	movs r1, #4
	ldr r2, [sp, #0x120]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0811B324
	movs r0, #1
	b _0811B326
	.align 2, 0
_0811B320: .4byte 0x00000482
_0811B324:
	movs r0, #0
_0811B326:
	ldr r3, _0811B410 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x13c]
	cmp r0, #0
	bne _0811B3FE
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _0811B414 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0811B418 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _0811B41C @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x100]
	ldr r2, _0811B420 @ =0x00000541
	adds r2, r2, r7
	mov ip, r2
	ldr r0, _0811B424 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x10c]
	ldr r1, _0811B428 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0xfc]
	ldr r1, _0811B42C @ =0x030046B8
	str r5, [sp, #0x148]
_0811B36C:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0811B430 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _0811B434 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x148]
	cmp r0, r2
	bne _0811B392
	adds r3, #1
	cmp r3, #3
	ble _0811B36C
	adds r0, r5, #0
_0811B392:
	movs r3, #0
	strb r0, [r4]
	ldr r4, [sp, #0x108]
	ldr r0, [r4]
	str r0, [r6]
	ldr r5, [sp, #0x104]
	ldrb r0, [r5]
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x124]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x128]
	ldrb r0, [r4]
	mov r5, sl
	strb r0, [r5]
	ldr r6, [sp, #0x12c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x100]
	strb r0, [r1]
	add r2, sp, #0x54
	ldrb r4, [r2]
	mov r2, ip
	strb r4, [r2]
	ldr r4, [sp, #0x10c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x138]
	strb r1, [r5]
	ldr r6, [sp, #0x130]
	strb r3, [r6]
	ldr r4, [sp, #0x104]
	strb r0, [r4]
	ldr r5, [sp, #0x108]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x11c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x124]
	strb r0, [r4]
	ldr r5, [sp, #0x128]
	strb r1, [r5]
	ldr r6, [sp, #0x12c]
	strb r2, [r6]
	ldr r0, [sp, #0x140]
	str r3, [r0]
	ldr r2, [sp, #0x134]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0xfc]
	strb r0, [r3]
_0811B3FE:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x13c]
	strh r0, [r4]
	movs r0, #0
	b _0811B50A
	.align 2, 0
_0811B410: .4byte 0x00000482
_0811B414: .4byte 0x0000054F
_0811B418: .4byte 0x0000054C
_0811B41C: .4byte 0x0000054E
_0811B420: .4byte 0x00000541
_0811B424: .4byte 0x000005BC
_0811B428: .4byte 0x00000542
_0811B42C: .4byte 0x030046B8
_0811B430: .4byte 0x000003FF
_0811B434: .4byte 0x0203B400
_0811B438:
	mov sb, sp
	ldr r6, _0811B474 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811B478
	adds r0, #4
	b _0811B482
	.align 2, 0
_0811B474: .4byte 0x030046A4
_0811B478:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811B482:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _0811B4B8 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _0811B4BC
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _0811B4E2
	.align 2, 0
_0811B4B8: .4byte 0x000004A4
_0811B4BC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0811B4DC
	cmp r0, #2
	beq _0811B4D8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811B4D8:
	movs r0, #1
	b _0811B4EC
_0811B4DC:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_0811B4E2:
	ldr r1, _0811B500 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0811B4EC:
	cmp r0, #0
	bne _0811B508
	ldr r3, _0811B504 @ =0x000005C4
	adds r0, r7, r3
_0811B4F4:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0811B50A
	.align 2, 0
_0811B500: .4byte 0xFFFFFDFF
_0811B504: .4byte 0x000005C4
_0811B508:
	movs r0, #1
_0811B50A:
	cmp r0, #0
	bne _0811B584
	ldr r4, _0811B53C @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0811B540
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0811B566
	.align 2, 0
_0811B53C: .4byte 0x000004A4
_0811B540:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0811B560
	cmp r0, #2
	beq _0811B55C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811B55C:
	movs r0, #1
	b _0811B570
_0811B560:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_0811B566:
	ldr r1, _0811B57C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0811B570:
	cmp r0, #0
	bne _0811B584
	ldr r4, _0811B580 @ =0x000005C4
	adds r0, r7, r4
	bl FUN_0811cf1c
	.align 2, 0
_0811B57C: .4byte 0xFFFFFDFF
_0811B580: .4byte 0x000005C4
_0811B584:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _0811B5DC @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _0811B5E0 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _0811B5E4 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811B5E8 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _0811B5EC @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	bl FUN_0811cf84
	.align 2, 0
_0811B5DC: .4byte 0x0000046D
_0811B5E0: .4byte 0x0000046B
_0811B5E4: .4byte 0x00000469
_0811B5E8: .4byte 0x0000046A
_0811B5EC: .4byte 0x00000484
_0811B5F0:
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0811B606
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	b _0811B848
_0811B606:
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _0811B69C
	movs r0, #0x83
	lsls r0, r0, #2
	adds r3, r7, r0
	movs r1, #0x85
	lsls r1, r1, #2
	adds r2, r7, r1
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r2, _0811B680 @ =0x00000594
	adds r0, r7, r2
	ldr r2, [r0]
	movs r1, #7
	ldr r3, _0811B684 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r5, _0811B688 @ =0x0000046B
	adds r0, r7, r5
	strb r4, [r0]
	ldr r6, _0811B68C @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _0811B690 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _0811B694 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	ldr r4, _0811B698 @ =0x0000046C
	adds r0, r7, r4
	strb r3, [r0]
	bl _0811CF88
	.align 2, 0
_0811B680: .4byte 0x00000594
_0811B684: .4byte 0x0000046D
_0811B688: .4byte 0x0000046B
_0811B68C: .4byte 0x00000553
_0811B690: .4byte 0x0000046A
_0811B694: .4byte 0x00000484
_0811B698: .4byte 0x0000046C
_0811B69C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	lsls r0, r1, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _0811B6AC
	b _0811B854
_0811B6AC:
	movs r5, #0x93
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r5, [r0]
	movs r0, #0x80
	ands r5, r0
	cmp r5, #0
	beq _0811B788
	ldr r6, [sp, #0x20]
	movs r0, #0xdc
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r2, #0
	movs r0, #0x1e
	strh r0, [r1]
	ldr r3, _0811B764 @ =0x000006E2
	adds r1, r6, r3
	movs r0, #0x14
	strh r0, [r1]
	movs r4, #0xc8
	lsls r4, r4, #1
	adds r0, r7, r4
	ldrh r0, [r0]
	movs r5, #0xc9
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	ldr r6, _0811B768 @ =0x000005CC
	adds r0, r7, r6
	ldr r4, [r0]
	movs r1, #0x12
	ldr r3, _0811B76C @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r5, _0811B770 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	subs r6, #0x79
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	mov r5, sb
	strh r5, [r0]
	movs r1, #3
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811B774 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	ldr r4, _0811B778 @ =0x0000046A
	adds r0, r7, r4
	strb r2, [r0]
	ldr r5, _0811B77C @ =0x00000484
	adds r0, r7, r5
	mov r6, sb
	str r6, [r0]
	adds r1, #3
	adds r0, r7, r1
	strb r3, [r0]
	adds r4, #0x32
	adds r2, r7, r4
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [r2]
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r2, r7, r5
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _0811B780 @ =0xFEFFFFFC
	mov r6, r8
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	ldr r1, _0811B784 @ =0x00000482
	adds r0, r7, r1
	strh r3, [r0]
	bl _0811CF88
	.align 2, 0
_0811B764: .4byte 0x000006E2
_0811B768: .4byte 0x000005CC
_0811B76C: .4byte 0x0000046D
_0811B770: .4byte 0x0000046B
_0811B774: .4byte 0x00000469
_0811B778: .4byte 0x0000046A
_0811B77C: .4byte 0x00000484
_0811B780: .4byte 0xFEFFFFFC
_0811B784: .4byte 0x00000482
_0811B788:
	ldr r2, _0811B804 @ =0x0000049C
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _0811B81C
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r0, [r0]
	movs r4, #0xc9
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r2, #0
	strh r0, [r1]
	ldr r6, _0811B808 @ =0x000005CC
	adds r0, r7, r6
	ldr r3, [r0]
	movs r1, #0x12
	ldr r4, _0811B80C @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0811B810 @ =0x0000046B
	adds r0, r7, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r5, [r0]
	movs r1, #3
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811B814 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	ldr r3, _0811B818 @ =0x0000046A
	adds r0, r7, r3
	strb r2, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r5, [r0]
	adds r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	mov r2, r8
	ldr r0, [r2]
	mov r3, sl
	ands r0, r3
	str r0, [r2]
	bl _0811CF88
	.align 2, 0
_0811B804: .4byte 0x0000049C
_0811B808: .4byte 0x000005CC
_0811B80C: .4byte 0x0000046D
_0811B810: .4byte 0x0000046B
_0811B814: .4byte 0x00000469
_0811B818: .4byte 0x0000046A
_0811B81C:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_080e81dc
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	cmp r0, #0
	beq _0811B840
	adds r0, r7, #0
	bl FUN_08115b00
	ldr r5, [sp, #0x20]
	ldr r0, _0811B850 @ =0x000006B4
	adds r1, r5, r0
	movs r0, #0x78
	strh r0, [r1]
_0811B840:
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
_0811B848:
	strh r0, [r6]
_0811B84A:
	movs r0, #0
	bl FUN_0811cf8a
	.align 2, 0
_0811B850: .4byte 0x000006B4
_0811B854:
	ldr r1, _0811B8D0 @ =0x0000049C
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _0811B8E4
	movs r2, #0xc8
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r2, #0
	strh r0, [r1]
	ldr r4, _0811B8D4 @ =0x000005CC
	adds r0, r7, r4
	ldr r3, [r0]
	movs r1, #0x12
	ldr r6, _0811B8D8 @ =0x0000046D
	adds r0, r7, r6
	movs r4, #1
	strb r4, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r5, [r0]
	movs r1, #3
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811B8DC @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	ldr r3, _0811B8E0 @ =0x0000046A
	adds r0, r7, r3
	strb r2, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r5, [r0]
	adds r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	mov r2, r8
	ldr r0, [r2]
	mov r3, sl
	ands r0, r3
	str r0, [r2]
	bl _0811CF88
	.align 2, 0
_0811B8D0: .4byte 0x0000049C
_0811B8D4: .4byte 0x000005CC
_0811B8D8: .4byte 0x0000046D
_0811B8DC: .4byte 0x00000469
_0811B8E0: .4byte 0x0000046A
_0811B8E4:
	movs r3, #0x21
	rsbs r3, r3, #0
	ands r3, r2
	strh r3, [r6]
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	ands r0, r2
	str r1, [sp, #0x114]
	cmp r0, #0
	bne _0811B84A
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	bne _0811B90A
	b _0811C07C
_0811B90A:
	ldr r5, _0811B9A4 @ =0x0000048D
	adds r2, r7, r5
	ldrb r0, [r2]
	cmp r0, #0
	bne _0811B936
	ldr r6, _0811B9A8 @ =0x0000048C
	adds r0, r7, r6
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0811B936
	ldr r1, _0811B9AC @ =0x000004BE
	adds r0, r7, r1
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_0811B936:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0
	bne _0811B944
	b _0811B84A
_0811B944:
	ldr r0, _0811B9B0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x80
	ldr r3, [sp, #0x114]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #4
	ldr r4, _0811B9B4 @ =0x00000222
	adds r3, r7, r4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r4, r7, r5
	ldr r6, [r4]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0x144]
	str r2, [sp, #0x110]
	str r3, [sp, #0x120]
	cmp r5, #0
	blt _0811B9A0
	cmp r1, #0
	blt _0811B9A0
	ldr r0, _0811B9B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0811B9A0
	ldr r0, _0811B9BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811B9C0
_0811B9A0:
	movs r4, #0
	b _0811B9CE
	.align 2, 0
_0811B9A4: .4byte 0x0000048D
_0811B9A8: .4byte 0x0000048C
_0811B9AC: .4byte 0x000004BE
_0811B9B0: .4byte 0x03002BE0
_0811B9B4: .4byte 0x00000222
_0811B9B8: .4byte 0x030046A8
_0811B9BC: .4byte 0x030046AC
_0811B9C0:
	ldr r0, _0811B9E0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0811B9CE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811B9E4
	adds r0, #4
	b _0811B9F0
	.align 2, 0
_0811B9E0: .4byte 0x030046A4
_0811B9E4:
	ldr r0, _0811BA04 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811B9F0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811BA08
	cmp r2, #2
	beq _0811BA0C
	b _0811BA10
	.align 2, 0
_0811BA04: .4byte 0x030046A4
_0811BA08:
	ldrb r0, [r6, #4]
	b _0811BA0E
_0811BA0C:
	ldrb r0, [r6]
_0811BA0E:
	subs r1, r1, r0
_0811BA10:
	strh r1, [r6, #2]
	ldr r0, _0811BA24 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811BA28
	movs r0, #1
	b _0811BA2A
	.align 2, 0
_0811BA24: .4byte 0x030047A4
_0811BA28:
	movs r0, #0
_0811BA2A:
	cmp r0, #0
	beq _0811BA68
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _0811BA4A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811BA46
	adds r2, r0, #0
_0811BA46:
	cmp r2, #0
	bge _0811BA54
_0811BA4A:
	ldr r1, _0811BA50 @ =0x000005C4
	adds r0, r7, r1
	b _0811BF88
	.align 2, 0
_0811BA50: .4byte 0x000005C4
_0811BA54:
	ldr r1, _0811BA64 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811BAB0
	.align 2, 0
_0811BA64: .4byte 0x03002BE0
_0811BA68:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811BA94
	cmp r1, #0
	blt _0811BA94
	ldr r0, _0811BA98 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811BA94
	ldr r0, _0811BA9C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811BAA0
_0811BA94:
	movs r5, #0
	b _0811BAAE
	.align 2, 0
_0811BA98: .4byte 0x030046A8
_0811BA9C: .4byte 0x030046AC
_0811BAA0:
	ldr r0, _0811BAF0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811BAAE:
	movs r2, #0
_0811BAB0:
	ldr r3, _0811BAF4 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811BAD0
	ldr r1, _0811BAF8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811BAD0
	b _0811BEC8
_0811BAD0:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x58]
	str r2, [sp, #0x118]
	cmp r1, #0
	beq _0811BAFC
	movs r0, #0
	b _0811BF9E
	.align 2, 0
_0811BAF0: .4byte 0x030046A4
_0811BAF4: .4byte 0x00000256
_0811BAF8: .4byte 0x03002BE0
_0811BAFC:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r5, [sp, #0x120]
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r1, #0x80
	ldr r6, [sp, #0x118]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0811BBB8
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _0811BB9C @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _0811BBA0 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x60]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _0811BBA4 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x64]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x68]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	add r2, sp, #0x58
	ldrh r2, [r2]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _0811BBA8 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _0811BBAC @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0811BBB0 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x58]
	str r6, [r1]
	ldr r6, _0811BBB4 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0x138]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0x130]
	ldr r6, [sp, #0x64]
	str r6, [sp, #0x104]
	ldr r6, [sp, #0x68]
	str r6, [sp, #0x108]
	str r5, [sp, #0x11c]
	str r4, [sp, #0x124]
	str r3, [sp, #0x128]
	str r2, [sp, #0x12c]
	str r1, [sp, #0x140]
	str r0, [sp, #0x134]
	b _0811BD86
	.align 2, 0
_0811BB9C: .4byte 0x0000046D
_0811BBA0: .4byte 0x0000046B
_0811BBA4: .4byte 0x00000553
_0811BBA8: .4byte 0x00000469
_0811BBAC: .4byte 0x0000046A
_0811BBB0: .4byte 0x00000484
_0811BBB4: .4byte 0x0000046C
_0811BBB8:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _0811BC78 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	strb r0, [r3]
	ldr r4, _0811BC7C @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x70]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _0811BC80 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x74]
	strb r0, [r6]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x78]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x7c]
	strh r2, [r4]
	movs r1, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x80]
	movs r6, #0
	strb r6, [r5]
	ldr r3, _0811BC84 @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _0811BC88 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _0811BC8C @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x144]
	ldr r0, [r0]
	str r0, [sp, #0x84]
	ldr r1, [sp, #0x110]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x84]
	strh r1, [r6]
	ldr r6, [sp, #0x110]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x84]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x6c]
	str r0, [sp, #0x138]
	ldr r6, [sp, #0x70]
	str r6, [sp, #0x130]
	ldr r0, [sp, #0x74]
	str r0, [sp, #0x104]
	ldr r6, [sp, #0x78]
	str r6, [sp, #0x108]
	ldr r0, [sp, #0x7c]
	str r0, [sp, #0x11c]
	ldr r6, [sp, #0x80]
	str r6, [sp, #0x124]
	str r5, [sp, #0x128]
	str r4, [sp, #0x12c]
	str r3, [sp, #0x140]
	str r2, [sp, #0x134]
	mov r0, r8
	cmp r0, #0
	blt _0811BC74
	cmp r1, #0
	blt _0811BC74
	ldr r0, _0811BC90 @ =0x030046A8
	ldr r0, [r0]
	cmp r8, r0
	bhs _0811BC74
	ldr r0, _0811BC94 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811BC98
_0811BC74:
	movs r4, #0
	b _0811BCA8
	.align 2, 0
_0811BC78: .4byte 0x0000046D
_0811BC7C: .4byte 0x0000046B
_0811BC80: .4byte 0x00000553
_0811BC84: .4byte 0x00000469
_0811BC88: .4byte 0x0000046A
_0811BC8C: .4byte 0x00000484
_0811BC90: .4byte 0x030046A8
_0811BC94: .4byte 0x030046AC
_0811BC98:
	ldr r0, _0811BCB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, r8
	adds r4, r0, r1
_0811BCA8:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811BCBC
	adds r0, #4
	b _0811BCC8
	.align 2, 0
_0811BCB8: .4byte 0x030046A4
_0811BCBC:
	ldr r0, _0811BCDC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811BCC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811BCE0
	cmp r2, #2
	beq _0811BCE6
	b _0811BCEC
	.align 2, 0
_0811BCDC: .4byte 0x030046A4
_0811BCE0:
	ldr r2, [sp, #0x84]
	ldrb r0, [r2, #4]
	b _0811BCEA
_0811BCE6:
	ldr r3, [sp, #0x84]
	ldrb r0, [r3]
_0811BCEA:
	subs r1, r1, r0
_0811BCEC:
	ldr r4, [sp, #0x84]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x144]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811BD18
	cmp r1, #0
	blt _0811BD18
	ldr r0, _0811BD1C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811BD18
	ldr r0, _0811BD20 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811BD24
_0811BD18:
	movs r4, #0
	b _0811BD32
	.align 2, 0
_0811BD1C: .4byte 0x030046A8
_0811BD20: .4byte 0x030046AC
_0811BD24:
	ldr r0, _0811BD48 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811BD32:
	ldr r6, [sp, #0x144]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811BD4C
	adds r0, #4
	b _0811BD58
	.align 2, 0
_0811BD48: .4byte 0x030046A4
_0811BD4C:
	ldr r0, _0811BD6C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811BD58:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811BD70
	cmp r3, #2
	beq _0811BD74
	b _0811BD78
	.align 2, 0
_0811BD6C: .4byte 0x030046A4
_0811BD70:
	ldrb r0, [r5, #4]
	b _0811BD76
_0811BD74:
	ldrb r0, [r5]
_0811BD76:
	subs r2, r2, r0
_0811BD78:
	ldr r1, [sp, #0x144]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x144]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0811BD86:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x88]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x118]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _0811BDB0 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x13c]
	cmp r0, #0
	bne _0811BE8E
	movs r1, #4
	ldr r2, [sp, #0x120]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0811BDB4
	movs r0, #1
	b _0811BDB6
	.align 2, 0
_0811BDB0: .4byte 0x00000482
_0811BDB4:
	movs r0, #0
_0811BDB6:
	ldr r3, _0811BEA0 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x13c]
	cmp r0, #0
	bne _0811BE8E
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _0811BEA4 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0811BEA8 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _0811BEAC @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x100]
	ldr r2, _0811BEB0 @ =0x00000541
	adds r2, r2, r7
	mov ip, r2
	ldr r0, _0811BEB4 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x10c]
	ldr r1, _0811BEB8 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0xfc]
	ldr r1, _0811BEBC @ =0x030046B8
	str r5, [sp, #0x148]
_0811BDFC:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0811BEC0 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _0811BEC4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x148]
	cmp r0, r2
	bne _0811BE22
	adds r3, #1
	cmp r3, #3
	ble _0811BDFC
	adds r0, r5, #0
_0811BE22:
	movs r3, #0
	strb r0, [r4]
	ldr r4, [sp, #0x108]
	ldr r0, [r4]
	str r0, [r6]
	ldr r5, [sp, #0x104]
	ldrb r0, [r5]
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x124]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x128]
	ldrb r0, [r4]
	mov r5, sl
	strb r0, [r5]
	ldr r6, [sp, #0x12c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x100]
	strb r0, [r1]
	add r2, sp, #0x88
	ldrb r4, [r2]
	mov r2, ip
	strb r4, [r2]
	ldr r4, [sp, #0x10c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x138]
	strb r1, [r5]
	ldr r6, [sp, #0x130]
	strb r3, [r6]
	ldr r4, [sp, #0x104]
	strb r0, [r4]
	ldr r5, [sp, #0x108]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x11c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x124]
	strb r0, [r4]
	ldr r5, [sp, #0x128]
	strb r1, [r5]
	ldr r6, [sp, #0x12c]
	strb r2, [r6]
	ldr r0, [sp, #0x140]
	str r3, [r0]
	ldr r2, [sp, #0x134]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0xfc]
	strb r0, [r3]
_0811BE8E:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x13c]
	strh r0, [r4]
	movs r0, #0
	b _0811BF9E
	.align 2, 0
_0811BEA0: .4byte 0x00000482
_0811BEA4: .4byte 0x0000054F
_0811BEA8: .4byte 0x0000054C
_0811BEAC: .4byte 0x0000054E
_0811BEB0: .4byte 0x00000541
_0811BEB4: .4byte 0x000005BC
_0811BEB8: .4byte 0x00000542
_0811BEBC: .4byte 0x030046B8
_0811BEC0: .4byte 0x000003FF
_0811BEC4: .4byte 0x0203B400
_0811BEC8:
	add r6, sp, #8
	ldr r0, _0811BF08 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _0811BF0C
	adds r0, #4
	b _0811BF18
	.align 2, 0
_0811BF08: .4byte 0x030046A4
_0811BF0C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811BF18:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0811BF4C @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _0811BF50
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _0811BF76
	.align 2, 0
_0811BF4C: .4byte 0x000004A4
_0811BF50:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _0811BF70
	cmp r0, #2
	beq _0811BF6C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811BF6C:
	movs r0, #1
	b _0811BF80
_0811BF70:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_0811BF76:
	ldr r1, _0811BF94 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0811BF80:
	cmp r0, #0
	bne _0811BF9C
	ldr r2, _0811BF98 @ =0x000005C4
	adds r0, r7, r2
_0811BF88:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0811BF9E
	.align 2, 0
_0811BF94: .4byte 0xFFFFFDFF
_0811BF98: .4byte 0x000005C4
_0811BF9C:
	movs r0, #1
_0811BF9E:
	cmp r0, #0
	bne _0811C00C
	ldr r3, _0811BFD0 @ =0x000004A4
	adds r0, r7, r3
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0811BFD4
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _0811BFFA
	.align 2, 0
_0811BFD0: .4byte 0x000004A4
_0811BFD4:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0811BFF4
	cmp r0, #2
	beq _0811BFF0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811BFF0:
	movs r0, #1
	b _0811C004
_0811BFF4:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_0811BFFA:
	ldr r1, _0811C064 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0811C004:
	cmp r0, #0
	bne _0811C00C
	bl _0811CF18
_0811C00C:
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r4, _0811C068 @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _0811C06C @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _0811C070 @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811C074 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _0811C078 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	bl _0811CF88
	.align 2, 0
_0811C064: .4byte 0xFFFFFDFF
_0811C068: .4byte 0x0000046D
_0811C06C: .4byte 0x0000046B
_0811C070: .4byte 0x00000553
_0811C074: .4byte 0x0000046A
_0811C078: .4byte 0x00000484
_0811C07C:
	ldr r6, [sp, #0x20]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0811C08C
	b _0811C824
_0811C08C:
	ldr r3, _0811C124 @ =0x0000048D
	adds r2, r7, r3
	ldrb r0, [r2]
	cmp r0, #0
	bne _0811C0B8
	ldr r4, _0811C128 @ =0x0000048C
	adds r0, r7, r4
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0811C0B8
	ldr r5, _0811C12C @ =0x000004BE
	adds r0, r7, r5
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_0811C0B8:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	cmp r0, #0
	bne _0811C0C8
	bl _0811B84A
_0811C0C8:
	ldr r0, _0811C130 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	strb r0, [r7, #5]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	adds r3, r7, r2
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x144]
	str r2, [sp, #0x110]
	cmp r5, #0
	blt _0811C11E
	cmp r1, #0
	blt _0811C11E
	ldr r0, _0811C134 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0811C11E
	ldr r0, _0811C138 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811C13C
_0811C11E:
	movs r4, #0
	b _0811C14A
	.align 2, 0
_0811C124: .4byte 0x0000048D
_0811C128: .4byte 0x0000048C
_0811C12C: .4byte 0x000004BE
_0811C130: .4byte 0x03002BE0
_0811C134: .4byte 0x030046A8
_0811C138: .4byte 0x030046AC
_0811C13C:
	ldr r0, _0811C15C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0811C14A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811C160
	adds r0, #4
	b _0811C16C
	.align 2, 0
_0811C15C: .4byte 0x030046A4
_0811C160:
	ldr r0, _0811C180 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811C16C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811C184
	cmp r2, #2
	beq _0811C188
	b _0811C18C
	.align 2, 0
_0811C180: .4byte 0x030046A4
_0811C184:
	ldrb r0, [r6, #4]
	b _0811C18A
_0811C188:
	ldrb r0, [r6]
_0811C18A:
	subs r1, r1, r0
_0811C18C:
	strh r1, [r6, #2]
	ldr r0, _0811C1A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811C1A4
	movs r0, #1
	b _0811C1A6
	.align 2, 0
_0811C1A0: .4byte 0x030047A4
_0811C1A4:
	movs r0, #0
_0811C1A6:
	cmp r0, #0
	beq _0811C1E4
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _0811C1C6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811C1C2
	adds r2, r0, #0
_0811C1C2:
	cmp r2, #0
	bge _0811C1D0
_0811C1C6:
	ldr r4, _0811C1CC @ =0x000005C4
	adds r0, r7, r4
	b _0811C710
	.align 2, 0
_0811C1CC: .4byte 0x000005C4
_0811C1D0:
	ldr r1, _0811C1E0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811C22C
	.align 2, 0
_0811C1E0: .4byte 0x03002BE0
_0811C1E4:
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811C210
	cmp r1, #0
	blt _0811C210
	ldr r0, _0811C214 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811C210
	ldr r0, _0811C218 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811C21C
_0811C210:
	movs r5, #0
	b _0811C22A
	.align 2, 0
_0811C214: .4byte 0x030046A8
_0811C218: .4byte 0x030046AC
_0811C21C:
	ldr r0, _0811C26C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811C22A:
	movs r2, #0
_0811C22C:
	ldr r6, _0811C270 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811C24C
	ldr r1, _0811C274 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811C24C
	b _0811C650
_0811C24C:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x8c]
	str r2, [sp, #0x118]
	cmp r1, #0
	beq _0811C278
	movs r0, #0
	b _0811C726
	.align 2, 0
_0811C26C: .4byte 0x030046A4
_0811C270: .4byte 0x00000256
_0811C274: .4byte 0x03002BE0
_0811C278:
	ldr r3, _0811C320 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x118]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0x120]
	cmp r0, #0
	beq _0811C338
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _0811C324 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x90]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _0811C328 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x94]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x98]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	add r1, sp, #0x8c
	ldrh r1, [r1]
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _0811C32C @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0811C330 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x8c]
	str r6, [r1]
	ldr r6, _0811C334 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x90]
	str r6, [sp, #0x138]
	ldr r6, [sp, #0x94]
	str r6, [sp, #0x130]
	ldr r6, [sp, #0x98]
	str r6, [sp, #0x104]
	ldr r6, [sp, #0x9c]
	str r6, [sp, #0x108]
	str r5, [sp, #0x11c]
	str r4, [sp, #0x124]
	str r3, [sp, #0x128]
	str r2, [sp, #0x12c]
	str r1, [sp, #0x140]
	str r0, [sp, #0x134]
	b _0811C50C
	.align 2, 0
_0811C320: .4byte 0x00000222
_0811C324: .4byte 0x0000046D
_0811C328: .4byte 0x0000046B
_0811C32C: .4byte 0x00000469
_0811C330: .4byte 0x00000484
_0811C334: .4byte 0x0000046C
_0811C338:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0811C400 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0xa0]
	strb r0, [r2]
	ldr r3, _0811C404 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0xa4]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0811C408 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0xa8]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xac]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xb0]
	mov r2, ip
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xb4]
	strb r4, [r3]
	ldr r4, _0811C40C @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _0811C410 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _0811C414 @ =0x00000484
	adds r3, r7, r6
	mov r1, ip
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x144]
	ldr r0, [r0]
	str r0, [sp, #0xb8]
	ldr r1, [sp, #0x110]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0xb8]
	strh r1, [r6]
	ldr r6, [sp, #0x110]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xb8]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r1, [sp, #0xbc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0xa0]
	str r0, [sp, #0x138]
	ldr r6, [sp, #0xa4]
	str r6, [sp, #0x130]
	ldr r0, [sp, #0xa8]
	str r0, [sp, #0x104]
	ldr r6, [sp, #0xac]
	str r6, [sp, #0x108]
	ldr r0, [sp, #0xb0]
	str r0, [sp, #0x11c]
	ldr r6, [sp, #0xb4]
	str r6, [sp, #0x124]
	str r5, [sp, #0x128]
	str r4, [sp, #0x12c]
	str r3, [sp, #0x140]
	str r2, [sp, #0x134]
	ldr r0, [sp, #0xbc]
	cmp r0, #0
	blt _0811C3FA
	cmp r1, #0
	blt _0811C3FA
	ldr r0, _0811C418 @ =0x030046A8
	ldr r0, [r0]
	ldr r2, [sp, #0xbc]
	cmp r2, r0
	bhs _0811C3FA
	ldr r0, _0811C41C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811C420
_0811C3FA:
	movs r4, #0
	b _0811C430
	.align 2, 0
_0811C400: .4byte 0x0000046D
_0811C404: .4byte 0x0000046B
_0811C408: .4byte 0x00000553
_0811C40C: .4byte 0x00000469
_0811C410: .4byte 0x0000046A
_0811C414: .4byte 0x00000484
_0811C418: .4byte 0x030046A8
_0811C41C: .4byte 0x030046AC
_0811C420:
	ldr r0, _0811C440 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r3, [sp, #0xbc]
	adds r4, r0, r3
_0811C430:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811C444
	adds r0, #4
	b _0811C450
	.align 2, 0
_0811C440: .4byte 0x030046A4
_0811C444:
	ldr r0, _0811C464 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811C450:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811C468
	cmp r2, #2
	beq _0811C46E
	b _0811C474
	.align 2, 0
_0811C464: .4byte 0x030046A4
_0811C468:
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4, #4]
	b _0811C472
_0811C46E:
	ldr r5, [sp, #0xb8]
	ldrb r0, [r5]
_0811C472:
	subs r1, r1, r0
_0811C474:
	ldr r6, [sp, #0xb8]
	strh r1, [r6, #2]
	ldr r1, [sp, #0x144]
	ldr r0, [r1]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811C4A0
	cmp r1, #0
	blt _0811C4A0
	ldr r0, _0811C4A4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811C4A0
	ldr r0, _0811C4A8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811C4AC
_0811C4A0:
	movs r4, #0
	b _0811C4BA
	.align 2, 0
_0811C4A4: .4byte 0x030046A8
_0811C4A8: .4byte 0x030046AC
_0811C4AC:
	ldr r0, _0811C4D0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811C4BA:
	ldr r2, [sp, #0x144]
	ldr r5, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811C4D4
	adds r0, #4
	b _0811C4E0
	.align 2, 0
_0811C4D0: .4byte 0x030046A4
_0811C4D4:
	ldr r0, _0811C4F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811C4E0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811C4F8
	cmp r3, #2
	beq _0811C4FC
	b _0811C500
	.align 2, 0
_0811C4F4: .4byte 0x030046A4
_0811C4F8:
	ldrb r0, [r5, #4]
	b _0811C4FE
_0811C4FC:
	ldrb r0, [r5]
_0811C4FE:
	subs r2, r2, r0
_0811C500:
	ldr r3, [sp, #0x144]
	ldr r0, [r3]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r3]
	strh r1, [r0, #6]
_0811C50C:
	ldrb r4, [r7, #5]
	str r4, [sp, #0xc0]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x118]
	ldrh r0, [r5]
	ands r0, r1
	adds r5, r4, #0
	ldr r6, _0811C538 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x13c]
	cmp r0, #0
	bne _0811C616
	movs r1, #4
	ldr r2, [sp, #0x120]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0811C53C
	movs r0, #1
	b _0811C53E
	.align 2, 0
_0811C538: .4byte 0x00000482
_0811C53C:
	movs r0, #0
_0811C53E:
	ldr r3, _0811C628 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x13c]
	cmp r0, #0
	bne _0811C616
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _0811C62C @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0811C630 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _0811C634 @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x100]
	ldr r2, _0811C638 @ =0x00000541
	adds r2, r2, r7
	mov ip, r2
	ldr r0, _0811C63C @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x10c]
	ldr r1, _0811C640 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0xfc]
	ldr r1, _0811C644 @ =0x030046B8
	str r5, [sp, #0x148]
_0811C584:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0811C648 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _0811C64C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x148]
	cmp r0, r2
	bne _0811C5AA
	adds r3, #1
	cmp r3, #3
	ble _0811C584
	adds r0, r5, #0
_0811C5AA:
	movs r3, #0
	strb r0, [r4]
	ldr r4, [sp, #0x108]
	ldr r0, [r4]
	str r0, [r6]
	ldr r5, [sp, #0x104]
	ldrb r0, [r5]
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x124]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x128]
	ldrb r0, [r4]
	mov r5, sl
	strb r0, [r5]
	ldr r6, [sp, #0x12c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x100]
	strb r0, [r1]
	add r2, sp, #0xc0
	ldrb r4, [r2]
	mov r2, ip
	strb r4, [r2]
	ldr r4, [sp, #0x10c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x138]
	strb r1, [r5]
	ldr r6, [sp, #0x130]
	strb r3, [r6]
	ldr r4, [sp, #0x104]
	strb r0, [r4]
	ldr r5, [sp, #0x108]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x11c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x124]
	strb r0, [r4]
	ldr r5, [sp, #0x128]
	strb r1, [r5]
	ldr r6, [sp, #0x12c]
	strb r2, [r6]
	ldr r0, [sp, #0x140]
	str r3, [r0]
	ldr r2, [sp, #0x134]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0xfc]
	strb r0, [r3]
_0811C616:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x13c]
	strh r0, [r4]
	movs r0, #0
	b _0811C726
	.align 2, 0
_0811C628: .4byte 0x00000482
_0811C62C: .4byte 0x0000054F
_0811C630: .4byte 0x0000054C
_0811C634: .4byte 0x0000054E
_0811C638: .4byte 0x00000541
_0811C63C: .4byte 0x000005BC
_0811C640: .4byte 0x00000542
_0811C644: .4byte 0x030046B8
_0811C648: .4byte 0x000003FF
_0811C64C: .4byte 0x0203B400
_0811C650:
	add r6, sp, #0x10
	ldr r0, _0811C690 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _0811C694
	adds r0, #4
	b _0811C6A0
	.align 2, 0
_0811C690: .4byte 0x030046A4
_0811C694:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811C6A0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0811C6D4 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _0811C6D8
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _0811C6FE
	.align 2, 0
_0811C6D4: .4byte 0x000004A4
_0811C6D8:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _0811C6F8
	cmp r0, #2
	beq _0811C6F4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811C6F4:
	movs r0, #1
	b _0811C708
_0811C6F8:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_0811C6FE:
	ldr r1, _0811C71C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0811C708:
	cmp r0, #0
	bne _0811C724
	ldr r2, _0811C720 @ =0x000005C4
	adds r0, r7, r2
_0811C710:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0811C726
	.align 2, 0
_0811C71C: .4byte 0xFFFFFDFF
_0811C720: .4byte 0x000005C4
_0811C724:
	movs r0, #1
_0811C726:
	cmp r0, #0
	bne _0811C792
	ldr r3, _0811C758 @ =0x000004A4
	adds r0, r7, r3
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0811C75C
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _0811C782
	.align 2, 0
_0811C758: .4byte 0x000004A4
_0811C75C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0811C77C
	cmp r0, #2
	beq _0811C778
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811C778:
	movs r0, #1
	b _0811C78C
_0811C77C:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_0811C782:
	ldr r1, _0811C804 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0811C78C:
	cmp r0, #0
	bne _0811C792
	b _0811CF18
_0811C792:
	ldr r2, _0811C808 @ =0x00000482
	adds r1, r7, r2
	movs r4, #0
	movs r5, #0
	movs r3, #1
	movs r0, #1
	strh r0, [r1]
	ldr r6, [sp, #0x20]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #2
	bhi _0811C7B2
	adds r0, #1
	strb r0, [r1]
_0811C7B2:
	ldr r2, _0811C80C @ =FUN_080f3cdc
	movs r1, #0xa
	ldr r6, _0811C810 @ =0x0000046D
	adds r0, r7, r6
	strb r3, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	subs r6, #0xeb
	adds r0, r7, r6
	strb r4, [r0]
	ldr r1, _0811C814 @ =0x00000469
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _0811C818 @ =0x0000046A
	adds r0, r7, r2
	strb r3, [r0]
	ldr r4, _0811C81C @ =0x00000484
	adds r0, r7, r4
	str r5, [r0]
	ldr r5, _0811C820 @ =0x0000046C
	adds r0, r7, r5
	strb r3, [r0]
	movs r1, #0x10
	ldr r6, [sp, #0x114]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	b _0811CF88
	.align 2, 0
_0811C804: .4byte 0xFFFFFDFF
_0811C808: .4byte 0x00000482
_0811C80C: .4byte FUN_080f3cdc
_0811C810: .4byte 0x0000046D
_0811C814: .4byte 0x00000469
_0811C818: .4byte 0x0000046A
_0811C81C: .4byte 0x00000484
_0811C820: .4byte 0x0000046C
_0811C824:
	ldr r0, _0811C8BC @ =0x0000048D
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _0811C850
	ldr r1, _0811C8C0 @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0811C850
	ldr r3, _0811C8C4 @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_0811C850:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	cmp r0, #0
	bne _0811C860
	bl _0811B84A
_0811C860:
	ldr r0, _0811C8C8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x90
	ldr r5, [sp, #0x114]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	adds r3, r7, r6
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x144]
	str r2, [sp, #0x110]
	cmp r5, #0
	blt _0811C8B6
	cmp r1, #0
	blt _0811C8B6
	ldr r0, _0811C8CC @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0811C8B6
	ldr r0, _0811C8D0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811C8D4
_0811C8B6:
	movs r4, #0
	b _0811C8E2
	.align 2, 0
_0811C8BC: .4byte 0x0000048D
_0811C8C0: .4byte 0x0000048C
_0811C8C4: .4byte 0x000004BE
_0811C8C8: .4byte 0x03002BE0
_0811C8CC: .4byte 0x030046A8
_0811C8D0: .4byte 0x030046AC
_0811C8D4:
	ldr r0, _0811C8F4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0811C8E2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811C8F8
	adds r0, #4
	b _0811C904
	.align 2, 0
_0811C8F4: .4byte 0x030046A4
_0811C8F8:
	ldr r0, _0811C918 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811C904:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811C91C
	cmp r2, #2
	beq _0811C920
	b _0811C924
	.align 2, 0
_0811C918: .4byte 0x030046A4
_0811C91C:
	ldrb r0, [r6, #4]
	b _0811C922
_0811C920:
	ldrb r0, [r6]
_0811C922:
	subs r1, r1, r0
_0811C924:
	strh r1, [r6, #2]
	ldr r0, _0811C938 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811C93C
	movs r0, #1
	b _0811C93E
	.align 2, 0
_0811C938: .4byte 0x030047A4
_0811C93C:
	movs r0, #0
_0811C93E:
	cmp r0, #0
	beq _0811C974
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _0811C950
	b _0811CE94
_0811C950:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811C95C
	adds r2, r0, #0
_0811C95C:
	cmp r2, #0
	bge _0811C962
	b _0811CE94
_0811C962:
	ldr r1, _0811C970 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811C9BC
	.align 2, 0
_0811C970: .4byte 0x03002BE0
_0811C974:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811C9A0
	cmp r1, #0
	blt _0811C9A0
	ldr r0, _0811C9A4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811C9A0
	ldr r0, _0811C9A8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811C9AC
_0811C9A0:
	movs r5, #0
	b _0811C9BA
	.align 2, 0
_0811C9A4: .4byte 0x030046A8
_0811C9A8: .4byte 0x030046AC
_0811C9AC:
	ldr r0, _0811C9FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811C9BA:
	movs r2, #0
_0811C9BC:
	ldr r4, _0811CA00 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811C9DC
	ldr r1, _0811CA04 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811C9DC
	b _0811CDD8
_0811C9DC:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0xc4]
	str r2, [sp, #0x118]
	cmp r1, #0
	beq _0811CA08
	movs r0, #0
	b _0811CEAE
	.align 2, 0
_0811C9FC: .4byte 0x030046A4
_0811CA00: .4byte 0x00000256
_0811CA04: .4byte 0x03002BE0
_0811CA08:
	ldr r6, _0811CAAC @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x118]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	str r2, [sp, #0x120]
	cmp r0, #0
	beq _0811CAC0
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _0811CAB0 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0xc8]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _0811CAB4 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0xcc]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0xd0]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xd4]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	add r0, sp, #0xc4
	ldrh r0, [r0]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _0811CAB8 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0811CABC @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0xc4]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0xc8]
	str r6, [sp, #0x138]
	ldr r6, [sp, #0xcc]
	str r6, [sp, #0x130]
	ldr r6, [sp, #0xd0]
	str r6, [sp, #0x104]
	ldr r6, [sp, #0xd4]
	str r6, [sp, #0x108]
	str r5, [sp, #0x11c]
	str r4, [sp, #0x124]
	str r3, [sp, #0x128]
	str r2, [sp, #0x12c]
	str r1, [sp, #0x140]
	str r0, [sp, #0x134]
	b _0811CC94
	.align 2, 0
_0811CAAC: .4byte 0x00000222
_0811CAB0: .4byte 0x0000046D
_0811CAB4: .4byte 0x0000046B
_0811CAB8: .4byte 0x00000469
_0811CABC: .4byte 0x00000484
_0811CAC0:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0811CB88 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0xd8]
	strb r0, [r2]
	ldr r3, _0811CB8C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0xdc]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0811CB90 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0xe0]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xe4]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xe8]
	mov r2, sl
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xec]
	strb r4, [r3]
	ldr r4, _0811CB94 @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _0811CB98 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _0811CB9C @ =0x00000484
	adds r3, r7, r6
	mov r1, sl
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x144]
	ldr r0, [r0]
	str r0, [sp, #0xf0]
	ldr r1, [sp, #0x110]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0xf0]
	strh r1, [r6]
	ldr r6, [sp, #0x110]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xf0]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r1, [sp, #0xf4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0xd8]
	str r0, [sp, #0x138]
	ldr r6, [sp, #0xdc]
	str r6, [sp, #0x130]
	ldr r0, [sp, #0xe0]
	str r0, [sp, #0x104]
	ldr r6, [sp, #0xe4]
	str r6, [sp, #0x108]
	ldr r0, [sp, #0xe8]
	str r0, [sp, #0x11c]
	ldr r6, [sp, #0xec]
	str r6, [sp, #0x124]
	str r5, [sp, #0x128]
	str r4, [sp, #0x12c]
	str r3, [sp, #0x140]
	str r2, [sp, #0x134]
	ldr r0, [sp, #0xf4]
	cmp r0, #0
	blt _0811CB82
	cmp r1, #0
	blt _0811CB82
	ldr r0, _0811CBA0 @ =0x030046A8
	ldr r0, [r0]
	ldr r2, [sp, #0xf4]
	cmp r2, r0
	bhs _0811CB82
	ldr r0, _0811CBA4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811CBA8
_0811CB82:
	movs r4, #0
	b _0811CBB8
	.align 2, 0
_0811CB88: .4byte 0x0000046D
_0811CB8C: .4byte 0x0000046B
_0811CB90: .4byte 0x00000553
_0811CB94: .4byte 0x00000469
_0811CB98: .4byte 0x0000046A
_0811CB9C: .4byte 0x00000484
_0811CBA0: .4byte 0x030046A8
_0811CBA4: .4byte 0x030046AC
_0811CBA8:
	ldr r0, _0811CBC8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r3, [sp, #0xf4]
	adds r4, r0, r3
_0811CBB8:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811CBCC
	adds r0, #4
	b _0811CBD8
	.align 2, 0
_0811CBC8: .4byte 0x030046A4
_0811CBCC:
	ldr r0, _0811CBEC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811CBD8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811CBF0
	cmp r2, #2
	beq _0811CBF6
	b _0811CBFC
	.align 2, 0
_0811CBEC: .4byte 0x030046A4
_0811CBF0:
	ldr r4, [sp, #0xf0]
	ldrb r0, [r4, #4]
	b _0811CBFA
_0811CBF6:
	ldr r5, [sp, #0xf0]
	ldrb r0, [r5]
_0811CBFA:
	subs r1, r1, r0
_0811CBFC:
	ldr r6, [sp, #0xf0]
	strh r1, [r6, #2]
	ldr r1, [sp, #0x144]
	ldr r0, [r1]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811CC28
	cmp r1, #0
	blt _0811CC28
	ldr r0, _0811CC2C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811CC28
	ldr r0, _0811CC30 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811CC34
_0811CC28:
	movs r4, #0
	b _0811CC42
	.align 2, 0
_0811CC2C: .4byte 0x030046A8
_0811CC30: .4byte 0x030046AC
_0811CC34:
	ldr r0, _0811CC58 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811CC42:
	ldr r2, [sp, #0x144]
	ldr r5, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811CC5C
	adds r0, #4
	b _0811CC68
	.align 2, 0
_0811CC58: .4byte 0x030046A4
_0811CC5C:
	ldr r0, _0811CC7C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811CC68:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811CC80
	cmp r3, #2
	beq _0811CC84
	b _0811CC88
	.align 2, 0
_0811CC7C: .4byte 0x030046A4
_0811CC80:
	ldrb r0, [r5, #4]
	b _0811CC86
_0811CC84:
	ldrb r0, [r5]
_0811CC86:
	subs r2, r2, r0
_0811CC88:
	ldr r3, [sp, #0x144]
	ldr r0, [r3]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r3]
	strh r1, [r0, #6]
_0811CC94:
	ldrb r4, [r7, #5]
	str r4, [sp, #0xf8]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x118]
	ldrh r0, [r5]
	ands r0, r1
	adds r5, r4, #0
	ldr r6, _0811CCC0 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x13c]
	cmp r0, #0
	bne _0811CD9E
	movs r1, #4
	ldr r2, [sp, #0x120]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0811CCC4
	movs r0, #1
	b _0811CCC6
	.align 2, 0
_0811CCC0: .4byte 0x00000482
_0811CCC4:
	movs r0, #0
_0811CCC6:
	ldr r3, _0811CDB0 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x13c]
	cmp r0, #0
	bne _0811CD9E
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _0811CDB4 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0811CDB8 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _0811CDBC @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x100]
	ldr r2, _0811CDC0 @ =0x00000541
	adds r2, r2, r7
	mov ip, r2
	ldr r0, _0811CDC4 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x10c]
	ldr r1, _0811CDC8 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0xfc]
	ldr r1, _0811CDCC @ =0x030046B8
	str r5, [sp, #0x148]
_0811CD0C:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0811CDD0 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _0811CDD4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x148]
	cmp r0, r2
	bne _0811CD32
	adds r3, #1
	cmp r3, #3
	ble _0811CD0C
	adds r0, r5, #0
_0811CD32:
	movs r3, #0
	strb r0, [r4]
	ldr r4, [sp, #0x108]
	ldr r0, [r4]
	str r0, [r6]
	ldr r5, [sp, #0x104]
	ldrb r0, [r5]
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x124]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x128]
	ldrb r0, [r4]
	mov r5, sl
	strb r0, [r5]
	ldr r6, [sp, #0x12c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x100]
	strb r0, [r1]
	add r2, sp, #0xf8
	ldrb r4, [r2]
	mov r2, ip
	strb r4, [r2]
	ldr r4, [sp, #0x10c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x138]
	strb r1, [r5]
	ldr r6, [sp, #0x130]
	strb r3, [r6]
	ldr r4, [sp, #0x104]
	strb r0, [r4]
	ldr r5, [sp, #0x108]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x11c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x124]
	strb r0, [r4]
	ldr r5, [sp, #0x128]
	strb r1, [r5]
	ldr r6, [sp, #0x12c]
	strb r2, [r6]
	ldr r0, [sp, #0x140]
	str r3, [r0]
	ldr r2, [sp, #0x134]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0xfc]
	strb r0, [r3]
_0811CD9E:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x13c]
	strh r0, [r4]
	movs r0, #0
	b _0811CEAE
	.align 2, 0
_0811CDB0: .4byte 0x00000482
_0811CDB4: .4byte 0x0000054F
_0811CDB8: .4byte 0x0000054C
_0811CDBC: .4byte 0x0000054E
_0811CDC0: .4byte 0x00000541
_0811CDC4: .4byte 0x000005BC
_0811CDC8: .4byte 0x00000542
_0811CDCC: .4byte 0x030046B8
_0811CDD0: .4byte 0x000003FF
_0811CDD4: .4byte 0x0203B400
_0811CDD8:
	add r6, sp, #0x18
	ldr r0, _0811CE18 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _0811CE1C
	adds r0, #4
	b _0811CE28
	.align 2, 0
_0811CE18: .4byte 0x030046A4
_0811CE1C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811CE28:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0811CE5C @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _0811CE60
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _0811CE86
	.align 2, 0
_0811CE5C: .4byte 0x000004A4
_0811CE60:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _0811CE80
	cmp r0, #2
	beq _0811CE7C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811CE7C:
	movs r0, #1
	b _0811CE90
_0811CE80:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_0811CE86:
	ldr r1, _0811CEA4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0811CE90:
	cmp r0, #0
	bne _0811CEAC
_0811CE94:
	ldr r2, _0811CEA8 @ =0x000005C4
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0811CEAE
	.align 2, 0
_0811CEA4: .4byte 0xFFFFFDFF
_0811CEA8: .4byte 0x000005C4
_0811CEAC:
	movs r0, #1
_0811CEAE:
	cmp r0, #0
	bne _0811CF30
	ldr r3, _0811CEE0 @ =0x000004A4
	adds r0, r7, r3
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0811CEE4
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _0811CF0A
	.align 2, 0
_0811CEE0: .4byte 0x000004A4
_0811CEE4:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0811CF04
	cmp r0, #2
	beq _0811CF00
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811CF00:
	movs r0, #1
	b _0811CF14
_0811CF04:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_0811CF0A:
	ldr r1, _0811CF28 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0811CF14:
	cmp r0, #0
	bne _0811CF30
_0811CF18:
	ldr r1, _0811CF2C @ =0x000005C4
	adds r0, r7, r1
FUN_0811cf1c:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _0811B84A
	.align 2, 0
_0811CF28: .4byte 0xFFFFFDFF
_0811CF2C: .4byte 0x000005C4
_0811CF30:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r3, #1
	ldr r4, _0811CF9C @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	strb r3, [r0]
	ldr r5, _0811CFA0 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _0811CFA4 @ =0x00000553
	adds r0, r7, r6
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r7, r4
	str r1, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r5, _0811CFA8 @ =0x00000469
	adds r0, r7, r5
	strb r1, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r4, [r0]
	ldr r1, _0811CFAC @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r2, _0811CFB0 @ =0x0000046C
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _0811CFB4 @ =0x00000482
	adds r1, r7, r3
FUN_0811cf84:
	movs r0, #2
	strh r0, [r1]
_0811CF88:
	movs r0, #1
FUN_0811cf8a:
	add sp, #0x14c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0811CF9C: .4byte 0x0000046D
_0811CFA0: .4byte 0x0000046B
_0811CFA4: .4byte 0x00000553
_0811CFA8: .4byte 0x00000469
_0811CFAC: .4byte 0x00000484
_0811CFB0: .4byte 0x0000046C
_0811CFB4: .4byte 0x00000482

	thumb_func_start FUN_0811cfb8
FUN_0811cfb8: @ 0x0811CFB8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0811CFD0 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811CFD4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811CFD6
	.align 2, 0
_0811CFD0: .4byte 0x0000046C
_0811CFD4:
	movs r0, #0
_0811CFD6:
	cmp r0, #0
	beq _0811D054
	ldr r4, _0811D068 @ =FUN_080f3cdc
	movs r3, #0xa
	ldr r2, _0811D06C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0811D070 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r5, #5]
	adds r1, #0x17
	adds r0, r5, r1
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080e5718
	adds r0, r5, #0
	bl FUN_080e6750
	ldr r2, _0811D074 @ =0x000001DF
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _0811D038
	movs r0, #4
	ldr r1, _0811D078 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0811D038:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
_0811D054:
	ldr r1, _0811D070 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0811D07C
	adds r0, r5, #0
	bl FUN_08115ce0
	b _0811D086
	.align 2, 0
_0811D068: .4byte FUN_080f3cdc
_0811D06C: .4byte 0x0000046D
_0811D070: .4byte 0x0000046B
_0811D074: .4byte 0x000001DF
_0811D078: .4byte 0x00000222
_0811D07C:
	ldr r2, _0811D08C @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0811D086:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0811D08C: .4byte 0x00000484

	thumb_func_start FUN_0811d090
FUN_0811d090: @ 0x0811D090
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r7, r0, #0
	ldr r0, _0811D1F4 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811D0AC
	movs r0, #0
	strb r0, [r1]
_0811D0AC:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811D0C4
	bl _0811D8AA
_0811D0C4:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _0811D0D6
	bl _0811D8AA
_0811D0D6:
	ldr r2, _0811D1F8 @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _0811D0E4
	bl FUN_0811d8a6
_0811D0E4:
	ldr r3, _0811D1FC @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r0, #3
	movs r1, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _0811D200 @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	strb r1, [r5]
	ldr r0, _0811D204 @ =0x0000046A
	adds r0, r7, r0
	str r0, [sp, #0x10]
	strb r6, [r0]
	ldr r2, _0811D1F8 @ =0x00000484
	adds r2, r2, r7
	mov sl, r2
	str r6, [r2]
	ldr r3, _0811D1F4 @ =0x0000046C
	adds r3, r3, r7
	mov ip, r3
	strb r1, [r3]
	ldr r2, _0811D208 @ =FUN_080e6794
	movs r0, #0xe
	ldr r4, _0811D20C @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	strb r1, [r4]
	ldr r5, _0811D210 @ =0x0000046B
	adds r5, r5, r7
	mov r8, r5
	strb r6, [r5]
	ldr r1, _0811D214 @ =0x00000553
	adds r5, r7, r1
	strb r0, [r5]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r4, r7, r3
	str r2, [r4]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r3, r7, r0
	strh r6, [r3]
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	mov r0, ip
	str r0, [sp, #0x28]
	ldr r0, [sp, #8]
	str r0, [sp, #0x18]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x20]
	mov r0, sl
	str r0, [sp, #0x34]
	mov r0, sb
	str r0, [sp, #0x2c]
	mov r0, r8
	str r0, [sp, #0x24]
	str r5, [sp, #0x50]
	str r4, [sp, #0x54]
	str r3, [sp, #0x40]
	mov sl, r2
	cmp r1, #0
	bne _0811D182
	b _0811D71C
_0811D182:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0811D218 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _0811D1EE
	cmp r1, #0
	blt _0811D1EE
	ldr r0, _0811D21C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0811D1EE
	ldr r0, _0811D220 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811D224
_0811D1EE:
	movs r4, #0
	b _0811D232
	.align 2, 0
_0811D1F4: .4byte 0x0000046C
_0811D1F8: .4byte 0x00000484
_0811D1FC: .4byte 0x000001DF
_0811D200: .4byte 0x00000469
_0811D204: .4byte 0x0000046A
_0811D208: .4byte FUN_080e6794
_0811D20C: .4byte 0x0000046D
_0811D210: .4byte 0x0000046B
_0811D214: .4byte 0x00000553
_0811D218: .4byte 0x00000551
_0811D21C: .4byte 0x030046A8
_0811D220: .4byte 0x030046AC
_0811D224:
	ldr r0, _0811D244 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0811D232:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811D248
	adds r0, #4
	b _0811D254
	.align 2, 0
_0811D244: .4byte 0x030046A4
_0811D248:
	ldr r0, _0811D268 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811D254:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811D26C
	cmp r2, #2
	beq _0811D270
	b _0811D274
	.align 2, 0
_0811D268: .4byte 0x030046A4
_0811D26C:
	ldrb r0, [r5, #4]
	b _0811D272
_0811D270:
	ldrb r0, [r5]
_0811D272:
	subs r1, r1, r0
_0811D274:
	strh r1, [r5, #2]
	ldr r0, _0811D288 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811D28C
	movs r0, #1
	b _0811D28E
	.align 2, 0
_0811D288: .4byte 0x030047A4
_0811D28C:
	movs r0, #0
_0811D28E:
	cmp r0, #0
	beq _0811D2CC
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0811D2AE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811D2AA
	adds r2, r0, #0
_0811D2AA:
	cmp r2, #0
	bge _0811D2B8
_0811D2AE:
	ldr r2, _0811D2B4 @ =0x000005C4
	adds r0, r7, r2
	b _0811D70A
	.align 2, 0
_0811D2B4: .4byte 0x000005C4
_0811D2B8:
	ldr r1, _0811D2C8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811D314
	.align 2, 0
_0811D2C8: .4byte 0x03002BE0
_0811D2CC:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811D2F8
	cmp r1, #0
	blt _0811D2F8
	ldr r0, _0811D2FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811D2F8
	ldr r0, _0811D300 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811D304
_0811D2F8:
	movs r5, #0
	b _0811D312
	.align 2, 0
_0811D2FC: .4byte 0x030046A8
_0811D300: .4byte 0x030046AC
_0811D304:
	ldr r0, _0811D3A4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811D312:
	movs r2, #0
_0811D314:
	ldr r4, _0811D3A8 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811D334
	ldr r1, _0811D3AC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811D334
	b _0811D648
_0811D334:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0811D348
	b _0811D8AA
_0811D348:
	ldr r0, _0811D3B0 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _0811D3B4
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x2c]
	strb r2, [r3]
	ldr r3, [sp, #0x24]
	strb r5, [r3]
	ldr r3, [sp, #0x50]
	strb r0, [r3]
	ldr r0, [sp, #0x54]
	str r1, [r0]
	ldr r1, [sp, #0x40]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x18]
	strb r5, [r3]
	ldr r1, [sp, #0x1c]
	strb r5, [r1]
	ldr r3, [sp, #0x20]
	strb r0, [r3]
	ldr r5, [sp, #0x34]
	str r4, [r5]
	ldr r0, [sp, #0x28]
	strb r2, [r0]
	b _0811D502
	.align 2, 0
_0811D3A4: .4byte 0x030046A4
_0811D3A8: .4byte 0x00000256
_0811D3AC: .4byte 0x03002BE0
_0811D3B0: .4byte 0x00000222
_0811D3B4:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x2c]
	strb r0, [r2]
	ldr r4, [sp, #0x24]
	strb r5, [r4]
	ldr r2, [sp, #0x50]
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	str r1, [r4]
	ldr r1, [sp, #0x40]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x18]
	strb r5, [r2]
	ldr r4, [sp, #0x1c]
	strb r5, [r4]
	ldr r5, [sp, #0x20]
	strb r1, [r5]
	ldr r1, [sp, #0x34]
	str r3, [r1]
	ldr r2, [sp, #0x28]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811D418
	cmp r1, #0
	blt _0811D418
	ldr r0, _0811D41C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811D418
	ldr r0, _0811D420 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811D424
_0811D418:
	movs r4, #0
	b _0811D432
	.align 2, 0
_0811D41C: .4byte 0x030046A8
_0811D420: .4byte 0x030046AC
_0811D424:
	ldr r0, _0811D444 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811D432:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811D448
	adds r0, #4
	b _0811D454
	.align 2, 0
_0811D444: .4byte 0x030046A4
_0811D448:
	ldr r0, _0811D468 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811D454:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811D46C
	cmp r2, #2
	beq _0811D470
	b _0811D474
	.align 2, 0
_0811D468: .4byte 0x030046A4
_0811D46C:
	ldrb r0, [r5, #4]
	b _0811D472
_0811D470:
	ldrb r0, [r5]
_0811D472:
	subs r1, r1, r0
_0811D474:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811D49C
	cmp r1, #0
	blt _0811D49C
	ldr r0, _0811D4A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811D49C
	ldr r0, _0811D4A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811D4A8
_0811D49C:
	movs r4, #0
	b _0811D4B6
	.align 2, 0
_0811D4A0: .4byte 0x030046A8
_0811D4A4: .4byte 0x030046AC
_0811D4A8:
	ldr r0, _0811D4C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811D4B6:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811D4CC
	adds r0, #4
	b _0811D4D8
	.align 2, 0
_0811D4C8: .4byte 0x030046A4
_0811D4CC:
	ldr r0, _0811D4EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811D4D8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811D4F0
	cmp r3, #2
	beq _0811D4F4
	b _0811D4F8
	.align 2, 0
_0811D4EC: .4byte 0x030046A4
_0811D4F0:
	ldrb r0, [r5, #4]
	b _0811D4F6
_0811D4F4:
	ldrb r0, [r5]
_0811D4F6:
	subs r2, r2, r0
_0811D4F8:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_0811D502:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x30]
	cmp r0, #0
	bne _0811D60C
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0811D52C
	movs r0, #1
	b _0811D52E
_0811D52C:
	movs r0, #0
_0811D52E:
	ldr r3, _0811D61C @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x30]
	cmp r0, #0
	bne _0811D60C
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _0811D620 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0811D624 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r2, _0811D628 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x48]
	ldr r4, _0811D62C @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	ldr r5, _0811D630 @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x38]
	ldr r0, _0811D634 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x58]
	ldr r1, _0811D638 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	ldr r6, _0811D63C @ =0x0203B400
	ldr r1, _0811D640 @ =0x030046B8
	ldr r5, _0811D644 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_0811D57E:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _0811D59C
	adds r3, #1
	cmp r3, #3
	ble _0811D57E
	mov r0, r8
_0811D59C:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x50]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x18]
	ldrb r0, [r4]
	ldr r5, [sp, #0x44]
	strb r0, [r5]
	ldr r1, [sp, #0x1c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	ldr r4, [sp, #0x20]
	ldrb r0, [r4]
	ldr r5, [sp, #0x4c]
	strb r0, [r5]
	mov r0, sp
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #0x38]
	strb r1, [r0]
	ldr r4, [sp, #0x58]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x2c]
	strb r1, [r5]
	ldr r4, [sp, #0x24]
	strb r3, [r4]
	ldr r5, [sp, #0x50]
	strb r0, [r5]
	ldr r0, [sp, #0x54]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x40]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	ldr r0, [sp, #0x1c]
	strb r1, [r0]
	ldr r4, [sp, #0x20]
	strb r2, [r4]
	ldr r5, [sp, #0x34]
	str r3, [r5]
	ldr r0, [sp, #0x28]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x3c]
	strb r0, [r1]
_0811D60C:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r2, [sp, #0x30]
	strh r0, [r2]
	b _0811D8AA
	.align 2, 0
_0811D61C: .4byte 0x00000482
_0811D620: .4byte 0x0000054F
_0811D624: .4byte 0x0000054C
_0811D628: .4byte 0x0000054D
_0811D62C: .4byte 0x0000054E
_0811D630: .4byte 0x00000541
_0811D634: .4byte 0x000005BC
_0811D638: .4byte 0x00000542
_0811D63C: .4byte 0x0203B400
_0811D640: .4byte 0x030046B8
_0811D644: .4byte 0x000003FF
_0811D648:
	mov sb, sp
	ldr r6, _0811D684 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811D688
	adds r0, #4
	b _0811D692
	.align 2, 0
_0811D684: .4byte 0x030046A4
_0811D688:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811D692:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r5, _0811D6CC @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _0811D6D4
	ldr r0, _0811D6D0 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811D6FE
	.align 2, 0
_0811D6CC: .4byte 0x000004A4
_0811D6D0: .4byte 0xFFFFFDFF
_0811D6D4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0811D6F4
	cmp r0, #2
	beq _0811D6F0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811D6F0:
	movs r0, #1
	b _0811D700
_0811D6F4:
	ldr r0, _0811D714 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0811D6FE:
	movs r0, #0
_0811D700:
	cmp r0, #0
	beq _0811D706
	b _0811D8AA
_0811D706:
	ldr r4, _0811D718 @ =0x000005C4
	adds r0, r7, r4
_0811D70A:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0811D8AA
	.align 2, 0
_0811D714: .4byte 0xFFFFFDFF
_0811D718: .4byte 0x000005C4
_0811D71C:
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r3, _0811D790 @ =FUN_08116ce4
	movs r4, #7
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _0811D794 @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0811D798 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xa8
	adds r0, r7, r1
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811D78A
	cmp r1, #0
	blt _0811D78A
	ldr r0, _0811D79C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811D78A
	ldr r0, _0811D7A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811D7A4
_0811D78A:
	movs r4, #0
	b _0811D7B2
	.align 2, 0
_0811D790: .4byte FUN_08116ce4
_0811D794: .4byte 0x00000554
_0811D798: .4byte 0x00000551
_0811D79C: .4byte 0x030046A8
_0811D7A0: .4byte 0x030046AC
_0811D7A4:
	ldr r0, _0811D7C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811D7B2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811D7C8
	adds r0, #4
	b _0811D7D4
	.align 2, 0
_0811D7C4: .4byte 0x030046A4
_0811D7C8:
	ldr r0, _0811D7E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811D7D4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811D7EC
	cmp r2, #2
	beq _0811D7F0
	b _0811D7F4
	.align 2, 0
_0811D7E8: .4byte 0x030046A4
_0811D7EC:
	ldrb r0, [r5, #4]
	b _0811D7F2
_0811D7F0:
	ldrb r0, [r5]
_0811D7F2:
	subs r1, r1, r0
_0811D7F4:
	strh r1, [r5, #2]
	ldr r2, _0811D824 @ =0x000004A4
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0811D82C
	ldr r0, _0811D828 @ =0xFFFFFDFF
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	b _0811D856
	.align 2, 0
_0811D824: .4byte 0x000004A4
_0811D828: .4byte 0xFFFFFDFF
_0811D82C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0811D84C
	cmp r0, #2
	beq _0811D848
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811D848:
	movs r0, #1
	b _0811D858
_0811D84C:
	ldr r0, _0811D890 @ =0xFFFFFDFF
	mov r5, sl
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_0811D856:
	movs r0, #0
_0811D858:
	adds r3, r0, #0
	cmp r3, #0
	bne _0811D898
	ldr r0, _0811D894 @ =FUN_080e48d0
	movs r2, #1
	ldr r1, [sp, #0x2c]
	strb r2, [r1]
	ldr r4, [sp, #0x24]
	strb r3, [r4]
	ldr r5, [sp, #0x50]
	strb r3, [r5]
	ldr r1, [sp, #0x54]
	str r0, [r1]
	movs r1, #0
	ldr r4, [sp, #0x40]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	ldr r0, [sp, #0x1c]
	strb r1, [r0]
	ldr r4, [sp, #0x20]
	strb r1, [r4]
	ldr r5, [sp, #0x34]
	str r3, [r5]
	ldr r0, [sp, #0x28]
	strb r2, [r0]
	b _0811D8AA
	.align 2, 0
_0811D890: .4byte 0xFFFFFDFF
_0811D894: .4byte FUN_080e48d0
_0811D898:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _0811D8AA

	non_word_aligned_thumb_func_start FUN_0811d8a6
FUN_0811d8a6: @ 0x0811D8A6
	adds r0, #1
	str r0, [r1]
_0811D8AA:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0811d8bc
FUN_0811d8bc: @ 0x0811D8BC
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _0811D8C8 @ =0x085AD60C
	str r1, [r0]
	bx lr
	.align 2, 0
_0811D8C8: .4byte 0x085AD60C

	thumb_func_start FUN_0811d8cc
FUN_0811d8cc: @ 0x0811D8CC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D8F4
	ldr r2, _0811D920 @ =0x0000065A
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0811D8F4
	subs r0, #1
	strh r0, [r1]
_0811D8F4:
	ldrb r0, [r6, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	movs r2, #0xd8
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _0811D924 @ =0x000006C2
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r2, #4
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0811D920: .4byte 0x0000065A
_0811D924: .4byte 0x000006C2

	thumb_func_start FUN_0811d928
FUN_0811d928: @ 0x0811D928
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #0x40
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0811D960
	ldr r0, _0811D97C @ =0x000006E2
	adds r4, r2, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _0811D960
	movs r1, #0xdc
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrh r0, [r0]
	bl FUN_0823b9cc
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
_0811D960:
	adds r0, r5, #0
	bl FUN_08115c7c
	adds r0, r5, #0
	bl FUN_081160e0
	adds r0, r5, #0
	bl FUN_081161d0
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0811D97C: .4byte 0x000006E2

	thumb_func_start FUN_0811d980
FUN_0811d980: @ 0x0811D980
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0811D9A8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811D9AC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811D9AE
	.align 2, 0
_0811D9A8: .4byte 0x0000046C
_0811D9AC:
	movs r0, #0
_0811D9AE:
	cmp r0, #0
	beq _0811D9F4
	ldr r4, _0811DA4C @ =FUN_0811783c
	movs r3, #0x24
	ldr r6, _0811DA50 @ =0x0000046D
	adds r1, r5, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0811DA54 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrb r0, [r0]
	strb r0, [r5, #5]
	ldr r3, _0811DA54 @ =0x0000046B
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _0811DA58 @ =0x000006BC
	adds r0, r7, r6
	strh r2, [r0]
_0811D9F4:
	adds r0, r5, #0
	bl FUN_08116058
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811DA02
	b _0811DC82
_0811DA02:
	ldr r1, _0811DA54 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0811DA0E
	b _0811DC78
_0811DA0E:
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r6, [r0]
	adds r2, r5, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811DA46
	cmp r1, #0
	blt _0811DA46
	ldr r0, _0811DA5C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811DA46
	ldr r0, _0811DA60 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811DA64
_0811DA46:
	movs r4, #0
	b _0811DA72
	.align 2, 0
_0811DA4C: .4byte FUN_0811783c
_0811DA50: .4byte 0x0000046D
_0811DA54: .4byte 0x0000046B
_0811DA58: .4byte 0x000006BC
_0811DA5C: .4byte 0x030046A8
_0811DA60: .4byte 0x030046AC
_0811DA64:
	ldr r0, _0811DA88 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811DA72:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811DA8C
	adds r0, #4
	ldr r3, _0811DA88 @ =0x030046A4
	mov sl, r3
	b _0811DA9A
	.align 2, 0
_0811DA88: .4byte 0x030046A4
_0811DA8C:
	ldr r2, _0811DAB0 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
	mov sl, r2
_0811DA9A:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r3, r0, #8
	cmp r2, #1
	beq _0811DAB4
	cmp r2, #2
	beq _0811DAB8
	b _0811DABC
	.align 2, 0
_0811DAB0: .4byte 0x030046A4
_0811DAB4:
	ldrb r0, [r6, #4]
	b _0811DABA
_0811DAB8:
	ldrb r0, [r6]
_0811DABA:
	subs r3, r3, r0
_0811DABC:
	movs r1, #0
	movs r2, #0
	strh r3, [r6, #2]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r0, [r0]
	strh r2, [r0, #6]
	ldr r3, _0811DB48 @ =0x000006C1
	adds r0, r7, r3
	strb r1, [r0]
	ldr r6, _0811DB4C @ =0x000006B4
	adds r1, r7, r6
	movs r0, #0x78
	strh r0, [r1]
	ldr r1, _0811DB50 @ =0x000006BA
	adds r0, r7, r1
	strh r2, [r0]
	subs r3, #9
	adds r1, r7, r3
	movs r0, #2
	strh r0, [r1]
	adds r6, #2
	adds r0, r7, r6
	strh r2, [r0]
	movs r0, #0xda
	lsls r0, r0, #3
	adds r2, r7, r0
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _0811DB54 @ =0x00000256
	adds r0, r5, r2
	ldrh r6, [r0]
	mov sb, sp
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811DB58
	adds r0, #4
	b _0811DB64
	.align 2, 0
_0811DB48: .4byte 0x000006C1
_0811DB4C: .4byte 0x000006B4
_0811DB50: .4byte 0x000006BA
_0811DB54: .4byte 0x00000256
_0811DB58:
	mov r3, sl
	ldr r0, [r3]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811DB64:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r6, sb
	strh r0, [r6, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	mov r6, sp
	mov r0, sp
	bl FUN_081155a0
	add r3, sp, #8
	adds r4, r5, #0
	adds r4, #8
	ldrh r0, [r5, #8]
	mov r1, sp
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r2, #0
	ldrsh r0, [r3, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0811DBC4 @ =0x000008FF
	cmp r1, r0
	bgt _0811DBC8
	adds r0, r7, #0
	bl FUN_081155c4
	b _0811DC0E
	.align 2, 0
_0811DBC4: .4byte 0x000008FF
_0811DBC8:
	ldr r1, _0811DC5C @ =0x000004A4
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r6, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r2, #0
	ldrsh r0, [r3, r2]
	movs r6, #4
	ldrsh r1, [r3, r6]
	bl FUN_0823785c
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r5, #5]
	ldr r2, _0811DC60 @ =0x000006C2
	adds r1, r7, r2
	strb r0, [r1]
_0811DC0E:
	ldr r2, _0811DC64 @ =FUN_08117b94
	movs r1, #0x22
	ldr r3, _0811DC68 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0811DC6C @ =0x0000046B
	adds r0, r5, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0811DC70 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _0811DC74 @ =0x0000046A
	adds r0, r5, r2
	strb r4, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r3, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	b _0811DC82
	.align 2, 0
_0811DC5C: .4byte 0x000004A4
_0811DC60: .4byte 0x000006C2
_0811DC64: .4byte FUN_08117b94
_0811DC68: .4byte 0x0000046D
_0811DC6C: .4byte 0x0000046B
_0811DC70: .4byte 0x00000469
_0811DC74: .4byte 0x0000046A
_0811DC78:
	ldr r2, _0811DC94 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0811DC82:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811DC94: .4byte 0x00000484

	thumb_func_start FUN_0811dc98
FUN_0811dc98: @ 0x0811DC98
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0811DCB0 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811DCB4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811DCB6
	.align 2, 0
_0811DCB0: .4byte 0x0000046C
_0811DCB4:
	movs r0, #0
_0811DCB6:
	cmp r0, #0
	beq _0811DCEC
	ldr r4, _0811DD50 @ =FUN_081178c0
	movs r3, #0x21
	ldr r2, _0811DD54 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _0811DD58 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _0811DD5C @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	ldr r2, _0811DD58 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
_0811DCEC:
	adds r0, r5, #0
	bl FUN_08116058
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0811DD76
	ldr r3, _0811DD58 @ =0x0000046B
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0811DD6C
	ldr r2, _0811DD60 @ =FUN_08117b94
	movs r1, #0x22
	ldr r6, _0811DD54 @ =0x0000046D
	adds r0, r5, r6
	movs r3, #1
	strb r3, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r4, [r0]
	movs r2, #2
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0811DD64 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _0811DD68 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r4, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r3, [r0]
	b _0811DD76
	.align 2, 0
_0811DD50: .4byte FUN_081178c0
_0811DD54: .4byte 0x0000046D
_0811DD58: .4byte 0x0000046B
_0811DD5C: .4byte 0x00000553
_0811DD60: .4byte FUN_08117b94
_0811DD64: .4byte 0x00000469
_0811DD68: .4byte 0x0000046A
_0811DD6C:
	ldr r2, _0811DD7C @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0811DD76:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0811DD7C: .4byte 0x00000484

	thumb_func_start FUN_0811dd80
FUN_0811dd80: @ 0x0811DD80
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x6c
	str r0, [sp, #0x18]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	ldr r2, [sp, #0x18]
	ldr r3, _0811DDAC @ =0x0000046C
	adds r1, r2, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811DDB0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811DDB2
	.align 2, 0
_0811DDAC: .4byte 0x0000046C
_0811DDB0:
	movs r0, #0
_0811DDB2:
	cmp r0, #0
	beq _0811DDBE
	ldr r4, _0811DE08 @ =0x00000659
	adds r1, r7, r4
	movs r0, #1
	strb r0, [r1]
_0811DDBE:
	ldr r0, [sp, #0x18]
	bl FUN_08116058
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811DDCE
	bl _0811EDDA
_0811DDCE:
	ldr r6, _0811DE08 @ =0x00000659
	adds r5, r7, r6
	ldrb r0, [r5]
	cmp r0, #1
	bne _0811DDEE
	ldr r1, _0811DE0C @ =0x000006B6
	adds r0, r7, r1
	movs r2, #0
	ldrsh r4, [r0, r2]
	cmp r4, #0
	bne _0811DDEE
	ldr r0, [sp, #0x18]
	movs r1, #4
	bl FUN_080e81dc
	strb r4, [r5]
_0811DDEE:
	ldr r0, [sp, #0x18]
	bl FUN_08115f8c
	ldr r0, _0811DE10 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811DE14
	movs r0, #1
	b _0811DE16
	.align 2, 0
_0811DE08: .4byte 0x00000659
_0811DE0C: .4byte 0x000006B6
_0811DE10: .4byte 0x030047A4
_0811DE14:
	movs r0, #0
_0811DE16:
	cmp r0, #0
	beq _0811DE80
	ldr r3, [sp, #0x18]
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r3, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0811DED0
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811DE34
	adds r2, r0, #0
_0811DE34:
	cmp r2, #0
	blt _0811DED0
	ldr r1, _0811DE60 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0811DED0
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r5, _0811DE64 @ =0x0000065C
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0811DE68
	movs r0, #1
	b _0811DE6A
	.align 2, 0
_0811DE60: .4byte 0x03002BE0
_0811DE64: .4byte 0x0000065C
_0811DE68:
	movs r0, #0
_0811DE6A:
	adds r5, r0, #0
	cmp r5, #0
	bne _0811DED0
	ldr r6, _0811DE7C @ =0x000006B4
	adds r1, r7, r6
	ldrh r0, [r1]
	subs r0, #0x1e
	movs r4, #0
	b _0811E25E
	.align 2, 0
_0811DE7C: .4byte 0x000006B4
_0811DE80:
	ldr r0, _0811DEA4 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0811DED0
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r2, _0811DEA8 @ =0x0000065C
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0811DEAC
	movs r0, #1
	b _0811DEAE
	.align 2, 0
_0811DEA4: .4byte 0x03002BE0
_0811DEA8: .4byte 0x0000065C
_0811DEAC:
	movs r0, #0
_0811DEAE:
	adds r5, r0, #0
	cmp r5, #0
	bne _0811DED0
	ldr r3, _0811DEC8 @ =0x000006B4
	adds r1, r7, r3
	ldrh r0, [r1]
	subs r0, #0x1e
	movs r4, #0
	strh r0, [r1]
	ldr r6, _0811DECC @ =0x000006C4
	adds r0, r7, r6
	b _0811E264
	.align 2, 0
_0811DEC8: .4byte 0x000006B4
_0811DECC: .4byte 0x000006C4
_0811DED0:
	ldr r2, [sp, #0x18]
	ldr r3, _0811DF7C @ =0x000004A4
	adds r0, r2, r3
	ldr r2, [r0]
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _0811DEE8
	b _0811E404
_0811DEE8:
	ldr r4, _0811DF80 @ =0x000006B6
	adds r0, r7, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, [sp, #0x18]
	adds r1, r2, #0
	movs r2, #0x18
	movs r3, #0x18
	bl FUN_08115324
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811DF0A
	b _0811E2E8
_0811DF0A:
	movs r6, #0xda
	lsls r6, r6, #3
	adds r2, r7, r6
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	add r3, sp, #8
	ldr r4, [sp, #0x18]
	adds r4, #8
	ldrh r0, [r2]
	ldr r5, [sp, #0x18]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	adds r0, r3, #0
	movs r6, #0
	ldrsh r0, [r0, r6]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r3, r1, r0
	ldr r5, _0811DF84 @ =0x000006C2
	adds r2, r7, r5
	ldr r6, _0811DF88 @ =0x00000659
	adds r1, r7, r6
	movs r0, #1
	strb r0, [r1]
	ldr r1, [sp, #0x18]
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r0, r1, r5
	ldrb r1, [r0]
	ldrb r0, [r2]
	subs r1, r1, r0
	adds r6, r4, #0
	cmp r1, #0x80
	ble _0811DF90
	ldr r0, _0811DF8C @ =0xFFFFFF00
	adds r1, r1, r0
	b _0811DF9E
	.align 2, 0
_0811DF7C: .4byte 0x000004A4
_0811DF80: .4byte 0x000006B6
_0811DF84: .4byte 0x000006C2
_0811DF88: .4byte 0x00000659
_0811DF8C: .4byte 0xFFFFFF00
_0811DF90:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0811DF9E
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0811DF9E:
	cmp r1, #0
	bge _0811DFA4
	rsbs r1, r1, #0
_0811DFA4:
	cmp r1, #0xf
	bgt _0811DFE0
	ldr r0, _0811DFD0 @ =0x0000FFFE
	cmp r3, r0
	bgt _0811DFE0
	ldr r3, _0811DFD4 @ =0x000006B6
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0xc7
	ble _0811DFE0
	ldr r5, _0811DFD8 @ =0x000006B4
	adds r1, r7, r5
	ldrh r0, [r1]
	subs r0, #0x1e
	movs r4, #0
	movs r5, #0
	strh r0, [r1]
	ldr r6, _0811DFDC @ =0x000006C4
	adds r0, r7, r6
	b _0811E264
	.align 2, 0
_0811DFD0: .4byte 0x0000FFFE
_0811DFD4: .4byte 0x000006B6
_0811DFD8: .4byte 0x000006B4
_0811DFDC: .4byte 0x000006C4
_0811DFE0:
	ldr r2, _0811E004 @ =0x000006C2
	adds r0, r7, r2
	ldrb r4, [r0]
	add r1, sp, #8
	adds r0, r1, #0
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r5, #4
	ldrsh r1, [r1, r5]
	bl FUN_0823785c
	subs r1, r0, r4
	cmp r1, #0x80
	ble _0811E00C
	ldr r0, _0811E008 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0811E01A
	.align 2, 0
_0811E004: .4byte 0x000006C2
_0811E008: .4byte 0xFFFFFF00
_0811E00C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0811E01A
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0811E01A:
	adds r0, r1, #0
	cmp r0, #0
	bge _0811E022
	rsbs r0, r0, #0
_0811E022:
	cmp r0, #0xf
	bgt _0811E0C8
	movs r3, #0xda
	lsls r3, r3, #3
	adds r0, r7, r3
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811E050
	cmp r1, #0
	blt _0811E050
	ldr r0, _0811E054 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811E050
	ldr r0, _0811E058 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811E05C
_0811E050:
	movs r5, #0
	b _0811E06A
	.align 2, 0
_0811E054: .4byte 0x030046A8
_0811E058: .4byte 0x030046AC
_0811E05C:
	ldr r0, _0811E07C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811E06A:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811E080
	adds r0, #4
	b _0811E08C
	.align 2, 0
_0811E07C: .4byte 0x030046A4
_0811E080:
	ldr r0, _0811E0C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811E08C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	ldr r4, _0811E0C4 @ =0x000006C2
	adds r0, r7, r4
	ldrb r0, [r0]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r4, r0, #6
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_08115448
	cmp r0, #0
	bne _0811E0B8
	movs r5, #0xda
	lsls r5, r5, #3
	adds r0, r7, r5
	adds r1, r4, #0
	bl FUN_08115550
_0811E0B8:
	adds r0, r7, #0
	bl FUN_081155c4
	b _0811E0D4
	.align 2, 0
_0811E0C0: .4byte 0x030046A4
_0811E0C4: .4byte 0x000006C2
_0811E0C8:
	subs r0, #0x34
	cmp r0, #0x18
	bhi _0811E0D4
	adds r0, r7, #0
	bl FUN_081155c4
_0811E0D4:
	ldr r1, _0811E0EC @ =0x000006C4
	adds r0, r7, r1
	ldrb r1, [r0]
	ldr r2, _0811E0F0 @ =0x000006C2
	adds r0, r7, r2
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0811E0F8
	ldr r3, _0811E0F4 @ =0xFFFFFF00
	adds r1, r1, r3
	b _0811E106
	.align 2, 0
_0811E0EC: .4byte 0x000006C4
_0811E0F0: .4byte 0x000006C2
_0811E0F4: .4byte 0xFFFFFF00
_0811E0F8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0811E106
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
_0811E106:
	cmp r1, #0
	bge _0811E10C
	rsbs r1, r1, #0
_0811E10C:
	cmp r1, #0x1f
	ble _0811E180
	ldr r5, _0811E164 @ =0x000006C4
	adds r2, r7, r5
	ldrb r1, [r2]
	ldr r6, _0811E168 @ =0x000006C5
	adds r0, r7, r6
	movs r4, #0
	strb r1, [r0]
	ldrb r0, [r2]
	strb r0, [r7, #5]
	ldr r0, _0811E16C @ =0x000006B4
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0xa
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0811E136
	b _0811E558
_0811E136:
	ldr r2, _0811E170 @ =FUN_08117dc0
	movs r1, #0x26
	ldr r3, _0811E174 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _0811E178 @ =0x0000046B
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, _0811E17C @ =0x00000553
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #3
	b _0811E596
	.align 2, 0
_0811E164: .4byte 0x000006C4
_0811E168: .4byte 0x000006C5
_0811E16C: .4byte 0x000006B4
_0811E170: .4byte FUN_08117dc0
_0811E174: .4byte 0x0000046D
_0811E178: .4byte 0x0000046B
_0811E17C: .4byte 0x00000553
_0811E180:
	add r2, sp, #8
	ldr r1, [sp, #0x18]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r1, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r1, #8]
	subs r0, r0, r1
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r2, #0
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r5, #4
	ldrsh r0, [r2, r5]
	adds r6, r0, #0
	muls r6, r0, r6
	adds r0, r6, #0
	adds r3, r1, r0
	ldr r0, _0811E1E4 @ =0x0000FFFE
	cmp r3, r0
	bgt _0811E252
	ldr r1, _0811E1E8 @ =0x000006B6
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xc7
	ble _0811E252
	ldr r0, _0811E1EC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811E1F0
	movs r0, #1
	b _0811E1F2
	.align 2, 0
_0811E1E4: .4byte 0x0000FFFE
_0811E1E8: .4byte 0x000006B6
_0811E1EC: .4byte 0x030047A4
_0811E1F0:
	movs r0, #0
_0811E1F2:
	cmp r0, #0
	beq _0811E238
	ldr r3, [sp, #0x18]
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r3, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0811E252
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811E210
	adds r2, r0, #0
_0811E210:
	cmp r2, #0
	blt _0811E252
	ldr r1, _0811E230 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811E252
	ldr r5, _0811E234 @ =0x000006BC
	adds r1, r7, r5
	b _0811E24C
	.align 2, 0
_0811E230: .4byte 0x03002BE0
_0811E234: .4byte 0x000006BC
_0811E238:
	ldr r0, _0811E2BC @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811E252
	ldr r6, _0811E2C0 @ =0x000006BC
	adds r1, r7, r6
_0811E24C:
	movs r0, #0xc8
	lsls r0, r0, #1
	strh r0, [r1]
_0811E252:
	ldr r0, _0811E2C4 @ =0x000006B4
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0x1e
	movs r4, #0
	movs r5, #0
_0811E25E:
	strh r0, [r1]
	ldr r1, _0811E2C8 @ =0x000006C4
	adds r0, r7, r1
_0811E264:
	ldrb r1, [r0]
	ldr r2, _0811E2CC @ =0x000006C5
	adds r0, r7, r2
	strb r1, [r0]
	movs r1, #2
	movs r2, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r4, [r0]
	ldr r6, _0811E2D0 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811E2D4 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _0811E2D8 @ =0x00000484
	adds r0, r7, r2
	str r5, [r0]
	adds r3, #4
	adds r0, r7, r3
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0811E2DC @ =FUN_08118d9c
	movs r2, #0x2a
	adds r6, #4
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0811E2E0 @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _0811E2E4 @ =0x00000553
	adds r0, r7, r4
	strb r2, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	bl _0811EDDA
	.align 2, 0
_0811E2BC: .4byte 0x03002BE0
_0811E2C0: .4byte 0x000006BC
_0811E2C4: .4byte 0x000006B4
_0811E2C8: .4byte 0x000006C4
_0811E2CC: .4byte 0x000006C5
_0811E2D0: .4byte 0x00000469
_0811E2D4: .4byte 0x0000046A
_0811E2D8: .4byte 0x00000484
_0811E2DC: .4byte FUN_08118d9c
_0811E2E0: .4byte 0x0000046B
_0811E2E4: .4byte 0x00000553
_0811E2E8:
	ldr r2, [sp, #0x18]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r1, [r0]
	ldr r4, _0811E304 @ =0x000006C2
	adds r0, r7, r4
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0811E30C
	ldr r5, _0811E308 @ =0xFFFFFF00
	adds r1, r1, r5
	b _0811E31A
	.align 2, 0
_0811E304: .4byte 0x000006C2
_0811E308: .4byte 0xFFFFFF00
_0811E30C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0811E31A
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r1, r6
_0811E31A:
	cmp r1, #0
	bge _0811E320
	rsbs r1, r1, #0
_0811E320:
	cmp r1, #0xf
	bgt _0811E352
	ldr r1, [sp, #0x18]
	ldr r2, _0811E36C @ =0x00000256
	adds r0, r1, r2
	movs r3, #0x96
	lsls r3, r3, #2
	adds r1, r1, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _0811E352
	movs r4, #0xda
	lsls r4, r4, #3
	adds r2, r7, r4
	movs r5, #0xd9
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl FUN_081155c4
_0811E352:
	ldr r6, _0811E370 @ =0x000006C4
	adds r0, r7, r6
	ldrb r1, [r0]
	ldr r2, _0811E374 @ =0x000006C2
	adds r0, r7, r2
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0811E37C
	ldr r3, _0811E378 @ =0xFFFFFF00
	adds r1, r1, r3
	b _0811E38A
	.align 2, 0
_0811E36C: .4byte 0x00000256
_0811E370: .4byte 0x000006C4
_0811E374: .4byte 0x000006C2
_0811E378: .4byte 0xFFFFFF00
_0811E37C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0811E38A
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
_0811E38A:
	cmp r1, #0
	bge _0811E390
	rsbs r1, r1, #0
_0811E390:
	cmp r1, #0x1f
	bgt _0811E396
	b _0811E5C8
_0811E396:
	ldr r5, _0811E3E8 @ =0x000006C4
	adds r2, r7, r5
	ldrb r1, [r2]
	ldr r6, _0811E3EC @ =0x000006C5
	adds r0, r7, r6
	movs r4, #0
	strb r1, [r0]
	ldrb r0, [r2]
	strb r0, [r7, #5]
	ldr r0, _0811E3F0 @ =0x000006B4
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0xa
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0811E3BC
	b _0811E558
_0811E3BC:
	ldr r2, _0811E3F4 @ =FUN_08117dc0
	movs r1, #0x26
	ldr r3, _0811E3F8 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _0811E3FC @ =0x0000046B
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, _0811E400 @ =0x00000553
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #3
	b _0811E596
	.align 2, 0
_0811E3E8: .4byte 0x000006C4
_0811E3EC: .4byte 0x000006C5
_0811E3F0: .4byte 0x000006B4
_0811E3F4: .4byte FUN_08117dc0
_0811E3F8: .4byte 0x0000046D
_0811E3FC: .4byte 0x0000046B
_0811E400: .4byte 0x00000553
_0811E404:
	ldr r3, _0811E440 @ =0x000006B6
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp, #0x18]
	adds r1, r2, #0
	movs r2, #0x18
	movs r3, #0x18
	bl FUN_08115324
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811E444
	movs r5, #0xda
	lsls r5, r5, #3
	adds r2, r7, r5
	movs r6, #0xd9
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl FUN_081155c4
	b _0811E4AE
	.align 2, 0
_0811E440: .4byte 0x000006B6
_0811E444:
	ldr r1, [sp, #0x18]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r1, [r0]
	ldr r3, _0811E460 @ =0x000006C2
	adds r0, r7, r3
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0811E468
	ldr r4, _0811E464 @ =0xFFFFFF00
	adds r1, r1, r4
	b _0811E476
	.align 2, 0
_0811E460: .4byte 0x000006C2
_0811E464: .4byte 0xFFFFFF00
_0811E468:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0811E476
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r1, r5
_0811E476:
	cmp r1, #0
	bge _0811E47C
	rsbs r1, r1, #0
_0811E47C:
	cmp r1, #0xf
	bgt _0811E4AE
	ldr r6, [sp, #0x18]
	ldr r1, _0811E4C8 @ =0x00000256
	adds r0, r6, r1
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r6, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _0811E4AE
	movs r3, #0xda
	lsls r3, r3, #3
	adds r2, r7, r3
	movs r4, #0xd9
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl FUN_081155c4
_0811E4AE:
	ldr r5, _0811E4CC @ =0x000006C4
	adds r0, r7, r5
	ldrb r1, [r0]
	ldr r6, _0811E4D0 @ =0x000006C2
	adds r0, r7, r6
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0811E4D8
	ldr r0, _0811E4D4 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0811E4E6
	.align 2, 0
_0811E4C8: .4byte 0x00000256
_0811E4CC: .4byte 0x000006C4
_0811E4D0: .4byte 0x000006C2
_0811E4D4: .4byte 0xFFFFFF00
_0811E4D8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0811E4E6
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0811E4E6:
	cmp r1, #0
	bge _0811E4EC
	rsbs r1, r1, #0
_0811E4EC:
	cmp r1, #0x1f
	ble _0811E5C8
	ldr r3, _0811E540 @ =0x000006C4
	adds r2, r7, r3
	ldrb r1, [r2]
	ldr r4, _0811E544 @ =0x000006C5
	adds r0, r7, r4
	movs r4, #0
	strb r1, [r0]
	ldrb r0, [r2]
	strb r0, [r7, #5]
	ldr r5, _0811E548 @ =0x000006B4
	adds r1, r7, r5
	ldrh r0, [r1]
	subs r0, #0xa
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0811E558
	ldr r2, _0811E54C @ =FUN_08117dc0
	movs r1, #0x26
	ldr r6, _0811E550 @ =0x0000046D
	adds r0, r7, r6
	movs r3, #1
	strb r3, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, _0811E554 @ =0x00000553
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #3
	b _0811E596
	.align 2, 0
_0811E540: .4byte 0x000006C4
_0811E544: .4byte 0x000006C5
_0811E548: .4byte 0x000006B4
_0811E54C: .4byte FUN_08117dc0
_0811E550: .4byte 0x0000046D
_0811E554: .4byte 0x00000553
_0811E558:
	movs r0, #0xda
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r1, _0811E5AC @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _0811E5B0 @ =FUN_08117ef8
	movs r1, #0x25
	ldr r3, _0811E5B4 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _0811E5B8 @ =0x0000046B
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, _0811E5BC @ =0x00000553
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #2
_0811E596:
	ldr r2, _0811E5C0 @ =0x0000046A
	adds r0, r7, r2
	strb r1, [r0]
	subs r5, #0xcf
	adds r0, r7, r5
	str r4, [r0]
	ldr r6, _0811E5C4 @ =0x0000046C
	adds r0, r7, r6
	strb r3, [r0]
	bl _0811EDDA
	.align 2, 0
_0811E5AC: .4byte 0x000004A4
_0811E5B0: .4byte FUN_08117ef8
_0811E5B4: .4byte 0x0000046D
_0811E5B8: .4byte 0x0000046B
_0811E5BC: .4byte 0x00000553
_0811E5C0: .4byte 0x0000046A
_0811E5C4: .4byte 0x0000046C
_0811E5C8:
	ldr r1, _0811E6F8 @ =0x000006B4
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _0811E5D8
	bl _0811EDC4
_0811E5D8:
	ldr r0, [sp, #0x18]
	movs r1, #0
	bl FUN_080ef86c
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	ldr r3, [sp, #0x18]
	adds r4, r3, r4
	str r4, [sp, #0x1c]
	movs r1, #0
	strb r0, [r4]
	ldr r5, _0811E6FC @ =0x00000469
	adds r5, r3, r5
	str r5, [sp, #0x20]
	movs r6, #1
	strb r6, [r5]
	ldr r0, _0811E700 @ =0x0000046A
	adds r3, r3, r0
	mov ip, r3
	strb r1, [r3]
	ldr r2, [sp, #0x18]
	ldr r3, _0811E704 @ =0x00000484
	adds r2, r2, r3
	mov sl, r2
	str r1, [r2]
	ldr r4, [sp, #0x18]
	ldr r5, _0811E708 @ =0x0000046C
	adds r6, r4, r5
	movs r0, #1
	strb r0, [r6]
	ldr r2, _0811E70C @ =FUN_080e6794
	movs r0, #0xe
	subs r3, #0x17
	adds r4, r4, r3
	mov sb, r4
	movs r5, #1
	strb r5, [r4]
	ldr r3, [sp, #0x18]
	ldr r4, _0811E710 @ =0x0000046B
	adds r3, r3, r4
	mov r8, r3
	strb r1, [r3]
	ldr r3, [sp, #0x18]
	adds r4, #0xe8
	adds r5, r3, r4
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r4, r3, r0
	str r2, [r4]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r3, r3, r2
	strh r1, [r3]
	ldr r0, [sp, #0x18]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r0, r1
	ldr r0, _0811E714 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ands r1, r0
	str r6, [sp, #0x40]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x30]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x34]
	mov r6, ip
	str r6, [sp, #0x38]
	mov r0, sl
	str r0, [sp, #0x4c]
	mov r6, sb
	str r6, [sp, #0x44]
	mov r0, r8
	str r0, [sp, #0x3c]
	str r5, [sp, #0x68]
	str r4, [sp, #0x28]
	str r3, [sp, #0x58]
	mov sl, r2
	cmp r1, #0
	bne _0811E682
	b _0811EC58
_0811E682:
	ldr r1, [sp, #0x18]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	ldr r5, [sp, #0x18]
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r5, r6
	subs r6, #4
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0811E718 @ =0x00000551
	adds r0, r5, r3
	strb r2, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r5, r0
	ldr r5, [r3]
	ldr r2, [sp, #0x18]
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _0811E6F2
	cmp r1, #0
	blt _0811E6F2
	ldr r0, _0811E71C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0811E6F2
	ldr r0, _0811E720 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811E724
_0811E6F2:
	movs r4, #0
	b _0811E732
	.align 2, 0
_0811E6F8: .4byte 0x000006B4
_0811E6FC: .4byte 0x00000469
_0811E700: .4byte 0x0000046A
_0811E704: .4byte 0x00000484
_0811E708: .4byte 0x0000046C
_0811E70C: .4byte FUN_080e6794
_0811E710: .4byte 0x0000046B
_0811E714: .4byte 0xFFFFFEFF
_0811E718: .4byte 0x00000551
_0811E71C: .4byte 0x030046A8
_0811E720: .4byte 0x030046AC
_0811E724:
	ldr r0, _0811E744 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0811E732:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811E748
	adds r0, #4
	b _0811E754
	.align 2, 0
_0811E744: .4byte 0x030046A4
_0811E748:
	ldr r0, _0811E768 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811E754:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811E76C
	cmp r2, #2
	beq _0811E770
	b _0811E774
	.align 2, 0
_0811E768: .4byte 0x030046A4
_0811E76C:
	ldrb r0, [r5, #4]
	b _0811E772
_0811E770:
	ldrb r0, [r5]
_0811E772:
	subs r1, r1, r0
_0811E774:
	strh r1, [r5, #2]
	ldr r0, _0811E788 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811E78C
	movs r0, #1
	b _0811E78E
	.align 2, 0
_0811E788: .4byte 0x030047A4
_0811E78C:
	movs r0, #0
_0811E78E:
	cmp r0, #0
	beq _0811E7D4
	ldr r1, [sp, #0x18]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _0811E7B0
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811E7AC
	adds r2, r0, #0
_0811E7AC:
	cmp r2, #0
	bge _0811E7C0
_0811E7B0:
	ldr r3, [sp, #0x18]
	ldr r4, _0811E7BC @ =0x000005C4
	adds r0, r3, r4
	ldr r1, [r0]
	adds r0, r3, #0
	b _0811EC2E
	.align 2, 0
_0811E7BC: .4byte 0x000005C4
_0811E7C0:
	ldr r1, _0811E7D0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811E820
	.align 2, 0
_0811E7D0: .4byte 0x03002BE0
_0811E7D4:
	ldr r5, [sp, #0x18]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811E802
	cmp r1, #0
	blt _0811E802
	ldr r0, _0811E808 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811E802
	ldr r0, _0811E80C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811E810
_0811E802:
	movs r5, #0
	b _0811E81E
	.align 2, 0
_0811E808: .4byte 0x030046A8
_0811E80C: .4byte 0x030046AC
_0811E810:
	ldr r0, _0811E858 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811E81E:
	movs r2, #0
_0811E820:
	ldr r3, [sp, #0x18]
	ldr r4, _0811E85C @ =0x00000256
	adds r0, r3, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811E842
	ldr r1, _0811E860 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811E842
	b _0811EB64
_0811E842:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0811E864
	movs r0, #0
	b _0811EC42
	.align 2, 0
_0811E858: .4byte 0x030046A4
_0811E85C: .4byte 0x00000256
_0811E860: .4byte 0x03002BE0
_0811E864:
	ldr r0, [sp, #0x18]
	ldr r1, _0811E8C4 @ =0x00000222
	adds r2, r0, r1
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _0811E8C8
	ldr r6, [sp, #0x18]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x44]
	strb r2, [r3]
	ldr r6, [sp, #0x3c]
	strb r5, [r6]
	ldr r3, [sp, #0x68]
	strb r0, [r3]
	ldr r6, [sp, #0x28]
	str r1, [r6]
	ldr r0, [sp, #0x58]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x30]
	strb r5, [r1]
	ldr r3, [sp, #0x34]
	strb r5, [r3]
	ldr r5, [sp, #0x38]
	strb r0, [r5]
	ldr r6, [sp, #0x4c]
	str r4, [r6]
	ldr r0, [sp, #0x40]
	strb r2, [r0]
	b _0811EA1A
	.align 2, 0
_0811E8C4: .4byte 0x00000222
_0811E8C8:
	ldr r1, [sp, #0x18]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r1, [r0]
	movs r0, #1
	ldr r4, [sp, #0x44]
	strb r0, [r4]
	ldr r2, [sp, #0x3c]
	strb r5, [r2]
	ldr r4, [sp, #0x68]
	strb r0, [r4]
	ldr r2, [sp, #0x28]
	str r1, [r2]
	ldr r4, [sp, #0x58]
	strh r3, [r4]
	movs r1, #5
	ldr r2, [sp, #0x30]
	strb r5, [r2]
	ldr r4, [sp, #0x34]
	strb r5, [r4]
	ldr r5, [sp, #0x38]
	strb r1, [r5]
	ldr r1, [sp, #0x4c]
	str r3, [r1]
	ldr r2, [sp, #0x40]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811E92E
	cmp r1, #0
	blt _0811E92E
	ldr r0, _0811E934 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811E92E
	ldr r0, _0811E938 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811E93C
_0811E92E:
	movs r4, #0
	b _0811E94A
	.align 2, 0
_0811E934: .4byte 0x030046A8
_0811E938: .4byte 0x030046AC
_0811E93C:
	ldr r0, _0811E95C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811E94A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811E960
	adds r0, #4
	b _0811E96C
	.align 2, 0
_0811E95C: .4byte 0x030046A4
_0811E960:
	ldr r0, _0811E980 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811E96C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811E984
	cmp r2, #2
	beq _0811E988
	b _0811E98C
	.align 2, 0
_0811E980: .4byte 0x030046A4
_0811E984:
	ldrb r0, [r5, #4]
	b _0811E98A
_0811E988:
	ldrb r0, [r5]
_0811E98A:
	subs r1, r1, r0
_0811E98C:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811E9B4
	cmp r1, #0
	blt _0811E9B4
	ldr r0, _0811E9B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811E9B4
	ldr r0, _0811E9BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811E9C0
_0811E9B4:
	movs r4, #0
	b _0811E9CE
	.align 2, 0
_0811E9B8: .4byte 0x030046A8
_0811E9BC: .4byte 0x030046AC
_0811E9C0:
	ldr r0, _0811E9E0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811E9CE:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811E9E4
	adds r0, #4
	b _0811E9F0
	.align 2, 0
_0811E9E0: .4byte 0x030046A4
_0811E9E4:
	ldr r0, _0811EA04 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811E9F0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811EA08
	cmp r3, #2
	beq _0811EA0C
	b _0811EA10
	.align 2, 0
_0811EA04: .4byte 0x030046A4
_0811EA08:
	ldrb r0, [r5, #4]
	b _0811EA0E
_0811EA0C:
	ldrb r0, [r5]
_0811EA0E:
	subs r2, r2, r0
_0811EA10:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_0811EA1A:
	ldr r4, [sp, #0x18]
	ldrb r4, [r4, #5]
	str r4, [sp, #0x24]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	ldr r6, [sp, #0x18]
	adds r1, r6, r1
	str r1, [sp, #0x48]
	cmp r0, #0
	bne _0811EB32
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0811EA48
	movs r0, #1
	b _0811EA4A
_0811EA48:
	movs r0, #0
_0811EA4A:
	ldr r4, _0811EB44 @ =0x00000482
	ldr r3, [sp, #0x18]
	adds r4, r3, r4
	str r4, [sp, #0x48]
	cmp r0, #0
	bne _0811EB32
	movs r3, #0
	ldr r5, [sp, #0x18]
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r5, r5, r6
	mov sb, r5
	ldr r0, [sp, #0x18]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r0, r0, r1
	mov sl, r0
	ldr r2, [sp, #0x18]
	ldr r4, _0811EB48 @ =0x0000054F
	adds r2, r2, r4
	mov ip, r2
	adds r6, #0xc
	ldr r5, [sp, #0x18]
	adds r6, r5, r6
	str r6, [sp, #0x5c]
	ldr r0, _0811EB4C @ =0x0000054D
	adds r0, r5, r0
	str r0, [sp, #0x60]
	adds r1, #6
	adds r1, r5, r1
	str r1, [sp, #0x64]
	ldr r2, _0811EB50 @ =0x00000541
	adds r2, r5, r2
	str r2, [sp, #0x50]
	adds r4, #0x6d
	adds r4, r5, r4
	str r4, [sp, #0x2c]
	ldr r6, _0811EB54 @ =0x00000542
	adds r6, r5, r6
	str r6, [sp, #0x54]
	ldr r6, _0811EB58 @ =0x0203B400
	ldr r1, _0811EB5C @ =0x030046B8
	ldr r5, _0811EB60 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_0811EAA4:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _0811EAC2
	adds r3, #1
	cmp r3, #3
	ble _0811EAA4
	mov r0, r8
_0811EAC2:
	movs r3, #0
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x28]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x68]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0x30]
	ldrb r0, [r1]
	ldr r2, [sp, #0x5c]
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	ldrb r0, [r4]
	ldr r5, [sp, #0x60]
	strb r0, [r5]
	ldr r6, [sp, #0x38]
	ldrb r0, [r6]
	ldr r1, [sp, #0x64]
	strb r0, [r1]
	add r2, sp, #0x24
	ldrb r4, [r2]
	ldr r2, [sp, #0x50]
	strb r4, [r2]
	ldr r4, [sp, #0x2c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r6, [sp, #0x3c]
	strb r3, [r6]
	ldr r4, [sp, #0x68]
	strb r0, [r4]
	ldr r5, [sp, #0x28]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x58]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x30]
	strb r0, [r4]
	ldr r5, [sp, #0x34]
	strb r1, [r5]
	ldr r6, [sp, #0x38]
	strb r2, [r6]
	ldr r0, [sp, #0x4c]
	str r3, [r0]
	ldr r2, [sp, #0x40]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x54]
	strb r0, [r3]
_0811EB32:
	ldr r0, [sp, #0x18]
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x48]
	strh r0, [r4]
	movs r0, #0
	b _0811EC42
	.align 2, 0
_0811EB44: .4byte 0x00000482
_0811EB48: .4byte 0x0000054F
_0811EB4C: .4byte 0x0000054D
_0811EB50: .4byte 0x00000541
_0811EB54: .4byte 0x00000542
_0811EB58: .4byte 0x0203B400
_0811EB5C: .4byte 0x030046B8
_0811EB60: .4byte 0x000003FF
_0811EB64:
	add r6, sp, #0x10
	ldr r0, _0811EBA4 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811EBA8
	adds r0, #4
	b _0811EBB4
	.align 2, 0
_0811EBA4: .4byte 0x030046A4
_0811EBA8:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811EBB4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, [sp, #0x18]
	ldr r6, _0811EBEC @ =0x000004A4
	adds r0, r5, r6
	ldr r4, [r0]
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	add r2, sp, #0x10
	bl FUN_0823599c
	cmp r0, #0
	bne _0811EBF4
	ldr r0, _0811EBF0 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811EC1E
	.align 2, 0
_0811EBEC: .4byte 0x000004A4
_0811EBF0: .4byte 0xFFFFFDFF
_0811EBF4:
	adds r0, r4, #0
	adds r1, r5, #0
	add r2, sp, #0x10
	bl FUN_08235f40
	cmp r0, #0
	beq _0811EC14
	cmp r0, #2
	beq _0811EC10
	ldr r0, [sp, #0x18]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811EC10:
	movs r0, #1
	b _0811EC20
_0811EC14:
	ldr r0, _0811EC38 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0811EC1E:
	movs r0, #0
_0811EC20:
	cmp r0, #0
	bne _0811EC40
	ldr r4, [sp, #0x18]
	ldr r5, _0811EC3C @ =0x000005C4
	adds r0, r4, r5
	ldr r1, [r0]
	adds r0, r4, #0
_0811EC2E:
	bl _call_via_r1
	movs r0, #0
	b _0811EC42
	.align 2, 0
_0811EC38: .4byte 0xFFFFFDFF
_0811EC3C: .4byte 0x000005C4
_0811EC40:
	movs r0, #1
_0811EC42:
	cmp r0, #0
	bne _0811EC48
	b _0811EDDA
_0811EC48:
	ldr r6, [sp, #0x18]
	ldr r0, _0811EC54 @ =0x00000482
	adds r1, r6, r0
	movs r0, #2
	strh r0, [r1]
	b _0811EDC4
	.align 2, 0
_0811EC54: .4byte 0x00000482
_0811EC58:
	movs r2, #0x10
	ldr r3, [sp, #0x18]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r5, _0811ECDC @ =0x00000482
	adds r0, r3, r5
	movs r6, #1
	strh r6, [r0]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	ldr r5, [sp, #0x18]
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r5, r6
	subs r6, #4
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0811ECE0 @ =0x00000551
	adds r0, r5, r3
	strb r2, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	subs r1, #0xa8
	adds r0, r5, r1
	ldr r5, [r0]
	ldr r2, [sp, #0x18]
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811ECD8
	cmp r1, #0
	blt _0811ECD8
	ldr r0, _0811ECE4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811ECD8
	ldr r0, _0811ECE8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811ECEC
_0811ECD8:
	movs r4, #0
	b _0811ECFA
	.align 2, 0
_0811ECDC: .4byte 0x00000482
_0811ECE0: .4byte 0x00000551
_0811ECE4: .4byte 0x030046A8
_0811ECE8: .4byte 0x030046AC
_0811ECEC:
	ldr r0, _0811ED0C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811ECFA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811ED10
	adds r0, #4
	b _0811ED1C
	.align 2, 0
_0811ED0C: .4byte 0x030046A4
_0811ED10:
	ldr r0, _0811ED30 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811ED1C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811ED34
	cmp r2, #2
	beq _0811ED38
	b _0811ED3C
	.align 2, 0
_0811ED30: .4byte 0x030046A4
_0811ED34:
	ldrb r0, [r5, #4]
	b _0811ED3A
_0811ED38:
	ldrb r0, [r5]
_0811ED3A:
	subs r1, r1, r0
_0811ED3C:
	strh r1, [r5, #2]
	ldr r3, [sp, #0x18]
	movs r4, #0x95
	lsls r4, r4, #3
	adds r2, r3, r4
	ldr r1, [r2]
	movs r0, #1
	strh r0, [r1, #6]
	ldr r5, _0811ED74 @ =0x000004A4
	adds r0, r3, r5
	ldr r4, [r0]
	adds r5, r3, #0
	adds r5, #8
	ldr r6, [r2]
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0811ED7C
	ldr r0, _0811ED78 @ =0xFFFFFDFF
	mov r6, sl
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _0811EDA6
	.align 2, 0
_0811ED74: .4byte 0x000004A4
_0811ED78: .4byte 0xFFFFFDFF
_0811ED7C:
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0811ED9C
	cmp r0, #2
	beq _0811ED98
	ldr r0, [sp, #0x18]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811ED98:
	movs r0, #1
	b _0811EDA8
_0811ED9C:
	ldr r0, _0811EDBC @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0811EDA6:
	movs r0, #0
_0811EDA8:
	cmp r0, #0
	bne _0811EDC4
	ldr r3, [sp, #0x18]
	ldr r4, _0811EDC0 @ =0x000005C4
	adds r0, r3, r4
	ldr r1, [r0]
	adds r0, r3, #0
	bl _call_via_r1
	b _0811EDDA
	.align 2, 0
_0811EDBC: .4byte 0xFFFFFDFF
_0811EDC0: .4byte 0x000005C4
_0811EDC4:
	ldr r5, _0811EDEC @ =0x000006BA
	adds r1, r7, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r6, [sp, #0x18]
	ldr r0, _0811EDF0 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0811EDDA:
	add sp, #0x6c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811EDEC: .4byte 0x000006BA
_0811EDF0: .4byte 0x00000484

	thumb_func_start FUN_0811edf4
FUN_0811edf4: @ 0x0811EDF4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _0811EE14 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811EE18
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811EE1A
	.align 2, 0
_0811EE14: .4byte 0x0000046C
_0811EE18:
	movs r0, #0
_0811EE1A:
	cmp r0, #0
	beq _0811EE26
	ldr r3, _0811EE54 @ =0x0000046B
	adds r1, r6, r3
	movs r0, #0
	strb r0, [r1]
_0811EE26:
	adds r0, r6, #0
	bl FUN_08116058
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811EE34
	b _0811F042
_0811EE34:
	ldr r5, _0811EE54 @ =0x0000046B
	adds r0, r6, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _0811EE40
	b _0811F038
_0811EE40:
	adds r3, r4, #0
	ldr r0, _0811EE58 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811EE5C
	movs r0, #1
	b _0811EE5E
	.align 2, 0
_0811EE54: .4byte 0x0000046B
_0811EE58: .4byte 0x030047A4
_0811EE5C:
	movs r0, #0
_0811EE5E:
	cmp r0, #0
	beq _0811EE8C
	movs r7, #0xec
	lsls r7, r7, #1
	adds r0, r3, r7
	ldr r1, [r0]
	cmp r1, #0
	beq _0811EE9C
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811EE7A
	adds r2, r0, #0
_0811EE7A:
	cmp r2, #0
	blt _0811EE9C
	ldr r1, _0811EE88 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	b _0811EE8E
	.align 2, 0
_0811EE88: .4byte 0x03002BE0
_0811EE8C:
	ldr r0, _0811EF04 @ =0x03002BE0
_0811EE8E:
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811EEDA
_0811EE9C:
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0811EEDA
	movs r5, #0xf2
	lsls r5, r5, #1
	adds r0, r3, r5
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xf
	subs r0, r0, r1
	cmp r0, #0
	bge _0811EEC0
	movs r0, #0
_0811EEC0:
	ldr r7, _0811EF08 @ =0x000006BC
	adds r1, r4, r7
	asrs r0, r0, #0x10
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xc8
	lsls r2, r2, #1
	cmp r0, r2
	bls _0811EEDA
	strh r2, [r1]
_0811EEDA:
	adds r3, r4, #0
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r3, r5
	ldr r0, [r0]
	cmp r0, #0
	beq _0811EFCC
	movs r2, #0
	movs r7, #0x90
	lsls r7, r7, #3
	adds r0, r3, r7
	ldrh r0, [r0]
	cmp r0, #0
	bne _0811EF10
	ldr r1, _0811EF08 @ =0x000006BC
	adds r0, r3, r1
	ldrh r1, [r0]
	ldr r0, _0811EF0C @ =0x0000018F
	cmp r1, r0
	bls _0811EF1C
	b _0811EF20
	.align 2, 0
_0811EF04: .4byte 0x03002BE0
_0811EF08: .4byte 0x000006BC
_0811EF0C: .4byte 0x0000018F
_0811EF10:
	ldr r5, _0811EFAC @ =0x000006BC
	adds r0, r3, r5
	ldrh r0, [r0]
	cmp r0, #0xc7
	bls _0811EF1C
	movs r2, #1
_0811EF1C:
	cmp r2, #0
	beq _0811EF54
_0811EF20:
	movs r7, #0xf2
	lsls r7, r7, #1
	adds r0, r3, r7
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0811EF54
	adds r0, r4, #0
	adds r0, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r1, [r1]
	adds r1, #8
	movs r2, #0xa
	movs r3, #0x80
	lsls r3, r3, #1
	bl FUN_082340c8
	lsls r0, r0, #0x18
	movs r1, #1
	cmp r0, #0
	bne _0811EF56
_0811EF54:
	movs r1, #0
_0811EF56:
	cmp r1, #0
	beq _0811EFCC
	ldr r2, _0811EFB0 @ =FUN_081183d0
	movs r1, #0x27
	ldr r5, _0811EFB4 @ =0x0000046D
	adds r0, r6, r5
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r7, _0811EFB8 @ =0x0000046B
	adds r0, r6, r7
	strb r3, [r0]
	ldr r4, _0811EFBC @ =0x00000553
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #4
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0811EFC0 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _0811EFC4 @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _0811EFC8 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _0811F042
	.align 2, 0
_0811EFAC: .4byte 0x000006BC
_0811EFB0: .4byte FUN_081183d0
_0811EFB4: .4byte 0x0000046D
_0811EFB8: .4byte 0x0000046B
_0811EFBC: .4byte 0x00000553
_0811EFC0: .4byte 0x00000469
_0811EFC4: .4byte 0x0000046A
_0811EFC8: .4byte 0x00000484
_0811EFCC:
	ldr r2, _0811F01C @ =FUN_08117b94
	movs r1, #0x22
	ldr r3, _0811F020 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _0811F024 @ =0x0000046B
	adds r0, r6, r5
	strb r3, [r0]
	ldr r7, _0811F028 @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	subs r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	subs r7, #0xea
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _0811F02C @ =0x0000046A
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _0811F030 @ =0x00000484
	adds r0, r6, r2
	str r3, [r0]
	ldr r3, _0811F034 @ =0x0000046C
	adds r0, r6, r3
	strb r4, [r0]
	b _0811F042
	.align 2, 0
_0811F01C: .4byte FUN_08117b94
_0811F020: .4byte 0x0000046D
_0811F024: .4byte 0x0000046B
_0811F028: .4byte 0x00000553
_0811F02C: .4byte 0x0000046A
_0811F030: .4byte 0x00000484
_0811F034: .4byte 0x0000046C
_0811F038:
	ldr r4, _0811F048 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0811F042:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811F048: .4byte 0x00000484

	thumb_func_start FUN_0811f04c
FUN_0811f04c: @ 0x0811F04C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x68
	adds r7, r0, #0
	ldr r0, _0811F174 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811F068
	movs r0, #0
	strb r0, [r1]
_0811F068:
	adds r0, r7, #0
	bl FUN_08116058
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _0811F07A
	bl _0811F8F6
_0811F07A:
	ldr r1, _0811F178 @ =0x0000046B
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0811F088
	bl FUN_0811f8ec
_0811F088:
	movs r0, #3
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #8]
	strb r0, [r2]
	ldr r4, _0811F17C @ =0x00000469
	adds r4, r7, r4
	str r4, [sp, #0xc]
	strb r1, [r4]
	ldr r5, _0811F180 @ =0x0000046A
	adds r5, r7, r5
	str r5, [sp, #0x10]
	strb r3, [r5]
	ldr r6, _0811F184 @ =0x00000484
	adds r6, r7, r6
	str r6, [sp, #0x14]
	str r3, [r6]
	ldr r0, _0811F174 @ =0x0000046C
	adds r0, r0, r7
	mov sb, r0
	strb r1, [r0]
	ldr r2, _0811F188 @ =FUN_080e6794
	movs r0, #0xe
	ldr r4, _0811F18C @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x18]
	strb r1, [r4]
	ldr r5, _0811F178 @ =0x0000046B
	adds r5, r5, r7
	mov sl, r5
	strb r3, [r5]
	ldr r6, _0811F190 @ =0x00000553
	adds r6, r6, r7
	mov r8, r6
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r6, r7, r0
	str r2, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	strh r3, [r5]
	ldr r2, _0811F194 @ =0x000004A4
	adds r0, r7, r2
	ldr r0, [r0]
	adds r4, r7, #0
	adds r4, #8
	adds r1, r4, #0
	bl FUN_082362fc
	movs r0, #0x80
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r2, [r1]
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov r0, sb
	str r0, [sp, #0x3c]
	ldr r0, [sp, #8]
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x34]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x48]
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x40]
	mov r0, sl
	str r0, [sp, #0x38]
	mov r0, r8
	str r0, [sp, #0x60]
	str r6, [sp, #0x64]
	str r5, [sp, #0x20]
	str r4, [sp, #0x24]
	mov sl, r1
	cmp r3, #0
	bne _0811F130
	b _0811F728
_0811F130:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	ldr r6, _0811F198 @ =0x00000554
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0811F19C @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #6
	adds r0, r7, r5
	strb r4, [r0]
	ldr r0, _0811F1A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811F1A4
	movs r0, #1
	b _0811F1A6
	.align 2, 0
_0811F174: .4byte 0x0000046C
_0811F178: .4byte 0x0000046B
_0811F17C: .4byte 0x00000469
_0811F180: .4byte 0x0000046A
_0811F184: .4byte 0x00000484
_0811F188: .4byte FUN_080e6794
_0811F18C: .4byte 0x0000046D
_0811F190: .4byte 0x00000553
_0811F194: .4byte 0x000004A4
_0811F198: .4byte 0x00000554
_0811F19C: .4byte 0x00000551
_0811F1A0: .4byte 0x030047A4
_0811F1A4:
	movs r0, #0
_0811F1A6:
	cmp r0, #0
	beq _0811F1BA
	adds r0, r7, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811F1B8
	b _0811F8F6
_0811F1B8:
	b _0811F1C8
_0811F1BA:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _0811F208 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
_0811F1C8:
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _0811F204
	cmp r1, #0
	blt _0811F204
	ldr r0, _0811F20C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0811F204
	ldr r0, _0811F210 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811F214
_0811F204:
	movs r4, #0
	b _0811F222
	.align 2, 0
_0811F208: .4byte 0x03002BE0
_0811F20C: .4byte 0x030046A8
_0811F210: .4byte 0x030046AC
_0811F214:
	ldr r0, _0811F234 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0811F222:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811F238
	adds r0, #4
	b _0811F244
	.align 2, 0
_0811F234: .4byte 0x030046A4
_0811F238:
	ldr r0, _0811F258 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811F244:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811F25C
	cmp r2, #2
	beq _0811F260
	b _0811F264
	.align 2, 0
_0811F258: .4byte 0x030046A4
_0811F25C:
	ldrb r0, [r5, #4]
	b _0811F262
_0811F260:
	ldrb r0, [r5]
_0811F262:
	subs r1, r1, r0
_0811F264:
	strh r1, [r5, #2]
	ldr r0, _0811F278 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811F27C
	movs r0, #1
	b _0811F27E
	.align 2, 0
_0811F278: .4byte 0x030047A4
_0811F27C:
	movs r0, #0
_0811F27E:
	cmp r0, #0
	beq _0811F2BC
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0811F29E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811F29A
	adds r2, r0, #0
_0811F29A:
	cmp r2, #0
	bge _0811F2A8
_0811F29E:
	ldr r2, _0811F2A4 @ =0x000005C4
	adds r0, r7, r2
	b _0811F6FC
	.align 2, 0
_0811F2A4: .4byte 0x000005C4
_0811F2A8:
	ldr r1, _0811F2B8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811F304
	.align 2, 0
_0811F2B8: .4byte 0x03002BE0
_0811F2BC:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811F2E8
	cmp r1, #0
	blt _0811F2E8
	ldr r0, _0811F2EC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811F2E8
	ldr r0, _0811F2F0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811F2F4
_0811F2E8:
	movs r5, #0
	b _0811F302
	.align 2, 0
_0811F2EC: .4byte 0x030046A8
_0811F2F0: .4byte 0x030046AC
_0811F2F4:
	ldr r0, _0811F33C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811F302:
	movs r2, #0
_0811F304:
	ldr r4, _0811F340 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811F324
	ldr r1, _0811F344 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811F324
	b _0811F640
_0811F324:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0811F348
	movs r0, #0
	b _0811F712
	.align 2, 0
_0811F33C: .4byte 0x030046A4
_0811F340: .4byte 0x00000256
_0811F344: .4byte 0x03002BE0
_0811F348:
	ldr r0, _0811F3A4 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _0811F3A8
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x40]
	strb r2, [r3]
	ldr r6, [sp, #0x38]
	strb r5, [r6]
	ldr r3, [sp, #0x60]
	strb r0, [r3]
	ldr r6, [sp, #0x64]
	str r1, [r6]
	ldr r0, [sp, #0x20]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x2c]
	strb r5, [r1]
	ldr r3, [sp, #0x30]
	strb r5, [r3]
	ldr r5, [sp, #0x34]
	strb r0, [r5]
	ldr r6, [sp, #0x48]
	str r4, [r6]
	ldr r0, [sp, #0x3c]
	strb r2, [r0]
	b _0811F4F6
	.align 2, 0
_0811F3A4: .4byte 0x00000222
_0811F3A8:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x40]
	strb r0, [r2]
	ldr r4, [sp, #0x38]
	strb r5, [r4]
	ldr r2, [sp, #0x60]
	strb r0, [r2]
	ldr r4, [sp, #0x64]
	str r1, [r4]
	ldr r1, [sp, #0x20]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x2c]
	strb r5, [r2]
	ldr r4, [sp, #0x30]
	strb r5, [r4]
	ldr r5, [sp, #0x34]
	strb r1, [r5]
	ldr r1, [sp, #0x48]
	str r3, [r1]
	ldr r2, [sp, #0x3c]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811F40C
	cmp r1, #0
	blt _0811F40C
	ldr r0, _0811F410 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811F40C
	ldr r0, _0811F414 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811F418
_0811F40C:
	movs r4, #0
	b _0811F426
	.align 2, 0
_0811F410: .4byte 0x030046A8
_0811F414: .4byte 0x030046AC
_0811F418:
	ldr r0, _0811F438 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811F426:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811F43C
	adds r0, #4
	b _0811F448
	.align 2, 0
_0811F438: .4byte 0x030046A4
_0811F43C:
	ldr r0, _0811F45C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811F448:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811F460
	cmp r2, #2
	beq _0811F464
	b _0811F468
	.align 2, 0
_0811F45C: .4byte 0x030046A4
_0811F460:
	ldrb r0, [r5, #4]
	b _0811F466
_0811F464:
	ldrb r0, [r5]
_0811F466:
	subs r1, r1, r0
_0811F468:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811F490
	cmp r1, #0
	blt _0811F490
	ldr r0, _0811F494 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811F490
	ldr r0, _0811F498 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811F49C
_0811F490:
	movs r4, #0
	b _0811F4AA
	.align 2, 0
_0811F494: .4byte 0x030046A8
_0811F498: .4byte 0x030046AC
_0811F49C:
	ldr r0, _0811F4BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811F4AA:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811F4C0
	adds r0, #4
	b _0811F4CC
	.align 2, 0
_0811F4BC: .4byte 0x030046A4
_0811F4C0:
	ldr r0, _0811F4E0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811F4CC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811F4E4
	cmp r3, #2
	beq _0811F4E8
	b _0811F4EC
	.align 2, 0
_0811F4E0: .4byte 0x030046A4
_0811F4E4:
	ldrb r0, [r5, #4]
	b _0811F4EA
_0811F4E8:
	ldrb r0, [r5]
_0811F4EA:
	subs r2, r2, r0
_0811F4EC:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_0811F4F6:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	ldr r6, _0811F520 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x44]
	cmp r0, #0
	bne _0811F604
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0811F524
	movs r0, #1
	b _0811F526
	.align 2, 0
_0811F520: .4byte 0x00000482
_0811F524:
	movs r0, #0
_0811F526:
	ldr r3, _0811F614 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x44]
	cmp r0, #0
	bne _0811F604
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _0811F618 @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _0811F61C @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x54]
	ldr r1, _0811F620 @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r2, _0811F624 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	ldr r4, _0811F628 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	ldr r5, _0811F62C @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x28]
	ldr r6, _0811F630 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x50]
	ldr r6, _0811F634 @ =0x0203B400
	ldr r1, _0811F638 @ =0x030046B8
	ldr r5, _0811F63C @ =0x000003FF
	movs r2, #3
	mov r4, r8
_0811F576:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _0811F594
	adds r3, #1
	cmp r3, #3
	ble _0811F576
	mov r0, r8
_0811F594:
	movs r3, #0
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x64]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x60]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0x2c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x54]
	strb r0, [r2]
	ldr r4, [sp, #0x30]
	ldrb r0, [r4]
	ldr r5, [sp, #0x58]
	strb r0, [r5]
	ldr r6, [sp, #0x34]
	ldrb r0, [r6]
	ldr r1, [sp, #0x5c]
	strb r0, [r1]
	mov r2, sp
	ldrb r4, [r2, #0x1c]
	ldr r2, [sp, #0x4c]
	strb r4, [r2]
	ldr r5, [sp, #0x28]
	ldr r2, [r5]
	movs r0, #0x1b
	movs r1, #1
	ldr r6, [sp, #0x40]
	strb r1, [r6]
	ldr r4, [sp, #0x38]
	strb r3, [r4]
	ldr r5, [sp, #0x60]
	strb r0, [r5]
	ldr r6, [sp, #0x64]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x20]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x2c]
	strb r0, [r4]
	ldr r5, [sp, #0x30]
	strb r1, [r5]
	ldr r6, [sp, #0x34]
	strb r2, [r6]
	ldr r0, [sp, #0x48]
	str r3, [r0]
	ldr r2, [sp, #0x3c]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x50]
	strb r0, [r3]
_0811F604:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x44]
	strh r0, [r4]
	movs r0, #0
	b _0811F712
	.align 2, 0
_0811F614: .4byte 0x00000482
_0811F618: .4byte 0x0000054F
_0811F61C: .4byte 0x0000054C
_0811F620: .4byte 0x0000054D
_0811F624: .4byte 0x0000054E
_0811F628: .4byte 0x00000541
_0811F62C: .4byte 0x000005BC
_0811F630: .4byte 0x00000542
_0811F634: .4byte 0x0203B400
_0811F638: .4byte 0x030046B8
_0811F63C: .4byte 0x000003FF
_0811F640:
	mov sb, sp
	ldr r6, _0811F67C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811F680
	adds r0, #4
	b _0811F68A
	.align 2, 0
_0811F67C: .4byte 0x030046A4
_0811F680:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811F68A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _0811F6C0 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _0811F6C8
	ldr r0, _0811F6C4 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811F6F2
	.align 2, 0
_0811F6C0: .4byte 0x000004A4
_0811F6C4: .4byte 0xFFFFFDFF
_0811F6C8:
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0811F6E8
	cmp r0, #2
	beq _0811F6E4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811F6E4:
	movs r0, #1
	b _0811F6F4
_0811F6E8:
	ldr r0, _0811F708 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0811F6F2:
	movs r0, #0
_0811F6F4:
	cmp r0, #0
	bne _0811F710
	ldr r4, _0811F70C @ =0x000005C4
	adds r0, r7, r4
_0811F6FC:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0811F712
	.align 2, 0
_0811F708: .4byte 0xFFFFFDFF
_0811F70C: .4byte 0x000005C4
_0811F710:
	movs r0, #1
_0811F712:
	cmp r0, #0
	bne _0811F718
	b _0811F8F6
_0811F718:
	ldr r5, _0811F724 @ =0x00000482
	adds r1, r7, r5
	movs r0, #2
	strh r0, [r1]
	b _0811F8F6
	.align 2, 0
_0811F724: .4byte 0x00000482
_0811F728:
	movs r5, #0x80
	lsls r5, r5, #2
	ands r2, r5
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r4, r7, r6
	cmp r2, #0
	beq _0811F780
	movs r1, #0x80
	lsls r1, r1, #0xe
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0811F770
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _0811F7FC @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	mov r1, sl
	ldrh r0, [r1]
	bics r0, r5
	strh r0, [r1]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r5, #0
	strb r5, [r0]
	adds r6, #0xa6
	adds r0, r7, r6
	strh r3, [r0]
	ldr r1, _0811F800 @ =0x00000202
	adds r0, r7, r1
	strh r3, [r0]
_0811F770:
	ldr r2, _0811F804 @ =0x000001DF
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
_0811F780:
	movs r1, #0x10
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r3, _0811F808 @ =0x00000482
	adds r1, r7, r3
	movs r4, #0
	movs r0, #1
	strh r0, [r1]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r5, #7
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _0811F80C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _0811F810 @ =0x00000552
	adds r0, r7, r3
	strb r5, [r0]
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811F7F8
	cmp r1, #0
	blt _0811F7F8
	ldr r0, _0811F814 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811F7F8
	ldr r0, _0811F818 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811F81C
_0811F7F8:
	movs r4, #0
	b _0811F82A
	.align 2, 0
_0811F7FC: .4byte 0xFEFFFFFF
_0811F800: .4byte 0x00000202
_0811F804: .4byte 0x000001DF
_0811F808: .4byte 0x00000482
_0811F80C: .4byte 0x00000551
_0811F810: .4byte 0x00000552
_0811F814: .4byte 0x030046A8
_0811F818: .4byte 0x030046AC
_0811F81C:
	ldr r0, _0811F83C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811F82A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811F840
	adds r0, #4
	b _0811F84C
	.align 2, 0
_0811F83C: .4byte 0x030046A4
_0811F840:
	ldr r0, _0811F860 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811F84C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811F864
	cmp r2, #2
	beq _0811F868
	b _0811F86C
	.align 2, 0
_0811F860: .4byte 0x030046A4
_0811F864:
	ldrb r0, [r5, #4]
	b _0811F86A
_0811F868:
	ldrb r0, [r5]
_0811F86A:
	subs r1, r1, r0
_0811F86C:
	strh r1, [r5, #2]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r2, r7, r5
	ldr r1, [r2]
	movs r0, #1
	strh r0, [r1, #6]
	ldr r6, _0811F89C @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	ldr r5, [r2]
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	adds r2, r5, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0811F8A4
	ldr r0, _0811F8A0 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811F8CE
	.align 2, 0
_0811F89C: .4byte 0x000004A4
_0811F8A0: .4byte 0xFFFFFDFF
_0811F8A4:
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0811F8C4
	cmp r0, #2
	beq _0811F8C0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811F8C0:
	movs r0, #1
	b _0811F8D0
_0811F8C4:
	ldr r0, _0811F8E4 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0811F8CE:
	movs r0, #0
_0811F8D0:
	cmp r0, #0
	bne _0811F8F6
	ldr r4, _0811F8E8 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0811F8F6
	.align 2, 0
_0811F8E4: .4byte 0xFFFFFDFF
_0811F8E8: .4byte 0x000005C4

	thumb_func_start FUN_0811f8ec
FUN_0811f8ec: @ 0x0811F8EC
	ldr r5, _0811F908 @ =0x00000484
	adds r1, r7, r5
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0811F8F6:
	add sp, #0x68
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811F908: .4byte 0x00000484

	thumb_func_start FUN_0811f90c
FUN_0811f90c: @ 0x0811F90C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	adds r5, r4, #0
	ldr r7, _0811F980 @ =0x0000046C
	adds r1, r4, r7
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811F928
	movs r0, #0
	strb r0, [r1]
_0811F928:
	adds r0, r4, #0
	bl FUN_08116058
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0811F97A
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	strb r0, [r5, #5]
	ldr r7, _0811F984 @ =0x00000484
	adds r5, r4, r7
	ldr r0, [r5]
	cmp r0, #0x77
	ble _0811F974
	movs r1, #2
	movs r2, #5
	subs r7, #0x1c
	adds r0, r4, r7
	strb r3, [r0]
	adds r7, #1
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _0811F988 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	adds r7, #0x1b
	adds r0, r4, r7
	str r3, [r0]
	ldr r0, _0811F980 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0811F98C @ =0x000006BC
	adds r0, r6, r1
	strh r3, [r0]
_0811F974:
	ldr r0, [r5]
	adds r0, #1
	str r0, [r5]
_0811F97A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811F980: .4byte 0x0000046C
_0811F984: .4byte 0x00000484
_0811F988: .4byte 0x0000046A
_0811F98C: .4byte 0x000006BC

	thumb_func_start FUN_0811f990
FUN_0811f990: @ 0x0811F990
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	adds r5, r6, #0
	ldr r2, _0811F9B0 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811F9B4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811F9B6
	.align 2, 0
_0811F9B0: .4byte 0x0000046C
_0811F9B4:
	movs r0, #0
_0811F9B6:
	cmp r0, #0
	beq _0811FA00
	ldr r4, _0811FA88 @ =FUN_081186a4
	movs r3, #0x28
	ldr r0, _0811FA8C @ =0x0000046D
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0811FA90 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	movs r1, #0
	strh r2, [r0]
	ldr r2, _0811FA90 @ =0x0000046B
	adds r0, r6, r2
	strb r1, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	strb r0, [r5, #5]
	ldr r4, _0811FA94 @ =0x000006B6
	adds r1, r7, r4
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r1]
_0811FA00:
	ldr r0, _0811FA98 @ =0x00000484
	adds r2, r6, r0
	ldr r1, [r2]
	cmp r1, #0x1e
	bgt _0811FA14
	ldr r3, _0811FA90 @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0811FAAC
_0811FA14:
	movs r4, #0xcd
	lsls r4, r4, #3
	adds r2, r7, r4
	ldrh r0, [r2]
	cmp r0, #0
	beq _0811FA36
	movs r7, #0xea
	lsls r7, r7, #1
	adds r1, r6, r7
	str r0, [r1]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
_0811FA36:
	ldr r2, _0811FA9C @ =FUN_08117dc0
	movs r1, #0x26
	ldr r3, _0811FA8C @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _0811FA90 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _0811FAA0 @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #3
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0811FAA4 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _0811FAA8 @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _0811FA98 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _0811FAB0
	.align 2, 0
_0811FA88: .4byte FUN_081186a4
_0811FA8C: .4byte 0x0000046D
_0811FA90: .4byte 0x0000046B
_0811FA94: .4byte 0x000006B6
_0811FA98: .4byte 0x00000484
_0811FA9C: .4byte FUN_08117dc0
_0811FAA0: .4byte 0x00000553
_0811FAA4: .4byte 0x00000469
_0811FAA8: .4byte 0x0000046A
_0811FAAC:
	adds r0, r1, #1
	str r0, [r2]
_0811FAB0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0811fab8
FUN_0811fab8: @ 0x0811FAB8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0811FAD8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811FADC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811FADE
	.align 2, 0
_0811FAD8: .4byte 0x0000046C
_0811FADC:
	movs r0, #0
_0811FADE:
	cmp r0, #0
	beq _0811FB24
	ldr r4, _0811FBA4 @ =FUN_081189c0
	movs r3, #0x29
	ldr r0, _0811FBA8 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0811FBAC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r2, [r0]
	ldr r2, _0811FBAC @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0811FB24:
	adds r0, r5, #0
	bl FUN_08116058
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0811FBC6
	ldr r1, _0811FBAC @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0811FBBC
	movs r3, #0xda
	lsls r3, r3, #3
	adds r2, r6, r3
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r6, #0
	bl FUN_081155c4
	ldr r2, _0811FBB0 @ =FUN_08117b94
	movs r1, #0x22
	ldr r3, _0811FBA8 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _0811FBAC @ =0x0000046B
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r4, [r0]
	movs r2, #2
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0811FBB4 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _0811FBB8 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r4, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r3, [r0]
	b _0811FBC6
	.align 2, 0
_0811FBA4: .4byte FUN_081189c0
_0811FBA8: .4byte 0x0000046D
_0811FBAC: .4byte 0x0000046B
_0811FBB0: .4byte FUN_08117b94
_0811FBB4: .4byte 0x00000469
_0811FBB8: .4byte 0x0000046A
_0811FBBC:
	ldr r2, _0811FBCC @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0811FBC6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0811FBCC: .4byte 0x00000484

	thumb_func_start FUN_0811fbd0
FUN_0811fbd0: @ 0x0811FBD0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _0811FBF8 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811FBFC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811FBFE
	.align 2, 0
_0811FBF8: .4byte 0x0000046C
_0811FBFC:
	movs r0, #0
_0811FBFE:
	cmp r0, #0
	beq _0811FC0A
	ldr r3, _0811FC3C @ =0x0000046B
	adds r1, r6, r3
	movs r0, #0
	strb r0, [r1]
_0811FC0A:
	adds r0, r6, #0
	bl FUN_08116058
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811FC18
	b _08120186
_0811FC18:
	ldr r4, _0811FC3C @ =0x0000046B
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0811FC24
	b _0812017C
_0811FC24:
	adds r3, r7, #0
	ldr r0, _0811FC40 @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #7
	ands r1, r2
	adds r4, r0, #0
	cmp r1, #0
	beq _0811FC44
	movs r0, #1
	b _0811FC46
	.align 2, 0
_0811FC3C: .4byte 0x0000046B
_0811FC40: .4byte 0x030047A4
_0811FC44:
	movs r0, #0
_0811FC46:
	cmp r0, #0
	beq _0811FC74
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0811FC84
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811FC62
	adds r2, r0, #0
_0811FC62:
	cmp r2, #0
	blt _0811FC84
	ldr r1, _0811FC70 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	b _0811FC76
	.align 2, 0
_0811FC70: .4byte 0x03002BE0
_0811FC74:
	ldr r0, _0811FCDC @ =0x03002BE0
_0811FC76:
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811FCC2
_0811FC84:
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0811FCC2
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xf
	subs r0, r0, r1
	cmp r0, #0
	bge _0811FCA8
	movs r0, #0
_0811FCA8:
	ldr r2, _0811FCE0 @ =0x000006BC
	adds r1, r7, r2
	asrs r0, r0, #0x10
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xc8
	lsls r2, r2, #1
	cmp r0, r2
	bls _0811FCC2
	strh r2, [r1]
_0811FCC2:
	ldr r0, _0811FCE4 @ =0x000006B4
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0x1e
	strh r0, [r1]
	ldr r0, [r4]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811FCE8
	movs r0, #1
	b _0811FCEA
	.align 2, 0
_0811FCDC: .4byte 0x03002BE0
_0811FCE0: .4byte 0x000006BC
_0811FCE4: .4byte 0x000006B4
_0811FCE8:
	movs r0, #0
_0811FCEA:
	adds r5, r0, #0
	cmp r5, #0
	beq _0811FD68
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0811FDE4
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811FD08
	adds r2, r0, #0
_0811FD08:
	cmp r2, #0
	blt _0811FDE4
	ldr r1, _0811FD54 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0811FDE4
	ldr r2, _0811FD58 @ =FUN_08117dc0
	movs r1, #0x26
	ldr r3, _0811FD5C @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _0811FD60 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _0811FD64 @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #3
	b _0811FF90
	.align 2, 0
_0811FD54: .4byte 0x03002BE0
_0811FD58: .4byte FUN_08117dc0
_0811FD5C: .4byte 0x0000046D
_0811FD60: .4byte 0x0000046B
_0811FD64: .4byte 0x00000553
_0811FD68:
	ldr r0, _0811FDC8 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0811FDE4
	ldr r2, _0811FDCC @ =FUN_08117dc0
	movs r1, #0x26
	ldr r3, _0811FDD0 @ =0x0000046D
	adds r0, r6, r3
	movs r4, #1
	strb r4, [r0]
	ldr r7, _0811FDD4 @ =0x0000046B
	adds r0, r6, r7
	strb r5, [r0]
	adds r3, #0xe6
	adds r0, r6, r3
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r5, [r0]
	movs r2, #2
	movs r3, #3
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0811FDD8 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _0811FDDC @ =0x0000046A
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _0811FDE0 @ =0x00000484
	adds r0, r6, r3
	str r5, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r4, [r0]
	b _08120186
	.align 2, 0
_0811FDC8: .4byte 0x03002BE0
_0811FDCC: .4byte FUN_08117dc0
_0811FDD0: .4byte 0x0000046D
_0811FDD4: .4byte 0x0000046B
_0811FDD8: .4byte 0x00000469
_0811FDDC: .4byte 0x0000046A
_0811FDE0: .4byte 0x00000484
_0811FDE4:
	ldr r1, _0811FE1C @ =0x000006B4
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _0811FEE4
	adds r3, r7, #0
	adds r4, r7, #0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0811FEA0
	movs r2, #0
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0811FE28
	ldr r1, _0811FE20 @ =0x000006BC
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r0, _0811FE24 @ =0x0000018F
	cmp r1, r0
	bls _0811FE34
	b _0811FE38
	.align 2, 0
_0811FE1C: .4byte 0x000006B4
_0811FE20: .4byte 0x000006BC
_0811FE24: .4byte 0x0000018F
_0811FE28:
	ldr r1, _0811FE8C @ =0x000006BC
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0xc7
	bls _0811FE34
	movs r2, #1
_0811FE34:
	cmp r2, #0
	beq _0811FE6C
_0811FE38:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r7, #0xf6
	lsls r7, r7, #1
	adds r1, r3, r7
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0811FE6C
	adds r0, r4, #0
	adds r0, #8
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r1, [r1]
	adds r1, #8
	movs r2, #0xa
	movs r3, #0x80
	lsls r3, r3, #1
	bl FUN_082340c8
	lsls r0, r0, #0x18
	movs r1, #1
	cmp r0, #0
	bne _0811FE6E
_0811FE6C:
	movs r1, #0
_0811FE6E:
	cmp r1, #0
	beq _0811FEA0
	ldr r2, _0811FE90 @ =FUN_081183d0
	movs r1, #0x27
	ldr r3, _0811FE94 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _0811FE98 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _0811FE9C @ =0x00000553
	b _0811FF76
	.align 2, 0
_0811FE8C: .4byte 0x000006BC
_0811FE90: .4byte FUN_081183d0
_0811FE94: .4byte 0x0000046D
_0811FE98: .4byte 0x0000046B
_0811FE9C: .4byte 0x00000553
_0811FEA0:
	ldr r2, _0811FED4 @ =FUN_08117dc0
	movs r1, #0x26
	ldr r3, _0811FED8 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _0811FEDC @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _0811FEE0 @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #3
	b _0811FF90
	.align 2, 0
_0811FED4: .4byte FUN_08117dc0
_0811FED8: .4byte 0x0000046D
_0811FEDC: .4byte 0x0000046B
_0811FEE0: .4byte 0x00000553
_0811FEE4:
	adds r3, r7, #0
	adds r4, r7, #0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0811FFCC
	movs r2, #0
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0811FF18
	ldr r1, _0811FF10 @ =0x000006BC
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r0, _0811FF14 @ =0x0000018F
	cmp r1, r0
	bls _0811FF24
	b _0811FF28
	.align 2, 0
_0811FF10: .4byte 0x000006BC
_0811FF14: .4byte 0x0000018F
_0811FF18:
	ldr r1, _0811FFB0 @ =0x000006BC
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0xc7
	bls _0811FF24
	movs r2, #1
_0811FF24:
	cmp r2, #0
	beq _0811FF5A
_0811FF28:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r3, r2
	adds r2, #8
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0811FF5A
	adds r0, r4, #0
	adds r0, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r1, [r1]
	adds r1, #8
	movs r2, #0xa
	movs r3, #0x80
	lsls r3, r3, #1
	bl FUN_082340c8
	lsls r0, r0, #0x18
	movs r1, #1
	cmp r0, #0
	bne _0811FF5C
_0811FF5A:
	movs r1, #0
_0811FF5C:
	cmp r1, #0
	beq _0811FFCC
	ldr r2, _0811FFB4 @ =FUN_081183d0
	movs r1, #0x27
	ldr r7, _0811FFB8 @ =0x0000046D
	adds r0, r6, r7
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _0811FFBC @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	adds r7, #0xe6
_0811FF76:
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #4
_0811FF90:
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0811FFC0 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _0811FFC4 @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _0811FFC8 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _08120186
	.align 2, 0
_0811FFB0: .4byte 0x000006BC
_0811FFB4: .4byte FUN_081183d0
_0811FFB8: .4byte 0x0000046D
_0811FFBC: .4byte 0x0000046B
_0811FFC0: .4byte 0x00000469
_0811FFC4: .4byte 0x0000046A
_0811FFC8: .4byte 0x00000484
_0811FFCC:
	ldr r1, _08120014 @ =0x00000256
	adds r0, r6, r1
	ldrh r5, [r0]
	mov sl, sp
	ldr r2, _08120018 @ =0x030046A4
	mov r8, r2
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812001C
	adds r0, #4
	b _08120028
	.align 2, 0
_08120014: .4byte 0x00000256
_08120018: .4byte 0x030046A4
_0812001C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08120028:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r4, #0
	mov r8, r4
	mov r1, sl
	strh r0, [r1, #2]
	mov r2, sb
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	mov r5, sp
	mov r0, sp
	bl FUN_081155a0
	add r3, sp, #8
	adds r4, r6, #0
	adds r4, #8
	ldrh r0, [r6, #8]
	mov r1, sp
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _081200B4 @ =0x00000FFF
	cmp r1, r0
	bgt _081200C8
	adds r0, r7, #0
	bl FUN_081155c4
	movs r1, #2
	movs r2, #6
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	mov r4, r8
	strb r4, [r0]
	ldr r7, _081200B8 @ =0x00000469
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081200BC @ =0x0000046A
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081200C0 @ =0x00000484
	adds r0, r6, r2
	movs r3, #0
	str r3, [r0]
	ldr r4, _081200C4 @ =0x0000046C
	adds r1, r6, r4
	movs r0, #1
	strb r0, [r1]
	b _08120186
	.align 2, 0
_081200B4: .4byte 0x00000FFF
_081200B8: .4byte 0x00000469
_081200BC: .4byte 0x0000046A
_081200C0: .4byte 0x00000484
_081200C4: .4byte 0x0000046C
_081200C8:
	ldr r1, _08120160 @ =0x000004A4
	adds r0, r6, r1
	ldr r2, [r0]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r5, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r2, #0
	ldrsh r0, [r3, r2]
	movs r4, #4
	ldrsh r1, [r3, r4]
	bl FUN_0823785c
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r6, #5]
	ldr r2, _08120164 @ =0x000006C2
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _08120168 @ =FUN_08117b94
	movs r1, #0x22
	ldr r4, _0812016C @ =0x0000046D
	adds r0, r6, r4
	movs r2, #1
	strb r2, [r0]
	ldr r7, _08120170 @ =0x0000046B
	adds r0, r6, r7
	mov r4, r8
	strb r4, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r4, #0
	strh r4, [r0]
	movs r1, #2
	subs r7, #0xeb
	adds r0, r6, r7
	mov r3, r8
	strb r3, [r0]
	ldr r4, _08120174 @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _08120178 @ =0x00000484
	adds r0, r6, r1
	movs r3, #0
	str r3, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r2, [r0]
	b _08120186
	.align 2, 0
_08120160: .4byte 0x000004A4
_08120164: .4byte 0x000006C2
_08120168: .4byte FUN_08117b94
_0812016C: .4byte 0x0000046D
_08120170: .4byte 0x0000046B
_08120174: .4byte 0x00000469
_08120178: .4byte 0x00000484
_0812017C:
	ldr r7, _08120198 @ =0x00000484
	adds r1, r6, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08120186:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08120198: .4byte 0x00000484

	thumb_func_start FUN_0812019c
FUN_0812019c: @ 0x0812019C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	adds r7, r0, #0
	ldr r0, _081201BC @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081201C0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081201C2
	.align 2, 0
_081201BC: .4byte 0x0000046C
_081201C0:
	movs r0, #0
_081201C2:
	cmp r0, #0
	beq _081201F6
	ldr r4, _08120284 @ =FUN_081177f0
	movs r3, #0x2b
	ldr r2, _08120288 @ =0x0000046D
	adds r1, r7, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r5, _0812028C @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _08120290 @ =0x00000553
	adds r0, r7, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	adds r0, r7, r5
	strb r1, [r0]
_081201F6:
	ldr r4, _0812028C @ =0x0000046B
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08120202
	b _0812088C
_08120202:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r3, _08120294 @ =FUN_080e6794
	movs r2, #0xe
	ldr r5, _08120288 @ =0x0000046D
	adds r5, r5, r7
	mov r8, r5
	movs r1, #0
	movs r0, #1
	strb r0, [r5]
	adds r6, r7, r4
	strb r1, [r6]
	ldr r0, _08120290 @ =0x00000553
	adds r5, r7, r0
	strb r2, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r4, r7, r2
	str r3, [r4]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r3, r7, r0
	movs r2, #0
	mov sb, r2
	strh r1, [r3]
	movs r1, #0x80
	subs r0, #0x48
	adds r2, r7, r0
	ldrh r0, [r2]
	ands r0, r1
	mov r1, r8
	str r1, [sp, #0x24]
	str r6, [sp, #0x1c]
	str r5, [sp, #0x48]
	str r4, [sp, #0x4c]
	str r3, [sp, #0x30]
	str r2, [sp, #0x14]
	cmp r0, #0
	beq _081202A0
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x78
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	ldr r6, _08120298 @ =0x00000554
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, sb
	strb r2, [r0]
	ldr r3, _0812029C @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #6
	adds r0, r7, r5
	b _081202CC
	.align 2, 0
_08120284: .4byte FUN_081177f0
_08120288: .4byte 0x0000046D
_0812028C: .4byte 0x0000046B
_08120290: .4byte 0x00000553
_08120294: .4byte FUN_080e6794
_08120298: .4byte 0x00000554
_0812029C: .4byte 0x00000551
_081202A0:
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x78
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _0812036C @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	subs r6, #0x50
	adds r0, r7, r6
	mov r1, sb
	strb r1, [r0]
	ldr r2, _08120370 @ =0x00000551
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _08120374 @ =0x00000552
	adds r0, r7, r3
_081202CC:
	strb r4, [r0]
	movs r2, #0x10
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r5, _08120378 @ =0x00000482
	adds r1, r7, r5
	movs r2, #0
	movs r3, #0
	movs r0, #2
	strh r0, [r1]
	movs r0, #3
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sb, r6
	strb r0, [r6]
	ldr r0, _0812037C @ =0x00000469
	adds r0, r0, r7
	mov r8, r0
	strb r1, [r0]
	ldr r4, _08120380 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x54]
	strb r2, [r4]
	ldr r6, _08120384 @ =0x00000484
	adds r5, r7, r6
	str r3, [r5]
	ldr r0, _08120388 @ =0x0000046C
	adds r3, r7, r0
	strb r1, [r3]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r4, r7, r1
	ldr r2, [r4]
	mov sl, r2
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	mov r6, sl
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x20]
	mov r0, sb
	str r0, [sp, #0xc]
	mov r3, r8
	str r3, [sp, #0x10]
	ldr r6, [sp, #0x54]
	str r6, [sp, #0x18]
	str r5, [sp, #0x2c]
	adds r6, r4, #0
	mov r8, r2
	mov r0, ip
	cmp r0, #0
	blt _08120366
	cmp r1, #0
	blt _08120366
	ldr r0, _0812038C @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _08120366
	ldr r0, _08120390 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08120394
_08120366:
	movs r4, #0
	b _081203A4
	.align 2, 0
_0812036C: .4byte 0x00000554
_08120370: .4byte 0x00000551
_08120374: .4byte 0x00000552
_08120378: .4byte 0x00000482
_0812037C: .4byte 0x00000469
_08120380: .4byte 0x0000046A
_08120384: .4byte 0x00000484
_08120388: .4byte 0x0000046C
_0812038C: .4byte 0x030046A8
_08120390: .4byte 0x030046AC
_08120394:
	ldr r0, _081203B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_081203A4:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081203B8
	adds r0, #4
	b _081203C4
	.align 2, 0
_081203B4: .4byte 0x030046A4
_081203B8:
	ldr r0, _081203D8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081203C4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081203DC
	cmp r2, #2
	beq _081203E2
	b _081203E8
	.align 2, 0
_081203D8: .4byte 0x030046A4
_081203DC:
	mov r2, sl
	ldrb r0, [r2, #4]
	b _081203E6
_081203E2:
	mov r3, sl
	ldrb r0, [r3]
_081203E6:
	subs r1, r1, r0
_081203E8:
	mov r4, sl
	strh r1, [r4, #2]
	ldr r0, _08120400 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08120404
	movs r0, #1
	b _08120406
	.align 2, 0
_08120400: .4byte 0x030047A4
_08120404:
	movs r0, #0
_08120406:
	cmp r0, #0
	beq _08120444
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _08120426
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08120422
	adds r2, r0, #0
_08120422:
	cmp r2, #0
	bge _08120430
_08120426:
	ldr r6, _0812042C @ =0x000005C4
	adds r0, r7, r6
	b _08120884
	.align 2, 0
_0812042C: .4byte 0x000005C4
_08120430:
	ldr r1, _08120440 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0812048C
	.align 2, 0
_08120440: .4byte 0x03002BE0
_08120444:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08120470
	cmp r1, #0
	blt _08120470
	ldr r0, _08120474 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08120470
	ldr r0, _08120478 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812047C
_08120470:
	movs r5, #0
	b _0812048A
	.align 2, 0
_08120474: .4byte 0x030046A8
_08120478: .4byte 0x030046AC
_0812047C:
	ldr r0, _0812051C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0812048A:
	movs r2, #0
_0812048C:
	ldr r3, _08120520 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081204AC
	ldr r1, _08120524 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081204AC
	b _081207C4
_081204AC:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x14]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081204C0
	b _0812088C
_081204C0:
	ldr r5, _08120528 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x14]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _0812052C
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x24]
	strb r2, [r3]
	ldr r6, [sp, #0x1c]
	strb r5, [r6]
	ldr r3, [sp, #0x48]
	strb r0, [r3]
	ldr r6, [sp, #0x4c]
	str r1, [r6]
	ldr r0, [sp, #0x30]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0xc]
	strb r5, [r1]
	ldr r3, [sp, #0x10]
	strb r5, [r3]
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	ldr r6, [sp, #0x2c]
	str r4, [r6]
	ldr r0, [sp, #0x20]
	strb r2, [r0]
	b _0812067A
	.align 2, 0
_0812051C: .4byte 0x030046A4
_08120520: .4byte 0x00000256
_08120524: .4byte 0x03002BE0
_08120528: .4byte 0x00000222
_0812052C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x24]
	strb r0, [r2]
	ldr r4, [sp, #0x1c]
	strb r5, [r4]
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	str r1, [r4]
	ldr r1, [sp, #0x30]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0xc]
	strb r5, [r2]
	ldr r4, [sp, #0x10]
	strb r5, [r4]
	ldr r5, [sp, #0x18]
	strb r1, [r5]
	ldr r1, [sp, #0x2c]
	str r3, [r1]
	ldr r2, [sp, #0x20]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08120590
	cmp r1, #0
	blt _08120590
	ldr r0, _08120594 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08120590
	ldr r0, _08120598 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812059C
_08120590:
	movs r4, #0
	b _081205AA
	.align 2, 0
_08120594: .4byte 0x030046A8
_08120598: .4byte 0x030046AC
_0812059C:
	ldr r0, _081205BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081205AA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081205C0
	adds r0, #4
	b _081205CC
	.align 2, 0
_081205BC: .4byte 0x030046A4
_081205C0:
	ldr r0, _081205E0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081205CC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081205E4
	cmp r2, #2
	beq _081205E8
	b _081205EC
	.align 2, 0
_081205E0: .4byte 0x030046A4
_081205E4:
	ldrb r0, [r5, #4]
	b _081205EA
_081205E8:
	ldrb r0, [r5]
_081205EA:
	subs r1, r1, r0
_081205EC:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08120614
	cmp r1, #0
	blt _08120614
	ldr r0, _08120618 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08120614
	ldr r0, _0812061C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08120620
_08120614:
	movs r4, #0
	b _0812062E
	.align 2, 0
_08120618: .4byte 0x030046A8
_0812061C: .4byte 0x030046AC
_08120620:
	ldr r0, _08120640 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0812062E:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08120644
	adds r0, #4
	b _08120650
	.align 2, 0
_08120640: .4byte 0x030046A4
_08120644:
	ldr r0, _08120664 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08120650:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08120668
	cmp r3, #2
	beq _0812066C
	b _08120670
	.align 2, 0
_08120664: .4byte 0x030046A4
_08120668:
	ldrb r0, [r5, #4]
	b _0812066E
_0812066C:
	ldrb r0, [r5]
_0812066E:
	subs r2, r2, r0
_08120670:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_0812067A:
	ldrb r4, [r7, #5]
	str r4, [sp, #8]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x14]
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	ldr r6, _081206A4 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x28]
	cmp r0, #0
	bne _08120788
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081206A8
	movs r0, #1
	b _081206AA
	.align 2, 0
_081206A4: .4byte 0x00000482
_081206A8:
	movs r0, #0
_081206AA:
	ldr r3, _08120798 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x28]
	cmp r0, #0
	bne _08120788
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _0812079C @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _081207A0 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	ldr r1, _081207A4 @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x40]
	ldr r2, _081207A8 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x44]
	ldr r4, _081207AC @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x34]
	ldr r5, _081207B0 @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x50]
	ldr r6, _081207B4 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x38]
	ldr r6, _081207B8 @ =0x0203B400
	ldr r1, _081207BC @ =0x030046B8
	ldr r5, _081207C0 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_081206FA:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _08120718
	adds r3, #1
	cmp r3, #3
	ble _081206FA
	mov r0, r8
_08120718:
	movs r3, #0
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x4c]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x48]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0xc]
	ldrb r0, [r1]
	ldr r2, [sp, #0x3c]
	strb r0, [r2]
	ldr r4, [sp, #0x10]
	ldrb r0, [r4]
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r6, [sp, #0x18]
	ldrb r0, [r6]
	ldr r1, [sp, #0x44]
	strb r0, [r1]
	mov r2, sp
	ldrb r4, [r2, #8]
	ldr r2, [sp, #0x34]
	strb r4, [r2]
	ldr r5, [sp, #0x50]
	ldr r2, [r5]
	movs r0, #0x1b
	movs r1, #1
	ldr r6, [sp, #0x24]
	strb r1, [r6]
	ldr r4, [sp, #0x1c]
	strb r3, [r4]
	ldr r5, [sp, #0x48]
	strb r0, [r5]
	ldr r6, [sp, #0x4c]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x30]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xc]
	strb r0, [r4]
	ldr r5, [sp, #0x10]
	strb r1, [r5]
	ldr r6, [sp, #0x18]
	strb r2, [r6]
	ldr r0, [sp, #0x2c]
	str r3, [r0]
	ldr r2, [sp, #0x20]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x38]
	strb r0, [r3]
_08120788:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x28]
	strh r0, [r4]
	b _0812088C
	.align 2, 0
_08120798: .4byte 0x00000482
_0812079C: .4byte 0x0000054F
_081207A0: .4byte 0x0000054C
_081207A4: .4byte 0x0000054D
_081207A8: .4byte 0x0000054E
_081207AC: .4byte 0x00000541
_081207B0: .4byte 0x000005BC
_081207B4: .4byte 0x00000542
_081207B8: .4byte 0x0203B400
_081207BC: .4byte 0x030046B8
_081207C0: .4byte 0x000003FF
_081207C4:
	mov sb, sp
	ldr r6, _08120800 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08120804
	adds r0, #4
	b _0812080E
	.align 2, 0
_08120800: .4byte 0x030046A4
_08120804:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0812080E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _08120848 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08120850
	ldr r0, _0812084C @ =0xFFFFFDFF
	ldr r2, [sp, #0x14]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0812087A
	.align 2, 0
_08120848: .4byte 0x000004A4
_0812084C: .4byte 0xFFFFFDFF
_08120850:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08120870
	cmp r0, #2
	beq _0812086C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812086C:
	movs r0, #1
	b _0812087C
_08120870:
	ldr r0, _0812089C @ =0xFFFFFDFF
	ldr r3, [sp, #0x14]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0812087A:
	movs r0, #0
_0812087C:
	cmp r0, #0
	bne _0812088C
	ldr r4, _081208A0 @ =0x000005C4
	adds r0, r7, r4
_08120884:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
_0812088C:
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812089C: .4byte 0xFFFFFDFF
_081208A0: .4byte 0x000005C4

	thumb_func_start FUN_081208a4
FUN_081208a4: @ 0x081208A4
	ldr r1, _081208B0 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _081208B4 @ =0x085AD614
	str r1, [r0]
	bx lr
	.align 2, 0
_081208B0: .4byte 0x0000063C
_081208B4: .4byte 0x085AD614

	thumb_func_start FUN_081208b8
FUN_081208b8: @ 0x081208B8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0811d8cc
	movs r1, #0x80
	lsls r1, r1, #6
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081208DC
	ldr r1, _0812090C @ =0x000004BE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081208FC
_081208DC:
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r2, _08120910 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
_081208FC:
	adds r0, r4, #0
	bl FUN_0811d928
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0812090C: .4byte 0x000004BE
_08120910: .4byte 0x0000062C

	thumb_func_start FUN_08120914
FUN_08120914: @ 0x08120914
	push {lr}
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start EnemyGolem_Destroy
EnemyGolem_Destroy: @ 0x08120920
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _08120938 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812093C
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _08120944
	.align 2, 0
_08120938: .4byte 0x0000025D
_0812093C:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_08120944:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _08120960 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _08120964
	movs r0, #1
	b _08120966
	.align 2, 0
_08120960: .4byte 0x00000474
_08120964:
	movs r0, #0
_08120966:
	cmp r0, #0
	beq _08120972
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_08120972:
	ldr r1, _081209CC @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _0812098A
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_0812098A:
	ldr r0, _081209D0 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _081209A2
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_081209A2:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081209BA
	adds r0, r4, #0
	bl FUN_08002a58
_081209BA:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081209D4
	movs r0, #1
	b _081209D6
	.align 2, 0
_081209CC: .4byte 0x0000044C
_081209D0: .4byte 0x0000044D
_081209D4:
	movs r0, #0
_081209D6:
	cmp r0, #0
	beq _081209E2
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_081209E2:
	adds r0, r4, #0
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_08236424
	adds r0, r4, #0
	bl FUN_080ec6fc
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EnemyGolem_Init
EnemyGolem_Init: @ 0x08120A00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1b0
	adds r7, r0, #0
	str r7, [sp, #0x24]
	ldr r1, _08120A88 @ =0x0000065C
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r2, _08120A8C @ =0x000001DF
	adds r1, r7, r2
	movs r0, #3
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_08115d58
	ldr r3, _08120A90 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08120A9C
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08120A94 @ =0x00005290
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _08120A98 @ =0x00001E38
	bl FUN_080e3804
	ldr r4, _08120A8C @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0xac]
	cmp r1, #0x11
	beq _08120A78
	cmp r1, #0x17
	bne _08120A7C
_08120A78:
	movs r0, #1
	strb r0, [r5, #7]
_08120A7C:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _08120B04
	.align 2, 0
_08120A88: .4byte 0x0000065C
_08120A8C: .4byte 0x000001DF
_08120A90: .4byte 0x0000025D
_08120A94: .4byte 0x00005290
_08120A98: .4byte 0x00001E38
_08120A9C:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r0, sp, #0x14
	mov r8, r0
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _08120B80 @ =0x05000002
	bl CpuSet
	ldr r0, _08120B84 @ =0x0000CB05
	ldr r1, _08120B88 @ =0x00005290
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl OpenSpriteSetFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r6, r8
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r0, _08120B8C @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _08120B90 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0xac]
_08120B04:
	str r7, [sp, #0x28]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0
	str r4, [r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r3, r3, r7
	mov r8, r3
	str r4, [r3]
	ldr r5, _08120B94 @ =0x0000046F
	adds r0, r7, r5
	strb r4, [r0]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0
	mov sl, r0
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, _08120B98 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _08120B80 @ =0x05000002
	bl CpuSet
	ldr r3, _08120B9C @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1ac]
	bl prepare_08231510
	mov r1, sb
	str r1, [sp, #0x5c]
	mov r3, r8
	str r3, [sp, #0x68]
	str r6, [sp, #0x4c]
	ldr r2, [sp, #0x1ac]
	adds r6, r2, #0
	cmp r0, #0
	bne _08120B70
	b _08120CD0
_08120B70:
	bl VM_GetPC
	cmp r0, #0
	beq _08120BA0
	bl Script_GetValue
	adds r1, r0, #0
	b _08120BA2
	.align 2, 0
_08120B80: .4byte 0x05000002
_08120B84: .4byte 0x0000CB05
_08120B88: .4byte 0x00005290
_08120B8C: .4byte 0x000004B7
_08120B90: .4byte 0x000001DF
_08120B94: .4byte 0x0000046F
_08120B98: .4byte 0x00000474
_08120B9C: .4byte 0x000004B6
_08120BA0:
	movs r1, #0
_08120BA2:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _08120BC8 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xc8]
	str r4, [sp, #0xd0]
	cmp r0, #0
	beq _08120BCC
	bl Script_GetValue
	adds r1, r0, #0
	b _08120BCE
	.align 2, 0
_08120BC8: .4byte 0x00000251
_08120BCC:
	movs r1, #0
_08120BCE:
	ldr r2, _08120C04 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _08120C08 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xc8]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xd4]
	cmp r0, #0
	beq _08120C0C
	bl Script_GetValue
	b _08120C10
	.align 2, 0
_08120C04: .4byte 0x00000252
_08120C08: .4byte 0x000004B4
_08120C0C:
	ldr r4, [sp, #0xc8]
	ldrb r0, [r4]
_08120C10:
	strb r0, [r6]
	ldr r5, [sp, #0xc8]
	ldrb r1, [r5]
	ldr r6, [sp, #0xd4]
	ldrb r2, [r6]
	add r0, sp, #0x1c
	bl FUN_08234f90
	add r0, sp, #0x1c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08120C48
	cmp r1, #0
	blt _08120C48
	ldr r0, _08120C4C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08120C48
	ldr r0, _08120C50 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08120C54
_08120C48:
	movs r1, #0
	b _08120C62
	.align 2, 0
_08120C4C: .4byte 0x030046A8
_08120C50: .4byte 0x030046AC
_08120C54:
	ldr r0, _08120C7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08120C62:
	ldr r2, _08120C80 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08120C84
	adds r0, #4
	b _08120C90
	.align 2, 0
_08120C7C: .4byte 0x030046A4
_08120C80: .4byte 0x00000256
_08120C84:
	ldr r0, _08120CA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08120C90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08120CA8
	cmp r2, #2
	beq _08120CAC
	b _08120CB0
	.align 2, 0
_08120CA4: .4byte 0x030046A4
_08120CA8:
	ldrb r0, [r4, #4]
	b _08120CAE
_08120CAC:
	ldrb r0, [r4]
_08120CAE:
	subs r1, r1, r0
_08120CB0:
	ldr r3, _08120CC8 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08120CCC @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _08120D10
	.align 2, 0
_08120CC8: .4byte 0x00000472
_08120CCC: .4byte 0x0000FFFF
_08120CD0:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _08120D34 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _08120D38 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08120D3C @ =0x000004B4
	adds r1, r7, r6
	adds r0, r1, r0
	mov r6, sl
	strb r6, [r0]
	ldrb r2, [r2]
	movs r0, #1
	eors r0, r2
	adds r1, r1, r0
	strb r6, [r1]
	movs r0, #0
	str r0, [sp, #0x2c]
	str r5, [sp, #0xc8]
	str r4, [sp, #0xd0]
	str r3, [sp, #0xd4]
_08120D10:
	movs r0, #0x4e
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _08120D5A
	bl VM_GetPC
	cmp r0, #0
	beq _08120D40
	bl Script_GetValue
	adds r4, r0, #0
	b _08120D42
	.align 2, 0
_08120D34: .4byte 0x00000251
_08120D38: .4byte 0x00000252
_08120D3C: .4byte 0x000004B4
_08120D40:
	movs r4, #0x30
_08120D42:
	bl VM_GetPC
	cmp r0, #0
	beq _08120D54
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _08120D56
_08120D54:
	movs r5, #0x40
_08120D56:
	mov r8, r4
	b _08120D60
_08120D5A:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08120D60:
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08120D98
	bl VM_GetPC
	cmp r0, #0
	beq _08120D7A
	bl Script_GetValue
	adds r6, r0, #0
	b _08120D7C
_08120D7A:
	movs r6, #0
_08120D7C:
	bl VM_GetPC
	cmp r0, #0
	beq _08120D8C
	bl Script_GetValue
	adds r1, r0, #0
	b _08120D8E
_08120D8C:
	movs r1, #0
_08120D8E:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08120DA2
_08120D98:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08120DA2:
	movs r0, #0x61
	bl prepare_08231510
	ldr r1, _08121030 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x7c]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x78]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xd8]
	lsls r4, r4, #0x10
	str r4, [sp, #0xa0]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xa8]
	lsls r6, r6, #0x10
	str r6, [sp, #0xb0]
	lsls r5, r5, #0x10
	str r5, [sp, #0xa4]
	ldr r4, _08121034 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xe0]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x98]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x30]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xb4]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xb8]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x34]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x38]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x194]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x6c]
	ldr r1, _08121038 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r2, _0812103C @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x60]
	ldr r3, _08121040 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x64]
	ldr r4, _08121044 @ =0x00000476
	adds r4, r7, r4
	str r4, [sp, #0x50]
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x54]
	ldr r6, _08121048 @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x88]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x110]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x118]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x120]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x130]
	ldr r6, _0812104C @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0x134]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x148]
	ldr r2, _08121050 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0x14c]
	ldr r3, _08121054 @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0x154]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x158]
	ldr r5, _08121058 @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0x15c]
	ldr r6, _0812105C @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x164]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x150]
	ldr r2, _08121060 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0x114]
	ldr r3, _08121064 @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x188]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x18c]
	ldr r5, _08121068 @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0xbc]
	ldr r6, _0812106C @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x190]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x178]
	ldr r2, _08121070 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x16c]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	ldr r4, _08121074 @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x180]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x184]
	ldr r6, _08121078 @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x198]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x19c]
	ldr r2, _0812107C @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0x144]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x170]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x168]
	ldr r5, _08121080 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x174]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x160]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x138]
	ldr r2, _08121084 @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x1a0]
	ldr r3, _08121088 @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0x11c]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x1a4]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x140]
	ldr r6, _0812108C @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0x124]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x128]
	ldr r2, _08121090 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0x12c]
	ldr r3, _08121094 @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0x13c]
	ldr r4, _08121098 @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0xc0]
	adds r5, r7, #0
	adds r5, #0xd8
	str r5, [sp, #0x3c]
	movs r6, #0xcc
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x80]
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x84]
	ldr r2, _0812109C @ =0x00000496
	adds r2, r7, r2
	str r2, [sp, #0x74]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x40]
	ldr r4, _081210A0 @ =0x00000469
	adds r4, r7, r4
	str r4, [sp, #0x44]
	ldr r5, _081210A4 @ =0x0000046A
	adds r5, r7, r5
	str r5, [sp, #0x48]
	ldr r6, _081210A8 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0xcc]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x10c]
	movs r2, #0x92
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x70]
	movs r3, #0xea
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x94]
	ldr r5, _081210AC @ =0x00000572
	adds r5, r7, r5
	str r5, [sp, #0x108]
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x90]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x104]
	ldr r2, _081210B0 @ =0x0000055C
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	movs r3, #0xac
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xe8]
	ldr r4, _081210B4 @ =0x00000564
	adds r4, r7, r4
	str r4, [sp, #0xec]
	ldr r5, _081210B8 @ =0x00000565
	adds r5, r7, r5
	str r5, [sp, #0xf0]
	ldr r6, _081210BC @ =0x00000566
	adds r6, r7, r6
	str r6, [sp, #0xf4]
	ldr r1, _081210C0 @ =0x00000567
	adds r1, r7, r1
	str r1, [sp, #0xf8]
	movs r2, #0xad
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xfc]
	ldr r3, _081210C4 @ =0x0000056C
	adds r3, r7, r3
	str r3, [sp, #0x100]
	cmp r0, #0
	bne _08121000
	b _08121120
_08121000:
	movs r4, #0
	mov sl, r4
	movs r5, #0x8d
	lsls r5, r5, #2
	adds r5, r5, r7
	mov sb, r5
	movs r6, #0x8f
	lsls r6, r6, #2
	adds r6, r6, r7
	mov r8, r6
	movs r0, #0x8b
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r1, #0x89
	lsls r1, r1, #2
	adds r4, r7, r1
_08121020:
	bl VM_GetPC
	cmp r0, #0
	beq _081210C8
	bl Script_GetValue
	b _081210CA
	.align 2, 0
_08121030: .4byte 0x0000025D
_08121034: .4byte 0x0000025A
_08121038: .4byte 0x0000047A
_0812103C: .4byte 0x0000047C
_08121040: .4byte 0x0000047E
_08121044: .4byte 0x00000476
_08121048: .4byte 0x000004A4
_0812104C: .4byte 0x000005A4
_08121050: .4byte 0x000005C4
_08121054: .4byte 0x000005CC
_08121058: .4byte 0x000005D4
_0812105C: .4byte 0x000005DC
_08121060: .4byte 0x00000584
_08121064: .4byte 0x00000604
_08121068: .4byte 0x0000021D
_0812106C: .4byte 0x0000060C
_08121070: .4byte 0x000005E4
_08121074: .4byte 0x000005FC
_08121078: .4byte 0x00000614
_0812107C: .4byte 0x000005BC
_08121080: .4byte 0x000005EC
_08121084: .4byte 0x00000624
_08121088: .4byte 0x0000058C
_0812108C: .4byte 0x00000594
_08121090: .4byte 0x0000059C
_08121094: .4byte 0x000005B4
_08121098: .4byte 0x00000543
_0812109C: .4byte 0x00000496
_081210A0: .4byte 0x00000469
_081210A4: .4byte 0x0000046A
_081210A8: .4byte 0x00000553
_081210AC: .4byte 0x00000572
_081210B0: .4byte 0x0000055C
_081210B4: .4byte 0x00000564
_081210B8: .4byte 0x00000565
_081210BC: .4byte 0x00000566
_081210C0: .4byte 0x00000567
_081210C4: .4byte 0x0000056C
_081210C8:
	movs r0, #0x18
_081210CA:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081210DC
	bl Script_GetValue
	b _081210DE
_081210DC:
	movs r0, #0x18
_081210DE:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081210F0
	bl Script_GetValue
	b _081210F2
_081210F0:
	movs r0, #0
_081210F2:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08121104
	bl Script_GetValue
	b _08121106
_08121104:
	movs r0, #0
_08121106:
	strh r0, [r6]
	movs r2, #2
	add sb, r2
	movs r3, #4
	add r8, r3
	adds r5, #2
	adds r4, #2
	movs r6, #1
	add sl, r6
	mov r0, sl
	cmp r0, #3
	bgt _08121120
	b _08121020
_08121120:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _0812116C
	bl VM_GetPC
	cmp r0, #0
	beq _0812113A
	bl Script_GetValue
	adds r4, r0, #0
	b _0812113E
_0812113A:
	movs r4, #0x96
	lsls r4, r4, #1
_0812113E:
	bl VM_GetPC
	cmp r0, #0
	beq _0812114E
	bl Script_GetValue
	adds r6, r0, #0
	b _08121152
_0812114E:
	movs r6, #0x96
	lsls r6, r6, #1
_08121152:
	bl VM_GetPC
	cmp r0, #0
	beq _08121160
	bl Script_GetValue
	b _08121166
_08121160:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_08121166:
	ldr r2, [sp, #0xc4]
	strh r0, [r2]
	b _08121174
_0812116C:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0xc4]
	strh r6, [r3]
_08121174:
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _0812118C
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x68]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0812118C:
	movs r0, #0x46
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0x7c]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, [sp, #0x78]
	strh r0, [r2]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _0812125C
	bl VM_GetPC
	cmp r0, #0
	beq _081211BC
	bl Script_GetValue
	b _081211BE
_081211BC:
	movs r0, #0
_081211BE:
	ldr r3, [sp, #0xd8]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _081211CC
	asrs r1, r0, #1
	b _081211D2
_081211CC:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081211D2:
	ldr r5, _081211E8 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081211EC
	bl Script_GetValue
	b _081211EE
	.align 2, 0
_081211E8: .4byte 0x00000546
_081211EC:
	movs r0, #0
_081211EE:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08121204
	bl Script_GetValue
	b _08121206
_08121204:
	movs r0, #0
_08121206:
	ldr r3, _0812121C @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08121220
	bl Script_GetValue
	adds r1, r0, #0
	b _08121222
	.align 2, 0
_0812121C: .4byte 0x00000187
_08121220:
	movs r1, #0
_08121222:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08121238
	bl Script_GetValue
	b _0812123A
_08121238:
	movs r0, #0
_0812123A:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08121252
	bl Script_GetValue
	adds r1, r0, #0
	b _08121254
_08121252:
	movs r1, #0
_08121254:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_0812125C:
	ldr r5, [sp, #0xd8]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r6, [sp, #0xa0]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0xa8]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0xb0]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0xa4]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl prepare_08231510
	cmp r0, #0
	beq _081212BE
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _081212A4
	bl Script_GetValue
	b _081212A6
_081212A4:
	movs r0, #0
_081212A6:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _081212B6
	bl Script_GetValue
	b _081212B8
_081212B6:
	movs r0, #0
_081212B8:
	ldr r6, _08121320 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_081212BE:
	movs r0, #0x4b
	movs r1, #2
	bl Script_GetKeywordValue
	ldr r1, [sp, #0xe0]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081212E2
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x68]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081212E2:
	movs r0, #0x4c
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081212FA
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x68]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081212FA:
	ldr r4, [sp, #0x98]
	lsrs r1, r4, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x28]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08121324
	movs r0, #1
	b _08121326
	.align 2, 0
_08121320: .4byte 0x00000189
_08121324:
	movs r0, #0
_08121326:
	cmp r0, #0
	beq _08121336
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08121360 @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_08121336:
	ldr r6, [sp, #0xe4]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _08121342
	ldr r1, [r7, #0x44]
_08121342:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r1, [sp, #0xac]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _08121364
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x30]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _08121370
	.align 2, 0
_08121360: .4byte FUN_080f48ac
_08121364:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x30]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_08121370:
	ldr r2, [sp, #0xac]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081213BE
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081213BE
	cmp r0, #0x16
	beq _081213BE
	cmp r0, #0x14
	beq _081213BE
	cmp r0, #9
	beq _081213BE
	cmp r0, #0x19
	beq _081213BE
	cmp r0, #0x1a
	beq _081213BE
	cmp r0, #0xd
	beq _081213BE
	cmp r0, #0x1b
	beq _081213BE
	cmp r0, #0x1f
	beq _081213BE
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0xc8]
	ldrb r2, [r3]
	ldr r4, [sp, #0xd0]
	ldrb r3, [r4]
	ldr r5, [sp, #0xd4]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl FUN_0823b490
_081213BE:
	movs r1, #8
	ldr r6, [sp, #0x4c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081213CE
	movs r0, #1
	b _081213D0
_081213CE:
	movs r0, #0
_081213D0:
	cmp r0, #0
	beq _081213DE
	ldr r1, [sp, #0xb8]
	ldr r0, [r1]
	ldr r2, [sp, #0xb4]
	str r0, [r2]
	b _081213F0
_081213DE:
	ldr r3, [sp, #0xb8]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0xb4]
	str r0, [r4]
_081213F0:
	ldrh r0, [r7]
	ldr r5, [sp, #0x34]
	strh r0, [r5]
	ldr r6, [sp, #0x194]
	ldr r0, [sp, #0x38]
	str r6, [r0]
	ldr r1, [sp, #0x2c]
	cmp r1, #0
	beq _0812141A
	adds r0, r7, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	lsrs r0, r0, #0xc
	movs r1, #7
	ands r0, r1
	adds r0, #5
	ands r0, r1
	lsls r0, r0, #5
	ldr r2, [sp, #0x28]
	strb r0, [r2, #5]
_0812141A:
	ldr r4, _08121454 @ =0x00000201
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x6c]
	strh r0, [r3]
	ldr r6, [sp, #0x58]
	strh r4, [r6]
	ldr r0, [sp, #0x60]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, r0, r4
	ldr r1, [sp, #0x64]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0xe4]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08121458
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _08121464
	.align 2, 0
_08121454: .4byte 0x00000201
_08121458:
	ldr r2, [r7, #0x44]
	ldr r0, _0812149C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08121464:
	ldr r3, [sp, #0xe4]
	ldrb r0, [r3]
	cmp r0, #1
	bne _081214B4
	ldr r4, [sp, #0xac]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081214A0
	movs r0, #5
	bl FUN_080ecf60
	adds r4, r0, #1
	movs r0, #6
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #7
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #8
	bl FUN_080ecf60
	adds r4, r4, r0
	b _081214AA
	.align 2, 0
_0812149C: .4byte 0x03003584
_081214A0:
	ldr r5, [sp, #0xac]
	ldrb r0, [r5]
	bl FUN_080ecf60
	adds r4, r0, #1
_081214AA:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081214B4:
	movs r4, #0
	ldr r6, [sp, #0x58]
	ldrh r0, [r6]
	adds r0, #2
	ldr r1, [sp, #0x50]
	strh r0, [r1]
	ldrh r0, [r6]
	ldr r2, [sp, #0x54]
	strh r0, [r2]
	adds r0, r7, #0
	bl FUN_0811613c
	ldr r3, [sp, #0x24]
	ldr r5, _08121670 @ =0x0000066C
	adds r0, r3, r5
	movs r6, #0xd2
	lsls r6, r6, #3
	adds r3, r3, r6
	mov r8, r3
	ldr r1, _08121674 @ =FUN_081208b8
	mov sb, r1
	ldr r2, _08121678 @ =FUN_08116088
	mov sl, r2
	ldr r3, _0812167C @ =FUN_08116d2c
	mov ip, r3
	ldr r5, _08121680 @ =FUN_08119a1c
	ldr r3, _08121684 @ =FUN_080f62b0
	ldr r6, _08121688 @ =FUN_080f62ac
	str r6, [sp, #0x1a8]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x5c]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x88]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x8c]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0x110]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0x118]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0x120]
	str r2, [r6]
	ldr r1, _0812168C @ =FUN_08116ce4
	ldr r2, [sp, #0x130]
	str r1, [r2]
	ldr r6, _08121690 @ =FUN_08116d08
	ldr r1, [sp, #0x134]
	str r6, [r1]
	ldr r2, _08121694 @ =FUN_081176c4
	ldr r6, [sp, #0x148]
	str r2, [r6]
	ldr r1, [sp, #0x14c]
	str r3, [r1]
	ldr r2, [sp, #0x154]
	str r5, [r2]
	ldr r3, _08121698 @ =FUN_0811aa68
	ldr r5, [sp, #0x158]
	str r3, [r5]
	ldr r1, _0812169C @ =FUN_080f44f4
	ldr r6, [sp, #0x15c]
	str r1, [r6]
	ldr r1, _081216A0 @ =FUN_080f410c
	ldr r2, [sp, #0x164]
	str r1, [r2]
	ldr r3, _081216A4 @ =FUN_08118fdc
	ldr r5, [sp, #0x150]
	str r3, [r5]
	ldr r6, _081216A8 @ =FUN_081173d8
	ldr r1, [sp, #0x114]
	str r6, [r1]
	ldr r2, [sp, #0x1a8]
	ldr r3, [sp, #0x188]
	str r2, [r3]
	ldr r1, _081216AC @ =FUN_080f0430
	ldr r5, [sp, #0x18c]
	str r1, [r5]
	movs r1, #1
	ldr r6, [sp, #0xbc]
	strb r1, [r6]
	ldr r1, _081216B0 @ =0x085AD470
	ldr r2, [sp, #0x190]
	str r1, [r2]
	ldr r1, _081216B4 @ =FUN_080e73c8
	ldr r3, [sp, #0x178]
	str r1, [r3]
	ldr r5, [sp, #0x16c]
	str r4, [r5]
	ldr r6, [sp, #0x17c]
	str r4, [r6]
	ldr r1, [sp, #0x180]
	str r4, [r1]
	ldr r2, [sp, #0x184]
	str r4, [r2]
	ldr r3, [sp, #0x198]
	str r4, [r3]
	ldr r1, _081216B8 @ =FUN_080f0320
	ldr r5, [sp, #0x19c]
	str r1, [r5]
	ldr r1, _081216BC @ =FUN_080eff14
	ldr r6, [sp, #0x144]
	str r1, [r6]
	ldr r1, _081216C0 @ =FUN_080e72b0
	ldr r2, [sp, #0x170]
	str r1, [r2]
	ldr r3, _081216C4 @ =FUN_0811aa64
	ldr r5, [sp, #0x168]
	str r3, [r5]
	ldr r1, _081216C8 @ =FUN_080f47c8
	ldr r6, [sp, #0x174]
	str r1, [r6]
	ldr r1, _081216CC @ =FUN_080f54e4
	ldr r2, [sp, #0x160]
	str r1, [r2]
	ldr r3, [sp, #0x138]
	str r4, [r3]
	ldr r1, _081216D0 @ =FUN_080f6e64
	ldr r5, [sp, #0x1a0]
	str r1, [r5]
	ldr r1, _081216D4 @ =FUN_080f64f0
	ldr r6, [sp, #0x11c]
	str r1, [r6]
	ldr r1, _081216D8 @ =FUN_080f84d4
	ldr r2, [sp, #0x1a4]
	str r1, [r2]
	ldr r1, _081216DC @ =FUN_080f624c
	ldr r3, [sp, #0x140]
	str r1, [r3]
	ldr r1, _081216E0 @ =FUN_080f56ec
	ldr r5, [sp, #0x124]
	str r1, [r5]
	ldr r1, _081216E4 @ =FUN_080f5b34
	ldr r6, [sp, #0x128]
	str r1, [r6]
	ldr r1, _081216E8 @ =FUN_080f5fac
	ldr r2, [sp, #0x12c]
	str r1, [r2]
	ldr r3, [sp, #0x13c]
	str r4, [r3]
	movs r1, #0x28
	ldr r5, [sp, #0xc0]
	strb r1, [r5]
	ldr r1, [sp, #0x194]
	bl FUN_082362fc
	adds r0, r7, #0
	bl FUN_080e6204
	movs r6, #0xbf
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _081216EC @ =FUN_08115dd8
	str r0, [r1]
	ldr r0, _081216F0 @ =0x000005FC
	adds r1, r7, r0
	ldr r0, _081216F4 @ =FUN_08115f78
	str r0, [r1]
	ldr r2, _081216F8 @ =0x000005AC
	adds r1, r7, r2
	ldr r0, _081216FC @ =FUN_0811579c
	str r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _08121700 @ =FUN_08115874
	str r0, [r1]
	ldr r5, _08121704 @ =0x0000058C
	adds r1, r7, r5
	ldr r0, _08121708 @ =FUN_0811ae30
	str r0, [r1]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r4, [r0]
	movs r1, #0xb8
	lsls r1, r1, #0x11
	ldr r2, [sp, #0x5c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r1, _0812170C @ =0x08000008
	ldr r3, [sp, #0x68]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ldr r4, [sp, #0x3c]
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r5, [sp, #0x80]
	strh r0, [r5]
	movs r0, #0x47
	bl prepare_08231510
	cmp r0, #0
	beq _0812171A
	subs r6, #0x20
	adds r5, r7, r6
	movs r4, #4
_08121660:
	bl VM_GetPC
	cmp r0, #0
	beq _08121710
	bl Script_GetValue
	b _08121712
	.align 2, 0
_08121670: .4byte 0x0000066C
_08121674: .4byte FUN_081208b8
_08121678: .4byte FUN_08116088
_0812167C: .4byte FUN_08116d2c
_08121680: .4byte FUN_08119a1c
_08121684: .4byte FUN_080f62b0
_08121688: .4byte FUN_080f62ac
_0812168C: .4byte FUN_08116ce4
_08121690: .4byte FUN_08116d08
_08121694: .4byte FUN_081176c4
_08121698: .4byte FUN_0811aa68
_0812169C: .4byte FUN_080f44f4
_081216A0: .4byte FUN_080f410c
_081216A4: .4byte FUN_08118fdc
_081216A8: .4byte FUN_081173d8
_081216AC: .4byte FUN_080f0430
_081216B0: .4byte 0x085AD470
_081216B4: .4byte FUN_080e73c8
_081216B8: .4byte FUN_080f0320
_081216BC: .4byte FUN_080eff14
_081216C0: .4byte FUN_080e72b0
_081216C4: .4byte FUN_0811aa64
_081216C8: .4byte FUN_080f47c8
_081216CC: .4byte FUN_080f54e4
_081216D0: .4byte FUN_080f6e64
_081216D4: .4byte FUN_080f64f0
_081216D8: .4byte FUN_080f84d4
_081216DC: .4byte FUN_080f624c
_081216E0: .4byte FUN_080f56ec
_081216E4: .4byte FUN_080f5b34
_081216E8: .4byte FUN_080f5fac
_081216EC: .4byte FUN_08115dd8
_081216F0: .4byte 0x000005FC
_081216F4: .4byte FUN_08115f78
_081216F8: .4byte 0x000005AC
_081216FC: .4byte FUN_0811579c
_08121700: .4byte FUN_08115874
_08121704: .4byte 0x0000058C
_08121708: .4byte FUN_0811ae30
_0812170C: .4byte 0x08000008
_08121710:
	movs r0, #0
_08121712:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08121660
_0812171A:
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0x84]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x74]
	strh r0, [r3]
	cmp r2, #0
	beq _08121752
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x5c]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _08121752
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_08121752:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08121764
	movs r0, #1
	b _08121766
_08121764:
	movs r0, #0
_08121766:
	cmp r0, #0
	beq _08121778
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x68]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_08121778:
	cmp r2, #1
	beq _081217B8
	movs r1, #0
	ldr r0, [sp, #0x40]
	strb r1, [r0]
	ldr r2, [sp, #0x44]
	strb r1, [r2]
	ldr r3, [sp, #0x48]
	strb r1, [r3]
	ldr r4, _081217C8 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081217CC @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x134]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0xcc]
	strb r1, [r6]
	ldr r0, [sp, #0x10c]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081217B8:
	movs r1, #2
	ldr r3, [sp, #0x4c]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081217D0
	movs r0, #1
	b _081217D2
	.align 2, 0
_081217C8: .4byte 0x00000484
_081217CC: .4byte 0x0000046C
_081217D0:
	movs r0, #0
_081217D2:
	cmp r0, #0
	beq _081217EC
	ldr r0, _081217E8 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x70]
	strh r0, [r5]
	b _081217F6
	.align 2, 0
_081217E8: .4byte 0x030046A0
_081217EC:
	ldr r0, [sp, #0x194]
	bl FUN_08241574
	ldr r6, [sp, #0x70]
	strh r0, [r6]
_081217F6:
	movs r1, #0x40
	ldr r2, [sp, #0x4c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08121806
	movs r0, #1
	b _08121808
_08121806:
	movs r0, #0
_08121808:
	cmp r0, #0
	beq _08121816
	ldr r0, _0812183C @ =0xFFFFFEFF
	ldr r3, [sp, #0x3c]
	ldrh r1, [r3, #6]
	ands r0, r1
	strh r0, [r3, #6]
_08121816:
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _0812184A
	ldr r0, _08121840 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x70]
	ldrh r5, [r5]
	cmp r0, r5
	bne _08121844
	movs r0, #1
	b _08121846
	.align 2, 0
_0812183C: .4byte 0xFFFFFEFF
_08121840: .4byte 0x030046A0
_08121844:
	movs r0, #0
_08121846:
	cmp r0, #0
	bne _08121852
_0812184A:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_08121852:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r6, [sp, #0xe4]
	ldrb r0, [r6]
	cmp r0, #0
	bne _0812193A
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08121894
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0812189C
_08121894:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0812189C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081218C0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081218C8
_081218C0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081218C8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08121900 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08121944
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08121904
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081218F8
	ldrb r0, [r4, #5]
_081218F8:
	subs r0, #1
	strh r0, [r4, #8]
	b _08121914
	.align 2, 0
_08121900: .4byte 0x0000FFFF
_08121904:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r5, [r4, #5]
	cmp r0, r5
	blo _08121914
	strh r1, [r4, #8]
_08121914:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08121944
	movs r0, #1
	strb r0, [r4, #7]
	b _08121944
_0812193A:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_08121944:
	movs r0, #0
	ldr r6, [sp, #0x9c]
	str r0, [r6]
	ldr r0, _0812195C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08121960
	movs r0, #1
	b _08121962
	.align 2, 0
_0812195C: .4byte 0x030047A4
_08121960:
	movs r0, #0
_08121962:
	cmp r0, #0
	bne _081219A2
	ldr r0, [sp, #0xac]
	ldrb r1, [r0]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0812198A
	adds r0, r1, #0
	cmp r0, #7
	beq _0812198A
	cmp r0, #6
	beq _0812198A
	cmp r0, #0x15
	beq _0812198A
	cmp r0, #0x14
	beq _0812198A
	cmp r0, #0x17
	bne _081219A2
_0812198A:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r2, [sp, #0x4c]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081219A2:
	ldr r3, [sp, #0x94]
	ldr r0, [r3]
	movs r4, #0xcc
	lsls r4, r4, #3
	adds r0, r0, r4
	ldr r5, [sp, #0xb4]
	ldr r1, [r5]
	str r1, [r0]
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_0811d8bc
	adds r0, r7, #0
	bl FUN_081208a4
	ldr r6, [sp, #0x24]
	ldr r1, _08121A7C @ =0x000006C1
	adds r0, r6, r1
	movs r2, #0
	strb r2, [r0]
	adds r4, #0x54
	adds r3, r6, r4
	movs r4, #0
	movs r0, #0x78
	strh r0, [r3]
	ldr r5, _08121A80 @ =0x000006BA
	adds r0, r6, r5
	strh r2, [r0]
	movs r0, #0xd7
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r0, #2
	strh r0, [r1]
	ldr r1, _08121A84 @ =0x000006B6
	adds r0, r6, r1
	strh r2, [r0]
	movs r0, #0xa0
	strh r0, [r3]
	ldr r3, _08121A88 @ =0x000006BE
	adds r0, r6, r3
	strh r2, [r0]
	subs r5, #0x62
	adds r0, r6, r5
	strb r4, [r0]
	adds r1, #0x11
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, [sp, #0x4c]
	ldrh r0, [r2]
	ldr r3, [sp, #0x108]
	strh r0, [r3]
	ldr r4, [sp, #0x90]
	ldrh r0, [r4]
	ldr r5, [sp, #0x104]
	strh r0, [r5]
	ldr r6, [sp, #0x5c]
	ldr r0, [r6]
	ldr r1, [sp, #0xdc]
	str r0, [r1]
	ldr r2, [sp, #0x68]
	ldr r0, [r2]
	ldr r3, [sp, #0xe8]
	str r0, [r3]
	ldrb r0, [r7, #5]
	ldr r4, [sp, #0xec]
	strb r0, [r4]
	ldr r5, [sp, #0x40]
	ldrb r0, [r5]
	ldr r6, [sp, #0xf0]
	strb r0, [r6]
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	ldr r2, [sp, #0xf4]
	strb r0, [r2]
	ldr r3, [sp, #0x48]
	ldrb r0, [r3]
	ldr r4, [sp, #0xf8]
	strb r0, [r4]
	ldr r5, [sp, #0x10c]
	ldr r0, [r5]
	ldr r6, [sp, #0xfc]
	str r0, [r6]
	ldr r1, [sp, #0xcc]
	ldrb r0, [r1]
	ldr r2, [sp, #0x100]
	strb r0, [r2]
	ldr r3, _08121A8C @ =0x0000057C
	adds r1, r7, r3
	ldr r0, _08121A90 @ =FUN_080f09e0
	str r0, [r1]
	ldr r4, _08121A94 @ =0x0000061C
	adds r1, r7, r4
	ldr r0, _08121A98 @ =FUN_08120914
	str r0, [r1]
	movs r5, #0xc4
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _08121A9C @ =EnemyGolem_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08121AA0
	movs r0, #0
	b _08121AA4
	.align 2, 0
_08121A7C: .4byte 0x000006C1
_08121A80: .4byte 0x000006BA
_08121A84: .4byte 0x000006B6
_08121A88: .4byte 0x000006BE
_08121A8C: .4byte 0x0000057C
_08121A90: .4byte FUN_080f09e0
_08121A94: .4byte 0x0000061C
_08121A98: .4byte FUN_08120914
_08121A9C: .4byte EnemyGolem_Destroy
_08121AA0:
	movs r0, #1
	rsbs r0, r0, #0
_08121AA4:
	add sp, #0x1b0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemyGolem_Create
EnemyGolem_Create: @ 0x08121AB4
	push {r4, r5, lr}
	ldr r5, _08121AE8 @ =0x000006E4
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _08121AE0
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyGolem_Init
	cmp r0, #0
	bge _08121AE0
	adds r0, r4, #0
	bl EnemyGolem_Destroy
	adds r0, r4, #0
	bl Free
_08121AE0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08121AE8: .4byte 0x000006E4

