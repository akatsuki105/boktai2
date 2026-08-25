	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080091c4
FUN_080091c4: @ 0x080091C4
	adds r2, r0, #0
	strb r1, [r2, #5]
	movs r1, #1
	strb r1, [r2, #6]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080091d0
FUN_080091d0: @ 0x080091D0
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #6]
	cmp r0, #0
	bne _080091DE
	movs r0, #0
	b _080091E4
_080091DE:
	movs r0, #0
	strb r0, [r1, #6]
	movs r0, #1
_080091E4:
	pop {r1}
	bx r1

	thumb_func_start FUN_080091e8
FUN_080091e8: @ 0x080091E8
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x50
	ldr r1, _0800921C @ =0x0000A850
	adds r0, r6, #0
	bl FUN_0822b16c
	cmp r0, #0
	beq _08009220
	adds r4, r5, #0
	adds r4, #0x24
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #1
	bl FUN_0822a470
	movs r0, #1
	strh r0, [r4, #0x10]
	adds r1, r5, #0
	adds r1, #0x2b
	movs r0, #2
	strb r0, [r1]
	movs r0, #0
	b _08009224
	.align 2, 0
_0800921C: .4byte 0x0000A850
_08009220:
	movs r0, #1
	rsbs r0, r0, #0
_08009224:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800922c
FUN_0800922c: @ 0x0800922C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	cmp r2, #0
	beq _0800923C
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r2]
_0800923C:
	ldr r3, [r4, #0x20]
	movs r1, #0
	ldrb r0, [r4, #0x18]
	cmp r1, r0
	bge _0800926E
	movs r7, #1
	ldr r5, [r4, #0x1c]
	adds r4, r0, #0
_0800924C:
	adds r0, r7, #0
	lsls r0, r1
	ands r0, r5
	cmp r0, #0
	beq _08009266
	ldrh r0, [r3]
	cmp r0, r6
	bne _08009266
	cmp r2, #0
	beq _08009262
	str r1, [r2]
_08009262:
	adds r0, r3, #0
	b _08009270
_08009266:
	adds r1, #1
	adds r3, #0x6c
	cmp r1, r4
	blt _0800924C
_0800926E:
	movs r0, #0
_08009270:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08009278
FUN_08009278: @ 0x08009278
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	adds r4, r2, #0
	adds r4, #0x50
	ldrb r1, [r2, #4]
	cmp r1, #0
	bne _08009292
	adds r1, r3, #0
	adds r1, #0x4c
	adds r0, r4, #0
	bl FUN_0822b20c
_08009292:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009298
FUN_08009298: @ 0x08009298
	push {r4, lr}
	adds r3, r1, #0
	adds r4, r3, #0
	adds r4, #0x24
	ldrh r1, [r2]
	strh r1, [r3, #0x1c]
	ldrh r1, [r2, #2]
	strh r1, [r3, #0x1e]
	ldrh r1, [r2, #4]
	strh r1, [r3, #0x20]
	ldrh r1, [r2]
	strh r1, [r4, #0x1c]
	ldrh r1, [r2, #2]
	strh r1, [r4, #0x1e]
	ldrh r1, [r2, #4]
	strh r1, [r4, #0x20]
	ldrb r1, [r3, #2]
	cmp r1, #0
	beq _080092CC
	ldrh r1, [r3, #0x1c]
	adds r1, #0x80
	strh r1, [r3, #0x1c]
	ldrh r1, [r4, #0x20]
	subs r1, #0x80
	strh r1, [r4, #0x20]
	b _080092D8
_080092CC:
	ldrh r1, [r3, #0x20]
	adds r1, #0x80
	strh r1, [r3, #0x20]
	ldrh r1, [r4, #0x1c]
	subs r1, #0x80
	strh r1, [r4, #0x1c]
_080092D8:
	ldrh r1, [r4, #0x1c]
	adds r1, #0x3c
	strh r1, [r4, #0x1c]
	ldrh r1, [r4, #0x20]
	adds r1, #0x3c
	strh r1, [r4, #0x20]
	ldrh r1, [r4, #0x1e]
	adds r1, #0x14
	strh r1, [r4, #0x1e]
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080092f0
FUN_080092f0: @ 0x080092F0
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #4]
	cmp r0, #1
	beq _0800935C
	ldrb r0, [r4, #5]
	cmp r0, #1
	beq _08009330
	cmp r0, #1
	bgt _0800930A
	cmp r0, #0
	beq _08009310
	b _0800935C
_0800930A:
	cmp r0, #2
	beq _08009350
	b _0800935C
_08009310:
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _08009320
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08009278
	b _0800935C
_08009320:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08009278
	ldrb r0, [r4, #7]
	subs r0, #1
	strb r0, [r4, #7]
	b _0800935C
_08009330:
	ldrb r0, [r4, #7]
	cmp r0, #4
	bls _08009340
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08009278
	b _0800935C
_08009340:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08009278
	ldrb r0, [r4, #7]
	adds r0, #1
	strb r0, [r4, #7]
	b _0800935C
_08009350:
	movs r0, #5
	strb r0, [r4, #7]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08009278
_0800935C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08009364
FUN_08009364: @ 0x08009364
	push {lr}
	adds r3, r0, #0
	ldr r2, [r3, #0x24]
	ldr r1, _0800938C @ =0x0000186C
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08009390
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08009390
	movs r0, #0x19
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bge _08009390
	movs r0, #1
	b _08009392
	.align 2, 0
_0800938C: .4byte 0x0000186C
_08009390:
	movs r0, #0
_08009392:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08009398
FUN_08009398: @ 0x08009398
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r2, #0
	cmp r5, #0
	beq _080093D4
	ldrh r0, [r1]
	str r0, [sp]
	movs r3, #0
	add r4, sp, #0x14
	adds r1, #0x14
	add r2, sp, #4
_080093AE:
	movs r6, #0
	ldrsh r0, [r1, r6]
	stm r2!, {r0}
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _080093AE
	ldr r0, _080093DC @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r0
	movs r0, #5
	orrs r1, r0
	str r1, [sp, #0x14]
	mov r0, sp
	str r0, [r4, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	bl Script_ExecById
_080093D4:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080093DC: .4byte 0xFFFF0000

	thumb_func_start FUN_080093e0
FUN_080093e0: @ 0x080093E0
	adds r2, r0, #0
	movs r3, #0
	strb r1, [r2, #0x19]
	strb r3, [r2, #0x1a]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080093ec
FUN_080093ec: @ 0x080093EC
	adds r2, r0, #0
	strb r1, [r2, #0x19]
	movs r1, #1
	strb r1, [r2, #0x1a]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080093f8
FUN_080093f8: @ 0x080093F8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_080091d0
	ldr r0, [r6, #0x24]
	cmp r0, #0
	beq _080094A4
	movs r0, #6
	ldr r1, _08009468 @ =0x03002BC0
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _080094A4
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080094A4
	movs r1, #0x1c
	ldrsh r0, [r5, r1]
	movs r2, #0x28
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #0x20
	ldrsh r1, [r5, r3]
	movs r3, #0x2c
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	adds r4, r0, #0
	muls r4, r0, r4
	adds r2, r1, #0
	muls r2, r1, r2
	adds r4, r4, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	ldr r0, [r5, #0x10]
	cmp r4, r0
	bhs _080094A4
	ldrb r0, [r5, #2]
	cmp r0, #0
	beq _0800946C
	movs r2, #0
	movs r3, #1
	movs r4, #2
	b _08009472
	.align 2, 0
_08009468: .4byte 0x03002BC0
_0800946C:
	movs r2, #6
	movs r3, #7
	movs r4, #0
_08009472:
	cmp r2, r1
	beq _0800947E
	cmp r3, r1
	beq _0800947E
	cmp r4, r1
	bne _080094A4
_0800947E:
	ldr r0, [r6, #0x24]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #1
	cmp r2, r0
	beq _08009498
	cmp r3, r0
	beq _08009498
	cmp r4, r0
	beq _08009498
	movs r1, #0
_08009498:
	cmp r1, #0
	beq _080094A4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080091c4
_080094A4:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080094ac
FUN_080094ac: @ 0x080094AC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	adds r0, r5, #0
	bl FUN_080091d0
	ldr r0, [r6, #0x24]
	cmp r0, #0
	beq _0800958C
	movs r0, #6
	ldr r1, _0800951C @ =0x03002BC0
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _0800958C
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0800958C
	movs r1, #0x1c
	ldrsh r0, [r5, r1]
	movs r2, #0x28
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #0x20
	ldrsh r1, [r5, r3]
	movs r3, #0x2c
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	adds r4, r0, #0
	muls r4, r0, r4
	adds r2, r1, #0
	muls r2, r1, r2
	adds r4, r4, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	ldr r0, [r5, #0x10]
	cmp r4, r0
	bhs _0800958C
	ldrb r0, [r5, #2]
	cmp r0, #0
	beq _08009520
	movs r2, #0
	movs r3, #1
	movs r4, #2
	b _08009526
	.align 2, 0
_0800951C: .4byte 0x03002BC0
_08009520:
	movs r2, #6
	movs r3, #7
	movs r4, #0
_08009526:
	cmp r2, r1
	beq _08009532
	cmp r3, r1
	beq _08009532
	cmp r4, r1
	bne _0800958C
_08009532:
	ldr r0, [r6, #0x24]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #1
	cmp r2, r0
	beq _0800954C
	cmp r3, r0
	beq _0800954C
	cmp r4, r0
	beq _0800954C
	movs r1, #0
_0800954C:
	cmp r1, #0
	beq _0800958C
	ldr r0, _08009588 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08009594
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08009364
	cmp r0, #0
	beq _08009594
	movs r0, #5
	strb r0, [r5, #7]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08009278
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080091c4
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_080093e0
	b _08009594
	.align 2, 0
_08009588: .4byte 0x030044E0
_0800958C:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080091c4
_08009594:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800959c
FUN_0800959c: @ 0x0800959C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	adds r0, r6, #0
	bl FUN_080091d0
	ldr r0, [r7, #0x24]
	cmp r0, #0
	beq _08009640
	movs r0, #6
	ldr r1, _0800960C @ =0x03002BC0
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08009640
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _08009640
	movs r1, #0x1c
	ldrsh r0, [r6, r1]
	movs r2, #0x28
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r3, #0x20
	ldrsh r1, [r6, r3]
	movs r3, #0x2c
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	adds r4, r0, #0
	muls r4, r0, r4
	adds r2, r1, #0
	muls r2, r1, r2
	adds r4, r4, r2
	bl FUN_0823785c
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r1, #0x10
	movs r2, #0xff
	ands r1, r2
	asrs r1, r1, #5
	adds r2, r1, #3
	movs r1, #7
	ands r2, r1
	ldr r1, [r6, #0x10]
	cmp r4, r1
	bhs _08009640
	ldrb r1, [r6, #2]
	cmp r1, #0
	beq _08009610
	movs r3, #0
	movs r4, #1
	movs r5, #2
	b _08009616
	.align 2, 0
_0800960C: .4byte 0x03002BC0
_08009610:
	movs r3, #6
	movs r4, #7
	movs r5, #0
_08009616:
	cmp r3, r2
	beq _08009622
	cmp r4, r2
	beq _08009622
	cmp r5, r2
	bne _08009640
_08009622:
	ldr r1, [r7, #0x24]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r1, r2
	ldrb r1, [r1]
	movs r2, #1
	cmp r3, r1
	beq _0800963C
	cmp r4, r1
	beq _0800963C
	cmp r5, r1
	beq _0800963C
	movs r2, #0
_0800963C:
	cmp r2, #0
	bne _0800964A
_08009640:
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080091c4
	movs r0, #0
_0800964A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity83B2_Update
Entity83B2_Update: @ 0x08009650
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _08009662
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r5, #0x28]
	str r1, [r5, #0x2c]
_08009662:
	ldr r4, [r5, #0x20]
	movs r6, #0
	b _080096DA
_08009668:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r5, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _080096D6
	ldr r1, [r4, #8]
	cmp r1, #0
	blt _080096AA
	ldr r0, _08009690 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, r1
	bne _08009694
	movs r0, #1
	b _08009696
	.align 2, 0
_08009690: .4byte 0x030046A0
_08009694:
	movs r0, #0
_08009696:
	cmp r0, #0
	bne _080096AA
	ldrb r0, [r4, #4]
	cmp r0, #1
	beq _080096D6
	ldr r0, [r4, #0x24]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x24]
	b _080096D6
_080096AA:
	ldrb r0, [r4, #4]
	cmp r0, #1
	beq _080096BA
	ldr r0, [r4, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x24]
_080096BA:
	ldr r0, _08009714 @ =0x085AA6AC
	ldrb r1, [r4, #5]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r3, [r1]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl _call_via_r3
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080092f0
_080096D6:
	adds r6, #1
	adds r4, #0x6c
_080096DA:
	ldrb r0, [r5, #0x18]
	cmp r6, r0
	blt _08009668
	ldrb r3, [r5, #0x1a]
	movs r2, #0x1a
	ldrsb r2, [r5, r2]
	cmp r2, #0
	blt _08009734
	ldrb r6, [r5, #0x19]
	movs r0, #0x19
	ldrsb r0, [r5, r0]
	cmp r0, #0
	blt _08009734
	adds r1, r0, #0
	movs r0, #0x6c
	muls r1, r0, r1
	ldr r0, [r5, #0x20]
	adds r4, r0, r1
	cmp r2, #0
	bne _08009718
	movs r0, #0xff
	strb r0, [r5, #0x1a]
	ldrh r2, [r4, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08009398
	b _08009734
	.align 2, 0
_08009714: .4byte 0x085AA6AC
_08009718:
	cmp r2, #1
	bne _08009734
	movs r1, #0xff
	adds r0, r3, #0
	orrs r0, r1
	strb r0, [r5, #0x1a]
	adds r0, r6, #0
	orrs r0, r1
	strb r0, [r5, #0x19]
	ldrh r2, [r4, #0xe]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08009398
_08009734:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity83B2_Destroy
Entity83B2_Destroy: @ 0x0800973C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, [r6, #0x20]
	movs r5, #0
	b _08009752
_08009746:
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_0822a4e0
	adds r5, #1
	adds r4, #0x6c
_08009752:
	ldrb r0, [r6, #0x18]
	cmp r5, r0
	blt _08009746
	ldr r0, [r6, #0x20]
	cmp r0, #0
	beq _08009762
	bl Free
_08009762:
	ldr r1, _08009770 @ =0x0300003C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08009770: .4byte 0x0300003C

	thumb_func_start Entity83B2_Init
Entity83B2_Init: @ 0x08009774
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080097AC @ =0x0300003C
	str r4, [r0]
	movs r0, #0x6e
	movs r1, #1
	bl Script_GetKeywordValue
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #0xff
	strb r0, [r4, #0x19]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r4, #0x1a]
	str r1, [r4, #0x1c]
	ldrb r0, [r4, #0x18]
	movs r5, #0x6c
	muls r0, r5, r0
	bl Malloc
	adds r2, r0, #0
	str r2, [r4, #0x20]
	cmp r2, #0
	bne _080097B0
_080097A6:
	movs r0, #1
	rsbs r0, r0, #0
	b _080097FC
	.align 2, 0
_080097AC: .4byte 0x0300003C
_080097B0:
	ldrb r0, [r4, #0x18]
	adds r1, r0, #0
	muls r1, r5, r1
	adds r0, r2, #0
	bl ClearMemory
	ldr r6, [r4, #0x20]
	movs r5, #0
	b _080097D4
_080097C2:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl FUN_080091e8
	cmp r0, #0
	blt _080097A6
	adds r5, #1
	adds r6, #0x6c
_080097D4:
	ldrb r0, [r4, #0x18]
	cmp r5, r0
	blt _080097C2
	ldr r0, _080097F0 @ =0x03002BE0
	ldr r0, [r0]
	str r0, [r4, #0x24]
	cmp r0, #0
	beq _080097F4
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	b _080097FA
	.align 2, 0
_080097F0: .4byte 0x03002BE0
_080097F4:
	strh r0, [r4, #0x28]
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x2c]
_080097FA:
	movs r0, #0
_080097FC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

