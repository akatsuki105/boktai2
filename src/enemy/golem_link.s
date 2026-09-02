	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ 通信対戦用のゴーレム(ボムゴーレム)
@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_081b8438
FUN_081b8438: @ 0x081B8438
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
	bge _081B8464
	rsbs r0, r2, #0
_081B8464:
	cmp r0, ip
	bhi _081B84D8
	adds r0, r1, #0
	cmp r1, #0
	bge _081B8470
	rsbs r0, r1, #0
_081B8470:
	cmp r0, r3
	bhi _081B84D8
	adds r3, r2, #0
	cmp r2, #0
	bge _081B847C
	rsbs r3, r2, #0
_081B847C:
	adds r0, r1, #0
	cmp r1, #0
	bge _081B8484
	rsbs r0, r1, #0
_081B8484:
	cmp r3, r0
	ble _081B848C
	movs r1, #0
	b _081B848E
_081B848C:
	movs r2, #0
_081B848E:
	adds r0, r2, #0
	bl FUN_0823785c
	ldr r1, _081B84D0 @ =0x000006C2
	adds r2, r6, r1
	strb r0, [r2]
	ldr r3, _081B84D4 @ =0x085B0A08
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
	b _081B8550
	.align 2, 0
_081B84D0: .4byte 0x000006C2
_081B84D4: .4byte 0x085B0A08
_081B84D8:
	cmp r2, #0
	bne _081B84E0
	cmp r1, #0
	beq _081B854E
_081B84E0:
	adds r3, r2, #0
	cmp r2, #0
	bge _081B84E8
	rsbs r3, r2, #0
_081B84E8:
	adds r0, r1, #0
	cmp r1, #0
	bge _081B84F0
	rsbs r0, r1, #0
_081B84F0:
	cmp r3, r0
	ble _081B84F8
	movs r1, #0
	b _081B84FA
_081B84F8:
	movs r2, #0
_081B84FA:
	adds r0, r2, #0
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, _081B8518 @ =0x000006C2
	adds r5, r6, r0
	ldrb r1, [r5]
	cmp r3, r1
	beq _081B851C
	strb r3, [r4, #5]
	strb r3, [r5]
	movs r0, #1
	b _081B8550
	.align 2, 0
_081B8518: .4byte 0x000006C2
_081B851C:
	ldr r2, _081B8558 @ =0x085B0A08
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
_081B854E:
	movs r0, #0
_081B8550:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081B8558: .4byte 0x085B0A08

	thumb_func_start FUN_081b855c
FUN_081b855c: @ 0x081B855C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	mov r8, r1
	movs r7, #1
	rsbs r7, r7, #0
	cmp r2, #1
	beq _081B8588
	cmp r2, #1
	bgt _081B8578
	cmp r2, #0
	beq _081B8582
	b _081B85B0
_081B8578:
	cmp r2, #2
	beq _081B859C
	cmp r2, #3
	beq _081B85A2
	b _081B85B0
_081B8582:
	adds r4, #1
	movs r7, #2
	b _081B85B0
_081B8588:
	ldr r0, _081B8598 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	b _081B85AE
	.align 2, 0
_081B8598: .4byte 0x030046A4
_081B859C:
	subs r4, #1
	movs r7, #2
	b _081B85B0
_081B85A2:
	ldr r0, _081B85C0 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
_081B85AE:
	movs r7, #1
_081B85B0:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B85C4
	adds r0, #4
	b _081B85D0
	.align 2, 0
_081B85C0: .4byte 0x030046A4
_081B85C4:
	ldr r0, _081B85E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B85D0:
	ldrb r0, [r0]
	movs r5, #0xf
	ands r5, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B85EC
	adds r0, #4
	b _081B85F8
	.align 2, 0
_081B85E8: .4byte 0x030046A4
_081B85EC:
	ldr r0, _081B860C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B85F8:
	ldrb r0, [r0]
	lsrs r6, r0, #4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B8610
	adds r0, #4
	b _081B861C
	.align 2, 0
_081B860C: .4byte 0x030046A4
_081B8610:
	ldr r0, _081B862C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B861C:
	ldrh r0, [r0, #2]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _081B8630
	cmp r5, r8
	bge _081B864C
	b _081B8658
	.align 2, 0
_081B862C: .4byte 0x030046A4
_081B8630:
	mov r0, r8
	subs r1, r5, r0
	cmp r1, #1
	bne _081B863C
	cmp r6, r7
	beq _081B8654
_081B863C:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _081B8648
	cmp r6, r7
	beq _081B8654
_081B8648:
	cmp r1, #0
	ble _081B8650
_081B864C:
	movs r0, #1
	b _081B865A
_081B8650:
	cmp r1, #0
	blt _081B8658
_081B8654:
	movs r0, #0
	b _081B865A
_081B8658:
	movs r0, #2
_081B865A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081b8664
FUN_081b8664: @ 0x081B8664
	push {lr}
	adds r2, r0, #0
	cmp r1, #1
	beq _081B8686
	cmp r1, #1
	bgt _081B8676
	cmp r1, #0
	beq _081B8680
	b _081B86AC
_081B8676:
	cmp r1, #2
	beq _081B868C
	cmp r1, #3
	beq _081B86A0
	b _081B86AC
_081B8680:
	ldrh r0, [r2]
	adds r0, #0xff
	b _081B8690
_081B8686:
	ldrh r0, [r2, #4]
	adds r0, #0xff
	b _081B86A4
_081B868C:
	ldrh r0, [r2]
	subs r0, #0xff
_081B8690:
	ldr r1, _081B869C @ =0xFFFFFF00
	ands r0, r1
	adds r0, #0x80
	strh r0, [r2]
	b _081B86AC
	.align 2, 0
_081B869C: .4byte 0xFFFFFF00
_081B86A0:
	ldrh r0, [r2, #4]
	subs r0, #0xff
_081B86A4:
	ldr r1, _081B86B0 @ =0xFFFFFF00
	ands r0, r1
	adds r0, #0x80
	strh r0, [r2, #4]
_081B86AC:
	pop {r0}
	bx r0
	.align 2, 0
_081B86B0: .4byte 0xFFFFFF00

	thumb_func_start FUN_081b86b4
FUN_081b86b4: @ 0x081B86B4
	ldrh r3, [r0]
	ldr r2, _081B86D4 @ =0xFFFFFF00
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
_081B86D4: .4byte 0xFFFFFF00

	thumb_func_start FUN_081b86d8
FUN_081b86d8: @ 0x081B86D8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r0, #0
	mov sb, r6
	mov r8, r6
	ldr r0, _081B8744 @ =0x000004A4
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
	bne _081B8704
	b _081B8894
_081B8704:
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
	blt _081B873E
	cmp r1, #0
	blt _081B873E
	ldr r0, _081B8748 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081B873E
	ldr r0, _081B874C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B8750
_081B873E:
	movs r4, #0
	mov ip, r4
	b _081B8760
	.align 2, 0
_081B8744: .4byte 0x000004A4
_081B8748: .4byte 0x030046A8
_081B874C: .4byte 0x030046AC
_081B8750:
	ldr r0, _081B878C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r3
	mov ip, r0
_081B8760:
	mov r5, r8
	ldrh r1, [r5, #8]
	lsls r0, r1, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r5, #0xc]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	adds r5, r1, #0
	cmp r4, #0
	blt _081B8788
	cmp r3, #0
	blt _081B8788
	ldr r0, _081B8790 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B8788
	ldr r0, _081B8794 @ =0x030046AC
	ldr r0, [r0]
	cmp r3, r0
	blo _081B8798
_081B8788:
	movs r0, #0
	b _081B87A6
	.align 2, 0
_081B878C: .4byte 0x030046A4
_081B8790: .4byte 0x030046A8
_081B8794: .4byte 0x030046AC
_081B8798:
	ldr r0, _081B87D0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r3, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r4
_081B87A6:
	cmp ip, r0
	beq _081B87EE
	adds r1, r7, #0
	cmp r7, #0
	bge _081B87B2
	rsbs r1, r7, #0
_081B87B2:
	adds r0, r2, #0
	cmp r2, #0
	bge _081B87BA
	rsbs r0, r2, #0
_081B87BA:
	cmp r1, r0
	bge _081B87DC
	ldr r0, _081B87D4 @ =0x000004A4
	add r0, sb
	ldr r1, [r0]
	ldr r0, _081B87D8 @ =0xFFFFFF00
	ands r0, r5
	adds r0, #0x80
	strh r0, [r1, #0x1c]
	b _081B87EE
	.align 2, 0
_081B87D0: .4byte 0x030046A4
_081B87D4: .4byte 0x000004A4
_081B87D8: .4byte 0xFFFFFF00
_081B87DC:
	ldr r0, _081B8888 @ =0x000004A4
	add r0, sb
	ldr r2, [r0]
	mov r0, r8
	ldrh r1, [r0, #0xc]
	ldr r0, _081B888C @ =0xFFFFFF00
	ands r0, r1
	adds r0, #0x80
	strh r0, [r2, #0x20]
_081B87EE:
	ldr r5, _081B8888 @ =0x000004A4
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
	ldr r4, _081B8890 @ =0x000006C2
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
	beq _081B889A
	ldrb r0, [r7]
	lsrs r0, r0, #6
	cmp r2, r0
	beq _081B889A
	mov r0, sb
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _081B889A
	.align 2, 0
_081B8888: .4byte 0x000004A4
_081B888C: .4byte 0xFFFFFF00
_081B8890: .4byte 0x000006C2
_081B8894:
	ldr r2, _081B88AC @ =0x000006B4
	adds r0, r6, r2
	strh r1, [r0]
_081B889A:
	movs r0, #1
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081B88AC: .4byte 0x000006B4

	thumb_func_start FUN_081b88b0
FUN_081b88b0: @ 0x081B88B0
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
	beq _081B8918
	ldr r3, _081B890C @ =0x000001DF
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _081B88DC
	movs r0, #4
	ldr r6, _081B8910 @ =0x00000222
	adds r2, r4, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081B88DC:
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
	ldr r6, _081B8914 @ =0x0000024E
	adds r0, r4, r6
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _081B8970
	adds r0, r4, #0
	bl enemy_golem_081b8df4
	b _081B8960
	.align 2, 0
_081B890C: .4byte 0x000001DF
_081B8910: .4byte 0x00000222
_081B8914: .4byte 0x0000024E
_081B8918:
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	ldr r3, _081B8978 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	ldr r6, _081B897C @ =0x0000046A
	adds r0, r4, r6
	strb r5, [r0]
	adds r2, #0x1c
	adds r0, r4, r2
	str r5, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r1, [r0]
	ldr r3, _081B8980 @ =FUN_080e48d0
	movs r2, #0x10
	adds r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081B8984 @ =0x0000046B
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
_081B8960:
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081B8970:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B8978: .4byte 0x00000469
_081B897C: .4byte 0x0000046A
_081B8980: .4byte FUN_080e48d0
_081B8984: .4byte 0x0000046B

	thumb_func_start FUN_081b8988
FUN_081b8988: @ 0x081B8988
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
	beq _081B89A8
	b _081B8C00
_081B89A8:
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r7, _081B8A74 @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _081B8A78 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r2, [r0]
	ldr r3, _081B8A7C @ =FUN_080e6794
	movs r1, #0xe
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _081B8A80 @ =0x0000046B
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
	beq _081B8A9C
	ldr r4, _081B8A84 @ =0x00000482
	adds r1, r5, r4
	movs r0, #2
	strh r0, [r1]
	movs r0, #4
	ldr r1, _081B8A88 @ =0x00000222
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
	ldr r4, _081B8A8C @ =0x00000554
	adds r0, r5, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _081B8A90 @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _081B8A94 @ =0x00000552
	adds r0, r5, r3
	mov r4, r8
	strb r4, [r0]
	ldrh r0, [r6]
	mov r6, ip
	ands r0, r6
	cmp r0, #0
	beq _081B8AE0
	ldr r7, _081B8A98 @ =0x0000024E
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
	bls _081B8AE0
	strh r1, [r2]
	b _081B8AE0
	.align 2, 0
_081B8A74: .4byte 0x00000469
_081B8A78: .4byte 0x0000046A
_081B8A7C: .4byte FUN_080e6794
_081B8A80: .4byte 0x0000046B
_081B8A84: .4byte 0x00000482
_081B8A88: .4byte 0x00000222
_081B8A8C: .4byte 0x00000554
_081B8A90: .4byte 0x00000551
_081B8A94: .4byte 0x00000552
_081B8A98: .4byte 0x0000024E
_081B8A9C:
	movs r2, #0x10
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081B8B1C @ =0x00000482
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
	ldr r2, _081B8B20 @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _081B8B24 @ =0x00000552
	adds r0, r5, r3
	strb r4, [r0]
_081B8AE0:
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
	blt _081B8B18
	cmp r1, #0
	blt _081B8B18
	ldr r0, _081B8B28 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B8B18
	ldr r0, _081B8B2C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B8B30
_081B8B18:
	movs r4, #0
	b _081B8B3E
	.align 2, 0
_081B8B1C: .4byte 0x00000482
_081B8B20: .4byte 0x00000551
_081B8B24: .4byte 0x00000552
_081B8B28: .4byte 0x030046A8
_081B8B2C: .4byte 0x030046AC
_081B8B30:
	ldr r0, _081B8B50 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B8B3E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B8B54
	adds r0, #4
	b _081B8B60
	.align 2, 0
_081B8B50: .4byte 0x030046A4
_081B8B54:
	ldr r0, _081B8B74 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B8B60:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B8B78
	cmp r3, #2
	beq _081B8B7C
	b _081B8B80
	.align 2, 0
_081B8B74: .4byte 0x030046A4
_081B8B78:
	ldrb r0, [r6, #4]
	b _081B8B7E
_081B8B7C:
	ldrb r0, [r6]
_081B8B7E:
	subs r2, r2, r0
_081B8B80:
	movs r1, #0
	strh r2, [r6, #2]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r0, [r0]
	strh r1, [r0, #6]
	ldr r7, _081B8BBC @ =0x000004A4
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
	bne _081B8BC0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _081B8BE6
	.align 2, 0
_081B8BBC: .4byte 0x000004A4
_081B8BC0:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081B8BE0
	cmp r0, #2
	beq _081B8BDC
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B8BDC:
	movs r0, #1
	b _081B8BF0
_081B8BE0:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_081B8BE6:
	ldr r1, _081B8C0C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081B8BF0:
	cmp r0, #0
	bne _081B8C00
	ldr r4, _081B8C10 @ =0x000005C4
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_081B8C00:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B8C0C: .4byte 0xFFFFFDFF
_081B8C10: .4byte 0x000005C4

	thumb_func_start FUN_081b8c14
FUN_081b8c14: @ 0x081B8C14
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
	blt _081B8C4C
	cmp r1, #0
	blt _081B8C4C
	ldr r0, _081B8C50 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B8C4C
	ldr r0, _081B8C54 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B8C58
_081B8C4C:
	movs r4, #0
	b _081B8C66
	.align 2, 0
_081B8C50: .4byte 0x030046A8
_081B8C54: .4byte 0x030046AC
_081B8C58:
	ldr r0, _081B8C78 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B8C66:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B8C7C
	adds r0, #4
	b _081B8C88
	.align 2, 0
_081B8C78: .4byte 0x030046A4
_081B8C7C:
	ldr r0, _081B8CC8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B8C88:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _081B8CC2
	ldr r1, _081B8CCC @ =0x000004A4
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
	beq _081B8CC2
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r4]
	ldr r2, [r1, #0xc]
	ldr r1, [r1, #8]
	str r1, [r0]
	str r2, [r0, #4]
	bl FUN_081b86b4
_081B8CC2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B8CC8: .4byte 0x030046A4
_081B8CCC: .4byte 0x000004A4

	thumb_func_start FUN_081b8cd0
FUN_081b8cd0: @ 0x081B8CD0
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
	blt _081B8D02
	cmp r1, #0
	blt _081B8D02
	ldr r0, _081B8D08 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B8D02
	ldr r0, _081B8D0C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B8D10
_081B8D02:
	movs r4, #0
	b _081B8D1E
	.align 2, 0
_081B8D08: .4byte 0x030046A8
_081B8D0C: .4byte 0x030046AC
_081B8D10:
	ldr r0, _081B8D30 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B8D1E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B8D34
	adds r0, #4
	b _081B8D40
	.align 2, 0
_081B8D30: .4byte 0x030046A4
_081B8D34:
	ldr r0, _081B8D84 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B8D40:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _081B8D7E
	ldr r1, _081B8D88 @ =0x000004A4
	adds r0, r6, r1
	ldr r0, [r0]
	adds r1, r6, #0
	adds r1, #8
	adds r2, r5, #0
	bl FUN_0823599c
	cmp r0, #0
	beq _081B8D7E
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r5]
	ldr r2, [r5, #4]
	str r1, [r0]
	str r2, [r0, #4]
	bl FUN_081b86b4
	movs r2, #0x80
	lsls r2, r2, #0xc
	ldr r0, _081B8D8C @ =0x0000065C
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081B8D7E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B8D84: .4byte 0x030046A4
_081B8D88: .4byte 0x000004A4
_081B8D8C: .4byte 0x0000065C

	thumb_func_start FUN_081b8d90
FUN_081b8d90: @ 0x081B8D90
	push {lr}
	adds r2, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r3, _081B8DB0 @ =0x0000065C
	adds r0, r0, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B8DB4
	movs r0, #1
	b _081B8DB6
	.align 2, 0
_081B8DB0: .4byte 0x0000065C
_081B8DB4:
	movs r0, #0
_081B8DB6:
	cmp r0, #0
	bne _081B8DEA
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B8DEA
	ldr r0, _081B8DF0 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B8DEA
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081B8DEA
	adds r0, r2, #0
	bl FUN_081b8c14
_081B8DEA:
	pop {r0}
	bx r0
	.align 2, 0
_081B8DF0: .4byte 0x03002BE0

	thumb_func_start enemy_golem_081b8df4
enemy_golem_081b8df4: @ 0x081B8DF4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _081B8E58 @ =0x082522A8
	movs r2, #0x86
	lsls r2, r2, #2
	bl FUN_080e6768
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081B8E5C @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	ldr r5, _081B8E60 @ =0x0000046A
	adds r0, r4, r5
	strb r2, [r0]
	ldr r1, _081B8E64 @ =0x00000484
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
	ldr r5, _081B8E68 @ =0x0000046D
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
_081B8E58: .4byte 0x082522A8
_081B8E5C: .4byte 0x00000469
_081B8E60: .4byte 0x0000046A
_081B8E64: .4byte 0x00000484
_081B8E68: .4byte 0x0000046D

	thumb_func_start FUN_081b8e6c
FUN_081b8e6c: @ 0x081B8E6C
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

	thumb_func_start FUN_081b8eec
FUN_081b8eec: @ 0x081B8EEC
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
	ldr r1, _081B8FD8 @ =0x0000065C
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
	ldr r2, _081B8FDC @ =0x000006E2
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
	beq _081B8FE0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081B8FE8
	.align 2, 0
_081B8FD8: .4byte 0x0000065C
_081B8FDC: .4byte 0x000006E2
_081B8FE0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081B8FE8:
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
	beq _081B900C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081B9014
_081B900C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081B9014:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081B904C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081B9084
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081B9050
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081B9044
	ldrb r0, [r4, #5]
_081B9044:
	subs r0, #1
	strh r0, [r4, #8]
	b _081B9060
	.align 2, 0
_081B904C: .4byte 0x0000FFFF
_081B9050:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081B9060
	strh r1, [r4, #8]
_081B9060:
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
	bne _081B9084
	movs r0, #1
	strb r0, [r4, #7]
_081B9084:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081b908c
FUN_081b908c: @ 0x081B908C
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

	thumb_func_start FUN_081b90a0
FUN_081b90a0: @ 0x081B90A0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r4, _081B90C4 @ =0x00000256
	adds r0, r5, r4
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081B90C8
	adds r0, #4
	b _081B90D4
	.align 2, 0
_081B90C4: .4byte 0x00000256
_081B90C8:
	ldr r0, _081B90F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B90D4:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #0
	beq _081B9116
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq _081B9100
	cmp r0, #1
	bgt _081B90F8
	cmp r0, #0
	beq _081B9108
	b _081B910E
	.align 2, 0
_081B90F4: .4byte 0x030046A4
_081B90F8:
	cmp r0, #3
	beq _081B9100
	cmp r0, #5
	bne _081B910E
_081B9100:
	movs r2, #0xa0
	lsls r2, r2, #1
	movs r3, #0xb
	b _081B914A
_081B9108:
	movs r2, #0xa0
	movs r3, #5
	b _081B914A
_081B910E:
	movs r2, #0x80
	lsls r2, r2, #1
	movs r3, #8
	b _081B914A
_081B9116:
	movs r4, #0x90
	lsls r4, r4, #3
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, #1
	beq _081B9134
	cmp r0, #1
	bgt _081B912C
	cmp r0, #0
	beq _081B913C
	b _081B9144
_081B912C:
	cmp r0, #3
	beq _081B9134
	cmp r0, #5
	bne _081B9144
_081B9134:
	movs r2, #0xe0
	lsls r2, r2, #1
	movs r3, #0x16
	b _081B914A
_081B913C:
	movs r2, #0xa0
	lsls r2, r2, #1
	movs r3, #0xa
	b _081B914A
_081B9144:
	movs r2, #0xc0
	lsls r2, r2, #1
	movs r3, #0x10
_081B914A:
	ldr r0, _081B9160 @ =0x000006B6
	adds r1, r6, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, r2
	bge _081B9164
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	b _081B9166
	.align 2, 0
_081B9160: .4byte 0x000006B6
_081B9164:
	strh r2, [r1]
_081B9166:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081b916c
FUN_081b916c: @ 0x081B916C
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
	beq _081B9196
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r1, [r0]
	adds r0, r2, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _081B9198
_081B9196:
	movs r0, #0
_081B9198:
	pop {r1}
	bx r1

	thumb_func_start FUN_081b919c
FUN_081b919c: @ 0x081B919C
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	adds r4, r3, #0
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	bne _081B91EC
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
	bhi _081B91D0
	ldr r0, _081B91CC @ =0x085ADF98
	ldrh r1, [r3, #8]
	b _081B91E0
	.align 2, 0
_081B91CC: .4byte 0x085ADF98
_081B91D0:
	subs r0, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _081B91EC
	ldr r0, _081B91E8 @ =0x085ADF98
	ldrh r1, [r4, #8]
	subs r1, #8
_081B91E0:
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	b _081B91EE
	.align 2, 0
_081B91E8: .4byte 0x085ADF98
_081B91EC:
	movs r0, #0
_081B91EE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081b91f4
FUN_081b91f4: @ 0x081B91F4
	push {lr}
	adds r2, r0, #0
	ldr r1, _081B9240 @ =0x00000553
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #9
	beq _081B923A
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081B923A
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, _081B9244 @ =0x00FFFFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	beq _081B923A
	adds r3, #0x4c
	adds r0, r2, r3
	ldr r1, [r0]
	ldr r0, _081B9248 @ =0x0000065C
	adds r1, r1, r0
	ldr r2, _081B924C @ =0xFFF7FFFF
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_081B923A:
	pop {r0}
	bx r0
	.align 2, 0
_081B9240: .4byte 0x00000553
_081B9244: .4byte 0x00FFFFFF
_081B9248: .4byte 0x0000065C
_081B924C: .4byte 0xFFF7FFFF

	thumb_func_start FUN_081b9250
FUN_081b9250: @ 0x081B9250
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x28
	mov r8, r0
	ldr r4, _081B92D4 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	movs r5, #0x40
	orrs r0, r5
	ldr r1, _081B92D8 @ =0x0000FFFF
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
	ldr r3, _081B92DC @ =FUN_081b973c
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
	ldr r3, _081B92E0 @ =FUN_081b9464
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
_081B92D4: .4byte 0xFFFF0000
_081B92D8: .4byte 0x0000FFFF
_081B92DC: .4byte FUN_081b973c
_081B92E0: .4byte FUN_081b9464

	thumb_func_start FUN_081b92e4
FUN_081b92e4: @ 0x081B92E4
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
	beq _081B9300
	b _081B9458
_081B9300:
	ldr r0, _081B9364 @ =0x0000A027
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _081B9312
	b _081B9458
_081B9312:
	movs r2, #0x10
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _081B9370
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r1, #0x20
	strh r1, [r0, #0xa]
	ldr r1, _081B9368 @ =0x00002001
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
	ldr r4, _081B936C @ =0x00200004
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
	b _081B940C
	.align 2, 0
_081B9364: .4byte 0x0000A027
_081B9368: .4byte 0x00002001
_081B936C: .4byte 0x00200004
_081B9370:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	cmp r1, #0
	beq _081B9424
	ldr r2, _081B938C @ =0x000006B6
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _081B9390
	asrs r0, r0, #5
	b _081B9396
	.align 2, 0
_081B938C: .4byte 0x000006B6
_081B9390:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081B9396:
	adds r5, r0, #0
	cmp r5, #0x14
	ble _081B93A0
	movs r5, #0x14
	b _081B93A6
_081B93A0:
	cmp r5, #9
	bgt _081B93A6
	movs r5, #0xa
_081B93A6:
	ldr r4, _081B9414 @ =0x00000226
	adds r0, r6, r4
	ldrh r0, [r0]
	muls r0, r5, r0
	movs r1, #0xa
	bl Div
	adds r4, r0, #0
	ldr r1, _081B9418 @ =0x0000022E
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
	ldr r1, _081B941C @ =0x00002301
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
	ldr r3, _081B9420 @ =0x00000236
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
_081B940C:
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081B9458
	.align 2, 0
_081B9414: .4byte 0x00000226
_081B9418: .4byte 0x0000022E
_081B941C: .4byte 0x00002301
_081B9420: .4byte 0x00000236
_081B9424:
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, _081B9460 @ =0x00002001
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
_081B9458:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B9460: .4byte 0x00002001

	thumb_func_start FUN_081b9464
FUN_081b9464: @ 0x081B9464
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
	beq _081B948E
	b _081B972A
_081B948E:
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
	beq _081B94C8
	cmp r0, #1
	bgt _081B94B0
	cmp r0, #0
	beq _081B94BA
	b _081B9510
_081B94B0:
	cmp r0, #2
	beq _081B94D8
	cmp r0, #3
	beq _081B94F8
	b _081B9510
_081B94BA:
	mov r0, sp
	ldrh r1, [r0]
	ldr r3, _081B94C4 @ =0xFFFFFF00
	adds r1, r1, r3
	b _081B94E2
	.align 2, 0
_081B94C4: .4byte 0xFFFFFF00
_081B94C8:
	mov r0, sp
	ldrh r1, [r0, #4]
	ldr r0, _081B94D4 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081B9502
	.align 2, 0
_081B94D4: .4byte 0xFFFFFF00
_081B94D8:
	mov r0, sp
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081B94E2:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081B94F4 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	b _081B9510
	.align 2, 0
_081B94F4: .4byte 0xFFFF0000
_081B94F8:
	mov r0, sp
	ldrh r1, [r0, #4]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r1, r3
_081B9502:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081B9590 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
_081B9510:
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
	bne _081B9552
	b _081B96FC
_081B9552:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081B9566
	b _081B96AC
_081B9566:
	ldr r3, _081B9594 @ =0x00000553
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0x28
	beq _081B95D2
	ldrb r2, [r7, #5]
	ldr r0, [r6, #0x4c]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081B95C8
	adds r1, r2, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081B9598
	asrs r0, r1, #6
	b _081B959E
	.align 2, 0
_081B9590: .4byte 0xFFFF0000
_081B9594: .4byte 0x00000553
_081B9598:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081B959E:
	adds r2, r0, #0
	adds r0, r6, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081B95B6
	asrs r0, r1, #6
	b _081B95BC
_081B95B6:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081B95BC:
	subs r0, r2, r0
	cmp r0, #0
	bge _081B95C4
	rsbs r0, r0, #0
_081B95C4:
	cmp r0, #2
	bne _081B95CC
_081B95C8:
	movs r0, #1
	b _081B95CE
_081B95CC:
	movs r0, #0
_081B95CE:
	cmp r0, #0
	beq _081B9638
_081B95D2:
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B9600
	ldrh r1, [r6, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081B9600
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _081B9630 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081B9600:
	ldr r1, _081B9634 @ =0x000006BC
	add r1, r8
	ldrh r0, [r1]
	adds r0, #0xc8
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xc8
	lsls r2, r2, #1
	cmp r0, r2
	bls _081B9618
	strh r2, [r1]
_081B9618:
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
	b _081B972A
	.align 2, 0
_081B9630: .4byte 0xFEFFFFFF
_081B9634: .4byte 0x000006BC
_081B9638:
	ldr r0, _081B964C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B9650
	movs r0, #1
	b _081B9652
	.align 2, 0
_081B964C: .4byte 0x030047A4
_081B9650:
	movs r0, #0
_081B9652:
	cmp r0, #0
	beq _081B9688
	ldrh r1, [r6, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081B9664
	movs r2, #0
	b _081B967C
_081B9664:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081B9670
	movs r2, #1
	b _081B967C
_081B9670:
	movs r0, #4
	ands r0, r1
	movs r2, #3
	cmp r0, #0
	beq _081B967C
	movs r2, #2
_081B967C:
	ldr r1, _081B9684 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	b _081B968A
	.align 2, 0
_081B9684: .4byte 0x03002BE0
_081B9688:
	ldr r0, _081B96A4 @ =0x03002BE0
_081B968A:
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B972A
	ldr r1, _081B96A8 @ =0x000006BC
	add r1, r8
	movs r0, #0xc8
	lsls r0, r0, #1
	strh r0, [r1]
	b _081B972A
	.align 2, 0
_081B96A4: .4byte 0x03002BE0
_081B96A8: .4byte 0x000006BC
_081B96AC:
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B96DA
	ldrh r1, [r6, #0xa]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _081B96DA
	movs r2, #0xea
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r5, r3
	ldr r1, _081B96F4 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081B96DA:
	ldr r1, _081B96F8 @ =0x000006BC
	add r1, r8
	ldrh r0, [r1]
	adds r0, #0xc8
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xc8
	lsls r2, r2, #1
	cmp r0, r2
	bls _081B972A
	strh r2, [r1]
	b _081B972A
	.align 2, 0
_081B96F4: .4byte 0xFEFFFFFF
_081B96F8: .4byte 0x000006BC
_081B96FC:
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B972A
	ldrh r1, [r6, #0xa]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _081B972A
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _081B9738 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081B972A:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B9738: .4byte 0xFEFFFFFF

	thumb_func_start FUN_081b973c
FUN_081b973c: @ 0x081B973C
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
	beq _081B975E
	b _081B9DE4
_081B975E:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081B9788
	ldr r3, _081B9784 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B9776
	b _081B9DE4
_081B9776:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _081B9DE4
	.align 2, 0
_081B9784: .4byte 0x0000048C
_081B9788:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _081B9798
	b _081B9DE4
_081B9798:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _081B97A8
	b _081B9AB4
_081B97A8:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _081B97BA
	b _081B9DE4
_081B97BA:
	ldr r2, _081B984C @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081B97CE
	b _081B9DE4
_081B97CE:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081B97DC
	b _081B9DE4
_081B97DC:
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
	bne _081B97F4
	b _081B993C
_081B97F4:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _081B985C
	ands r3, r1
	cmp r3, #0
	beq _081B985C
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081B981A
	rsbs r1, r1, #0
_081B981A:
	cmp r1, #0x20
	bgt _081B985C
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _081B9850 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _081B9854 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _081B9858 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _081B9DE4
	.align 2, 0
_081B984C: .4byte 0x0000A007
_081B9850: .4byte 0x000004BE
_081B9854: .4byte 0x0000048C
_081B9858: .4byte 0x0000044E
_081B985C:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _081B9884 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081B988C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081B9888 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081B98FA
	.align 2, 0
_081B9884: .4byte 0x0000048A
_081B9888: .4byte 0x03002BE0
_081B988C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081B98A8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081B98A4 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081B98FA
	.align 2, 0
_081B98A4: .4byte 0x03002BE0
_081B98A8:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081B98C4
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081B98C0 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081B98FA
	.align 2, 0
_081B98C0: .4byte 0x03002BE0
_081B98C4:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081B98E0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081B98DC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081B98FA
	.align 2, 0
_081B98DC: .4byte 0x03002BE0
_081B98E0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081B98F2
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081B98FA
_081B98F2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081B98FC
_081B98FA:
	movs r3, #1
_081B98FC:
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
	ldr r5, _081B9930 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _081B991E
	b _081B9A74
_081B991E:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B9934
	movs r0, #1
	b _081B9936
	.align 2, 0
_081B9930: .4byte 0x0000049C
_081B9934:
	movs r0, #0
_081B9936:
	cmp r0, #0
	bne _081B9A1A
	b _081B9A30
_081B993C:
	strh r2, [r7, #0x3e]
	ldr r1, _081B9964 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _081B996C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081B9968 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081B99DA
	.align 2, 0
_081B9964: .4byte 0x0000048A
_081B9968: .4byte 0x03002BE0
_081B996C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081B9988
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081B9984 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081B99DA
	.align 2, 0
_081B9984: .4byte 0x03002BE0
_081B9988:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _081B99A4
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081B99A0 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081B99DA
	.align 2, 0
_081B99A0: .4byte 0x03002BE0
_081B99A4:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081B99C0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081B99BC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081B99DA
	.align 2, 0
_081B99BC: .4byte 0x03002BE0
_081B99C0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081B99D2
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081B99DA
_081B99D2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081B99DC
_081B99DA:
	movs r3, #1
_081B99DC:
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
	ldr r5, _081B9A10 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _081B9A74
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B9A14
	movs r0, #1
	b _081B9A16
	.align 2, 0
_081B9A10: .4byte 0x0000049C
_081B9A14:
	movs r0, #0
_081B9A16:
	cmp r0, #0
	beq _081B9A30
_081B9A1A:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081B9A2C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081B9A3C
	.align 2, 0
_081B9A2C: .4byte 0x03002BE0
_081B9A30:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081B9A74
_081B9A3C:
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
_081B9A74:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081B9AA0
	ldr r5, _081B9AAC @ =0x0000024E
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
	bls _081B9AA0
	strh r1, [r2]
_081B9AA0:
	ldr r5, _081B9AB0 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _081B9DE4
	.align 2, 0
_081B9AAC: .4byte 0x0000024E
_081B9AB0: .4byte 0x0000048C
_081B9AB4:
	ldr r0, _081B9AC8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B9ACC
	movs r0, #1
	b _081B9ACE
	.align 2, 0
_081B9AC8: .4byte 0x030047A4
_081B9ACC:
	movs r0, #0
_081B9ACE:
	cmp r0, #0
	beq _081B9ADC
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236640
	b _081B9AE4
_081B9ADC:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236524
_081B9AE4:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _081B9B1C @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _081B9B20 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _081B9B12
	cmp r2, #0x17
	bne _081B9B24
_081B9B12:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _081B9B46
	.align 2, 0
_081B9B1C: .4byte 0x0000048C
_081B9B20: .4byte 0x000001DF
_081B9B24:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _081B9B12
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _081B9B74 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081B9B46
	movs r1, #0
_081B9B46:
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
	beq _081B9B82
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _081B9B78
	asrs r0, r0, #1
	b _081B9B7E
	.align 2, 0
_081B9B74: .4byte 0x00000187
_081B9B78:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081B9B7E:
	mov r2, sb
	strh r0, [r2]
_081B9B82:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081B9BA0
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _081B9B9C @ =0x000001DD
	adds r1, r6, r4
	b _081B9C14
	.align 2, 0
_081B9B9C: .4byte 0x000001DD
_081B9BA0:
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
	bne _081B9C00
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _081B9C00
	ldr r2, _081B9BF0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081B9BF4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081B9BF8 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _081B9BFC @ =0x000001DD
	adds r1, r6, r4
	b _081B9C14
	.align 2, 0
_081B9BF0: .4byte 0x030046B8
_081B9BF4: .4byte 0x000003FF
_081B9BF8: .4byte 0x0203B400
_081B9BFC: .4byte 0x000001DD
_081B9C00:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _081B9C34 @ =0x000001DD
	adds r1, r6, r3
_081B9C14:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081B9C3C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081B9C38 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081B9CAA
	.align 2, 0
_081B9C34: .4byte 0x000001DD
_081B9C38: .4byte 0x03002BE0
_081B9C3C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081B9C58
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081B9C54 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081B9CAA
	.align 2, 0
_081B9C54: .4byte 0x03002BE0
_081B9C58:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081B9C74
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081B9C70 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081B9CAA
	.align 2, 0
_081B9C70: .4byte 0x03002BE0
_081B9C74:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081B9C90
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081B9C8C @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081B9CAA
	.align 2, 0
_081B9C8C: .4byte 0x03002BE0
_081B9C90:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081B9CA2
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _081B9CAA
_081B9CA2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081B9CAC
_081B9CAA:
	movs r3, #1
_081B9CAC:
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
	ldr r5, _081B9CE0 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _081B9D48
	movs r1, #2
	ldr r2, _081B9CE4 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B9CE8
	movs r0, #1
	b _081B9CEA
	.align 2, 0
_081B9CE0: .4byte 0x0000049C
_081B9CE4: .4byte 0x00000474
_081B9CE8:
	movs r0, #0
_081B9CEA:
	cmp r0, #0
	beq _081B9D04
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081B9D00 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081B9D10
	.align 2, 0
_081B9D00: .4byte 0x03002BE0
_081B9D04:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081B9D48
_081B9D10:
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
_081B9D48:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _081B9D7C
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081B9D7C
	ldr r0, _081B9D94 @ =0x0000024E
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
	bls _081B9D7C
	strh r1, [r2]
_081B9D7C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _081B9D98 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _081B9D9C @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B9DA0
	movs r0, #1
	b _081B9DA2
	.align 2, 0
_081B9D94: .4byte 0x0000024E
_081B9D98: .4byte 0x030046A0
_081B9D9C: .4byte 0x00000934
_081B9DA0:
	movs r0, #0
_081B9DA2:
	ldr r1, _081B9DF4 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _081B9DBA
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_081B9DBA:
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
_081B9DE4:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B9DF4: .4byte 0x0000048A

	thumb_func_start FUN_081b9df8
FUN_081b9df8: @ 0x081B9DF8
	push {lr}
	adds r2, r0, #0
	ldr r0, _081B9E18 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B9E0A
	movs r0, #0
	strb r0, [r1]
_081B9E0A:
	adds r0, r2, #0
	movs r1, #1
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_081B9E18: .4byte 0x0000046D

	thumb_func_start FUN_081b9e1c
FUN_081b9e1c: @ 0x081B9E1C
	push {lr}
	adds r2, r0, #0
	ldr r0, _081B9E3C @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B9E2E
	movs r0, #0
	strb r0, [r1]
_081B9E2E:
	adds r0, r2, #0
	movs r1, #0
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_081B9E3C: .4byte 0x0000046D

	thumb_func_start FUN_081b9e40
FUN_081b9e40: @ 0x081B9E40
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r5
	ldr r0, _081B9E60 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B9E64
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B9E66
	.align 2, 0
_081B9E60: .4byte 0x0000046D
_081B9E64:
	movs r0, #0
_081B9E66:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	bne _081B9E74
	b _081BA30E
_081B9E74:
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
	ldr r3, _081B9EC4 @ =0x0000046A
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #6
	beq _081B9EC8
	movs r1, #0x90
	lsls r1, r1, #3
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _081B9EC8
	mov r1, r8
	ldr r0, [r1, #0x24]
	ldr r0, [r0, #8]
	ldrh r0, [r0, #4]
	lsrs r1, r0, #0xc
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	b _081B9ED0
	.align 2, 0
_081B9EC4: .4byte 0x0000046A
_081B9EC8:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
_081B9ED0:
	cmp r1, #0
	blt _081B9ED8
	asrs r0, r1, #1
	b _081B9EDE
_081B9ED8:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081B9EDE:
	cmp r2, r0
	bne _081B9F4A
	ldr r2, _081B9F30 @ =0x0000046B
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
	beq _081B9F40
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _081B9F34 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _081B9F38 @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _081B9F3C @ =0x000005BC
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #0x1b
	adds r3, #1
	b _081BA470
	.align 2, 0
_081B9F30: .4byte 0x0000046B
_081B9F34: .4byte 0x00000469
_081B9F38: .4byte 0x0000046A
_081B9F3C: .4byte 0x000005BC
_081B9F40:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	b _081BA4D4
_081B9F4A:
	cmp r2, #1
	beq _081BA028
	cmp r2, #1
	bgt _081B9F58
	cmp r2, #0
	beq _081B9F66
	b _081BA306
_081B9F58:
	cmp r2, #2
	bne _081B9F5E
	b _081BA0F8
_081B9F5E:
	cmp r2, #3
	bne _081B9F64
	b _081BA1E4
_081B9F64:
	b _081BA306
_081B9F66:
	subs r0, r1, #2
	cmp r0, #3
	bhi _081B9FB8
	movs r2, #2
	ldr r3, _081B9F8C @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _081B9F94
	ldr r1, _081B9F90 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	b _081BA206
	.align 2, 0
_081B9F8C: .4byte 0x0000025D
_081B9F90: .4byte 0x000004B7
_081B9F94:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #3
	ldr r3, _081B9FB0 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081B9FB4 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #3
	beq _081B9FAE
	b _081BA242
_081B9FAE:
	b _081BA232
	.align 2, 0
_081B9FB0: .4byte 0x000004B7
_081B9FB4: .4byte 0x0000046E
_081B9FB8:
	movs r1, #2
	ldr r2, _081B9FE0 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B9FE8
	ldr r3, _081B9FE4 @ =0x000004B7
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
	b _081BA00E
	.align 2, 0
_081B9FE0: .4byte 0x0000025D
_081B9FE4: .4byte 0x000004B7
_081B9FE8:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r2, _081BA020 @ =0x000004B7
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
_081BA00E:
	ldr r3, _081BA024 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	b _081BA2FE
	.align 2, 0
_081BA020: .4byte 0x000004B7
_081BA024: .4byte 0x0000046E
_081BA028:
	subs r0, r1, #4
	cmp r0, #3
	bhi _081BA088
	movs r2, #2
	ldr r1, _081BA050 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _081BA058
	ldr r1, _081BA054 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #2
	b _081BA206
	.align 2, 0
_081BA050: .4byte 0x0000025D
_081BA054: .4byte 0x000004B7
_081BA058:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #4
	ldr r3, _081BA080 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081BA084 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #4
	beq _081BA072
	b _081BA242
_081BA072:
	ldrb r0, [r6]
	cmp r0, #0
	beq _081BA07A
	b _081BA242
_081BA07A:
	ldr r0, [r4, #8]
	ands r0, r2
	b _081BA23E
	.align 2, 0
_081BA080: .4byte 0x000004B7
_081BA084: .4byte 0x0000046E
_081BA088:
	movs r1, #2
	ldr r2, _081BA0B0 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BA0B8
	ldr r3, _081BA0B4 @ =0x000004B7
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
	b _081BA0E0
	.align 2, 0
_081BA0B0: .4byte 0x0000025D
_081BA0B4: .4byte 0x000004B7
_081BA0B8:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #3
	ldr r2, _081BA0F0 @ =0x000004B7
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
_081BA0E0:
	ldr r3, _081BA0F4 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	b _081BA2FE
	.align 2, 0
_081BA0F0: .4byte 0x000004B7
_081BA0F4: .4byte 0x0000046E
_081BA0F8:
	subs r0, r1, #1
	cmp r0, #4
	bls _081BA174
	movs r1, #2
	ldr r2, _081BA128 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BA130
	ldr r3, _081BA12C @ =0x000004B7
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
	b _081BA156
	.align 2, 0
_081BA128: .4byte 0x0000025D
_081BA12C: .4byte 0x000004B7
_081BA130:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #3
	ldr r2, _081BA16C @ =0x000004B7
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
_081BA156:
	ldr r3, _081BA170 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	b _081BA26C
	.align 2, 0
_081BA16C: .4byte 0x000004B7
_081BA170: .4byte 0x0000046E
_081BA174:
	movs r2, #4
	ldr r1, _081BA19C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BA1A4
	ldr r3, _081BA1A0 @ =0x000004B7
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
	b _081BA1CA
	.align 2, 0
_081BA19C: .4byte 0x0000025D
_081BA1A0: .4byte 0x000004B7
_081BA1A4:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r1, _081BA1DC @ =0x000004B7
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
_081BA1CA:
	ldr r2, _081BA1E0 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r5, r3
	b _081BA2FE
	.align 2, 0
_081BA1DC: .4byte 0x000004B7
_081BA1E0: .4byte 0x0000046E
_081BA1E4:
	cmp r1, #3
	bhi _081BA27C
	movs r2, #2
	ldr r1, _081BA210 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _081BA21C
	ldr r1, _081BA214 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
_081BA206:
	bl FUN_08236fac
	ldr r2, _081BA218 @ =0x0000046E
	adds r6, r5, r2
	b _081BA25E
	.align 2, 0
_081BA210: .4byte 0x0000025D
_081BA214: .4byte 0x000004B7
_081BA218: .4byte 0x0000046E
_081BA21C:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r3, _081BA274 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081BA278 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #2
	bne _081BA242
_081BA232:
	ldrb r0, [r6]
	cmp r0, #0
	bne _081BA242
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
_081BA23E:
	cmp r0, #0
	beq _081BA262
_081BA242:
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
_081BA25E:
	movs r0, #0
	strb r0, [r6]
_081BA262:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
_081BA26C:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081BA306
	.align 2, 0
_081BA274: .4byte 0x000004B7
_081BA278: .4byte 0x0000046E
_081BA27C:
	movs r2, #2
	ldr r1, _081BA2A8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BA2B4
	ldr r3, _081BA2AC @ =0x000004B7
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
	ldr r0, _081BA2B0 @ =0x0000046E
	adds r6, r5, r0
	b _081BA2F4
	.align 2, 0
_081BA2A8: .4byte 0x0000025D
_081BA2AC: .4byte 0x000004B7
_081BA2B0: .4byte 0x0000046E
_081BA2B4:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #3
	ldr r1, _081BA340 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081BA344 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #3
	bne _081BA2DC
	ldrb r0, [r6]
	cmp r0, #0
	bne _081BA2DC
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081BA2F8
_081BA2DC:
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
_081BA2F4:
	movs r0, #0
	strb r0, [r6]
_081BA2F8:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r5, r1
_081BA2FE:
	ldr r1, _081BA348 @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081BA306:
	ldr r2, _081BA344 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_081BA30E:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	bne _081BA370
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
	bge _081BA336
	rsbs r0, r0, #0
_081BA336:
	cmp r0, #0x16
	bgt _081BA34C
	mov r0, r8
	strb r1, [r0, #5]
	b _081BA370
	.align 2, 0
_081BA340: .4byte 0x000004B7
_081BA344: .4byte 0x0000046E
_081BA348: .4byte 0xFFFEFFFF
_081BA34C:
	movs r1, #0x80
	lsls r1, r1, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081BA368
	adds r0, r2, #0
	adds r0, #0x16
	mov r1, r8
	strb r0, [r1, #5]
	b _081BA370
_081BA368:
	adds r0, r2, #0
	subs r0, #0x16
	mov r2, r8
	strb r0, [r2, #5]
_081BA370:
	ldr r1, _081BA388 @ =0x0000A02F
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081BA390
	ldr r0, _081BA38C @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081BA3A0
	.align 2, 0
_081BA388: .4byte 0x0000A02F
_081BA38C: .4byte 0x00000482
_081BA390:
	ldr r1, _081BA3C4 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081BA3A0
	movs r0, #1
	strh r0, [r2]
_081BA3A0:
	ldr r3, _081BA3C8 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BA3CC
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
	b _081BA3E4
	.align 2, 0
_081BA3C4: .4byte 0x00000482
_081BA3C8: .4byte 0x0000025D
_081BA3CC:
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
_081BA3E4:
	ldr r1, _081BA494 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081BA4D4
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
	bge _081BA40E
	rsbs r1, r1, #0
_081BA40E:
	cmp r1, #0
	bgt _081BA4A4
	ldr r1, _081BA498 @ =0x0000046B
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
	beq _081BA4D4
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r7, [r0]
	adds r1, #0x69
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081BA49C @ =0x0000046A
	adds r0, r5, r2
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081BA4A0 @ =0x000005BC
	adds r0, r5, r2
	ldr r2, [r0]
	movs r1, #0x1b
	subs r3, #0x17
_081BA470:
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
	b _081BA4D4
	.align 2, 0
_081BA494: .4byte 0x0000046E
_081BA498: .4byte 0x0000046B
_081BA49C: .4byte 0x0000046A
_081BA4A0: .4byte 0x000005BC
_081BA4A4:
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _081BA4E4 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081BA4E8 @ =0x0000046B
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
_081BA4D4:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081BA4E4: .4byte 0x0000046D
_081BA4E8: .4byte 0x0000046B

	thumb_func_start FUN_081ba4ec
FUN_081ba4ec: @ 0x081BA4EC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	movs r2, #1
	ldr r1, _081BA508 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BA50C
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081BA516
	.align 2, 0
_081BA508: .4byte 0x0000025D
_081BA50C:
	ldr r1, [r4, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_081BA516:
	ldr r1, _081BA52C @ =0x0000046D
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _081BA530
	movs r0, #0
	strb r0, [r6]
	movs r0, #1
	b _081BA532
	.align 2, 0
_081BA52C: .4byte 0x0000046D
_081BA530:
	movs r0, #0
_081BA532:
	adds r5, r0, #0
	cmp r5, #0
	beq _081BA544
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r4, r3
	bl FUN_080136b4
	b _081BA586
_081BA544:
	cmp r3, #0x1a
	ble _081BA580
	adds r0, r4, #0
	movs r1, #7
	bl FUN_080ef86c
	ldr r2, _081BA578 @ =FUN_081ba590
	movs r1, #0xd
	movs r0, #1
	strb r0, [r6]
	ldr r3, _081BA57C @ =0x0000046B
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
	b _081BA586
	.align 2, 0
_081BA578: .4byte FUN_081ba590
_081BA57C: .4byte 0x0000046B
_081BA580:
	ldr r1, _081BA58C @ =0x0000046E
	adds r0, r4, r1
	strb r5, [r0]
_081BA586:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081BA58C: .4byte 0x0000046E

	thumb_func_start FUN_081ba590
FUN_081ba590: @ 0x081BA590
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _081BA5A8 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BA5AC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BA5AE
	.align 2, 0
_081BA5A8: .4byte 0x0000046D
_081BA5AC:
	movs r0, #0
_081BA5AE:
	cmp r0, #0
	beq _081BA5FA
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_08013698
	ldr r2, _081BA5D4 @ =0x0000025D
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BA5D8
	ldr r2, [r6, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081BA5E6
	.align 2, 0
_081BA5D4: .4byte 0x0000025D
_081BA5D8:
	ldr r0, [r6, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_081BA5E6:
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
_081BA5FA:
	ldr r1, _081BA798 @ =0x0000046E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BA606
	b _081BA792
_081BA606:
	adds r0, r6, #0
	bl FUN_081b8eec
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, _081BA79C @ =0x0000055C
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
	ldr r1, _081BA7A0 @ =0x00000564
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
	ldr r1, _081BA7A4 @ =0x00000566
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _081BA7A8 @ =0x00000567
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
	ldr r1, _081BA7AC @ =0x0000056C
	adds r0, r6, r1
	ldrb r1, [r0]
	subs r2, #0x15
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _081BA7B0 @ =0x00000572
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
	ldr r2, _081BA7B4 @ =0x0000046B
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _081BA7B8 @ =0x0000046C
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r5, [r0]
	ldr r2, _081BA7BC @ =0x0000024E
	adds r0, r6, r2
	strh r4, [r0]
	subs r2, #0xbc
	adds r0, r6, r2
	strh r4, [r0]
	ldr r2, _081BA7C0 @ =0x00000544
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
	ldr r2, _081BA7C4 @ =0x00000482
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
	ldr r1, _081BA7C8 @ =0x00000464
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0x8c
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r4, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r1, _081BA7CC @ =0x08252288
	adds r0, r6, #0
	ldr r2, _081BA7D0 @ =0x00000982
	bl FUN_080e6768
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _081BA7D4 @ =0x00000541
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
_081BA792:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081BA798: .4byte 0x0000046E
_081BA79C: .4byte 0x0000055C
_081BA7A0: .4byte 0x00000564
_081BA7A4: .4byte 0x00000566
_081BA7A8: .4byte 0x00000567
_081BA7AC: .4byte 0x0000056C
_081BA7B0: .4byte 0x00000572
_081BA7B4: .4byte 0x0000046B
_081BA7B8: .4byte 0x0000046C
_081BA7BC: .4byte 0x0000024E
_081BA7C0: .4byte 0x00000544
_081BA7C4: .4byte 0x00000482
_081BA7C8: .4byte 0x00000464
_081BA7CC: .4byte 0x08252288
_081BA7D0: .4byte 0x00000982
_081BA7D4: .4byte 0x00000541

	thumb_func_start FUN_081ba7d8
FUN_081ba7d8: @ 0x081BA7D8
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _081BA7F0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BA7F4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BA7F6
	.align 2, 0
_081BA7F0: .4byte 0x0000046D
_081BA7F4:
	movs r0, #0
_081BA7F6:
	cmp r0, #0
	beq _081BA818
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
	bne _081BA818
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
_081BA818:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Mod
	cmp r0, #0
	bne _081BA834
	ldr r2, _081BA880 @ =0x000001DF
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080e5718
_081BA834:
	ldr r1, _081BA884 @ =0x00000466
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _081BA87A
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _081BA87A
	ldr r3, _081BA888 @ =FUN_081ba894
	movs r2, #6
	ldr r0, _081BA88C @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081BA890 @ =0x0000046B
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
_081BA87A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081BA880: .4byte 0x000001DF
_081BA884: .4byte 0x00000466
_081BA888: .4byte FUN_081ba894
_081BA88C: .4byte 0x0000046D
_081BA890: .4byte 0x0000046B

	thumb_func_start FUN_081ba894
FUN_081ba894: @ 0x081BA894
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _081BA8AC @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BA8B0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BA8B2
	.align 2, 0
_081BA8AC: .4byte 0x0000046D
_081BA8B0:
	movs r0, #0
_081BA8B2:
	cmp r0, #0
	beq _081BA8CE
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
_081BA8CE:
	cmp r5, #0x28
	bne _081BA8E0
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081BA8E0:
	ldr r1, _081BA8FC @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081BA8F6
	cmp r5, #0x78
	ble _081BA8F6
	ldr r0, _081BA900 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081BA8F6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081BA8FC: .4byte 0x0000046E
_081BA900: .4byte 0x0000046B

	thumb_func_start FUN_081ba904
FUN_081ba904: @ 0x081BA904
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r0, _081BA920 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BA924
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BA926
	.align 2, 0
_081BA920: .4byte 0x0000046D
_081BA924:
	movs r0, #0
_081BA926:
	cmp r0, #0
	beq _081BA93A
	adds r0, r4, #0
	movs r1, #0xf
	bl FUN_080ef86c
	ldr r0, _081BA94C @ =0x0000046E
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_081BA93A:
	ldrh r0, [r5, #8]
	cmp r0, #1
	bne _081BA944
	movs r0, #0
	strh r0, [r5, #0xe]
_081BA944:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081BA94C: .4byte 0x0000046E

	thumb_func_start FUN_081ba950
FUN_081ba950: @ 0x081BA950
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081BA968 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BA96C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BA96E
	.align 2, 0
_081BA968: .4byte 0x0000046D
_081BA96C:
	movs r0, #0
_081BA96E:
	cmp r0, #0
	beq _081BA98A
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
_081BA98A:
	ldr r1, _081BA9C4 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081BA9BC
	ldr r4, _081BA9C8 @ =FUN_081ba9d4
	movs r3, #0x21
	ldr r0, _081BA9CC @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081BA9D0 @ =0x0000046B
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
_081BA9BC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081BA9C4: .4byte 0x0000046E
_081BA9C8: .4byte FUN_081ba9d4
_081BA9CC: .4byte 0x0000046D
_081BA9D0: .4byte 0x0000046B

	thumb_func_start FUN_081ba9d4
FUN_081ba9d4: @ 0x081BA9D4
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
	ldr r2, _081BAA00 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BAA04
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BAA06
	.align 2, 0
_081BAA00: .4byte 0x0000046D
_081BAA04:
	movs r0, #0
_081BAA06:
	cmp r0, #0
	beq _081BAAE4
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #1
	beq _081BAA30
	cmp r0, #1
	bgt _081BAA28
	cmp r0, #0
	beq _081BAA8C
	b _081BAADC
_081BAA28:
	cmp r0, #3
	beq _081BAA30
	cmp r0, #5
	bne _081BAADC
_081BAA30:
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r0, _081BAA48 @ =0x0000065C
	adds r1, r1, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081BAA4C
	movs r0, #1
	b _081BAA4E
	.align 2, 0
_081BAA48: .4byte 0x0000065C
_081BAA4C:
	movs r0, #0
_081BAA4E:
	cmp r0, #0
	beq _081BAA60
_081BAA52:
	ldr r1, _081BAA5C @ =0xFFFFF7FF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081BAADC
	.align 2, 0
_081BAA5C: .4byte 0xFFFFF7FF
_081BAA60:
	ldr r2, _081BAA80 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081BAA84 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081BAA88 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r1, r0, #0
	adds r1, #0x1e
	b _081BAADE
	.align 2, 0
_081BAA80: .4byte 0x030046B8
_081BAA84: .4byte 0x000003FF
_081BAA88: .4byte 0x0203B400
_081BAA8C:
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r0, _081BAAA4 @ =0x0000065C
	adds r1, r1, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081BAAA8
	movs r0, #1
	b _081BAAAA
	.align 2, 0
_081BAAA4: .4byte 0x0000065C
_081BAAA8:
	movs r0, #0
_081BAAAA:
	cmp r0, #0
	bne _081BAA52
	ldr r2, _081BAAD0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081BAAD4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081BAAD8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #4
	adds r1, r0, #0
	adds r1, #0x32
	b _081BAADE
	.align 2, 0
_081BAAD0: .4byte 0x030046B8
_081BAAD4: .4byte 0x000003FF
_081BAAD8: .4byte 0x0203B400
_081BAADC:
	movs r1, #0
_081BAADE:
	ldr r0, _081BAB34 @ =0x000006BE
	add r0, sb
	strh r1, [r0]
_081BAAE4:
	mov r4, sp
	adds r4, #5
	adds r0, r5, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_080e5d44
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _081BAB38 @ =0x085ADFA8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _081BAB3C @ =0x0000025D
	adds r0, r5, r1
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #0
	bne _081BAB48
	ldr r2, _081BAB40 @ =0x000004B7
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
	ldr r2, _081BAB44 @ =0x0000046E
	adds r7, r5, r2
	b _081BABCA
	.align 2, 0
_081BAB34: .4byte 0x000006BE
_081BAB38: .4byte 0x085ADFA8
_081BAB3C: .4byte 0x0000025D
_081BAB40: .4byte 0x000004B7
_081BAB44: .4byte 0x0000046E
_081BAB48:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r3, #8
	mov ip, r3
	ldr r1, _081BABB8 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r0, _081BABBC @ =0x0000046E
	adds r7, r5, r0
	cmp r1, ip
	bne _081BAB84
	ldrb r0, [r7]
	cmp r0, #0
	bne _081BAB84
	cmp r4, #1
	bne _081BAB76
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081BABCE
_081BAB76:
	cmp r4, #0
	bne _081BAB84
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081BABCE
_081BAB84:
	mov r1, ip
	strb r1, [r2]
	movs r2, #4
	mov r8, r2
	adds r0, r4, #0
	ands r0, r2
	movs r3, #4
	cmp r0, #0
	beq _081BAB98
	movs r3, #6
_081BAB98:
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
	beq _081BABC0
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081BABC8
	.align 2, 0
_081BABB8: .4byte 0x000004B7
_081BABBC: .4byte 0x0000046E
_081BABC0:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081BABC8:
	str r0, [r6, #8]
_081BABCA:
	movs r0, #0
	strb r0, [r7]
_081BABCE:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r3, r5, r2
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r2, _081BAC14 @ =0x000006B6
	add r2, sb
	ldrh r4, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _081BAC18 @ =0x0000017F
	cmp r1, r0
	bgt _081BABF4
	adds r0, r4, #0
	adds r0, #0x10
	strh r0, [r2]
_081BABF4:
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	ldr r2, _081BAC1C @ =0x00000482
	adds r1, r5, r2
	strh r0, [r1]
	ldr r1, _081BAC20 @ =0x0000A02F
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081BAC24
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081BAC34
	.align 2, 0
_081BAC14: .4byte 0x000006B6
_081BAC18: .4byte 0x0000017F
_081BAC1C: .4byte 0x00000482
_081BAC20: .4byte 0x0000A02F
_081BAC24:
	ldr r1, _081BAC58 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081BAC34
	movs r0, #1
	strh r0, [r2]
_081BAC34:
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _081BAC5C
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
	b _081BAC74
	.align 2, 0
_081BAC58: .4byte 0x00000482
_081BAC5C:
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
_081BAC74:
	ldr r0, _081BACA0 @ =0x000006BE
	add r0, sb
	ldr r2, [sp, #8]
	ldrh r0, [r0]
	cmp r2, r0
	ble _081BAC90
	ldr r0, _081BACA4 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080e81dc
_081BAC90:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081BACA0: .4byte 0x000006BE
_081BACA4: .4byte 0x0000046B

	thumb_func_start FUN_081baca8
FUN_081baca8: @ 0x081BACA8
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
	ldr r1, _081BACD8 @ =0x0000046D
	add r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BACDC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BACDE
	.align 2, 0
_081BACD8: .4byte 0x0000046D
_081BACDC:
	movs r0, #0
_081BACDE:
	cmp r0, #0
	beq _081BACEA
	ldr r2, _081BAD4C @ =0x0000046E
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
_081BACEA:
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
	ldr r1, _081BAD50 @ =0x085ADFA8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _081BAD54 @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	str r5, [sp, #0x24]
	str r0, [sp, #0x20]
	cmp r1, #0
	bne _081BAD5C
	ldr r2, _081BAD58 @ =0x000004B7
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
	ldr r2, _081BAD4C @ =0x0000046E
	adds r7, r6, r2
	b _081BADDE
	.align 2, 0
_081BAD4C: .4byte 0x0000046E
_081BAD50: .4byte 0x085ADFA8
_081BAD54: .4byte 0x0000025D
_081BAD58: .4byte 0x000004B7
_081BAD5C:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r3, #8
	mov ip, r3
	ldr r1, _081BADCC @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r0, _081BADD0 @ =0x0000046E
	adds r7, r6, r0
	cmp r1, ip
	bne _081BAD98
	ldrb r0, [r7]
	cmp r0, #0
	bne _081BAD98
	cmp r4, #1
	bne _081BAD8A
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081BADE2
_081BAD8A:
	cmp r4, #0
	bne _081BAD98
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081BADE2
_081BAD98:
	mov r1, ip
	strb r1, [r2]
	movs r2, #4
	mov r8, r2
	adds r0, r4, #0
	ands r0, r2
	movs r3, #4
	cmp r0, #0
	beq _081BADAC
	movs r3, #6
_081BADAC:
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
	beq _081BADD4
	ldr r0, [r5, #8]
	mov r1, r8
	orrs r0, r1
	b _081BADDC
	.align 2, 0
_081BADCC: .4byte 0x000004B7
_081BADD0: .4byte 0x0000046E
_081BADD4:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081BADDC:
	str r0, [r5, #8]
_081BADDE:
	movs r0, #0
	strb r0, [r7]
_081BADE2:
	ldr r2, [sp, #0x1c]
	ldr r1, _081BAE0C @ =0x000006B6
	adds r0, r2, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	ldr r2, _081BAE10 @ =0x00000482
	adds r1, r6, r2
	strh r0, [r1]
	ldr r1, _081BAE14 @ =0x0000A02F
	ldr r2, [sp, #0x24]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081BAE18
	ldr r0, _081BAE10 @ =0x00000482
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081BAE28
	.align 2, 0
_081BAE0C: .4byte 0x000006B6
_081BAE10: .4byte 0x00000482
_081BAE14: .4byte 0x0000A02F
_081BAE18:
	ldr r1, _081BAE4C @ =0x00000482
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081BAE28
	movs r0, #1
	strh r0, [r2]
_081BAE28:
	ldr r1, [sp, #0x20]
	ldrb r0, [r1]
	cmp r0, #0
	bne _081BAE50
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
	b _081BAE68
	.align 2, 0
_081BAE4C: .4byte 0x00000482
_081BAE50:
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
_081BAE68:
	movs r6, #3
	mov r2, sl
	ands r2, r6
	cmp r2, #0
	bne _081BAEBA
	mov r1, sb
	ldrh r0, [r1, #0x10]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	ldr r4, _081BAECC @ =0xFFFF0000
	ldr r5, _081BAED0 @ =0x0000FFFF
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
_081BAEBA:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081BAECC: .4byte 0xFFFF0000
_081BAED0: .4byte 0x0000FFFF

	thumb_func_start FUN_081baed4
FUN_081baed4: @ 0x081BAED4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _081BAEF0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BAEF4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BAEF6
	.align 2, 0
_081BAEF0: .4byte 0x0000046D
_081BAEF4:
	movs r0, #0
_081BAEF6:
	cmp r0, #0
	beq _081BAFD2
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
	ldr r1, _081BAF3C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BAF48
	ldr r1, _081BAF40 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _081BAF44 @ =0x0000046E
	adds r7, r5, r0
	b _081BAFC6
	.align 2, 0
_081BAF3C: .4byte 0x0000025D
_081BAF40: .4byte 0x000004B7
_081BAF44: .4byte 0x0000046E
_081BAF48:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r3, #7
	ldr r1, _081BAFB4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081BAFB8 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081BAF82
	ldrb r0, [r7]
	cmp r0, #0
	bne _081BAF82
	cmp r4, #1
	bne _081BAF74
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081BAFCA
_081BAF74:
	cmp r4, #0
	bne _081BAF82
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081BAFCA
_081BAF82:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081BAF94
	movs r3, #6
_081BAF94:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081BAFBC
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081BAFC4
	.align 2, 0
_081BAFB4: .4byte 0x000004B7
_081BAFB8: .4byte 0x0000046E
_081BAFBC:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081BAFC4:
	str r0, [r6, #8]
_081BAFC6:
	movs r0, #0
	strb r0, [r7]
_081BAFCA:
	ldr r0, _081BB000 @ =0x0000046E
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
_081BAFD2:
	ldr r1, _081BB000 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081BAFF2
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, _081BB004 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _081BB008 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_081BAFF2:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081BB000: .4byte 0x0000046E
_081BB004: .4byte 0xFFFFFEFF
_081BB008: .4byte 0x0000046B

	thumb_func_start FUN_081bb00c
FUN_081bb00c: @ 0x081BB00C
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
	ldr r2, _081BB038 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BB03C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BB03E
	.align 2, 0
_081BB038: .4byte 0x0000046D
_081BB03C:
	movs r0, #0
_081BB03E:
	cmp r0, #0
	beq _081BB086
	ldr r3, _081BB0E8 @ =0x0000046B
	adds r0, r6, r3
	movs r1, #0
	strb r1, [r0]
	ldr r7, _081BB0EC @ =0x0000046E
	adds r0, r6, r7
	strb r1, [r0]
	ldr r0, _081BB0F0 @ =0x000006C1
	add r0, r8
	strb r1, [r0]
	ldr r0, _081BB0F4 @ =0x000006C4
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
	bl FUN_081b86b4
_081BB086:
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
	ldr r1, _081BB0F8 @ =0x085ADFA8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov sb, r0
	orrs r4, r2
	ldr r1, _081BB0FC @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	str r5, [sp, #0x2c]
	str r0, [sp, #0x30]
	cmp r1, #0
	bne _081BB104
	ldr r2, _081BB100 @ =0x000004B7
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
	ldr r0, _081BB0EC @ =0x0000046E
	adds r7, r6, r0
	b _081BB186
	.align 2, 0
_081BB0E8: .4byte 0x0000046B
_081BB0EC: .4byte 0x0000046E
_081BB0F0: .4byte 0x000006C1
_081BB0F4: .4byte 0x000006C4
_081BB0F8: .4byte 0x085ADFA8
_081BB0FC: .4byte 0x0000025D
_081BB100: .4byte 0x000004B7
_081BB104:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r3, #8
	mov sb, r3
	ldr r1, _081BB174 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r3, _081BB178 @ =0x0000046E
	adds r7, r6, r3
	cmp r1, sb
	bne _081BB140
	ldrb r0, [r7]
	cmp r0, #0
	bne _081BB140
	cmp r4, #1
	bne _081BB132
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081BB18A
_081BB132:
	cmp r4, #0
	bne _081BB140
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081BB18A
_081BB140:
	mov r0, sb
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #4
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081BB152
	movs r3, #6
_081BB152:
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
	beq _081BB17C
	ldr r0, [r5, #8]
	movs r2, #4
	orrs r0, r2
	b _081BB184
	.align 2, 0
_081BB174: .4byte 0x000004B7
_081BB178: .4byte 0x0000046E
_081BB17C:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081BB184:
	str r0, [r5, #8]
_081BB186:
	movs r0, #0
	strb r0, [r7]
_081BB18A:
	ldr r3, _081BB1B0 @ =0x000006C1
	add r3, r8
	ldrb r2, [r3]
	cmp r2, #0
	beq _081BB196
	b _081BB2BC
_081BB196:
	ldr r1, _081BB1B4 @ =0x000006B6
	add r1, r8
	ldrh r0, [r1]
	subs r0, #0x28
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081BB1B8
	movs r0, #1
	strb r0, [r3]
	strh r2, [r1]
	b _081BB4D4
	.align 2, 0
_081BB1B0: .4byte 0x000006C1
_081BB1B4: .4byte 0x000006B6
_081BB1B8:
	movs r3, #0
	ldrsh r5, [r1, r3]
	ldr r4, _081BB258 @ =0x085B0A08
	ldr r0, _081BB25C @ =0x000006C5
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
	ldr r3, _081BB260 @ =0xFFFF0000
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
	blt _081BB252
	cmp r1, #0
	blt _081BB252
	ldr r0, _081BB264 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081BB252
	ldr r0, _081BB268 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BB26C
_081BB252:
	movs r1, #0
	b _081BB27A
	.align 2, 0
_081BB258: .4byte 0x085B0A08
_081BB25C: .4byte 0x000006C5
_081BB260: .4byte 0xFFFF0000
_081BB264: .4byte 0x030046A8
_081BB268: .4byte 0x030046AC
_081BB26C:
	ldr r0, _081BB298 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r3
_081BB27A:
	ldr r2, _081BB29C @ =0x00000256
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, r1
	beq _081BB2A8
	ldr r1, _081BB2A0 @ =0x000006B6
	add r1, r8
	movs r0, #0
	strh r0, [r1]
	ldr r1, _081BB2A4 @ =0x000006C1
	add r1, r8
	movs r0, #1
	strb r0, [r1]
	b _081BB454
	.align 2, 0
_081BB298: .4byte 0x030046A4
_081BB29C: .4byte 0x00000256
_081BB2A0: .4byte 0x000006B6
_081BB2A4: .4byte 0x000006C1
_081BB2A8:
	mov r3, sp
	ldrh r0, [r3, #0x20]
	ldrh r7, [r6, #0x10]
	adds r0, r0, r7
	strh r0, [r6, #0x10]
	ldrh r0, [r3, #0x24]
	ldrh r1, [r6, #0x14]
	adds r0, r0, r1
	strh r0, [r6, #0x14]
	b _081BB454
_081BB2BC:
	cmp r2, #1
	beq _081BB2C2
	b _081BB3F0
_081BB2C2:
	ldr r2, _081BB308 @ =0x00000256
	adds r0, r6, r2
	ldrh r5, [r0]
	add r7, sp, #0x10
	ldr r3, _081BB30C @ =0x030046A4
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
	beq _081BB310
	adds r0, #4
	b _081BB31C
	.align 2, 0
_081BB308: .4byte 0x00000256
_081BB30C: .4byte 0x030046A4
_081BB310:
	mov r3, sb
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081BB31C:
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
	ldr r0, _081BB364 @ =0x000006C5
	add r0, r8
	ldrb r0, [r0]
	lsrs r0, r0, #6
	cmp r0, #1
	beq _081BB39E
	cmp r0, #1
	bgt _081BB368
	cmp r0, #0
	beq _081BB372
	b _081BB3C8
	.align 2, 0
_081BB364: .4byte 0x000006C5
_081BB368:
	cmp r0, #2
	beq _081BB372
	cmp r0, #3
	beq _081BB39E
	b _081BB3C8
_081BB372:
	movs r0, #0
	strh r0, [r2, #4]
	add r0, sp, #0x18
	ldrh r3, [r0]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #8
	ble _081BB38A
	movs r0, #8
	mov r1, sl
	strh r0, [r1, #0x10]
	b _081BB3C8
_081BB38A:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r0, r1
	bge _081BB398
	mov r3, sl
	strh r1, [r3, #0x10]
	b _081BB3C8
_081BB398:
	mov r7, sl
	strh r3, [r7, #0x10]
	b _081BB3C8
_081BB39E:
	movs r0, #0
	strh r0, [r2]
	add r0, sp, #0x18
	ldrh r3, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #8
	ble _081BB3B6
	movs r0, #8
	mov r3, sl
	strh r0, [r3, #0x14]
	b _081BB3C8
_081BB3B6:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r0, r1
	bge _081BB3C4
	mov r7, sl
	strh r1, [r7, #0x14]
	b _081BB3C8
_081BB3C4:
	mov r0, sl
	strh r3, [r0, #0x14]
_081BB3C8:
	movs r1, #0
	ldrsh r0, [r2, r1]
	add r1, sp, #0x18
	movs r2, #4
	ldrsh r1, [r1, r2]
	adds r2, r0, r1
	cmp r2, #0
	bne _081BB454
	ldr r0, _081BB3E8 @ =0x000006C1
	add r0, r8
	movs r1, #2
	strb r1, [r0]
	ldr r0, _081BB3EC @ =0x000006C3
	add r0, r8
	strb r2, [r0]
	b _081BB4D4
	.align 2, 0
_081BB3E8: .4byte 0x000006C1
_081BB3EC: .4byte 0x000006C3
_081BB3F0:
	ldr r4, _081BB440 @ =0x000006C3
	add r4, r8
	ldrb r0, [r4]
	adds r0, #1
	movs r5, #0
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _081BB454
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
	bl FUN_081b86d8
	ldr r2, _081BB444 @ =0x000006C2
	add r2, r8
	ldrb r1, [r2]
	ldr r0, _081BB448 @ =0x000006C4
	add r0, r8
	strb r1, [r0]
	ldrb r0, [r2]
	strb r0, [r6, #5]
	ldr r3, _081BB44C @ =0x0000046B
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	strb r5, [r4]
	ldr r0, _081BB450 @ =0x000006B6
	add r0, r8
	strh r5, [r0]
	b _081BB4D4
	.align 2, 0
_081BB440: .4byte 0x000006C3
_081BB444: .4byte 0x000006C2
_081BB448: .4byte 0x000006C4
_081BB44C: .4byte 0x0000046B
_081BB450: .4byte 0x000006B6
_081BB454:
	movs r0, #0xd7
	lsls r0, r0, #3
	add r0, r8
	ldrh r0, [r0]
	lsrs r0, r0, #7
	ldr r7, _081BB47C @ =0x00000482
	adds r1, r6, r7
	strh r0, [r1]
	ldr r1, _081BB480 @ =0x0000A02F
	ldr r2, [sp, #0x2c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081BB484
	adds r3, r7, #0
	adds r1, r6, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081BB494
	.align 2, 0
_081BB47C: .4byte 0x00000482
_081BB480: .4byte 0x0000A02F
_081BB484:
	ldr r7, _081BB4B8 @ =0x00000482
	adds r0, r6, r7
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081BB494
	movs r0, #1
	strh r0, [r2]
_081BB494:
	ldr r1, [sp, #0x30]
	ldrb r0, [r1]
	cmp r0, #0
	bne _081BB4BC
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
	b _081BB4D4
	.align 2, 0
_081BB4B8: .4byte 0x00000482
_081BB4BC:
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
_081BB4D4:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081bb4e4
FUN_081bb4e4: @ 0x081BB4E4
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
	ldr r2, _081BB514 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BB518
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BB51A
	.align 2, 0
_081BB514: .4byte 0x0000046D
_081BB518:
	movs r0, #0
_081BB51A:
	cmp r0, #0
	beq _081BB52E
	ldr r3, _081BB580 @ =0x0000046E
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	movs r0, #0xcd
	lsls r0, r0, #3
	add r0, sl
	strh r1, [r0]
_081BB52E:
	mov r4, sp
	adds r4, #9
	adds r0, r5, #0
	add r1, sp, #8
	adds r2, r4, #0
	bl FUN_080e5d44
	add r0, sp, #8
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _081BB584 @ =0x085ADFA8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _081BB588 @ =0x0000025D
	adds r0, r5, r1
	ldrb r1, [r0]
	str r0, [sp, #0x20]
	cmp r1, #0
	bne _081BB590
	ldr r2, _081BB58C @ =0x000004B7
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
	ldr r2, _081BB580 @ =0x0000046E
	adds r7, r5, r2
	b _081BB612
	.align 2, 0
_081BB580: .4byte 0x0000046E
_081BB584: .4byte 0x085ADFA8
_081BB588: .4byte 0x0000025D
_081BB58C: .4byte 0x000004B7
_081BB590:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r3, #8
	mov ip, r3
	ldr r3, _081BB600 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r0, _081BB604 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, ip
	bne _081BB5CC
	ldrb r0, [r7]
	cmp r0, #0
	bne _081BB5CC
	cmp r4, #1
	bne _081BB5BE
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081BB616
_081BB5BE:
	cmp r4, #0
	bne _081BB5CC
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081BB616
_081BB5CC:
	mov r1, ip
	strb r1, [r2]
	movs r2, #4
	mov r8, r2
	adds r0, r4, #0
	ands r0, r2
	movs r3, #4
	cmp r0, #0
	beq _081BB5E0
	movs r3, #6
_081BB5E0:
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
	beq _081BB608
	ldr r0, [r6, #8]
	mov r3, r8
	orrs r0, r3
	b _081BB610
	.align 2, 0
_081BB600: .4byte 0x000004B7
_081BB604: .4byte 0x0000046E
_081BB608:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081BB610:
	str r0, [r6, #8]
_081BB612:
	movs r0, #0
	strb r0, [r7]
_081BB616:
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
	bne _081BB702
	ldr r2, _081BB674 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081BB678 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081BB67C @ =0x0203B400
	adds r0, r0, r3
	movs r1, #0xff
	ldrb r4, [r0]
	ldr r3, _081BB680 @ =0x085B0A08
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
	blt _081BB684
	asrs r0, r1, #0x18
	b _081BB68A
	.align 2, 0
_081BB674: .4byte 0x030046B8
_081BB678: .4byte 0x000003FF
_081BB67C: .4byte 0x0203B400
_081BB680: .4byte 0x085B0A08
_081BB684:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081BB68A:
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
	blt _081BB6AC
	asrs r0, r2, #0x18
	b _081BB6B2
_081BB6AC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081BB6B2:
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _081BB738 @ =0xFFFF0000
	add r1, sp, #0xc
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	ldr r0, [sp, #0x14]
	ands r0, r3
	movs r4, #0x30
	orrs r0, r4
	ldr r2, _081BB73C @ =0x0000FFFF
	ands r0, r2
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	ldr r0, [r6]
	adds r0, #1
	ldr r3, _081BB740 @ =0x000003FF
	ands r0, r3
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _081BB744 @ =0x0203B400
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
_081BB702:
	ldr r2, _081BB748 @ =0x000006B6
	add r2, sl
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _081BB74C @ =0x0000017F
	cmp r1, r0
	bgt _081BB718
	adds r0, r3, #0
	adds r0, #0x10
	strh r0, [r2]
_081BB718:
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	ldr r2, _081BB750 @ =0x00000482
	adds r1, r5, r2
	strh r0, [r1]
	ldr r1, _081BB754 @ =0x0000A02F
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081BB758
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081BB768
	.align 2, 0
_081BB738: .4byte 0xFFFF0000
_081BB73C: .4byte 0x0000FFFF
_081BB740: .4byte 0x000003FF
_081BB744: .4byte 0x0203B400
_081BB748: .4byte 0x000006B6
_081BB74C: .4byte 0x0000017F
_081BB750: .4byte 0x00000482
_081BB754: .4byte 0x0000A02F
_081BB758:
	ldr r3, _081BB78C @ =0x00000482
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081BB768
	movs r0, #1
	strh r0, [r2]
_081BB768:
	ldr r1, [sp, #0x20]
	ldrb r0, [r1]
	cmp r0, #0
	bne _081BB790
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
	b _081BB7A8
	.align 2, 0
_081BB78C: .4byte 0x00000482
_081BB790:
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
_081BB7A8:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081bb7b8
FUN_081bb7b8: @ 0x081BB7B8
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
	ldr r2, _081BB7E8 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BB7EC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BB7EE
	.align 2, 0
_081BB7E8: .4byte 0x0000046D
_081BB7EC:
	movs r0, #0
_081BB7EE:
	cmp r0, #0
	beq _081BB7FA
	adds r0, r7, #0
	movs r1, #4
	bl FUN_080e81dc
_081BB7FA:
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
	ldr r1, _081BB8F8 @ =0x000006B6
	adds r3, r0, r1
	movs r0, #0
	ldrsh r2, [r3, r0]
	ldr r4, _081BB8FC @ =0x085B0A08
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
	bne _081BB8C0
	ldrh r0, [r2, #0x10]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	ldr r3, _081BB900 @ =0xFFFF0000
	ldr r2, _081BB904 @ =0x0000FFFF
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
_081BB8C0:
	adds r0, r7, #0
	adds r0, #0x8c
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081BB8D0
	b _081BBAB2
_081BB8D0:
	ldr r0, [sp, #0x2c]
	movs r2, #0xdc
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r3, [sp, #0x2c]
	ldr r5, _081BB908 @ =0x000006E2
	adds r1, r3, r5
	movs r0, #0x14
	strh r0, [r1]
	mov r1, sl
	movs r2, #0x14
	ldrsh r0, [r1, r2]
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _081BB90C
	asrs r0, r1, #0x12
	b _081BB912
	.align 2, 0
_081BB8F8: .4byte 0x000006B6
_081BB8FC: .4byte 0x085B0A08
_081BB900: .4byte 0xFFFF0000
_081BB904: .4byte 0x0000FFFF
_081BB908: .4byte 0x000006E2
_081BB90C:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081BB912:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _081BB958 @ =0xFFFF0000
	ldr r2, [sp, #0x1c]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0x1c]
	ldr r3, _081BB95C @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081BB960 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r5, _081BB964 @ =0x0203B400
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081BB968 @ =0x0000FFFF
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
	blt _081BB96C
	asrs r0, r1, #0x12
	b _081BB972
	.align 2, 0
_081BB958: .4byte 0xFFFF0000
_081BB95C: .4byte 0x030046B8
_081BB960: .4byte 0x000003FF
_081BB964: .4byte 0x0203B400
_081BB968: .4byte 0x0000FFFF
_081BB96C:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081BB972:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _081BBA38 @ =0xFFFF0000
	mov r8, r3
	add r5, sp, #0x1c
	mov sb, r5
	ldr r0, [r5, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r5, #4]
	ldr r6, _081BBA3C @ =0x0203B400
	mov r0, ip
	ldr r2, [r0]
	adds r2, #1
	ldr r4, _081BBA40 @ =0x000003FF
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
	ldr r3, _081BBA44 @ =0x0000FFFF
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
	beq _081BBA4C
	ldr r5, _081BBA48 @ =0x0000046B
	adds r1, r7, r5
	movs r0, #1
	strb r0, [r1]
	b _081BBAB2
	.align 2, 0
_081BBA38: .4byte 0xFFFF0000
_081BBA3C: .4byte 0x0203B400
_081BBA40: .4byte 0x000003FF
_081BBA44: .4byte 0x0000FFFF
_081BBA48: .4byte 0x0000046B
_081BBA4C:
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
	ldr r5, _081BBAC4 @ =0x0000046A
	adds r0, r7, r5
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r4, [r0]
	adds r5, #2
	adds r0, r7, r5
	strb r2, [r0]
	ldr r1, _081BBAC8 @ =0x00000594
	adds r0, r7, r1
	ldr r1, [r0]
	adds r5, #1
	adds r0, r7, r5
	strb r2, [r0]
	ldr r2, _081BBACC @ =0x0000046B
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _081BBAD0 @ =0x00000553
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
_081BBAB2:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081BBAC4: .4byte 0x0000046A
_081BBAC8: .4byte 0x00000594
_081BBACC: .4byte 0x0000046B
_081BBAD0: .4byte 0x00000553

	thumb_func_start FUN_081bbad4
FUN_081bbad4: @ 0x081BBAD4
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
	ldr r2, _081BBB00 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BBB04
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BBB06
	.align 2, 0
_081BBB00: .4byte 0x0000046D
_081BBB04:
	movs r0, #0
_081BBB06:
	cmp r0, #0
	beq _081BBB48
	ldr r3, _081BBBBC @ =0x0000046E
	adds r0, r6, r3
	movs r1, #0
	strb r1, [r0]
	ldr r5, _081BBBC0 @ =0x000006C1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _081BBBC4 @ =0x000006C2
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
	bl FUN_081b86b4
_081BBB48:
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
	ldr r1, _081BBBC8 @ =0x085ADFA8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _081BBBCC @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	str r5, [sp, #0x10]
	str r0, [sp, #0x14]
	cmp r1, #0
	bne _081BBBD4
	ldr r2, _081BBBD0 @ =0x000004B7
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
	ldr r0, _081BBBBC @ =0x0000046E
	adds r0, r0, r6
	mov r8, r0
	b _081BBC5A
	.align 2, 0
_081BBBBC: .4byte 0x0000046E
_081BBBC0: .4byte 0x000006C1
_081BBBC4: .4byte 0x000006C2
_081BBBC8: .4byte 0x085ADFA8
_081BBBCC: .4byte 0x0000025D
_081BBBD0: .4byte 0x000004B7
_081BBBD4:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r3, #8
	mov ip, r3
	ldr r1, _081BBC48 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r3, _081BBC4C @ =0x0000046E
	adds r3, r3, r6
	mov r8, r3
	cmp r1, ip
	bne _081BBC12
	ldrb r0, [r3]
	cmp r0, #0
	bne _081BBC12
	cmp r4, #1
	bne _081BBC04
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081BBC60
_081BBC04:
	cmp r4, #0
	bne _081BBC12
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081BBC60
_081BBC12:
	mov r0, ip
	strb r0, [r2]
	movs r1, #4
	mov sl, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081BBC26
	movs r3, #6
_081BBC26:
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
	beq _081BBC50
	ldr r0, [r5, #8]
	mov r2, sl
	orrs r0, r2
	b _081BBC58
	.align 2, 0
_081BBC48: .4byte 0x000004B7
_081BBC4C: .4byte 0x0000046E
_081BBC50:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081BBC58:
	str r0, [r5, #8]
_081BBC5A:
	movs r0, #0
	mov r3, r8
	strb r0, [r3]
_081BBC60:
	ldr r5, _081BBC80 @ =0x000006C1
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BBD20
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq _081BBC8C
	cmp r0, #1
	bgt _081BBC84
	cmp r0, #0
	beq _081BBC9C
	b _081BBCAC
	.align 2, 0
_081BBC80: .4byte 0x000006C1
_081BBC84:
	cmp r0, #3
	beq _081BBC8C
	cmp r0, #5
	bne _081BBCAC
_081BBC8C:
	ldr r2, _081BBC98 @ =0x000006B6
	adds r1, r7, r2
	ldrh r0, [r1]
	subs r0, #0xc0
	b _081BBCB4
	.align 2, 0
_081BBC98: .4byte 0x000006B6
_081BBC9C:
	ldr r3, _081BBCA8 @ =0x000006B6
	adds r1, r7, r3
	ldrh r0, [r1]
	subs r0, #0x40
	b _081BBCB4
	.align 2, 0
_081BBCA8: .4byte 0x000006B6
_081BBCAC:
	ldr r5, _081BBCD0 @ =0x000006B6
	adds r1, r7, r5
	ldrh r0, [r1]
	subs r0, #0x80
_081BBCB4:
	strh r0, [r1]
	ldr r0, _081BBCD0 @ =0x000006B6
	adds r5, r7, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _081BBCD8
	ldr r2, _081BBCD4 @ =0x000006C1
	adds r0, r7, r2
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	strh r2, [r5]
	b _081BBEA0
	.align 2, 0
_081BBCD0: .4byte 0x000006B6
_081BBCD4: .4byte 0x000006C1
_081BBCD8:
	movs r0, #0
	ldrsh r3, [r5, r0]
	ldr r4, _081BBD18 @ =0x085B0A08
	ldr r1, _081BBD1C @ =0x000006C2
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
	b _081BBE20
	.align 2, 0
_081BBD18: .4byte 0x085B0A08
_081BBD1C: .4byte 0x000006C2
_081BBD20:
	cmp r0, #1
	bne _081BBDEC
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
	ldr r1, _081BBD60 @ =0x000006C5
	adds r0, r7, r1
	ldrb r0, [r0]
	lsrs r0, r0, #6
	cmp r0, #1
	beq _081BBD9A
	cmp r0, #1
	bgt _081BBD64
	cmp r0, #0
	beq _081BBD6E
	b _081BBDC4
	.align 2, 0
_081BBD60: .4byte 0x000006C5
_081BBD64:
	cmp r0, #2
	beq _081BBD6E
	cmp r0, #3
	beq _081BBD9A
	b _081BBDC4
_081BBD6E:
	movs r0, #0
	strh r0, [r3, #4]
	add r0, sp, #8
	ldrh r2, [r0]
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #8
	ble _081BBD86
	movs r0, #8
	mov r1, sb
	strh r0, [r1, #0x10]
	b _081BBDC4
_081BBD86:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r0, r1
	bge _081BBD94
	mov r2, sb
	strh r1, [r2, #0x10]
	b _081BBDC4
_081BBD94:
	mov r5, sb
	strh r2, [r5, #0x10]
	b _081BBDC4
_081BBD9A:
	movs r0, #0
	strh r0, [r3]
	add r0, sp, #8
	ldrh r2, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #8
	ble _081BBDB2
	movs r0, #8
	mov r2, sb
	strh r0, [r2, #0x14]
	b _081BBDC4
_081BBDB2:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r0, r1
	bge _081BBDC0
	mov r5, sb
	strh r1, [r5, #0x14]
	b _081BBDC4
_081BBDC0:
	mov r0, sb
	strh r2, [r0, #0x14]
_081BBDC4:
	movs r1, #0
	ldrsh r0, [r3, r1]
	add r1, sp, #8
	movs r2, #4
	ldrsh r1, [r1, r2]
	adds r3, r0, r1
	cmp r3, #0
	bne _081BBE20
	ldr r5, _081BBDE4 @ =0x000006C1
	adds r0, r7, r5
	movs r1, #2
	strb r1, [r0]
	ldr r1, _081BBDE8 @ =0x000006C3
	adds r0, r7, r1
	strb r3, [r0]
	b _081BBEA0
	.align 2, 0
_081BBDE4: .4byte 0x000006C1
_081BBDE8: .4byte 0x000006C3
_081BBDEC:
	ldr r3, _081BBE14 @ =0x000006C3
	adds r2, r7, r3
	ldrb r0, [r2]
	adds r0, #1
	movs r3, #0
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _081BBE20
	ldr r5, _081BBE18 @ =0x0000046B
	adds r0, r6, r5
	movs r1, #1
	strb r1, [r0]
	strb r3, [r2]
	ldr r1, _081BBE1C @ =0x000006B6
	adds r0, r7, r1
	strh r3, [r0]
	b _081BBEA0
	.align 2, 0
_081BBE14: .4byte 0x000006C3
_081BBE18: .4byte 0x0000046B
_081BBE1C: .4byte 0x000006B6
_081BBE20:
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	lsrs r0, r0, #7
	ldr r3, _081BBE48 @ =0x00000482
	adds r1, r6, r3
	strh r0, [r1]
	ldr r1, _081BBE4C @ =0x0000A02F
	ldr r5, [sp, #0x10]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081BBE50
	adds r1, r6, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081BBE60
	.align 2, 0
_081BBE48: .4byte 0x00000482
_081BBE4C: .4byte 0x0000A02F
_081BBE50:
	ldr r1, _081BBE84 @ =0x00000482
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081BBE60
	movs r0, #1
	strh r0, [r2]
_081BBE60:
	ldr r3, [sp, #0x14]
	ldrb r0, [r3]
	cmp r0, #0
	bne _081BBE88
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
	b _081BBEA0
	.align 2, 0
_081BBE84: .4byte 0x00000482
_081BBE88:
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
_081BBEA0:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081bbeb0
FUN_081bbeb0: @ 0x081BBEB0
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
	ldr r2, _081BBEDC @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BBEE0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BBEE2
	.align 2, 0
_081BBEDC: .4byte 0x0000046D
_081BBEE0:
	movs r0, #0
_081BBEE2:
	cmp r0, #0
	bne _081BBEE8
	b _081BBFEC
_081BBEE8:
	ldrb r5, [r6, #5]
	ldr r0, _081BBF44 @ =0x000006C5
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
	ldr r1, _081BBF48 @ =0x085ADFA8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _081BBF4C @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BBF58
	ldr r2, _081BBF50 @ =0x000004B7
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
	ldr r2, _081BBF54 @ =0x0000046E
	adds r7, r6, r2
	b _081BBFDA
	.align 2, 0
_081BBF44: .4byte 0x000006C5
_081BBF48: .4byte 0x085ADFA8
_081BBF4C: .4byte 0x0000025D
_081BBF50: .4byte 0x000004B7
_081BBF54: .4byte 0x0000046E
_081BBF58:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r3, #8
	mov ip, r3
	ldr r3, _081BBFC8 @ =0x000004B7
	adds r0, r6, r3
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r0, _081BBFCC @ =0x0000046E
	adds r7, r6, r0
	cmp r1, ip
	bne _081BBF94
	ldrb r0, [r7]
	cmp r0, #0
	bne _081BBF94
	cmp r4, #1
	bne _081BBF86
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081BBFDE
_081BBF86:
	cmp r4, #0
	bne _081BBF94
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081BBFDE
_081BBF94:
	mov r1, ip
	strb r1, [r2]
	movs r2, #4
	mov sb, r2
	adds r0, r4, #0
	ands r0, r2
	movs r3, #4
	cmp r0, #0
	beq _081BBFA8
	movs r3, #6
_081BBFA8:
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
	beq _081BBFD0
	ldr r0, [r5, #8]
	mov r3, sb
	orrs r0, r3
	b _081BBFD8
	.align 2, 0
_081BBFC8: .4byte 0x000004B7
_081BBFCC: .4byte 0x0000046E
_081BBFD0:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081BBFD8:
	str r0, [r5, #8]
_081BBFDA:
	movs r0, #0
	strb r0, [r7]
_081BBFDE:
	ldr r1, _081BC034 @ =0x0000046E
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, _081BC038 @ =0x000006C3
	add r0, r8
	strb r1, [r0]
_081BBFEC:
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
	ldr r2, _081BC03C @ =0x085B0A08
	ldr r0, _081BC040 @ =0x000006C5
	add r0, r8
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, _081BC044 @ =0x000006B6
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _081BC048
	asrs r0, r0, #0x10
	b _081BC04E
	.align 2, 0
_081BC034: .4byte 0x0000046E
_081BC038: .4byte 0x000006C3
_081BC03C: .4byte 0x085B0A08
_081BC040: .4byte 0x000006C5
_081BC044: .4byte 0x000006B6
_081BC048:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_081BC04E:
	adds r3, r0, #0
	ldr r0, _081BC070 @ =0x000006C5
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _081BC074 @ =0x000006B6
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _081BC078
	asrs r0, r0, #0x10
	b _081BC07E
	.align 2, 0
_081BC070: .4byte 0x000006C5
_081BC074: .4byte 0x000006B6
_081BC078:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_081BC07E:
	adds r2, r3, #0
	cmp r3, #0
	bge _081BC086
	rsbs r2, r3, #0
_081BC086:
	adds r1, r0, #0
	cmp r0, #0
	bge _081BC08E
	rsbs r1, r0, #0
_081BC08E:
	cmp r2, r1
	bge _081BC098
	mov r3, sl
	strh r0, [r3, #0x14]
	b _081BC09C
_081BC098:
	mov r0, sl
	strh r3, [r0, #0x10]
_081BC09C:
	ldr r2, _081BC0CC @ =0x000006B6
	add r2, r8
	ldrh r1, [r2]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bgt _081BC0D8
	movs r3, #0
	strh r3, [r2]
	ldr r1, _081BC0D0 @ =0x000006C3
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bls _081BC0DE
	ldr r0, _081BC0D4 @ =0x0000046B
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	strh r3, [r2]
	b _081BC0DE
	.align 2, 0
_081BC0CC: .4byte 0x000006B6
_081BC0D0: .4byte 0x000006C3
_081BC0D4: .4byte 0x0000046B
_081BC0D8:
	adds r0, r1, #0
	subs r0, #0x10
	strh r0, [r2]
_081BC0DE:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081bc0f0
FUN_081bc0f0: @ 0x081BC0F0
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
	ldr r2, _081BC11C @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BC120
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BC122
	.align 2, 0
_081BC11C: .4byte 0x0000046D
_081BC120:
	movs r0, #0
_081BC122:
	cmp r0, #0
	beq _081BC136
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r3, _081BC1E8 @ =0x0000046E
	adds r1, r4, r3
	movs r0, #0
	strb r0, [r1]
_081BC136:
	cmp r6, #0x3c
	bgt _081BC13C
	b _081BC2A4
_081BC13C:
	ldr r6, _081BC1E8 @ =0x0000046E
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BC148
	b _081BC2C0
_081BC148:
	ldr r1, _081BC1EC @ =0x0000046B
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
	beq _081BC208
	ldr r3, _081BC1F0 @ =0x000004A4
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
	ldr r3, _081BC1F4 @ =0x0000046D
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
	ldr r1, _081BC1F8 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _081BC1FC @ =0x00000484
	adds r0, r4, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	movs r0, #4
	ldr r6, _081BC200 @ =0x00000222
	adds r2, r4, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _081BC204 @ =0x00000482
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1]
	b _081BC2C0
	.align 2, 0
_081BC1E8: .4byte 0x0000046E
_081BC1EC: .4byte 0x0000046B
_081BC1F0: .4byte 0x000004A4
_081BC1F4: .4byte 0x0000046D
_081BC1F8: .4byte 0x0000046A
_081BC1FC: .4byte 0x00000484
_081BC200: .4byte 0x00000222
_081BC204: .4byte 0x00000482
_081BC208:
	movs r0, #0xd1
	lsls r0, r0, #3
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _081BC28C @ =0x0000068C
	add r0, r8
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl FUN_080e6304
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r1, _081BC290 @ =FUN_080e48d0
	movs r3, #0x10
	ldr r6, _081BC294 @ =0x0000046D
	adds r0, r4, r6
	strb r7, [r0]
	ldr r2, _081BC298 @ =0x0000046B
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
	ldr r1, _081BC29C @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _081BC2A0 @ =0x00000484
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
	bl FUN_081b8cd0
	b _081BC2C0
	.align 2, 0
_081BC28C: .4byte 0x0000068C
_081BC290: .4byte FUN_080e48d0
_081BC294: .4byte 0x0000046D
_081BC298: .4byte 0x0000046B
_081BC29C: .4byte 0x0000046A
_081BC2A0: .4byte 0x00000484
_081BC2A4:
	ldrh r0, [r5, #8]
	cmp r0, #2
	bne _081BC2C0
	ldrh r1, [r5, #0xe]
	ldrb r2, [r5, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _081BC2C0
	cmp r2, #1
	beq _081BC2C0
	movs r0, #0
	strh r0, [r5, #0xe]
_081BC2C0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081bc2cc
FUN_081bc2cc: @ 0x081BC2CC
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
	ldr r0, _081BC2F4 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BC2F8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BC2FA
	.align 2, 0
_081BC2F4: .4byte 0x0000046D
_081BC2F8:
	movs r0, #0
_081BC2FA:
	cmp r0, #0
	beq _081BC306
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_081BC306:
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	cmp r5, #0x13
	bgt _081BC332
	ldrh r3, [r4, #8]
	cmp r3, #0
	bne _081BC332
	ldrh r1, [r4, #0xe]
	ldrb r2, [r4, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _081BC332
	cmp r2, #1
	beq _081BC332
	strh r3, [r4, #0xe]
_081BC332:
	ldr r2, _081BC424 @ =0x0000046E
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BC340
	bl _081BCB20
_081BC340:
	ldr r3, _081BC428 @ =0x0000046B
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
	ldr r2, _081BC42C @ =0x00000469
	adds r2, r7, r2
	str r2, [sp, #0xc]
	strb r5, [r2]
	ldr r3, _081BC430 @ =0x0000046A
	adds r3, r7, r3
	str r3, [sp, #0x10]
	strb r4, [r3]
	ldr r5, _081BC434 @ =0x00000484
	adds r5, r5, r7
	mov ip, r5
	str r4, [r5]
	ldr r0, _081BC438 @ =0x0000046C
	adds r0, r0, r7
	mov sl, r0
	movs r1, #1
	strb r1, [r0]
	ldr r1, _081BC43C @ =FUN_080e6794
	movs r0, #0xe
	ldr r2, _081BC440 @ =0x0000046D
	adds r3, r7, r2
	movs r5, #1
	strb r5, [r3]
	subs r2, #2
	adds r2, r2, r7
	mov sb, r2
	strb r4, [r2]
	ldr r5, _081BC444 @ =0x00000553
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
	bne _081BC3E2
	b _081BC990
_081BC3E2:
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
	blt _081BC41E
	cmp r1, #0
	blt _081BC41E
	ldr r0, _081BC448 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081BC41E
	ldr r0, _081BC44C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BC450
_081BC41E:
	movs r4, #0
	b _081BC45E
	.align 2, 0
_081BC424: .4byte 0x0000046E
_081BC428: .4byte 0x0000046B
_081BC42C: .4byte 0x00000469
_081BC430: .4byte 0x0000046A
_081BC434: .4byte 0x00000484
_081BC438: .4byte 0x0000046C
_081BC43C: .4byte FUN_080e6794
_081BC440: .4byte 0x0000046D
_081BC444: .4byte 0x00000553
_081BC448: .4byte 0x030046A8
_081BC44C: .4byte 0x030046AC
_081BC450:
	ldr r0, _081BC470 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081BC45E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BC474
	adds r0, #4
	b _081BC480
	.align 2, 0
_081BC470: .4byte 0x030046A4
_081BC474:
	ldr r0, _081BC494 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BC480:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BC498
	cmp r2, #2
	beq _081BC49C
	b _081BC4A0
	.align 2, 0
_081BC494: .4byte 0x030046A4
_081BC498:
	ldrb r0, [r5, #4]
	b _081BC49E
_081BC49C:
	ldrb r0, [r5]
_081BC49E:
	subs r1, r1, r0
_081BC4A0:
	strh r1, [r5, #2]
	ldr r0, _081BC4B4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081BC4B8
	movs r0, #1
	b _081BC4BA
	.align 2, 0
_081BC4B4: .4byte 0x030047A4
_081BC4B8:
	movs r0, #0
_081BC4BA:
	cmp r0, #0
	beq _081BC4F8
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _081BC4DA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081BC4D6
	adds r2, r0, #0
_081BC4D6:
	cmp r2, #0
	bge _081BC4E4
_081BC4DA:
	ldr r3, _081BC4E0 @ =0x000005C4
	adds r0, r7, r3
	b _081BC938
	.align 2, 0
_081BC4E0: .4byte 0x000005C4
_081BC4E4:
	ldr r1, _081BC4F4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081BC540
	.align 2, 0
_081BC4F4: .4byte 0x03002BE0
_081BC4F8:
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
	blt _081BC524
	cmp r1, #0
	blt _081BC524
	ldr r0, _081BC528 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BC524
	ldr r0, _081BC52C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BC530
_081BC524:
	movs r5, #0
	b _081BC53E
	.align 2, 0
_081BC528: .4byte 0x030046A8
_081BC52C: .4byte 0x030046AC
_081BC530:
	ldr r0, _081BC578 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081BC53E:
	movs r2, #0
_081BC540:
	ldr r1, _081BC57C @ =0x00000256
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r5, r0
	beq _081BC560
	ldr r1, _081BC580 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081BC560
	b _081BC878
_081BC560:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081BC584
	movs r0, #0
	b _081BC94E
	.align 2, 0
_081BC578: .4byte 0x030046A4
_081BC57C: .4byte 0x00000256
_081BC580: .4byte 0x03002BE0
_081BC584:
	ldr r3, _081BC5E0 @ =0x00000222
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
	beq _081BC5E4
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
	b _081BC732
	.align 2, 0
_081BC5E0: .4byte 0x00000222
_081BC5E4:
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
	blt _081BC648
	cmp r1, #0
	blt _081BC648
	ldr r0, _081BC64C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BC648
	ldr r0, _081BC650 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BC654
_081BC648:
	movs r4, #0
	b _081BC662
	.align 2, 0
_081BC64C: .4byte 0x030046A8
_081BC650: .4byte 0x030046AC
_081BC654:
	ldr r0, _081BC674 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BC662:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BC678
	adds r0, #4
	b _081BC684
	.align 2, 0
_081BC674: .4byte 0x030046A4
_081BC678:
	ldr r0, _081BC698 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BC684:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BC69C
	cmp r2, #2
	beq _081BC6A0
	b _081BC6A4
	.align 2, 0
_081BC698: .4byte 0x030046A4
_081BC69C:
	ldrb r0, [r5, #4]
	b _081BC6A2
_081BC6A0:
	ldrb r0, [r5]
_081BC6A2:
	subs r1, r1, r0
_081BC6A4:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081BC6CC
	cmp r1, #0
	blt _081BC6CC
	ldr r0, _081BC6D0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BC6CC
	ldr r0, _081BC6D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BC6D8
_081BC6CC:
	movs r4, #0
	b _081BC6E6
	.align 2, 0
_081BC6D0: .4byte 0x030046A8
_081BC6D4: .4byte 0x030046AC
_081BC6D8:
	ldr r0, _081BC6F8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BC6E6:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BC6FC
	adds r0, #4
	b _081BC708
	.align 2, 0
_081BC6F8: .4byte 0x030046A4
_081BC6FC:
	ldr r0, _081BC71C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BC708:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081BC720
	cmp r3, #2
	beq _081BC724
	b _081BC728
	.align 2, 0
_081BC71C: .4byte 0x030046A4
_081BC720:
	ldrb r0, [r5, #4]
	b _081BC726
_081BC724:
	ldrb r0, [r5]
_081BC726:
	subs r2, r2, r0
_081BC728:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081BC732:
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
	bne _081BC83C
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081BC75C
	movs r0, #1
	b _081BC75E
_081BC75C:
	movs r0, #0
_081BC75E:
	ldr r3, _081BC84C @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x30]
	cmp r0, #0
	bne _081BC83C
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _081BC850 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081BC854 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x40]
	ldr r2, _081BC858 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x44]
	ldr r4, _081BC85C @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x48]
	ldr r5, _081BC860 @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x38]
	ldr r0, _081BC864 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x58]
	ldr r1, _081BC868 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	ldr r6, _081BC86C @ =0x0203B400
	ldr r1, _081BC870 @ =0x030046B8
	ldr r5, _081BC874 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_081BC7AE:
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
	bne _081BC7CC
	adds r3, #1
	cmp r3, #3
	ble _081BC7AE
	mov r0, r8
_081BC7CC:
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
_081BC83C:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r2, [sp, #0x30]
	strh r0, [r2]
	movs r0, #0
	b _081BC94E
	.align 2, 0
_081BC84C: .4byte 0x00000482
_081BC850: .4byte 0x0000054F
_081BC854: .4byte 0x0000054C
_081BC858: .4byte 0x0000054D
_081BC85C: .4byte 0x0000054E
_081BC860: .4byte 0x00000541
_081BC864: .4byte 0x000005BC
_081BC868: .4byte 0x00000542
_081BC86C: .4byte 0x0203B400
_081BC870: .4byte 0x030046B8
_081BC874: .4byte 0x000003FF
_081BC878:
	mov sb, sp
	ldr r6, _081BC8B4 @ =0x030046A4
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
	beq _081BC8B8
	adds r0, #4
	b _081BC8C2
	.align 2, 0
_081BC8B4: .4byte 0x030046A4
_081BC8B8:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081BC8C2:
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
	ldr r5, _081BC8FC @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081BC904
	ldr r0, _081BC900 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081BC92E
	.align 2, 0
_081BC8FC: .4byte 0x000004A4
_081BC900: .4byte 0xFFFFFDFF
_081BC904:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081BC924
	cmp r0, #2
	beq _081BC920
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BC920:
	movs r0, #1
	b _081BC930
_081BC924:
	ldr r0, _081BC944 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081BC92E:
	movs r0, #0
_081BC930:
	cmp r0, #0
	bne _081BC94C
	ldr r4, _081BC948 @ =0x000005C4
	adds r0, r7, r4
_081BC938:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081BC94E
	.align 2, 0
_081BC944: .4byte 0xFFFFFDFF
_081BC948: .4byte 0x000005C4
_081BC94C:
	movs r0, #1
_081BC94E:
	cmp r0, #0
	bne _081BC954
	b _081BCB20
_081BC954:
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
	ldr r2, _081BC988 @ =0x00000551
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _081BC98C @ =0x00000552
	adds r0, r7, r3
	strb r4, [r0]
	b _081BCB20
	.align 2, 0
_081BC988: .4byte 0x00000551
_081BC98C: .4byte 0x00000552
_081BC990:
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
	ldr r3, _081BCA10 @ =0x00000551
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
	ldr r1, _081BCA14 @ =0x00000482
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
	blt _081BCA0C
	cmp r1, #0
	blt _081BCA0C
	ldr r0, _081BCA18 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BCA0C
	ldr r0, _081BCA1C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BCA20
_081BCA0C:
	movs r4, #0
	b _081BCA2E
	.align 2, 0
_081BCA10: .4byte 0x00000551
_081BCA14: .4byte 0x00000482
_081BCA18: .4byte 0x030046A8
_081BCA1C: .4byte 0x030046AC
_081BCA20:
	ldr r0, _081BCA40 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BCA2E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BCA44
	adds r0, #4
	b _081BCA50
	.align 2, 0
_081BCA40: .4byte 0x030046A4
_081BCA44:
	ldr r0, _081BCA64 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BCA50:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BCA68
	cmp r2, #2
	beq _081BCA6C
	b _081BCA70
	.align 2, 0
_081BCA64: .4byte 0x030046A4
_081BCA68:
	ldrb r0, [r5, #4]
	b _081BCA6E
_081BCA6C:
	ldrb r0, [r5]
_081BCA6E:
	subs r1, r1, r0
_081BCA70:
	strh r1, [r5, #2]
	ldr r4, _081BCAA0 @ =0x000004A4
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
	bne _081BCAA8
	ldr r0, _081BCAA4 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081BCAD2
	.align 2, 0
_081BCAA0: .4byte 0x000004A4
_081BCAA4: .4byte 0xFFFFFDFF
_081BCAA8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081BCAC8
	cmp r0, #2
	beq _081BCAC4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BCAC4:
	movs r0, #1
	b _081BCAD4
_081BCAC8:
	ldr r0, _081BCB0C @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081BCAD2:
	movs r0, #0
_081BCAD4:
	adds r3, r0, #0
	cmp r3, #0
	bne _081BCB14
	ldr r0, _081BCB10 @ =FUN_080e48d0
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
	b _081BCB20
	.align 2, 0
_081BCB0C: .4byte 0xFFFFFDFF
_081BCB10: .4byte FUN_080e48d0
_081BCB14:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_081BCB20:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081bcb30
FUN_081bcb30: @ 0x081BCB30
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xbc
	adds r7, r0, #0
	ldr r0, _081BCB50 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BCB54
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BCB56
	.align 2, 0
_081BCB50: .4byte 0x0000046D
_081BCB54:
	movs r0, #0
_081BCB56:
	cmp r0, #0
	beq _081BCB8A
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
	beq _081BCB78
	ldr r0, _081BCBBC @ =0x0000018B
	bl PlaySound_082406e0
_081BCB78:
	movs r0, #0x20
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	ldr r1, _081BCBC0 @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r2]
_081BCB8A:
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
	blt _081BCBC4
	asrs r0, r0, #2
	b _081BCBCA
	.align 2, 0
_081BCBBC: .4byte 0x0000018B
_081BCBC0: .4byte 0xFFFFFEFF
_081BCBC4:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081BCBCA:
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
	blt _081BCBEA
	asrs r0, r0, #2
	b _081BCBF0
_081BCBEA:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081BCBF0:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _081BCBFA
	movs r3, #0xc8
	b _081BCC04
_081BCBFA:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _081BCC04
	adds r3, r0, #0
_081BCC04:
	cmp r2, #0xc8
	ble _081BCC0C
	movs r2, #0xc8
	b _081BCC16
_081BCC0C:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _081BCC16
	adds r2, r0, #0
_081BCC16:
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
	bne _081BCC3A
	cmp r2, #0
	bne _081BCC3A
	movs r0, #1
	b _081BCC3C
_081BCC3A:
	movs r0, #0
_081BCC3C:
	cmp r0, #0
	bne _081BCC44
	bl FUN_081bdb58
_081BCC44:
	ldr r6, _081BCCD0 @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BCC52
	bl FUN_081bdb58
_081BCC52:
	ldr r1, _081BCCD4 @ =0x0000046B
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
	beq _081BCCEC
	ldr r2, _081BCCD8 @ =0x00000594
	adds r0, r7, r2
	ldr r2, [r0]
	movs r1, #7
	ldr r3, _081BCCDC @ =0x0000046D
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
	ldr r1, _081BCCE0 @ =0x00000469
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081BCCE4 @ =0x0000046A
	adds r0, r7, r2
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r7, r3
	str r6, [r0]
	ldr r4, _081BCCE8 @ =0x0000046C
	adds r0, r7, r4
	strb r5, [r0]
	bl _081BDB68
	.align 2, 0
_081BCCD0: .4byte 0x0000046E
_081BCCD4: .4byte 0x0000046B
_081BCCD8: .4byte 0x00000594
_081BCCDC: .4byte 0x0000046D
_081BCCE0: .4byte 0x00000469
_081BCCE4: .4byte 0x0000046A
_081BCCE8: .4byte 0x0000046C
_081BCCEC:
	movs r2, #0x80
	adds r0, r3, #0
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _081BCCFC
	b _081BD41C
_081BCCFC:
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #4
	ldr r6, _081BCD64 @ =0x00000222
	adds r3, r7, r6
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _081BCD68 @ =0x03002BE0
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
	blt _081BCD60
	cmp r1, #0
	blt _081BCD60
	ldr r0, _081BCD6C @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _081BCD60
	ldr r0, _081BCD70 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BCD74
_081BCD60:
	movs r4, #0
	b _081BCD82
	.align 2, 0
_081BCD64: .4byte 0x00000222
_081BCD68: .4byte 0x03002BE0
_081BCD6C: .4byte 0x030046A8
_081BCD70: .4byte 0x030046AC
_081BCD74:
	ldr r0, _081BCD94 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_081BCD82:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BCD98
	adds r0, #4
	b _081BCDA4
	.align 2, 0
_081BCD94: .4byte 0x030046A4
_081BCD98:
	ldr r0, _081BCDB8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BCDA4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BCDBC
	cmp r2, #2
	beq _081BCDC0
	b _081BCDC4
	.align 2, 0
_081BCDB8: .4byte 0x030046A4
_081BCDBC:
	ldrb r0, [r6, #4]
	b _081BCDC2
_081BCDC0:
	ldrb r0, [r6]
_081BCDC2:
	subs r1, r1, r0
_081BCDC4:
	strh r1, [r6, #2]
	ldr r0, _081BCDD8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081BCDDC
	movs r0, #1
	b _081BCDDE
	.align 2, 0
_081BCDD8: .4byte 0x030047A4
_081BCDDC:
	movs r0, #0
_081BCDDE:
	cmp r0, #0
	beq _081BCE1C
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _081BCDFE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081BCDFA
	adds r2, r0, #0
_081BCDFA:
	cmp r2, #0
	bge _081BCE08
_081BCDFE:
	ldr r3, _081BCE04 @ =0x000005C4
	adds r0, r7, r3
	b _081BD32C
	.align 2, 0
_081BCE04: .4byte 0x000005C4
_081BCE08:
	ldr r1, _081BCE18 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081BCE64
	.align 2, 0
_081BCE18: .4byte 0x03002BE0
_081BCE1C:
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
	blt _081BCE48
	cmp r1, #0
	blt _081BCE48
	ldr r0, _081BCE4C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BCE48
	ldr r0, _081BCE50 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BCE54
_081BCE48:
	movs r5, #0
	b _081BCE62
	.align 2, 0
_081BCE4C: .4byte 0x030046A8
_081BCE50: .4byte 0x030046AC
_081BCE54:
	ldr r0, _081BCE9C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081BCE62:
	movs r2, #0
_081BCE64:
	ldr r6, _081BCEA0 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081BCE84
	ldr r1, _081BCEA4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081BCE84
	b _081BD26C
_081BCE84:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x98]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _081BCEA8
	movs r0, #0
	b _081BD342
	.align 2, 0
_081BCE9C: .4byte 0x030046A4
_081BCEA0: .4byte 0x00000256
_081BCEA4: .4byte 0x03002BE0
_081BCEA8:
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
	beq _081BCF5C
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081BCF48 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x10]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _081BCF4C @ =0x0000046B
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
	ldr r6, _081BCF50 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081BCF54 @ =0x00000484
	adds r1, r7, r0
	mov r6, sb
	str r6, [r1]
	ldr r6, _081BCF58 @ =0x0000046C
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
	b _081BD12A
	.align 2, 0
_081BCF48: .4byte 0x0000046D
_081BCF4C: .4byte 0x0000046B
_081BCF50: .4byte 0x00000469
_081BCF54: .4byte 0x00000484
_081BCF58: .4byte 0x0000046C
_081BCF5C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _081BD01C @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	strb r0, [r3]
	ldr r4, _081BD020 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x20]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _081BD024 @ =0x00000553
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
	ldr r3, _081BD028 @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _081BD02C @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _081BD030 @ =0x00000484
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
	blt _081BD018
	cmp r1, #0
	blt _081BD018
	ldr r0, _081BD034 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _081BD018
	ldr r0, _081BD038 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BD03C
_081BD018:
	movs r4, #0
	b _081BD04C
	.align 2, 0
_081BD01C: .4byte 0x0000046D
_081BD020: .4byte 0x0000046B
_081BD024: .4byte 0x00000553
_081BD028: .4byte 0x00000469
_081BD02C: .4byte 0x0000046A
_081BD030: .4byte 0x00000484
_081BD034: .4byte 0x030046A8
_081BD038: .4byte 0x030046AC
_081BD03C:
	ldr r0, _081BD05C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_081BD04C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BD060
	adds r0, #4
	b _081BD06C
	.align 2, 0
_081BD05C: .4byte 0x030046A4
_081BD060:
	ldr r0, _081BD080 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BD06C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BD084
	cmp r2, #2
	beq _081BD08A
	b _081BD090
	.align 2, 0
_081BD080: .4byte 0x030046A4
_081BD084:
	ldr r2, [sp, #0x34]
	ldrb r0, [r2, #4]
	b _081BD08E
_081BD08A:
	ldr r3, [sp, #0x34]
	ldrb r0, [r3]
_081BD08E:
	subs r1, r1, r0
_081BD090:
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
	blt _081BD0BC
	cmp r1, #0
	blt _081BD0BC
	ldr r0, _081BD0C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BD0BC
	ldr r0, _081BD0C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BD0C8
_081BD0BC:
	movs r4, #0
	b _081BD0D6
	.align 2, 0
_081BD0C0: .4byte 0x030046A8
_081BD0C4: .4byte 0x030046AC
_081BD0C8:
	ldr r0, _081BD0EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BD0D6:
	ldr r6, [sp, #0x94]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BD0F0
	adds r0, #4
	b _081BD0FC
	.align 2, 0
_081BD0EC: .4byte 0x030046A4
_081BD0F0:
	ldr r0, _081BD110 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BD0FC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081BD114
	cmp r3, #2
	beq _081BD118
	b _081BD11C
	.align 2, 0
_081BD110: .4byte 0x030046A4
_081BD114:
	ldrb r0, [r5, #4]
	b _081BD11A
_081BD118:
	ldrb r0, [r5]
_081BD11A:
	subs r2, r2, r0
_081BD11C:
	ldr r1, [sp, #0x94]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x94]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081BD12A:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x38]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _081BD154 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	cmp r0, #0
	bne _081BD234
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081BD158
	movs r0, #1
	b _081BD15A
	.align 2, 0
_081BD154: .4byte 0x00000482
_081BD158:
	movs r0, #0
_081BD15A:
	ldr r1, _081BD244 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	cmp r0, #0
	bne _081BD234
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r0, _081BD248 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081BD24C @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _081BD250 @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r0, _081BD254 @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081BD258 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb4]
	ldr r2, _081BD25C @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa0]
	ldr r1, _081BD260 @ =0x030046B8
	adds r2, r4, #0
_081BD1A2:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081BD264 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081BD268 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081BD1C6
	adds r3, #1
	cmp r3, #3
	ble _081BD1A2
	adds r0, r4, #0
_081BD1C6:
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
_081BD234:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x8c]
	strh r0, [r5]
	movs r0, #0
	b _081BD342
	.align 2, 0
_081BD244: .4byte 0x00000482
_081BD248: .4byte 0x0000054F
_081BD24C: .4byte 0x0000054C
_081BD250: .4byte 0x0000054E
_081BD254: .4byte 0x00000541
_081BD258: .4byte 0x000005BC
_081BD25C: .4byte 0x00000542
_081BD260: .4byte 0x030046B8
_081BD264: .4byte 0x000003FF
_081BD268: .4byte 0x0203B400
_081BD26C:
	mov sb, sp
	ldr r6, _081BD2A8 @ =0x030046A4
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
	beq _081BD2AC
	adds r0, #4
	b _081BD2B6
	.align 2, 0
_081BD2A8: .4byte 0x030046A4
_081BD2AC:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081BD2B6:
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
	ldr r6, _081BD2F0 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081BD2F8
	ldr r0, _081BD2F4 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081BD322
	.align 2, 0
_081BD2F0: .4byte 0x000004A4
_081BD2F4: .4byte 0xFFFFFDFF
_081BD2F8:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081BD318
	cmp r0, #2
	beq _081BD314
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BD314:
	movs r0, #1
	b _081BD324
_081BD318:
	ldr r0, _081BD338 @ =0xFFFFFDFF
	ldr r3, [sp, #0x98]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081BD322:
	movs r0, #0
_081BD324:
	cmp r0, #0
	bne _081BD340
	ldr r4, _081BD33C @ =0x000005C4
	adds r0, r7, r4
_081BD32C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081BD342
	.align 2, 0
_081BD338: .4byte 0xFFFFFDFF
_081BD33C: .4byte 0x000005C4
_081BD340:
	movs r0, #1
_081BD342:
	cmp r0, #0
	bne _081BD3B2
	ldr r5, _081BD378 @ =0x000004A4
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
	bne _081BD380
	ldr r0, _081BD37C @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081BD3AA
	.align 2, 0
_081BD378: .4byte 0x000004A4
_081BD37C: .4byte 0xFFFFFDFF
_081BD380:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081BD3A0
	cmp r0, #2
	beq _081BD39C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BD39C:
	movs r0, #1
	b _081BD3AC
_081BD3A0:
	ldr r0, _081BD408 @ =0xFFFFFDFF
	ldr r3, [sp, #0x98]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081BD3AA:
	movs r0, #0
_081BD3AC:
	cmp r0, #0
	bne _081BD3B2
	b _081BDAD0
_081BD3B2:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _081BD40C @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _081BD410 @ =0x0000046B
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
	ldr r1, _081BD414 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _081BD418 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _081BDB68
	.align 2, 0
_081BD408: .4byte 0xFFFFFDFF
_081BD40C: .4byte 0x0000046D
_081BD410: .4byte 0x0000046B
_081BD414: .4byte 0x0000046A
_081BD418: .4byte 0x00000484
_081BD41C:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _081BD480 @ =0x03002BE0
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
	blt _081BD47A
	cmp r1, #0
	blt _081BD47A
	ldr r0, _081BD484 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _081BD47A
	ldr r0, _081BD488 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BD48C
_081BD47A:
	movs r4, #0
	b _081BD49A
	.align 2, 0
_081BD480: .4byte 0x03002BE0
_081BD484: .4byte 0x030046A8
_081BD488: .4byte 0x030046AC
_081BD48C:
	ldr r0, _081BD4AC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_081BD49A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BD4B0
	adds r0, #4
	b _081BD4BC
	.align 2, 0
_081BD4AC: .4byte 0x030046A4
_081BD4B0:
	ldr r0, _081BD4D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BD4BC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BD4D4
	cmp r2, #2
	beq _081BD4D8
	b _081BD4DC
	.align 2, 0
_081BD4D0: .4byte 0x030046A4
_081BD4D4:
	ldrb r0, [r6, #4]
	b _081BD4DA
_081BD4D8:
	ldrb r0, [r6]
_081BD4DA:
	subs r1, r1, r0
_081BD4DC:
	strh r1, [r6, #2]
	ldr r0, _081BD4F0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081BD4F4
	movs r0, #1
	b _081BD4F6
	.align 2, 0
_081BD4F0: .4byte 0x030047A4
_081BD4F4:
	movs r0, #0
_081BD4F6:
	cmp r0, #0
	beq _081BD52C
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	bne _081BD508
	b _081BDA48
_081BD508:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081BD514
	adds r2, r0, #0
_081BD514:
	cmp r2, #0
	bge _081BD51A
	b _081BDA48
_081BD51A:
	ldr r1, _081BD528 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081BD574
	.align 2, 0
_081BD528: .4byte 0x03002BE0
_081BD52C:
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
	blt _081BD558
	cmp r1, #0
	blt _081BD558
	ldr r0, _081BD55C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BD558
	ldr r0, _081BD560 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BD564
_081BD558:
	movs r5, #0
	b _081BD572
	.align 2, 0
_081BD55C: .4byte 0x030046A8
_081BD560: .4byte 0x030046AC
_081BD564:
	ldr r0, _081BD5AC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081BD572:
	movs r2, #0
_081BD574:
	ldr r6, _081BD5B0 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081BD594
	ldr r1, _081BD5B4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081BD594
	b _081BD988
_081BD594:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x98]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x3c]
	cmp r0, #0
	beq _081BD5B8
	movs r0, #0
	b _081BDA62
	.align 2, 0
_081BD5AC: .4byte 0x030046A4
_081BD5B0: .4byte 0x00000256
_081BD5B4: .4byte 0x03002BE0
_081BD5B8:
	ldr r3, _081BD65C @ =0x00000222
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
	beq _081BD674
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081BD660 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x40]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _081BD664 @ =0x0000046B
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
	ldr r6, _081BD668 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081BD66C @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x3c]
	str r6, [r1]
	ldr r6, _081BD670 @ =0x0000046C
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
	b _081BD846
	.align 2, 0
_081BD65C: .4byte 0x00000222
_081BD660: .4byte 0x0000046D
_081BD664: .4byte 0x0000046B
_081BD668: .4byte 0x00000469
_081BD66C: .4byte 0x00000484
_081BD670: .4byte 0x0000046C
_081BD674:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081BD738 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x50]
	strb r0, [r2]
	ldr r3, _081BD73C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x54]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081BD740 @ =0x00000553
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
	ldr r2, _081BD744 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081BD748 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081BD74C @ =0x0000046C
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
	blt _081BD732
	cmp r1, #0
	blt _081BD732
	ldr r0, _081BD750 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _081BD732
	ldr r0, _081BD754 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BD758
_081BD732:
	movs r4, #0
	b _081BD768
	.align 2, 0
_081BD738: .4byte 0x0000046D
_081BD73C: .4byte 0x0000046B
_081BD740: .4byte 0x00000553
_081BD744: .4byte 0x00000469
_081BD748: .4byte 0x00000484
_081BD74C: .4byte 0x0000046C
_081BD750: .4byte 0x030046A8
_081BD754: .4byte 0x030046AC
_081BD758:
	ldr r0, _081BD778 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_081BD768:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BD77C
	adds r0, #4
	b _081BD788
	.align 2, 0
_081BD778: .4byte 0x030046A4
_081BD77C:
	ldr r0, _081BD79C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BD788:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BD7A0
	cmp r2, #2
	beq _081BD7A6
	b _081BD7AC
	.align 2, 0
_081BD79C: .4byte 0x030046A4
_081BD7A0:
	ldr r2, [sp, #0x68]
	ldrb r0, [r2, #4]
	b _081BD7AA
_081BD7A6:
	ldr r3, [sp, #0x68]
	ldrb r0, [r3]
_081BD7AA:
	subs r1, r1, r0
_081BD7AC:
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
	blt _081BD7D8
	cmp r1, #0
	blt _081BD7D8
	ldr r0, _081BD7DC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BD7D8
	ldr r0, _081BD7E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BD7E4
_081BD7D8:
	movs r4, #0
	b _081BD7F2
	.align 2, 0
_081BD7DC: .4byte 0x030046A8
_081BD7E0: .4byte 0x030046AC
_081BD7E4:
	ldr r0, _081BD808 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BD7F2:
	ldr r6, [sp, #0x94]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BD80C
	adds r0, #4
	b _081BD818
	.align 2, 0
_081BD808: .4byte 0x030046A4
_081BD80C:
	ldr r0, _081BD82C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BD818:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081BD830
	cmp r3, #2
	beq _081BD834
	b _081BD838
	.align 2, 0
_081BD82C: .4byte 0x030046A4
_081BD830:
	ldrb r0, [r5, #4]
	b _081BD836
_081BD834:
	ldrb r0, [r5]
_081BD836:
	subs r2, r2, r0
_081BD838:
	ldr r1, [sp, #0x94]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x94]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081BD846:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x6c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _081BD870 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	cmp r0, #0
	bne _081BD950
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081BD874
	movs r0, #1
	b _081BD876
	.align 2, 0
_081BD870: .4byte 0x00000482
_081BD874:
	movs r0, #0
_081BD876:
	ldr r1, _081BD960 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	cmp r0, #0
	bne _081BD950
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r0, _081BD964 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081BD968 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _081BD96C @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r0, _081BD970 @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081BD974 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb4]
	ldr r2, _081BD978 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa0]
	ldr r1, _081BD97C @ =0x030046B8
	adds r2, r4, #0
_081BD8BE:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081BD980 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081BD984 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081BD8E2
	adds r3, #1
	cmp r3, #3
	ble _081BD8BE
	adds r0, r4, #0
_081BD8E2:
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
_081BD950:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x8c]
	strh r0, [r5]
	movs r0, #0
	b _081BDA62
	.align 2, 0
_081BD960: .4byte 0x00000482
_081BD964: .4byte 0x0000054F
_081BD968: .4byte 0x0000054C
_081BD96C: .4byte 0x0000054E
_081BD970: .4byte 0x00000541
_081BD974: .4byte 0x000005BC
_081BD978: .4byte 0x00000542
_081BD97C: .4byte 0x030046B8
_081BD980: .4byte 0x000003FF
_081BD984: .4byte 0x0203B400
_081BD988:
	add r6, sp, #8
	ldr r0, _081BD9C8 @ =0x030046A4
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
	beq _081BD9CC
	adds r0, #4
	b _081BD9D8
	.align 2, 0
_081BD9C8: .4byte 0x030046A4
_081BD9CC:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081BD9D8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081BDA10 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _081BDA18
	ldr r0, _081BDA14 @ =0xFFFFFDFF
	ldr r6, [sp, #0x98]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081BDA42
	.align 2, 0
_081BDA10: .4byte 0x000004A4
_081BDA14: .4byte 0xFFFFFDFF
_081BDA18:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081BDA38
	cmp r0, #2
	beq _081BDA34
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BDA34:
	movs r0, #1
	b _081BDA44
_081BDA38:
	ldr r0, _081BDA58 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081BDA42:
	movs r0, #0
_081BDA44:
	cmp r0, #0
	bne _081BDA60
_081BDA48:
	ldr r3, _081BDA5C @ =0x000005C4
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081BDA62
	.align 2, 0
_081BDA58: .4byte 0xFFFFFDFF
_081BDA5C: .4byte 0x000005C4
_081BDA60:
	movs r0, #1
_081BDA62:
	cmp r0, #0
	bne _081BDAE8
	ldr r4, _081BDA98 @ =0x000004A4
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
	bne _081BDAA0
	ldr r0, _081BDA9C @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081BDACA
	.align 2, 0
_081BDA98: .4byte 0x000004A4
_081BDA9C: .4byte 0xFFFFFDFF
_081BDAA0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081BDAC0
	cmp r0, #2
	beq _081BDABC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BDABC:
	movs r0, #1
	b _081BDACC
_081BDAC0:
	ldr r0, _081BDAE0 @ =0xFFFFFDFF
	ldr r3, [sp, #0x98]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081BDACA:
	movs r0, #0
_081BDACC:
	cmp r0, #0
	bne _081BDAE8
_081BDAD0:
	ldr r4, _081BDAE4 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081BDB68
	.align 2, 0
_081BDAE0: .4byte 0xFFFFFDFF
_081BDAE4: .4byte 0x000005C4
_081BDAE8:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081BDB44 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081BDB48 @ =0x0000046B
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
	ldr r6, _081BDB4C @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081BDB50 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081BDB54 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
	b _081BDB68
	.align 2, 0
_081BDB44: .4byte 0x0000046D
_081BDB48: .4byte 0x0000046B
_081BDB4C: .4byte 0x00000469
_081BDB50: .4byte 0x0000046A
_081BDB54: .4byte 0x00000484

	thumb_func_start FUN_081bdb58
FUN_081bdb58: @ 0x081BDB58
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081BDB68:
	add sp, #0xbc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081bdb78
FUN_081bdb78: @ 0x081BDB78
	bx lr
	.align 2, 0

	thumb_func_start FUN_081bdb7c
FUN_081bdb7c: @ 0x081BDB7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r7, r0, #0
	ldr r0, _081BDB9C @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BDBA0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BDBA2
	.align 2, 0
_081BDB9C: .4byte 0x0000046D
_081BDBA0:
	movs r0, #0
_081BDBA2:
	cmp r0, #0
	beq _081BDC18
	adds r0, r7, #0
	movs r1, #0xa
	bl FUN_080ef86c
	ldr r1, _081BDCC0 @ =0x0000046E
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
	ldr r1, _081BDCC4 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _081BDCC8 @ =0x0000021E
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
_081BDC18:
	adds r0, r7, #0
	bl FUN_080e499c
	ldr r1, _081BDCC0 @ =0x0000046E
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BDC2A
	b _081BDF32
_081BDC2A:
	ldr r2, _081BDCCC @ =0x0000046B
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
	beq _081BDC96
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
	ldr r1, _081BDCD0 @ =0xFFFF0000
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
_081BDC96:
	ldr r1, _081BDCD4 @ =0x000001DF
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
	bgt _081BDCDC
	ldr r0, _081BDCD8 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r1, r5, #0
	lsls r1, r3
	b _081BDCEE
	.align 2, 0
_081BDCC0: .4byte 0x0000046E
_081BDCC4: .4byte 0xFFFEBE3F
_081BDCC8: .4byte 0x0000021E
_081BDCCC: .4byte 0x0000046B
_081BDCD0: .4byte 0xFFFF0000
_081BDCD4: .4byte 0x000001DF
_081BDCD8: .4byte 0x030046A0
_081BDCDC:
	ldr r0, _081BDEF0 @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r5, #0
	lsls r1, r0
_081BDCEE:
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
	beq _081BDD08
	b _081BDE84
_081BDD08:
	ldr r2, _081BDEF4 @ =0xFFFF0000
	ldr r0, [sp, #0x38]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _081BDEF8 @ =0x0000FFFF
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
	ldr r4, _081BDEFC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081BDF00 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081BDF04 @ =0x0203B400
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
	ldr r1, _081BDF00 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081BDF04 @ =0x0203B400
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
	ldr r1, _081BDF00 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081BDF04 @ =0x0203B400
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
	ldr r1, _081BDF00 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081BDF04 @ =0x0203B400
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
	ldr r1, _081BDF00 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081BDF04 @ =0x0203B400
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
	ldr r1, _081BDF00 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081BDF04 @ =0x0203B400
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
	beq _081BDE7E
	cmp r4, #1
	beq _081BDE7E
	cmp r4, #5
	beq _081BDE7E
	cmp r4, #7
	beq _081BDE7E
	cmp r4, #6
	beq _081BDE7E
	cmp r4, #0x18
	bne _081BDE84
_081BDE7E:
	movs r0, #0xe5
	bl PlaySound_082406e0
_081BDE84:
	ldr r3, _081BDF08 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r5, _081BDF0C @ =0x0000046D
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
	ldr r2, _081BDF10 @ =0x0000046A
	adds r0, r7, r2
	strb r3, [r0]
	adds r5, #0x1b
	adds r0, r7, r5
	str r1, [r0]
	ldr r1, _081BDF14 @ =0x0000046C
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r7, r2
	bl FUN_080136b4
	ldr r5, _081BDF18 @ =0x0000025D
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BDF1C
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	b _081BDF26
	.align 2, 0
_081BDEF0: .4byte 0x030046A0
_081BDEF4: .4byte 0xFFFF0000
_081BDEF8: .4byte 0x0000FFFF
_081BDEFC: .4byte 0x030046B8
_081BDF00: .4byte 0x000003FF
_081BDF04: .4byte 0x0203B400
_081BDF08: .4byte FUN_080e48d0
_081BDF0C: .4byte 0x0000046D
_081BDF10: .4byte 0x0000046A
_081BDF14: .4byte 0x0000046C
_081BDF18: .4byte 0x0000025D
_081BDF1C:
	ldr r1, [r7, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r4
	str r0, [r1, #8]
_081BDF26:
	adds r0, r7, #0
	bl FUN_080f8ae0
	adds r0, r7, #0
	bl FUN_080e8360
_081BDF32:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081bdf44
FUN_081bdf44: @ 0x081BDF44
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081BDF5C @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BDF60
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BDF62
	.align 2, 0
_081BDF5C: .4byte 0x0000046C
_081BDF60:
	movs r0, #0
_081BDF62:
	cmp r0, #0
	beq _081BDFE0
	ldr r4, _081BDFF4 @ =FUN_080f3cdc
	movs r3, #0xa
	ldr r2, _081BDFF8 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081BDFFC @ =0x0000046B
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
	ldr r2, _081BE000 @ =0x000001DF
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _081BDFC4
	movs r0, #4
	ldr r1, _081BE004 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081BDFC4:
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
_081BDFE0:
	ldr r1, _081BDFFC @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081BE008
	adds r0, r5, #0
	bl enemy_golem_081b8df4
	b _081BE012
	.align 2, 0
_081BDFF4: .4byte FUN_080f3cdc
_081BDFF8: .4byte 0x0000046D
_081BDFFC: .4byte 0x0000046B
_081BE000: .4byte 0x000001DF
_081BE004: .4byte 0x00000222
_081BE008:
	ldr r2, _081BE018 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081BE012:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081BE018: .4byte 0x00000484

	thumb_func_start FUN_081be01c
FUN_081be01c: @ 0x081BE01C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r7, r0, #0
	ldr r0, _081BE180 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BE038
	movs r0, #0
	strb r0, [r1]
_081BE038:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081BE050
	bl _081BE836
_081BE050:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _081BE062
	bl _081BE836
_081BE062:
	ldr r2, _081BE184 @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _081BE070
	bl FUN_081be832
_081BE070:
	ldr r3, _081BE188 @ =0x000001DF
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
	ldr r5, _081BE18C @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	strb r1, [r5]
	ldr r0, _081BE190 @ =0x0000046A
	adds r0, r7, r0
	str r0, [sp, #0x10]
	strb r6, [r0]
	ldr r2, _081BE184 @ =0x00000484
	adds r2, r2, r7
	mov sl, r2
	str r6, [r2]
	ldr r3, _081BE180 @ =0x0000046C
	adds r3, r3, r7
	mov ip, r3
	strb r1, [r3]
	ldr r2, _081BE194 @ =FUN_080e6794
	movs r0, #0xe
	ldr r4, _081BE198 @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	strb r1, [r4]
	ldr r5, _081BE19C @ =0x0000046B
	adds r5, r5, r7
	mov r8, r5
	strb r6, [r5]
	ldr r1, _081BE1A0 @ =0x00000553
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
	bne _081BE10E
	b _081BE6A8
_081BE10E:
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
	ldr r3, _081BE1A4 @ =0x00000551
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
	blt _081BE17A
	cmp r1, #0
	blt _081BE17A
	ldr r0, _081BE1A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081BE17A
	ldr r0, _081BE1AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BE1B0
_081BE17A:
	movs r4, #0
	b _081BE1BE
	.align 2, 0
_081BE180: .4byte 0x0000046C
_081BE184: .4byte 0x00000484
_081BE188: .4byte 0x000001DF
_081BE18C: .4byte 0x00000469
_081BE190: .4byte 0x0000046A
_081BE194: .4byte FUN_080e6794
_081BE198: .4byte 0x0000046D
_081BE19C: .4byte 0x0000046B
_081BE1A0: .4byte 0x00000553
_081BE1A4: .4byte 0x00000551
_081BE1A8: .4byte 0x030046A8
_081BE1AC: .4byte 0x030046AC
_081BE1B0:
	ldr r0, _081BE1D0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081BE1BE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BE1D4
	adds r0, #4
	b _081BE1E0
	.align 2, 0
_081BE1D0: .4byte 0x030046A4
_081BE1D4:
	ldr r0, _081BE1F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BE1E0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BE1F8
	cmp r2, #2
	beq _081BE1FC
	b _081BE200
	.align 2, 0
_081BE1F4: .4byte 0x030046A4
_081BE1F8:
	ldrb r0, [r5, #4]
	b _081BE1FE
_081BE1FC:
	ldrb r0, [r5]
_081BE1FE:
	subs r1, r1, r0
_081BE200:
	strh r1, [r5, #2]
	ldr r0, _081BE214 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081BE218
	movs r0, #1
	b _081BE21A
	.align 2, 0
_081BE214: .4byte 0x030047A4
_081BE218:
	movs r0, #0
_081BE21A:
	cmp r0, #0
	beq _081BE258
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081BE23A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081BE236
	adds r2, r0, #0
_081BE236:
	cmp r2, #0
	bge _081BE244
_081BE23A:
	ldr r2, _081BE240 @ =0x000005C4
	adds r0, r7, r2
	b _081BE696
	.align 2, 0
_081BE240: .4byte 0x000005C4
_081BE244:
	ldr r1, _081BE254 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081BE2A0
	.align 2, 0
_081BE254: .4byte 0x03002BE0
_081BE258:
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
	blt _081BE284
	cmp r1, #0
	blt _081BE284
	ldr r0, _081BE288 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BE284
	ldr r0, _081BE28C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BE290
_081BE284:
	movs r5, #0
	b _081BE29E
	.align 2, 0
_081BE288: .4byte 0x030046A8
_081BE28C: .4byte 0x030046AC
_081BE290:
	ldr r0, _081BE330 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081BE29E:
	movs r2, #0
_081BE2A0:
	ldr r4, _081BE334 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081BE2C0
	ldr r1, _081BE338 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081BE2C0
	b _081BE5D4
_081BE2C0:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081BE2D4
	b _081BE836
_081BE2D4:
	ldr r0, _081BE33C @ =0x00000222
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
	beq _081BE340
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
	b _081BE48E
	.align 2, 0
_081BE330: .4byte 0x030046A4
_081BE334: .4byte 0x00000256
_081BE338: .4byte 0x03002BE0
_081BE33C: .4byte 0x00000222
_081BE340:
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
	blt _081BE3A4
	cmp r1, #0
	blt _081BE3A4
	ldr r0, _081BE3A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BE3A4
	ldr r0, _081BE3AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BE3B0
_081BE3A4:
	movs r4, #0
	b _081BE3BE
	.align 2, 0
_081BE3A8: .4byte 0x030046A8
_081BE3AC: .4byte 0x030046AC
_081BE3B0:
	ldr r0, _081BE3D0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BE3BE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BE3D4
	adds r0, #4
	b _081BE3E0
	.align 2, 0
_081BE3D0: .4byte 0x030046A4
_081BE3D4:
	ldr r0, _081BE3F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BE3E0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BE3F8
	cmp r2, #2
	beq _081BE3FC
	b _081BE400
	.align 2, 0
_081BE3F4: .4byte 0x030046A4
_081BE3F8:
	ldrb r0, [r5, #4]
	b _081BE3FE
_081BE3FC:
	ldrb r0, [r5]
_081BE3FE:
	subs r1, r1, r0
_081BE400:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081BE428
	cmp r1, #0
	blt _081BE428
	ldr r0, _081BE42C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BE428
	ldr r0, _081BE430 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BE434
_081BE428:
	movs r4, #0
	b _081BE442
	.align 2, 0
_081BE42C: .4byte 0x030046A8
_081BE430: .4byte 0x030046AC
_081BE434:
	ldr r0, _081BE454 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BE442:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BE458
	adds r0, #4
	b _081BE464
	.align 2, 0
_081BE454: .4byte 0x030046A4
_081BE458:
	ldr r0, _081BE478 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BE464:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081BE47C
	cmp r3, #2
	beq _081BE480
	b _081BE484
	.align 2, 0
_081BE478: .4byte 0x030046A4
_081BE47C:
	ldrb r0, [r5, #4]
	b _081BE482
_081BE480:
	ldrb r0, [r5]
_081BE482:
	subs r2, r2, r0
_081BE484:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081BE48E:
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
	bne _081BE598
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081BE4B8
	movs r0, #1
	b _081BE4BA
_081BE4B8:
	movs r0, #0
_081BE4BA:
	ldr r3, _081BE5A8 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x30]
	cmp r0, #0
	bne _081BE598
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _081BE5AC @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081BE5B0 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r2, _081BE5B4 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x48]
	ldr r4, _081BE5B8 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	ldr r5, _081BE5BC @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x38]
	ldr r0, _081BE5C0 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x58]
	ldr r1, _081BE5C4 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	ldr r6, _081BE5C8 @ =0x0203B400
	ldr r1, _081BE5CC @ =0x030046B8
	ldr r5, _081BE5D0 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_081BE50A:
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
	bne _081BE528
	adds r3, #1
	cmp r3, #3
	ble _081BE50A
	mov r0, r8
_081BE528:
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
_081BE598:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r2, [sp, #0x30]
	strh r0, [r2]
	b _081BE836
	.align 2, 0
_081BE5A8: .4byte 0x00000482
_081BE5AC: .4byte 0x0000054F
_081BE5B0: .4byte 0x0000054C
_081BE5B4: .4byte 0x0000054D
_081BE5B8: .4byte 0x0000054E
_081BE5BC: .4byte 0x00000541
_081BE5C0: .4byte 0x000005BC
_081BE5C4: .4byte 0x00000542
_081BE5C8: .4byte 0x0203B400
_081BE5CC: .4byte 0x030046B8
_081BE5D0: .4byte 0x000003FF
_081BE5D4:
	mov sb, sp
	ldr r6, _081BE610 @ =0x030046A4
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
	beq _081BE614
	adds r0, #4
	b _081BE61E
	.align 2, 0
_081BE610: .4byte 0x030046A4
_081BE614:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081BE61E:
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
	ldr r5, _081BE658 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081BE660
	ldr r0, _081BE65C @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081BE68A
	.align 2, 0
_081BE658: .4byte 0x000004A4
_081BE65C: .4byte 0xFFFFFDFF
_081BE660:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081BE680
	cmp r0, #2
	beq _081BE67C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BE67C:
	movs r0, #1
	b _081BE68C
_081BE680:
	ldr r0, _081BE6A0 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081BE68A:
	movs r0, #0
_081BE68C:
	cmp r0, #0
	beq _081BE692
	b _081BE836
_081BE692:
	ldr r4, _081BE6A4 @ =0x000005C4
	adds r0, r7, r4
_081BE696:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081BE836
	.align 2, 0
_081BE6A0: .4byte 0xFFFFFDFF
_081BE6A4: .4byte 0x000005C4
_081BE6A8:
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r3, _081BE71C @ =FUN_081b9df8
	movs r4, #7
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _081BE720 @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081BE724 @ =0x00000551
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
	blt _081BE716
	cmp r1, #0
	blt _081BE716
	ldr r0, _081BE728 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BE716
	ldr r0, _081BE72C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BE730
_081BE716:
	movs r4, #0
	b _081BE73E
	.align 2, 0
_081BE71C: .4byte FUN_081b9df8
_081BE720: .4byte 0x00000554
_081BE724: .4byte 0x00000551
_081BE728: .4byte 0x030046A8
_081BE72C: .4byte 0x030046AC
_081BE730:
	ldr r0, _081BE750 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BE73E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BE754
	adds r0, #4
	b _081BE760
	.align 2, 0
_081BE750: .4byte 0x030046A4
_081BE754:
	ldr r0, _081BE774 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BE760:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BE778
	cmp r2, #2
	beq _081BE77C
	b _081BE780
	.align 2, 0
_081BE774: .4byte 0x030046A4
_081BE778:
	ldrb r0, [r5, #4]
	b _081BE77E
_081BE77C:
	ldrb r0, [r5]
_081BE77E:
	subs r1, r1, r0
_081BE780:
	strh r1, [r5, #2]
	ldr r2, _081BE7B0 @ =0x000004A4
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
	bne _081BE7B8
	ldr r0, _081BE7B4 @ =0xFFFFFDFF
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	b _081BE7E2
	.align 2, 0
_081BE7B0: .4byte 0x000004A4
_081BE7B4: .4byte 0xFFFFFDFF
_081BE7B8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081BE7D8
	cmp r0, #2
	beq _081BE7D4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BE7D4:
	movs r0, #1
	b _081BE7E4
_081BE7D8:
	ldr r0, _081BE81C @ =0xFFFFFDFF
	mov r5, sl
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_081BE7E2:
	movs r0, #0
_081BE7E4:
	adds r3, r0, #0
	cmp r3, #0
	bne _081BE824
	ldr r0, _081BE820 @ =FUN_080e48d0
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
	b _081BE836
	.align 2, 0
_081BE81C: .4byte 0xFFFFFDFF
_081BE820: .4byte FUN_080e48d0
_081BE824:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _081BE836

	non_word_aligned_thumb_func_start FUN_081be832
FUN_081be832: @ 0x081BE832
	adds r0, #1
	str r0, [r1]
_081BE836:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081be848
FUN_081be848: @ 0x081BE848
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _081BE854 @ =0x085ADFAC
	str r1, [r0]
	bx lr
	.align 2, 0
_081BE854: .4byte 0x085ADFAC

	thumb_func_start FUN_081be858
FUN_081be858: @ 0x081BE858
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
	ldr r2, _081BE880 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BE884
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BE886
	.align 2, 0
_081BE880: .4byte 0x0000046C
_081BE884:
	movs r0, #0
_081BE886:
	cmp r0, #0
	beq _081BE8CC
	ldr r4, _081BE924 @ =FUN_081ba950
	movs r3, #0x24
	ldr r6, _081BE928 @ =0x0000046D
	adds r1, r5, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081BE92C @ =0x0000046B
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
	ldr r3, _081BE92C @ =0x0000046B
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _081BE930 @ =0x000006BC
	adds r0, r7, r6
	strh r2, [r0]
_081BE8CC:
	adds r0, r5, #0
	bl FUN_081b916c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081BE8DA
	b _081BEB5A
_081BE8DA:
	ldr r1, _081BE92C @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BE8E6
	b _081BEB50
_081BE8E6:
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
	blt _081BE91E
	cmp r1, #0
	blt _081BE91E
	ldr r0, _081BE934 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BE91E
	ldr r0, _081BE938 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BE93C
_081BE91E:
	movs r4, #0
	b _081BE94A
	.align 2, 0
_081BE924: .4byte FUN_081ba950
_081BE928: .4byte 0x0000046D
_081BE92C: .4byte 0x0000046B
_081BE930: .4byte 0x000006BC
_081BE934: .4byte 0x030046A8
_081BE938: .4byte 0x030046AC
_081BE93C:
	ldr r0, _081BE960 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BE94A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BE964
	adds r0, #4
	ldr r3, _081BE960 @ =0x030046A4
	mov sl, r3
	b _081BE972
	.align 2, 0
_081BE960: .4byte 0x030046A4
_081BE964:
	ldr r2, _081BE988 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
	mov sl, r2
_081BE972:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r3, r0, #8
	cmp r2, #1
	beq _081BE98C
	cmp r2, #2
	beq _081BE990
	b _081BE994
	.align 2, 0
_081BE988: .4byte 0x030046A4
_081BE98C:
	ldrb r0, [r6, #4]
	b _081BE992
_081BE990:
	ldrb r0, [r6]
_081BE992:
	subs r3, r3, r0
_081BE994:
	movs r1, #0
	movs r2, #0
	strh r3, [r6, #2]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r0, [r0]
	strh r2, [r0, #6]
	ldr r3, _081BEA20 @ =0x000006C1
	adds r0, r7, r3
	strb r1, [r0]
	ldr r6, _081BEA24 @ =0x000006B4
	adds r1, r7, r6
	movs r0, #0x78
	strh r0, [r1]
	ldr r1, _081BEA28 @ =0x000006BA
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
	ldr r2, _081BEA2C @ =0x00000256
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
	beq _081BEA30
	adds r0, #4
	b _081BEA3C
	.align 2, 0
_081BEA20: .4byte 0x000006C1
_081BEA24: .4byte 0x000006B4
_081BEA28: .4byte 0x000006BA
_081BEA2C: .4byte 0x00000256
_081BEA30:
	mov r3, sl
	ldr r0, [r3]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081BEA3C:
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
	bl FUN_081b86b4
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
	ldr r0, _081BEA9C @ =0x000008FF
	cmp r1, r0
	bgt _081BEAA0
	adds r0, r7, #0
	bl FUN_081b86d8
	b _081BEAE6
	.align 2, 0
_081BEA9C: .4byte 0x000008FF
_081BEAA0:
	ldr r1, _081BEB34 @ =0x000004A4
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
	ldr r2, _081BEB38 @ =0x000006C2
	adds r1, r7, r2
	strb r0, [r1]
_081BEAE6:
	ldr r2, _081BEB3C @ =FUN_081baca8
	movs r1, #0x22
	ldr r3, _081BEB40 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081BEB44 @ =0x0000046B
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
	ldr r1, _081BEB48 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _081BEB4C @ =0x0000046A
	adds r0, r5, r2
	strb r4, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r3, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	b _081BEB5A
	.align 2, 0
_081BEB34: .4byte 0x000004A4
_081BEB38: .4byte 0x000006C2
_081BEB3C: .4byte FUN_081baca8
_081BEB40: .4byte 0x0000046D
_081BEB44: .4byte 0x0000046B
_081BEB48: .4byte 0x00000469
_081BEB4C: .4byte 0x0000046A
_081BEB50:
	ldr r2, _081BEB6C @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081BEB5A:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081BEB6C: .4byte 0x00000484

	thumb_func_start FUN_081beb70
FUN_081beb70: @ 0x081BEB70
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081BEB88 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BEB8C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BEB8E
	.align 2, 0
_081BEB88: .4byte 0x0000046C
_081BEB8C:
	movs r0, #0
_081BEB8E:
	cmp r0, #0
	beq _081BEBC4
	ldr r4, _081BEC28 @ =FUN_081ba9d4
	movs r3, #0x21
	ldr r2, _081BEC2C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _081BEC30 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _081BEC34 @ =0x00000553
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
	ldr r2, _081BEC30 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
_081BEBC4:
	adds r0, r5, #0
	bl FUN_081b916c
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _081BEC4E
	ldr r3, _081BEC30 @ =0x0000046B
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081BEC44
	ldr r2, _081BEC38 @ =FUN_081baca8
	movs r1, #0x22
	ldr r6, _081BEC2C @ =0x0000046D
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
	ldr r1, _081BEC3C @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _081BEC40 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r4, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r3, [r0]
	b _081BEC4E
	.align 2, 0
_081BEC28: .4byte FUN_081ba9d4
_081BEC2C: .4byte 0x0000046D
_081BEC30: .4byte 0x0000046B
_081BEC34: .4byte 0x00000553
_081BEC38: .4byte FUN_081baca8
_081BEC3C: .4byte 0x00000469
_081BEC40: .4byte 0x0000046A
_081BEC44:
	ldr r2, _081BEC54 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081BEC4E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081BEC54: .4byte 0x00000484

	thumb_func_start FUN_081bec58
FUN_081bec58: @ 0x081BEC58
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
	ldr r3, _081BEC84 @ =0x0000046C
	adds r1, r2, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BEC88
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BEC8A
	.align 2, 0
_081BEC84: .4byte 0x0000046C
_081BEC88:
	movs r0, #0
_081BEC8A:
	cmp r0, #0
	beq _081BEC96
	ldr r4, _081BECE0 @ =0x00000659
	adds r1, r7, r4
	movs r0, #1
	strb r0, [r1]
_081BEC96:
	ldr r0, [sp, #0x18]
	bl FUN_081b916c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081BECA6
	bl _081BFCB2
_081BECA6:
	ldr r6, _081BECE0 @ =0x00000659
	adds r5, r7, r6
	ldrb r0, [r5]
	cmp r0, #1
	bne _081BECC6
	ldr r1, _081BECE4 @ =0x000006B6
	adds r0, r7, r1
	movs r2, #0
	ldrsh r4, [r0, r2]
	cmp r4, #0
	bne _081BECC6
	ldr r0, [sp, #0x18]
	movs r1, #4
	bl FUN_080e81dc
	strb r4, [r5]
_081BECC6:
	ldr r0, [sp, #0x18]
	bl FUN_081b90a0
	ldr r0, _081BECE8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081BECEC
	movs r0, #1
	b _081BECEE
	.align 2, 0
_081BECE0: .4byte 0x00000659
_081BECE4: .4byte 0x000006B6
_081BECE8: .4byte 0x030047A4
_081BECEC:
	movs r0, #0
_081BECEE:
	cmp r0, #0
	beq _081BED58
	ldr r3, [sp, #0x18]
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r3, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081BEDA8
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081BED0C
	adds r2, r0, #0
_081BED0C:
	cmp r2, #0
	blt _081BEDA8
	ldr r1, _081BED38 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081BEDA8
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r5, _081BED3C @ =0x0000065C
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081BED40
	movs r0, #1
	b _081BED42
	.align 2, 0
_081BED38: .4byte 0x03002BE0
_081BED3C: .4byte 0x0000065C
_081BED40:
	movs r0, #0
_081BED42:
	adds r5, r0, #0
	cmp r5, #0
	bne _081BEDA8
	ldr r6, _081BED54 @ =0x000006B4
	adds r1, r7, r6
	ldrh r0, [r1]
	subs r0, #0x1e
	movs r4, #0
	b _081BF136
	.align 2, 0
_081BED54: .4byte 0x000006B4
_081BED58:
	ldr r0, _081BED7C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081BEDA8
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r2, _081BED80 @ =0x0000065C
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081BED84
	movs r0, #1
	b _081BED86
	.align 2, 0
_081BED7C: .4byte 0x03002BE0
_081BED80: .4byte 0x0000065C
_081BED84:
	movs r0, #0
_081BED86:
	adds r5, r0, #0
	cmp r5, #0
	bne _081BEDA8
	ldr r3, _081BEDA0 @ =0x000006B4
	adds r1, r7, r3
	ldrh r0, [r1]
	subs r0, #0x1e
	movs r4, #0
	strh r0, [r1]
	ldr r6, _081BEDA4 @ =0x000006C4
	adds r0, r7, r6
	b _081BF13C
	.align 2, 0
_081BEDA0: .4byte 0x000006B4
_081BEDA4: .4byte 0x000006C4
_081BEDA8:
	ldr r2, [sp, #0x18]
	ldr r3, _081BEE54 @ =0x000004A4
	adds r0, r2, r3
	ldr r2, [r0]
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _081BEDC0
	b _081BF2DC
_081BEDC0:
	ldr r4, _081BEE58 @ =0x000006B6
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
	bl FUN_081b8438
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081BEDE2
	b _081BF1C0
_081BEDE2:
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
	ldr r5, _081BEE5C @ =0x000006C2
	adds r2, r7, r5
	ldr r6, _081BEE60 @ =0x00000659
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
	ble _081BEE68
	ldr r0, _081BEE64 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081BEE76
	.align 2, 0
_081BEE54: .4byte 0x000004A4
_081BEE58: .4byte 0x000006B6
_081BEE5C: .4byte 0x000006C2
_081BEE60: .4byte 0x00000659
_081BEE64: .4byte 0xFFFFFF00
_081BEE68:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081BEE76
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081BEE76:
	cmp r1, #0
	bge _081BEE7C
	rsbs r1, r1, #0
_081BEE7C:
	cmp r1, #0xf
	bgt _081BEEB8
	ldr r0, _081BEEA8 @ =0x0000FFFE
	cmp r3, r0
	bgt _081BEEB8
	ldr r3, _081BEEAC @ =0x000006B6
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0xc7
	ble _081BEEB8
	ldr r5, _081BEEB0 @ =0x000006B4
	adds r1, r7, r5
	ldrh r0, [r1]
	subs r0, #0x1e
	movs r4, #0
	movs r5, #0
	strh r0, [r1]
	ldr r6, _081BEEB4 @ =0x000006C4
	adds r0, r7, r6
	b _081BF13C
	.align 2, 0
_081BEEA8: .4byte 0x0000FFFE
_081BEEAC: .4byte 0x000006B6
_081BEEB0: .4byte 0x000006B4
_081BEEB4: .4byte 0x000006C4
_081BEEB8:
	ldr r2, _081BEEDC @ =0x000006C2
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
	ble _081BEEE4
	ldr r0, _081BEEE0 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081BEEF2
	.align 2, 0
_081BEEDC: .4byte 0x000006C2
_081BEEE0: .4byte 0xFFFFFF00
_081BEEE4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081BEEF2
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081BEEF2:
	adds r0, r1, #0
	cmp r0, #0
	bge _081BEEFA
	rsbs r0, r0, #0
_081BEEFA:
	cmp r0, #0xf
	bgt _081BEFA0
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
	blt _081BEF28
	cmp r1, #0
	blt _081BEF28
	ldr r0, _081BEF2C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BEF28
	ldr r0, _081BEF30 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BEF34
_081BEF28:
	movs r5, #0
	b _081BEF42
	.align 2, 0
_081BEF2C: .4byte 0x030046A8
_081BEF30: .4byte 0x030046AC
_081BEF34:
	ldr r0, _081BEF54 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081BEF42:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BEF58
	adds r0, #4
	b _081BEF64
	.align 2, 0
_081BEF54: .4byte 0x030046A4
_081BEF58:
	ldr r0, _081BEF98 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BEF64:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	ldr r4, _081BEF9C @ =0x000006C2
	adds r0, r7, r4
	ldrb r0, [r0]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r4, r0, #6
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_081b855c
	cmp r0, #0
	bne _081BEF90
	movs r5, #0xda
	lsls r5, r5, #3
	adds r0, r7, r5
	adds r1, r4, #0
	bl FUN_081b8664
_081BEF90:
	adds r0, r7, #0
	bl FUN_081b86d8
	b _081BEFAC
	.align 2, 0
_081BEF98: .4byte 0x030046A4
_081BEF9C: .4byte 0x000006C2
_081BEFA0:
	subs r0, #0x34
	cmp r0, #0x18
	bhi _081BEFAC
	adds r0, r7, #0
	bl FUN_081b86d8
_081BEFAC:
	ldr r1, _081BEFC4 @ =0x000006C4
	adds r0, r7, r1
	ldrb r1, [r0]
	ldr r2, _081BEFC8 @ =0x000006C2
	adds r0, r7, r2
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081BEFD0
	ldr r3, _081BEFCC @ =0xFFFFFF00
	adds r1, r1, r3
	b _081BEFDE
	.align 2, 0
_081BEFC4: .4byte 0x000006C4
_081BEFC8: .4byte 0x000006C2
_081BEFCC: .4byte 0xFFFFFF00
_081BEFD0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081BEFDE
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
_081BEFDE:
	cmp r1, #0
	bge _081BEFE4
	rsbs r1, r1, #0
_081BEFE4:
	cmp r1, #0x1f
	ble _081BF058
	ldr r5, _081BF03C @ =0x000006C4
	adds r2, r7, r5
	ldrb r1, [r2]
	ldr r6, _081BF040 @ =0x000006C5
	adds r0, r7, r6
	movs r4, #0
	strb r1, [r0]
	ldrb r0, [r2]
	strb r0, [r7, #5]
	ldr r0, _081BF044 @ =0x000006B4
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0xa
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _081BF00E
	b _081BF430
_081BF00E:
	ldr r2, _081BF048 @ =FUN_081baed4
	movs r1, #0x26
	ldr r3, _081BF04C @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _081BF050 @ =0x0000046B
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, _081BF054 @ =0x00000553
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
	b _081BF46E
	.align 2, 0
_081BF03C: .4byte 0x000006C4
_081BF040: .4byte 0x000006C5
_081BF044: .4byte 0x000006B4
_081BF048: .4byte FUN_081baed4
_081BF04C: .4byte 0x0000046D
_081BF050: .4byte 0x0000046B
_081BF054: .4byte 0x00000553
_081BF058:
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
	ldr r0, _081BF0BC @ =0x0000FFFE
	cmp r3, r0
	bgt _081BF12A
	ldr r1, _081BF0C0 @ =0x000006B6
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xc7
	ble _081BF12A
	ldr r0, _081BF0C4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081BF0C8
	movs r0, #1
	b _081BF0CA
	.align 2, 0
_081BF0BC: .4byte 0x0000FFFE
_081BF0C0: .4byte 0x000006B6
_081BF0C4: .4byte 0x030047A4
_081BF0C8:
	movs r0, #0
_081BF0CA:
	cmp r0, #0
	beq _081BF110
	ldr r3, [sp, #0x18]
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r3, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081BF12A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081BF0E8
	adds r2, r0, #0
_081BF0E8:
	cmp r2, #0
	blt _081BF12A
	ldr r1, _081BF108 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081BF12A
	ldr r5, _081BF10C @ =0x000006BC
	adds r1, r7, r5
	b _081BF124
	.align 2, 0
_081BF108: .4byte 0x03002BE0
_081BF10C: .4byte 0x000006BC
_081BF110:
	ldr r0, _081BF194 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081BF12A
	ldr r6, _081BF198 @ =0x000006BC
	adds r1, r7, r6
_081BF124:
	movs r0, #0xc8
	lsls r0, r0, #1
	strh r0, [r1]
_081BF12A:
	ldr r0, _081BF19C @ =0x000006B4
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0x1e
	movs r4, #0
	movs r5, #0
_081BF136:
	strh r0, [r1]
	ldr r1, _081BF1A0 @ =0x000006C4
	adds r0, r7, r1
_081BF13C:
	ldrb r1, [r0]
	ldr r2, _081BF1A4 @ =0x000006C5
	adds r0, r7, r2
	strb r1, [r0]
	movs r1, #2
	movs r2, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r4, [r0]
	ldr r6, _081BF1A8 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081BF1AC @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _081BF1B0 @ =0x00000484
	adds r0, r7, r2
	str r5, [r0]
	adds r3, #4
	adds r0, r7, r3
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081BF1B4 @ =FUN_081bbeb0
	movs r2, #0x2a
	adds r6, #4
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081BF1B8 @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081BF1BC @ =0x00000553
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
	bl _081BFCB2
	.align 2, 0
_081BF194: .4byte 0x03002BE0
_081BF198: .4byte 0x000006BC
_081BF19C: .4byte 0x000006B4
_081BF1A0: .4byte 0x000006C4
_081BF1A4: .4byte 0x000006C5
_081BF1A8: .4byte 0x00000469
_081BF1AC: .4byte 0x0000046A
_081BF1B0: .4byte 0x00000484
_081BF1B4: .4byte FUN_081bbeb0
_081BF1B8: .4byte 0x0000046B
_081BF1BC: .4byte 0x00000553
_081BF1C0:
	ldr r2, [sp, #0x18]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r1, [r0]
	ldr r4, _081BF1DC @ =0x000006C2
	adds r0, r7, r4
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081BF1E4
	ldr r5, _081BF1E0 @ =0xFFFFFF00
	adds r1, r1, r5
	b _081BF1F2
	.align 2, 0
_081BF1DC: .4byte 0x000006C2
_081BF1E0: .4byte 0xFFFFFF00
_081BF1E4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081BF1F2
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r1, r6
_081BF1F2:
	cmp r1, #0
	bge _081BF1F8
	rsbs r1, r1, #0
_081BF1F8:
	cmp r1, #0xf
	bgt _081BF22A
	ldr r1, [sp, #0x18]
	ldr r2, _081BF244 @ =0x00000256
	adds r0, r1, r2
	movs r3, #0x96
	lsls r3, r3, #2
	adds r1, r1, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _081BF22A
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
	bl FUN_081b86d8
_081BF22A:
	ldr r6, _081BF248 @ =0x000006C4
	adds r0, r7, r6
	ldrb r1, [r0]
	ldr r2, _081BF24C @ =0x000006C2
	adds r0, r7, r2
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081BF254
	ldr r3, _081BF250 @ =0xFFFFFF00
	adds r1, r1, r3
	b _081BF262
	.align 2, 0
_081BF244: .4byte 0x00000256
_081BF248: .4byte 0x000006C4
_081BF24C: .4byte 0x000006C2
_081BF250: .4byte 0xFFFFFF00
_081BF254:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081BF262
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
_081BF262:
	cmp r1, #0
	bge _081BF268
	rsbs r1, r1, #0
_081BF268:
	cmp r1, #0x1f
	bgt _081BF26E
	b _081BF4A0
_081BF26E:
	ldr r5, _081BF2C0 @ =0x000006C4
	adds r2, r7, r5
	ldrb r1, [r2]
	ldr r6, _081BF2C4 @ =0x000006C5
	adds r0, r7, r6
	movs r4, #0
	strb r1, [r0]
	ldrb r0, [r2]
	strb r0, [r7, #5]
	ldr r0, _081BF2C8 @ =0x000006B4
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0xa
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _081BF294
	b _081BF430
_081BF294:
	ldr r2, _081BF2CC @ =FUN_081baed4
	movs r1, #0x26
	ldr r3, _081BF2D0 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _081BF2D4 @ =0x0000046B
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, _081BF2D8 @ =0x00000553
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
	b _081BF46E
	.align 2, 0
_081BF2C0: .4byte 0x000006C4
_081BF2C4: .4byte 0x000006C5
_081BF2C8: .4byte 0x000006B4
_081BF2CC: .4byte FUN_081baed4
_081BF2D0: .4byte 0x0000046D
_081BF2D4: .4byte 0x0000046B
_081BF2D8: .4byte 0x00000553
_081BF2DC:
	ldr r3, _081BF318 @ =0x000006B6
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp, #0x18]
	adds r1, r2, #0
	movs r2, #0x18
	movs r3, #0x18
	bl FUN_081b8438
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081BF31C
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
	bl FUN_081b86d8
	b _081BF386
	.align 2, 0
_081BF318: .4byte 0x000006B6
_081BF31C:
	ldr r1, [sp, #0x18]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r1, [r0]
	ldr r3, _081BF338 @ =0x000006C2
	adds r0, r7, r3
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081BF340
	ldr r4, _081BF33C @ =0xFFFFFF00
	adds r1, r1, r4
	b _081BF34E
	.align 2, 0
_081BF338: .4byte 0x000006C2
_081BF33C: .4byte 0xFFFFFF00
_081BF340:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081BF34E
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r1, r5
_081BF34E:
	cmp r1, #0
	bge _081BF354
	rsbs r1, r1, #0
_081BF354:
	cmp r1, #0xf
	bgt _081BF386
	ldr r6, [sp, #0x18]
	ldr r1, _081BF3A0 @ =0x00000256
	adds r0, r6, r1
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r6, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _081BF386
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
	bl FUN_081b86d8
_081BF386:
	ldr r5, _081BF3A4 @ =0x000006C4
	adds r0, r7, r5
	ldrb r1, [r0]
	ldr r6, _081BF3A8 @ =0x000006C2
	adds r0, r7, r6
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081BF3B0
	ldr r0, _081BF3AC @ =0xFFFFFF00
	adds r1, r1, r0
	b _081BF3BE
	.align 2, 0
_081BF3A0: .4byte 0x00000256
_081BF3A4: .4byte 0x000006C4
_081BF3A8: .4byte 0x000006C2
_081BF3AC: .4byte 0xFFFFFF00
_081BF3B0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081BF3BE
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081BF3BE:
	cmp r1, #0
	bge _081BF3C4
	rsbs r1, r1, #0
_081BF3C4:
	cmp r1, #0x1f
	ble _081BF4A0
	ldr r3, _081BF418 @ =0x000006C4
	adds r2, r7, r3
	ldrb r1, [r2]
	ldr r4, _081BF41C @ =0x000006C5
	adds r0, r7, r4
	movs r4, #0
	strb r1, [r0]
	ldrb r0, [r2]
	strb r0, [r7, #5]
	ldr r5, _081BF420 @ =0x000006B4
	adds r1, r7, r5
	ldrh r0, [r1]
	subs r0, #0xa
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _081BF430
	ldr r2, _081BF424 @ =FUN_081baed4
	movs r1, #0x26
	ldr r6, _081BF428 @ =0x0000046D
	adds r0, r7, r6
	movs r3, #1
	strb r3, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, _081BF42C @ =0x00000553
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
	b _081BF46E
	.align 2, 0
_081BF418: .4byte 0x000006C4
_081BF41C: .4byte 0x000006C5
_081BF420: .4byte 0x000006B4
_081BF424: .4byte FUN_081baed4
_081BF428: .4byte 0x0000046D
_081BF42C: .4byte 0x00000553
_081BF430:
	movs r0, #0xda
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r1, _081BF484 @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _081BF488 @ =FUN_081bb00c
	movs r1, #0x25
	ldr r3, _081BF48C @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _081BF490 @ =0x0000046B
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, _081BF494 @ =0x00000553
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
_081BF46E:
	ldr r2, _081BF498 @ =0x0000046A
	adds r0, r7, r2
	strb r1, [r0]
	subs r5, #0xcf
	adds r0, r7, r5
	str r4, [r0]
	ldr r6, _081BF49C @ =0x0000046C
	adds r0, r7, r6
	strb r3, [r0]
	bl _081BFCB2
	.align 2, 0
_081BF484: .4byte 0x000004A4
_081BF488: .4byte FUN_081bb00c
_081BF48C: .4byte 0x0000046D
_081BF490: .4byte 0x0000046B
_081BF494: .4byte 0x00000553
_081BF498: .4byte 0x0000046A
_081BF49C: .4byte 0x0000046C
_081BF4A0:
	ldr r1, _081BF5D0 @ =0x000006B4
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _081BF4B0
	bl _081BFC9C
_081BF4B0:
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
	ldr r5, _081BF5D4 @ =0x00000469
	adds r5, r3, r5
	str r5, [sp, #0x20]
	movs r6, #1
	strb r6, [r5]
	ldr r0, _081BF5D8 @ =0x0000046A
	adds r3, r3, r0
	mov ip, r3
	strb r1, [r3]
	ldr r2, [sp, #0x18]
	ldr r3, _081BF5DC @ =0x00000484
	adds r2, r2, r3
	mov sl, r2
	str r1, [r2]
	ldr r4, [sp, #0x18]
	ldr r5, _081BF5E0 @ =0x0000046C
	adds r6, r4, r5
	movs r0, #1
	strb r0, [r6]
	ldr r2, _081BF5E4 @ =FUN_080e6794
	movs r0, #0xe
	subs r3, #0x17
	adds r4, r4, r3
	mov sb, r4
	movs r5, #1
	strb r5, [r4]
	ldr r3, [sp, #0x18]
	ldr r4, _081BF5E8 @ =0x0000046B
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
	ldr r0, _081BF5EC @ =0xFFFFFEFF
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
	bne _081BF55A
	b _081BFB30
_081BF55A:
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
	ldr r3, _081BF5F0 @ =0x00000551
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
	blt _081BF5CA
	cmp r1, #0
	blt _081BF5CA
	ldr r0, _081BF5F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081BF5CA
	ldr r0, _081BF5F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BF5FC
_081BF5CA:
	movs r4, #0
	b _081BF60A
	.align 2, 0
_081BF5D0: .4byte 0x000006B4
_081BF5D4: .4byte 0x00000469
_081BF5D8: .4byte 0x0000046A
_081BF5DC: .4byte 0x00000484
_081BF5E0: .4byte 0x0000046C
_081BF5E4: .4byte FUN_080e6794
_081BF5E8: .4byte 0x0000046B
_081BF5EC: .4byte 0xFFFFFEFF
_081BF5F0: .4byte 0x00000551
_081BF5F4: .4byte 0x030046A8
_081BF5F8: .4byte 0x030046AC
_081BF5FC:
	ldr r0, _081BF61C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081BF60A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BF620
	adds r0, #4
	b _081BF62C
	.align 2, 0
_081BF61C: .4byte 0x030046A4
_081BF620:
	ldr r0, _081BF640 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BF62C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BF644
	cmp r2, #2
	beq _081BF648
	b _081BF64C
	.align 2, 0
_081BF640: .4byte 0x030046A4
_081BF644:
	ldrb r0, [r5, #4]
	b _081BF64A
_081BF648:
	ldrb r0, [r5]
_081BF64A:
	subs r1, r1, r0
_081BF64C:
	strh r1, [r5, #2]
	ldr r0, _081BF660 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081BF664
	movs r0, #1
	b _081BF666
	.align 2, 0
_081BF660: .4byte 0x030047A4
_081BF664:
	movs r0, #0
_081BF666:
	cmp r0, #0
	beq _081BF6AC
	ldr r1, [sp, #0x18]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _081BF688
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081BF684
	adds r2, r0, #0
_081BF684:
	cmp r2, #0
	bge _081BF698
_081BF688:
	ldr r3, [sp, #0x18]
	ldr r4, _081BF694 @ =0x000005C4
	adds r0, r3, r4
	ldr r1, [r0]
	adds r0, r3, #0
	b _081BFB06
	.align 2, 0
_081BF694: .4byte 0x000005C4
_081BF698:
	ldr r1, _081BF6A8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081BF6F8
	.align 2, 0
_081BF6A8: .4byte 0x03002BE0
_081BF6AC:
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
	blt _081BF6DA
	cmp r1, #0
	blt _081BF6DA
	ldr r0, _081BF6E0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BF6DA
	ldr r0, _081BF6E4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BF6E8
_081BF6DA:
	movs r5, #0
	b _081BF6F6
	.align 2, 0
_081BF6E0: .4byte 0x030046A8
_081BF6E4: .4byte 0x030046AC
_081BF6E8:
	ldr r0, _081BF730 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081BF6F6:
	movs r2, #0
_081BF6F8:
	ldr r3, [sp, #0x18]
	ldr r4, _081BF734 @ =0x00000256
	adds r0, r3, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081BF71A
	ldr r1, _081BF738 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081BF71A
	b _081BFA3C
_081BF71A:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081BF73C
	movs r0, #0
	b _081BFB1A
	.align 2, 0
_081BF730: .4byte 0x030046A4
_081BF734: .4byte 0x00000256
_081BF738: .4byte 0x03002BE0
_081BF73C:
	ldr r0, [sp, #0x18]
	ldr r1, _081BF79C @ =0x00000222
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
	beq _081BF7A0
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
	b _081BF8F2
	.align 2, 0
_081BF79C: .4byte 0x00000222
_081BF7A0:
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
	blt _081BF806
	cmp r1, #0
	blt _081BF806
	ldr r0, _081BF80C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BF806
	ldr r0, _081BF810 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BF814
_081BF806:
	movs r4, #0
	b _081BF822
	.align 2, 0
_081BF80C: .4byte 0x030046A8
_081BF810: .4byte 0x030046AC
_081BF814:
	ldr r0, _081BF834 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BF822:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BF838
	adds r0, #4
	b _081BF844
	.align 2, 0
_081BF834: .4byte 0x030046A4
_081BF838:
	ldr r0, _081BF858 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BF844:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BF85C
	cmp r2, #2
	beq _081BF860
	b _081BF864
	.align 2, 0
_081BF858: .4byte 0x030046A4
_081BF85C:
	ldrb r0, [r5, #4]
	b _081BF862
_081BF860:
	ldrb r0, [r5]
_081BF862:
	subs r1, r1, r0
_081BF864:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081BF88C
	cmp r1, #0
	blt _081BF88C
	ldr r0, _081BF890 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BF88C
	ldr r0, _081BF894 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BF898
_081BF88C:
	movs r4, #0
	b _081BF8A6
	.align 2, 0
_081BF890: .4byte 0x030046A8
_081BF894: .4byte 0x030046AC
_081BF898:
	ldr r0, _081BF8B8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BF8A6:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BF8BC
	adds r0, #4
	b _081BF8C8
	.align 2, 0
_081BF8B8: .4byte 0x030046A4
_081BF8BC:
	ldr r0, _081BF8DC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BF8C8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081BF8E0
	cmp r3, #2
	beq _081BF8E4
	b _081BF8E8
	.align 2, 0
_081BF8DC: .4byte 0x030046A4
_081BF8E0:
	ldrb r0, [r5, #4]
	b _081BF8E6
_081BF8E4:
	ldrb r0, [r5]
_081BF8E6:
	subs r2, r2, r0
_081BF8E8:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081BF8F2:
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
	bne _081BFA0A
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081BF920
	movs r0, #1
	b _081BF922
_081BF920:
	movs r0, #0
_081BF922:
	ldr r4, _081BFA1C @ =0x00000482
	ldr r3, [sp, #0x18]
	adds r4, r3, r4
	str r4, [sp, #0x48]
	cmp r0, #0
	bne _081BFA0A
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
	ldr r4, _081BFA20 @ =0x0000054F
	adds r2, r2, r4
	mov ip, r2
	adds r6, #0xc
	ldr r5, [sp, #0x18]
	adds r6, r5, r6
	str r6, [sp, #0x5c]
	ldr r0, _081BFA24 @ =0x0000054D
	adds r0, r5, r0
	str r0, [sp, #0x60]
	adds r1, #6
	adds r1, r5, r1
	str r1, [sp, #0x64]
	ldr r2, _081BFA28 @ =0x00000541
	adds r2, r5, r2
	str r2, [sp, #0x50]
	adds r4, #0x6d
	adds r4, r5, r4
	str r4, [sp, #0x2c]
	ldr r6, _081BFA2C @ =0x00000542
	adds r6, r5, r6
	str r6, [sp, #0x54]
	ldr r6, _081BFA30 @ =0x0203B400
	ldr r1, _081BFA34 @ =0x030046B8
	ldr r5, _081BFA38 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_081BF97C:
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
	bne _081BF99A
	adds r3, #1
	cmp r3, #3
	ble _081BF97C
	mov r0, r8
_081BF99A:
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
_081BFA0A:
	ldr r0, [sp, #0x18]
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x48]
	strh r0, [r4]
	movs r0, #0
	b _081BFB1A
	.align 2, 0
_081BFA1C: .4byte 0x00000482
_081BFA20: .4byte 0x0000054F
_081BFA24: .4byte 0x0000054D
_081BFA28: .4byte 0x00000541
_081BFA2C: .4byte 0x00000542
_081BFA30: .4byte 0x0203B400
_081BFA34: .4byte 0x030046B8
_081BFA38: .4byte 0x000003FF
_081BFA3C:
	add r6, sp, #0x10
	ldr r0, _081BFA7C @ =0x030046A4
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
	beq _081BFA80
	adds r0, #4
	b _081BFA8C
	.align 2, 0
_081BFA7C: .4byte 0x030046A4
_081BFA80:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081BFA8C:
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
	ldr r6, _081BFAC4 @ =0x000004A4
	adds r0, r5, r6
	ldr r4, [r0]
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	add r2, sp, #0x10
	bl FUN_0823599c
	cmp r0, #0
	bne _081BFACC
	ldr r0, _081BFAC8 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081BFAF6
	.align 2, 0
_081BFAC4: .4byte 0x000004A4
_081BFAC8: .4byte 0xFFFFFDFF
_081BFACC:
	adds r0, r4, #0
	adds r1, r5, #0
	add r2, sp, #0x10
	bl FUN_08235f40
	cmp r0, #0
	beq _081BFAEC
	cmp r0, #2
	beq _081BFAE8
	ldr r0, [sp, #0x18]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BFAE8:
	movs r0, #1
	b _081BFAF8
_081BFAEC:
	ldr r0, _081BFB10 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081BFAF6:
	movs r0, #0
_081BFAF8:
	cmp r0, #0
	bne _081BFB18
	ldr r4, [sp, #0x18]
	ldr r5, _081BFB14 @ =0x000005C4
	adds r0, r4, r5
	ldr r1, [r0]
	adds r0, r4, #0
_081BFB06:
	bl _call_via_r1
	movs r0, #0
	b _081BFB1A
	.align 2, 0
_081BFB10: .4byte 0xFFFFFDFF
_081BFB14: .4byte 0x000005C4
_081BFB18:
	movs r0, #1
_081BFB1A:
	cmp r0, #0
	bne _081BFB20
	b _081BFCB2
_081BFB20:
	ldr r6, [sp, #0x18]
	ldr r0, _081BFB2C @ =0x00000482
	adds r1, r6, r0
	movs r0, #2
	strh r0, [r1]
	b _081BFC9C
	.align 2, 0
_081BFB2C: .4byte 0x00000482
_081BFB30:
	movs r2, #0x10
	ldr r3, [sp, #0x18]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r5, _081BFBB4 @ =0x00000482
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
	ldr r3, _081BFBB8 @ =0x00000551
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
	blt _081BFBB0
	cmp r1, #0
	blt _081BFBB0
	ldr r0, _081BFBBC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BFBB0
	ldr r0, _081BFBC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BFBC4
_081BFBB0:
	movs r4, #0
	b _081BFBD2
	.align 2, 0
_081BFBB4: .4byte 0x00000482
_081BFBB8: .4byte 0x00000551
_081BFBBC: .4byte 0x030046A8
_081BFBC0: .4byte 0x030046AC
_081BFBC4:
	ldr r0, _081BFBE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BFBD2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081BFBE8
	adds r0, #4
	b _081BFBF4
	.align 2, 0
_081BFBE4: .4byte 0x030046A4
_081BFBE8:
	ldr r0, _081BFC08 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BFBF4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BFC0C
	cmp r2, #2
	beq _081BFC10
	b _081BFC14
	.align 2, 0
_081BFC08: .4byte 0x030046A4
_081BFC0C:
	ldrb r0, [r5, #4]
	b _081BFC12
_081BFC10:
	ldrb r0, [r5]
_081BFC12:
	subs r1, r1, r0
_081BFC14:
	strh r1, [r5, #2]
	ldr r3, [sp, #0x18]
	movs r4, #0x95
	lsls r4, r4, #3
	adds r2, r3, r4
	ldr r1, [r2]
	movs r0, #1
	strh r0, [r1, #6]
	ldr r5, _081BFC4C @ =0x000004A4
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
	bne _081BFC54
	ldr r0, _081BFC50 @ =0xFFFFFDFF
	mov r6, sl
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081BFC7E
	.align 2, 0
_081BFC4C: .4byte 0x000004A4
_081BFC50: .4byte 0xFFFFFDFF
_081BFC54:
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081BFC74
	cmp r0, #2
	beq _081BFC70
	ldr r0, [sp, #0x18]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BFC70:
	movs r0, #1
	b _081BFC80
_081BFC74:
	ldr r0, _081BFC94 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081BFC7E:
	movs r0, #0
_081BFC80:
	cmp r0, #0
	bne _081BFC9C
	ldr r3, [sp, #0x18]
	ldr r4, _081BFC98 @ =0x000005C4
	adds r0, r3, r4
	ldr r1, [r0]
	adds r0, r3, #0
	bl _call_via_r1
	b _081BFCB2
	.align 2, 0
_081BFC94: .4byte 0xFFFFFDFF
_081BFC98: .4byte 0x000005C4
_081BFC9C:
	ldr r5, _081BFCC4 @ =0x000006BA
	adds r1, r7, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r6, [sp, #0x18]
	ldr r0, _081BFCC8 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081BFCB2:
	add sp, #0x6c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081BFCC4: .4byte 0x000006BA
_081BFCC8: .4byte 0x00000484

	thumb_func_start FUN_081bfccc
FUN_081bfccc: @ 0x081BFCCC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _081BFCEC @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BFCF0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BFCF2
	.align 2, 0
_081BFCEC: .4byte 0x0000046C
_081BFCF0:
	movs r0, #0
_081BFCF2:
	cmp r0, #0
	beq _081BFCFE
	ldr r3, _081BFD2C @ =0x0000046B
	adds r1, r6, r3
	movs r0, #0
	strb r0, [r1]
_081BFCFE:
	adds r0, r6, #0
	bl FUN_081b916c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081BFD0C
	b _081BFF1A
_081BFD0C:
	ldr r5, _081BFD2C @ =0x0000046B
	adds r0, r6, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BFD18
	b _081BFF10
_081BFD18:
	adds r3, r4, #0
	ldr r0, _081BFD30 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081BFD34
	movs r0, #1
	b _081BFD36
	.align 2, 0
_081BFD2C: .4byte 0x0000046B
_081BFD30: .4byte 0x030047A4
_081BFD34:
	movs r0, #0
_081BFD36:
	cmp r0, #0
	beq _081BFD64
	movs r7, #0xec
	lsls r7, r7, #1
	adds r0, r3, r7
	ldr r1, [r0]
	cmp r1, #0
	beq _081BFD74
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081BFD52
	adds r2, r0, #0
_081BFD52:
	cmp r2, #0
	blt _081BFD74
	ldr r1, _081BFD60 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	b _081BFD66
	.align 2, 0
_081BFD60: .4byte 0x03002BE0
_081BFD64:
	ldr r0, _081BFDDC @ =0x03002BE0
_081BFD66:
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081BFDB2
_081BFD74:
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081BFDB2
	movs r5, #0xf2
	lsls r5, r5, #1
	adds r0, r3, r5
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xf
	subs r0, r0, r1
	cmp r0, #0
	bge _081BFD98
	movs r0, #0
_081BFD98:
	ldr r7, _081BFDE0 @ =0x000006BC
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
	bls _081BFDB2
	strh r2, [r1]
_081BFDB2:
	adds r3, r4, #0
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r3, r5
	ldr r0, [r0]
	cmp r0, #0
	beq _081BFEA4
	movs r2, #0
	movs r7, #0x90
	lsls r7, r7, #3
	adds r0, r3, r7
	ldrh r0, [r0]
	cmp r0, #0
	bne _081BFDE8
	ldr r1, _081BFDE0 @ =0x000006BC
	adds r0, r3, r1
	ldrh r1, [r0]
	ldr r0, _081BFDE4 @ =0x0000018F
	cmp r1, r0
	bls _081BFDF4
	b _081BFDF8
	.align 2, 0
_081BFDDC: .4byte 0x03002BE0
_081BFDE0: .4byte 0x000006BC
_081BFDE4: .4byte 0x0000018F
_081BFDE8:
	ldr r5, _081BFE84 @ =0x000006BC
	adds r0, r3, r5
	ldrh r0, [r0]
	cmp r0, #0xc7
	bls _081BFDF4
	movs r2, #1
_081BFDF4:
	cmp r2, #0
	beq _081BFE2C
_081BFDF8:
	movs r7, #0xf2
	lsls r7, r7, #1
	adds r0, r3, r7
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081BFE2C
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
	bne _081BFE2E
_081BFE2C:
	movs r1, #0
_081BFE2E:
	cmp r1, #0
	beq _081BFEA4
	ldr r2, _081BFE88 @ =FUN_081bb4e4
	movs r1, #0x27
	ldr r5, _081BFE8C @ =0x0000046D
	adds r0, r6, r5
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r7, _081BFE90 @ =0x0000046B
	adds r0, r6, r7
	strb r3, [r0]
	ldr r4, _081BFE94 @ =0x00000553
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
	ldr r1, _081BFE98 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081BFE9C @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _081BFEA0 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _081BFF1A
	.align 2, 0
_081BFE84: .4byte 0x000006BC
_081BFE88: .4byte FUN_081bb4e4
_081BFE8C: .4byte 0x0000046D
_081BFE90: .4byte 0x0000046B
_081BFE94: .4byte 0x00000553
_081BFE98: .4byte 0x00000469
_081BFE9C: .4byte 0x0000046A
_081BFEA0: .4byte 0x00000484
_081BFEA4:
	ldr r2, _081BFEF4 @ =FUN_081baca8
	movs r1, #0x22
	ldr r3, _081BFEF8 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _081BFEFC @ =0x0000046B
	adds r0, r6, r5
	strb r3, [r0]
	ldr r7, _081BFF00 @ =0x00000553
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
	ldr r1, _081BFF04 @ =0x0000046A
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _081BFF08 @ =0x00000484
	adds r0, r6, r2
	str r3, [r0]
	ldr r3, _081BFF0C @ =0x0000046C
	adds r0, r6, r3
	strb r4, [r0]
	b _081BFF1A
	.align 2, 0
_081BFEF4: .4byte FUN_081baca8
_081BFEF8: .4byte 0x0000046D
_081BFEFC: .4byte 0x0000046B
_081BFF00: .4byte 0x00000553
_081BFF04: .4byte 0x0000046A
_081BFF08: .4byte 0x00000484
_081BFF0C: .4byte 0x0000046C
_081BFF10:
	ldr r4, _081BFF20 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081BFF1A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081BFF20: .4byte 0x00000484

	thumb_func_start FUN_081bff24
FUN_081bff24: @ 0x081BFF24
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x68
	adds r7, r0, #0
	ldr r0, _081C004C @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BFF40
	movs r0, #0
	strb r0, [r1]
_081BFF40:
	adds r0, r7, #0
	bl FUN_081b916c
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _081BFF52
	bl _081C07CE
_081BFF52:
	ldr r1, _081C0050 @ =0x0000046B
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BFF60
	bl FUN_081c07c4
_081BFF60:
	movs r0, #3
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #8]
	strb r0, [r2]
	ldr r4, _081C0054 @ =0x00000469
	adds r4, r7, r4
	str r4, [sp, #0xc]
	strb r1, [r4]
	ldr r5, _081C0058 @ =0x0000046A
	adds r5, r7, r5
	str r5, [sp, #0x10]
	strb r3, [r5]
	ldr r6, _081C005C @ =0x00000484
	adds r6, r7, r6
	str r6, [sp, #0x14]
	str r3, [r6]
	ldr r0, _081C004C @ =0x0000046C
	adds r0, r0, r7
	mov sb, r0
	strb r1, [r0]
	ldr r2, _081C0060 @ =FUN_080e6794
	movs r0, #0xe
	ldr r4, _081C0064 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x18]
	strb r1, [r4]
	ldr r5, _081C0050 @ =0x0000046B
	adds r5, r5, r7
	mov sl, r5
	strb r3, [r5]
	ldr r6, _081C0068 @ =0x00000553
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
	ldr r2, _081C006C @ =0x000004A4
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
	bne _081C0008
	b _081C0600
_081C0008:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	ldr r6, _081C0070 @ =0x00000554
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081C0074 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #6
	adds r0, r7, r5
	strb r4, [r0]
	ldr r0, _081C0078 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C007C
	movs r0, #1
	b _081C007E
	.align 2, 0
_081C004C: .4byte 0x0000046C
_081C0050: .4byte 0x0000046B
_081C0054: .4byte 0x00000469
_081C0058: .4byte 0x0000046A
_081C005C: .4byte 0x00000484
_081C0060: .4byte FUN_080e6794
_081C0064: .4byte 0x0000046D
_081C0068: .4byte 0x00000553
_081C006C: .4byte 0x000004A4
_081C0070: .4byte 0x00000554
_081C0074: .4byte 0x00000551
_081C0078: .4byte 0x030047A4
_081C007C:
	movs r0, #0
_081C007E:
	cmp r0, #0
	beq _081C0092
	adds r0, r7, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C0090
	b _081C07CE
_081C0090:
	b _081C00A0
_081C0092:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _081C00E0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
_081C00A0:
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
	blt _081C00DC
	cmp r1, #0
	blt _081C00DC
	ldr r0, _081C00E4 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081C00DC
	ldr r0, _081C00E8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C00EC
_081C00DC:
	movs r4, #0
	b _081C00FA
	.align 2, 0
_081C00E0: .4byte 0x03002BE0
_081C00E4: .4byte 0x030046A8
_081C00E8: .4byte 0x030046AC
_081C00EC:
	ldr r0, _081C010C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081C00FA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C0110
	adds r0, #4
	b _081C011C
	.align 2, 0
_081C010C: .4byte 0x030046A4
_081C0110:
	ldr r0, _081C0130 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C011C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C0134
	cmp r2, #2
	beq _081C0138
	b _081C013C
	.align 2, 0
_081C0130: .4byte 0x030046A4
_081C0134:
	ldrb r0, [r5, #4]
	b _081C013A
_081C0138:
	ldrb r0, [r5]
_081C013A:
	subs r1, r1, r0
_081C013C:
	strh r1, [r5, #2]
	ldr r0, _081C0150 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C0154
	movs r0, #1
	b _081C0156
	.align 2, 0
_081C0150: .4byte 0x030047A4
_081C0154:
	movs r0, #0
_081C0156:
	cmp r0, #0
	beq _081C0194
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081C0176
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C0172
	adds r2, r0, #0
_081C0172:
	cmp r2, #0
	bge _081C0180
_081C0176:
	ldr r2, _081C017C @ =0x000005C4
	adds r0, r7, r2
	b _081C05D4
	.align 2, 0
_081C017C: .4byte 0x000005C4
_081C0180:
	ldr r1, _081C0190 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081C01DC
	.align 2, 0
_081C0190: .4byte 0x03002BE0
_081C0194:
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
	blt _081C01C0
	cmp r1, #0
	blt _081C01C0
	ldr r0, _081C01C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C01C0
	ldr r0, _081C01C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C01CC
_081C01C0:
	movs r5, #0
	b _081C01DA
	.align 2, 0
_081C01C4: .4byte 0x030046A8
_081C01C8: .4byte 0x030046AC
_081C01CC:
	ldr r0, _081C0214 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081C01DA:
	movs r2, #0
_081C01DC:
	ldr r4, _081C0218 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081C01FC
	ldr r1, _081C021C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C01FC
	b _081C0518
_081C01FC:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081C0220
	movs r0, #0
	b _081C05EA
	.align 2, 0
_081C0214: .4byte 0x030046A4
_081C0218: .4byte 0x00000256
_081C021C: .4byte 0x03002BE0
_081C0220:
	ldr r0, _081C027C @ =0x00000222
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
	beq _081C0280
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
	b _081C03CE
	.align 2, 0
_081C027C: .4byte 0x00000222
_081C0280:
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
	blt _081C02E4
	cmp r1, #0
	blt _081C02E4
	ldr r0, _081C02E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C02E4
	ldr r0, _081C02EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C02F0
_081C02E4:
	movs r4, #0
	b _081C02FE
	.align 2, 0
_081C02E8: .4byte 0x030046A8
_081C02EC: .4byte 0x030046AC
_081C02F0:
	ldr r0, _081C0310 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C02FE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C0314
	adds r0, #4
	b _081C0320
	.align 2, 0
_081C0310: .4byte 0x030046A4
_081C0314:
	ldr r0, _081C0334 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C0320:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C0338
	cmp r2, #2
	beq _081C033C
	b _081C0340
	.align 2, 0
_081C0334: .4byte 0x030046A4
_081C0338:
	ldrb r0, [r5, #4]
	b _081C033E
_081C033C:
	ldrb r0, [r5]
_081C033E:
	subs r1, r1, r0
_081C0340:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C0368
	cmp r1, #0
	blt _081C0368
	ldr r0, _081C036C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C0368
	ldr r0, _081C0370 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C0374
_081C0368:
	movs r4, #0
	b _081C0382
	.align 2, 0
_081C036C: .4byte 0x030046A8
_081C0370: .4byte 0x030046AC
_081C0374:
	ldr r0, _081C0394 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C0382:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C0398
	adds r0, #4
	b _081C03A4
	.align 2, 0
_081C0394: .4byte 0x030046A4
_081C0398:
	ldr r0, _081C03B8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C03A4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C03BC
	cmp r3, #2
	beq _081C03C0
	b _081C03C4
	.align 2, 0
_081C03B8: .4byte 0x030046A4
_081C03BC:
	ldrb r0, [r5, #4]
	b _081C03C2
_081C03C0:
	ldrb r0, [r5]
_081C03C2:
	subs r2, r2, r0
_081C03C4:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081C03CE:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	ldr r6, _081C03F8 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x44]
	cmp r0, #0
	bne _081C04DC
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C03FC
	movs r0, #1
	b _081C03FE
	.align 2, 0
_081C03F8: .4byte 0x00000482
_081C03FC:
	movs r0, #0
_081C03FE:
	ldr r3, _081C04EC @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x44]
	cmp r0, #0
	bne _081C04DC
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _081C04F0 @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _081C04F4 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x54]
	ldr r1, _081C04F8 @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r2, _081C04FC @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	ldr r4, _081C0500 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	ldr r5, _081C0504 @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x28]
	ldr r6, _081C0508 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x50]
	ldr r6, _081C050C @ =0x0203B400
	ldr r1, _081C0510 @ =0x030046B8
	ldr r5, _081C0514 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_081C044E:
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
	bne _081C046C
	adds r3, #1
	cmp r3, #3
	ble _081C044E
	mov r0, r8
_081C046C:
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
_081C04DC:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x44]
	strh r0, [r4]
	movs r0, #0
	b _081C05EA
	.align 2, 0
_081C04EC: .4byte 0x00000482
_081C04F0: .4byte 0x0000054F
_081C04F4: .4byte 0x0000054C
_081C04F8: .4byte 0x0000054D
_081C04FC: .4byte 0x0000054E
_081C0500: .4byte 0x00000541
_081C0504: .4byte 0x000005BC
_081C0508: .4byte 0x00000542
_081C050C: .4byte 0x0203B400
_081C0510: .4byte 0x030046B8
_081C0514: .4byte 0x000003FF
_081C0518:
	mov sb, sp
	ldr r6, _081C0554 @ =0x030046A4
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
	beq _081C0558
	adds r0, #4
	b _081C0562
	.align 2, 0
_081C0554: .4byte 0x030046A4
_081C0558:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C0562:
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
	ldr r6, _081C0598 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081C05A0
	ldr r0, _081C059C @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C05CA
	.align 2, 0
_081C0598: .4byte 0x000004A4
_081C059C: .4byte 0xFFFFFDFF
_081C05A0:
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081C05C0
	cmp r0, #2
	beq _081C05BC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C05BC:
	movs r0, #1
	b _081C05CC
_081C05C0:
	ldr r0, _081C05E0 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C05CA:
	movs r0, #0
_081C05CC:
	cmp r0, #0
	bne _081C05E8
	ldr r4, _081C05E4 @ =0x000005C4
	adds r0, r7, r4
_081C05D4:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081C05EA
	.align 2, 0
_081C05E0: .4byte 0xFFFFFDFF
_081C05E4: .4byte 0x000005C4
_081C05E8:
	movs r0, #1
_081C05EA:
	cmp r0, #0
	bne _081C05F0
	b _081C07CE
_081C05F0:
	ldr r5, _081C05FC @ =0x00000482
	adds r1, r7, r5
	movs r0, #2
	strh r0, [r1]
	b _081C07CE
	.align 2, 0
_081C05FC: .4byte 0x00000482
_081C0600:
	movs r5, #0x80
	lsls r5, r5, #2
	ands r2, r5
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r4, r7, r6
	cmp r2, #0
	beq _081C0658
	movs r1, #0x80
	lsls r1, r1, #0xe
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081C0648
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _081C06D4 @ =0xFEFFFFFF
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
	ldr r1, _081C06D8 @ =0x00000202
	adds r0, r7, r1
	strh r3, [r0]
_081C0648:
	ldr r2, _081C06DC @ =0x000001DF
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
_081C0658:
	movs r1, #0x10
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r3, _081C06E0 @ =0x00000482
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
	ldr r2, _081C06E4 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081C06E8 @ =0x00000552
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
	blt _081C06D0
	cmp r1, #0
	blt _081C06D0
	ldr r0, _081C06EC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C06D0
	ldr r0, _081C06F0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C06F4
_081C06D0:
	movs r4, #0
	b _081C0702
	.align 2, 0
_081C06D4: .4byte 0xFEFFFFFF
_081C06D8: .4byte 0x00000202
_081C06DC: .4byte 0x000001DF
_081C06E0: .4byte 0x00000482
_081C06E4: .4byte 0x00000551
_081C06E8: .4byte 0x00000552
_081C06EC: .4byte 0x030046A8
_081C06F0: .4byte 0x030046AC
_081C06F4:
	ldr r0, _081C0714 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C0702:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C0718
	adds r0, #4
	b _081C0724
	.align 2, 0
_081C0714: .4byte 0x030046A4
_081C0718:
	ldr r0, _081C0738 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C0724:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C073C
	cmp r2, #2
	beq _081C0740
	b _081C0744
	.align 2, 0
_081C0738: .4byte 0x030046A4
_081C073C:
	ldrb r0, [r5, #4]
	b _081C0742
_081C0740:
	ldrb r0, [r5]
_081C0742:
	subs r1, r1, r0
_081C0744:
	strh r1, [r5, #2]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r2, r7, r5
	ldr r1, [r2]
	movs r0, #1
	strh r0, [r1, #6]
	ldr r6, _081C0774 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	ldr r5, [r2]
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	adds r2, r5, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081C077C
	ldr r0, _081C0778 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C07A6
	.align 2, 0
_081C0774: .4byte 0x000004A4
_081C0778: .4byte 0xFFFFFDFF
_081C077C:
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081C079C
	cmp r0, #2
	beq _081C0798
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C0798:
	movs r0, #1
	b _081C07A8
_081C079C:
	ldr r0, _081C07BC @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C07A6:
	movs r0, #0
_081C07A8:
	cmp r0, #0
	bne _081C07CE
	ldr r4, _081C07C0 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081C07CE
	.align 2, 0
_081C07BC: .4byte 0xFFFFFDFF
_081C07C0: .4byte 0x000005C4

	thumb_func_start FUN_081c07c4
FUN_081c07c4: @ 0x081C07C4
	ldr r5, _081C07E0 @ =0x00000484
	adds r1, r7, r5
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081C07CE:
	add sp, #0x68
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C07E0: .4byte 0x00000484

	thumb_func_start FUN_081c07e4
FUN_081c07e4: @ 0x081C07E4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	adds r5, r4, #0
	ldr r7, _081C0858 @ =0x0000046C
	adds r1, r4, r7
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C0800
	movs r0, #0
	strb r0, [r1]
_081C0800:
	adds r0, r4, #0
	bl FUN_081b916c
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _081C0852
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	strb r0, [r5, #5]
	ldr r7, _081C085C @ =0x00000484
	adds r5, r4, r7
	ldr r0, [r5]
	cmp r0, #0x77
	ble _081C084C
	movs r1, #2
	movs r2, #5
	subs r7, #0x1c
	adds r0, r4, r7
	strb r3, [r0]
	adds r7, #1
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _081C0860 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	adds r7, #0x1b
	adds r0, r4, r7
	str r3, [r0]
	ldr r0, _081C0858 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081C0864 @ =0x000006BC
	adds r0, r6, r1
	strh r3, [r0]
_081C084C:
	ldr r0, [r5]
	adds r0, #1
	str r0, [r5]
_081C0852:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C0858: .4byte 0x0000046C
_081C085C: .4byte 0x00000484
_081C0860: .4byte 0x0000046A
_081C0864: .4byte 0x000006BC

	thumb_func_start FUN_081c0868
FUN_081c0868: @ 0x081C0868
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	adds r5, r6, #0
	ldr r2, _081C0888 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C088C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C088E
	.align 2, 0
_081C0888: .4byte 0x0000046C
_081C088C:
	movs r0, #0
_081C088E:
	cmp r0, #0
	beq _081C08D8
	ldr r4, _081C0960 @ =FUN_081bb7b8
	movs r3, #0x28
	ldr r0, _081C0964 @ =0x0000046D
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081C0968 @ =0x0000046B
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
	ldr r2, _081C0968 @ =0x0000046B
	adds r0, r6, r2
	strb r1, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	strb r0, [r5, #5]
	ldr r4, _081C096C @ =0x000006B6
	adds r1, r7, r4
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r1]
_081C08D8:
	ldr r0, _081C0970 @ =0x00000484
	adds r2, r6, r0
	ldr r1, [r2]
	cmp r1, #0x1e
	bgt _081C08EC
	ldr r3, _081C0968 @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081C0984
_081C08EC:
	movs r4, #0xcd
	lsls r4, r4, #3
	adds r2, r7, r4
	ldrh r0, [r2]
	cmp r0, #0
	beq _081C090E
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
_081C090E:
	ldr r2, _081C0974 @ =FUN_081baed4
	movs r1, #0x26
	ldr r3, _081C0964 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _081C0968 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _081C0978 @ =0x00000553
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
	ldr r1, _081C097C @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081C0980 @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _081C0970 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _081C0988
	.align 2, 0
_081C0960: .4byte FUN_081bb7b8
_081C0964: .4byte 0x0000046D
_081C0968: .4byte 0x0000046B
_081C096C: .4byte 0x000006B6
_081C0970: .4byte 0x00000484
_081C0974: .4byte FUN_081baed4
_081C0978: .4byte 0x00000553
_081C097C: .4byte 0x00000469
_081C0980: .4byte 0x0000046A
_081C0984:
	adds r0, r1, #1
	str r0, [r2]
_081C0988:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081c0990
FUN_081c0990: @ 0x081C0990
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _081C09B0 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C09B4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C09B6
	.align 2, 0
_081C09B0: .4byte 0x0000046C
_081C09B4:
	movs r0, #0
_081C09B6:
	cmp r0, #0
	beq _081C09FC
	ldr r4, _081C0A7C @ =FUN_081bbad4
	movs r3, #0x29
	ldr r0, _081C0A80 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081C0A84 @ =0x0000046B
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
	ldr r2, _081C0A84 @ =0x0000046B
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
_081C09FC:
	adds r0, r5, #0
	bl FUN_081b916c
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _081C0A9E
	ldr r1, _081C0A84 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081C0A94
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
	bl FUN_081b86d8
	ldr r2, _081C0A88 @ =FUN_081baca8
	movs r1, #0x22
	ldr r3, _081C0A80 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _081C0A84 @ =0x0000046B
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
	ldr r1, _081C0A8C @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _081C0A90 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r4, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r3, [r0]
	b _081C0A9E
	.align 2, 0
_081C0A7C: .4byte FUN_081bbad4
_081C0A80: .4byte 0x0000046D
_081C0A84: .4byte 0x0000046B
_081C0A88: .4byte FUN_081baca8
_081C0A8C: .4byte 0x00000469
_081C0A90: .4byte 0x0000046A
_081C0A94:
	ldr r2, _081C0AA4 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081C0A9E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081C0AA4: .4byte 0x00000484

	thumb_func_start FUN_081c0aa8
FUN_081c0aa8: @ 0x081C0AA8
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
	ldr r2, _081C0AD0 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C0AD4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C0AD6
	.align 2, 0
_081C0AD0: .4byte 0x0000046C
_081C0AD4:
	movs r0, #0
_081C0AD6:
	cmp r0, #0
	beq _081C0AE2
	ldr r3, _081C0B14 @ =0x0000046B
	adds r1, r6, r3
	movs r0, #0
	strb r0, [r1]
_081C0AE2:
	adds r0, r6, #0
	bl FUN_081b916c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C0AF0
	b _081C105E
_081C0AF0:
	ldr r4, _081C0B14 @ =0x0000046B
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C0AFC
	b _081C1054
_081C0AFC:
	adds r3, r7, #0
	ldr r0, _081C0B18 @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #7
	ands r1, r2
	adds r4, r0, #0
	cmp r1, #0
	beq _081C0B1C
	movs r0, #1
	b _081C0B1E
	.align 2, 0
_081C0B14: .4byte 0x0000046B
_081C0B18: .4byte 0x030047A4
_081C0B1C:
	movs r0, #0
_081C0B1E:
	cmp r0, #0
	beq _081C0B4C
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081C0B5C
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C0B3A
	adds r2, r0, #0
_081C0B3A:
	cmp r2, #0
	blt _081C0B5C
	ldr r1, _081C0B48 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	b _081C0B4E
	.align 2, 0
_081C0B48: .4byte 0x03002BE0
_081C0B4C:
	ldr r0, _081C0BB4 @ =0x03002BE0
_081C0B4E:
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C0B9A
_081C0B5C:
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C0B9A
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xf
	subs r0, r0, r1
	cmp r0, #0
	bge _081C0B80
	movs r0, #0
_081C0B80:
	ldr r2, _081C0BB8 @ =0x000006BC
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
	bls _081C0B9A
	strh r2, [r1]
_081C0B9A:
	ldr r0, _081C0BBC @ =0x000006B4
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0x1e
	strh r0, [r1]
	ldr r0, [r4]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C0BC0
	movs r0, #1
	b _081C0BC2
	.align 2, 0
_081C0BB4: .4byte 0x03002BE0
_081C0BB8: .4byte 0x000006BC
_081C0BBC: .4byte 0x000006B4
_081C0BC0:
	movs r0, #0
_081C0BC2:
	adds r5, r0, #0
	cmp r5, #0
	beq _081C0C40
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081C0CBC
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C0BE0
	adds r2, r0, #0
_081C0BE0:
	cmp r2, #0
	blt _081C0CBC
	ldr r1, _081C0C2C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081C0CBC
	ldr r2, _081C0C30 @ =FUN_081baed4
	movs r1, #0x26
	ldr r3, _081C0C34 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _081C0C38 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _081C0C3C @ =0x00000553
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
	b _081C0E68
	.align 2, 0
_081C0C2C: .4byte 0x03002BE0
_081C0C30: .4byte FUN_081baed4
_081C0C34: .4byte 0x0000046D
_081C0C38: .4byte 0x0000046B
_081C0C3C: .4byte 0x00000553
_081C0C40:
	ldr r0, _081C0CA0 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081C0CBC
	ldr r2, _081C0CA4 @ =FUN_081baed4
	movs r1, #0x26
	ldr r3, _081C0CA8 @ =0x0000046D
	adds r0, r6, r3
	movs r4, #1
	strb r4, [r0]
	ldr r7, _081C0CAC @ =0x0000046B
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
	ldr r1, _081C0CB0 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081C0CB4 @ =0x0000046A
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _081C0CB8 @ =0x00000484
	adds r0, r6, r3
	str r5, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r4, [r0]
	b _081C105E
	.align 2, 0
_081C0CA0: .4byte 0x03002BE0
_081C0CA4: .4byte FUN_081baed4
_081C0CA8: .4byte 0x0000046D
_081C0CAC: .4byte 0x0000046B
_081C0CB0: .4byte 0x00000469
_081C0CB4: .4byte 0x0000046A
_081C0CB8: .4byte 0x00000484
_081C0CBC:
	ldr r1, _081C0CF4 @ =0x000006B4
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _081C0DBC
	adds r3, r7, #0
	adds r4, r7, #0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081C0D78
	movs r2, #0
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081C0D00
	ldr r1, _081C0CF8 @ =0x000006BC
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r0, _081C0CFC @ =0x0000018F
	cmp r1, r0
	bls _081C0D0C
	b _081C0D10
	.align 2, 0
_081C0CF4: .4byte 0x000006B4
_081C0CF8: .4byte 0x000006BC
_081C0CFC: .4byte 0x0000018F
_081C0D00:
	ldr r1, _081C0D64 @ =0x000006BC
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0xc7
	bls _081C0D0C
	movs r2, #1
_081C0D0C:
	cmp r2, #0
	beq _081C0D44
_081C0D10:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r7, #0xf6
	lsls r7, r7, #1
	adds r1, r3, r7
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081C0D44
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
	bne _081C0D46
_081C0D44:
	movs r1, #0
_081C0D46:
	cmp r1, #0
	beq _081C0D78
	ldr r2, _081C0D68 @ =FUN_081bb4e4
	movs r1, #0x27
	ldr r3, _081C0D6C @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _081C0D70 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _081C0D74 @ =0x00000553
	b _081C0E4E
	.align 2, 0
_081C0D64: .4byte 0x000006BC
_081C0D68: .4byte FUN_081bb4e4
_081C0D6C: .4byte 0x0000046D
_081C0D70: .4byte 0x0000046B
_081C0D74: .4byte 0x00000553
_081C0D78:
	ldr r2, _081C0DAC @ =FUN_081baed4
	movs r1, #0x26
	ldr r3, _081C0DB0 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _081C0DB4 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _081C0DB8 @ =0x00000553
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
	b _081C0E68
	.align 2, 0
_081C0DAC: .4byte FUN_081baed4
_081C0DB0: .4byte 0x0000046D
_081C0DB4: .4byte 0x0000046B
_081C0DB8: .4byte 0x00000553
_081C0DBC:
	adds r3, r7, #0
	adds r4, r7, #0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081C0EA4
	movs r2, #0
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081C0DF0
	ldr r1, _081C0DE8 @ =0x000006BC
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r0, _081C0DEC @ =0x0000018F
	cmp r1, r0
	bls _081C0DFC
	b _081C0E00
	.align 2, 0
_081C0DE8: .4byte 0x000006BC
_081C0DEC: .4byte 0x0000018F
_081C0DF0:
	ldr r1, _081C0E88 @ =0x000006BC
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0xc7
	bls _081C0DFC
	movs r2, #1
_081C0DFC:
	cmp r2, #0
	beq _081C0E32
_081C0E00:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r3, r2
	adds r2, #8
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081C0E32
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
	bne _081C0E34
_081C0E32:
	movs r1, #0
_081C0E34:
	cmp r1, #0
	beq _081C0EA4
	ldr r2, _081C0E8C @ =FUN_081bb4e4
	movs r1, #0x27
	ldr r7, _081C0E90 @ =0x0000046D
	adds r0, r6, r7
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _081C0E94 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	adds r7, #0xe6
_081C0E4E:
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
_081C0E68:
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081C0E98 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081C0E9C @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _081C0EA0 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _081C105E
	.align 2, 0
_081C0E88: .4byte 0x000006BC
_081C0E8C: .4byte FUN_081bb4e4
_081C0E90: .4byte 0x0000046D
_081C0E94: .4byte 0x0000046B
_081C0E98: .4byte 0x00000469
_081C0E9C: .4byte 0x0000046A
_081C0EA0: .4byte 0x00000484
_081C0EA4:
	ldr r1, _081C0EEC @ =0x00000256
	adds r0, r6, r1
	ldrh r5, [r0]
	mov sl, sp
	ldr r2, _081C0EF0 @ =0x030046A4
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
	beq _081C0EF4
	adds r0, #4
	b _081C0F00
	.align 2, 0
_081C0EEC: .4byte 0x00000256
_081C0EF0: .4byte 0x030046A4
_081C0EF4:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C0F00:
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
	bl FUN_081b86b4
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
	ldr r0, _081C0F8C @ =0x00000FFF
	cmp r1, r0
	bgt _081C0FA0
	adds r0, r7, #0
	bl FUN_081b86d8
	movs r1, #2
	movs r2, #6
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	mov r4, r8
	strb r4, [r0]
	ldr r7, _081C0F90 @ =0x00000469
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081C0F94 @ =0x0000046A
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081C0F98 @ =0x00000484
	adds r0, r6, r2
	movs r3, #0
	str r3, [r0]
	ldr r4, _081C0F9C @ =0x0000046C
	adds r1, r6, r4
	movs r0, #1
	strb r0, [r1]
	b _081C105E
	.align 2, 0
_081C0F8C: .4byte 0x00000FFF
_081C0F90: .4byte 0x00000469
_081C0F94: .4byte 0x0000046A
_081C0F98: .4byte 0x00000484
_081C0F9C: .4byte 0x0000046C
_081C0FA0:
	ldr r1, _081C1038 @ =0x000004A4
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
	ldr r2, _081C103C @ =0x000006C2
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _081C1040 @ =FUN_081baca8
	movs r1, #0x22
	ldr r4, _081C1044 @ =0x0000046D
	adds r0, r6, r4
	movs r2, #1
	strb r2, [r0]
	ldr r7, _081C1048 @ =0x0000046B
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
	ldr r4, _081C104C @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _081C1050 @ =0x00000484
	adds r0, r6, r1
	movs r3, #0
	str r3, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r2, [r0]
	b _081C105E
	.align 2, 0
_081C1038: .4byte 0x000004A4
_081C103C: .4byte 0x000006C2
_081C1040: .4byte FUN_081baca8
_081C1044: .4byte 0x0000046D
_081C1048: .4byte 0x0000046B
_081C104C: .4byte 0x00000469
_081C1050: .4byte 0x00000484
_081C1054:
	ldr r7, _081C1070 @ =0x00000484
	adds r1, r6, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081C105E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C1070: .4byte 0x00000484

	thumb_func_start FUN_081c1074
FUN_081c1074: @ 0x081C1074
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	adds r7, r0, #0
	ldr r0, _081C1094 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C1098
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C109A
	.align 2, 0
_081C1094: .4byte 0x0000046C
_081C1098:
	movs r0, #0
_081C109A:
	cmp r0, #0
	beq _081C10CE
	ldr r4, _081C115C @ =FUN_081ba904
	movs r3, #0x2b
	ldr r2, _081C1160 @ =0x0000046D
	adds r1, r7, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r5, _081C1164 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _081C1168 @ =0x00000553
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
_081C10CE:
	ldr r4, _081C1164 @ =0x0000046B
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C10DA
	b _081C1764
_081C10DA:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r3, _081C116C @ =FUN_080e6794
	movs r2, #0xe
	ldr r5, _081C1160 @ =0x0000046D
	adds r5, r5, r7
	mov r8, r5
	movs r1, #0
	movs r0, #1
	strb r0, [r5]
	adds r6, r7, r4
	strb r1, [r6]
	ldr r0, _081C1168 @ =0x00000553
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
	beq _081C1178
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x78
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	ldr r6, _081C1170 @ =0x00000554
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, sb
	strb r2, [r0]
	ldr r3, _081C1174 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #6
	adds r0, r7, r5
	b _081C11A4
	.align 2, 0
_081C115C: .4byte FUN_081ba904
_081C1160: .4byte 0x0000046D
_081C1164: .4byte 0x0000046B
_081C1168: .4byte 0x00000553
_081C116C: .4byte FUN_080e6794
_081C1170: .4byte 0x00000554
_081C1174: .4byte 0x00000551
_081C1178:
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x78
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _081C1244 @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	subs r6, #0x50
	adds r0, r7, r6
	mov r1, sb
	strb r1, [r0]
	ldr r2, _081C1248 @ =0x00000551
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _081C124C @ =0x00000552
	adds r0, r7, r3
_081C11A4:
	strb r4, [r0]
	movs r2, #0x10
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r5, _081C1250 @ =0x00000482
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
	ldr r0, _081C1254 @ =0x00000469
	adds r0, r0, r7
	mov r8, r0
	strb r1, [r0]
	ldr r4, _081C1258 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x54]
	strb r2, [r4]
	ldr r6, _081C125C @ =0x00000484
	adds r5, r7, r6
	str r3, [r5]
	ldr r0, _081C1260 @ =0x0000046C
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
	blt _081C123E
	cmp r1, #0
	blt _081C123E
	ldr r0, _081C1264 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _081C123E
	ldr r0, _081C1268 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C126C
_081C123E:
	movs r4, #0
	b _081C127C
	.align 2, 0
_081C1244: .4byte 0x00000554
_081C1248: .4byte 0x00000551
_081C124C: .4byte 0x00000552
_081C1250: .4byte 0x00000482
_081C1254: .4byte 0x00000469
_081C1258: .4byte 0x0000046A
_081C125C: .4byte 0x00000484
_081C1260: .4byte 0x0000046C
_081C1264: .4byte 0x030046A8
_081C1268: .4byte 0x030046AC
_081C126C:
	ldr r0, _081C128C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_081C127C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C1290
	adds r0, #4
	b _081C129C
	.align 2, 0
_081C128C: .4byte 0x030046A4
_081C1290:
	ldr r0, _081C12B0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C129C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C12B4
	cmp r2, #2
	beq _081C12BA
	b _081C12C0
	.align 2, 0
_081C12B0: .4byte 0x030046A4
_081C12B4:
	mov r2, sl
	ldrb r0, [r2, #4]
	b _081C12BE
_081C12BA:
	mov r3, sl
	ldrb r0, [r3]
_081C12BE:
	subs r1, r1, r0
_081C12C0:
	mov r4, sl
	strh r1, [r4, #2]
	ldr r0, _081C12D8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C12DC
	movs r0, #1
	b _081C12DE
	.align 2, 0
_081C12D8: .4byte 0x030047A4
_081C12DC:
	movs r0, #0
_081C12DE:
	cmp r0, #0
	beq _081C131C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _081C12FE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C12FA
	adds r2, r0, #0
_081C12FA:
	cmp r2, #0
	bge _081C1308
_081C12FE:
	ldr r6, _081C1304 @ =0x000005C4
	adds r0, r7, r6
	b _081C175C
	.align 2, 0
_081C1304: .4byte 0x000005C4
_081C1308:
	ldr r1, _081C1318 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081C1364
	.align 2, 0
_081C1318: .4byte 0x03002BE0
_081C131C:
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
	blt _081C1348
	cmp r1, #0
	blt _081C1348
	ldr r0, _081C134C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C1348
	ldr r0, _081C1350 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C1354
_081C1348:
	movs r5, #0
	b _081C1362
	.align 2, 0
_081C134C: .4byte 0x030046A8
_081C1350: .4byte 0x030046AC
_081C1354:
	ldr r0, _081C13F4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081C1362:
	movs r2, #0
_081C1364:
	ldr r3, _081C13F8 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081C1384
	ldr r1, _081C13FC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C1384
	b _081C169C
_081C1384:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x14]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081C1398
	b _081C1764
_081C1398:
	ldr r5, _081C1400 @ =0x00000222
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
	beq _081C1404
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
	b _081C1552
	.align 2, 0
_081C13F4: .4byte 0x030046A4
_081C13F8: .4byte 0x00000256
_081C13FC: .4byte 0x03002BE0
_081C1400: .4byte 0x00000222
_081C1404:
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
	blt _081C1468
	cmp r1, #0
	blt _081C1468
	ldr r0, _081C146C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C1468
	ldr r0, _081C1470 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C1474
_081C1468:
	movs r4, #0
	b _081C1482
	.align 2, 0
_081C146C: .4byte 0x030046A8
_081C1470: .4byte 0x030046AC
_081C1474:
	ldr r0, _081C1494 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C1482:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C1498
	adds r0, #4
	b _081C14A4
	.align 2, 0
_081C1494: .4byte 0x030046A4
_081C1498:
	ldr r0, _081C14B8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C14A4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C14BC
	cmp r2, #2
	beq _081C14C0
	b _081C14C4
	.align 2, 0
_081C14B8: .4byte 0x030046A4
_081C14BC:
	ldrb r0, [r5, #4]
	b _081C14C2
_081C14C0:
	ldrb r0, [r5]
_081C14C2:
	subs r1, r1, r0
_081C14C4:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C14EC
	cmp r1, #0
	blt _081C14EC
	ldr r0, _081C14F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C14EC
	ldr r0, _081C14F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C14F8
_081C14EC:
	movs r4, #0
	b _081C1506
	.align 2, 0
_081C14F0: .4byte 0x030046A8
_081C14F4: .4byte 0x030046AC
_081C14F8:
	ldr r0, _081C1518 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C1506:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C151C
	adds r0, #4
	b _081C1528
	.align 2, 0
_081C1518: .4byte 0x030046A4
_081C151C:
	ldr r0, _081C153C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C1528:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C1540
	cmp r3, #2
	beq _081C1544
	b _081C1548
	.align 2, 0
_081C153C: .4byte 0x030046A4
_081C1540:
	ldrb r0, [r5, #4]
	b _081C1546
_081C1544:
	ldrb r0, [r5]
_081C1546:
	subs r2, r2, r0
_081C1548:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081C1552:
	ldrb r4, [r7, #5]
	str r4, [sp, #8]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x14]
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	ldr r6, _081C157C @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x28]
	cmp r0, #0
	bne _081C1660
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C1580
	movs r0, #1
	b _081C1582
	.align 2, 0
_081C157C: .4byte 0x00000482
_081C1580:
	movs r0, #0
_081C1582:
	ldr r3, _081C1670 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x28]
	cmp r0, #0
	bne _081C1660
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _081C1674 @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _081C1678 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	ldr r1, _081C167C @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x40]
	ldr r2, _081C1680 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x44]
	ldr r4, _081C1684 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x34]
	ldr r5, _081C1688 @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x50]
	ldr r6, _081C168C @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x38]
	ldr r6, _081C1690 @ =0x0203B400
	ldr r1, _081C1694 @ =0x030046B8
	ldr r5, _081C1698 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_081C15D2:
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
	bne _081C15F0
	adds r3, #1
	cmp r3, #3
	ble _081C15D2
	mov r0, r8
_081C15F0:
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
_081C1660:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x28]
	strh r0, [r4]
	b _081C1764
	.align 2, 0
_081C1670: .4byte 0x00000482
_081C1674: .4byte 0x0000054F
_081C1678: .4byte 0x0000054C
_081C167C: .4byte 0x0000054D
_081C1680: .4byte 0x0000054E
_081C1684: .4byte 0x00000541
_081C1688: .4byte 0x000005BC
_081C168C: .4byte 0x00000542
_081C1690: .4byte 0x0203B400
_081C1694: .4byte 0x030046B8
_081C1698: .4byte 0x000003FF
_081C169C:
	mov sb, sp
	ldr r6, _081C16D8 @ =0x030046A4
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
	beq _081C16DC
	adds r0, #4
	b _081C16E6
	.align 2, 0
_081C16D8: .4byte 0x030046A4
_081C16DC:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C16E6:
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
	ldr r6, _081C1720 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081C1728
	ldr r0, _081C1724 @ =0xFFFFFDFF
	ldr r2, [sp, #0x14]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C1752
	.align 2, 0
_081C1720: .4byte 0x000004A4
_081C1724: .4byte 0xFFFFFDFF
_081C1728:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081C1748
	cmp r0, #2
	beq _081C1744
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C1744:
	movs r0, #1
	b _081C1754
_081C1748:
	ldr r0, _081C1774 @ =0xFFFFFDFF
	ldr r3, [sp, #0x14]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C1752:
	movs r0, #0
_081C1754:
	cmp r0, #0
	bne _081C1764
	ldr r4, _081C1778 @ =0x000005C4
	adds r0, r7, r4
_081C175C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
_081C1764:
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C1774: .4byte 0xFFFFFDFF
_081C1778: .4byte 0x000005C4

	thumb_func_start FUN_081c177c
FUN_081c177c: @ 0x081C177C
	ldr r1, _081C1788 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _081C178C @ =0x085ADFB4
	str r1, [r0]
	bx lr
	.align 2, 0
_081C1788: .4byte 0x0000063C
_081C178C: .4byte 0x085ADFB4

	thumb_func_start FUN_081c1790
FUN_081c1790: @ 0x081C1790
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _081C17AC @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C17B0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C17B2
	.align 2, 0
_081C17AC: .4byte 0x0000046D
_081C17B0:
	movs r0, #0
_081C17B2:
	cmp r0, #0
	beq _081C17E8
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	movs r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081C17E8:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ef86c
	ldr r2, _081C1890 @ =0x00000482
	adds r2, r2, r5
	mov r8, r2
	movs r7, #0
	movs r0, #4
	strh r0, [r2]
	ldr r3, _081C1894 @ =0x00000464
	adds r0, r5, r3
	ldrh r6, [r0]
	cmp r6, #0
	bne _081C1886
	ldr r1, _081C1898 @ =0x0000046B
	adds r0, r5, r1
	movs r4, #1
	strb r4, [r0]
	adds r0, r5, #0
	movs r1, #6
	bl FUN_080ef86c
	ldr r2, _081C189C @ =0x00000494
	adds r1, r5, r2
	movs r0, #0x20
	strh r0, [r1]
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _081C18A0 @ =0x00000469
	adds r0, r5, r1
	strb r7, [r0]
	subs r2, #0x2a
	adds r0, r5, r2
	strb r7, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081C18A4 @ =FUN_081c18a8
	movs r1, #0x13
	subs r3, #0x17
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r7, [r0]
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
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r0, #0x31
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	mov r0, r8
	strh r4, [r0]
	movs r2, #0x10
	subs r3, #8
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081C1886:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C1890: .4byte 0x00000482
_081C1894: .4byte 0x00000464
_081C1898: .4byte 0x0000046B
_081C189C: .4byte 0x00000494
_081C18A0: .4byte 0x00000469
_081C18A4: .4byte FUN_081c18a8

	thumb_func_start FUN_081c18a8
FUN_081c18a8: @ 0x081C18A8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _081C18C0 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C18C4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C18C6
	.align 2, 0
_081C18C0: .4byte 0x0000046D
_081C18C4:
	movs r0, #0
_081C18C6:
	cmp r0, #0
	beq _081C18F6
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _081C196C @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _081C1970 @ =0x0000021E
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	ldr r5, _081C1974 @ =0x00000202
	adds r0, r6, r5
	strh r1, [r0]
	adds r0, r6, #0
	movs r1, #7
	bl FUN_080ef86c
_081C18F6:
	cmp r4, #0x3b
	bgt _081C1908
	ldr r0, [r6, #0x44]
	adds r0, #0x48
	movs r1, #0
	strh r1, [r0, #8]
	ldr r0, [r6, #0x44]
	adds r0, #0x48
	strh r1, [r0, #0xe]
_081C1908:
	ldr r7, _081C1978 @ =0x0000046E
	adds r0, r6, r7
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C1914
	b _081C1B40
_081C1914:
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, _081C197C @ =0x0000046B
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r5, [r0]
	adds r2, r6, #0
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
	blt _081C1966
	cmp r1, #0
	blt _081C1966
	ldr r0, _081C1980 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C1966
	ldr r0, _081C1984 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C1988
_081C1966:
	movs r4, #0
	b _081C1996
	.align 2, 0
_081C196C: .4byte 0xFFFEBE3F
_081C1970: .4byte 0x0000021E
_081C1974: .4byte 0x00000202
_081C1978: .4byte 0x0000046E
_081C197C: .4byte 0x0000046B
_081C1980: .4byte 0x030046A8
_081C1984: .4byte 0x030046AC
_081C1988:
	ldr r0, _081C19A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C1996:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C19AC
	adds r0, #4
	b _081C19B8
	.align 2, 0
_081C19A8: .4byte 0x030046A4
_081C19AC:
	ldr r0, _081C19CC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C19B8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C19D0
	cmp r2, #2
	beq _081C19D4
	b _081C19D8
	.align 2, 0
_081C19CC: .4byte 0x030046A4
_081C19D0:
	ldrb r0, [r5, #4]
	b _081C19D6
_081C19D4:
	ldrb r0, [r5]
_081C19D6:
	subs r1, r1, r0
_081C19D8:
	strh r1, [r5, #2]
	ldr r5, _081C1A04 @ =0x000004A4
	adds r0, r6, r5
	ldr r5, [r0]
	adds r7, r6, #0
	adds r7, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081C1A08
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	b _081C1A2E
	.align 2, 0
_081C1A04: .4byte 0x000004A4
_081C1A08:
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081C1A28
	cmp r0, #2
	beq _081C1A24
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C1A24:
	movs r0, #1
	b _081C1A38
_081C1A28:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r6, r3
_081C1A2E:
	ldr r1, _081C1A8C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081C1A38:
	adds r4, r0, #0
	cmp r4, #0
	bne _081C1AAC
	ldr r1, _081C1A90 @ =FUN_080e48d0
	ldr r5, _081C1A94 @ =0x0000046D
	adds r0, r6, r5
	movs r3, #1
	strb r3, [r0]
	ldr r7, _081C1A98 @ =0x0000046B
	adds r0, r6, r7
	strb r4, [r0]
	ldr r2, _081C1A9C @ =0x00000553
	adds r0, r6, r2
	strb r4, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r6, r5
	str r1, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	ldr r7, _081C1AA0 @ =0x00000469
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _081C1AA4 @ =0x0000046A
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081C1AA8 @ =0x00000484
	adds r0, r6, r2
	str r4, [r0]
	adds r5, #4
	adds r0, r6, r5
	strb r3, [r0]
	b _081C1B40
	.align 2, 0
_081C1A8C: .4byte 0xFFFFFDFF
_081C1A90: .4byte FUN_080e48d0
_081C1A94: .4byte 0x0000046D
_081C1A98: .4byte 0x0000046B
_081C1A9C: .4byte 0x00000553
_081C1AA0: .4byte 0x00000469
_081C1AA4: .4byte 0x0000046A
_081C1AA8: .4byte 0x00000484
_081C1AAC:
	movs r7, #0x95
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r1, [r0]
	movs r4, #0
	movs r5, #0
	movs r3, #1
	movs r0, #1
	strh r0, [r1, #6]
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r1, [r0]
	subs r7, #0x3f
	adds r0, r6, r7
	strb r3, [r0]
	ldr r1, _081C1B48 @ =0x0000046A
	adds r0, r6, r1
	strb r4, [r0]
	adds r2, #0x1c
	adds r0, r6, r2
	str r5, [r0]
	adds r7, #3
	adds r0, r6, r7
	strb r3, [r0]
	ldr r2, _081C1B4C @ =FUN_080e6794
	movs r1, #0xe
	adds r7, #1
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _081C1B50 @ =0x0000046B
	adds r0, r6, r3
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r3, [r0]
	movs r5, #7
	movs r1, #0x3c
	adds r7, #5
	adds r2, r6, r7
	subs r7, #4
	adds r0, r6, r7
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _081C1B54 @ =0x00000551
	adds r0, r6, r2
	strb r4, [r0]
	ldr r3, _081C1B58 @ =0x00000552
	adds r0, r6, r3
	strb r5, [r0]
_081C1B40:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C1B48: .4byte 0x0000046A
_081C1B4C: .4byte FUN_080e6794
_081C1B50: .4byte 0x0000046B
_081C1B54: .4byte 0x00000551
_081C1B58: .4byte 0x00000552

	thumb_func_start FUN_081c1b5c
FUN_081c1b5c: @ 0x081C1B5C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _081C1B74 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C1B78
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C1B7A
	.align 2, 0
_081C1B74: .4byte 0x0000046D
_081C1B78:
	movs r0, #0
_081C1B7A:
	cmp r0, #0
	beq _081C1BB8
	mov r4, sp
	adds r4, #5
	adds r0, r5, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_080e5d44
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	ldr r3, _081C1C40 @ =0x000004C4
	adds r2, r5, r3
	ldrb r2, [r2]
	add r3, sp, #4
	ldrb r3, [r3]
	ldrb r4, [r4]
	str r4, [sp]
	bl FUN_08237040
	movs r7, #0xe1
	lsls r7, r7, #1
	adds r2, r5, r7
	movs r1, #0
	movs r0, #0x20
	strh r0, [r2]
	ldr r2, _081C1C44 @ =0x0000046E
	adds r0, r5, r2
	strb r1, [r0]
_081C1BB8:
	ldr r3, _081C1C48 @ =0x00000482
	adds r1, r5, r3
	movs r4, #0
	movs r6, #0
	movs r0, #4
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ef86c
	movs r1, #0x10
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r0, r5, r7
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C1C38
	adds r0, r5, #0
	bl FUN_080fa7a4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C1BEE
	adds r0, r5, #0
	bl FUN_080faad8
_081C1BEE:
	movs r1, #8
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _081C1C4C @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r7, _081C1C50 @ =0x0000046A
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _081C1C54 @ =0x00000484
	adds r0, r5, r1
	str r6, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081C1C58 @ =FUN_081c1790
	movs r2, #0x13
	adds r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _081C1C5C @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
_081C1C38:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C1C40: .4byte 0x000004C4
_081C1C44: .4byte 0x0000046E
_081C1C48: .4byte 0x00000482
_081C1C4C: .4byte 0x00000469
_081C1C50: .4byte 0x0000046A
_081C1C54: .4byte 0x00000484
_081C1C58: .4byte FUN_081c1790
_081C1C5C: .4byte 0x0000046B

	thumb_func_start FUN_081c1c60
FUN_081c1c60: @ 0x081C1C60
	push {r4, r5, r6, lr}
	sub sp, #0x34
	adds r5, r0, #0
	ldr r0, _081C1C78 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C1C7C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C1C7E
	.align 2, 0
_081C1C78: .4byte 0x0000046D
_081C1C7C:
	movs r0, #0
_081C1C7E:
	cmp r0, #0
	beq _081C1CF4
	adds r0, r5, #0
	movs r1, #0xa
	bl FUN_080ef86c
	ldr r1, _081C1D9C @ =0x0000046E
	adds r0, r5, r1
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080e64b4
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r5, r3
	ldr r1, _081C1DA0 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _081C1DA4 @ =0x0000021E
	adds r0, r5, r1
	strh r4, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r4, [r0]
	adds r3, #0x8a
	adds r0, r5, r3
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080e81dc
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_081C1CF4:
	adds r0, r5, #0
	bl FUN_080e499c
	ldr r1, _081C1D9C @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C1D06
	b _081C1E7C
_081C1D06:
	ldr r2, _081C1DA8 @ =0x0000046B
	adds r0, r5, r2
	movs r4, #1
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_080e6658
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _081C1D74
	movs r1, #8
	ldrsh r0, [r5, r1]
	str r0, [sp, #0xc]
	movs r3, #0xa
	ldrsh r0, [r5, r3]
	str r0, [sp, #0x10]
	movs r1, #0xc
	ldrsh r0, [r5, r1]
	str r0, [sp, #0x14]
	movs r3, #0xce
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp, #0x18]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	adds r3, #8
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp, #0x20]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldrh r0, [r5]
	str r0, [sp, #0x28]
	ldr r1, _081C1DAC @ =0xFFFF0000
	ldr r0, [sp, #0x2c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x2c]
	add r1, sp, #0x2c
	add r3, sp, #0xc
	str r3, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081C1D74:
	ldr r1, _081C1DB0 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _081C1DB8
	ldr r0, _081C1DB4 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r1, r4, #0
	lsls r1, r3
	b _081C1DCA
	.align 2, 0
_081C1D9C: .4byte 0x0000046E
_081C1DA0: .4byte 0xFFFEBE3F
_081C1DA4: .4byte 0x0000021E
_081C1DA8: .4byte 0x0000046B
_081C1DAC: .4byte 0xFFFF0000
_081C1DB0: .4byte 0x000001DF
_081C1DB4: .4byte 0x030046A0
_081C1DB8:
	ldr r0, _081C1E54 @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_081C1DCA:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r5, #0
	adds r0, #8
	movs r1, #0x40
	str r1, [sp]
	movs r1, #0x28
	str r1, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r1, #2
	movs r2, #0
	movs r3, #0x80
	bl FUN_080dd8d4
	ldr r2, _081C1E58 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _081C1E5C @ =0x0000046D
	adds r0, r5, r3
	movs r6, #1
	strb r6, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r4, [r0]
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
	movs r1, #0
	strh r4, [r0]
	movs r2, #2
	subs r3, #0xeb
	adds r0, r5, r3
	strb r6, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _081C1E60 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _081C1E64 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r6, [r0]
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_080136b4
	ldr r2, _081C1E68 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C1E6C
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	b _081C1E76
	.align 2, 0
_081C1E54: .4byte 0x030046A0
_081C1E58: .4byte FUN_080e48d0
_081C1E5C: .4byte 0x0000046D
_081C1E60: .4byte 0x0000046A
_081C1E64: .4byte 0x00000484
_081C1E68: .4byte 0x0000025D
_081C1E6C:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r6
	str r0, [r1, #8]
_081C1E76:
	adds r0, r5, #0
	bl FUN_080e8360
_081C1E7C:
	add sp, #0x34
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081c1e84
FUN_081c1e84: @ 0x081C1E84
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r7, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _081C1E98
	b _081C2360
_081C1E98:
	ldr r0, _081C1EFC @ =0x00000464
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _081C1EA4
	b _081C2360
_081C1EA4:
	ldr r1, _081C1F00 @ =0x00000553
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _081C1F0C
	ldr r2, _081C1F04 @ =0x00000494
	adds r1, r7, r2
	movs r0, #0x20
	strh r0, [r1]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	subs r0, #0x31
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _081C1F08 @ =0x00000482
	adds r1, r7, r0
	movs r0, #1
	strh r0, [r1]
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
	strh r5, [r4]
	b _081C2360
	.align 2, 0
_081C1EFC: .4byte 0x00000464
_081C1F00: .4byte 0x00000553
_081C1F04: .4byte 0x00000494
_081C1F08: .4byte 0x00000482
_081C1F0C:
	ldr r1, _081C1F2C @ =0x00000316
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #2
	bls _081C1F30
	ldrh r0, [r4]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _081C1F4A
	movs r0, #0x10
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	b _081C1F44
	.align 2, 0
_081C1F2C: .4byte 0x00000316
_081C1F30:
	ldrh r0, [r4]
	movs r1, #0x30
	bl Mod
	cmp r0, #0
	bne _081C1F4A
	movs r0, #0x20
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r2, r7, r4
_081C1F44:
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081C1F4A:
	movs r5, #0x8c
	lsls r5, r5, #3
	adds r1, r7, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _081C1FA4
	movs r6, #0
	ldrh r1, [r1]
	cmp r6, r1
	bge _081C1FA4
	ldr r0, _081C1FE0 @ =0x00000462
	adds r3, r7, r0
	adds r2, r7, r5
_081C1F64:
	lsls r1, r6, #1
	movs r4, #0x8b
	lsls r4, r4, #3
	adds r0, r7, r4
	adds r5, r0, r1
	ldrh r4, [r5]
	cmp r4, #0
	bne _081C1F96
	adds r0, r7, #0
	movs r1, #1
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	bl FUN_080e64b4
	strh r4, [r5]
	movs r0, #1
	lsls r0, r6
	ldr r3, [sp, #0x18]
	ldrh r1, [r3]
	bics r1, r0
	strh r1, [r3]
	ldr r2, [sp, #0x14]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_081C1F96:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	adds r6, #1
	ldrh r5, [r2]
	cmp r6, r5
	blt _081C1F64
_081C1FA4:
	ldr r0, _081C1FE4 @ =0x00000464
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _081C1FEC
	adds r0, r7, #0
	movs r1, #4
	bl FUN_080e64b4
	ldr r1, _081C1FE0 @ =0x00000462
	adds r0, r7, r1
	strh r4, [r0]
	movs r2, #0x8c
	lsls r2, r2, #3
	adds r0, r7, r2
	strh r4, [r0]
	movs r1, #0
	movs r6, #3
	ldr r3, _081C1FE8 @ =0x0000045E
	adds r0, r7, r3
_081C1FD4:
	strh r1, [r0]
	subs r0, #2
	subs r6, #1
	cmp r6, #0
	bge _081C1FD4
	b _081C2176
	.align 2, 0
_081C1FE0: .4byte 0x00000462
_081C1FE4: .4byte 0x00000464
_081C1FE8: .4byte 0x0000045E
_081C1FEC:
	ldrh r0, [r1]
	movs r1, #0x28
	bl Mod
	cmp r0, #0
	beq _081C1FFA
	b _081C2176
_081C1FFA:
	ldr r4, _081C2050 @ =0x00000316
	adds r1, r7, r4
	movs r0, #2
	ldrb r1, [r1]
	lsls r0, r1
	movs r5, #0x8b
	lsls r5, r5, #1
	adds r3, r7, r5
	strh r0, [r3]
	ldr r2, _081C2054 @ =0x0000048A
	adds r1, r7, r2
	strh r0, [r1]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r0, [r2]
	ldrh r1, [r3]
	subs r0, r0, r1
	strh r0, [r2]
	movs r5, #0x93
	lsls r5, r5, #3
	adds r2, r7, r5
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	beq _081C2036
	b _081C2176
_081C2036:
	ldr r1, _081C2058 @ =0x0000047C
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _081C205C @ =0x0000025D
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C2060
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _081C206C
	.align 2, 0
_081C2050: .4byte 0x00000316
_081C2054: .4byte 0x0000048A
_081C2058: .4byte 0x0000047C
_081C205C: .4byte 0x0000025D
_081C2060:
	ldr r2, [r7, #0x44]
	ldr r0, _081C2098 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081C206C:
	ldr r3, _081C209C @ =0x00000492
	adds r1, r7, r3
	movs r0, #8
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #8
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081C20A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C20A4
	movs r0, #1
	b _081C20A6
	.align 2, 0
_081C2098: .4byte 0x03003584
_081C209C: .4byte 0x00000492
_081C20A0: .4byte 0x030047A4
_081C20A4:
	movs r0, #0
_081C20A6:
	cmp r0, #0
	beq _081C2114
	movs r5, #0x94
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _081C2114
	cmp r2, #0
	beq _081C2114
	ldr r0, _081C20CC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081C20D0
	movs r0, #1
	rsbs r0, r0, #0
	b _081C20D4
	.align 2, 0
_081C20CC: .4byte 0x03002C68
_081C20D0:
	movs r2, #0x18
	ldrsh r0, [r0, r2]
_081C20D4:
	cmp r0, #1
	beq _081C20F6
	cmp r0, #1
	bgt _081C20E2
	cmp r0, #0
	beq _081C20EC
	b _081C2114
_081C20E2:
	cmp r0, #2
	beq _081C2100
	cmp r0, #3
	beq _081C210A
	b _081C2114
_081C20EC:
	ldr r0, [r1]
	cmp r0, #1
	beq _081C2114
	movs r0, #0
	b _081C2116
_081C20F6:
	ldr r0, [r1]
	cmp r0, #2
	beq _081C2114
	movs r0, #0
	b _081C2116
_081C2100:
	ldr r0, [r1]
	cmp r0, #4
	beq _081C2114
	movs r0, #0
	b _081C2116
_081C210A:
	ldr r0, [r1]
	cmp r0, #8
	beq _081C2114
	movs r0, #0
	b _081C2116
_081C2114:
	movs r0, #1
_081C2116:
	cmp r0, #0
	beq _081C2176
	ldrh r0, [r7]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	movs r5, #0x95
	lsls r5, r5, #2
	adds r2, r7, r5
	ldrh r2, [r2]
	ldr r4, _081C21EC @ =0x0000025A
	adds r3, r7, r4
	ldrh r3, [r3]
	movs r4, #0
	str r4, [sp]
	bl FUN_0809c344
	add r5, sp, #0xc
	str r4, [sp, #8]
	add r0, sp, #8
	adds r1, r5, #0
	ldr r2, _081C21F0 @ =0x05000002
	bl CpuSet
	ldr r0, _081C21F4 @ =0x0000048A
	adds r2, r7, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _081C2160
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _081C2176
_081C2160:
	adds r0, r7, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r7, #0
	adds r3, #8
	str r5, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
_081C2176:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _081C2186
	b _081C2360
_081C2186:
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r2, #0
	strb r1, [r0]
	ldr r4, _081C21F8 @ =0x00000469
	adds r0, r7, r4
	strb r2, [r0]
	ldr r5, _081C21FC @ =0x0000046A
	adds r0, r7, r5
	strb r2, [r0]
	ldr r1, _081C2200 @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	adds r3, #4
	adds r0, r7, r3
	movs r1, #1
	strb r1, [r0]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r4, [r0]
	movs r3, #0x11
	adds r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _081C2204 @ =0x0000046B
	adds r0, r7, r1
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
	ldr r0, _081C2208 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C220C
	movs r0, #1
	b _081C220E
	.align 2, 0
_081C21EC: .4byte 0x0000025A
_081C21F0: .4byte 0x05000002
_081C21F4: .4byte 0x0000048A
_081C21F8: .4byte 0x00000469
_081C21FC: .4byte 0x0000046A
_081C2200: .4byte 0x00000484
_081C2204: .4byte 0x0000046B
_081C2208: .4byte 0x030047A4
_081C220C:
	movs r0, #0
_081C220E:
	cmp r0, #0
	beq _081C2228
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r0, [r0]
	movs r5, #0x93
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r1, [r1]
	bl FUN_080ce544
	b _081C2352
_081C2228:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r2, _081C224C @ =0x00000474
	adds r5, r7, r2
	cmp r0, #0
	beq _081C22F2
	movs r1, #0x80
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081C2250
	movs r0, #1
	b _081C2252
	.align 2, 0
_081C224C: .4byte 0x00000474
_081C2250:
	movs r0, #0
_081C2252:
	cmp r0, #0
	bne _081C22F2
	ldr r3, _081C2290 @ =0x000001DF
	adds r0, r7, r3
	ldrb r1, [r0]
	cmp r1, #0xe
	bne _081C226C
	movs r4, #0x90
	lsls r4, r4, #3
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r0, #1
	beq _081C22D4
_081C226C:
	cmp r1, #5
	beq _081C22D4
	cmp r1, #7
	beq _081C22D4
	cmp r1, #6
	beq _081C22D4
	ldr r2, _081C2294 @ =0x030046A0
	ldr r0, [r2]
	ldr r1, _081C2298 @ =0x00000948
	adds r3, r0, r1
	ldrh r4, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _081C229C @ =0x0000270E
	cmp r1, r0
	bgt _081C22A0
	adds r0, r4, #1
	b _081C22A4
	.align 2, 0
_081C2290: .4byte 0x000001DF
_081C2294: .4byte 0x030046A0
_081C2298: .4byte 0x00000948
_081C229C: .4byte 0x0000270E
_081C22A0:
	ldr r1, _081C22C0 @ =0x0000270F
	adds r0, r1, #0
_081C22A4:
	strh r0, [r3]
	ldr r0, [r2]
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	ldr r0, _081C22C4 @ =0x0000270E
	cmp r1, r0
	bgt _081C22C8
	adds r0, r3, #1
	b _081C22CC
	.align 2, 0
_081C22C0: .4byte 0x0000270F
_081C22C4: .4byte 0x0000270E
_081C22C8:
	ldr r1, _081C2300 @ =0x0000270F
	adds r0, r1, #0
_081C22CC:
	strh r0, [r2]
	adds r0, r7, #0
	bl FUN_080e9178
_081C22D4:
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	bl FUN_0807a798
	movs r3, #0x93
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r4, _081C2304 @ =0x00000189
	adds r1, r7, r4
	ldrb r1, [r1]
	bl FUN_0807a840
_081C22F2:
	movs r1, #0x80
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081C2308
	movs r0, #1
	b _081C230A
	.align 2, 0
_081C2300: .4byte 0x0000270F
_081C2304: .4byte 0x00000189
_081C2308:
	movs r0, #0
_081C230A:
	cmp r0, #0
	bne _081C2346
	ldr r0, _081C2320 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C2324
	movs r0, #1
	b _081C2326
	.align 2, 0
_081C2320: .4byte 0x030047A4
_081C2324:
	movs r0, #0
_081C2326:
	cmp r0, #0
	bne _081C2346
	movs r1, #0x80
	lsls r1, r1, #4
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081C2346
	ldr r0, _081C2368 @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r7]
	bl FUN_080ec5b4
_081C2346:
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_081C2352:
	ldr r1, _081C236C @ =0x00000464
	adds r0, r7, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _081C2370 @ =0x000004BE
	adds r0, r7, r2
	strh r1, [r0]
_081C2360:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C2368: .4byte 0x03002B28
_081C236C: .4byte 0x00000464
_081C2370: .4byte 0x000004BE

	thumb_func_start FUN_081c2374
FUN_081c2374: @ 0x081C2374
	push {lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r2, _081C2394 @ =0x0000065C
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C2398
	movs r0, #1
	b _081C239A
	.align 2, 0
_081C2394: .4byte 0x0000065C
_081C2398:
	movs r0, #0
_081C239A:
	cmp r0, #0
	bne _081C23EC
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C23EC
	adds r1, #0x58
	adds r0, r3, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081C23DA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C23C2
	adds r2, r0, #0
_081C23C2:
	cmp r2, #0
	blt _081C23DA
	ldr r1, _081C23F0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C23EC
_081C23DA:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _081C23EC
	adds r0, r3, #0
	bl FUN_081b8c14
_081C23EC:
	pop {r0}
	bx r0
	.align 2, 0
_081C23F0: .4byte 0x03002BE0

	thumb_func_start FUN_081c23f4
FUN_081c23f4: @ 0x081C23F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18c
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x34]
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r3, _081C24E4 @ =0x0000065C
	adds r1, r0, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r6, r7, r4
	ldr r0, [r6]
	ldr r5, _081C24E8 @ =0xFEFFFFFF
	ands r0, r5
	str r0, [r6]
	ldr r0, _081C24EC @ =0x0000049C
	adds r0, r0, r7
	mov sl, r0
	ldr r4, [r0]
	movs r0, #4
	ands r4, r0
	cmp r4, #0
	bne _081C243A
	b _081C2750
_081C243A:
	movs r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	ldr r1, _081C24F0 @ =0xFFFF5FD8
	ands r0, r1
	strh r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r0, _081C24F4 @ =0xFFFFF634
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _081C24F8 @ =0xFFFFBFFF
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	ldr r5, _081C24FC @ =0x00000316
	adds r4, r7, r5
	ldrb r0, [r4]
	cmp r0, #3
	bhi _081C24B8
	movs r0, #0x14
	str r0, [sp]
	subs r0, #0x15
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0xa
	bl FUN_080e6408
	movs r6, #0x8c
	lsls r6, r6, #3
	adds r2, r7, r6
	ldrh r0, [r2]
	lsls r0, r0, #1
	movs r3, #0x8b
	lsls r3, r3, #3
	adds r1, r7, r3
	adds r1, r1, r0
	movs r0, #0x91
	lsls r0, r0, #2
	strh r0, [r1]
	ldr r5, _081C2500 @ =0x00000462
	adds r3, r7, r5
	movs r0, #1
	ldrh r6, [r2]
	lsls r0, r6
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
_081C24B8:
	movs r1, #1
	ldrb r4, [r4]
	lsls r1, r4
	ldr r2, _081C2504 @ =0x0000048A
	adds r0, r7, r2
	strh r1, [r0]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	ldr r0, _081C2508 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C250C
	movs r0, #1
	b _081C250E
	.align 2, 0
_081C24E4: .4byte 0x0000065C
_081C24E8: .4byte 0xFEFFFFFF
_081C24EC: .4byte 0x0000049C
_081C24F0: .4byte 0xFFFF5FD8
_081C24F4: .4byte 0xFFFFF634
_081C24F8: .4byte 0xFFFFBFFF
_081C24FC: .4byte 0x00000316
_081C2500: .4byte 0x00000462
_081C2504: .4byte 0x0000048A
_081C2508: .4byte 0x030047A4
_081C250C:
	movs r0, #0
_081C250E:
	cmp r0, #0
	beq _081C257C
	movs r4, #0x94
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _081C257C
	cmp r2, #0
	beq _081C257C
	ldr r0, _081C2534 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081C2538
	movs r0, #1
	rsbs r0, r0, #0
	b _081C253C
	.align 2, 0
_081C2534: .4byte 0x03002C68
_081C2538:
	movs r5, #0x18
	ldrsh r0, [r0, r5]
_081C253C:
	cmp r0, #1
	beq _081C255E
	cmp r0, #1
	bgt _081C254A
	cmp r0, #0
	beq _081C2554
	b _081C257C
_081C254A:
	cmp r0, #2
	beq _081C2568
	cmp r0, #3
	beq _081C2572
	b _081C257C
_081C2554:
	ldr r0, [r1]
	cmp r0, #1
	beq _081C257C
	movs r0, #0
	b _081C257E
_081C255E:
	ldr r0, [r1]
	cmp r0, #2
	beq _081C257C
	movs r0, #0
	b _081C257E
_081C2568:
	ldr r0, [r1]
	cmp r0, #4
	beq _081C257C
	movs r0, #0
	b _081C257E
_081C2572:
	ldr r0, [r1]
	cmp r0, #8
	beq _081C257C
	movs r0, #0
	b _081C257E
_081C257C:
	movs r0, #1
_081C257E:
	cmp r0, #0
	beq _081C25E4
	ldrh r0, [r7]
	movs r6, #0xc2
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #0x95
	lsls r3, r3, #2
	adds r2, r7, r3
	ldrh r2, [r2]
	ldr r4, _081C2684 @ =0x0000025A
	adds r3, r7, r4
	ldrh r3, [r3]
	movs r5, #1
	str r5, [sp]
	bl FUN_0809c344
	add r4, sp, #0xc
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #8
	adds r1, r4, #0
	ldr r2, _081C2688 @ =0x05000002
	bl CpuSet
	ldr r6, _081C268C @ =0x0000048A
	adds r2, r7, r6
	ldrh r0, [r2]
	cmp r0, #0
	bne _081C25D0
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _081C25E4
_081C25D0:
	adds r0, r7, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r7, #0
	adds r3, #8
	str r4, [sp]
	str r5, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
_081C25E4:
	movs r0, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x38]
	movs r1, #0
	strb r0, [r2]
	ldr r3, _081C2690 @ =0x00000469
	adds r3, r7, r3
	str r3, [sp, #0x3c]
	strb r1, [r3]
	ldr r4, _081C2694 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x40]
	strb r1, [r4]
	ldr r5, _081C2698 @ =0x00000484
	adds r5, r7, r5
	str r5, [sp, #0x44]
	str r1, [r5]
	ldr r6, _081C269C @ =0x0000046C
	adds r6, r7, r6
	str r6, [sp, #0x48]
	movs r0, #1
	strb r0, [r6]
	ldr r3, _081C26A0 @ =FUN_081c1b5c
	movs r2, #0x2d
	ldr r4, _081C26A4 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	strb r0, [r4]
	ldr r5, _081C26A8 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x50]
	strb r1, [r5]
	ldr r6, _081C26AC @ =0x00000553
	adds r5, r7, r6
	strb r2, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r4, r7, r0
	str r3, [r4]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r2, r7, r3
	strh r1, [r2]
	subs r6, #0xef
	adds r1, r7, r6
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	ldr r1, _081C26B0 @ =0x0000047E
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r3, #0x95
	adds r0, r7, r3
	ldrb r0, [r0]
	ldr r6, [sp, #0x38]
	str r6, [sp, #0x164]
	ldr r3, [sp, #0x3c]
	str r3, [sp, #0x168]
	ldr r6, [sp, #0x40]
	str r6, [sp, #0x16c]
	ldr r3, [sp, #0x44]
	str r3, [sp, #0x180]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x174]
	ldr r3, [sp, #0x4c]
	str r3, [sp, #0x178]
	ldr r6, [sp, #0x50]
	str r6, [sp, #0x170]
	str r5, [sp, #0x144]
	str r4, [sp, #0x148]
	str r2, [sp, #0x15c]
	cmp r0, #0
	bne _081C26B4
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _081C26C0
	.align 2, 0
_081C2684: .4byte 0x0000025A
_081C2688: .4byte 0x05000002
_081C268C: .4byte 0x0000048A
_081C2690: .4byte 0x00000469
_081C2694: .4byte 0x0000046A
_081C2698: .4byte 0x00000484
_081C269C: .4byte 0x0000046C
_081C26A0: .4byte FUN_081c1b5c
_081C26A4: .4byte 0x0000046D
_081C26A8: .4byte 0x0000046B
_081C26AC: .4byte 0x00000553
_081C26B0: .4byte 0x0000047E
_081C26B4:
	ldr r2, [r7, #0x44]
	ldr r0, _081C273C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081C26C0:
	movs r2, #0x80
	lsls r2, r2, #0x12
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _081C2740 @ =0x00000494
	adds r1, r7, r2
	movs r5, #0
	movs r4, #0
	ldr r0, _081C2744 @ =0x00001770
	strh r0, [r1]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_080e81dc
	ldr r3, _081C2748 @ =0x000004BE
	adds r0, r7, r3
	strh r4, [r0]
	movs r6, #0xc2
	lsls r6, r6, #1
	adds r0, r7, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _081C26FC
	bl _081C491C
_081C26FC:
	movs r0, #3
	ldr r2, [sp, #0x164]
	strb r0, [r2]
	ldr r3, [sp, #0x168]
	strb r5, [r3]
	ldr r6, [sp, #0x16c]
	strb r5, [r6]
	ldr r0, [sp, #0x180]
	str r4, [r0]
	movs r1, #1
	ldr r2, [sp, #0x174]
	strb r1, [r2]
	movs r3, #0xba
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r2, [r0]
	movs r0, #0x11
	ldr r6, [sp, #0x178]
	strb r1, [r6]
	ldr r1, [sp, #0x170]
	strb r5, [r1]
	ldr r3, [sp, #0x144]
	strb r0, [r3]
	ldr r5, [sp, #0x148]
	str r2, [r5]
	ldr r6, [sp, #0x15c]
	strh r4, [r6]
	ldr r1, _081C274C @ =0x00000464
	adds r0, r7, r1
	strh r4, [r0]
	bl _081C491C
	.align 2, 0
_081C273C: .4byte 0x03003584
_081C2740: .4byte 0x00000494
_081C2744: .4byte 0x00001770
_081C2748: .4byte 0x000004BE
_081C274C: .4byte 0x00000464
_081C2750:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_080e81dc
	movs r2, #0x10
	mov sb, r2
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r5, [r1]
	mov r8, r5
	mov r2, r8
	adds r0, r2, #0
	mov r3, sb
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	str r1, [sp, #0x158]
	cmp r5, #0
	beq _081C2800
	movs r1, #8
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	strb r4, [r0]
	ldr r6, _081C27E8 @ =0x00000469
	adds r0, r7, r6
	strb r4, [r0]
	ldr r2, _081C27EC @ =0x0000046A
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _081C27F0 @ =0x00000484
	adds r0, r7, r3
	str r4, [r0]
	adds r5, #4
	adds r0, r7, r5
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081C27F4 @ =FUN_081c1790
	movs r2, #0x13
	adds r6, #4
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081C27F8 @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	adds r5, #0xe7
	adds r0, r7, r5
	strb r2, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	ldr r0, _081C27FC @ =0xFFFFDFDF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r7, #0
	bl FUN_080fa7a4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C27DC
	bl _081C491C
_081C27DC:
	adds r0, r7, #0
	bl FUN_080faad8
	bl _081C491C
	.align 2, 0
_081C27E8: .4byte 0x00000469
_081C27EC: .4byte 0x0000046A
_081C27F0: .4byte 0x00000484
_081C27F4: .4byte FUN_081c1790
_081C27F8: .4byte 0x0000046B
_081C27FC: .4byte 0xFFFFDFDF
_081C2800:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r2
	cmp r0, #0
	bne _081C280C
	b _081C2F0C
_081C280C:
	ldr r3, _081C2898 @ =0x000001DD
	adds r0, r7, r3
	ldrb r0, [r0]
	adds r0, #0x80
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, _081C289C @ =0xFFFFDFDF
	ldr r4, [sp, #0x158]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	ldr r6, _081C28A0 @ =0x00000544
	adds r1, r7, r6
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	adds r0, #0x4c
	adds r1, r7, r0
	ldr r0, [r1]
	mov r2, sb
	orrs r0, r2
	str r0, [r1]
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r0, [r0]
	strh r5, [r0, #6]
	adds r0, r7, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C2858
	bl _081C314C
_081C2858:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r3, r7, r4
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
	str r3, [sp, #0x184]
	str r2, [sp, #0x150]
	cmp r4, #0
	blt _081C2894
	cmp r1, #0
	blt _081C2894
	ldr r0, _081C28A4 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081C2894
	ldr r0, _081C28A8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C28AC
_081C2894:
	movs r4, #0
	b _081C28BA
	.align 2, 0
_081C2898: .4byte 0x000001DD
_081C289C: .4byte 0xFFFFDFDF
_081C28A0: .4byte 0x00000544
_081C28A4: .4byte 0x030046A8
_081C28A8: .4byte 0x030046AC
_081C28AC:
	ldr r0, _081C28CC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081C28BA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C28D0
	adds r0, #4
	b _081C28DC
	.align 2, 0
_081C28CC: .4byte 0x030046A4
_081C28D0:
	ldr r0, _081C28F0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C28DC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C28F4
	cmp r2, #2
	beq _081C28F8
	b _081C28FC
	.align 2, 0
_081C28F0: .4byte 0x030046A4
_081C28F4:
	ldrb r0, [r5, #4]
	b _081C28FA
_081C28F8:
	ldrb r0, [r5]
_081C28FA:
	subs r1, r1, r0
_081C28FC:
	strh r1, [r5, #2]
	ldr r0, _081C2910 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C2914
	movs r0, #1
	b _081C2916
	.align 2, 0
_081C2910: .4byte 0x030047A4
_081C2914:
	movs r0, #0
_081C2916:
	cmp r0, #0
	beq _081C2954
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _081C2936
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C2932
	adds r2, r0, #0
_081C2932:
	cmp r2, #0
	bge _081C2940
_081C2936:
	ldr r6, _081C293C @ =0x000005C4
	adds r0, r7, r6
	b _081C2E78
	.align 2, 0
_081C293C: .4byte 0x000005C4
_081C2940:
	ldr r1, _081C2950 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081C299C
	.align 2, 0
_081C2950: .4byte 0x03002BE0
_081C2954:
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
	blt _081C2980
	cmp r1, #0
	blt _081C2980
	ldr r0, _081C2984 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C2980
	ldr r0, _081C2988 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C298C
_081C2980:
	movs r5, #0
	b _081C299A
	.align 2, 0
_081C2984: .4byte 0x030046A8
_081C2988: .4byte 0x030046AC
_081C298C:
	ldr r0, _081C29D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081C299A:
	movs r2, #0
_081C299C:
	ldr r3, _081C29D8 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081C29BC
	ldr r1, _081C29DC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C29BC
	b _081C2DB4
_081C29BC:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x158]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x54]
	cmp r0, #0
	beq _081C29E0
	movs r0, #0
	b _081C2E8E
	.align 2, 0
_081C29D4: .4byte 0x030046A4
_081C29D8: .4byte 0x00000256
_081C29DC: .4byte 0x03002BE0
_081C29E0:
	ldr r5, _081C2A84 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0x158]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0x160]
	cmp r6, #0
	beq _081C2AA4
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _081C2A88 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x58]
	movs r5, #1
	strb r5, [r2]
	ldr r3, _081C2A8C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x5c]
	movs r4, #0
	strb r4, [r3]
	ldr r6, _081C2A90 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x60]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x64]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x68]
	add r2, sp, #0x54
	ldrh r2, [r2]
	strh r2, [r1]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _081C2A94 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _081C2A98 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081C2A9C @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x54]
	str r6, [r1]
	ldr r6, _081C2AA0 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	str r4, [sp, #0x164]
	str r3, [sp, #0x168]
	str r2, [sp, #0x16c]
	str r1, [sp, #0x180]
	str r0, [sp, #0x174]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0x178]
	ldr r1, [sp, #0x5c]
	str r1, [sp, #0x170]
	ldr r2, [sp, #0x60]
	str r2, [sp, #0x144]
	ldr r3, [sp, #0x64]
	str r3, [sp, #0x148]
	ldr r4, [sp, #0x68]
	str r4, [sp, #0x15c]
	b _081C2C72
	.align 2, 0
_081C2A84: .4byte 0x00000222
_081C2A88: .4byte 0x0000046D
_081C2A8C: .4byte 0x0000046B
_081C2A90: .4byte 0x00000553
_081C2A94: .4byte 0x00000469
_081C2A98: .4byte 0x0000046A
_081C2A9C: .4byte 0x00000484
_081C2AA0: .4byte 0x0000046C
_081C2AA4:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081C2B68 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x6c]
	strb r0, [r2]
	ldr r3, _081C2B6C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x70]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x4d
	adds r5, r7, r5
	str r5, [sp, #0x74]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x78]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x7c]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x80]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081C2B70 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081C2B74 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081C2B78 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x184]
	ldr r0, [r0]
	str r0, [sp, #0x84]
	ldr r1, [sp, #0x150]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x84]
	strh r1, [r6]
	ldr r6, [sp, #0x150]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x84]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x80]
	str r0, [sp, #0x164]
	str r5, [sp, #0x168]
	str r4, [sp, #0x16c]
	str r3, [sp, #0x180]
	str r2, [sp, #0x174]
	ldr r2, [sp, #0x6c]
	str r2, [sp, #0x178]
	ldr r3, [sp, #0x70]
	str r3, [sp, #0x170]
	ldr r4, [sp, #0x74]
	str r4, [sp, #0x144]
	ldr r5, [sp, #0x78]
	str r5, [sp, #0x148]
	ldr r6, [sp, #0x7c]
	str r6, [sp, #0x15c]
	mov r0, sb
	cmp r0, #0
	blt _081C2B62
	cmp r1, #0
	blt _081C2B62
	ldr r0, _081C2B7C @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _081C2B62
	ldr r0, _081C2B80 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C2B84
_081C2B62:
	movs r4, #0
	b _081C2B94
	.align 2, 0
_081C2B68: .4byte 0x0000046D
_081C2B6C: .4byte 0x0000046B
_081C2B70: .4byte 0x00000469
_081C2B74: .4byte 0x00000484
_081C2B78: .4byte 0x0000046C
_081C2B7C: .4byte 0x030046A8
_081C2B80: .4byte 0x030046AC
_081C2B84:
	ldr r0, _081C2BA4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_081C2B94:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C2BA8
	adds r0, #4
	b _081C2BB4
	.align 2, 0
_081C2BA4: .4byte 0x030046A4
_081C2BA8:
	ldr r0, _081C2BC8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C2BB4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C2BCC
	cmp r2, #2
	beq _081C2BD2
	b _081C2BD8
	.align 2, 0
_081C2BC8: .4byte 0x030046A4
_081C2BCC:
	ldr r2, [sp, #0x84]
	ldrb r0, [r2, #4]
	b _081C2BD6
_081C2BD2:
	ldr r3, [sp, #0x84]
	ldrb r0, [r3]
_081C2BD6:
	subs r1, r1, r0
_081C2BD8:
	ldr r4, [sp, #0x84]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x184]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C2C04
	cmp r1, #0
	blt _081C2C04
	ldr r0, _081C2C08 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C2C04
	ldr r0, _081C2C0C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C2C10
_081C2C04:
	movs r4, #0
	b _081C2C1E
	.align 2, 0
_081C2C08: .4byte 0x030046A8
_081C2C0C: .4byte 0x030046AC
_081C2C10:
	ldr r0, _081C2C34 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C2C1E:
	ldr r6, [sp, #0x184]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C2C38
	adds r0, #4
	b _081C2C44
	.align 2, 0
_081C2C34: .4byte 0x030046A4
_081C2C38:
	ldr r0, _081C2C58 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C2C44:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C2C5C
	cmp r3, #2
	beq _081C2C60
	b _081C2C64
	.align 2, 0
_081C2C58: .4byte 0x030046A4
_081C2C5C:
	ldrb r0, [r5, #4]
	b _081C2C62
_081C2C60:
	ldrb r0, [r5]
_081C2C62:
	subs r2, r2, r0
_081C2C64:
	ldr r1, [sp, #0x184]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x184]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081C2C72:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x88]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x158]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _081C2C9C @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	cmp r0, #0
	bne _081C2D7A
	movs r1, #4
	ldr r2, [sp, #0x160]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C2CA0
	movs r0, #1
	b _081C2CA2
	.align 2, 0
_081C2C9C: .4byte 0x00000482
_081C2CA0:
	movs r0, #0
_081C2CA2:
	ldr r3, _081C2D8C @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	cmp r0, #0
	bne _081C2D7A
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _081C2D90 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081C2D94 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081C2D98 @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x140]
	ldr r2, _081C2D9C @ =0x00000541
	adds r2, r2, r7
	mov ip, r2
	ldr r0, _081C2DA0 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x14c]
	ldr r1, _081C2DA4 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r1, _081C2DA8 @ =0x030046B8
	str r5, [sp, #0x188]
_081C2CE8:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081C2DAC @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081C2DB0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x188]
	cmp r0, r2
	bne _081C2D0E
	adds r3, #1
	cmp r3, #3
	ble _081C2CE8
	adds r0, r5, #0
_081C2D0E:
	movs r3, #0
	strb r0, [r4]
	ldr r4, [sp, #0x148]
	ldr r0, [r4]
	str r0, [r6]
	ldr r5, [sp, #0x144]
	ldrb r0, [r5]
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x164]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x168]
	ldrb r0, [r4]
	mov r5, sl
	strb r0, [r5]
	ldr r6, [sp, #0x16c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x140]
	strb r0, [r1]
	add r2, sp, #0x88
	ldrb r4, [r2]
	mov r2, ip
	strb r4, [r2]
	ldr r4, [sp, #0x14c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x178]
	strb r1, [r5]
	ldr r6, [sp, #0x170]
	strb r3, [r6]
	ldr r4, [sp, #0x144]
	strb r0, [r4]
	ldr r5, [sp, #0x148]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x15c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x164]
	strb r0, [r4]
	ldr r5, [sp, #0x168]
	strb r1, [r5]
	ldr r6, [sp, #0x16c]
	strb r2, [r6]
	ldr r0, [sp, #0x180]
	str r3, [r0]
	ldr r2, [sp, #0x174]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x13c]
	strb r0, [r3]
_081C2D7A:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x17c]
	strh r0, [r4]
	movs r0, #0
	b _081C2E8E
	.align 2, 0
_081C2D8C: .4byte 0x00000482
_081C2D90: .4byte 0x0000054F
_081C2D94: .4byte 0x0000054C
_081C2D98: .4byte 0x0000054E
_081C2D9C: .4byte 0x00000541
_081C2DA0: .4byte 0x000005BC
_081C2DA4: .4byte 0x00000542
_081C2DA8: .4byte 0x030046B8
_081C2DAC: .4byte 0x000003FF
_081C2DB0: .4byte 0x0203B400
_081C2DB4:
	add r6, sp, #0x14
	ldr r0, _081C2DF4 @ =0x030046A4
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
	beq _081C2DF8
	adds r0, #4
	b _081C2E04
	.align 2, 0
_081C2DF4: .4byte 0x030046A4
_081C2DF8:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C2E04:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081C2E3C @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _081C2E44
	ldr r0, _081C2E40 @ =0xFFFFFDFF
	ldr r6, [sp, #0x158]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081C2E6E
	.align 2, 0
_081C2E3C: .4byte 0x000004A4
_081C2E40: .4byte 0xFFFFFDFF
_081C2E44:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081C2E64
	cmp r0, #2
	beq _081C2E60
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C2E60:
	movs r0, #1
	b _081C2E70
_081C2E64:
	ldr r0, _081C2E84 @ =0xFFFFFDFF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081C2E6E:
	movs r0, #0
_081C2E70:
	cmp r0, #0
	bne _081C2E8C
	ldr r3, _081C2E88 @ =0x000005C4
	adds r0, r7, r3
_081C2E78:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081C2E8E
	.align 2, 0
_081C2E84: .4byte 0xFFFFFDFF
_081C2E88: .4byte 0x000005C4
_081C2E8C:
	movs r0, #1
_081C2E8E:
	cmp r0, #0
	beq _081C2E96
	bl _081C48C4
_081C2E96:
	ldr r4, _081C2EC8 @ =0x000004A4
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
	bne _081C2ED0
	ldr r0, _081C2ECC @ =0xFFFFFDFF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C2EFA
	.align 2, 0
_081C2EC8: .4byte 0x000004A4
_081C2ECC: .4byte 0xFFFFFDFF
_081C2ED0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081C2EF0
	cmp r0, #2
	beq _081C2EEC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C2EEC:
	movs r0, #1
	b _081C2EFC
_081C2EF0:
	ldr r0, _081C2F08 @ =0xFFFFFDFF
	ldr r3, [sp, #0x158]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C2EFA:
	movs r0, #0
_081C2EFC:
	cmp r0, #0
	bne _081C2F04
	bl _081C48AC
_081C2F04:
	bl _081C48C4
	.align 2, 0
_081C2F08: .4byte 0xFFFFFDFF
_081C2F0C:
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081C2F26
	movs r0, #0x21
	rsbs r0, r0, #0
	mov r1, r8
	ands r0, r1
	ldr r2, [sp, #0x158]
	b _081C314A
_081C2F26:
	movs r0, #2
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _081C2FBC
	movs r5, #0x83
	lsls r5, r5, #2
	adds r3, r7, r5
	movs r6, #0x85
	lsls r6, r6, #2
	adds r2, r7, r6
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r1, _081C2FA0 @ =0x00000594
	adds r0, r7, r1
	ldr r2, [r0]
	movs r1, #7
	ldr r3, _081C2FA4 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r5, _081C2FA8 @ =0x0000046B
	adds r0, r7, r5
	strb r4, [r0]
	ldr r6, _081C2FAC @ =0x00000553
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
	ldr r1, _081C2FB0 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _081C2FB4 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	ldr r4, _081C2FB8 @ =0x0000046C
	adds r0, r7, r4
	strb r3, [r0]
	bl _081C491C
	.align 2, 0
_081C2FA0: .4byte 0x00000594
_081C2FA4: .4byte 0x0000046D
_081C2FA8: .4byte 0x0000046B
_081C2FAC: .4byte 0x00000553
_081C2FB0: .4byte 0x0000046A
_081C2FB4: .4byte 0x00000484
_081C2FB8: .4byte 0x0000046C
_081C2FBC:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r2, r0
	lsls r0, r2, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _081C2FCC
	b _081C3158
_081C2FCC:
	movs r5, #0x93
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r5, [r0]
	movs r0, #0x80
	ands r5, r0
	cmp r5, #0
	beq _081C3088
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r2, #0
	strh r0, [r1]
	ldr r3, _081C3070 @ =0x000005CC
	adds r0, r7, r3
	ldr r4, [r0]
	movs r1, #0x12
	ldr r5, _081C3074 @ =0x0000046D
	adds r0, r7, r5
	movs r3, #1
	strb r3, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
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
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r7, r4
	strb r1, [r0]
	ldr r5, _081C3078 @ =0x00000469
	adds r0, r7, r5
	strb r2, [r0]
	ldr r1, _081C307C @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _081C3080 @ =0x00000484
	adds r0, r7, r2
	mov r4, sb
	str r4, [r0]
	adds r5, #3
	adds r0, r7, r5
	strb r3, [r0]
	mov r1, sl
	ldr r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	mov r2, sl
	str r0, [r2]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r7, r4
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _081C3084 @ =0xFEFFFFFC
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	adds r5, #0x16
	adds r0, r7, r5
	strh r3, [r0]
	bl _081C491C
	.align 2, 0
_081C3070: .4byte 0x000005CC
_081C3074: .4byte 0x0000046D
_081C3078: .4byte 0x00000469
_081C307C: .4byte 0x0000046A
_081C3080: .4byte 0x00000484
_081C3084: .4byte 0xFEFFFFFC
_081C3088:
	mov r1, sl
	ldr r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _081C311C
	movs r2, #0xc8
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r2, #0
	strh r0, [r1]
	ldr r4, _081C3108 @ =0x000005CC
	adds r0, r7, r4
	ldr r0, [r0]
	mov r8, r0
	movs r1, #0x12
	ldr r3, _081C310C @ =0x0000046D
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r2, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r3, r8
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _081C3110 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r5, [r0]
	ldr r2, _081C3114 @ =0x0000046C
	adds r0, r7, r2
	strb r4, [r0]
	ldr r0, [r6]
	ldr r3, _081C3118 @ =0xFEFFFFFF
	ands r0, r3
	str r0, [r6]
	bl _081C491C
	.align 2, 0
_081C3108: .4byte 0x000005CC
_081C310C: .4byte 0x0000046D
_081C3110: .4byte 0x00000469
_081C3114: .4byte 0x0000046C
_081C3118: .4byte 0xFEFFFFFF
_081C311C:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_080e81dc
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	cmp r0, #0
	beq _081C3140
	adds r0, r7, #0
	bl FUN_081b8c14
	ldr r5, [sp, #0x34]
	ldr r6, _081C3154 @ =0x000006B4
	adds r1, r5, r6
	movs r0, #0x78
	strh r0, [r1]
_081C3140:
	movs r0, #0x21
	rsbs r0, r0, #0
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
_081C314A:
	strh r0, [r2]
_081C314C:
	movs r0, #0
	bl FUN_081c491e
	.align 2, 0
_081C3154: .4byte 0x000006B4
_081C3158:
	mov r3, sl
	ldr r0, [r3]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _081C31F0
	movs r4, #0xc8
	lsls r4, r4, #1
	adds r0, r7, r4
	ldrh r0, [r0]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r2, #0
	strh r0, [r1]
	ldr r3, _081C31D8 @ =0x000005CC
	adds r0, r7, r3
	ldr r0, [r0]
	mov r8, r0
	movs r1, #0x12
	ldr r4, _081C31DC @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r3, _081C31E0 @ =0x0000046B
	adds r0, r7, r3
	strb r2, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r3, r8
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _081C31E4 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r5, [r0]
	ldr r2, _081C31E8 @ =0x0000046C
	adds r0, r7, r2
	strb r4, [r0]
	ldr r0, [r6]
	ldr r3, _081C31EC @ =0xFEFFFFFF
	ands r0, r3
	str r0, [r6]
	bl _081C491C
	.align 2, 0
_081C31D8: .4byte 0x000005CC
_081C31DC: .4byte 0x0000046D
_081C31E0: .4byte 0x0000046B
_081C31E4: .4byte 0x00000469
_081C31E8: .4byte 0x0000046C
_081C31EC: .4byte 0xFEFFFFFF
_081C31F0:
	movs r3, #0x21
	rsbs r3, r3, #0
	mov r4, r8
	ands r3, r4
	ldr r5, [sp, #0x158]
	strh r3, [r5]
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	ands r0, r2
	str r1, [sp, #0x154]
	cmp r0, #0
	bne _081C314C
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	bne _081C321A
	b _081C3970
_081C321A:
	ldr r0, _081C32AC @ =0x0000048D
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _081C3246
	ldr r1, _081C32B0 @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081C3246
	ldr r3, _081C32B4 @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_081C3246:
	movs r1, #0x80
	ldr r4, [sp, #0x154]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #4
	ldr r5, _081C32B8 @ =0x00000222
	adds r4, r7, r5
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	str r4, [sp, #0x160]
	cmp r0, #0
	bne _081C326C
	b _081C314C
_081C326C:
	movs r6, #0x95
	lsls r6, r6, #3
	adds r3, r7, r6
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
	str r3, [sp, #0x184]
	str r2, [sp, #0x150]
	cmp r4, #0
	blt _081C32A8
	cmp r1, #0
	blt _081C32A8
	ldr r0, _081C32BC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081C32A8
	ldr r0, _081C32C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C32C4
_081C32A8:
	movs r4, #0
	b _081C32D2
	.align 2, 0
_081C32AC: .4byte 0x0000048D
_081C32B0: .4byte 0x0000048C
_081C32B4: .4byte 0x000004BE
_081C32B8: .4byte 0x00000222
_081C32BC: .4byte 0x030046A8
_081C32C0: .4byte 0x030046AC
_081C32C4:
	ldr r0, _081C32E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081C32D2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C32E8
	adds r0, #4
	b _081C32F4
	.align 2, 0
_081C32E4: .4byte 0x030046A4
_081C32E8:
	ldr r0, _081C3308 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C32F4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C330C
	cmp r2, #2
	beq _081C3310
	b _081C3314
	.align 2, 0
_081C3308: .4byte 0x030046A4
_081C330C:
	ldrb r0, [r5, #4]
	b _081C3312
_081C3310:
	ldrb r0, [r5]
_081C3312:
	subs r1, r1, r0
_081C3314:
	strh r1, [r5, #2]
	ldr r0, _081C3328 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C332C
	movs r0, #1
	b _081C332E
	.align 2, 0
_081C3328: .4byte 0x030047A4
_081C332C:
	movs r0, #0
_081C332E:
	cmp r0, #0
	beq _081C336C
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081C334E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C334A
	adds r2, r0, #0
_081C334A:
	cmp r2, #0
	bge _081C3358
_081C334E:
	ldr r2, _081C3354 @ =0x000005C4
	adds r0, r7, r2
	b _081C387C
	.align 2, 0
_081C3354: .4byte 0x000005C4
_081C3358:
	ldr r1, _081C3368 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081C33B4
	.align 2, 0
_081C3368: .4byte 0x03002BE0
_081C336C:
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
	blt _081C3398
	cmp r1, #0
	blt _081C3398
	ldr r0, _081C339C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C3398
	ldr r0, _081C33A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C33A4
_081C3398:
	movs r5, #0
	b _081C33B2
	.align 2, 0
_081C339C: .4byte 0x030046A8
_081C33A0: .4byte 0x030046AC
_081C33A4:
	ldr r0, _081C33EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081C33B2:
	movs r2, #0
_081C33B4:
	ldr r4, _081C33F0 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081C33D4
	ldr r1, _081C33F4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C33D4
	b _081C37B8
_081C33D4:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x158]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x8c]
	cmp r0, #0
	beq _081C33F8
	movs r0, #0
	b _081C3892
	.align 2, 0
_081C33EC: .4byte 0x030046A4
_081C33F0: .4byte 0x00000256
_081C33F4: .4byte 0x03002BE0
_081C33F8:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r6, [sp, #0x160]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	movs r1, #0x80
	ldr r2, [sp, #0x158]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _081C34A8
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r4, _081C3498 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x90]
	movs r5, #1
	strb r5, [r4]
	ldr r6, _081C349C @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x94]
	movs r2, #0
	strb r2, [r6]
	subs r3, #0x65
	adds r3, r7, r3
	str r3, [sp, #0x98]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x9c]
	str r1, [r4]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0xa0]
	add r0, sp, #0x8c
	ldrh r0, [r0]
	strh r0, [r6]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r2, [r4]
	ldr r2, _081C34A0 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _081C34A4 @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x8c]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	strb r5, [r0]
	str r4, [sp, #0x164]
	str r3, [sp, #0x168]
	str r2, [sp, #0x16c]
	str r1, [sp, #0x180]
	str r0, [sp, #0x174]
	ldr r0, [sp, #0x90]
	str r0, [sp, #0x178]
	ldr r1, [sp, #0x94]
	str r1, [sp, #0x170]
	ldr r2, [sp, #0x98]
	str r2, [sp, #0x144]
	ldr r3, [sp, #0x9c]
	str r3, [sp, #0x148]
	ldr r4, [sp, #0xa0]
	str r4, [sp, #0x15c]
	b _081C3676
	.align 2, 0
_081C3498: .4byte 0x0000046D
_081C349C: .4byte 0x0000046B
_081C34A0: .4byte 0x00000469
_081C34A4: .4byte 0x00000484
_081C34A8:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #1
	ldr r6, _081C3568 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	strb r0, [r6]
	ldr r3, _081C356C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0xa8]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x4d
	adds r5, r7, r5
	str r5, [sp, #0xac]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb0]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xb4]
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xb8]
	strb r4, [r3]
	ldr r4, _081C3570 @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r3, _081C3574 @ =0x0000046A
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081C3578 @ =0x00000484
	adds r3, r7, r6
	str r2, [r3]
	ldr r1, _081C357C @ =0x0000046C
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, [sp, #0x184]
	ldr r6, [r6]
	str r6, [sp, #0xbc]
	ldr r1, [sp, #0x150]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r6, [sp, #0x150]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xbc]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0xb8]
	str r0, [sp, #0x164]
	str r5, [sp, #0x168]
	str r4, [sp, #0x16c]
	str r3, [sp, #0x180]
	str r2, [sp, #0x174]
	ldr r2, [sp, #0xa4]
	str r2, [sp, #0x178]
	ldr r3, [sp, #0xa8]
	str r3, [sp, #0x170]
	ldr r4, [sp, #0xac]
	str r4, [sp, #0x144]
	ldr r5, [sp, #0xb0]
	str r5, [sp, #0x148]
	ldr r6, [sp, #0xb4]
	str r6, [sp, #0x15c]
	mov r0, r8
	cmp r0, #0
	blt _081C3562
	cmp r1, #0
	blt _081C3562
	ldr r0, _081C3580 @ =0x030046A8
	ldr r0, [r0]
	cmp r8, r0
	bhs _081C3562
	ldr r0, _081C3584 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C3588
_081C3562:
	movs r4, #0
	b _081C3598
	.align 2, 0
_081C3568: .4byte 0x0000046D
_081C356C: .4byte 0x0000046B
_081C3570: .4byte 0x00000469
_081C3574: .4byte 0x0000046A
_081C3578: .4byte 0x00000484
_081C357C: .4byte 0x0000046C
_081C3580: .4byte 0x030046A8
_081C3584: .4byte 0x030046AC
_081C3588:
	ldr r0, _081C35A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, r8
	adds r4, r0, r1
_081C3598:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C35AC
	adds r0, #4
	b _081C35B8
	.align 2, 0
_081C35A8: .4byte 0x030046A4
_081C35AC:
	ldr r0, _081C35CC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C35B8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C35D0
	cmp r2, #2
	beq _081C35D6
	b _081C35DC
	.align 2, 0
_081C35CC: .4byte 0x030046A4
_081C35D0:
	ldr r2, [sp, #0xbc]
	ldrb r0, [r2, #4]
	b _081C35DA
_081C35D6:
	ldr r3, [sp, #0xbc]
	ldrb r0, [r3]
_081C35DA:
	subs r1, r1, r0
_081C35DC:
	ldr r4, [sp, #0xbc]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x184]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C3608
	cmp r1, #0
	blt _081C3608
	ldr r0, _081C360C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C3608
	ldr r0, _081C3610 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C3614
_081C3608:
	movs r4, #0
	b _081C3622
	.align 2, 0
_081C360C: .4byte 0x030046A8
_081C3610: .4byte 0x030046AC
_081C3614:
	ldr r0, _081C3638 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C3622:
	ldr r6, [sp, #0x184]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C363C
	adds r0, #4
	b _081C3648
	.align 2, 0
_081C3638: .4byte 0x030046A4
_081C363C:
	ldr r0, _081C365C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C3648:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C3660
	cmp r3, #2
	beq _081C3664
	b _081C3668
	.align 2, 0
_081C365C: .4byte 0x030046A4
_081C3660:
	ldrb r0, [r5, #4]
	b _081C3666
_081C3664:
	ldrb r0, [r5]
_081C3666:
	subs r2, r2, r0
_081C3668:
	ldr r1, [sp, #0x184]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x184]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081C3676:
	ldrb r3, [r7, #5]
	str r3, [sp, #0xc0]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x158]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _081C36A0 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	cmp r0, #0
	bne _081C377E
	movs r1, #4
	ldr r2, [sp, #0x160]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C36A4
	movs r0, #1
	b _081C36A6
	.align 2, 0
_081C36A0: .4byte 0x00000482
_081C36A4:
	movs r0, #0
_081C36A6:
	ldr r3, _081C3790 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	cmp r0, #0
	bne _081C377E
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _081C3794 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081C3798 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081C379C @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x140]
	ldr r2, _081C37A0 @ =0x00000541
	adds r2, r2, r7
	mov ip, r2
	ldr r0, _081C37A4 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x14c]
	ldr r1, _081C37A8 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r1, _081C37AC @ =0x030046B8
	str r5, [sp, #0x188]
_081C36EC:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081C37B0 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081C37B4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x188]
	cmp r0, r2
	bne _081C3712
	adds r3, #1
	cmp r3, #3
	ble _081C36EC
	adds r0, r5, #0
_081C3712:
	movs r3, #0
	strb r0, [r4]
	ldr r4, [sp, #0x148]
	ldr r0, [r4]
	str r0, [r6]
	ldr r5, [sp, #0x144]
	ldrb r0, [r5]
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x164]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x168]
	ldrb r0, [r4]
	mov r5, sl
	strb r0, [r5]
	ldr r6, [sp, #0x16c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x140]
	strb r0, [r1]
	add r2, sp, #0xc0
	ldrb r4, [r2]
	mov r2, ip
	strb r4, [r2]
	ldr r4, [sp, #0x14c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x178]
	strb r1, [r5]
	ldr r6, [sp, #0x170]
	strb r3, [r6]
	ldr r4, [sp, #0x144]
	strb r0, [r4]
	ldr r5, [sp, #0x148]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x15c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x164]
	strb r0, [r4]
	ldr r5, [sp, #0x168]
	strb r1, [r5]
	ldr r6, [sp, #0x16c]
	strb r2, [r6]
	ldr r0, [sp, #0x180]
	str r3, [r0]
	ldr r2, [sp, #0x174]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x13c]
	strb r0, [r3]
_081C377E:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x17c]
	strh r0, [r4]
	movs r0, #0
	b _081C3892
	.align 2, 0
_081C3790: .4byte 0x00000482
_081C3794: .4byte 0x0000054F
_081C3798: .4byte 0x0000054C
_081C379C: .4byte 0x0000054E
_081C37A0: .4byte 0x00000541
_081C37A4: .4byte 0x000005BC
_081C37A8: .4byte 0x00000542
_081C37AC: .4byte 0x030046B8
_081C37B0: .4byte 0x000003FF
_081C37B4: .4byte 0x0203B400
_081C37B8:
	add r6, sp, #0x1c
	ldr r0, _081C37F8 @ =0x030046A4
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
	beq _081C37FC
	adds r0, #4
	b _081C3808
	.align 2, 0
_081C37F8: .4byte 0x030046A4
_081C37FC:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C3808:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081C3840 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _081C3848
	ldr r0, _081C3844 @ =0xFFFFFDFF
	ldr r6, [sp, #0x158]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081C3872
	.align 2, 0
_081C3840: .4byte 0x000004A4
_081C3844: .4byte 0xFFFFFDFF
_081C3848:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081C3868
	cmp r0, #2
	beq _081C3864
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C3864:
	movs r0, #1
	b _081C3874
_081C3868:
	ldr r0, _081C3888 @ =0xFFFFFDFF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081C3872:
	movs r0, #0
_081C3874:
	cmp r0, #0
	bne _081C3890
	ldr r3, _081C388C @ =0x000005C4
	adds r0, r7, r3
_081C387C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081C3892
	.align 2, 0
_081C3888: .4byte 0xFFFFFDFF
_081C388C: .4byte 0x000005C4
_081C3890:
	movs r0, #1
_081C3892:
	cmp r0, #0
	bne _081C3904
	ldr r4, _081C38C8 @ =0x000004A4
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
	bne _081C38D0
	ldr r0, _081C38CC @ =0xFFFFFDFF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C38FA
	.align 2, 0
_081C38C8: .4byte 0x000004A4
_081C38CC: .4byte 0xFFFFFDFF
_081C38D0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081C38F0
	cmp r0, #2
	beq _081C38EC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C38EC:
	movs r0, #1
	b _081C38FC
_081C38F0:
	ldr r0, _081C395C @ =0xFFFFFDFF
	ldr r3, [sp, #0x158]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C38FA:
	movs r0, #0
_081C38FC:
	cmp r0, #0
	bne _081C3904
	bl _081C48AC
_081C3904:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _081C3960 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _081C3964 @ =0x0000046B
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
	ldr r1, _081C3968 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _081C396C @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	bl _081C491C
	.align 2, 0
_081C395C: .4byte 0xFFFFFDFF
_081C3960: .4byte 0x0000046D
_081C3964: .4byte 0x0000046B
_081C3968: .4byte 0x0000046A
_081C396C: .4byte 0x00000484
_081C3970:
	ldr r6, [sp, #0x34]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081C3982
	bl FUN_081c41a4
_081C3982:
	ldr r3, _081C39F8 @ =0x0000048D
	adds r2, r7, r3
	ldrb r0, [r2]
	cmp r0, #0
	bne _081C39AE
	ldr r4, _081C39FC @ =0x0000048C
	adds r0, r7, r4
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081C39AE
	ldr r5, _081C3A00 @ =0x000004BE
	adds r0, r7, r5
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_081C39AE:
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r0, r7, r6
	ldrb r0, [r0]
	strb r0, [r7, #5]
	movs r1, #0x95
	lsls r1, r1, #3
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
	asrs r3, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r2, [sp, #0x150]
	cmp r3, #0
	blt _081C39F2
	cmp r1, #0
	blt _081C39F2
	ldr r0, _081C3A04 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081C39F2
	ldr r0, _081C3A08 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C3A0C
_081C39F2:
	movs r4, #0
	b _081C3A1A
	.align 2, 0
_081C39F8: .4byte 0x0000048D
_081C39FC: .4byte 0x0000048C
_081C3A00: .4byte 0x000004BE
_081C3A04: .4byte 0x030046A8
_081C3A08: .4byte 0x030046AC
_081C3A0C:
	ldr r0, _081C3A2C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_081C3A1A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C3A30
	adds r0, #4
	b _081C3A3C
	.align 2, 0
_081C3A2C: .4byte 0x030046A4
_081C3A30:
	ldr r0, _081C3A50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C3A3C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C3A54
	cmp r2, #2
	beq _081C3A58
	b _081C3A5C
	.align 2, 0
_081C3A50: .4byte 0x030046A4
_081C3A54:
	ldrb r0, [r5, #4]
	b _081C3A5A
_081C3A58:
	ldrb r0, [r5]
_081C3A5A:
	subs r1, r1, r0
_081C3A5C:
	strh r1, [r5, #2]
	adds r0, r7, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C3A6E
	bl _081C314C
_081C3A6E:
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	adds r2, r7, r2
	ldr r5, [r2]
	ldr r3, [sp, #0x150]
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r2, [sp, #0x184]
	cmp r4, #0
	blt _081C3AAE
	cmp r1, #0
	blt _081C3AAE
	ldr r0, _081C3AB4 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081C3AAE
	ldr r0, _081C3AB8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C3ABC
_081C3AAE:
	movs r4, #0
	b _081C3ACA
	.align 2, 0
_081C3AB4: .4byte 0x030046A8
_081C3AB8: .4byte 0x030046AC
_081C3ABC:
	ldr r0, _081C3ADC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081C3ACA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C3AE0
	adds r0, #4
	b _081C3AEC
	.align 2, 0
_081C3ADC: .4byte 0x030046A4
_081C3AE0:
	ldr r0, _081C3B00 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C3AEC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C3B04
	cmp r2, #2
	beq _081C3B08
	b _081C3B0C
	.align 2, 0
_081C3B00: .4byte 0x030046A4
_081C3B04:
	ldrb r0, [r5, #4]
	b _081C3B0A
_081C3B08:
	ldrb r0, [r5]
_081C3B0A:
	subs r1, r1, r0
_081C3B0C:
	strh r1, [r5, #2]
	ldr r0, _081C3B20 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C3B24
	movs r0, #1
	b _081C3B26
	.align 2, 0
_081C3B20: .4byte 0x030047A4
_081C3B24:
	movs r0, #0
_081C3B26:
	cmp r0, #0
	beq _081C3B64
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081C3B46
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C3B42
	adds r2, r0, #0
_081C3B42:
	cmp r2, #0
	bge _081C3B50
_081C3B46:
	ldr r5, _081C3B4C @ =0x000005C4
	adds r0, r7, r5
	b _081C408C
	.align 2, 0
_081C3B4C: .4byte 0x000005C4
_081C3B50:
	ldr r1, _081C3B60 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081C3BAC
	.align 2, 0
_081C3B60: .4byte 0x03002BE0
_081C3B64:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C3B90
	cmp r1, #0
	blt _081C3B90
	ldr r0, _081C3B94 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C3B90
	ldr r0, _081C3B98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C3B9C
_081C3B90:
	movs r5, #0
	b _081C3BAA
	.align 2, 0
_081C3B94: .4byte 0x030046A8
_081C3B98: .4byte 0x030046AC
_081C3B9C:
	ldr r0, _081C3BE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081C3BAA:
	movs r2, #0
_081C3BAC:
	ldr r1, _081C3BE8 @ =0x00000256
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r5, r0
	beq _081C3BCC
	ldr r1, _081C3BEC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C3BCC
	b _081C3FC8
_081C3BCC:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x158]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc4]
	cmp r0, #0
	beq _081C3BF0
	movs r0, #0
	b _081C40A2
	.align 2, 0
_081C3BE4: .4byte 0x030046A4
_081C3BE8: .4byte 0x00000256
_081C3BEC: .4byte 0x03002BE0
_081C3BF0:
	ldr r3, _081C3C98 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x158]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0x160]
	cmp r0, #0
	beq _081C3CB4
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081C3C9C @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0xc8]
	movs r5, #1
	strb r5, [r6]
	ldr r2, _081C3CA0 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0xcc]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081C3CA4 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0xd0]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xd4]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r7, r0
	str r0, [sp, #0xd8]
	add r1, sp, #0xc4
	ldrh r1, [r1]
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _081C3CA8 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081C3CAC @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0xc4]
	str r6, [r1]
	ldr r6, _081C3CB0 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	str r4, [sp, #0x164]
	str r3, [sp, #0x168]
	str r2, [sp, #0x16c]
	str r1, [sp, #0x180]
	str r0, [sp, #0x174]
	ldr r0, [sp, #0xc8]
	str r0, [sp, #0x178]
	ldr r1, [sp, #0xcc]
	str r1, [sp, #0x170]
	ldr r2, [sp, #0xd0]
	str r2, [sp, #0x144]
	ldr r3, [sp, #0xd4]
	str r3, [sp, #0x148]
	ldr r4, [sp, #0xd8]
	str r4, [sp, #0x15c]
	b _081C3E84
	.align 2, 0
_081C3C98: .4byte 0x00000222
_081C3C9C: .4byte 0x0000046D
_081C3CA0: .4byte 0x0000046B
_081C3CA4: .4byte 0x00000553
_081C3CA8: .4byte 0x00000469
_081C3CAC: .4byte 0x00000484
_081C3CB0: .4byte 0x0000046C
_081C3CB4:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #1
	ldr r6, _081C3D78 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0xdc]
	strb r0, [r6]
	ldr r2, _081C3D7C @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081C3D80 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0xe4]
	strb r0, [r4]
	subs r5, #0x28
	adds r5, r7, r5
	str r5, [sp, #0xe8]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0xec]
	mov r1, ip
	strh r1, [r6]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xf0]
	strb r3, [r2]
	ldr r3, _081C3D84 @ =0x00000469
	adds r5, r7, r3
	movs r4, #0
	strb r4, [r5]
	ldr r6, _081C3D88 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _081C3D8C @ =0x00000484
	adds r3, r7, r1
	mov r2, ip
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x184]
	ldr r0, [r0]
	str r0, [sp, #0xf4]
	ldr r1, [sp, #0x150]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0xf4]
	strh r1, [r6]
	ldr r6, [sp, #0x150]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xf4]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r1, [sp, #0xf8]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0xf0]
	str r0, [sp, #0x164]
	str r5, [sp, #0x168]
	str r4, [sp, #0x16c]
	str r3, [sp, #0x180]
	str r2, [sp, #0x174]
	ldr r2, [sp, #0xdc]
	str r2, [sp, #0x178]
	ldr r3, [sp, #0xe0]
	str r3, [sp, #0x170]
	ldr r4, [sp, #0xe4]
	str r4, [sp, #0x144]
	ldr r5, [sp, #0xe8]
	str r5, [sp, #0x148]
	ldr r6, [sp, #0xec]
	str r6, [sp, #0x15c]
	ldr r0, [sp, #0xf8]
	cmp r0, #0
	blt _081C3D74
	cmp r1, #0
	blt _081C3D74
	ldr r0, _081C3D90 @ =0x030046A8
	ldr r0, [r0]
	ldr r2, [sp, #0xf8]
	cmp r2, r0
	bhs _081C3D74
	ldr r0, _081C3D94 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C3D98
_081C3D74:
	movs r4, #0
	b _081C3DA8
	.align 2, 0
_081C3D78: .4byte 0x0000046D
_081C3D7C: .4byte 0x0000046B
_081C3D80: .4byte 0x00000553
_081C3D84: .4byte 0x00000469
_081C3D88: .4byte 0x0000046A
_081C3D8C: .4byte 0x00000484
_081C3D90: .4byte 0x030046A8
_081C3D94: .4byte 0x030046AC
_081C3D98:
	ldr r0, _081C3DB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r3, [sp, #0xf8]
	adds r4, r0, r3
_081C3DA8:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C3DBC
	adds r0, #4
	b _081C3DC8
	.align 2, 0
_081C3DB8: .4byte 0x030046A4
_081C3DBC:
	ldr r0, _081C3DDC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C3DC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C3DE0
	cmp r2, #2
	beq _081C3DE6
	b _081C3DEC
	.align 2, 0
_081C3DDC: .4byte 0x030046A4
_081C3DE0:
	ldr r4, [sp, #0xf4]
	ldrb r0, [r4, #4]
	b _081C3DEA
_081C3DE6:
	ldr r5, [sp, #0xf4]
	ldrb r0, [r5]
_081C3DEA:
	subs r1, r1, r0
_081C3DEC:
	ldr r6, [sp, #0xf4]
	strh r1, [r6, #2]
	ldr r1, [sp, #0x184]
	ldr r0, [r1]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C3E18
	cmp r1, #0
	blt _081C3E18
	ldr r0, _081C3E1C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C3E18
	ldr r0, _081C3E20 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C3E24
_081C3E18:
	movs r4, #0
	b _081C3E32
	.align 2, 0
_081C3E1C: .4byte 0x030046A8
_081C3E20: .4byte 0x030046AC
_081C3E24:
	ldr r0, _081C3E48 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C3E32:
	ldr r2, [sp, #0x184]
	ldr r5, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C3E4C
	adds r0, #4
	b _081C3E58
	.align 2, 0
_081C3E48: .4byte 0x030046A4
_081C3E4C:
	ldr r0, _081C3E6C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C3E58:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C3E70
	cmp r3, #2
	beq _081C3E74
	b _081C3E78
	.align 2, 0
_081C3E6C: .4byte 0x030046A4
_081C3E70:
	ldrb r0, [r5, #4]
	b _081C3E76
_081C3E74:
	ldrb r0, [r5]
_081C3E76:
	subs r2, r2, r0
_081C3E78:
	ldr r3, [sp, #0x184]
	ldr r0, [r3]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r3]
	strh r1, [r0, #6]
_081C3E84:
	ldrb r4, [r7, #5]
	str r4, [sp, #0xfc]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x158]
	ldrh r0, [r5]
	ands r0, r1
	adds r5, r4, #0
	ldr r6, _081C3EB0 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	cmp r0, #0
	bne _081C3F8E
	movs r1, #4
	ldr r2, [sp, #0x160]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C3EB4
	movs r0, #1
	b _081C3EB6
	.align 2, 0
_081C3EB0: .4byte 0x00000482
_081C3EB4:
	movs r0, #0
_081C3EB6:
	ldr r3, _081C3FA0 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	cmp r0, #0
	bne _081C3F8E
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _081C3FA4 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081C3FA8 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081C3FAC @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x140]
	ldr r2, _081C3FB0 @ =0x00000541
	adds r2, r2, r7
	mov ip, r2
	ldr r0, _081C3FB4 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x14c]
	ldr r1, _081C3FB8 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r1, _081C3FBC @ =0x030046B8
	str r5, [sp, #0x188]
_081C3EFC:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081C3FC0 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081C3FC4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x188]
	cmp r0, r2
	bne _081C3F22
	adds r3, #1
	cmp r3, #3
	ble _081C3EFC
	adds r0, r5, #0
_081C3F22:
	movs r3, #0
	strb r0, [r4]
	ldr r4, [sp, #0x148]
	ldr r0, [r4]
	str r0, [r6]
	ldr r5, [sp, #0x144]
	ldrb r0, [r5]
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x164]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x168]
	ldrb r0, [r4]
	mov r5, sl
	strb r0, [r5]
	ldr r6, [sp, #0x16c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x140]
	strb r0, [r1]
	add r2, sp, #0xfc
	ldrb r4, [r2]
	mov r2, ip
	strb r4, [r2]
	ldr r4, [sp, #0x14c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x178]
	strb r1, [r5]
	ldr r6, [sp, #0x170]
	strb r3, [r6]
	ldr r4, [sp, #0x144]
	strb r0, [r4]
	ldr r5, [sp, #0x148]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x15c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x164]
	strb r0, [r4]
	ldr r5, [sp, #0x168]
	strb r1, [r5]
	ldr r6, [sp, #0x16c]
	strb r2, [r6]
	ldr r0, [sp, #0x180]
	str r3, [r0]
	ldr r2, [sp, #0x174]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x13c]
	strb r0, [r3]
_081C3F8E:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x17c]
	strh r0, [r4]
	movs r0, #0
	b _081C40A2
	.align 2, 0
_081C3FA0: .4byte 0x00000482
_081C3FA4: .4byte 0x0000054F
_081C3FA8: .4byte 0x0000054C
_081C3FAC: .4byte 0x0000054E
_081C3FB0: .4byte 0x00000541
_081C3FB4: .4byte 0x000005BC
_081C3FB8: .4byte 0x00000542
_081C3FBC: .4byte 0x030046B8
_081C3FC0: .4byte 0x000003FF
_081C3FC4: .4byte 0x0203B400
_081C3FC8:
	add r6, sp, #0x24
	ldr r0, _081C4008 @ =0x030046A4
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
	beq _081C400C
	adds r0, #4
	b _081C4018
	.align 2, 0
_081C4008: .4byte 0x030046A4
_081C400C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C4018:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081C4050 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _081C4058
	ldr r0, _081C4054 @ =0xFFFFFDFF
	ldr r6, [sp, #0x158]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081C4082
	.align 2, 0
_081C4050: .4byte 0x000004A4
_081C4054: .4byte 0xFFFFFDFF
_081C4058:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081C4078
	cmp r0, #2
	beq _081C4074
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C4074:
	movs r0, #1
	b _081C4084
_081C4078:
	ldr r0, _081C4098 @ =0xFFFFFDFF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081C4082:
	movs r0, #0
_081C4084:
	cmp r0, #0
	bne _081C40A0
	ldr r3, _081C409C @ =0x000005C4
	adds r0, r7, r3
_081C408C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081C40A2
	.align 2, 0
_081C4098: .4byte 0xFFFFFDFF
_081C409C: .4byte 0x000005C4
_081C40A0:
	movs r0, #1
_081C40A2:
	cmp r0, #0
	bne _081C4112
	ldr r4, _081C40D8 @ =0x000004A4
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
	bne _081C40E0
	ldr r0, _081C40DC @ =0xFFFFFDFF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C410A
	.align 2, 0
_081C40D8: .4byte 0x000004A4
_081C40DC: .4byte 0xFFFFFDFF
_081C40E0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081C4100
	cmp r0, #2
	beq _081C40FC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C40FC:
	movs r0, #1
	b _081C410C
_081C4100:
	ldr r0, _081C4184 @ =0xFFFFFDFF
	ldr r3, [sp, #0x158]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C410A:
	movs r0, #0
_081C410C:
	cmp r0, #0
	bne _081C4112
	b _081C48AC
_081C4112:
	ldr r5, _081C4188 @ =0x00000482
	adds r1, r7, r5
	movs r4, #0
	movs r5, #0
	movs r3, #1
	movs r0, #1
	strh r0, [r1]
	ldr r6, [sp, #0x34]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #2
	bhi _081C4132
	adds r0, #1
	strb r0, [r1]
_081C4132:
	ldr r2, _081C418C @ =FUN_080f3cdc
	movs r1, #0xa
	ldr r6, _081C4190 @ =0x0000046D
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
	ldr r1, _081C4194 @ =0x00000469
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _081C4198 @ =0x0000046A
	adds r0, r7, r2
	strb r3, [r0]
	ldr r4, _081C419C @ =0x00000484
	adds r0, r7, r4
	str r5, [r0]
	ldr r5, _081C41A0 @ =0x0000046C
	adds r0, r7, r5
	strb r3, [r0]
	movs r1, #0x10
	ldr r6, [sp, #0x154]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	b _081C491C
	.align 2, 0
_081C4184: .4byte 0xFFFFFDFF
_081C4188: .4byte 0x00000482
_081C418C: .4byte FUN_080f3cdc
_081C4190: .4byte 0x0000046D
_081C4194: .4byte 0x00000469
_081C4198: .4byte 0x0000046A
_081C419C: .4byte 0x00000484
_081C41A0: .4byte 0x0000046C

	thumb_func_start FUN_081c41a4
FUN_081c41a4: @ 0x081C41A4
	ldr r1, _081C4240 @ =0x00000544
	adds r0, r7, r1
	movs r1, #0x96
	lsls r1, r1, #1
	strh r1, [r0]
	ldr r3, _081C4244 @ =0x0000048D
	adds r2, r7, r3
	ldrb r0, [r2]
	cmp r0, #0
	bne _081C41DA
	ldr r4, _081C4248 @ =0x0000048C
	adds r0, r7, r4
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081C41DA
	ldr r5, _081C424C @ =0x000004BE
	adds r0, r7, r5
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_081C41DA:
	adds r0, r7, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C41EA
	bl _081C314C
_081C41EA:
	movs r1, #0x90
	ldr r6, [sp, #0x154]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r3, r7, r2
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
	str r3, [sp, #0x184]
	str r2, [sp, #0x150]
	cmp r4, #0
	blt _081C423C
	cmp r1, #0
	blt _081C423C
	ldr r0, _081C4250 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081C423C
	ldr r0, _081C4254 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C4258
_081C423C:
	movs r4, #0
	b _081C4266
	.align 2, 0
_081C4240: .4byte 0x00000544
_081C4244: .4byte 0x0000048D
_081C4248: .4byte 0x0000048C
_081C424C: .4byte 0x000004BE
_081C4250: .4byte 0x030046A8
_081C4254: .4byte 0x030046AC
_081C4258:
	ldr r0, _081C4278 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081C4266:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C427C
	adds r0, #4
	b _081C4288
	.align 2, 0
_081C4278: .4byte 0x030046A4
_081C427C:
	ldr r0, _081C429C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C4288:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C42A0
	cmp r2, #2
	beq _081C42A4
	b _081C42A8
	.align 2, 0
_081C429C: .4byte 0x030046A4
_081C42A0:
	ldrb r0, [r5, #4]
	b _081C42A6
_081C42A4:
	ldrb r0, [r5]
_081C42A6:
	subs r1, r1, r0
_081C42A8:
	strh r1, [r5, #2]
	ldr r0, _081C42BC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C42C0
	movs r0, #1
	b _081C42C2
	.align 2, 0
_081C42BC: .4byte 0x030047A4
_081C42C0:
	movs r0, #0
_081C42C2:
	cmp r0, #0
	beq _081C4300
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _081C42E2
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C42DE
	adds r2, r0, #0
_081C42DE:
	cmp r2, #0
	bge _081C42EC
_081C42E2:
	ldr r4, _081C42E8 @ =0x000005C4
	adds r0, r7, r4
	b _081C4828
	.align 2, 0
_081C42E8: .4byte 0x000005C4
_081C42EC:
	ldr r1, _081C42FC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081C4348
	.align 2, 0
_081C42FC: .4byte 0x03002BE0
_081C4300:
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
	blt _081C432C
	cmp r1, #0
	blt _081C432C
	ldr r0, _081C4330 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C432C
	ldr r0, _081C4334 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C4338
_081C432C:
	movs r5, #0
	b _081C4346
	.align 2, 0
_081C4330: .4byte 0x030046A8
_081C4334: .4byte 0x030046AC
_081C4338:
	ldr r0, _081C4380 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081C4346:
	movs r2, #0
_081C4348:
	ldr r6, _081C4384 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081C4368
	ldr r1, _081C4388 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C4368
	b _081C4764
_081C4368:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x158]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x100]
	cmp r0, #0
	beq _081C438C
	movs r0, #0
	b _081C483E
	.align 2, 0
_081C4380: .4byte 0x030046A4
_081C4384: .4byte 0x00000256
_081C4388: .4byte 0x03002BE0
_081C438C:
	ldr r3, _081C4434 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x158]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	str r2, [sp, #0x160]
	cmp r0, #0
	beq _081C4450
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081C4438 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x104]
	movs r5, #1
	strb r5, [r6]
	ldr r2, _081C443C @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x108]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081C4440 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x10c]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x110]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r7, r0
	str r0, [sp, #0x114]
	add r1, sp, #0x100
	ldrh r1, [r1]
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _081C4444 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081C4448 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x100]
	str r6, [r1]
	ldr r6, _081C444C @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	str r4, [sp, #0x164]
	str r3, [sp, #0x168]
	str r2, [sp, #0x16c]
	str r1, [sp, #0x180]
	str r0, [sp, #0x174]
	ldr r0, [sp, #0x104]
	str r0, [sp, #0x178]
	ldr r1, [sp, #0x108]
	str r1, [sp, #0x170]
	ldr r2, [sp, #0x10c]
	str r2, [sp, #0x144]
	ldr r3, [sp, #0x110]
	str r3, [sp, #0x148]
	ldr r4, [sp, #0x114]
	str r4, [sp, #0x15c]
	b _081C4620
	.align 2, 0
_081C4434: .4byte 0x00000222
_081C4438: .4byte 0x0000046D
_081C443C: .4byte 0x0000046B
_081C4440: .4byte 0x00000553
_081C4444: .4byte 0x00000469
_081C4448: .4byte 0x00000484
_081C444C: .4byte 0x0000046C
_081C4450:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #1
	ldr r6, _081C4514 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x118]
	strb r0, [r6]
	ldr r2, _081C4518 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x11c]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _081C451C @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x120]
	strb r0, [r4]
	subs r5, #0x28
	adds r5, r7, r5
	str r5, [sp, #0x124]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x128]
	mov r1, sl
	strh r1, [r6]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x12c]
	strb r3, [r2]
	ldr r3, _081C4520 @ =0x00000469
	adds r5, r7, r3
	movs r4, #0
	strb r4, [r5]
	ldr r6, _081C4524 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _081C4528 @ =0x00000484
	adds r3, r7, r1
	mov r2, sl
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x184]
	ldr r0, [r0]
	str r0, [sp, #0x130]
	ldr r1, [sp, #0x150]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x130]
	strh r1, [r6]
	ldr r6, [sp, #0x150]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x130]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r1, [sp, #0x134]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x12c]
	str r0, [sp, #0x164]
	str r5, [sp, #0x168]
	str r4, [sp, #0x16c]
	str r3, [sp, #0x180]
	str r2, [sp, #0x174]
	ldr r2, [sp, #0x118]
	str r2, [sp, #0x178]
	ldr r3, [sp, #0x11c]
	str r3, [sp, #0x170]
	ldr r4, [sp, #0x120]
	str r4, [sp, #0x144]
	ldr r5, [sp, #0x124]
	str r5, [sp, #0x148]
	ldr r6, [sp, #0x128]
	str r6, [sp, #0x15c]
	ldr r0, [sp, #0x134]
	cmp r0, #0
	blt _081C4510
	cmp r1, #0
	blt _081C4510
	ldr r0, _081C452C @ =0x030046A8
	ldr r0, [r0]
	ldr r2, [sp, #0x134]
	cmp r2, r0
	bhs _081C4510
	ldr r0, _081C4530 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C4534
_081C4510:
	movs r4, #0
	b _081C4544
	.align 2, 0
_081C4514: .4byte 0x0000046D
_081C4518: .4byte 0x0000046B
_081C451C: .4byte 0x00000553
_081C4520: .4byte 0x00000469
_081C4524: .4byte 0x0000046A
_081C4528: .4byte 0x00000484
_081C452C: .4byte 0x030046A8
_081C4530: .4byte 0x030046AC
_081C4534:
	ldr r0, _081C4554 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r3, [sp, #0x134]
	adds r4, r0, r3
_081C4544:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C4558
	adds r0, #4
	b _081C4564
	.align 2, 0
_081C4554: .4byte 0x030046A4
_081C4558:
	ldr r0, _081C4578 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C4564:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C457C
	cmp r2, #2
	beq _081C4582
	b _081C4588
	.align 2, 0
_081C4578: .4byte 0x030046A4
_081C457C:
	ldr r4, [sp, #0x130]
	ldrb r0, [r4, #4]
	b _081C4586
_081C4582:
	ldr r5, [sp, #0x130]
	ldrb r0, [r5]
_081C4586:
	subs r1, r1, r0
_081C4588:
	ldr r6, [sp, #0x130]
	strh r1, [r6, #2]
	ldr r1, [sp, #0x184]
	ldr r0, [r1]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C45B4
	cmp r1, #0
	blt _081C45B4
	ldr r0, _081C45B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C45B4
	ldr r0, _081C45BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C45C0
_081C45B4:
	movs r4, #0
	b _081C45CE
	.align 2, 0
_081C45B8: .4byte 0x030046A8
_081C45BC: .4byte 0x030046AC
_081C45C0:
	ldr r0, _081C45E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C45CE:
	ldr r2, [sp, #0x184]
	ldr r5, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C45E8
	adds r0, #4
	b _081C45F4
	.align 2, 0
_081C45E4: .4byte 0x030046A4
_081C45E8:
	ldr r0, _081C4608 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C45F4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C460C
	cmp r3, #2
	beq _081C4610
	b _081C4614
	.align 2, 0
_081C4608: .4byte 0x030046A4
_081C460C:
	ldrb r0, [r5, #4]
	b _081C4612
_081C4610:
	ldrb r0, [r5]
_081C4612:
	subs r2, r2, r0
_081C4614:
	ldr r3, [sp, #0x184]
	ldr r0, [r3]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r3]
	strh r1, [r0, #6]
_081C4620:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x138]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x158]
	ldrh r0, [r5]
	ands r0, r1
	adds r5, r4, #0
	ldr r6, _081C464C @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	cmp r0, #0
	bne _081C472A
	movs r1, #4
	ldr r2, [sp, #0x160]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C4650
	movs r0, #1
	b _081C4652
	.align 2, 0
_081C464C: .4byte 0x00000482
_081C4650:
	movs r0, #0
_081C4652:
	ldr r3, _081C473C @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	cmp r0, #0
	bne _081C472A
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _081C4740 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081C4744 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081C4748 @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x140]
	ldr r2, _081C474C @ =0x00000541
	adds r2, r2, r7
	mov ip, r2
	ldr r0, _081C4750 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x14c]
	ldr r1, _081C4754 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r1, _081C4758 @ =0x030046B8
	str r5, [sp, #0x188]
_081C4698:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081C475C @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081C4760 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x188]
	cmp r0, r2
	bne _081C46BE
	adds r3, #1
	cmp r3, #3
	ble _081C4698
	adds r0, r5, #0
_081C46BE:
	movs r3, #0
	strb r0, [r4]
	ldr r4, [sp, #0x148]
	ldr r0, [r4]
	str r0, [r6]
	ldr r5, [sp, #0x144]
	ldrb r0, [r5]
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x164]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x168]
	ldrb r0, [r4]
	mov r5, sl
	strb r0, [r5]
	ldr r6, [sp, #0x16c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x140]
	strb r0, [r1]
	add r2, sp, #0x138
	ldrb r4, [r2]
	mov r2, ip
	strb r4, [r2]
	ldr r4, [sp, #0x14c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x178]
	strb r1, [r5]
	ldr r6, [sp, #0x170]
	strb r3, [r6]
	ldr r4, [sp, #0x144]
	strb r0, [r4]
	ldr r5, [sp, #0x148]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x15c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x164]
	strb r0, [r4]
	ldr r5, [sp, #0x168]
	strb r1, [r5]
	ldr r6, [sp, #0x16c]
	strb r2, [r6]
	ldr r0, [sp, #0x180]
	str r3, [r0]
	ldr r2, [sp, #0x174]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x13c]
	strb r0, [r3]
_081C472A:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x17c]
	strh r0, [r4]
	movs r0, #0
	b _081C483E
	.align 2, 0
_081C473C: .4byte 0x00000482
_081C4740: .4byte 0x0000054F
_081C4744: .4byte 0x0000054C
_081C4748: .4byte 0x0000054E
_081C474C: .4byte 0x00000541
_081C4750: .4byte 0x000005BC
_081C4754: .4byte 0x00000542
_081C4758: .4byte 0x030046B8
_081C475C: .4byte 0x000003FF
_081C4760: .4byte 0x0203B400
_081C4764:
	add r6, sp, #0x2c
	ldr r0, _081C47A4 @ =0x030046A4
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
	beq _081C47A8
	adds r0, #4
	b _081C47B4
	.align 2, 0
_081C47A4: .4byte 0x030046A4
_081C47A8:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C47B4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081C47EC @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _081C47F4
	ldr r0, _081C47F0 @ =0xFFFFFDFF
	ldr r6, [sp, #0x158]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081C481E
	.align 2, 0
_081C47EC: .4byte 0x000004A4
_081C47F0: .4byte 0xFFFFFDFF
_081C47F4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081C4814
	cmp r0, #2
	beq _081C4810
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C4810:
	movs r0, #1
	b _081C4820
_081C4814:
	ldr r0, _081C4834 @ =0xFFFFFDFF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081C481E:
	movs r0, #0
_081C4820:
	cmp r0, #0
	bne _081C483C
	ldr r3, _081C4838 @ =0x000005C4
	adds r0, r7, r3
_081C4828:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081C483E
	.align 2, 0
_081C4834: .4byte 0xFFFFFDFF
_081C4838: .4byte 0x000005C4
_081C483C:
	movs r0, #1
_081C483E:
	cmp r0, #0
	bne _081C48C4
	ldr r4, _081C4874 @ =0x000004A4
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
	bne _081C487C
	ldr r0, _081C4878 @ =0xFFFFFDFF
	ldr r2, [sp, #0x158]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C48A6
	.align 2, 0
_081C4874: .4byte 0x000004A4
_081C4878: .4byte 0xFFFFFDFF
_081C487C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081C489C
	cmp r0, #2
	beq _081C4898
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C4898:
	movs r0, #1
	b _081C48A8
_081C489C:
	ldr r0, _081C48BC @ =0xFFFFFDFF
	ldr r3, [sp, #0x158]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C48A6:
	movs r0, #0
_081C48A8:
	cmp r0, #0
	bne _081C48C4
_081C48AC:
	ldr r4, _081C48C0 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _081C314C
	.align 2, 0
_081C48BC: .4byte 0xFFFFFDFF
_081C48C0: .4byte 0x000005C4
_081C48C4:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081C4930 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081C4934 @ =0x0000046B
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
	ldr r6, _081C4938 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081C493C @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081C4940 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
_081C491C:
	movs r0, #1
FUN_081c491e:
	add sp, #0x18c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081C4930: .4byte 0x0000046D
_081C4934: .4byte 0x0000046B
_081C4938: .4byte 0x00000469
_081C493C: .4byte 0x0000046A
_081C4940: .4byte 0x00000484

	thumb_func_start FUN_081c4944
FUN_081c4944: @ 0x081C4944
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r4, #0
	bl FUN_080fa77c
	movs r0, #0x4a
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r6, r4, r1
	ldrh r5, [r6]
	ands r5, r0
	cmp r5, #0
	bne _081C49D0
	adds r0, r4, #0
	bl FUN_080f9f20
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C49D0
	movs r1, #0x10
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081C49D0
	adds r0, r4, #0
	bl FUN_080fa7a4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C4986
	adds r0, r4, #0
	bl FUN_080faad8
_081C4986:
	movs r1, #8
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	ldr r6, _081C4A04 @ =0x00000469
	adds r0, r4, r6
	strb r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r4, r6
	str r5, [r0]
	ldr r1, _081C4A08 @ =0x0000046C
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081C4A0C @ =FUN_081c1790
	movs r2, #0x13
	subs r6, #0x17
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081C4A10 @ =0x0000046B
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
_081C49D0:
	adds r0, r7, #0
	bl FUN_081c1e84
	ldrb r0, [r7, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	movs r6, #0xd8
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081C4A14 @ =0x000006C2
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, _081C4A18 @ =0x000006C4
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081C4A04: .4byte 0x00000469
_081C4A08: .4byte 0x0000046C
_081C4A0C: .4byte FUN_081c1790
_081C4A10: .4byte 0x0000046B
_081C4A14: .4byte 0x000006C2
_081C4A18: .4byte 0x000006C4

	thumb_func_start FUN_081c4a1c
FUN_081c4a1c: @ 0x081C4A1C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081c2374
	adds r0, r4, #0
	bl FUN_081b91f4
	adds r0, r4, #0
	bl FUN_081b92e4
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081c4a38
FUN_081c4a38: @ 0x081C4A38
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081c4944
	movs r1, #0x80
	lsls r1, r1, #6
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081C4A5C
	ldr r1, _081C4A8C @ =0x000004BE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081C4A7C
_081C4A5C:
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r2, _081C4A90 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
_081C4A7C:
	adds r0, r4, #0
	bl FUN_081c4a1c
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081C4A8C: .4byte 0x000004BE
_081C4A90: .4byte 0x0000062C

	thumb_func_start FUN_081c4a94
FUN_081c4a94: @ 0x081C4A94
	push {lr}
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start EnemyBombGolem_Destroy
EnemyBombGolem_Destroy: @ 0x081C4AA0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _081C4AB8 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C4ABC
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _081C4AC4
	.align 2, 0
_081C4AB8: .4byte 0x0000025D
_081C4ABC:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_081C4AC4:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _081C4AE0 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081C4AE4
	movs r0, #1
	b _081C4AE6
	.align 2, 0
_081C4AE0: .4byte 0x00000474
_081C4AE4:
	movs r0, #0
_081C4AE6:
	cmp r0, #0
	beq _081C4AF2
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_081C4AF2:
	ldr r1, _081C4B4C @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _081C4B0A
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_081C4B0A:
	ldr r0, _081C4B50 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _081C4B22
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_081C4B22:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081C4B3A
	adds r0, r4, #0
	bl FUN_08002a58
_081C4B3A:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081C4B54
	movs r0, #1
	b _081C4B56
	.align 2, 0
_081C4B4C: .4byte 0x0000044C
_081C4B50: .4byte 0x0000044D
_081C4B54:
	movs r0, #0
_081C4B56:
	cmp r0, #0
	beq _081C4B62
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_081C4B62:
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

	thumb_func_start EnemyBombGolem_Init
EnemyBombGolem_Init: @ 0x081C4B80
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1ac
	adds r7, r0, #0
	str r7, [sp, #0x24]
	ldr r1, _081C4C08 @ =0x0000065C
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r2, _081C4C0C @ =0x000001DF
	adds r1, r7, r2
	movs r0, #3
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_081b8e6c
	ldr r3, _081C4C10 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C4C1C
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _081C4C14 @ =0x00005290
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _081C4C18 @ =0x00001E38
	bl FUN_080e3804
	ldr r4, _081C4C0C @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0x9c]
	cmp r1, #0x11
	beq _081C4BF8
	cmp r1, #0x17
	bne _081C4BFC
_081C4BF8:
	movs r0, #1
	strb r0, [r5, #7]
_081C4BFC:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _081C4C84
	.align 2, 0
_081C4C08: .4byte 0x0000065C
_081C4C0C: .4byte 0x000001DF
_081C4C10: .4byte 0x0000025D
_081C4C14: .4byte 0x00005290
_081C4C18: .4byte 0x00001E38
_081C4C1C:
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
	ldr r2, _081C4D00 @ =0x05000002
	bl CpuSet
	ldr r0, _081C4D04 @ =0x0000CB05
	ldr r1, _081C4D08 @ =0x00005290
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
	ldr r0, _081C4D0C @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081C4D10 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0x9c]
_081C4C84:
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
	ldr r5, _081C4D14 @ =0x0000046F
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
	ldr r1, _081C4D18 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081C4D00 @ =0x05000002
	bl CpuSet
	ldr r3, _081C4D1C @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1a8]
	bl prepare_08231510
	mov r1, sb
	str r1, [sp, #0x58]
	mov r3, r8
	str r3, [sp, #0x5c]
	str r6, [sp, #0x3c]
	ldr r2, [sp, #0x1a8]
	adds r6, r2, #0
	cmp r0, #0
	bne _081C4CF0
	b _081C4E50
_081C4CF0:
	bl VM_GetPC
	cmp r0, #0
	beq _081C4D20
	bl Script_GetValue
	adds r1, r0, #0
	b _081C4D22
	.align 2, 0
_081C4D00: .4byte 0x05000002
_081C4D04: .4byte 0x0000CB05
_081C4D08: .4byte 0x00005290
_081C4D0C: .4byte 0x000004B7
_081C4D10: .4byte 0x000001DF
_081C4D14: .4byte 0x0000046F
_081C4D18: .4byte 0x00000474
_081C4D1C: .4byte 0x000004B6
_081C4D20:
	movs r1, #0
_081C4D22:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081C4D48 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xbc]
	str r4, [sp, #0xc0]
	cmp r0, #0
	beq _081C4D4C
	bl Script_GetValue
	adds r1, r0, #0
	b _081C4D4E
	.align 2, 0
_081C4D48: .4byte 0x00000251
_081C4D4C:
	movs r1, #0
_081C4D4E:
	ldr r2, _081C4D84 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081C4D88 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xbc]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xc4]
	cmp r0, #0
	beq _081C4D8C
	bl Script_GetValue
	b _081C4D90
	.align 2, 0
_081C4D84: .4byte 0x00000252
_081C4D88: .4byte 0x000004B4
_081C4D8C:
	ldr r4, [sp, #0xbc]
	ldrb r0, [r4]
_081C4D90:
	strb r0, [r6]
	ldr r5, [sp, #0xbc]
	ldrb r1, [r5]
	ldr r6, [sp, #0xc4]
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
	blt _081C4DC8
	cmp r1, #0
	blt _081C4DC8
	ldr r0, _081C4DCC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C4DC8
	ldr r0, _081C4DD0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C4DD4
_081C4DC8:
	movs r1, #0
	b _081C4DE2
	.align 2, 0
_081C4DCC: .4byte 0x030046A8
_081C4DD0: .4byte 0x030046AC
_081C4DD4:
	ldr r0, _081C4DFC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081C4DE2:
	ldr r2, _081C4E00 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C4E04
	adds r0, #4
	b _081C4E10
	.align 2, 0
_081C4DFC: .4byte 0x030046A4
_081C4E00: .4byte 0x00000256
_081C4E04:
	ldr r0, _081C4E24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C4E10:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C4E28
	cmp r2, #2
	beq _081C4E2C
	b _081C4E30
	.align 2, 0
_081C4E24: .4byte 0x030046A4
_081C4E28:
	ldrb r0, [r4, #4]
	b _081C4E2E
_081C4E2C:
	ldrb r0, [r4]
_081C4E2E:
	subs r1, r1, r0
_081C4E30:
	ldr r3, _081C4E48 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081C4E4C @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _081C4E90
	.align 2, 0
_081C4E48: .4byte 0x00000472
_081C4E4C: .4byte 0x0000FFFF
_081C4E50:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081C4EB4 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081C4EB8 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081C4EBC @ =0x000004B4
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
	str r5, [sp, #0xbc]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xc4]
_081C4E90:
	movs r0, #0x4e
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _081C4EDA
	bl VM_GetPC
	cmp r0, #0
	beq _081C4EC0
	bl Script_GetValue
	adds r4, r0, #0
	b _081C4EC2
	.align 2, 0
_081C4EB4: .4byte 0x00000251
_081C4EB8: .4byte 0x00000252
_081C4EBC: .4byte 0x000004B4
_081C4EC0:
	movs r4, #0x30
_081C4EC2:
	bl VM_GetPC
	cmp r0, #0
	beq _081C4ED4
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081C4ED6
_081C4ED4:
	movs r5, #0x40
_081C4ED6:
	mov r8, r4
	b _081C4EE0
_081C4EDA:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081C4EE0:
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _081C4F18
	bl VM_GetPC
	cmp r0, #0
	beq _081C4EFA
	bl Script_GetValue
	adds r6, r0, #0
	b _081C4EFC
_081C4EFA:
	movs r6, #0
_081C4EFC:
	bl VM_GetPC
	cmp r0, #0
	beq _081C4F0C
	bl Script_GetValue
	adds r1, r0, #0
	b _081C4F0E
_081C4F0C:
	movs r1, #0
_081C4F0E:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081C4F22
_081C4F18:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081C4F22:
	movs r0, #0x61
	bl prepare_08231510
	ldr r1, _081C51A8 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xe0]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xb8]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x68]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xcc]
	lsls r4, r4, #0x10
	str r4, [sp, #0x90]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x98]
	lsls r6, r6, #0x10
	str r6, [sp, #0xa0]
	lsls r5, r5, #0x10
	str r5, [sp, #0x94]
	ldr r4, _081C51AC @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xd4]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x88]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x198]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa4]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xa8]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x19c]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x1a0]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x18c]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x54]
	ldr r1, _081C51B0 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x48]
	ldr r2, _081C51B4 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x4c]
	ldr r3, _081C51B8 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x50]
	ldr r4, _081C51BC @ =0x00000476
	adds r4, r7, r4
	str r4, [sp, #0x40]
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x44]
	ldr r6, _081C51C0 @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x78]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x7c]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x100]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x108]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x110]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x120]
	ldr r6, _081C51C4 @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0x124]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x138]
	ldr r2, _081C51C8 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0x13c]
	ldr r3, _081C51CC @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0x144]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x148]
	ldr r5, _081C51D0 @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0x14c]
	ldr r6, _081C51D4 @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x154]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x140]
	ldr r2, _081C51D8 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0x104]
	ldr r3, _081C51DC @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x178]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x17c]
	ldr r5, _081C51E0 @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0xac]
	ldr r6, _081C51E4 @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x180]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x168]
	ldr r2, _081C51E8 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x15c]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x16c]
	ldr r4, _081C51EC @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x170]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x174]
	ldr r6, _081C51F0 @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x184]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x188]
	ldr r2, _081C51F4 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0x134]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x160]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x158]
	ldr r5, _081C51F8 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x164]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x150]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x128]
	ldr r2, _081C51FC @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x190]
	ldr r3, _081C5200 @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0x10c]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x194]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x130]
	ldr r6, _081C5204 @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0x114]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x118]
	ldr r2, _081C5208 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0x11c]
	ldr r3, _081C520C @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0x12c]
	ldr r4, _081C5210 @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0xb0]
	movs r5, #0xcc
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x70]
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x74]
	ldr r1, _081C5214 @ =0x00000496
	adds r1, r7, r1
	str r1, [sp, #0x64]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x30]
	ldr r3, _081C5218 @ =0x00000469
	adds r3, r7, r3
	str r3, [sp, #0x34]
	ldr r4, _081C521C @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x38]
	ldr r5, _081C5220 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0xb4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xfc]
	movs r1, #0x92
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x60]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x8c]
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x84]
	ldr r4, _081C5224 @ =0x00000572
	adds r4, r7, r4
	str r4, [sp, #0xf8]
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x80]
	movs r6, #0xae
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xf4]
	ldr r1, _081C5228 @ =0x0000055C
	adds r1, r7, r1
	str r1, [sp, #0xc8]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xd0]
	ldr r3, _081C522C @ =0x00000564
	adds r3, r7, r3
	str r3, [sp, #0xd8]
	ldr r4, _081C5230 @ =0x00000565
	adds r4, r7, r4
	str r4, [sp, #0xdc]
	ldr r5, _081C5234 @ =0x00000566
	adds r5, r7, r5
	str r5, [sp, #0xe4]
	ldr r6, _081C5238 @ =0x00000567
	adds r6, r7, r6
	str r6, [sp, #0xe8]
	movs r1, #0xad
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xec]
	ldr r2, _081C523C @ =0x0000056C
	adds r2, r7, r2
	str r2, [sp, #0xf0]
	cmp r0, #0
	bne _081C517A
	b _081C5298
_081C517A:
	movs r3, #0
	mov sl, r3
	movs r4, #0x8d
	lsls r4, r4, #2
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r5, r5, r7
	mov r8, r5
	movs r6, #0x8b
	lsls r6, r6, #2
	adds r5, r7, r6
	movs r0, #0x89
	lsls r0, r0, #2
	adds r4, r7, r0
_081C519A:
	bl VM_GetPC
	cmp r0, #0
	beq _081C5240
	bl Script_GetValue
	b _081C5242
	.align 2, 0
_081C51A8: .4byte 0x0000025D
_081C51AC: .4byte 0x0000025A
_081C51B0: .4byte 0x0000047A
_081C51B4: .4byte 0x0000047C
_081C51B8: .4byte 0x0000047E
_081C51BC: .4byte 0x00000476
_081C51C0: .4byte 0x000004A4
_081C51C4: .4byte 0x000005A4
_081C51C8: .4byte 0x000005C4
_081C51CC: .4byte 0x000005CC
_081C51D0: .4byte 0x000005D4
_081C51D4: .4byte 0x000005DC
_081C51D8: .4byte 0x00000584
_081C51DC: .4byte 0x00000604
_081C51E0: .4byte 0x0000021D
_081C51E4: .4byte 0x0000060C
_081C51E8: .4byte 0x000005E4
_081C51EC: .4byte 0x000005FC
_081C51F0: .4byte 0x00000614
_081C51F4: .4byte 0x000005BC
_081C51F8: .4byte 0x000005EC
_081C51FC: .4byte 0x00000624
_081C5200: .4byte 0x0000058C
_081C5204: .4byte 0x00000594
_081C5208: .4byte 0x0000059C
_081C520C: .4byte 0x000005B4
_081C5210: .4byte 0x00000543
_081C5214: .4byte 0x00000496
_081C5218: .4byte 0x00000469
_081C521C: .4byte 0x0000046A
_081C5220: .4byte 0x00000553
_081C5224: .4byte 0x00000572
_081C5228: .4byte 0x0000055C
_081C522C: .4byte 0x00000564
_081C5230: .4byte 0x00000565
_081C5234: .4byte 0x00000566
_081C5238: .4byte 0x00000567
_081C523C: .4byte 0x0000056C
_081C5240:
	movs r0, #0x18
_081C5242:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081C5254
	bl Script_GetValue
	b _081C5256
_081C5254:
	movs r0, #0x18
_081C5256:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081C5268
	bl Script_GetValue
	b _081C526A
_081C5268:
	movs r0, #0
_081C526A:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _081C527C
	bl Script_GetValue
	b _081C527E
_081C527C:
	movs r0, #0
_081C527E:
	strh r0, [r6]
	movs r1, #2
	add sb, r1
	movs r2, #4
	add r8, r2
	adds r5, #2
	adds r4, #2
	movs r3, #1
	add sl, r3
	mov r6, sl
	cmp r6, #3
	bgt _081C5298
	b _081C519A
_081C5298:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _081C52E4
	bl VM_GetPC
	cmp r0, #0
	beq _081C52B2
	bl Script_GetValue
	adds r4, r0, #0
	b _081C52B6
_081C52B2:
	movs r4, #0x96
	lsls r4, r4, #1
_081C52B6:
	bl VM_GetPC
	cmp r0, #0
	beq _081C52C6
	bl Script_GetValue
	adds r6, r0, #0
	b _081C52CA
_081C52C6:
	movs r6, #0x96
	lsls r6, r6, #1
_081C52CA:
	bl VM_GetPC
	cmp r0, #0
	beq _081C52D8
	bl Script_GetValue
	b _081C52DE
_081C52D8:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_081C52DE:
	ldr r2, [sp, #0xb8]
	strh r0, [r2]
	b _081C52EC
_081C52E4:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0xb8]
	strh r6, [r3]
_081C52EC:
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081C5304
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x5c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_081C5304:
	movs r0, #0x46
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0x6c]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, [sp, #0x68]
	strh r0, [r2]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _081C53D4
	bl VM_GetPC
	cmp r0, #0
	beq _081C5334
	bl Script_GetValue
	b _081C5336
_081C5334:
	movs r0, #0
_081C5336:
	ldr r3, [sp, #0xcc]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _081C5344
	asrs r1, r0, #1
	b _081C534A
_081C5344:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081C534A:
	ldr r5, _081C5360 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081C5364
	bl Script_GetValue
	b _081C5366
	.align 2, 0
_081C5360: .4byte 0x00000546
_081C5364:
	movs r0, #0
_081C5366:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081C537C
	bl Script_GetValue
	b _081C537E
_081C537C:
	movs r0, #0
_081C537E:
	ldr r3, _081C5394 @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081C5398
	bl Script_GetValue
	adds r1, r0, #0
	b _081C539A
	.align 2, 0
_081C5394: .4byte 0x00000187
_081C5398:
	movs r1, #0
_081C539A:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081C53B0
	bl Script_GetValue
	b _081C53B2
_081C53B0:
	movs r0, #0
_081C53B2:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081C53CA
	bl Script_GetValue
	adds r1, r0, #0
	b _081C53CC
_081C53CA:
	movs r1, #0
_081C53CC:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_081C53D4:
	ldr r5, [sp, #0xcc]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r6, [sp, #0x90]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0x98]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0xa0]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0x94]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl prepare_08231510
	cmp r0, #0
	beq _081C5436
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _081C541C
	bl Script_GetValue
	b _081C541E
_081C541C:
	movs r0, #0
_081C541E:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _081C542E
	bl Script_GetValue
	b _081C5430
_081C542E:
	movs r0, #0
_081C5430:
	ldr r6, _081C5498 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_081C5436:
	movs r0, #0x4b
	movs r1, #2
	bl Script_GetKeywordValue
	ldr r1, [sp, #0xd4]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081C545A
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x5c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081C545A:
	movs r0, #0x4c
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081C5472
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x5c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081C5472:
	ldr r4, [sp, #0x88]
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
	ldr r5, [sp, #0x3c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081C549C
	movs r0, #1
	b _081C549E
	.align 2, 0
_081C5498: .4byte 0x00000189
_081C549C:
	movs r0, #0
_081C549E:
	cmp r0, #0
	beq _081C54AE
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _081C54D8 @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_081C54AE:
	ldr r6, [sp, #0xe0]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _081C54BA
	ldr r1, [r7, #0x44]
_081C54BA:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r1, [sp, #0x9c]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _081C54DC
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x198]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _081C54E8
	.align 2, 0
_081C54D8: .4byte FUN_080f48ac
_081C54DC:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x198]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_081C54E8:
	ldr r2, [sp, #0x9c]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081C5536
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081C5536
	cmp r0, #0x16
	beq _081C5536
	cmp r0, #0x14
	beq _081C5536
	cmp r0, #9
	beq _081C5536
	cmp r0, #0x19
	beq _081C5536
	cmp r0, #0x1a
	beq _081C5536
	cmp r0, #0xd
	beq _081C5536
	cmp r0, #0x1b
	beq _081C5536
	cmp r0, #0x1f
	beq _081C5536
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0xbc]
	ldrb r2, [r3]
	ldr r4, [sp, #0xc0]
	ldrb r3, [r4]
	ldr r5, [sp, #0xc4]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl FUN_0823b490
_081C5536:
	movs r1, #8
	ldr r6, [sp, #0x3c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081C5546
	movs r0, #1
	b _081C5548
_081C5546:
	movs r0, #0
_081C5548:
	cmp r0, #0
	beq _081C5556
	ldr r1, [sp, #0xa8]
	ldr r0, [r1]
	ldr r2, [sp, #0xa4]
	str r0, [r2]
	b _081C5568
_081C5556:
	ldr r3, [sp, #0xa8]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0xa4]
	str r0, [r4]
_081C5568:
	ldrh r0, [r7]
	ldr r5, [sp, #0x19c]
	strh r0, [r5]
	ldr r6, [sp, #0x18c]
	ldr r0, [sp, #0x1a0]
	str r6, [r0]
	ldr r1, [sp, #0x2c]
	cmp r1, #0
	beq _081C5592
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
_081C5592:
	ldr r4, _081C55CC @ =0x00000201
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x54]
	strh r0, [r3]
	ldr r6, [sp, #0x48]
	strh r4, [r6]
	ldr r0, [sp, #0x4c]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, r0, r4
	ldr r1, [sp, #0x50]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0xe0]
	ldrb r0, [r2]
	cmp r0, #0
	bne _081C55D0
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _081C55DC
	.align 2, 0
_081C55CC: .4byte 0x00000201
_081C55D0:
	ldr r2, [r7, #0x44]
	ldr r0, _081C5614 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081C55DC:
	ldr r3, [sp, #0xe0]
	ldrb r0, [r3]
	cmp r0, #1
	bne _081C562C
	ldr r4, [sp, #0x9c]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081C5618
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
	b _081C5622
	.align 2, 0
_081C5614: .4byte 0x03003584
_081C5618:
	ldr r5, [sp, #0x9c]
	ldrb r0, [r5]
	bl FUN_080ecf60
	adds r4, r0, #1
_081C5622:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081C562C:
	ldr r6, _081C57FC @ =0x0000047A
	adds r0, r7, r6
	ldrh r0, [r0]
	adds r0, #3
	ldr r2, _081C5800 @ =0x0000047E
	adds r1, r7, r2
	movs r4, #0
	strh r0, [r1]
	ldr r3, [sp, #0x48]
	ldrh r0, [r3]
	adds r0, #2
	ldr r5, [sp, #0x40]
	strh r0, [r5]
	ldrh r0, [r3]
	ldr r6, [sp, #0x44]
	strh r0, [r6]
	adds r0, r7, #0
	bl FUN_081b9250
	ldr r1, [sp, #0x24]
	ldr r2, _081C5804 @ =0x0000066C
	adds r0, r1, r2
	movs r3, #0xd2
	lsls r3, r3, #3
	adds r1, r1, r3
	mov r8, r1
	ldr r5, _081C5808 @ =FUN_081c4a38
	mov sb, r5
	ldr r6, _081C580C @ =FUN_081b919c
	mov sl, r6
	ldr r1, _081C5810 @ =FUN_081b9e40
	mov ip, r1
	ldr r5, _081C5814 @ =FUN_081bcb30
	ldr r3, _081C5818 @ =FUN_080f62b0
	ldr r2, _081C581C @ =FUN_080f62ac
	str r2, [sp, #0x1a4]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x58]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x78]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x7c]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0x100]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0x108]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0x110]
	str r2, [r6]
	ldr r1, _081C5820 @ =FUN_081b9df8
	ldr r2, [sp, #0x120]
	str r1, [r2]
	ldr r6, _081C5824 @ =FUN_081b9e1c
	ldr r1, [sp, #0x124]
	str r6, [r1]
	ldr r2, _081C5828 @ =FUN_081ba7d8
	ldr r6, [sp, #0x138]
	str r2, [r6]
	ldr r1, [sp, #0x13c]
	str r3, [r1]
	ldr r2, [sp, #0x144]
	str r5, [r2]
	ldr r3, _081C582C @ =FUN_081c1c60
	ldr r5, [sp, #0x148]
	str r3, [r5]
	ldr r1, _081C5830 @ =FUN_080f44f4
	ldr r6, [sp, #0x14c]
	str r1, [r6]
	ldr r1, _081C5834 @ =FUN_080f410c
	ldr r2, [sp, #0x154]
	str r1, [r2]
	ldr r3, _081C5838 @ =FUN_081bc0f0
	ldr r5, [sp, #0x140]
	str r3, [r5]
	ldr r6, _081C583C @ =FUN_081ba4ec
	ldr r1, [sp, #0x104]
	str r6, [r1]
	ldr r2, [sp, #0x1a4]
	ldr r3, [sp, #0x178]
	str r2, [r3]
	ldr r1, _081C5840 @ =FUN_080f0430
	ldr r5, [sp, #0x17c]
	str r1, [r5]
	movs r1, #1
	ldr r6, [sp, #0xac]
	strb r1, [r6]
	ldr r1, _081C5844 @ =0x085AD470
	ldr r2, [sp, #0x180]
	str r1, [r2]
	ldr r1, _081C5848 @ =FUN_080e73c8
	ldr r3, [sp, #0x168]
	str r1, [r3]
	ldr r5, [sp, #0x15c]
	str r4, [r5]
	ldr r6, [sp, #0x16c]
	str r4, [r6]
	ldr r1, [sp, #0x170]
	str r4, [r1]
	ldr r2, [sp, #0x174]
	str r4, [r2]
	ldr r3, [sp, #0x184]
	str r4, [r3]
	ldr r1, _081C584C @ =FUN_080f0320
	ldr r5, [sp, #0x188]
	str r1, [r5]
	ldr r1, _081C5850 @ =FUN_080eff14
	ldr r6, [sp, #0x134]
	str r1, [r6]
	ldr r1, _081C5854 @ =FUN_080e72b0
	ldr r2, [sp, #0x160]
	str r1, [r2]
	ldr r3, _081C5858 @ =FUN_081bdb78
	ldr r5, [sp, #0x158]
	str r3, [r5]
	ldr r1, _081C585C @ =FUN_080f47c8
	ldr r6, [sp, #0x164]
	str r1, [r6]
	ldr r1, _081C5860 @ =FUN_080f54e4
	ldr r2, [sp, #0x150]
	str r1, [r2]
	ldr r3, [sp, #0x128]
	str r4, [r3]
	ldr r1, _081C5864 @ =FUN_080f6e64
	ldr r5, [sp, #0x190]
	str r1, [r5]
	ldr r1, _081C5868 @ =FUN_080f64f0
	ldr r6, [sp, #0x10c]
	str r1, [r6]
	ldr r1, _081C586C @ =FUN_080f84d4
	ldr r2, [sp, #0x194]
	str r1, [r2]
	ldr r1, _081C5870 @ =FUN_080f624c
	ldr r3, [sp, #0x130]
	str r1, [r3]
	ldr r1, _081C5874 @ =FUN_080f56ec
	ldr r5, [sp, #0x114]
	str r1, [r5]
	ldr r1, _081C5878 @ =FUN_080f5b34
	ldr r6, [sp, #0x118]
	str r1, [r6]
	ldr r1, _081C587C @ =FUN_080f5fac
	ldr r2, [sp, #0x11c]
	str r1, [r2]
	ldr r3, [sp, #0x12c]
	str r4, [r3]
	movs r1, #0x28
	ldr r5, [sp, #0xb0]
	strb r1, [r5]
	ldr r1, [sp, #0x18c]
	bl FUN_082362fc
	adds r0, r7, #0
	bl FUN_080e6204
	movs r6, #0xbf
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _081C5880 @ =FUN_081b8eec
	str r0, [r1]
	ldr r0, _081C5884 @ =0x000005FC
	adds r1, r7, r0
	ldr r0, _081C5888 @ =FUN_081b908c
	str r0, [r1]
	ldr r2, _081C588C @ =0x000005AC
	adds r1, r7, r2
	ldr r0, _081C5890 @ =FUN_081b88b0
	str r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _081C5894 @ =FUN_081b8988
	str r0, [r1]
	ldr r5, _081C5898 @ =0x0000058C
	adds r1, r7, r5
	ldr r0, _081C589C @ =FUN_081c23f4
	str r0, [r1]
	adds r6, #0x30
	adds r1, r7, r6
	ldr r0, _081C58A0 @ =FUN_080fa384
	str r0, [r1]
	movs r0, #0xb5
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081C58A4 @ =FUN_081c1790
	str r0, [r1]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #0xe0
	lsls r1, r1, #0xf
	ldr r2, [sp, #0x58]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #8
	ldr r3, [sp, #0x5c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r4, [sp, #0x70]
	strh r0, [r4]
	movs r0, #0x47
	bl prepare_08231510
	cmp r0, #0
	beq _081C58B2
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_081C57EE:
	bl VM_GetPC
	cmp r0, #0
	beq _081C58A8
	bl Script_GetValue
	b _081C58AA
	.align 2, 0
_081C57FC: .4byte 0x0000047A
_081C5800: .4byte 0x0000047E
_081C5804: .4byte 0x0000066C
_081C5808: .4byte FUN_081c4a38
_081C580C: .4byte FUN_081b919c
_081C5810: .4byte FUN_081b9e40
_081C5814: .4byte FUN_081bcb30
_081C5818: .4byte FUN_080f62b0
_081C581C: .4byte FUN_080f62ac
_081C5820: .4byte FUN_081b9df8
_081C5824: .4byte FUN_081b9e1c
_081C5828: .4byte FUN_081ba7d8
_081C582C: .4byte FUN_081c1c60
_081C5830: .4byte FUN_080f44f4
_081C5834: .4byte FUN_080f410c
_081C5838: .4byte FUN_081bc0f0
_081C583C: .4byte FUN_081ba4ec
_081C5840: .4byte FUN_080f0430
_081C5844: .4byte 0x085AD470
_081C5848: .4byte FUN_080e73c8
_081C584C: .4byte FUN_080f0320
_081C5850: .4byte FUN_080eff14
_081C5854: .4byte FUN_080e72b0
_081C5858: .4byte FUN_081bdb78
_081C585C: .4byte FUN_080f47c8
_081C5860: .4byte FUN_080f54e4
_081C5864: .4byte FUN_080f6e64
_081C5868: .4byte FUN_080f64f0
_081C586C: .4byte FUN_080f84d4
_081C5870: .4byte FUN_080f624c
_081C5874: .4byte FUN_080f56ec
_081C5878: .4byte FUN_080f5b34
_081C587C: .4byte FUN_080f5fac
_081C5880: .4byte FUN_081b8eec
_081C5884: .4byte 0x000005FC
_081C5888: .4byte FUN_081b908c
_081C588C: .4byte 0x000005AC
_081C5890: .4byte FUN_081b88b0
_081C5894: .4byte FUN_081b8988
_081C5898: .4byte 0x0000058C
_081C589C: .4byte FUN_081c23f4
_081C58A0: .4byte FUN_080fa384
_081C58A4: .4byte FUN_081c1790
_081C58A8:
	movs r0, #0
_081C58AA:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081C57EE
_081C58B2:
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0x74]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x64]
	strh r0, [r3]
	cmp r2, #0
	beq _081C58EA
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x58]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _081C58EA
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_081C58EA:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x3c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081C58FC
	movs r0, #1
	b _081C58FE
_081C58FC:
	movs r0, #0
_081C58FE:
	cmp r0, #0
	beq _081C5910
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x5c]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081C5910:
	cmp r2, #1
	beq _081C5950
	movs r1, #0
	ldr r0, [sp, #0x30]
	strb r1, [r0]
	ldr r2, [sp, #0x34]
	strb r1, [r2]
	ldr r3, [sp, #0x38]
	strb r1, [r3]
	ldr r4, _081C5960 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081C5964 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x124]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0xb4]
	strb r1, [r6]
	ldr r0, [sp, #0xfc]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081C5950:
	movs r1, #2
	ldr r3, [sp, #0x3c]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081C5968
	movs r0, #1
	b _081C596A
	.align 2, 0
_081C5960: .4byte 0x00000484
_081C5964: .4byte 0x0000046C
_081C5968:
	movs r0, #0
_081C596A:
	cmp r0, #0
	beq _081C5984
	ldr r0, _081C5980 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x60]
	strh r0, [r5]
	b _081C598E
	.align 2, 0
_081C5980: .4byte 0x030046A0
_081C5984:
	ldr r0, [sp, #0x18c]
	bl FUN_08241574
	ldr r6, [sp, #0x60]
	strh r0, [r6]
_081C598E:
	movs r1, #0x40
	ldr r2, [sp, #0x3c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C599E
	movs r0, #1
	b _081C59A0
_081C599E:
	movs r0, #0
_081C59A0:
	cmp r0, #0
	beq _081C59B0
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _081C59D4 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_081C59B0:
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _081C59E2
	ldr r0, _081C59D8 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x60]
	ldrh r4, [r4]
	cmp r0, r4
	bne _081C59DC
	movs r0, #1
	b _081C59DE
	.align 2, 0
_081C59D4: .4byte 0xFFFFFEFF
_081C59D8: .4byte 0x030046A0
_081C59DC:
	movs r0, #0
_081C59DE:
	cmp r0, #0
	bne _081C59EA
_081C59E2:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_081C59EA:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0xe0]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081C5AD2
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
	beq _081C5A2C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081C5A34
_081C5A2C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081C5A34:
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
	beq _081C5A58
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081C5A60
_081C5A58:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081C5A60:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081C5A98 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081C5ADC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081C5A9C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081C5A90
	ldrb r0, [r4, #5]
_081C5A90:
	subs r0, #1
	strh r0, [r4, #8]
	b _081C5AAC
	.align 2, 0
_081C5A98: .4byte 0x0000FFFF
_081C5A9C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081C5AAC
	strh r1, [r4, #8]
_081C5AAC:
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
	bne _081C5ADC
	movs r0, #1
	strb r0, [r4, #7]
	b _081C5ADC
_081C5AD2:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_081C5ADC:
	movs r0, #0
	ldr r3, [sp, #0x8c]
	str r0, [r3]
	ldr r0, _081C5AF4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C5AF8
	movs r0, #1
	b _081C5AFA
	.align 2, 0
_081C5AF4: .4byte 0x030047A4
_081C5AF8:
	movs r0, #0
_081C5AFA:
	cmp r0, #0
	bne _081C5B3A
	ldr r4, [sp, #0x9c]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081C5B22
	adds r0, r1, #0
	cmp r0, #7
	beq _081C5B22
	cmp r0, #6
	beq _081C5B22
	cmp r0, #0x15
	beq _081C5B22
	cmp r0, #0x14
	beq _081C5B22
	cmp r0, #0x17
	bne _081C5B3A
_081C5B22:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x3c]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_081C5B3A:
	ldr r6, [sp, #0x84]
	ldr r0, [r6]
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r2, [sp, #0xa4]
	ldr r1, [r2]
	str r1, [r0]
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	ldr r3, _081C5C20 @ =0x00000634
	adds r1, r7, r3
	ldr r0, _081C5C24 @ =0x085ADFDC
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_081be848
	adds r0, r7, #0
	bl FUN_081c177c
	ldr r4, [sp, #0x24]
	ldr r5, _081C5C28 @ =0x000006C1
	adds r0, r4, r5
	movs r2, #0
	strb r2, [r0]
	ldr r6, _081C5C2C @ =0x000006B4
	adds r3, r4, r6
	movs r4, #0
	movs r0, #0x78
	strh r0, [r3]
	ldr r1, [sp, #0x24]
	subs r5, #7
	adds r0, r1, r5
	strh r2, [r0]
	adds r6, #4
	adds r1, r1, r6
	movs r0, #2
	strh r0, [r1]
	ldr r1, [sp, #0x24]
	subs r5, #4
	adds r0, r1, r5
	strh r2, [r0]
	movs r0, #0xa0
	strh r0, [r3]
	adds r6, #6
	adds r0, r1, r6
	strh r2, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r1, r2
	strb r4, [r0]
	ldr r3, _081C5C30 @ =0x000006C7
	adds r0, r1, r3
	strb r4, [r0]
	ldr r4, [sp, #0x3c]
	ldrh r0, [r4]
	ldr r5, [sp, #0xf8]
	strh r0, [r5]
	ldr r6, [sp, #0x80]
	ldrh r0, [r6]
	ldr r1, [sp, #0xf4]
	strh r0, [r1]
	ldr r2, [sp, #0x58]
	ldr r0, [r2]
	ldr r3, [sp, #0xc8]
	str r0, [r3]
	ldr r4, [sp, #0x5c]
	ldr r0, [r4]
	ldr r5, [sp, #0xd0]
	str r0, [r5]
	ldrb r0, [r7, #5]
	ldr r6, [sp, #0xd8]
	strb r0, [r6]
	ldr r1, [sp, #0x30]
	ldrb r0, [r1]
	ldr r2, [sp, #0xdc]
	strb r0, [r2]
	ldr r3, [sp, #0x34]
	ldrb r0, [r3]
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
	ldr r5, [sp, #0x38]
	ldrb r0, [r5]
	ldr r6, [sp, #0xe8]
	strb r0, [r6]
	ldr r1, [sp, #0xfc]
	ldr r0, [r1]
	ldr r2, [sp, #0xec]
	str r0, [r2]
	ldr r3, [sp, #0xb4]
	ldrb r0, [r3]
	ldr r4, [sp, #0xf0]
	strb r0, [r4]
	ldr r5, _081C5C34 @ =0x0000057C
	adds r1, r7, r5
	ldr r0, _081C5C38 @ =FUN_080f09e0
	str r0, [r1]
	ldr r6, _081C5C3C @ =0x0000061C
	adds r1, r7, r6
	ldr r0, _081C5C40 @ =FUN_081c4a94
	str r0, [r1]
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081C5C44 @ =EnemyBombGolem_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C5C48
	movs r0, #0
	b _081C5C4C
	.align 2, 0
_081C5C20: .4byte 0x00000634
_081C5C24: .4byte 0x085ADFDC
_081C5C28: .4byte 0x000006C1
_081C5C2C: .4byte 0x000006B4
_081C5C30: .4byte 0x000006C7
_081C5C34: .4byte 0x0000057C
_081C5C38: .4byte FUN_080f09e0
_081C5C3C: .4byte 0x0000061C
_081C5C40: .4byte FUN_081c4a94
_081C5C44: .4byte EnemyBombGolem_Destroy
_081C5C48:
	movs r0, #1
	rsbs r0, r0, #0
_081C5C4C:
	add sp, #0x1ac
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

@ 通信対戦専用のエネミー
	thumb_func_start EnemyBombGolem_Create
EnemyBombGolem_Create: @ 0x081C5C5C
	push {r4, r5, lr}
	ldr r5, _081C5C90 @ =0x000006E4
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _081C5C88
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyBombGolem_Init
	cmp r0, #0
	bge _081C5C88
	adds r0, r4, #0
	bl EnemyBombGolem_Destroy
	adds r0, r4, #0
	bl Free
_081C5C88:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081C5C90: .4byte 0x000006E4
