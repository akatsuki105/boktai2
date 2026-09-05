	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b9390
FUN_080b9390: @ 0x080B9390
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _080B93AC @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	movs r3, #0x1f
	ands r1, r3
	lsls r1, r1, #1
	adds r0, r0, r1
	ands r2, r3
	lsls r2, r2, #6
	adds r0, r0, r2
	bx lr
	.align 2, 0
_080B93AC: .4byte 0x03003ED0

	thumb_func_start FUN_080b93b0
FUN_080b93b0: @ 0x080B93B0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r4, [sp, #0x14]
	movs r0, #0
	bl FUN_080b9390
	adds r7, r0, #0
	lsls r4, r4, #4
	adds r4, #0x21
	cmp r6, #0
	ble _080B93F8
_080B93CC:
	adds r0, r5, #0
	adds r1, r6, #0
	bl Div
	adds r1, r0, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r3, #0xf0
	lsls r3, r3, #8
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r7]
	adds r7, #2
	muls r0, r6, r0
	subs r5, r5, r0
	adds r0, r6, #0
	movs r1, #0xa
	bl Div
	adds r6, r0, #0
	cmp r6, #0
	bgt _080B93CC
_080B93F8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b9400
FUN_080b9400: @ 0x080B9400
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x12
	movs r2, #0
	bl FUN_080b9390
	adds r1, r0, #0
	cmp r4, #0
	bne _080B9444
	ldr r2, _080B9440 @ =0x0000F03B
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1, #2]
	bl GetHour
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_080b93b0
	bl GetMinute
	b _080B9470
	.align 2, 0
_080B9440: .4byte 0x0000F03B
_080B9444:
	cmp r4, #1
	bne _080B9488
	ldr r2, _080B9480 @ =0x0000F045
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _080B9484 @ =0x030047E0
	ldrb r0, [r5, #0xa]
	movs r4, #0
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_080b93b0
	ldrb r0, [r5, #0xb]
_080B9470:
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x19
	movs r3, #0
	bl FUN_080b93b0
	b _080B94BC
	.align 2, 0
_080B9480: .4byte 0x0000F045
_080B9484: .4byte 0x030047E0
_080B9488:
	ldr r2, _080B94C4 @ =0x0000F045
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _080B94C8 @ =0x030047E0
	ldrb r0, [r5, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_080b93b0
	ldrb r0, [r5, #0xd]
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x19
	movs r3, #0
	bl FUN_080b93b0
_080B94BC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B94C4: .4byte 0x0000F045
_080B94C8: .4byte 0x030047E0

	thumb_func_start FUN_080b94cc
FUN_080b94cc: @ 0x080B94CC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x12
	movs r2, #1
	bl FUN_080b9390
	adds r1, r0, #0
	cmp r4, #0
	bne _080B9520
	ldr r2, _080B9518 @ =0x0000F03E
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x2a
	adds r0, r2, #0
	strh r0, [r1]
	subs r2, #0x68
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r0, _080B951C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	b _080B9554
	.align 2, 0
_080B9518: .4byte 0x0000F03E
_080B951C: .4byte 0x030046A0
_080B9520:
	cmp r4, #1
	bne _080B956C
	ldr r2, _080B9564 @ =0x0000F040
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #4
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x2c
	adds r0, r2, #0
	strh r0, [r1]
	subs r2, #0x39
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r0, _080B9568 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
_080B9554:
	movs r1, #0xfa
	lsls r1, r1, #2
	str r4, [sp]
	movs r2, #0x17
	movs r3, #1
	bl FUN_080b93b0
	b _080B95AA
	.align 2, 0
_080B9564: .4byte 0x0000F040
_080B9568: .4byte 0x030046A0
_080B956C:
	ldr r2, _080B95B4 @ =0x0000F042
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #6
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #7
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #0x25
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r0, _080B95B8 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, #0x2c
	movs r2, #0
	str r2, [sp]
	movs r2, #0x17
	movs r3, #1
	bl FUN_080b93b0
_080B95AA:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B95B4: .4byte 0x0000F042
_080B95B8: .4byte 0x030046A0

	thumb_func_start FUN_080b95bc
FUN_080b95bc: @ 0x080B95BC
	strh r1, [r0, #0x3a]
	ldr r1, _080B95CC @ =0x03003584
	ldrh r2, [r0, #0x3a]
	lsls r2, r2, #5
	ldr r1, [r1]
	adds r1, r1, r2
	str r1, [r0, #0x48]
	bx lr
	.align 2, 0
_080B95CC: .4byte 0x03003584

	thumb_func_start FUN_080b95d0
FUN_080b95d0: @ 0x080B95D0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r3, #0
	cmp r4, #0
	beq _080B95FC
	movs r1, #4
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B95F4
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r4, #0
	bl FUN_080b95bc
	b _080B95FC
_080B95F4:
	ldr r1, _080B9618 @ =0x000002DF
	adds r0, r4, #0
	bl FUN_080b95bc
_080B95FC:
	cmp r5, #0
	beq _080B9624
	adds r0, r6, #0
	movs r1, #8
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B961C
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r5, #0
	bl FUN_080b95bc
	b _080B9624
	.align 2, 0
_080B9618: .4byte 0x000002DF
_080B961C:
	ldr r1, _080B9640 @ =0x000002DF
	adds r0, r5, #0
	bl FUN_080b95bc
_080B9624:
	cmp r7, #0
	beq _080B964C
	adds r0, r6, #0
	movs r1, #0x10
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9644
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r7, #0
	bl FUN_080b95bc
	b _080B964C
	.align 2, 0
_080B9640: .4byte 0x000002DF
_080B9644:
	ldr r1, _080B9654 @ =0x000002DF
	adds r0, r7, #0
	bl FUN_080b95bc
_080B964C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B9654: .4byte 0x000002DF

	thumb_func_start FUN_080b9658
FUN_080b9658: @ 0x080B9658
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov sb, r0
	adds r6, r1, #0
	mov r8, r2
	adds r4, r3, #0
	ldr r5, [sp, #0x2c]
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x20]
	str r1, [r6, #0x24]
	adds r2, r5, #0
	adds r2, #0x17
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	adds r6, #0x60
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [sp, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, #0
	bne _080B96D8
	movs r0, #0
_080B96D8:
	adds r4, r0, #0
	mov r7, sp
	movs r5, #3
_080B96DE:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldm r7!, {r2}
	adds r2, #0x19
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x20]
	str r1, [r6, #0x24]
	ldrh r0, [r6, #0x20]
	adds r0, r0, r4
	strh r0, [r6, #0x20]
	adds r6, #0x60
	adds r4, #6
	subs r5, #1
	cmp r5, #0
	bge _080B96DE
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b9724
FUN_080b9724: @ 0x080B9724
	push {lr}
	adds r1, r0, #0
	movs r3, #1
	movs r2, #4
_080B972C:
	ldr r0, [r1, #8]
	orrs r0, r3
	str r0, [r1, #8]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080B972C
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b9740
FUN_080b9740: @ 0x080B9740
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	strb r3, [r2]
	lsls r3, r3, #0x18
	movs r2, #5
	cmp r3, #0
	beq _080B975E
	movs r2, #4
_080B975E:
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_082370cc
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_082372cc
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b977c
FUN_080b977c: @ 0x080B977C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	ldr r0, _080B97A0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080B97A4
	ldr r0, [r5, #8]
	orrs r0, r2
	str r0, [r5, #8]
	ldrb r0, [r4]
	b _080B980C
	.align 2, 0
_080B97A0: .4byte 0x030044E0
_080B97A4:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080B97B6
	ldr r0, [r5, #8]
	orrs r0, r2
	str r0, [r5, #8]
	movs r0, #0
	b _080B980C
_080B97B6:
	movs r2, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _080B97CC
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r2, r0, #0x1f
	b _080B97D6
_080B97CC:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080B97D6
	movs r2, #1
_080B97D6:
	cmp r2, #0
	beq _080B9800
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldrb r1, [r4]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r4]
	ldrb r0, [r4]
	movs r2, #5
	subs r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r3, #1
	bl FUN_082370cc
_080B9800:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_082372cc
	movs r0, #1
	rsbs r0, r0, #0
_080B980C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b9814
FUN_080b9814: @ 0x080B9814
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r0, _080B9888 @ =0x0000CB05
	ldr r1, _080B988C @ =0x0000B343
	bl GetFile
	adds r1, r0, #0
	adds r2, r7, #0
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r0, r7, #0
	bl OpenSpriteSetFile
	ldr r1, _080B9890 @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r5, #0
	mov r8, r5
	add r4, sp, #0x10
	adds r5, r7, #0
	adds r5, #0x20
	movs r6, #1
_080B9854:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #0x93
	movs r3, #0x31
	bl FUN_0822f3fc
	ldrh r0, [r4, #2]
	adds r0, #8
	strh r0, [r4, #2]
	adds r5, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080B9854
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B9888: .4byte 0x0000CB05
_080B988C: .4byte 0x0000B343
_080B9890: .4byte 0xFFFF0000

	thumb_func_start FUN_080b9894
FUN_080b9894: @ 0x080B9894
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x20
	movs r5, #1
_080B989C:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B989C
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b98b0
FUN_080b98b0: @ 0x080B98B0
	push {lr}
	cmp r0, #0
	beq _080B98BA
	adds r0, #0xa0
	b _080B98BC
_080B98BA:
	movs r0, #0x93
_080B98BC:
	pop {r1}
	bx r1

	thumb_func_start FUN_080b98c0
FUN_080b98c0: @ 0x080B98C0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	cmp r3, #0
	blt _080B98F0
	ldr r0, [r4, #0x28]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x28]
	adds r0, r3, #0
	bl FUN_080b98b0
	adds r2, r0, #0
	adds r0, r4, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
	b _080B98F8
_080B98F0:
	ldr r0, [r4, #0x28]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x28]
_080B98F8:
	cmp r5, #0
	blt _080B9924
	adds r2, r4, #0
	adds r2, #0x88
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_080b98b0
	adds r2, r0, #0
	adds r0, r4, #0
	adds r0, #0x80
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
	b _080B9930
_080B9924:
	adds r0, r4, #0
	adds r0, #0x88
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_080B9930:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b9938
FUN_080b9938: @ 0x080B9938
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	cmp r2, #0xf
	bgt _080B995C
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r3]
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	b _080B999A
_080B995C:
	cmp r2, #0x1f
	bgt _080B997C
	subs r2, #0x10
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r3]
	asrs r2, r2, #2
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, #0x20
	b _080B999A
_080B997C:
	cmp r2, #0x20
	bne _080B9988
	movs r0, #0x70
	strh r0, [r3]
	movs r0, #0x40
	b _080B999A
_080B9988:
	cmp r2, #0x21
	bne _080B9994
	movs r0, #0x78
	strh r0, [r3]
	movs r0, #0x68
	b _080B999A
_080B9994:
	movs r0, #0x68
	strh r0, [r3]
	movs r0, #0x20
_080B999A:
	strh r0, [r3, #2]
	pop {r0}
	bx r0

	thumb_func_start FUN_080b99a0
FUN_080b99a0: @ 0x080B99A0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, _080B9A00 @ =0x0000CB05
	ldr r1, _080B9A04 @ =0x00005D04
	bl GetFile
	adds r1, r0, #0
	adds r2, r6, #0
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r0, r6, #0
	bl OpenSpriteSetFile
	ldr r1, _080B9A08 @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r7, #0
	adds r4, r6, #0
	adds r4, #0x20
	movs r5, #1
_080B99D8:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x31
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B99D8
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B9A00: .4byte 0x0000CB05
_080B9A04: .4byte 0x00005D04
_080B9A08: .4byte 0xFFFF0000

	thumb_func_start FUN_080b9a0c
FUN_080b9a0c: @ 0x080B9A0C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x20
	movs r5, #1
_080B9A14:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B9A14
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b9a28
FUN_080b9a28: @ 0x080B9A28
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0
	mov sl, r0
	mov sb, r3
	mov r8, r2
	ldr r3, [sp, #0x28]
	str r3, [sp, #4]
	adds r4, r5, #0
	adds r4, #0x20
	movs r7, #0
	str r7, [sp]
	adds r6, r1, #0
_080B9A4C:
	ldr r0, [r6]
	cmp r0, #0
	bne _080B9A5C
	ldr r0, [r4, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #8]
	b _080B9A9A
_080B9A5C:
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	ldr r0, [sp, #4]
	ldrh r2, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl Sprite_SetSprite
	adds r2, r5, #0
	adds r2, #0x40
	ldr r3, [sp]
	adds r2, r2, r3
	mov r7, sl
	lsls r3, r7, #3
	mov r7, r8
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r2, r5, #0
	adds r2, #0xe0
	adds r2, r2, r3
	mov r3, sb
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
_080B9A9A:
	movs r7, #8
	add sb, r7
	movs r0, #8
	add r8, r0
	ldr r3, [sp, #4]
	adds r3, #4
	str r3, [sp, #4]
	adds r4, #0x60
	ldr r7, [sp]
	adds r7, #0x60
	str r7, [sp]
	adds r6, #4
	movs r0, #1
	add sl, r0
	mov r3, sl
	cmp r3, #1
	ble _080B9A4C
	movs r1, #0
	adds r0, r5, #0
	adds r0, #0xf0
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0xf2
	ldr r0, [sp, #0x30]
	strh r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b9adc
FUN_080b9adc: @ 0x080B9ADC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	adds r2, r3, #0
	adds r2, #0xf0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	adds r1, r3, #0
	adds r1, #0xf2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r4, [r1]
	cmp r0, r4
	blo _080B9B10
	ldr r0, [r3, #0x28]
	movs r2, #1
	orrs r0, r2
	str r0, [r3, #0x28]
	subs r1, #0x6a
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #1
	b _080B9B68
_080B9B10:
	ldrh r1, [r1]
	ldrh r0, [r2]
	subs r6, r1, r0
	adds r7, r6, #1
	adds r5, r3, #0
	adds r5, #0xe0
	adds r4, r3, #0
	adds r4, #0x28
	movs r0, #1
	mov r8, r0
_080B9B24:
	ldr r0, [r4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080B9B56
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	muls r0, r6, r0
	movs r2, #0
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	adds r1, r7, #0
	bl Div
	strh r0, [r4, #0x18]
	movs r1, #0x1a
	ldrsh r0, [r4, r1]
	muls r0, r6, r0
	movs r2, #2
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	adds r1, r7, #0
	bl Div
	strh r0, [r4, #0x1a]
_080B9B56:
	adds r5, #8
	adds r4, #0x60
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _080B9B24
	movs r0, #0
_080B9B68:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080b9b74
FUN_080b9b74: @ 0x080B9B74
	ldrb r1, [r0, #1]
	lsls r1, r1, #2
	ldrb r2, [r0, #2]
	adds r1, r1, r2
	adds r0, #0xc
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bx lr

	thumb_func_start FUN_080b9b88
FUN_080b9b88: @ 0x080B9B88
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #1
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9BC4
	movs r3, #0
	adds r4, r5, #0
	adds r4, #0xc
	movs r0, #0x2c
	adds r0, r0, r5
	mov r8, r0
	adds r7, r4, #0
	movs r6, #0xff
_080B9BAA:
	adds r1, r3, r7
	movs r2, #3
_080B9BAE:
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9BAE
	adds r3, #1
	cmp r3, #3
	ble _080B9BAA
	b _080B9BEE
_080B9BC4:
	movs r3, #0
	adds r4, r5, #0
	adds r4, #0xc
	movs r1, #0x2c
	adds r1, r1, r5
	mov r8, r1
	adds r6, r4, #0
_080B9BD2:
	lsls r0, r3, #2
	movs r2, #3
	adds r1, r0, #3
	adds r0, r3, r6
	adds r0, #0xc
_080B9BDC:
	strb r1, [r0]
	subs r1, #1
	subs r0, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9BDC
	adds r3, #1
	cmp r3, #3
	ble _080B9BD2
_080B9BEE:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9C1E
	movs r3, #0
	movs r6, #0xff
	adds r7, r4, #0
	adds r7, #0x10
_080B9C02:
	adds r4, r3, #1
	adds r1, r3, r7
	movs r2, #3
_080B9C08:
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9C08
	adds r3, r4, #0
	cmp r3, #3
	ble _080B9C02
	b _080B9CDC
_080B9C1E:
	ldrb r1, [r5]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B9C9E
	adds r0, r5, #0
	movs r1, #0x20
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9C54
	movs r3, #0
	adds r6, r4, #0
	adds r6, #0x10
_080B9C3A:
	adds r4, r3, #1
	adds r1, r3, r6
	movs r2, #3
_080B9C40:
	ldrb r0, [r5, #6]
	strb r0, [r1]
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9C40
	adds r3, r4, #0
	cmp r3, #3
	ble _080B9C3A
	b _080B9CDC
_080B9C54:
	movs r3, #0
	adds r6, r5, #0
	adds r6, #0xf
	movs r0, #0xe
	adds r0, r0, r5
	mov ip, r0
	adds r7, r4, #0
	adds r7, #0x10
_080B9C64:
	adds r4, r3, #1
	lsls r0, r3, #2
	movs r2, #3
	adds r1, r0, #0
	adds r1, #0x13
	adds r0, r3, r7
	adds r0, #0xc
_080B9C72:
	strb r1, [r0]
	subs r1, #1
	subs r0, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9C72
	adds r3, r4, #0
	cmp r3, #2
	ble _080B9C64
	mov r3, ip
	adds r3, #0x10
	adds r1, r6, #0
	adds r1, #0x10
	movs r2, #3
_080B9C8E:
	ldrb r0, [r3]
	strb r0, [r1]
	adds r3, #4
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9C8E
	b _080B9CDC
_080B9C9E:
	movs r3, #0
	adds r6, r5, #0
	adds r6, #0xf
	adds r7, r4, #0
	adds r7, #0x10
_080B9CA8:
	adds r4, r3, #1
	lsls r0, r3, #2
	movs r2, #3
	adds r1, r0, #0
	adds r1, #0x13
	adds r0, r3, r7
	adds r0, #0xc
_080B9CB6:
	strb r1, [r0]
	subs r1, #1
	subs r0, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9CB6
	adds r3, r4, #0
	cmp r3, #2
	ble _080B9CA8
	movs r2, #3
	movs r1, #0x1f
	adds r0, r6, #0
	adds r0, #0x1c
_080B9CD0:
	strb r1, [r0]
	subs r1, #1
	subs r0, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9CD0
_080B9CDC:
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9D24
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9D0A
	movs r3, #0
	mov r2, r8
	movs r4, #0xff
_080B9CFA:
	adds r1, r2, r3
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	adds r3, #1
	cmp r3, #3
	ble _080B9CFA
	b _080B9D8A
_080B9D0A:
	movs r3, #0
	adds r4, r5, #0
	adds r4, #0x2f
	mov r2, r8
	movs r5, #0xff
_080B9D14:
	adds r1, r2, r3
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r3, #1
	cmp r3, #2
	ble _080B9D14
	b _080B9D4E
_080B9D24:
	ldrb r0, [r5]
	cmp r0, #1
	bne _080B9D54
	adds r4, r5, #0
	adds r4, #0x2f
	mov r1, r8
	movs r2, #0x22
	adds r0, r1, #2
_080B9D34:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _080B9D34
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9D4E
	movs r0, #0x22
	strb r0, [r4]
	b _080B9D8A
_080B9D4E:
	movs r0, #0x21
	strb r0, [r4]
	b _080B9D8A
_080B9D54:
	movs r0, #0x22
	mov r1, r8
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	adds r4, r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9D82
	adds r1, r5, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	orrs r0, r4
	b _080B9D88
_080B9D82:
	adds r1, r5, #0
	adds r1, #0x2f
	movs r0, #0x21
_080B9D88:
	strb r0, [r1]
_080B9D8A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b9d94
FUN_080b9d94: @ 0x080B9D94
	push {lr}
	strb r1, [r0, #7]
	bl FUN_080b9b88
	pop {r0}
	bx r0

	thumb_func_start FUN_080b9da0
FUN_080b9da0: @ 0x080B9DA0
	ldrb r0, [r0, #7]
	ands r0, r1
	bx lr
	.align 2, 0

	thumb_func_start FUN_080b9da8
FUN_080b9da8: @ 0x080B9DA8
	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _080B9DC4 @ =0x030044E0
	ldrh r0, [r4, #2]
	movs r1, #0xf0
	adds r2, r1, #0
	ands r2, r0
	cmp r2, #0
	beq _080B9DC8
	movs r0, #0
	strb r0, [r3, #8]
	ldrh r0, [r4, #2]
	b _080B9DE8
	.align 2, 0
_080B9DC4: .4byte 0x030044E0
_080B9DC8:
	ldrh r0, [r4]
	ands r1, r0
	cmp r1, #0
	beq _080B9DE4
	ldrb r0, [r3, #8]
	adds r0, #1
	strb r0, [r3, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _080B9DE6
	strb r2, [r3, #8]
	ldrh r0, [r4]
	b _080B9DE8
_080B9DE4:
	strb r1, [r3, #8]
_080B9DE6:
	movs r0, #0
_080B9DE8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080b9df0
FUN_080b9df0: @ 0x080B9DF0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #2]
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	adds r1, r2, r1
	adds r0, #0xc
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r3, r2, #3
	movs r0, #3
	ands r3, r0
	cmp r3, r2
	beq _080B9E48
_080B9E0E:
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	adds r1, r3, r1
	adds r0, r4, #0
	adds r0, #0xc
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080B9E3C
	cmp r0, r5
	beq _080B9E3C
	strb r3, [r4, #2]
	adds r0, r4, #0
	bl FUN_080b9b74
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _080B9E4A
_080B9E3C:
	adds r3, #3
	movs r0, #3
	ands r3, r0
	ldrb r0, [r4, #2]
	cmp r3, r0
	bne _080B9E0E
_080B9E48:
	movs r0, #0
_080B9E4A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b9e50
FUN_080b9e50: @ 0x080B9E50
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #2]
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	adds r1, r2, r1
	adds r0, #0xc
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r3, r2, #1
	movs r0, #3
	ands r3, r0
	cmp r3, r2
	beq _080B9EA8
_080B9E6E:
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	adds r1, r3, r1
	adds r0, r4, #0
	adds r0, #0xc
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080B9E9C
	cmp r0, r5
	beq _080B9E9C
	strb r3, [r4, #2]
	adds r0, r4, #0
	bl FUN_080b9b74
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _080B9EAA
_080B9E9C:
	adds r3, #1
	movs r0, #3
	ands r3, r0
	ldrb r0, [r4, #2]
	cmp r3, r0
	bne _080B9E6E
_080B9EA8:
	movs r0, #0
_080B9EAA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b9eb0
FUN_080b9eb0: @ 0x080B9EB0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r3, [r4, #1]
	lsls r1, r3, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xc
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	subs r2, r3, #1
	cmp r3, #0
	bne _080B9F04
_080B9ECC:
	movs r2, #8
	b _080B9F04
_080B9ED0:
	lsls r1, r2, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xc
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080B9EFE
	cmp r0, r5
	beq _080B9EFE
	strb r2, [r4, #1]
	adds r0, r4, #0
	bl FUN_080b9b74
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _080B9F0A
_080B9EFE:
	cmp r2, #0
	beq _080B9ECC
	subs r2, #1
_080B9F04:
	cmp r2, r3
	bne _080B9ED0
	movs r0, #0
_080B9F0A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b9f10
FUN_080b9f10: @ 0x080B9F10
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r3, [r4, #1]
	lsls r1, r3, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xc
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r2, r3, #1
	cmp r3, #8
	bne _080B9F64
_080B9F2C:
	movs r2, #0
	b _080B9F64
_080B9F30:
	lsls r1, r2, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xc
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080B9F5E
	cmp r0, r5
	beq _080B9F5E
	strb r2, [r4, #1]
	adds r0, r4, #0
	bl FUN_080b9b74
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _080B9F6A
_080B9F5E:
	cmp r2, #8
	beq _080B9F2C
	adds r2, #1
_080B9F64:
	cmp r2, r3
	bne _080B9F30
	movs r0, #0
_080B9F6A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b9f70
FUN_080b9f70: @ 0x080B9F70
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080b9da8
	adds r1, r0, #0
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080B9F8A
	adds r0, r4, #0
	bl FUN_080b9df0
	b _080B9FBC
_080B9F8A:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080B9F9A
	adds r0, r4, #0
	bl FUN_080b9e50
	b _080B9FBC
_080B9F9A:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080B9FAA
	adds r0, r4, #0
	bl FUN_080b9eb0
	b _080B9FBC
_080B9FAA:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080B9FB6
	movs r0, #0
	b _080B9FBC
_080B9FB6:
	adds r0, r4, #0
	bl FUN_080b9f10
_080B9FBC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080b9fc4
FUN_080b9fc4: @ 0x080B9FC4
	push {lr}
	adds r1, #0x20
	ldrb r2, [r0, #3]
	adds r0, r1, #0
	adds r1, r2, #0
	bl FUN_080b9938
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b9fd8
FUN_080b9fd8: @ 0x080B9FD8
	ldrb r1, [r0, #1]
	strb r1, [r0, #4]
	ldrb r1, [r0, #2]
	strb r1, [r0, #5]
	ldrb r1, [r0, #3]
	strb r1, [r0, #6]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080b9fe8
FUN_080b9fe8: @ 0x080B9FE8
	ldrb r1, [r0, #4]
	strb r1, [r0, #1]
	ldrb r1, [r0, #5]
	strb r1, [r0, #2]
	ldrb r1, [r0, #6]
	strb r1, [r0, #3]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080b9ff8
FUN_080b9ff8: @ 0x080B9FF8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	adds r0, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r1, [sp, #0x14]
	movs r2, #0
	mov r8, r2
	strb r0, [r4]
	adds r0, r4, #0
	bl FUN_080b9d94
	strb r5, [r4, #1]
	strb r6, [r4, #2]
	adds r0, r4, #0
	bl FUN_080b9b74
	strb r0, [r4, #3]
	mov r0, r8
	strb r0, [r4, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ba030
FUN_080ba030: @ 0x080BA030
	ldr r3, _080BA040 @ =0x00001538
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080BA044 @ =0x000012F0
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080BA040: .4byte 0x00001538
_080BA044: .4byte 0x000012F0

	thumb_func_start FUN_080ba048
FUN_080ba048: @ 0x080BA048
	ldr r2, _080BA050 @ =0x000012EE
	adds r0, r0, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
_080BA050: .4byte 0x000012EE

	thumb_func_start FUN_080ba054
FUN_080ba054: @ 0x080BA054
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _080BA074 @ =0x0000153C
	adds r0, r4, r3
	str r1, [r0]
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080ba048
	ldr r0, _080BA078 @ =0x000012F0
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BA074: .4byte 0x0000153C
_080BA078: .4byte 0x000012F0

	thumb_func_start FUN_080ba07c
FUN_080ba07c: @ 0x080BA07C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_08049e5c
	movs r0, #0xce
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x97
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r5, #0
	bl FUN_08047a28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ba0c0
FUN_080ba0c0: @ 0x080BA0C0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0x64
	bl Div
	str r0, [r5]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [r5, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [r5, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ba0f0
FUN_080ba0f0: @ 0x080BA0F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	mov sl, r0
	adds r7, r1, #0
	ldr r0, _080BA114 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x5c
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _080BA118
	movs r0, #0
	b _080BA126
	.align 2, 0
_080BA114: .4byte 0x030046A0
_080BA118:
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl GetInventoryArmor
	lsls r0, r0, #3
	ldr r1, _080BA138 @ =0x08DAA7B0
	adds r0, r0, r1
_080BA126:
	bl FUN_0807a70c
	adds r4, r0, #0
	cmp r7, #0
	bge _080BA13C
	adds r0, r4, #0
	movs r6, #0
	b _080BA154
	.align 2, 0
_080BA138: .4byte 0x08DAA7B0
_080BA13C:
	lsls r0, r7, #3
	ldr r1, _080BA1B4 @ =0x08DAA7B0
	adds r0, r0, r1
	bl FUN_0807a70c
	movs r6, #0
	cmp r0, r4
	beq _080BA154
	movs r6, #2
	cmp r0, r4
	ble _080BA154
	movs r6, #1
_080BA154:
	add r4, sp, #0x24
	adds r1, r4, #0
	bl FUN_080ba0c0
	movs r0, #0x18
	add r0, sl
	mov r8, r0
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r6, r0, #1
	add r1, sp, #0x24
	mov sb, r1
	ldr r4, _080BA1B8 @ =0x00001158
	add r4, sl
	movs r5, #2
_080BA172:
	mov r0, sb
	adds r0, #4
	mov sb, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BA172
	ldr r0, _080BA1BC @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x58
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	bl FUN_08242b28
	mov r0, sp
	bl FUN_0807a6cc
	adds r5, r0, #0
	cmp r7, #0
	bge _080BA1C0
	movs r6, #0
	b _080BA1DA
	.align 2, 0
_080BA1B4: .4byte 0x08DAA7B0
_080BA1B8: .4byte 0x00001158
_080BA1BC: .4byte 0x030046A0
_080BA1C0:
	lsls r1, r7, #3
	ldr r0, _080BA218 @ =0x08DAA7B0
	adds r1, r1, r0
	mov r0, sp
	bl FUN_0807a5d8
	movs r6, #0
	cmp r0, r5
	beq _080BA1DA
	movs r6, #2
	cmp r0, r5
	ble _080BA1DA
	movs r6, #1
_080BA1DA:
	add r1, sp, #0x24
	bl FUN_080ba0c0
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r6, r0, #1
	add r7, sp, #0x24
	ldr r4, _080BA21C @ =0x00001038
	add r4, sl
	movs r5, #2
_080BA1EE:
	ldm r7!, {r2}
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BA1EE
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BA218: .4byte 0x08DAA7B0
_080BA21C: .4byte 0x00001038

	thumb_func_start FUN_080ba220
FUN_080ba220: @ 0x080BA220
	push {lr}
	adds r1, r0, #0
	cmp r1, #4
	bls _080BA238
	cmp r1, #6
	beq _080BA238
	cmp r1, #7
	beq _080BA238
	cmp r1, #9
	beq _080BA238
	cmp r1, #0xa
	bne _080BA274
_080BA238:
	ldr r0, _080BA268 @ =0x08DAA8D8
	lsls r1, r1, #4
	adds r0, #0xc
	adds r1, r1, r0
	ldr r0, _080BA26C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xef
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r0, [r1]
	muls r0, r2, r0
	movs r1, #0x64
	bl Div
	cmp r0, #0
	bgt _080BA25E
	movs r0, #1
_080BA25E:
	ldr r1, _080BA270 @ =0x0000270F
	cmp r0, r1
	ble _080BA27E
	adds r0, r1, #0
	b _080BA27E
	.align 2, 0
_080BA268: .4byte 0x08DAA8D8
_080BA26C: .4byte 0x030046A0
_080BA270: .4byte 0x0000270F
_080BA274:
	ldr r0, _080BA284 @ =0x08DAA8D8
	lsls r1, r1, #4
	adds r0, #0xc
	adds r1, r1, r0
	ldr r0, [r1]
_080BA27E:
	pop {r1}
	bx r1
	.align 2, 0
_080BA284: .4byte 0x08DAA8D8

	thumb_func_start FUN_080ba288
FUN_080ba288: @ 0x080BA288
	push {r4, r5, lr}
	adds r5, r0, #0
	bl item_08092034
	movs r4, #0x32
	cmp r0, #0xcf
	beq _080BA2AE
	adds r1, r0, #0
	subs r1, #0xd0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	subs r4, r4, r0
	cmp r4, #0x32
	ble _080BA2A8
	movs r4, #0x32
_080BA2A8:
	cmp r4, #0x13
	bgt _080BA2AE
	movs r4, #0x14
_080BA2AE:
	adds r0, r5, #0
	bl GetNormalItemID
	bl FUN_080ba220
	muls r0, r4, r0
	movs r1, #0x64
	bl Div
	cmp r0, #0
	bgt _080BA2C6
	movs r0, #1
_080BA2C6:
	ldr r1, _080BA2D4 @ =0x0000270F
	cmp r0, r1
	ble _080BA2CE
	adds r0, r1, #0
_080BA2CE:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080BA2D4: .4byte 0x0000270F

	thumb_func_start FUN_080ba2d8
FUN_080ba2d8: @ 0x080BA2D8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _080BA2FC @ =0x00001409
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BA304
	ldr r2, _080BA300 @ =0x0000140B
	adds r4, r5, r2
	ldrb r0, [r4]
	bl GetNormalItemID
	adds r6, r0, #0
	ldrb r0, [r4]
	bl item_08092034
	adds r3, r0, #0
	b _080BA33A
	.align 2, 0
_080BA2FC: .4byte 0x00001409
_080BA300: .4byte 0x0000140B
_080BA304:
	cmp r0, #7
	bhi _080BA334
	ldr r1, _080BA328 @ =0x0000140B
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r2, _080BA32C @ =0x000012E4
	adds r0, r0, r2
	movs r6, #0
	ldrsb r6, [r0, r6]
	ldr r1, _080BA330 @ =0x08DAA8D8
	lsls r0, r6, #4
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	movs r3, #0xd0
	cmp r0, #0
	bne _080BA33A
	b _080BA338
	.align 2, 0
_080BA328: .4byte 0x0000140B
_080BA32C: .4byte 0x000012E4
_080BA330: .4byte 0x08DAA8D8
_080BA334:
	movs r6, #1
	rsbs r6, r6, #0
_080BA338:
	movs r3, #0xcf
_080BA33A:
	cmp r6, #0
	bge _080BA356
	movs r1, #0xce
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _080BA408
_080BA356:
	movs r0, #0xce
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BA3C0 @ =0x00000CD8
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x38
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _080BA3C4 @ =0x000012E4
	adds r4, r5, r2
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r6, #0
	bl FUN_08047a28
	ldr r0, [r4]
	bl VM_ParseStringRef
	adds r1, r0, #0
	ldr r0, _080BA3C8 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #5
	bne _080BA3DE
	cmp r6, #1
	bne _080BA3CC
	adds r0, r1, #0
	adds r0, #0xea
	b _080BA3D4
	.align 2, 0
_080BA3C0: .4byte 0x00000CD8
_080BA3C4: .4byte 0x000012E4
_080BA3C8: .4byte 0x030046A0
_080BA3CC:
	cmp r6, #0xd
	bne _080BA3DE
	adds r0, r1, #0
	adds r0, #0xa9
_080BA3D4:
	bl Textbox_LookupString
	bl FUN_08049e30
	b _080BA408
_080BA3DE:
	ldr r0, _080BA3F8 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _080BA3F4
	cmp r0, #5
	bne _080BA3FC
_080BA3F4:
	adds r1, #0x4e
	b _080BA3FE
	.align 2, 0
_080BA3F8: .4byte 0x030046A0
_080BA3FC:
	adds r1, #0x9c
_080BA3FE:
	adds r0, r1, r6
	bl Textbox_LookupString
	bl FUN_08049e30
_080BA408:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ba410
FUN_080ba410: @ 0x080BA410
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	movs r7, #0
	adds r0, #0x80
	str r0, [sp]
	movs r1, #0
	str r1, [sp, #8]
_080BA428:
	movs r0, #0
	mov sl, r0
	lsls r1, r7, #2
	mov r8, r1
	movs r0, #0xcc
	lsls r0, r0, #1
	add r0, sb
	ldr r1, [sp, #8]
	adds r6, r1, r0
	mov r1, r8
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, [sp]
	adds r4, r0, r1
_080BA448:
	mov r1, r8
	add r1, sl
	adds r0, r1, #0
	bl GetNormalItemID
	adds r5, r0, #0
	cmp r5, #0
	blt _080BA478
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, r5, #0
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080BA480
_080BA478:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080BA480:
	adds r0, r6, #0
	ldr r1, _080BA524 @ =0x000002DF
	bl FUN_080b95bc
	adds r6, #0x60
	adds r4, #0x60
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	ble _080BA448
	ldr r0, [sp, #8]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #8]
	adds r7, #1
	cmp r7, #3
	ble _080BA428
	movs r7, #0
_080BA4A8:
	movs r0, #0
	mov sl, r0
	lsls r1, r7, #2
	mov r8, r1
	adds r0, r7, #1
	str r0, [sp, #4]
	mov r2, r8
	adds r2, #0x13
	lsls r0, r7, #3
	add r0, r8
	lsls r0, r0, #5
	movs r1, #0xf3
	lsls r1, r1, #3
	add r1, sb
	adds r7, r0, r1
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r1, [sp]
	adds r6, r0, r1
_080BA4D0:
	mov r1, r8
	add r1, sl
	ldr r0, _080BA528 @ =0x000012F4
	add r0, sb
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	cmp r5, #0
	blt _080BA540
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r2, r5, #0
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r7, #0
	mov r1, sb
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _080BA52C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0
	ldrsh r4, [r0, r1]
	adds r0, r5, #0
	bl FUN_080ba220
	cmp r4, r0
	bge _080BA530
	adds r0, r7, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BA548
	.align 2, 0
_080BA524: .4byte 0x000002DF
_080BA528: .4byte 0x000012F4
_080BA52C: .4byte 0x030046A0
_080BA530:
	adds r0, r7, #0
	ldr r1, _080BA53C @ =0x000002DF
	bl FUN_080b95bc
	b _080BA548
	.align 2, 0
_080BA53C: .4byte 0x000002DF
_080BA540:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
_080BA548:
	adds r6, #0x60
	adds r7, #0x60
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	ble _080BA4D0
	ldr r7, [sp, #4]
	cmp r7, #2
	ble _080BA4A8
	movs r0, #0xd4
	lsls r0, r0, #4
	add r0, sb
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ba57c
FUN_080ba57c: @ 0x080BA57C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r1, _080BA5A8 @ =0x00001409
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BA5B0
	ldr r2, _080BA5AC @ =0x0000140B
	adds r6, r5, r2
	ldrb r0, [r6]
	bl GetNormalItemID
	adds r4, r0, #0
	cmp r4, #0
	blt _080BA610
	ldrb r0, [r6]
	bl FUN_080ba288
	adds r6, r0, #0
	movs r7, #1
	b _080BA5E4
	.align 2, 0
_080BA5A8: .4byte 0x00001409
_080BA5AC: .4byte 0x0000140B
_080BA5B0:
	cmp r0, #7
	bhi _080BA5DC
	ldr r1, _080BA5D4 @ =0x0000140B
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r2, _080BA5D8 @ =0x000012E4
	adds r0, r0, r2
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #0
	blt _080BA610
	adds r0, r4, #0
	bl FUN_080ba220
	adds r6, r0, #0
	b _080BA5E2
	.align 2, 0
_080BA5D4: .4byte 0x0000140B
_080BA5D8: .4byte 0x000012E4
_080BA5DC:
	movs r4, #1
	rsbs r4, r4, #0
	movs r6, #0
_080BA5E2:
	movs r7, #0
_080BA5E4:
	cmp r4, #0
	blt _080BA610
	ldr r1, _080BA608 @ =0x0000140B
	adds r0, r5, r1
	ldrb r1, [r0]
	add r0, sp, #4
	bl FUN_080b9938
	adds r0, r5, #0
	adds r0, #0x58
	ldr r2, _080BA60C @ =0x00000E58
	adds r1, r5, r2
	str r7, [sp]
	add r2, sp, #4
	adds r3, r6, #0
	bl FUN_080b9658
	b _080BA618
	.align 2, 0
_080BA608: .4byte 0x0000140B
_080BA60C: .4byte 0x00000E58
_080BA610:
	ldr r1, _080BA620 @ =0x00000E58
	adds r0, r5, r1
	bl FUN_080b9724
_080BA618:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BA620: .4byte 0x00000E58

	thumb_func_start FUN_080ba624
FUN_080ba624: @ 0x080BA624
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	adds r7, r0, #0
	movs r6, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x44]
	add r1, sp, #0x34
	mov r8, r1
	add r0, sp, #0x3c
	mov sb, r0
	add r1, sp, #0x1c
	mov sl, r1
	str r0, [sp, #0x48]
	mov r1, r8
	str r1, [sp, #0x4c]
	ldr r2, [sp, #0x44]
_080BA64E:
	cmp r6, #0
	bne _080BA65C
	ldr r1, _080BA658 @ =0x0000140E
	b _080BA65E
	.align 2, 0
_080BA658: .4byte 0x0000140E
_080BA65C:
	ldr r1, _080BA68C @ =0x0000140B
_080BA65E:
	adds r0, r7, r1
	ldrb r4, [r0]
	adds r1, r4, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r1, r7, #0
	adds r1, #0x80
	adds r1, r1, r0
	ldr r0, [r1]
	movs r5, #1
	orrs r0, r5
	str r0, [r1]
	adds r0, r4, #0
	str r2, [sp, #0x50]
	bl GetNormalItemID
	adds r1, r0, #0
	ldr r2, [sp, #0x50]
	cmp r1, #0
	blt _080BA690
	str r5, [r2]
	b _080BA694
	.align 2, 0
_080BA68C: .4byte 0x0000140B
_080BA690:
	movs r0, #0
	str r0, [r2]
_080BA694:
	adds r0, r1, #0
	adds r0, #0x68
	ldr r1, [sp, #0x4c]
	stm r1!, {r0}
	str r1, [sp, #0x4c]
	ldr r0, _080BA704 @ =0x000002DF
	ldr r1, [sp, #0x48]
	stm r1!, {r0}
	str r1, [sp, #0x48]
	lsls r0, r6, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r4, #0
	str r2, [sp, #0x50]
	bl FUN_080b9938
	ldr r2, [sp, #0x50]
	adds r2, #4
	adds r6, #1
	cmp r6, #1
	ble _080BA64E
	add r2, sp, #0x14
	mov r3, sl
	movs r6, #1
_080BA6C4:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r6, #1
	cmp r6, #0
	bge _080BA6C4
	ldr r1, _080BA708 @ =0x00001314
	adds r0, r7, r1
	mov r1, r8
	str r1, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x44]
	add r2, sp, #0xc
	mov r3, sl
	bl FUN_080b9a28
	ldr r0, _080BA70C @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BA704: .4byte 0x000002DF
_080BA708: .4byte 0x00001314
_080BA70C: .4byte 0x0000038A

	thumb_func_start FUN_080ba710
FUN_080ba710: @ 0x080BA710
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r3, #1
	str r3, [sp, #0x2c]
	ldr r0, _080BA7A8 @ =0x0000140E
	adds r4, r5, r0
	ldrb r0, [r4]
	adds r0, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r5, #0
	adds r2, #0x80
	adds r2, r2, r1
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldrb r0, [r4]
	bl GetNormalItemID
	adds r0, #0x68
	str r0, [sp, #0x34]
	ldr r1, _080BA7AC @ =0x000002DF
	mov r8, r1
	str r1, [sp, #0x3c]
	ldrb r1, [r4]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	ldr r1, _080BA7B0 @ =0x0000140B
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	movs r0, #0x68
	add r6, sp, #0x34
	str r0, [r6, #4]
	add r3, sp, #0x3c
	mov r0, r8
	str r0, [r3, #4]
	add r0, sp, #0xc
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	strh r2, [r4, #8]
	strh r2, [r4, #0xa]
	strh r2, [r4, #0xc]
	ldr r0, _080BA7B4 @ =0x00001314
	adds r5, r5, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080BA7B8 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BA7A8: .4byte 0x0000140E
_080BA7AC: .4byte 0x000002DF
_080BA7B0: .4byte 0x0000140B
_080BA7B4: .4byte 0x00001314
_080BA7B8: .4byte 0x0000038A

	thumb_func_start FUN_080ba7bc
FUN_080ba7bc: @ 0x080BA7BC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r0, #1
	str r0, [sp, #0x2c]
	ldr r0, _080BA844 @ =0x0000140E
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, r5, r0
	ldr r2, _080BA848 @ =0x000012E4
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #0x68
	str r0, [sp, #0x34]
	ldr r0, _080BA84C @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r1]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	ldr r1, _080BA850 @ =0x0000140B
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	movs r0, #0x68
	add r6, sp, #0x34
	str r0, [r6, #4]
	add r3, sp, #0x3c
	mov r0, r8
	str r0, [r3, #4]
	add r0, sp, #0xc
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	strh r2, [r4, #8]
	strh r2, [r4, #0xa]
	strh r2, [r4, #0xc]
	ldr r2, _080BA854 @ =0x00001314
	adds r5, r5, r2
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080BA858 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BA844: .4byte 0x0000140E
_080BA848: .4byte 0x000012E4
_080BA84C: .4byte 0x000002DF
_080BA850: .4byte 0x0000140B
_080BA854: .4byte 0x00001314
_080BA858: .4byte 0x0000038A

	thumb_func_start FUN_080ba85c
FUN_080ba85c: @ 0x080BA85C
	push {r4, r5, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _080BA894
	ldr r1, _080BA87C @ =0x00001409
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BA880
	adds r1, #0x2f
	adds r0, r4, r1
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080BA976
	.align 2, 0
_080BA87C: .4byte 0x00001409
_080BA880:
	ldr r1, _080BA890 @ =0x00001438
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080BA976
	.align 2, 0
_080BA890: .4byte 0x00001438
_080BA894:
	movs r2, #0
	ldr r1, _080BA8C4 @ =0x0000140C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BA8E4
	ldr r0, _080BA8C8 @ =0x0000140E
	adds r5, r4, r0
	ldrb r0, [r5]
	bl GetNormalItemID
	cmp r0, #0
	blt _080BA8D0
	ldr r1, _080BA8CC @ =0x0000140B
	adds r0, r4, r1
	ldrb r0, [r0]
	ldrb r5, [r5]
	cmp r0, r5
	beq _080BA8C0
	movs r2, #1
	cmp r0, #0x22
	bne _080BA912
_080BA8C0:
	movs r2, #5
	b _080BA912
	.align 2, 0
_080BA8C4: .4byte 0x0000140C
_080BA8C8: .4byte 0x0000140E
_080BA8CC: .4byte 0x0000140B
_080BA8D0:
	ldr r1, _080BA8E0 @ =0x0000140B
	adds r0, r4, r1
	ldrb r0, [r0]
	bl GetNormalItemID
	mvns r0, r0
	lsrs r2, r0, #0x1f
	b _080BA912
	.align 2, 0
_080BA8E0: .4byte 0x0000140B
_080BA8E4:
	ldr r0, _080BA8F8 @ =0x0000140B
	adds r3, r4, r0
	adds r0, #3
	adds r1, r4, r0
	ldrb r0, [r3]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BA8FC
	movs r2, #4
	b _080BA912
	.align 2, 0
_080BA8F8: .4byte 0x0000140B
_080BA8FC:
	ldr r1, _080BA920 @ =0x00001409
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BA912
	ldrb r0, [r3]
	bl GetNormalItemID
	asrs r2, r0, #0x1f
	movs r0, #4
	ands r2, r0
_080BA912:
	cmp r2, #4
	beq _080BA92A
	cmp r2, #4
	bgt _080BA924
	cmp r2, #1
	beq _080BA954
	b _080BA968
	.align 2, 0
_080BA920: .4byte 0x00001409
_080BA924:
	cmp r2, #5
	beq _080BA940
	b _080BA968
_080BA92A:
	ldr r1, _080BA93C @ =0x00001438
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #7
	bl FUN_080b98c0
	b _080BA976
	.align 2, 0
_080BA93C: .4byte 0x00001438
_080BA940:
	ldr r1, _080BA950 @ =0x00001438
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #6
	bl FUN_080b98c0
	b _080BA976
	.align 2, 0
_080BA950: .4byte 0x00001438
_080BA954:
	ldr r1, _080BA964 @ =0x00001438
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080BA976
	.align 2, 0
_080BA964: .4byte 0x00001438
_080BA968:
	ldr r1, _080BA97C @ =0x00001438
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080BA976:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BA97C: .4byte 0x00001438

	thumb_func_start FUN_080ba980
FUN_080ba980: @ 0x080BA980
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080BA9B0 @ =0x0000140C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BA9DC
	ldr r2, _080BA9B4 @ =0x0000140E
	adds r5, r4, r2
	ldrb r0, [r5]
	bl GetNormalItemID
	cmp r0, #0
	blt _080BA9C4
	ldr r3, _080BA9B8 @ =0x0000140B
	adds r1, r4, r3
	ldrb r0, [r1]
	ldrb r5, [r5]
	cmp r0, r5
	bne _080BA9BC
	movs r0, #0x22
	strb r0, [r1]
	movs r0, #5
	b _080BAA3A
	.align 2, 0
_080BA9B0: .4byte 0x0000140C
_080BA9B4: .4byte 0x0000140E
_080BA9B8: .4byte 0x0000140B
_080BA9BC:
	cmp r0, #0x22
	bne _080BA9D2
	movs r0, #5
	b _080BAA3A
_080BA9C4:
	ldr r1, _080BA9D8 @ =0x0000140B
	adds r0, r4, r1
	ldrb r0, [r0]
	bl GetNormalItemID
	cmp r0, #0
	blt _080BAA38
_080BA9D2:
	movs r0, #1
	b _080BAA3A
	.align 2, 0
_080BA9D8: .4byte 0x0000140B
_080BA9DC:
	ldr r3, _080BAA0C @ =0x0000140B
	adds r2, r4, r3
	ldr r0, _080BAA10 @ =0x0000140E
	adds r1, r4, r0
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BAA1C
	ldr r1, _080BAA14 @ =0x000012F2
	adds r0, r4, r1
	ldrh r1, [r0]
	strb r1, [r2]
	movs r0, #3
	ands r0, r1
	subs r3, #2
	adds r1, r4, r3
	strb r0, [r1]
	ldrb r0, [r2]
	lsrs r0, r0, #2
	ldr r2, _080BAA18 @ =0x0000140A
	adds r1, r4, r2
	strb r0, [r1]
	movs r0, #4
	b _080BAA3A
	.align 2, 0
_080BAA0C: .4byte 0x0000140B
_080BAA10: .4byte 0x0000140E
_080BAA14: .4byte 0x000012F2
_080BAA18: .4byte 0x0000140A
_080BAA1C:
	ldr r3, _080BAA34 @ =0x00001409
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BAA38
	ldrb r0, [r2]
	bl GetNormalItemID
	cmp r0, #0
	bge _080BAA38
	movs r0, #4
	b _080BAA3A
	.align 2, 0
_080BAA34: .4byte 0x00001409
_080BAA38:
	movs r0, #0
_080BAA3A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080baa40
FUN_080baa40: @ 0x080BAA40
	push {r4, lr}
	movs r4, #0
_080BAA44:
	adds r0, r4, #0
	bl GetNormalItemID
	cmp r0, #0
	bge _080BAA52
	adds r0, r4, #0
	b _080BAA5C
_080BAA52:
	adds r4, #1
	cmp r4, #0xf
	ble _080BAA44
	movs r0, #1
	rsbs r0, r0, #0
_080BAA5C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080baa64
FUN_080baa64: @ 0x080BAA64
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xda
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	subs r1, #3
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_080baa40
	ldr r2, _080BAAD8 @ =0x000012F2
	adds r1, r5, r2
	strh r0, [r1]
	ldr r0, _080BAADC @ =0x00001408
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r2, _080BAAE0 @ =0x00000D98
	adds r1, r5, r2
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #0x14
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FUN_080ba410
	adds r0, r5, #0
	bl FUN_080ba57c
	adds r0, r5, #0
	bl FUN_080ba2d8
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba85c
	ldr r1, _080BAAE4 @ =FUN_080baae8
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080ba054
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BAAD8: .4byte 0x000012F2
_080BAADC: .4byte 0x00001408
_080BAAE0: .4byte 0x00000D98
_080BAAE4: .4byte FUN_080baae8

	thumb_func_start FUN_080baae8
FUN_080baae8: @ 0x080BAAE8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _080BAB54 @ =0x00001408
	adds r6, r5, r0
	ldr r1, _080BAB58 @ =0x00000C78
	adds r2, r5, r1
	ldr r0, _080BAB5C @ =0x00000C18
	adds r3, r5, r0
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080b95d0
	ldr r7, _080BAB60 @ =0x030044E0
	ldrh r1, [r7]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080BAB6C
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba048
	ldr r1, _080BAB64 @ =0x00000D98
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldrh r1, [r7, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BAB34
	b _080BAD26
_080BAB34:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r2, _080BAB68 @ =0x0000151A
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080BAB4E
	b _080BAD26
_080BAB4E:
	movs r0, #0
	strb r0, [r1]
	b _080BAD26
	.align 2, 0
_080BAB54: .4byte 0x00001408
_080BAB58: .4byte 0x00000C78
_080BAB5C: .4byte 0x00000C18
_080BAB60: .4byte 0x030044E0
_080BAB64: .4byte 0x00000D98
_080BAB68: .4byte 0x0000151A
_080BAB6C:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ba048
	ldr r0, _080BABD4 @ =0x00000D98
	adds r4, r5, r0
	movs r1, #0x18
	adds r1, r1, r5
	mov r8, r1
	adds r0, r4, #0
	bl FUN_082372cc
	ldrh r1, [r7, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BAB90
	b _080BAD00
_080BAB90:
	ldr r2, _080BABD8 @ =0x0000140B
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0x21
	bne _080BABF4
	ldr r0, _080BABDC @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BABE0 @ =0x000012E4
	adds r0, r5, r1
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl FUN_080ba07c
	ldr r2, _080BABE4 @ =0x00001278
	adds r0, r5, r2
	ldr r1, _080BABE8 @ =0x000012EF
	adds r2, r5, r1
	mov r1, r8
	movs r3, #1
	bl FUN_080b9740
	ldr r2, _080BABEC @ =0x00001438
	adds r0, r5, r2
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080BABF0 @ =FUN_080baeb0
	b _080BACF2
	.align 2, 0
_080BABD4: .4byte 0x00000D98
_080BABD8: .4byte 0x0000140B
_080BABDC: .4byte 0x00000107
_080BABE0: .4byte 0x000012E4
_080BABE4: .4byte 0x00001278
_080BABE8: .4byte 0x000012EF
_080BABEC: .4byte 0x00001438
_080BABF0: .4byte FUN_080baeb0
_080BABF4:
	ldr r2, _080BAC44 @ =0x00001409
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #3
	bls _080BAC90
	movs r7, #1
	ldrb r0, [r1]
	adds r0, r5, r0
	ldr r1, _080BAC48 @ =0x000012E4
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	blt _080BAC3A
	ldr r0, _080BAC4C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r2, #0
	ldrsh r4, [r0, r2]
	adds r0, r1, #0
	bl FUN_080ba220
	cmp r4, r0
	blt _080BAC3A
	ldr r1, _080BAC50 @ =0x000012F2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bge _080BAC36
	movs r7, #0
_080BAC36:
	cmp r7, #0
	bne _080BAC54
_080BAC3A:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BAD26
	.align 2, 0
_080BAC44: .4byte 0x00001409
_080BAC48: .4byte 0x000012E4
_080BAC4C: .4byte 0x030046A0
_080BAC50: .4byte 0x000012F2
_080BAC54:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_080b9fd8
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BAC8C @ =0x00000E18
	adds r2, r5, r1
	subs r1, #0x60
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r6, #0
	movs r1, #0x3c
	bl FUN_080b9d94
	b _080BACE8
	.align 2, 0
_080BAC8C: .4byte 0x00000E18
_080BAC90:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_080b9fd8
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BACD8 @ =0x00000E18
	adds r2, r5, r1
	subs r1, #0x60
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080BACDC @ =0x0000140E
	adds r0, r5, r2
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r1, r0, #0
	cmp r1, #0
	bge _080BACE0
	adds r0, r6, #0
	movs r1, #0x1e
	bl FUN_080b9d94
	b _080BACE8
	.align 2, 0
_080BACD8: .4byte 0x00000E18
_080BACDC: .4byte 0x0000140E
_080BACE0:
	adds r0, r6, #0
	movs r1, #0xe
	bl FUN_080b9d94
_080BACE8:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ba85c
	ldr r1, _080BACFC @ =FUN_080bad30
_080BACF2:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BAD26
	.align 2, 0
_080BACFC: .4byte FUN_080bad30
_080BAD00:
	adds r0, r6, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080BAD26
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080ba2d8
	adds r0, r5, #0
	bl FUN_080ba57c
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba85c
_080BAD26:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bad30
FUN_080bad30: @ 0x080BAD30
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080BAD68 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BAD42
	b _080BAE3E
_080BAD42:
	adds r0, r5, #0
	bl FUN_080ba980
	adds r4, r0, #0
	ldr r1, _080BAD6C @ =0x00001438
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	cmp r4, #4
	beq _080BAD8C
	cmp r4, #4
	bgt _080BAD70
	cmp r4, #1
	beq _080BAD76
	b _080BAE34
	.align 2, 0
_080BAD68: .4byte 0x030044E0
_080BAD6C: .4byte 0x00001438
_080BAD70:
	cmp r4, #5
	beq _080BADDC
	b _080BAE34
_080BAD76:
	adds r0, r5, #0
	bl FUN_080ba624
	ldr r1, _080BAD88 @ =0x080BAF1D
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BAE52
	.align 2, 0
_080BAD88: .4byte 0x080BAF1D
_080BAD8C:
	ldr r0, _080BADC8 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BADCC @ =0x000012E4
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r1, _080BADD0 @ =0x0000140E
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r1, _080BADCC @ =0x000012E4
	adds r0, r0, r1
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba07c
	ldr r1, _080BADD4 @ =0x00001278
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x77
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080BADD8 @ =FUN_080baf50
	b _080BAE14
	.align 2, 0
_080BADC8: .4byte 0x00000107
_080BADCC: .4byte 0x000012E4
_080BADD0: .4byte 0x0000140E
_080BADD4: .4byte 0x00001278
_080BADD8: .4byte FUN_080baf50
_080BADDC:
	ldr r0, _080BAE20 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BAE24 @ =0x000012E4
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r1, _080BAE28 @ =0x0000140E
	adds r0, r5, r1
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r3, r0, #0
	adds r0, r5, #0
	movs r1, #1
	adds r2, r4, #0
	bl FUN_080ba07c
	ldr r1, _080BAE2C @ =0x00001278
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x77
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080BAE30 @ =FUN_080bb01c
_080BAE14:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BAE82
	.align 2, 0
_080BAE20: .4byte 0x00000107
_080BAE24: .4byte 0x000012E4
_080BAE28: .4byte 0x0000140E
_080BAE2C: .4byte 0x00001278
_080BAE30: .4byte FUN_080bb01c
_080BAE34:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BAE52
_080BAE3E:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BAE58
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080baa64
_080BAE52:
	adds r4, r5, #0
	adds r4, #0x18
	b _080BAE82
_080BAE58:
	ldr r0, _080BAEA4 @ =0x00001408
	adds r6, r5, r0
	adds r0, r6, #0
	bl FUN_080b9f70
	adds r4, r5, #0
	adds r4, #0x18
	cmp r0, #0
	beq _080BAE82
	ldr r0, _080BAEA8 @ =0x00000D98
	adds r1, r5, r0
	adds r0, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080ba2d8
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ba85c
_080BAE82:
	ldr r1, _080BAEA4 @ =0x00001408
	adds r0, r5, r1
	ldr r1, _080BAEAC @ =0x00000C78
	adds r2, r5, r1
	subs r1, #0x60
	adds r3, r5, r1
	movs r1, #0
	bl FUN_080b95d0
	ldr r1, _080BAEA8 @ =0x00000D98
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_082372cc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BAEA4: .4byte 0x00001408
_080BAEA8: .4byte 0x00000D98
_080BAEAC: .4byte 0x00000C78

	thumb_func_start FUN_080baeb0
FUN_080baeb0: @ 0x080BAEB0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BAEF0 @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BAEF4 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BAF04
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortInventory
	ldr r1, _080BAEF8 @ =0x0000140C
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080BAEFC @ =0x0000140D
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080BAF00 @ =0x0000140E
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080baa64
	b _080BAF14
	.align 2, 0
_080BAEF0: .4byte 0x00001278
_080BAEF4: .4byte 0x000012EF
_080BAEF8: .4byte 0x0000140C
_080BAEFC: .4byte 0x0000140D
_080BAF00: .4byte 0x0000140E
_080BAF04:
	cmp r0, #0
	bne _080BAF14
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080baa64
_080BAF14:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BAF1C:
	.byte 0x10, 0xB5, 0x04, 0x1C
	.byte 0x09, 0x49, 0x60, 0x18, 0xFE, 0xF7, 0xDA, 0xFD, 0x00, 0x28, 0x0A, 0xD0, 0x07, 0x4A, 0xA0, 0x18
	.byte 0x00, 0x78, 0x03, 0x3A, 0xA1, 0x18, 0x09, 0x78, 0x87, 0xF1, 0xDA, 0xFA, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0x91, 0xFD, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x14, 0x13, 0x00, 0x00, 0x0E, 0x14, 0x00, 0x00

	thumb_func_start FUN_080baf50
FUN_080baf50: @ 0x080BAF50
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BAF80 @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BAF84 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BAF8C
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080ba7bc
	ldr r1, _080BAF88 @ =0x080BAFA5
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BAF9C
	.align 2, 0
_080BAF80: .4byte 0x00001278
_080BAF84: .4byte 0x000012EF
_080BAF88: .4byte 0x080BAFA5
_080BAF8C:
	cmp r0, #0
	bne _080BAF9C
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080baa64
_080BAF9C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BAFA4:
	.byte 0x70, 0xB5, 0x06, 0x1C, 0x16, 0x49, 0x70, 0x18, 0xFE, 0xF7, 0x96, 0xFD
	.byte 0x00, 0x28, 0x23, 0xD0, 0x14, 0x49, 0x70, 0x18, 0x05, 0x78, 0x03, 0x31, 0x70, 0x18, 0x04, 0x78
	.byte 0x34, 0x19, 0x12, 0x48, 0x24, 0x18, 0x00, 0x20, 0x20, 0x56, 0xFF, 0xF7, 0x29, 0xF9, 0x10, 0x49
	.byte 0x0A, 0x68, 0x91, 0x21, 0x09, 0x01, 0x52, 0x18, 0x11, 0x88, 0x09, 0x1A, 0x11, 0x80, 0x00, 0x21
	.byte 0x61, 0x56, 0x28, 0x1C, 0x87, 0xF1, 0x50, 0xF9, 0x0A, 0x48, 0x31, 0x18, 0x01, 0x20, 0x08, 0x70
	.byte 0x09, 0x48, 0x85, 0xF1, 0x75, 0xFB, 0x30, 0x1C, 0xFF, 0xF7, 0x34, 0xFD, 0x70, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00, 0x14, 0x13, 0x00, 0x00, 0x0B, 0x14, 0x00, 0x00, 0xE4, 0x12, 0x00, 0x00
	.byte 0xA0, 0x46, 0x00, 0x03, 0x1B, 0x15, 0x00, 0x00, 0x11, 0x01, 0x00, 0x00

	thumb_func_start FUN_080bb01c
FUN_080bb01c: @ 0x080BB01C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BB04C @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BB050 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BB058
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080ba710
	ldr r1, _080BB054 @ =0x080BB071
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BB068
	.align 2, 0
_080BB04C: .4byte 0x00001278
_080BB050: .4byte 0x000012EF
_080BB054: .4byte 0x080BB071
_080BB058:
	cmp r0, #0
	bne _080BB068
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080baa64
_080BB068:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BB070:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0x16, 0x49, 0x60, 0x18, 0xFE, 0xF7, 0x30, 0xFD, 0x00, 0x28, 0x23, 0xD0
	.byte 0x14, 0x49, 0x60, 0x18, 0x05, 0x78, 0x28, 0x1C, 0xFF, 0xF7, 0xFE, 0xF8, 0x12, 0x4B, 0x1A, 0x68
	.byte 0x91, 0x21, 0x09, 0x01, 0x52, 0x18, 0x11, 0x88, 0x09, 0x18, 0x11, 0x80, 0x09, 0x04, 0x09, 0x14
	.byte 0x0E, 0x4A, 0x91, 0x42, 0x04, 0xDD, 0x18, 0x68, 0x91, 0x21, 0x09, 0x01, 0x40, 0x18, 0x02, 0x80
	.byte 0x28, 0x1C, 0x87, 0xF1, 0xFF, 0xF8, 0x0A, 0x49, 0x60, 0x18, 0x01, 0x21, 0x01, 0x70, 0x09, 0x49
	.byte 0x20, 0x1C, 0x00, 0x22, 0xFE, 0xF7, 0xC6, 0xFF, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x14, 0x13, 0x00, 0x00, 0x0E, 0x14, 0x00, 0x00, 0xA0, 0x46, 0x00, 0x03, 0x0F, 0x27, 0x00, 0x00
	.byte 0x1C, 0x15, 0x00, 0x00, 0xE9, 0xB0, 0x0B, 0x08

	thumb_func_start FUN_080bb0e8
FUN_080bb0e8: @ 0x080BB0E8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080BB11C @ =0x000012F0
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080BB0FC
	ldr r0, _080BB120 @ =0x00000276
	bl PlaySound_082406e0
_080BB0FC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	bhi _080BB140
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BB128
	ldr r2, _080BB124 @ =0x00000C3A
	adds r1, r5, r2
	b _080BB148
	.align 2, 0
_080BB11C: .4byte 0x000012F0
_080BB120: .4byte 0x00000276
_080BB124: .4byte 0x00000C3A
_080BB128:
	ldrh r1, [r4]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x20
	subs r1, r1, r0
	ldr r2, _080BB13C @ =0x00000C3A
	adds r0, r5, r2
	strh r1, [r0]
	b _080BB15A
	.align 2, 0
_080BB13C: .4byte 0x00000C3A
_080BB140:
	cmp r1, #0xf
	bhi _080BB154
	ldr r0, _080BB150 @ =0x00000C3A
	adds r1, r5, r0
_080BB148:
	movs r0, #0x20
	strh r0, [r1]
	b _080BB15A
	.align 2, 0
_080BB150: .4byte 0x00000C3A
_080BB154:
	adds r0, r5, #0
	bl FUN_080baa64
_080BB15A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bb160
FUN_080bb160: @ 0x080BB160
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, _080BB23C @ =0x000012ED
	adds r0, r6, r1
	movs r5, #0
	strb r5, [r0]
	adds r0, r6, #0
	bl FUN_080baa40
	ldr r2, _080BB240 @ =0x000012F2
	adds r1, r6, r2
	strh r0, [r1]
	ldr r0, _080BB244 @ =0x03003ED0
	ldr r4, [r0, #0x2c]
	ldr r1, _080BB248 @ =0x000012D8
	adds r0, r6, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #2
	bl FUN_0822c398
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r4, #0xe4
	ldr r2, _080BB24C @ =0x0000F050
	adds r0, r2, #0
	strh r0, [r4]
	adds r4, #2
	ldr r1, _080BB250 @ =0x0000F051
	adds r0, r1, #0
	strh r0, [r4]
	adds r4, #2
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r4]
	adds r4, #2
	adds r1, #0xf
	adds r0, r1, #0
	strh r0, [r4]
	adds r4, #2
	adds r2, #0xf
	adds r0, r2, #0
	strh r0, [r4]
	adds r4, #2
	adds r1, #2
	adds r0, r1, #0
	strh r0, [r4]
	adds r4, #2
	subs r2, #0x51
	adds r0, r2, #0
	strh r0, [r4]
	adds r4, #2
	strh r0, [r4]
	adds r4, #2
	strh r0, [r4]
	adds r4, #2
	strh r0, [r4]
	strh r0, [r4, #2]
	ldr r0, _080BB254 @ =0x0000151A
	adds r4, r6, r0
	ldrb r0, [r4]
	bl FUN_080b94cc
	ldrb r0, [r4]
	bl FUN_080b9400
	ldr r1, _080BB258 @ =0x00001408
	adds r4, r6, r1
	movs r0, #0x14
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #4
	movs r3, #0
	bl FUN_080b9ff8
	ldr r2, _080BB25C @ =0x00000D98
	adds r1, r6, r2
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r6, #0
	bl FUN_080ba410
	adds r0, r6, #0
	bl FUN_080ba57c
	adds r0, r6, #0
	bl FUN_080ba2d8
	ldr r0, _080BB260 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x5c
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _080BB264
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r6, #0
	bl FUN_080ba0f0
	b _080BB274
	.align 2, 0
_080BB23C: .4byte 0x000012ED
_080BB240: .4byte 0x000012F2
_080BB244: .4byte 0x03003ED0
_080BB248: .4byte 0x000012D8
_080BB24C: .4byte 0x0000F050
_080BB250: .4byte 0x0000F051
_080BB254: .4byte 0x0000151A
_080BB258: .4byte 0x00001408
_080BB25C: .4byte 0x00000D98
_080BB260: .4byte 0x030046A0
_080BB264:
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl GetInventoryArmor
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_080ba0f0
_080BB274:
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ba85c
	ldr r1, _080BB290 @ =FUN_080baae8
	adds r0, r6, #0
	movs r2, #1
	bl FUN_080ba054
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BB290: .4byte FUN_080baae8

	thumb_func_start FUN_080bb294
FUN_080bb294: @ 0x080BB294
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, _080BB2BC @ =0x00001409
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BB2C4
	adds r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	ldr r1, _080BB2C0 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r7, [r0, r1]
	b _080BB2E8
	.align 2, 0
_080BB2BC: .4byte 0x00001409
_080BB2C0: .4byte 0x030046A0
_080BB2C4:
	cmp r0, #7
	bhi _080BB2E4
	ldr r1, _080BB2DC @ =0x0000140B
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r0, r6, r0
	ldr r1, _080BB2E0 @ =0x000012F4
	adds r0, r0, r1
	movs r7, #0
	ldrsb r7, [r0, r7]
	b _080BB2E8
	.align 2, 0
_080BB2DC: .4byte 0x0000140B
_080BB2E0: .4byte 0x000012F4
_080BB2E4:
	movs r7, #1
	rsbs r7, r7, #0
_080BB2E8:
	cmp r7, #0
	bge _080BB304
	movs r1, #0xce
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _080BB36E
_080BB304:
	movs r0, #0xce
	lsls r0, r0, #4
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BB37C @ =0x00000CD8
	adds r0, r6, r1
	adds r1, r6, #0
	adds r1, #0x38
	movs r2, #0xcf
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _080BB380 @ =0x000012E8
	adds r5, r6, r0
	ldr r0, [r5]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r0, _080BB384 @ =0x08DAA7B0
	lsls r4, r7, #3
	adds r4, r4, r0
	ldrb r1, [r4, #1]
	movs r0, #0
	bl FUN_08049e6c
	ldrb r1, [r4, #2]
	movs r0, #1
	bl FUN_08049e6c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r7, #0
	bl FUN_08047a28
	ldr r0, [r5]
	bl VM_ParseStringRef
	adds r0, #0x25
	adds r0, r0, r7
	bl Textbox_LookupString
	bl FUN_08049e30
_080BB36E:
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_080ba0f0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BB37C: .4byte 0x00000CD8
_080BB380: .4byte 0x000012E8
_080BB384: .4byte 0x08DAA7B0

	thumb_func_start FUN_080bb388
FUN_080bb388: @ 0x080BB388
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov sl, r0
	movs r0, #0
	str r0, [sp]
	mov r1, sl
	adds r1, #0x80
	str r1, [sp, #8]
	movs r2, #0
	str r2, [sp, #0xc]
	str r0, [sp, #0x10]
	movs r1, #0
	str r1, [sp, #0x14]
_080BB3AA:
	movs r2, #0
	mov sb, r2
	movs r0, #0xcc
	lsls r0, r0, #1
	add r0, sl
	ldr r1, [sp, #0x14]
	adds r6, r1, r0
	ldr r2, [sp, #0xc]
	mov r8, r2
	ldr r1, [sp, #0x10]
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #8]
	adds r5, r0, r1
_080BB3CA:
	ldr r7, [sp, #0x10]
	add r7, sb
	ldr r0, _080BB404 @ =0x030046A0
	ldr r0, [r0]
	add r0, r8
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r4, [r0, r1]
	cmp r4, #0
	blt _080BB408
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r2, r4, #0
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080BB410
	.align 2, 0
_080BB404: .4byte 0x030046A0
_080BB408:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
_080BB410:
	ldr r0, _080BB438 @ =0x08DAA7B0
	lsls r1, r4, #3
	adds r1, r1, r0
	movs r2, #6
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _080BB42C
	ldr r0, _080BB43C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r7, r0
	bne _080BB440
_080BB42C:
	adds r0, r6, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BB448
	.align 2, 0
_080BB438: .4byte 0x08DAA7B0
_080BB43C: .4byte 0x030046A0
_080BB440:
	adds r0, r6, #0
	ldr r1, _080BB504 @ =0x000002DF
	bl FUN_080b95bc
_080BB448:
	adds r6, #0x60
	movs r2, #2
	add r8, r2
	adds r5, #0x60
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #3
	ble _080BB3CA
	ldr r2, [sp, #0xc]
	adds r2, #8
	str r2, [sp, #0xc]
	ldr r0, [sp, #0x10]
	adds r0, #4
	str r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r1, r2
	str r1, [sp, #0x14]
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	cmp r0, #3
	ble _080BB3AA
	movs r1, #0
	str r1, [sp]
_080BB47E:
	movs r2, #0
	mov sb, r2
	ldr r0, [sp]
	lsls r0, r0, #2
	mov r8, r0
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp, #4]
	mov r2, r8
	adds r2, #0x13
	ldr r1, [sp]
	lsls r0, r1, #3
	add r0, r8
	lsls r0, r0, #5
	movs r1, #0xf3
	lsls r1, r1, #3
	add r1, sl
	adds r6, r0, r1
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r2, [sp, #8]
	adds r5, r0, r2
_080BB4AC:
	mov r7, r8
	add r7, sb
	ldr r0, _080BB508 @ =0x00001304
	add r0, sl
	adds r0, r0, r7
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #0
	blt _080BB524
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r2, r4, #0
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _080BB50C @ =0x030046A0
	ldr r1, [r0]
	movs r0, #0x91
	lsls r0, r0, #4
	adds r1, r1, r0
	ldr r2, _080BB510 @ =0x08DAA7B0
	lsls r0, r4, #3
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #6
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _080BB514
	adds r0, r6, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BB52C
	.align 2, 0
_080BB504: .4byte 0x000002DF
_080BB508: .4byte 0x00001304
_080BB50C: .4byte 0x030046A0
_080BB510: .4byte 0x08DAA7B0
_080BB514:
	adds r0, r6, #0
	ldr r1, _080BB520 @ =0x000002DF
	bl FUN_080b95bc
	b _080BB52C
	.align 2, 0
_080BB520: .4byte 0x000002DF
_080BB524:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
_080BB52C:
	adds r5, #0x60
	adds r6, #0x60
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #3
	ble _080BB4AC
	movs r5, #3
	ldr r2, [sp, #4]
	str r2, [sp]
	cmp r2, #2
	ble _080BB47E
	ldr r0, _080BB568 @ =0x030046A0
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x5c
	ldrh r4, [r3]
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bge _080BB56C
	movs r0, #0xd4
	lsls r0, r0, #4
	add r0, sl
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080BB5A2
	.align 2, 0
_080BB568: .4byte 0x030046A0
_080BB56C:
	movs r2, #0xd4
	lsls r2, r2, #4
	add r2, sl
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r5, #0
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	ldr r1, _080BB5B4 @ =0x00000D58
	add r1, sl
	strh r0, [r1]
	ldrh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x12
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	ldr r1, _080BB5B8 @ =0x00000D5A
	add r1, sl
	strh r0, [r1]
_080BB5A2:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BB5B4: .4byte 0x00000D58
_080BB5B8: .4byte 0x00000D5A

	thumb_func_start FUN_080bb5bc
FUN_080bb5bc: @ 0x080BB5BC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r1, _080BB600 @ =0x00001409
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BB610
	ldr r2, _080BB604 @ =0x0000140B
	adds r0, r5, r2
	ldrb r0, [r0]
	ldr r1, _080BB608 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r4, [r0, r2]
	ldr r1, _080BB60C @ =0x08DAA7B0
	lsls r0, r4, #3
	adds r0, r0, r1
	movs r2, #6
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	adds r6, r0, #0
	movs r7, #1
	b _080BB644
	.align 2, 0
_080BB600: .4byte 0x00001409
_080BB604: .4byte 0x0000140B
_080BB608: .4byte 0x030046A0
_080BB60C: .4byte 0x08DAA7B0
_080BB610:
	cmp r0, #7
	bhi _080BB63C
	ldr r1, _080BB630 @ =0x0000140B
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r2, _080BB634 @ =0x000012F4
	adds r0, r0, r2
	movs r4, #0
	ldrsb r4, [r0, r4]
	ldr r1, _080BB638 @ =0x08DAA7B0
	lsls r0, r4, #3
	adds r0, r0, r1
	movs r1, #6
	ldrsh r6, [r0, r1]
	b _080BB642
	.align 2, 0
_080BB630: .4byte 0x0000140B
_080BB634: .4byte 0x000012F4
_080BB638: .4byte 0x08DAA7B0
_080BB63C:
	movs r4, #1
	rsbs r4, r4, #0
	movs r6, #0
_080BB642:
	movs r7, #0
_080BB644:
	cmp r4, #0
	blt _080BB674
	cmp r6, #0
	ble _080BB674
	ldr r2, _080BB66C @ =0x0000140B
	adds r0, r5, r2
	ldrb r1, [r0]
	add r0, sp, #4
	bl FUN_080b9938
	adds r0, r5, #0
	adds r0, #0x58
	ldr r2, _080BB670 @ =0x00000E58
	adds r1, r5, r2
	str r7, [sp]
	add r2, sp, #4
	adds r3, r6, #0
	bl FUN_080b9658
	b _080BB67C
	.align 2, 0
_080BB66C: .4byte 0x0000140B
_080BB670: .4byte 0x00000E58
_080BB674:
	ldr r1, _080BB684 @ =0x00000E58
	adds r0, r5, r1
	bl FUN_080b9724
_080BB67C:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BB684: .4byte 0x00000E58

	thumb_func_start FUN_080bb688
FUN_080bb688: @ 0x080BB688
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	adds r6, r0, #0
	movs r5, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x44]
	add r1, sp, #0x34
	mov r8, r1
	add r4, sp, #0x3c
	mov sb, r4
	add r0, sp, #0x1c
	mov sl, r0
	mov r1, sb
	str r1, [sp, #0x48]
	mov r4, r8
	str r4, [sp, #0x4c]
	ldr r7, [sp, #0x44]
_080BB6B4:
	cmp r5, #0
	bne _080BB6C4
	ldr r1, _080BB6C0 @ =0x0000140E
	adds r0, r6, r1
	b _080BB6C8
	.align 2, 0
_080BB6C0: .4byte 0x0000140E
_080BB6C4:
	ldr r4, _080BB714 @ =0x0000140B
	adds r0, r6, r4
_080BB6C8:
	ldrb r2, [r0]
	adds r1, r2, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r1, r6, #0
	adds r1, #0x80
	adds r1, r1, r0
	ldr r0, [r1]
	movs r3, #1
	orrs r0, r3
	str r0, [r1]
	ldr r4, _080BB718 @ =0x030046A0
	ldr r0, [r4]
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bne _080BB6FA
	movs r0, #0xd4
	lsls r0, r0, #4
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
_080BB6FA:
	ldr r1, [r4]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	cmp r1, #0
	blt _080BB71C
	str r3, [r7]
	b _080BB720
	.align 2, 0
_080BB714: .4byte 0x0000140B
_080BB718: .4byte 0x030046A0
_080BB71C:
	movs r0, #0
	str r0, [r7]
_080BB720:
	adds r0, r1, #0
	adds r0, #0x43
	ldr r1, [sp, #0x4c]
	stm r1!, {r0}
	str r1, [sp, #0x4c]
	ldr r0, _080BB78C @ =0x000002DF
	ldr r4, [sp, #0x48]
	stm r4!, {r0}
	str r4, [sp, #0x48]
	lsls r0, r5, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r2, #0
	bl FUN_080b9938
	adds r7, #4
	adds r5, #1
	cmp r5, #1
	ble _080BB6B4
	add r2, sp, #0x14
	mov r3, sl
	movs r5, #1
_080BB74C:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r5, #1
	cmp r5, #0
	bge _080BB74C
	ldr r1, _080BB790 @ =0x00001314
	adds r0, r6, r1
	mov r4, r8
	str r4, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x44]
	add r2, sp, #0xc
	mov r3, sl
	bl FUN_080b9a28
	ldr r0, _080BB794 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BB78C: .4byte 0x000002DF
_080BB790: .4byte 0x00001314
_080BB794: .4byte 0x0000038A

	thumb_func_start FUN_080bb798
FUN_080bb798: @ 0x080BB798
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r4, #1
	str r4, [sp, #0x2c]
	ldr r0, _080BB83C @ =0x0000140E
	adds r3, r5, r0
	ldrb r0, [r3]
	adds r0, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r5, #0
	adds r2, #0x80
	adds r2, r2, r1
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	ldrb r0, [r3]
	ldr r1, _080BB840 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r0, #0x43
	str r0, [sp, #0x34]
	ldr r0, _080BB844 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r3]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	ldr r1, _080BB848 @ =0x0000140B
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	movs r0, #0x43
	add r6, sp, #0x34
	str r0, [r6, #4]
	add r3, sp, #0x3c
	mov r0, r8
	str r0, [r3, #4]
	add r0, sp, #0xc
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	strh r2, [r4, #8]
	strh r2, [r4, #0xa]
	strh r2, [r4, #0xc]
	ldr r0, _080BB84C @ =0x00001314
	adds r5, r5, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080BB850 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BB83C: .4byte 0x0000140E
_080BB840: .4byte 0x030046A0
_080BB844: .4byte 0x000002DF
_080BB848: .4byte 0x0000140B
_080BB84C: .4byte 0x00001314
_080BB850: .4byte 0x0000038A

	thumb_func_start FUN_080bb854
FUN_080bb854: @ 0x080BB854
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r0, #1
	str r0, [sp, #0x2c]
	ldr r0, _080BB8DC @ =0x0000140E
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, r5, r0
	ldr r2, _080BB8E0 @ =0x000012F4
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #0x43
	str r0, [sp, #0x34]
	ldr r0, _080BB8E4 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r1]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	ldr r1, _080BB8E8 @ =0x0000140B
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	movs r0, #0x68
	add r6, sp, #0x34
	str r0, [r6, #4]
	add r3, sp, #0x3c
	mov r0, r8
	str r0, [r3, #4]
	add r0, sp, #0xc
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	strh r2, [r4, #8]
	strh r2, [r4, #0xa]
	strh r2, [r4, #0xc]
	ldr r2, _080BB8EC @ =0x00001314
	adds r5, r5, r2
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080BB8F0 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BB8DC: .4byte 0x0000140E
_080BB8E0: .4byte 0x000012F4
_080BB8E4: .4byte 0x000002DF
_080BB8E8: .4byte 0x0000140B
_080BB8EC: .4byte 0x00001314
_080BB8F0: .4byte 0x0000038A

	thumb_func_start FUN_080bb8f4
FUN_080bb8f4: @ 0x080BB8F4
	push {r4, r5, lr}
	adds r3, r0, #0
	cmp r1, #0
	bne _080BB930
	ldr r1, _080BB914 @ =0x00001409
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BB91C
	ldr r2, _080BB918 @ =0x00001438
	adds r0, r3, r2
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080BBA7E
	.align 2, 0
_080BB914: .4byte 0x00001409
_080BB918: .4byte 0x00001438
_080BB91C:
	ldr r4, _080BB92C @ =0x00001438
	adds r0, r3, r4
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080BBA7E
	.align 2, 0
_080BB92C: .4byte 0x00001438
_080BB930:
	movs r4, #0
	ldr r5, _080BB97C @ =0x0000140C
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BB9D4
	ldr r1, _080BB980 @ =0x0000140E
	adds r0, r3, r1
	ldrb r2, [r0]
	ldr r0, _080BB984 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	blt _080BB9B4
	ldr r5, _080BB988 @ =0x00001409
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BB990
	adds r0, r1, #0
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, r2
	beq _080BBA14
	ldr r2, _080BB98C @ =0x0000140B
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080BBA14
	movs r4, #5
	b _080BBA14
	.align 2, 0
_080BB97C: .4byte 0x0000140C
_080BB980: .4byte 0x0000140E
_080BB984: .4byte 0x030046A0
_080BB988: .4byte 0x00001409
_080BB98C: .4byte 0x0000140B
_080BB990:
	ldr r4, _080BB9AC @ =0x0000140B
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, r2
	bne _080BB9B0
	adds r0, r1, #0
	adds r0, #0x5c
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r4, #5
	cmp r0, r2
	bne _080BBA14
	movs r4, #0
	b _080BBA14
	.align 2, 0
_080BB9AC: .4byte 0x0000140B
_080BB9B0:
	movs r4, #1
	b _080BBA14
_080BB9B4:
	ldr r2, _080BB9D0 @ =0x0000140B
	adds r0, r3, r2
	ldrb r2, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r4, #0xa8
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	mvns r0, r0
	lsrs r4, r0, #0x1f
	b _080BBA14
	.align 2, 0
_080BB9D0: .4byte 0x0000140B
_080BB9D4:
	ldr r0, _080BB9E8 @ =0x0000140B
	adds r2, r3, r0
	ldr r5, _080BB9EC @ =0x0000140E
	adds r1, r3, r5
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BB9F0
	movs r4, #4
	b _080BBA14
	.align 2, 0
_080BB9E8: .4byte 0x0000140B
_080BB9EC: .4byte 0x0000140E
_080BB9F0:
	ldr r1, _080BBA24 @ =0x00001409
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BBA14
	ldrb r2, [r2]
	ldr r0, _080BBA28 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	asrs r4, r0, #0x1f
	movs r0, #4
	ands r4, r0
_080BBA14:
	cmp r4, #4
	beq _080BBA32
	cmp r4, #4
	bgt _080BBA2C
	cmp r4, #1
	beq _080BBA5C
	b _080BBA70
	.align 2, 0
_080BBA24: .4byte 0x00001409
_080BBA28: .4byte 0x030046A0
_080BBA2C:
	cmp r4, #5
	beq _080BBA48
	b _080BBA70
_080BBA32:
	ldr r5, _080BBA44 @ =0x00001438
	adds r0, r3, r5
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #7
	bl FUN_080b98c0
	b _080BBA7E
	.align 2, 0
_080BBA44: .4byte 0x00001438
_080BBA48:
	ldr r1, _080BBA58 @ =0x00001438
	adds r0, r3, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #6
	bl FUN_080b98c0
	b _080BBA7E
	.align 2, 0
_080BBA58: .4byte 0x00001438
_080BBA5C:
	ldr r2, _080BBA6C @ =0x00001438
	adds r0, r3, r2
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080BBA7E
	.align 2, 0
_080BBA6C: .4byte 0x00001438
_080BBA70:
	ldr r4, _080BBA84 @ =0x00001438
	adds r0, r3, r4
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080BBA7E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BBA84: .4byte 0x00001438

	thumb_func_start FUN_080bba88
FUN_080bba88: @ 0x080BBA88
	push {r4, lr}
	adds r2, r0, #0
	ldr r1, _080BBAD8 @ =0x0000140C
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BBB34
	ldr r3, _080BBADC @ =0x0000140E
	adds r0, r2, r3
	ldrb r3, [r0]
	ldr r0, _080BBAE0 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r4, #0xa8
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	blt _080BBB14
	ldr r4, _080BBAE4 @ =0x00001409
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BBAEC
	adds r0, r1, #0
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, r3
	beq _080BBBA4
	ldr r3, _080BBAE8 @ =0x0000140B
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080BBBA4
	movs r0, #5
	b _080BBBA6
	.align 2, 0
_080BBAD8: .4byte 0x0000140C
_080BBADC: .4byte 0x0000140E
_080BBAE0: .4byte 0x030046A0
_080BBAE4: .4byte 0x00001409
_080BBAE8: .4byte 0x0000140B
_080BBAEC:
	ldr r0, _080BBB0C @ =0x0000140B
	adds r4, r2, r0
	ldrb r0, [r4]
	cmp r0, r3
	bne _080BBB2C
	ldr r1, _080BBB10 @ =0x0000140F
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080BBBA4
	movs r0, #0x22
	strb r0, [r4]
	movs r0, #5
	b _080BBBA6
	.align 2, 0
_080BBB0C: .4byte 0x0000140B
_080BBB10: .4byte 0x0000140F
_080BBB14:
	ldr r3, _080BBB30 @ =0x0000140B
	adds r0, r2, r3
	ldrb r2, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r4, #0xa8
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080BBBA4
_080BBB2C:
	movs r0, #1
	b _080BBBA6
	.align 2, 0
_080BBB30: .4byte 0x0000140B
_080BBB34:
	ldr r4, _080BBB64 @ =0x0000140B
	adds r3, r2, r4
	ldr r0, _080BBB68 @ =0x0000140E
	adds r1, r2, r0
	ldrb r0, [r3]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BBB74
	ldr r1, _080BBB6C @ =0x000012F2
	adds r0, r2, r1
	ldrh r1, [r0]
	strb r1, [r3]
	movs r0, #3
	ands r0, r1
	subs r4, #2
	adds r1, r2, r4
	strb r0, [r1]
	ldrb r0, [r3]
	lsrs r0, r0, #2
	ldr r3, _080BBB70 @ =0x0000140A
	adds r1, r2, r3
	strb r0, [r1]
	movs r0, #4
	b _080BBBA6
	.align 2, 0
_080BBB64: .4byte 0x0000140B
_080BBB68: .4byte 0x0000140E
_080BBB6C: .4byte 0x000012F2
_080BBB70: .4byte 0x0000140A
_080BBB74:
	ldr r4, _080BBB9C @ =0x00001409
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BBBA4
	ldrb r2, [r3]
	ldr r0, _080BBBA0 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bge _080BBBA4
	movs r0, #4
	b _080BBBA6
	.align 2, 0
_080BBB9C: .4byte 0x00001409
_080BBBA0: .4byte 0x030046A0
_080BBBA4:
	movs r0, #0
_080BBBA6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080bbbac
FUN_080bbbac: @ 0x080BBBAC
	push {lr}
	movs r2, #0
	ldr r0, _080BBBC8 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r1, r0, r3
_080BBBBA:
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bge _080BBBCC
	adds r0, r2, #0
	b _080BBBD8
	.align 2, 0
_080BBBC8: .4byte 0x030046A0
_080BBBCC:
	adds r1, #2
	adds r2, #1
	cmp r2, #0xf
	ble _080BBBBA
	movs r0, #1
	rsbs r0, r0, #0
_080BBBD8:
	pop {r1}
	bx r1

	thumb_func_start FUN_080bbbdc
FUN_080bbbdc: @ 0x080BBBDC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xda
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	subs r1, #3
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_080bbbac
	ldr r2, _080BBC50 @ =0x000012F2
	adds r1, r5, r2
	strh r0, [r1]
	ldr r0, _080BBC54 @ =0x00001408
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r2, _080BBC58 @ =0x00000D98
	adds r1, r5, r2
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #0x14
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FUN_080bb294
	adds r0, r5, #0
	bl FUN_080bb388
	adds r0, r5, #0
	bl FUN_080bb5bc
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bb8f4
	ldr r1, _080BBC5C @ =FUN_080bbc60
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080ba054
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BBC50: .4byte 0x000012F2
_080BBC54: .4byte 0x00001408
_080BBC58: .4byte 0x00000D98
_080BBC5C: .4byte FUN_080bbc60

	thumb_func_start FUN_080bbc60
FUN_080bbc60: @ 0x080BBC60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _080BBCCC @ =0x00001408
	adds r6, r5, r0
	ldr r1, _080BBCD0 @ =0x00000C78
	adds r2, r5, r1
	ldr r0, _080BBCD4 @ =0x00000C18
	adds r3, r5, r0
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080b95d0
	ldr r7, _080BBCD8 @ =0x030044E0
	ldrh r1, [r7]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080BBCE4
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba048
	ldr r1, _080BBCDC @ =0x00000D98
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldrh r1, [r7, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BBCAC
	b _080BBEE2
_080BBCAC:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r2, _080BBCE0 @ =0x0000151A
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080BBCC6
	b _080BBEE2
_080BBCC6:
	movs r0, #0
	strb r0, [r1]
	b _080BBEE2
	.align 2, 0
_080BBCCC: .4byte 0x00001408
_080BBCD0: .4byte 0x00000C78
_080BBCD4: .4byte 0x00000C18
_080BBCD8: .4byte 0x030044E0
_080BBCDC: .4byte 0x00000D98
_080BBCE0: .4byte 0x0000151A
_080BBCE4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ba048
	ldr r3, _080BBD50 @ =0x00000D98
	adds r4, r5, r3
	movs r0, #0x18
	adds r0, r0, r5
	mov r8, r0
	adds r0, r4, #0
	mov r1, r8
	bl FUN_082372cc
	ldrh r1, [r7, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BBD0A
	b _080BBEBC
_080BBD0A:
	ldr r1, _080BBD54 @ =0x0000140B
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #0x21
	bne _080BBD70
	ldr r0, _080BBD58 @ =0x00000107
	bl PlaySound_082406e0
	ldr r2, _080BBD5C @ =0x000012E4
	adds r0, r5, r2
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl FUN_080ba07c
	ldr r3, _080BBD60 @ =0x00001278
	adds r0, r5, r3
	ldr r1, _080BBD64 @ =0x000012EF
	adds r2, r5, r1
	mov r1, r8
	movs r3, #1
	bl FUN_080b9740
	ldr r2, _080BBD68 @ =0x00001438
	adds r0, r5, r2
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080BBD6C @ =FUN_080bc07c
	b _080BBEAE
	.align 2, 0
_080BBD50: .4byte 0x00000D98
_080BBD54: .4byte 0x0000140B
_080BBD58: .4byte 0x00000107
_080BBD5C: .4byte 0x000012E4
_080BBD60: .4byte 0x00001278
_080BBD64: .4byte 0x000012EF
_080BBD68: .4byte 0x00001438
_080BBD6C: .4byte FUN_080bc07c
_080BBD70:
	ldr r3, _080BBDC4 @ =0x00001409
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #3
	bls _080BBE18
	movs r7, #1
	ldrb r0, [r4]
	adds r0, r5, r0
	ldr r1, _080BBDC8 @ =0x000012F4
	adds r0, r0, r1
	movs r3, #0
	ldrsb r3, [r0, r3]
	cmp r3, #0
	blt _080BBDBA
	ldr r0, _080BBDCC @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r1, r1, r2
	ldr r2, _080BBDD0 @ =0x08DAA7B0
	lsls r0, r3, #3
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r2, #6
	ldrsh r0, [r0, r2]
	cmp r1, r0
	blt _080BBDBA
	ldr r3, _080BBDD4 @ =0x000012F2
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _080BBDB6
	movs r7, #0
_080BBDB6:
	cmp r7, #0
	bne _080BBDD8
_080BBDBA:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BBEE2
	.align 2, 0
_080BBDC4: .4byte 0x00001409
_080BBDC8: .4byte 0x000012F4
_080BBDCC: .4byte 0x030046A0
_080BBDD0: .4byte 0x08DAA7B0
_080BBDD4: .4byte 0x000012F2
_080BBDD8:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_080b9fd8
	movs r3, #0xe0
	lsls r3, r3, #4
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080BBE10 @ =0x00000E18
	adds r2, r5, r0
	ldr r1, _080BBE14 @ =0x00000DB8
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r6, #0
	movs r1, #0x3c
	bl FUN_080b9d94
	b _080BBEA4
	.align 2, 0
_080BBE10: .4byte 0x00000E18
_080BBE14: .4byte 0x00000DB8
_080BBE18:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_080b9fd8
	movs r3, #0xe0
	lsls r3, r3, #4
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080BBE88 @ =0x00000E18
	adds r2, r5, r0
	ldr r1, _080BBE8C @ =0x00000DB8
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldrb r2, [r4]
	ldr r0, _080BBE90 @ =0x030046A0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x5c
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r2, r0
	beq _080BBE7A
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	blt _080BBE7A
	ldr r0, _080BBE94 @ =0x08DAA7B0
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r3, #6
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne _080BBE9C
_080BBE7A:
	ldr r1, _080BBE98 @ =0x00001408
	adds r0, r5, r1
	movs r1, #0x1e
	bl FUN_080b9d94
	b _080BBEA4
	.align 2, 0
_080BBE88: .4byte 0x00000E18
_080BBE8C: .4byte 0x00000DB8
_080BBE90: .4byte 0x030046A0
_080BBE94: .4byte 0x08DAA7B0
_080BBE98: .4byte 0x00001408
_080BBE9C:
	adds r0, r6, #0
	movs r1, #0xe
	bl FUN_080b9d94
_080BBEA4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bb8f4
	ldr r1, _080BBEB8 @ =FUN_080bbeec
_080BBEAE:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BBEE2
	.align 2, 0
_080BBEB8: .4byte FUN_080bbeec
_080BBEBC:
	adds r0, r6, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080BBEE2
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080bb294
	adds r0, r5, #0
	bl FUN_080bb5bc
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bb8f4
_080BBEE2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bbeec
FUN_080bbeec: @ 0x080BBEEC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080BBF24 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BBEFE
	b _080BC00A
_080BBEFE:
	adds r0, r5, #0
	bl FUN_080bba88
	adds r4, r0, #0
	ldr r1, _080BBF28 @ =0x00001438
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	cmp r4, #4
	beq _080BBF48
	cmp r4, #4
	bgt _080BBF2C
	cmp r4, #1
	beq _080BBF32
	b _080BC000
	.align 2, 0
_080BBF24: .4byte 0x030044E0
_080BBF28: .4byte 0x00001438
_080BBF2C:
	cmp r4, #5
	beq _080BBF9C
	b _080BC000
_080BBF32:
	adds r0, r5, #0
	bl FUN_080bb688
	ldr r1, _080BBF44 @ =0x080BC0E9
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BC01E
	.align 2, 0
_080BBF44: .4byte 0x080BC0E9
_080BBF48:
	ldr r0, _080BBF84 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BBF88 @ =0x000012E8
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r1, _080BBF8C @ =0x0000140E
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r1, _080BBF90 @ =0x000012F4
	adds r0, r0, r1
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba07c
	ldr r1, _080BBF94 @ =0x00001278
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x77
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080BBF98 @ =FUN_080bc11c
	b _080BBFDE
	.align 2, 0
_080BBF84: .4byte 0x00000107
_080BBF88: .4byte 0x000012E8
_080BBF8C: .4byte 0x0000140E
_080BBF90: .4byte 0x000012F4
_080BBF94: .4byte 0x00001278
_080BBF98: .4byte FUN_080bc11c
_080BBF9C:
	ldr r0, _080BBFE8 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BBFEC @ =0x000012E8
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r1, _080BBFF0 @ =0x0000140E
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r1, _080BBFF4 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r3, [r0, r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ba07c
	ldr r1, _080BBFF8 @ =0x00001278
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x77
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080BBFFC @ =FUN_080bc1ec
_080BBFDE:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BC04E
	.align 2, 0
_080BBFE8: .4byte 0x00000107
_080BBFEC: .4byte 0x000012E8
_080BBFF0: .4byte 0x0000140E
_080BBFF4: .4byte 0x030046A0
_080BBFF8: .4byte 0x00001278
_080BBFFC: .4byte FUN_080bc1ec
_080BC000:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BC01E
_080BC00A:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BC024
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080bbbdc
_080BC01E:
	adds r4, r5, #0
	adds r4, #0x18
	b _080BC04E
_080BC024:
	ldr r0, _080BC070 @ =0x00001408
	adds r6, r5, r0
	adds r0, r6, #0
	bl FUN_080b9f70
	adds r4, r5, #0
	adds r4, #0x18
	cmp r0, #0
	beq _080BC04E
	ldr r0, _080BC074 @ =0x00000D98
	adds r1, r5, r0
	adds r0, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080bb294
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bb8f4
_080BC04E:
	ldr r1, _080BC070 @ =0x00001408
	adds r0, r5, r1
	ldr r1, _080BC078 @ =0x00000C78
	adds r2, r5, r1
	subs r1, #0x60
	adds r3, r5, r1
	movs r1, #0
	bl FUN_080b95d0
	ldr r1, _080BC074 @ =0x00000D98
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_082372cc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BC070: .4byte 0x00001408
_080BC074: .4byte 0x00000D98
_080BC078: .4byte 0x00000C78

	thumb_func_start FUN_080bc07c
FUN_080bc07c: @ 0x080BC07C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BC0BC @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BC0C0 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BC0D0
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortArmors
	ldr r1, _080BC0C4 @ =0x0000140C
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080BC0C8 @ =0x0000140D
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080BC0CC @ =0x0000140E
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080bbbdc
	b _080BC0E0
	.align 2, 0
_080BC0BC: .4byte 0x00001278
_080BC0C0: .4byte 0x000012EF
_080BC0C4: .4byte 0x0000140C
_080BC0C8: .4byte 0x0000140D
_080BC0CC: .4byte 0x0000140E
_080BC0D0:
	cmp r0, #0
	bne _080BC0E0
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bbbdc
_080BC0E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BC0E8:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x09, 0x49, 0x60, 0x18
	.byte 0xFD, 0xF7, 0xF4, 0xFC, 0x00, 0x28, 0x0A, 0xD0, 0x07, 0x4A, 0xA0, 0x18, 0x00, 0x78, 0x03, 0x3A
	.byte 0xA1, 0x18, 0x09, 0x78, 0x87, 0xF1, 0xBE, 0xF8, 0x20, 0x1C, 0xFF, 0xF7, 0x67, 0xFD, 0x10, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47, 0x14, 0x13, 0x00, 0x00, 0x0E, 0x14, 0x00, 0x00

	thumb_func_start FUN_080bc11c
FUN_080bc11c: @ 0x080BC11C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BC14C @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BC150 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BC158
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080bb854
	ldr r1, _080BC154 @ =0x080BC171
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BC168
	.align 2, 0
_080BC14C: .4byte 0x00001278
_080BC150: .4byte 0x000012EF
_080BC154: .4byte 0x080BC171
_080BC158:
	cmp r0, #0
	bne _080BC168
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bbbdc
_080BC168:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BC170:
	.byte 0x30, 0xB5, 0x05, 0x1C, 0x16, 0x49, 0x68, 0x18, 0xFD, 0xF7, 0xB0, 0xFC, 0x00, 0x28, 0x24, 0xD0
	.byte 0x14, 0x4A, 0xA8, 0x18, 0x00, 0x78, 0x03, 0x32, 0xA9, 0x18, 0x0C, 0x78, 0x2C, 0x19, 0x12, 0x49
	.byte 0x64, 0x18, 0x00, 0x21, 0x61, 0x56, 0x87, 0xF1, 0x47, 0xF8, 0x10, 0x48, 0x02, 0x68, 0x91, 0x20
	.byte 0x00, 0x01, 0x12, 0x18, 0x0E, 0x49, 0x00, 0x20, 0x20, 0x56, 0xC0, 0x00, 0x40, 0x18, 0x11, 0x88
	.byte 0xC0, 0x88, 0x09, 0x1A, 0x11, 0x80, 0x0B, 0x4A, 0xA9, 0x18, 0x01, 0x20, 0x08, 0x70, 0x0A, 0x48
	.byte 0x84, 0xF1, 0x8E, 0xFA, 0x28, 0x1C, 0xFF, 0xF7, 0x09, 0xFD, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.byte 0x14, 0x13, 0x00, 0x00, 0x0B, 0x14, 0x00, 0x00, 0xF4, 0x12, 0x00, 0x00, 0xA0, 0x46, 0x00, 0x03
	.byte 0xB0, 0xA7, 0xDA, 0x08, 0x1B, 0x15, 0x00, 0x00, 0x11, 0x01, 0x00, 0x00

	thumb_func_start FUN_080bc1ec
FUN_080bc1ec: @ 0x080BC1EC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BC21C @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BC220 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BC228
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080bb798
	ldr r1, _080BC224 @ =0x080BC241
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BC238
	.align 2, 0
_080BC21C: .4byte 0x00001278
_080BC220: .4byte 0x000012EF
_080BC224: .4byte 0x080BC241
_080BC228:
	cmp r0, #0
	bne _080BC238
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bbbdc
_080BC238:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BC240:
	.byte 0x70, 0xB5, 0x04, 0x1C, 0x1D, 0x49, 0x60, 0x18, 0xFD, 0xF7, 0x48, 0xFC, 0x00, 0x28, 0x32, 0xD0
	.byte 0x1B, 0x4A, 0xA0, 0x18, 0x06, 0x78, 0x1B, 0x4A, 0x1B, 0x4D, 0x29, 0x68, 0x70, 0x00, 0x40, 0x18
	.byte 0xA8, 0x21, 0x49, 0x00, 0x40, 0x18, 0x00, 0x21, 0x40, 0x5E, 0xC0, 0x00, 0x80, 0x18, 0x06, 0x22
	.byte 0x81, 0x5E, 0x32, 0x20, 0x48, 0x43, 0x64, 0x21, 0x8F, 0xF1, 0xA0, 0xFF, 0x2A, 0x68, 0x91, 0x21
	.byte 0x09, 0x01, 0x52, 0x18, 0x11, 0x88, 0x09, 0x18, 0x11, 0x80, 0x09, 0x04, 0x09, 0x14, 0x0F, 0x4A
	.byte 0x91, 0x42, 0x04, 0xDD, 0x28, 0x68, 0x91, 0x21, 0x09, 0x01, 0x40, 0x18, 0x02, 0x80, 0x30, 0x1C
	.byte 0x86, 0xF1, 0xE2, 0xFF, 0x0A, 0x4A, 0xA0, 0x18, 0x01, 0x21, 0x01, 0x70, 0x09, 0x49, 0x20, 0x1C
	.byte 0x00, 0x22, 0xFD, 0xF7, 0xCF, 0xFE, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x14, 0x13, 0x00, 0x00
	.byte 0x0E, 0x14, 0x00, 0x00, 0xB0, 0xA7, 0xDA, 0x08, 0xA0, 0x46, 0x00, 0x03, 0x0F, 0x27, 0x00, 0x00
	.byte 0x1C, 0x15, 0x00, 0x00, 0xD9, 0xC2, 0x0B, 0x08

	thumb_func_start FUN_080bc2d8
FUN_080bc2d8: @ 0x080BC2D8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080BC30C @ =0x000012F0
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080BC2EC
	ldr r0, _080BC310 @ =0x00000276
	bl PlaySound_082406e0
_080BC2EC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	bhi _080BC330
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BC318
	ldr r2, _080BC314 @ =0x00000C3A
	adds r1, r5, r2
	b _080BC338
	.align 2, 0
_080BC30C: .4byte 0x000012F0
_080BC310: .4byte 0x00000276
_080BC314: .4byte 0x00000C3A
_080BC318:
	ldrh r1, [r4]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x20
	subs r1, r1, r0
	ldr r2, _080BC32C @ =0x00000C3A
	adds r0, r5, r2
	strh r1, [r0]
	b _080BC34A
	.align 2, 0
_080BC32C: .4byte 0x00000C3A
_080BC330:
	cmp r1, #0xf
	bhi _080BC344
	ldr r0, _080BC340 @ =0x00000C3A
	adds r1, r5, r0
_080BC338:
	movs r0, #0x20
	strh r0, [r1]
	b _080BC34A
	.align 2, 0
_080BC340: .4byte 0x00000C3A
_080BC344:
	adds r0, r5, #0
	bl FUN_080bbbdc
_080BC34A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bc350
FUN_080bc350: @ 0x080BC350
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _080BC3E4 @ =0x000012ED
	adds r1, r4, r0
	movs r5, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080bbbac
	ldr r2, _080BC3E8 @ =0x000012F2
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _080BC3EC @ =0x000012D8
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #2
	bl FUN_0822c398
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r2, _080BC3F0 @ =0x0000151A
	adds r5, r4, r2
	ldrb r0, [r5]
	bl FUN_080b94cc
	ldrb r0, [r5]
	bl FUN_080b9400
	ldr r0, _080BC3F4 @ =0x00001408
	adds r5, r4, r0
	movs r0, #0x14
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #4
	movs r3, #0
	bl FUN_080b9ff8
	ldr r2, _080BC3F8 @ =0x00000D98
	adds r1, r4, r2
	adds r0, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080bb388
	adds r0, r4, #0
	bl FUN_080bb5bc
	adds r0, r4, #0
	bl FUN_080bb294
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080bb8f4
	ldr r1, _080BC3FC @ =FUN_080bbc60
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080ba054
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BC3E4: .4byte 0x000012ED
_080BC3E8: .4byte 0x000012F2
_080BC3EC: .4byte 0x000012D8
_080BC3F0: .4byte 0x0000151A
_080BC3F4: .4byte 0x00001408
_080BC3F8: .4byte 0x00000D98
_080BC3FC: .4byte FUN_080bbc60

	thumb_func_start FUN_080bc400
FUN_080bc400: @ 0x080BC400
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080BC450 @ =0x0000C091
	ldr r1, _080BC454 @ =0x00009F57
	bl GetFile
	adds r2, r0, #0
	ldr r0, _080BC458 @ =0x000012D8
	adds r4, r4, r0
	str r2, [r4]
	movs r5, #0
	str r5, [sp, #0xc]
	str r5, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	ldr r1, [r4]
	movs r0, #0
	movs r2, #2
	bl FUN_0822c398
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BC450: .4byte 0x0000C091
_080BC454: .4byte 0x00009F57
_080BC458: .4byte 0x000012D8

	thumb_func_start FUN_080bc45c
FUN_080bc45c: @ 0x080BC45C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080BC484 @ =0x000092B3
	ldr r1, _080BC488 @ =0x0000A41A
	bl GetFile
	ldr r1, _080BC48C @ =0x000012DC
	adds r4, r4, r1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, _080BC490 @ =0x030043F0
	ldr r2, _080BC494 @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BC484: .4byte 0x000092B3
_080BC488: .4byte 0x0000A41A
_080BC48C: .4byte 0x000012DC
_080BC490: .4byte 0x030043F0
_080BC494: .4byte 0x04000018

	thumb_func_start FUN_080bc498
FUN_080bc498: @ 0x080BC498
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r4, _080BC598 @ =0x0000CB05
	ldr r1, _080BC59C @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x38
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080BC5A0 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x18
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	adds r0, r7, #0
	adds r0, #0x18
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080BC5A4 @ =0x0000414C
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x58
	ldm r0!, {r4, r5, r6}
	stm r1!, {r4, r5, r6}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	adds r5, r7, #0
	adds r5, #0x58
	adds r0, r5, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080BC5A8 @ =0xFFFF0000
	movs r6, #0
	str r6, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	ldr r4, _080BC5AC @ =0x000012EC
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #1
	bne _080BC5B4
	ldr r0, _080BC5B0 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r4, #0x31
	mov r8, r4
	cmp r0, #5
	beq _080BC548
	movs r0, #0x30
	mov r8, r0
_080BC548:
	adds r0, r7, #0
	adds r0, #0x78
	str r1, [sp]
	str r1, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x25
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r0, r7, #0
	adds r0, #0xd8
	str r6, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x23
	mov r3, r8
	bl FUN_0822f3fc
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r0, r7, r3
	str r6, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x24
	mov r3, r8
	bl FUN_0822f3fc
	b _080BC600
	.align 2, 0
_080BC598: .4byte 0x0000CB05
_080BC59C: .4byte 0x00005D04
_080BC5A0: .4byte 0x0000B343
_080BC5A4: .4byte 0x0000414C
_080BC5A8: .4byte 0xFFFF0000
_080BC5AC: .4byte 0x000012EC
_080BC5B0: .4byte 0x030046A0
_080BC5B4:
	adds r0, r7, #0
	adds r0, #0x78
	str r1, [sp]
	str r1, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x26
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r0, r7, #0
	adds r0, #0xd8
	str r6, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x23
	movs r3, #0x31
	bl FUN_0822f3fc
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r0, r7, r3
	str r6, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x24
	movs r3, #0x31
	bl FUN_0822f3fc
_080BC600:
	movs r4, #0
	movs r5, #0x38
	adds r5, r5, r7
	mov sb, r5
	adds r6, r7, #0
	adds r6, #0x18
	str r6, [sp, #0x18]
	adds r0, r7, #0
	adds r0, #0x58
	str r0, [sp, #0x1c]
	add r6, sp, #0x10
	mov r8, r4
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r5, r7, r1
_080BC61E:
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r6, #2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r6]
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sb
	movs r2, #0x68
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xf
	ble _080BC61E
	movs r4, #0
	add r6, sp, #0x10
	mov r8, r4
	movs r3, #0xf3
	lsls r3, r3, #3
	adds r5, r7, r3
_080BC664:
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r6, #2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r6]
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0x3c
	mov sl, r1
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sb
	movs r2, #0x68
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xb
	ble _080BC664
	ldr r2, _080BC894 @ =0x00000D38
	adds r0, r7, r2
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	add r6, sp, #0x10
	str r6, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x41
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	movs r0, #0x80
	strh r0, [r6, #2]
	ldr r5, _080BC898 @ =0x00000CD8
	adds r0, r7, r5
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sb
	movs r2, #0xd0
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0x78
	add r0, sp, #0x10
	strh r1, [r0]
	movs r5, #0x68
	strh r5, [r6, #2]
	ldr r3, _080BC89C @ =0x00000C78
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sb
	movs r2, #0xcb
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r5, [r0]
	movs r3, #0x20
	mov r8, r3
	mov r5, r8
	strh r5, [r6, #2]
	ldr r0, _080BC8A0 @ =0x00000C18
	adds r5, r7, r0
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sb
	movs r2, #0xcc
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r5, #0
	bl FUN_080b95bc
	ldr r3, _080BC8A4 @ =0x00000DF8
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r5, sl
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x3c
	movs r3, #0x31
	bl FUN_0822f3fc
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	mov r2, r8
	strh r2, [r6, #2]
	ldr r3, _080BC8A8 @ =0x00000D98
	adds r5, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r6, sl
	str r6, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x39
	movs r3, #0x30
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _080BC8AC @ =0x00000E58
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0x18
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0xb
	add r1, sp, #0x10
	strh r0, [r1]
	adds r6, r1, #0
	ldr r3, _080BC8B0 @ =0x00000EB8
	adds r5, r7, r3
	mov r8, r4
	movs r4, #3
_080BC7AC:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0x19
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #6
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BC7AC
	movs r1, #0x30
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x68
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r1, _080BC8B4 @ =0x00001038
	adds r5, r7, r1
	movs r2, #0
	mov r8, r2
	movs r4, #2
_080BC7EA:
	mov r3, r8
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BC7EA
	movs r1, #0x30
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x70
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r4, _080BC8B8 @ =0x00001158
	adds r5, r7, r4
	movs r0, #0
	mov r8, r0
	movs r4, #2
_080BC828:
	mov r1, r8
	str r1, [sp]
	str r1, [sp, #4]
	movs r2, #0x3c
	mov sb, r2
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BC828
	movs r1, #0
	add r0, sp, #0x10
	strh r1, [r0]
	strh r1, [r0, #2]
	ldr r3, _080BC8BC @ =0x00001278
	adds r0, r7, r3
	str r1, [sp]
	str r1, [sp, #4]
	mov r4, sb
	str r4, [sp, #8]
	add r5, sp, #0x10
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x94
	movs r3, #0x11
	bl FUN_0822f3fc
	ldr r6, _080BC8C0 @ =0x00001314
	adds r0, r7, r6
	bl FUN_080b99a0
	ldr r1, _080BC8C4 @ =0x00001438
	adds r0, r7, r1
	bl FUN_080b9814
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BC894: .4byte 0x00000D38
_080BC898: .4byte 0x00000CD8
_080BC89C: .4byte 0x00000C78
_080BC8A0: .4byte 0x00000C18
_080BC8A4: .4byte 0x00000DF8
_080BC8A8: .4byte 0x00000D98
_080BC8AC: .4byte 0x00000E58
_080BC8B0: .4byte 0x00000EB8
_080BC8B4: .4byte 0x00001038
_080BC8B8: .4byte 0x00001158
_080BC8BC: .4byte 0x00001278
_080BC8C0: .4byte 0x00001314
_080BC8C4: .4byte 0x00001438

	thumb_func_start FUN_080bc8c8
FUN_080bc8c8: @ 0x080BC8C8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BC8E2
	bl FUN_0823d340
	movs r2, #0x97
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
_080BC8E2:
	bl FUN_08049f5c
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	ldr r0, _080BC904 @ =0x0000A41A
	bl FUN_08047dc0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BC904: .4byte 0x0000A41A

	thumb_func_start FUN_080bc908
FUN_080bc908: @ 0x080BC908
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x49
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BC91E
	bl Script_GetValue
	adds r5, r0, #0
	b _080BC920
_080BC91E:
	movs r5, #0
_080BC920:
	movs r0, #0x54
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BC96C
	movs r4, #0
	cmp r4, r5
	bge _080BC942
	ldr r0, _080BC988 @ =0x000012F4
	adds r6, r7, r0
_080BC934:
	bl Script_GetValue
	adds r1, r6, r4
	strb r0, [r1]
	adds r4, #1
	cmp r4, r5
	blt _080BC934
_080BC942:
	cmp r4, #0xb
	bgt _080BC95A
	ldr r0, _080BC988 @ =0x000012F4
	adds r2, r7, r0
	movs r3, #0xff
_080BC94C:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #0xb
	ble _080BC94C
_080BC95A:
	ldr r2, _080BC98C @ =0x000012FC
	adds r1, r7, r2
	movs r4, #3
_080BC960:
	ldrb r0, [r1]
	strb r0, [r1, #4]
	adds r1, #1
	subs r4, #1
	cmp r4, #0
	bge _080BC960
_080BC96C:
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BC980
	bl FUN_0823d340
	ldr r2, _080BC990 @ =0x000012E4
	adds r1, r7, r2
	str r0, [r1]
_080BC980:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BC988: .4byte 0x000012F4
_080BC98C: .4byte 0x000012FC
_080BC990: .4byte 0x000012E4

	thumb_func_start FUN_080bc994
FUN_080bc994: @ 0x080BC994
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BC9AA
	bl Script_GetValue
	adds r5, r0, #0
	b _080BC9AC
_080BC9AA:
	movs r5, #0
_080BC9AC:
	movs r0, #0x52
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BC9F8
	movs r4, #0
	cmp r4, r5
	bge _080BC9CE
	ldr r0, _080BCA14 @ =0x00001304
	adds r6, r7, r0
_080BC9C0:
	bl Script_GetValue
	adds r1, r6, r4
	strb r0, [r1]
	adds r4, #1
	cmp r4, r5
	blt _080BC9C0
_080BC9CE:
	cmp r4, #0xb
	bgt _080BC9E6
	ldr r0, _080BCA14 @ =0x00001304
	adds r2, r7, r0
	movs r3, #0xff
_080BC9D8:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #0xb
	ble _080BC9D8
_080BC9E6:
	ldr r2, _080BCA18 @ =0x0000130C
	adds r1, r7, r2
	movs r4, #3
_080BC9EC:
	ldrb r0, [r1]
	strb r0, [r1, #4]
	adds r1, #1
	subs r4, #1
	cmp r4, #0
	bge _080BC9EC
_080BC9F8:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BCA0C
	bl FUN_0823d340
	ldr r2, _080BCA1C @ =0x000012E8
	adds r1, r7, r2
	str r0, [r1]
_080BCA0C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BCA14: .4byte 0x00001304
_080BCA18: .4byte 0x0000130C
_080BCA1C: .4byte 0x000012E8

	thumb_func_start FUN_080bca20
FUN_080bca20: @ 0x080BCA20
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x65
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080BCA40
	bl Script_GetValue
	ldr r2, _080BCA3C @ =0x00001534
	adds r1, r4, r2
	str r0, [r1]
	b _080BCA46
	.align 2, 0
_080BCA3C: .4byte 0x00001534
_080BCA40:
	ldr r2, _080BCA4C @ =0x00001534
	adds r0, r4, r2
	str r1, [r0]
_080BCA46:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BCA4C: .4byte 0x00001534

	thumb_func_start FUN_080bca50
FUN_080bca50: @ 0x080BCA50
	push {lr}
	adds r2, r0, #0
	ldr r0, _080BCA74 @ =0x000012F0
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BCA6E
	ldr r1, _080BCA78 @ =FUN_080bca7c
	adds r0, r2, #0
	bl FUN_080ba030
_080BCA6E:
	pop {r0}
	bx r0
	.align 2, 0
_080BCA74: .4byte 0x000012F0
_080BCA78: .4byte FUN_080bca7c

	thumb_func_start FUN_080bca7c
FUN_080bca7c: @ 0x080BCA7C
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080BCAD8 @ =0x000012EE
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _080BCA8E
	b _080BCBB8
_080BCA8E:
	subs r1, #2
	adds r0, r4, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _080BCB5C
	ldr r0, _080BCADC @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #5
	beq _080BCB5C
	ldr r1, _080BCAE0 @ =0x0000151D
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1d
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080BCAE4
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	b _080BCAFC
	.align 2, 0
_080BCAD8: .4byte 0x000012EE
_080BCADC: .4byte 0x030046A0
_080BCAE0: .4byte 0x0000151D
_080BCAE4:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
_080BCAFC:
	str r0, [r1]
	ldr r0, _080BCB28 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r5, #0xc0
	lsls r5, r5, #2
	ands r5, r1
	cmp r5, #0
	beq _080BCB38
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080BCB2C @ =0x000012ED
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080BCB30
	adds r0, r4, #0
	bl FUN_080bc350
	b _080BCBD6
	.align 2, 0
_080BCB28: .4byte 0x030044E0
_080BCB2C: .4byte 0x000012ED
_080BCB30:
	adds r0, r4, #0
	bl FUN_080bb160
	b _080BCBD6
_080BCB38:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BCBD6
	ldr r0, _080BCB54 @ =0x00000119
	bl PlaySound_082406e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BCB58 @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	b _080BCB92
	.align 2, 0
_080BCB54: .4byte 0x00000119
_080BCB58: .4byte 0x0000FFFF
_080BCB5C:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080BCBA8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BCBD6
	ldr r0, _080BCBAC @ =0x00000119
	bl PlaySound_082406e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BCBB0 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
_080BCB92:
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080BCBB4 @ =FUN_080bcbf4
	adds r0, r4, #0
	bl FUN_080ba030
	b _080BCBE2
	.align 2, 0
_080BCBA8: .4byte 0x030044E0
_080BCBAC: .4byte 0x00000119
_080BCBB0: .4byte 0x0000FFFF
_080BCBB4: .4byte FUN_080bcbf4
_080BCBB8:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080BCBEC @ =0x0000151D
	adds r0, r4, r1
	strb r3, [r0]
_080BCBD6:
	ldr r1, _080BCBF0 @ =0x0000153C
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080BCBE2:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BCBEC: .4byte 0x0000151D
_080BCBF0: .4byte 0x0000153C

	thumb_func_start FUN_080bcbf4
FUN_080bcbf4: @ 0x080BCBF4
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080BCC4C @ =0x000012F0
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BCC44
	ldr r1, _080BCC50 @ =0x00001534
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080BCC3E
	ldr r1, _080BCC54 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	ldr r1, _080BCC58 @ =0x0000151B
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp, #4]
	add r1, sp, #8
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_080BCC3E:
	adds r0, r4, #0
	bl KillEntity
_080BCC44:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BCC4C: .4byte 0x000012F0
_080BCC50: .4byte 0x00001534
_080BCC54: .4byte 0xFFFF0000
_080BCC58: .4byte 0x0000151B

	thumb_func_start FUN_080bcc5c
FUN_080bcc5c: @ 0x080BCC5C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080BCC84 @ =0x0000151A
	adds r5, r4, r0
	ldrb r0, [r5]
	bl FUN_080b94cc
	ldrb r0, [r5]
	bl FUN_080b9400
	ldr r1, _080BCC88 @ =0x00001538
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080BCC84: .4byte 0x0000151A
_080BCC88: .4byte 0x00001538

	thumb_func_start FUN_080bcc8c
FUN_080bcc8c: @ 0x080BCC8C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x78
	movs r5, #0x30
_080BCC96:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BCC96
	ldr r1, _080BCCBC @ =0x00001314
	adds r0, r6, r1
	bl FUN_080b9a0c
	ldr r1, _080BCCC0 @ =0x00001438
	adds r0, r6, r1
	bl FUN_080b9894
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BCCBC: .4byte 0x00001314
_080BCCC0: .4byte 0x00001438

	thumb_func_start FUN_080bccc4
FUN_080bccc4: @ 0x080BCCC4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _080BCD44 @ =0x000012EC
	adds r4, r5, r0
	movs r6, #0
	strb r1, [r4]
	adds r0, r5, #0
	bl FUN_080bc908
	ldrb r0, [r4]
	cmp r0, #1
	bne _080BCCE4
	adds r0, r5, #0
	bl FUN_080bc994
_080BCCE4:
	adds r0, r5, #0
	bl FUN_080bc400
	adds r0, r5, #0
	bl FUN_080bc45c
	adds r0, r5, #0
	bl FUN_080bc498
	adds r0, r5, #0
	bl FUN_080bc8c8
	adds r0, r5, #0
	bl FUN_080bca20
	ldr r1, _080BCD48 @ =0x0000151B
	adds r0, r5, r1
	strb r6, [r0]
	adds r1, #1
	adds r0, r5, r1
	strb r6, [r0]
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BCD4C @ =0x0000FFFF
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r5, #0
	bl FUN_080bb160
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080BCD50 @ =FUN_080bca50
	adds r0, r5, #0
	bl FUN_080ba030
	movs r0, #0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BCD44: .4byte 0x000012EC
_080BCD48: .4byte 0x0000151B
_080BCD4C: .4byte 0x0000FFFF
_080BCD50: .4byte FUN_080bca50
_080BCD54:
	.byte 0x10, 0xB5, 0xAA, 0x21, 0x49, 0x01, 0x0B, 0x20, 0x73, 0xF1, 0x28, 0xFF
	.byte 0x04, 0x1C, 0x00, 0x2C, 0x12, 0xD0, 0x07, 0x49, 0x07, 0x4A, 0x73, 0xF1, 0x45, 0xFF, 0x20, 0x1C
	.byte 0x00, 0x21, 0xFF, 0xF7, 0xA7, 0xFF, 0x00, 0x28, 0x08, 0xDA, 0x20, 0x1C, 0x73, 0xF1, 0x76, 0xFF
	.byte 0x00, 0x20, 0x04, 0xE0, 0x5D, 0xCC, 0x0B, 0x08, 0x8D, 0xCC, 0x0B, 0x08, 0x20, 0x1C, 0x10, 0xBC
	.byte 0x02, 0xBC, 0x08, 0x47, 0x10, 0xB5, 0xAA, 0x21, 0x49, 0x01, 0x0B, 0x20, 0x73, 0xF1, 0x08, 0xFF
	.byte 0x04, 0x1C, 0x00, 0x2C, 0x12, 0xD0, 0x07, 0x49, 0x07, 0x4A, 0x73, 0xF1, 0x25, 0xFF, 0x20, 0x1C
	.byte 0x01, 0x21, 0xFF, 0xF7, 0x87, 0xFF, 0x00, 0x28, 0x08, 0xDA, 0x20, 0x1C, 0x73, 0xF1, 0x56, 0xFF
	.byte 0x00, 0x20, 0x04, 0xE0, 0x5D, 0xCC, 0x0B, 0x08, 0x8D, 0xCC, 0x0B, 0x08, 0x20, 0x1C, 0x10, 0xBC
	.byte 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080bcdd4
FUN_080bcdd4: @ 0x080BCDD4
	ldr r3, _080BCDE4 @ =0x00001898
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080BCDE8 @ =0x0000168E
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080BCDE4: .4byte 0x00001898
_080BCDE8: .4byte 0x0000168E

	thumb_func_start FUN_080bcdec
FUN_080bcdec: @ 0x080BCDEC
	ldr r2, _080BCDF4 @ =0x00001655
	adds r0, r0, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
_080BCDF4: .4byte 0x00001655

	thumb_func_start FUN_080bcdf8
FUN_080bcdf8: @ 0x080BCDF8
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _080BCE18 @ =0x0000189C
	adds r0, r4, r3
	str r1, [r0]
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080bcdec
	ldr r0, _080BCE1C @ =0x0000168E
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BCE18: .4byte 0x0000189C
_080BCE1C: .4byte 0x0000168E

	thumb_func_start FUN_080bce20
FUN_080bce20: @ 0x080BCE20
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_08049e5c
	movs r0, #0xce
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xb2
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r5, #0
	bl FUN_08047a28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bce64
FUN_080bce64: @ 0x080BCE64
	push {r4, r5, lr}
	bl GetWeapon
	adds r5, r0, #0
	ldr r2, _080BCE84 @ =0x08DA9E68
	ldrb r1, [r5]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r2, [r0, #0xa]
	cmp r2, #0
	bne _080BCE88
	movs r0, #0
	b _080BCECE
	.align 2, 0
_080BCE84: .4byte 0x08DA9E68
_080BCE88:
	movs r3, #0
	adds r1, r5, #0
	movs r4, #2
_080BCE8E:
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	beq _080BCE96
	adds r3, #1
_080BCE96:
	adds r1, #4
	subs r4, #1
	cmp r4, #0
	bge _080BCE8E
	cmp r3, #0
	bne _080BCEB2
	movs r0, #1
	ldrsb r0, [r5, r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	adds r1, #0x32
	adds r0, r2, #0
	muls r0, r1, r0
	b _080BCEBC
_080BCEB2:
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, #0x64
	muls r0, r2, r0
_080BCEBC:
	movs r1, #0x64
	bl Div
	adds r2, r0, #0
	cmp r2, #0
	ble _080BCECC
	adds r0, r2, #0
	b _080BCECE
_080BCECC:
	movs r0, #1
_080BCECE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080bced4
FUN_080bced4: @ 0x080BCED4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0x64
	bl Div
	str r0, [r5]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [r5, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [r5, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bcf04
FUN_080bcf04: @ 0x080BCF04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	mov sl, r0
	str r1, [sp, #0x30]
	ldrb r0, [r1, #1]
	cmp r0, #1
	beq _080BCF34
	cmp r0, #1
	bgt _080BCF24
	cmp r0, #0
	beq _080BCF2E
	b _080BCF44
_080BCF24:
	cmp r0, #2
	beq _080BCF38
	cmp r0, #4
	beq _080BCF3E
	b _080BCF44
_080BCF2E:
	movs r0, #0
	str r0, [sp, #0x34]
	b _080BCF4A
_080BCF34:
	movs r1, #1
	b _080BCF48
_080BCF38:
	movs r2, #2
	str r2, [sp, #0x34]
	b _080BCF4A
_080BCF3E:
	movs r0, #3
	str r0, [sp, #0x34]
	b _080BCF4A
_080BCF44:
	movs r1, #1
	rsbs r1, r1, #0
_080BCF48:
	str r1, [sp, #0x34]
_080BCF4A:
	movs r6, #0
	mov r2, sp
	adds r2, #0xc
	str r2, [sp, #0x3c]
	mov r0, sl
	adds r0, #0x18
	str r0, [sp, #0x38]
_080BCF58:
	adds r0, r6, #0
	ldr r1, [sp, #0x3c]
	bl FUN_08242b28
	ldr r0, [sp, #0x3c]
	bl FUN_0807a6cc
	adds r4, r0, #0
	ldr r1, [sp, #0x34]
	cmp r6, r1
	beq _080BCFAC
	mov r1, sp
	bl FUN_080bced4
	movs r7, #0
	lsls r1, r6, #1
	adds r2, r6, #1
	mov sb, r2
	movs r0, #0
	mov r8, r0
	mov r5, sp
	adds r0, r6, #0
	adds r0, #0x28
	adds r4, r1, r0
_080BCF88:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #5
	adds r0, #0x78
	add r0, sl
	ldm r5!, {r2}
	add r2, r8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, [sp, #0x38]
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #1
	adds r7, #1
	cmp r7, #2
	ble _080BCF88
	b _080BD006
_080BCFAC:
	ldr r0, [sp, #0x30]
	bl FUN_0807a6cc
	movs r5, #0
	cmp r0, r4
	beq _080BCFC0
	movs r5, #2
	cmp r0, r4
	ble _080BCFC0
	movs r5, #1
_080BCFC0:
	mov r1, sp
	bl FUN_080bced4
	movs r7, #0
	lsls r1, r6, #1
	lsls r0, r5, #2
	adds r2, r6, #1
	mov sb, r2
	adds r0, r0, r5
	lsls r5, r0, #1
	mov r8, sp
	adds r0, r6, #0
	adds r0, #0x28
	adds r4, r1, r0
_080BCFDC:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #5
	adds r0, #0x78
	add r0, sl
	mov r1, r8
	adds r1, #4
	mov r8, r1
	subs r1, #4
	ldm r1!, {r2}
	adds r2, r2, r5
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, [sp, #0x38]
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #1
	adds r7, #1
	cmp r7, #2
	ble _080BCFDC
_080BD006:
	mov r6, sb
	cmp r6, #3
	ble _080BCF58
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bd01c
FUN_080bd01c: @ 0x080BD01C
	push {r4, r5, lr}
	adds r5, r1, #0
	movs r1, #0
	ldr r2, _080BD054 @ =0x00001648
	adds r0, r0, r2
	ldr r3, [r0]
	ldrb r2, [r3]
	cmp r2, #0
	beq _080BD044
	adds r4, r5, #0
	adds r4, #0xc
_080BD032:
	adds r0, r4, r1
	strb r2, [r0]
	adds r3, #1
	adds r1, #1
	ldrb r2, [r3]
	cmp r2, #0
	beq _080BD044
	cmp r1, #0xa
	ble _080BD032
_080BD044:
	adds r0, r5, #0
	adds r0, #0xc
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BD054: .4byte 0x00001648

	thumb_func_start FUN_080bd058
FUN_080bd058: @ 0x080BD058
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	ldr r1, _080BD078 @ =0x00001785
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD080
	ldr r2, _080BD07C @ =0x00001787
	adds r0, r6, r2
	ldrb r0, [r0]
	mov r1, sp
	bl FUN_08242b14
	b _080BD0E8
	.align 2, 0
_080BD078: .4byte 0x00001785
_080BD07C: .4byte 0x00001787
_080BD080:
	cmp r0, #7
	bhi _080BD0D8
	ldr r2, _080BD0C8 @ =0x08DA9E68
	ldr r3, _080BD0CC @ =0x00001787
	adds r1, r6, r3
	ldr r4, _080BD0D0 @ =0x00001654
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #4
	subs r0, #0x10
	ldrb r1, [r1]
	adds r0, r0, r1
	ldr r3, _080BD0D4 @ =0x0000165C
	adds r1, r6, r3
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, sp
	adds r1, r1, r2
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	mov r1, sp
	movs r0, #0
	strb r0, [r1, #0x18]
	adds r0, r6, #0
	bl FUN_080bd01c
	b _080BD0E8
	.align 2, 0
_080BD0C8: .4byte 0x08DA9E68
_080BD0CC: .4byte 0x00001787
_080BD0D0: .4byte 0x00001654
_080BD0D4: .4byte 0x0000165C
_080BD0D8:
	mov r1, sp
	ldr r0, _080BD108 @ =0x08DA9E68
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
_080BD0E8:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _080BD10C
	movs r4, #0xce
	lsls r4, r4, #4
	adds r0, r6, r4
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _080BD162
	.align 2, 0
_080BD108: .4byte 0x08DA9E68
_080BD10C:
	movs r0, #0xce
	lsls r0, r0, #4
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BD174 @ =0x00000CD8
	adds r4, r6, r1
	adds r5, r6, #0
	adds r5, #0x38
	mov r0, sp
	bl FUN_08094e70
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _080BD178 @ =0x00001644
	adds r4, r6, r2
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r3, _080BD17C @ =0x0000164C
	adds r1, r6, r3
	mov r0, sp
	bl FUN_08094d1c
	ldr r1, [r4]
	mov r0, sp
	bl FUN_08094d48
_080BD162:
	adds r0, r6, #0
	mov r1, sp
	bl FUN_080bcf04
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BD174: .4byte 0x00000CD8
_080BD178: .4byte 0x00001644
_080BD17C: .4byte 0x0000164C

	thumb_func_start FUN_080bd180
FUN_080bd180: @ 0x080BD180
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	movs r0, #0
	mov sl, r0
	mov r1, r8
	adds r1, #0x80
	str r1, [sp, #8]
	movs r2, #0
	str r2, [sp, #0xc]
_080BD19C:
	movs r0, #0
	str r0, [sp]
	mov r1, sl
	lsls r1, r1, #2
	mov sb, r1
	movs r0, #0xcc
	lsls r0, r0, #1
	add r0, r8
	ldr r2, [sp, #0xc]
	adds r7, r2, r0
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #8]
	adds r6, r0, r1
_080BD1BC:
	ldr r5, [sp]
	add r5, sb
	adds r0, r5, #0
	bl GetWeaponID
	adds r4, r0, #0
	cmp r4, #0
	ble _080BD1E8
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	adds r0, r7, #0
	mov r1, r8
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	b _080BD1F0
_080BD1E8:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
_080BD1F0:
	adds r0, r5, #0
	bl FUN_082430d4
	cmp r0, #0
	bne _080BD204
	adds r0, r5, #0
	bl FUN_080bce64
	cmp r0, #0
	bne _080BD210
_080BD204:
	adds r0, r7, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BD218
_080BD210:
	adds r0, r7, #0
	ldr r1, _080BD2D8 @ =0x000002DF
	bl FUN_080b95bc
_080BD218:
	adds r7, #0x60
	adds r6, #0x60
	ldr r2, [sp]
	adds r2, #1
	str r2, [sp]
	cmp r2, #3
	ble _080BD1BC
	ldr r0, [sp, #0xc]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #0xc]
	movs r2, #1
	add sl, r2
	mov r0, sl
	cmp r0, #3
	ble _080BD19C
	movs r1, #0
	mov sl, r1
_080BD23E:
	movs r2, #0
	str r2, [sp]
	mov r0, sl
	lsls r0, r0, #2
	mov sb, r0
	mov r1, sl
	adds r1, #1
	str r1, [sp, #4]
	mov r2, sb
	adds r2, #0x13
	mov r1, sl
	lsls r0, r1, #3
	add r0, sb
	lsls r0, r0, #5
	movs r1, #0xf3
	lsls r1, r1, #3
	add r1, r8
	adds r7, r0, r1
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r2, [sp, #8]
	adds r6, r0, r2
_080BD26C:
	ldr r5, [sp]
	add r5, sb
	ldr r0, _080BD2DC @ =0x00001654
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r5, r0
	ldr r1, _080BD2E0 @ =0x0000165C
	add r1, r8
	adds r1, r1, r0
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080BD2E4 @ =0x08DA9E68
	adds r0, r0, r1
	ldrb r4, [r0]
	cmp r4, #0
	ble _080BD2FC
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r0, r7, #0
	mov r1, r8
	adds r1, #0x38
	adds r2, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _080BD2E8 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #2
	ldr r2, _080BD2E4 @ =0x08DA9E68
	adds r0, r0, r2
	ldrh r0, [r0, #0xa]
	cmp r1, r0
	bge _080BD2EC
	adds r0, r7, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BD304
	.align 2, 0
_080BD2D8: .4byte 0x000002DF
_080BD2DC: .4byte 0x00001654
_080BD2E0: .4byte 0x0000165C
_080BD2E4: .4byte 0x08DA9E68
_080BD2E8: .4byte 0x030046A0
_080BD2EC:
	adds r0, r7, #0
	ldr r1, _080BD2F8 @ =0x000002DF
	bl FUN_080b95bc
	b _080BD304
	.align 2, 0
_080BD2F8: .4byte 0x000002DF
_080BD2FC:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
_080BD304:
	adds r6, #0x60
	adds r7, #0x60
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	cmp r0, #3
	ble _080BD26C
	ldr r1, [sp, #4]
	mov sl, r1
	cmp r1, #2
	ble _080BD23E
	ldr r0, _080BD344 @ =0x030046A0
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #0x60
	ldr r5, _080BD348 @ =0x00000D58
	add r5, r8
	ldr r0, [sp, #8]
	movs r1, #0xcc
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r6, #3
_080BD330:
	ldrh r3, [r4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _080BD34C
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _080BD374
	.align 2, 0
_080BD344: .4byte 0x030046A0
_080BD348: .4byte 0x00000D58
_080BD34C:
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #3
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r5]
	ldrh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x12
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r5, #2]
_080BD374:
	adds r4, #2
	adds r5, #0x60
	adds r2, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080BD330
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bd390
FUN_080bd390: @ 0x080BD390
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r1, _080BD3B8 @ =0x00001785
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD3C0
	ldr r2, _080BD3BC @ =0x00001787
	adds r4, r6, r2
	ldrb r0, [r4]
	bl GetWeaponID
	adds r5, r0, #0
	ldrb r0, [r4]
	bl FUN_080bce64
	adds r4, r0, #0
	movs r7, #1
	b _080BD402
	.align 2, 0
_080BD3B8: .4byte 0x00001785
_080BD3BC: .4byte 0x00001787
_080BD3C0:
	cmp r0, #7
	bhi _080BD3FC
	ldr r0, _080BD3F0 @ =0x00001787
	adds r1, r6, r0
	ldr r2, _080BD3F4 @ =0x00001654
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #4
	subs r0, #0x10
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r2, #8
	adds r1, r6, r2
	adds r1, r1, r0
	movs r5, #0
	ldrsb r5, [r1, r5]
	ldr r1, _080BD3F8 @ =0x08DA9E68
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r4, [r0, #0xa]
	b _080BD400
	.align 2, 0
_080BD3F0: .4byte 0x00001787
_080BD3F4: .4byte 0x00001654
_080BD3F8: .4byte 0x08DA9E68
_080BD3FC:
	movs r5, #0
	movs r4, #0
_080BD400:
	movs r7, #0
_080BD402:
	cmp r5, #0
	ble _080BD434
	cmp r4, #0
	ble _080BD434
	ldr r1, _080BD42C @ =0x00001787
	adds r0, r6, r1
	ldrb r1, [r0]
	add r0, sp, #4
	bl FUN_080b9938
	adds r0, r6, #0
	adds r0, #0x58
	ldr r2, _080BD430 @ =0x000013F8
	adds r1, r6, r2
	str r7, [sp]
	add r2, sp, #4
	adds r3, r4, #0
	bl FUN_080b9658
	b _080BD43C
	.align 2, 0
_080BD42C: .4byte 0x00001787
_080BD430: .4byte 0x000013F8
_080BD434:
	ldr r1, _080BD444 @ =0x000013F8
	adds r0, r6, r1
	bl FUN_080b9724
_080BD43C:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BD444: .4byte 0x000013F8

	thumb_func_start FUN_080bd448
FUN_080bd448: @ 0x080BD448
	push {r4, lr}
	adds r3, r0, #0
	movs r2, #0
	ldr r0, _080BD464 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x60
_080BD456:
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, r3
	bne _080BD468
	adds r0, r2, #0
	b _080BD474
	.align 2, 0
_080BD464: .4byte 0x030046A0
_080BD468:
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _080BD456
	movs r0, #1
	rsbs r0, r0, #0
_080BD474:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080bd47c
FUN_080bd47c: @ 0x080BD47C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	mov r8, r0
	movs r7, #0
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x4c]
	add r1, sp, #0x34
	mov sl, r1
	mov r2, sp
	adds r2, #0x3c
	str r2, [sp, #0x44]
	subs r0, #0x10
	str r0, [sp, #0x48]
	str r2, [sp, #0x50]
	str r1, [sp, #0x54]
	ldr r2, [sp, #0x4c]
	mov sb, r2
_080BD4A8:
	cmp r7, #0
	bne _080BD4B4
	ldr r0, _080BD4B0 @ =0x0000178A
	b _080BD4B6
	.align 2, 0
_080BD4B0: .4byte 0x0000178A
_080BD4B4:
	ldr r0, _080BD4FC @ =0x00001787
_080BD4B6:
	add r0, r8
	ldrb r4, [r0]
	adds r0, r4, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	mov r5, r8
	adds r5, #0x80
	adds r1, r5, r1
	ldr r0, [r1]
	movs r6, #1
	orrs r0, r6
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080bd448
	cmp r0, #0
	blt _080BD4EA
	adds r0, #0x22
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r1, r5, r1
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
_080BD4EA:
	adds r0, r4, #0
	bl GetWeaponID
	adds r1, r0, #0
	cmp r1, #0
	ble _080BD500
	mov r0, sb
	str r6, [r0]
	b _080BD506
	.align 2, 0
_080BD4FC: .4byte 0x00001787
_080BD500:
	movs r0, #0
	mov r2, sb
	str r0, [r2]
_080BD506:
	ldr r0, [sp, #0x54]
	stm r0!, {r1}
	str r0, [sp, #0x54]
	ldr r0, _080BD570 @ =0x000002DF
	ldr r1, [sp, #0x50]
	stm r1!, {r0}
	str r1, [sp, #0x50]
	lsls r0, r7, #3
	add r0, sp
	adds r0, #0xc
	adds r1, r4, #0
	bl FUN_080b9938
	movs r2, #4
	add sb, r2
	adds r7, #1
	cmp r7, #1
	ble _080BD4A8
	add r2, sp, #0x14
	ldr r3, [sp, #0x48]
	movs r7, #1
_080BD530:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	stm r3!, {r0, r1}
	subs r2, #8
	subs r7, #1
	cmp r7, #0
	bge _080BD530
	ldr r0, _080BD574 @ =0x00001690
	add r0, r8
	mov r1, sl
	str r1, [sp]
	ldr r2, [sp, #0x44]
	str r2, [sp, #4]
	movs r1, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x4c]
	add r2, sp, #0xc
	ldr r3, [sp, #0x48]
	bl FUN_080b9a28
	ldr r0, _080BD578 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BD570: .4byte 0x000002DF
_080BD574: .4byte 0x00001690
_080BD578: .4byte 0x0000038A

	thumb_func_start FUN_080bd57c
FUN_080bd57c: @ 0x080BD57C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r3, #1
	str r3, [sp, #0x2c]
	ldr r0, _080BD610 @ =0x0000178A
	adds r4, r5, r0
	ldrb r0, [r4]
	adds r0, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r5, #0
	adds r2, #0x80
	adds r2, r2, r1
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldrb r0, [r4]
	bl GetWeaponID
	str r0, [sp, #0x34]
	ldr r1, _080BD614 @ =0x000002DF
	mov r8, r1
	str r1, [sp, #0x3c]
	ldrb r1, [r4]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	ldr r1, _080BD618 @ =0x00001787
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	add r6, sp, #0x34
	str r2, [r6, #4]
	add r3, sp, #0x3c
	mov r0, r8
	str r0, [r3, #4]
	add r0, sp, #0xc
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	strh r2, [r4, #8]
	strh r2, [r4, #0xa]
	strh r2, [r4, #0xc]
	ldr r0, _080BD61C @ =0x00001690
	adds r5, r5, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080BD620 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BD610: .4byte 0x0000178A
_080BD614: .4byte 0x000002DF
_080BD618: .4byte 0x00001787
_080BD61C: .4byte 0x00001690
_080BD620: .4byte 0x0000038A

	thumb_func_start FUN_080bd624
FUN_080bd624: @ 0x080BD624
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r4, r0, #0
	movs r0, #1
	str r0, [sp, #0x2c]
	ldr r0, _080BD6B4 @ =0x0000178A
	adds r2, r4, r0
	ldr r1, _080BD6B8 @ =0x00001654
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #4
	subs r0, #0x10
	ldrb r3, [r2]
	adds r0, r0, r3
	ldr r3, _080BD6BC @ =0x0000165C
	adds r1, r4, r3
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	str r0, [sp, #0x34]
	ldr r0, _080BD6C0 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r2]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r5, sp, #0x1c
	ldr r1, _080BD6C4 @ =0x00001787
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	add r6, sp, #0x34
	str r2, [r6, #4]
	add r3, sp, #0x3c
	mov r0, r8
	str r0, [r3, #4]
	add r0, sp, #0xc
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	strh r2, [r5, #8]
	strh r2, [r5, #0xa]
	strh r2, [r5, #0xc]
	ldr r0, _080BD6C8 @ =0x00001690
	adds r4, r4, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r4, #0
	add r2, sp, #0xc
	adds r3, r5, #0
	bl FUN_080b9a28
	ldr r0, _080BD6CC @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BD6B4: .4byte 0x0000178A
_080BD6B8: .4byte 0x00001654
_080BD6BC: .4byte 0x0000165C
_080BD6C0: .4byte 0x000002DF
_080BD6C4: .4byte 0x00001787
_080BD6C8: .4byte 0x00001690
_080BD6CC: .4byte 0x0000038A

	thumb_func_start FUN_080bd6d0
FUN_080bd6d0: @ 0x080BD6D0
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _080BD708
	ldr r1, _080BD6F0 @ =0x00001785
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BD6F4
	adds r1, #0x2f
	adds r0, r4, r1
	movs r1, #0
	movs r2, #4
	bl FUN_080b98c0
	b _080BD832
	.align 2, 0
_080BD6F0: .4byte 0x00001785
_080BD6F4:
	ldr r1, _080BD704 @ =0x000017B4
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080BD832
	.align 2, 0
_080BD704: .4byte 0x000017B4
_080BD708:
	movs r6, #0
	ldr r1, _080BD750 @ =0x00001788
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD7A4
	ldr r0, _080BD754 @ =0x0000178A
	adds r7, r4, r0
	ldrb r5, [r7]
	adds r0, r5, #0
	bl GetWeaponID
	cmp r0, #0
	ble _080BD78C
	ldr r1, _080BD758 @ =0x00001785
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BD760
	adds r0, r5, #0
	bl FUN_080bd448
	cmp r0, #0
	bge _080BD7CA
	adds r0, r5, #0
	bl FUN_080bce64
	cmp r0, #0
	beq _080BD7CA
	ldr r1, _080BD75C @ =0x00001787
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080BD7CA
	movs r6, #5
	b _080BD7CA
	.align 2, 0
_080BD750: .4byte 0x00001788
_080BD754: .4byte 0x0000178A
_080BD758: .4byte 0x00001785
_080BD75C: .4byte 0x00001787
_080BD760:
	ldr r1, _080BD788 @ =0x00001787
	adds r0, r4, r1
	ldrb r0, [r0]
	ldrb r7, [r7]
	cmp r0, r7
	bne _080BD79A
	adds r0, r5, #0
	bl FUN_080bd448
	cmp r0, #0
	bge _080BD7CA
	adds r0, r5, #0
	bl FUN_080bce64
	movs r6, #5
	cmp r0, #0
	bne _080BD7CA
	movs r6, #0
	b _080BD7CA
	.align 2, 0
_080BD788: .4byte 0x00001787
_080BD78C:
	ldr r1, _080BD7A0 @ =0x00001787
	adds r0, r4, r1
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	ble _080BD7CA
_080BD79A:
	movs r6, #1
	b _080BD7CA
	.align 2, 0
_080BD7A0: .4byte 0x00001787
_080BD7A4:
	ldr r0, _080BD7D8 @ =0x00001787
	adds r2, r4, r0
	adds r0, #3
	adds r1, r4, r0
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080BD7C8
	ldr r1, _080BD7DC @ =0x00001785
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD7CA
	ldrb r0, [r2]
	bl GetWeaponID
	cmp r0, #0
	bne _080BD7CA
_080BD7C8:
	movs r6, #4
_080BD7CA:
	cmp r6, #4
	beq _080BD7E6
	cmp r6, #4
	bgt _080BD7E0
	cmp r6, #1
	beq _080BD810
	b _080BD824
	.align 2, 0
_080BD7D8: .4byte 0x00001787
_080BD7DC: .4byte 0x00001785
_080BD7E0:
	cmp r6, #5
	beq _080BD7FC
	b _080BD824
_080BD7E6:
	ldr r1, _080BD7F8 @ =0x000017B4
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #7
	bl FUN_080b98c0
	b _080BD832
	.align 2, 0
_080BD7F8: .4byte 0x000017B4
_080BD7FC:
	ldr r1, _080BD80C @ =0x000017B4
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #6
	bl FUN_080b98c0
	b _080BD832
	.align 2, 0
_080BD80C: .4byte 0x000017B4
_080BD810:
	ldr r1, _080BD820 @ =0x000017B4
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #3
	bl FUN_080b98c0
	b _080BD832
	.align 2, 0
_080BD820: .4byte 0x000017B4
_080BD824:
	ldr r1, _080BD838 @ =0x000017B4
	adds r0, r4, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080BD832:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BD838: .4byte 0x000017B4

	thumb_func_start FUN_080bd83c
FUN_080bd83c: @ 0x080BD83C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080BD888 @ =0x00001788
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD8DC
	ldr r2, _080BD88C @ =0x0000178A
	adds r6, r4, r2
	ldrb r5, [r6]
	adds r0, r5, #0
	bl GetWeaponID
	cmp r0, #0
	ble _080BD8C4
	ldr r3, _080BD890 @ =0x00001785
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #8
	bne _080BD898
	adds r0, r5, #0
	bl FUN_080bd448
	cmp r0, #0
	bge _080BD938
	adds r0, r5, #0
	bl FUN_080bce64
	cmp r0, #0
	beq _080BD938
	ldr r1, _080BD894 @ =0x00001787
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x22
	bne _080BD938
	movs r0, #5
	b _080BD93A
	.align 2, 0
_080BD888: .4byte 0x00001788
_080BD88C: .4byte 0x0000178A
_080BD890: .4byte 0x00001785
_080BD894: .4byte 0x00001787
_080BD898:
	ldr r2, _080BD8C0 @ =0x00001787
	adds r4, r4, r2
	ldrb r0, [r4]
	ldrb r6, [r6]
	cmp r0, r6
	bne _080BD8D2
	adds r0, r5, #0
	bl FUN_080bd448
	cmp r0, #0
	bge _080BD938
	adds r0, r5, #0
	bl FUN_080bce64
	cmp r0, #0
	beq _080BD938
	movs r0, #0x22
	strb r0, [r4]
	movs r0, #5
	b _080BD93A
	.align 2, 0
_080BD8C0: .4byte 0x00001787
_080BD8C4:
	ldr r3, _080BD8D8 @ =0x00001787
	adds r0, r4, r3
	ldrb r0, [r0]
	bl GetWeaponID
	cmp r0, #0
	ble _080BD938
_080BD8D2:
	movs r0, #1
	b _080BD93A
	.align 2, 0
_080BD8D8: .4byte 0x00001787
_080BD8DC:
	ldr r0, _080BD90C @ =0x00001787
	adds r2, r4, r0
	ldr r3, _080BD910 @ =0x0000178A
	adds r1, r4, r3
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BD91C
	ldr r1, _080BD914 @ =0x0000168C
	adds r0, r4, r1
	ldrh r1, [r0]
	strb r1, [r2]
	movs r0, #3
	ands r0, r1
	subs r3, #5
	adds r1, r4, r3
	strb r0, [r1]
	ldrb r0, [r2]
	lsrs r0, r0, #2
	ldr r2, _080BD918 @ =0x00001786
	adds r1, r4, r2
	strb r0, [r1]
	movs r0, #4
	b _080BD93A
	.align 2, 0
_080BD90C: .4byte 0x00001787
_080BD910: .4byte 0x0000178A
_080BD914: .4byte 0x0000168C
_080BD918: .4byte 0x00001786
_080BD91C:
	ldr r3, _080BD934 @ =0x00001785
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BD938
	ldrb r0, [r2]
	bl GetWeaponID
	cmp r0, #0
	bne _080BD938
	movs r0, #4
	b _080BD93A
	.align 2, 0
_080BD934: .4byte 0x00001785
_080BD938:
	movs r0, #0
_080BD93A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080bd940
FUN_080bd940: @ 0x080BD940
	push {r4, lr}
	movs r4, #0
_080BD944:
	adds r0, r4, #0
	bl GetWeaponID
	cmp r0, #0
	bne _080BD952
	adds r0, r4, #0
	b _080BD95C
_080BD952:
	adds r4, #1
	cmp r4, #0xf
	ble _080BD944
	movs r0, #1
	rsbs r0, r0, #0
_080BD95C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080bd964
FUN_080bd964: @ 0x080BD964
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xec
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	subs r1, #3
	ands r0, r1
	str r0, [r2]
	ldr r2, _080BD9D8 @ =0x00001784
	adds r4, r5, r2
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r0, _080BD9DC @ =0x00000EB8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #0x14
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FUN_080bd940
	ldr r2, _080BD9E0 @ =0x0000168C
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080bd058
	adds r0, r5, #0
	bl FUN_080bd180
	adds r0, r5, #0
	bl FUN_080bd390
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bd6d0
	ldr r1, _080BD9E4 @ =FUN_080bd9e8
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080bcdf8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BD9D8: .4byte 0x00001784
_080BD9DC: .4byte 0x00000EB8
_080BD9E0: .4byte 0x0000168C
_080BD9E4: .4byte FUN_080bd9e8

	thumb_func_start FUN_080bd9e8
FUN_080bd9e8: @ 0x080BD9E8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _080BDA54 @ =0x00001784
	adds r7, r5, r0
	ldr r1, _080BDA58 @ =0x00000C78
	adds r2, r5, r1
	ldr r0, _080BDA5C @ =0x00000C18
	adds r3, r5, r0
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080b95d0
	ldr r6, _080BDA60 @ =0x030044E0
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080BDA6C
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bcdec
	ldr r1, _080BDA64 @ =0x00000EB8
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldrh r1, [r6, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BDA34
	b _080BDC5A
_080BDA34:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r2, _080BDA68 @ =0x00001657
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080BDA4E
	b _080BDC5A
_080BDA4E:
	movs r0, #0
	strb r0, [r1]
	b _080BDC5A
	.align 2, 0
_080BDA54: .4byte 0x00001784
_080BDA58: .4byte 0x00000C78
_080BDA5C: .4byte 0x00000C18
_080BDA60: .4byte 0x030044E0
_080BDA64: .4byte 0x00000EB8
_080BDA68: .4byte 0x00001657
_080BDA6C:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bcdec
	ldr r0, _080BDAD4 @ =0x00000EB8
	adds r4, r5, r0
	movs r1, #0x18
	adds r1, r1, r5
	mov r8, r1
	adds r0, r4, #0
	bl FUN_082372cc
	ldrh r1, [r6, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BDA90
	b _080BDC34
_080BDA90:
	ldr r2, _080BDAD8 @ =0x00001787
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0x21
	bne _080BDAF0
	ldr r0, _080BDADC @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BDAE0 @ =0x00001644
	adds r0, r5, r1
	ldr r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	adds r0, r5, #0
	movs r1, #3
	adds r3, r4, #0
	bl FUN_080bce20
	ldr r2, _080BDAE4 @ =0x000017B4
	adds r0, r5, r2
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080b98c0
	ldr r1, _080BDAE8 @ =0x000015D8
	adds r0, r5, r1
	adds r1, #0x7e
	adds r2, r5, r1
	mov r1, r8
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080BDAEC @ =FUN_080bddc0
	b _080BDC26
	.align 2, 0
_080BDAD4: .4byte 0x00000EB8
_080BDAD8: .4byte 0x00001787
_080BDADC: .4byte 0x00000107
_080BDAE0: .4byte 0x00001644
_080BDAE4: .4byte 0x000017B4
_080BDAE8: .4byte 0x000015D8
_080BDAEC: .4byte FUN_080bddc0
_080BDAF0:
	ldr r2, _080BDB54 @ =0x00001785
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #3
	bls _080BDBA8
	movs r6, #1
	ldr r1, _080BDB58 @ =0x00001654
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #4
	subs r0, #0x10
	ldrb r4, [r4]
	adds r0, r0, r4
	ldr r2, _080BDB5C @ =0x0000165C
	adds r1, r5, r2
	adds r1, r1, r0
	movs r3, #0
	ldrsb r3, [r1, r3]
	cmp r3, #0
	ble _080BDB48
	ldr r0, _080BDB60 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldr r1, _080BDB64 @ =0x08DA9E68
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0, #0xa]
	cmp r2, r0
	blt _080BDB48
	ldr r2, _080BDB68 @ =0x0000168C
	adds r0, r5, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _080BDB44
	movs r6, #0
_080BDB44:
	cmp r6, #0
	bne _080BDB6C
_080BDB48:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BDC5A
	.align 2, 0
_080BDB54: .4byte 0x00001785
_080BDB58: .4byte 0x00001654
_080BDB5C: .4byte 0x0000165C
_080BDB60: .4byte 0x030046A0
_080BDB64: .4byte 0x08DA9E68
_080BDB68: .4byte 0x0000168C
_080BDB6C:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r7, #0
	bl FUN_080b9fd8
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BDBA4 @ =0x00000F38
	adds r2, r5, r1
	subs r1, #0x60
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	movs r1, #0x3c
	bl FUN_080b9d94
	b _080BDC1C
	.align 2, 0
_080BDBA4: .4byte 0x00000F38
_080BDBA8:
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r7, #0
	bl FUN_080b9fd8
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BDC08 @ =0x00000F38
	adds r2, r5, r1
	subs r1, #0x60
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldrb r4, [r4]
	adds r0, r4, #0
	bl GetWeaponID
	adds r6, r0, #0
	adds r0, r4, #0
	bl FUN_080bd448
	cmp r0, #0
	bge _080BDBFC
	cmp r6, #0
	ble _080BDBFC
	ldr r0, _080BDC0C @ =0x08DA9E68
	lsls r1, r6, #3
	adds r1, r1, r6
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r0, [r1, #0xa]
	cmp r0, #0
	bne _080BDC14
_080BDBFC:
	ldr r2, _080BDC10 @ =0x00001784
	adds r0, r5, r2
	movs r1, #0x1e
	bl FUN_080b9d94
	b _080BDC1C
	.align 2, 0
_080BDC08: .4byte 0x00000F38
_080BDC0C: .4byte 0x08DA9E68
_080BDC10: .4byte 0x00001784
_080BDC14:
	adds r0, r7, #0
	movs r1, #0xe
	bl FUN_080b9d94
_080BDC1C:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bd6d0
	ldr r1, _080BDC30 @ =FUN_080bdc64
_080BDC26:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080bcdf8
	b _080BDC5A
	.align 2, 0
_080BDC30: .4byte FUN_080bdc64
_080BDC34:
	adds r0, r7, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080BDC5A
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080bd058
	adds r0, r5, #0
	bl FUN_080bd390
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bd6d0
_080BDC5A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bdc64
FUN_080bdc64: @ 0x080BDC64
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080BDC98 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080BDD4E
	adds r0, r5, #0
	bl FUN_080bd83c
	adds r4, r0, #0
	ldr r1, _080BDC9C @ =0x000017B4
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	cmp r4, #4
	beq _080BDCBC
	cmp r4, #4
	bgt _080BDCA0
	cmp r4, #1
	beq _080BDCA6
	b _080BDD44
	.align 2, 0
_080BDC98: .4byte 0x030044E0
_080BDC9C: .4byte 0x000017B4
_080BDCA0:
	cmp r4, #5
	beq _080BDCFC
	b _080BDD44
_080BDCA6:
	adds r0, r5, #0
	bl FUN_080bd47c
	ldr r1, _080BDCB8 @ =0x080BDE2D
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080bcdf8
	b _080BDD62
	.align 2, 0
_080BDCB8: .4byte 0x080BDE2D
_080BDCBC:
	ldr r0, _080BDCEC @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BDCF0 @ =0x00001644
	adds r0, r5, r1
	ldr r2, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_080bce20
	ldr r1, _080BDCF4 @ =0x000015D8
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x7e
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080BDCF8 @ =FUN_080bde60
	b _080BDD28
	.align 2, 0
_080BDCEC: .4byte 0x00000107
_080BDCF0: .4byte 0x00001644
_080BDCF4: .4byte 0x000015D8
_080BDCF8: .4byte FUN_080bde60
_080BDCFC:
	ldr r0, _080BDD34 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BDD38 @ =0x00001644
	adds r0, r5, r1
	ldr r2, [r0]
	adds r0, r5, #0
	movs r1, #1
	movs r3, #0
	bl FUN_080bce20
	ldr r1, _080BDD3C @ =0x000015D8
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x7e
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080BDD40 @ =FUN_080bdf94
_080BDD28:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080bcdf8
	b _080BDD92
	.align 2, 0
_080BDD34: .4byte 0x00000107
_080BDD38: .4byte 0x00001644
_080BDD3C: .4byte 0x000015D8
_080BDD40: .4byte FUN_080bdf94
_080BDD44:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BDD62
_080BDD4E:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BDD68
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080bd964
_080BDD62:
	adds r4, r5, #0
	adds r4, #0x18
	b _080BDD92
_080BDD68:
	ldr r0, _080BDDB4 @ =0x00001784
	adds r6, r5, r0
	adds r0, r6, #0
	bl FUN_080b9f70
	adds r4, r5, #0
	adds r4, #0x18
	cmp r0, #0
	beq _080BDD92
	ldr r0, _080BDDB8 @ =0x00000EB8
	adds r1, r5, r0
	adds r0, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080bd058
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bd6d0
_080BDD92:
	ldr r1, _080BDDB4 @ =0x00001784
	adds r0, r5, r1
	ldr r1, _080BDDBC @ =0x00000C78
	adds r2, r5, r1
	subs r1, #0x60
	adds r3, r5, r1
	movs r1, #0
	bl FUN_080b95d0
	ldr r1, _080BDDB8 @ =0x00000EB8
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_082372cc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BDDB4: .4byte 0x00001784
_080BDDB8: .4byte 0x00000EB8
_080BDDBC: .4byte 0x00000C78

	thumb_func_start FUN_080bddc0
FUN_080bddc0: @ 0x080BDDC0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BDE00 @ =0x000015D8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BDE04 @ =0x00001656
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BDE14
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortWeapons
	ldr r1, _080BDE08 @ =0x00001788
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080BDE0C @ =0x00001789
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080BDE10 @ =0x0000178A
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080bd964
	b _080BDE24
	.align 2, 0
_080BDE00: .4byte 0x000015D8
_080BDE04: .4byte 0x00001656
_080BDE08: .4byte 0x00001788
_080BDE0C: .4byte 0x00001789
_080BDE10: .4byte 0x0000178A
_080BDE14:
	cmp r0, #0
	bne _080BDE24
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bd964
_080BDE24:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BDE2C:
	.byte 0x10, 0xB5, 0x04, 0x1C
	.byte 0x09, 0x49, 0x60, 0x18, 0xFB, 0xF7, 0x52, 0xFE, 0x00, 0x28, 0x0A, 0xD0, 0x07, 0x4A, 0xA0, 0x18
	.byte 0x00, 0x78, 0x03, 0x3A, 0xA1, 0x18, 0x09, 0x78, 0x84, 0xF1, 0xFC, 0xFE, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0x89, 0xFD, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x90, 0x16, 0x00, 0x00, 0x8A, 0x17, 0x00, 0x00

	thumb_func_start FUN_080bde60
FUN_080bde60: @ 0x080BDE60
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BDE90 @ =0x000015D8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BDE94 @ =0x00001656
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BDE9C
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080bd624
	ldr r1, _080BDE98 @ =0x080BDEB5
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080bcdf8
	b _080BDEAC
	.align 2, 0
_080BDE90: .4byte 0x000015D8
_080BDE94: .4byte 0x00001656
_080BDE98: .4byte 0x080BDEB5
_080BDE9C:
	cmp r0, #0
	bne _080BDEAC
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bd964
_080BDEAC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BDEB4:
	.byte 0xF0, 0xB5, 0x57, 0x46, 0x4E, 0x46, 0x45, 0x46, 0xE0, 0xB4, 0x89, 0xB0
	.byte 0x07, 0x1C, 0x2B, 0x49, 0x78, 0x18, 0xFB, 0xF7, 0x09, 0xFE, 0x00, 0x28, 0x48, 0xD0, 0x29, 0x4A
	.byte 0xB8, 0x18, 0x00, 0x78, 0x81, 0x46, 0x28, 0x4B, 0xF8, 0x18, 0x04, 0x78, 0x10, 0x3C, 0x27, 0x4E
	.byte 0xB0, 0x46, 0x27, 0x48, 0xC0, 0x19, 0x82, 0x46, 0x00, 0x78, 0x00, 0x01, 0x20, 0x18, 0x25, 0x49
	.byte 0x7D, 0x18, 0x28, 0x18, 0x00, 0x78, 0x00, 0x06, 0x00, 0x16, 0xC1, 0x00, 0x09, 0x18, 0x89, 0x00
	.byte 0x68, 0x46, 0x41, 0x44, 0x4C, 0xC9, 0x4C, 0xC0, 0x4C, 0xC9, 0x4C, 0xC0, 0x4C, 0xC9, 0x4C, 0xC0
	.byte 0x69, 0x46, 0x00, 0x20, 0x08, 0x76, 0x38, 0x1C, 0xFF, 0xF7, 0x80, 0xF8, 0x48, 0x46, 0x69, 0x46
	.byte 0x84, 0xF1, 0x24, 0xFE, 0x18, 0x48, 0x02, 0x68, 0x91, 0x20, 0x00, 0x01, 0x12, 0x18, 0x51, 0x46
	.byte 0x08, 0x78, 0x00, 0x01, 0x24, 0x18, 0x2D, 0x19, 0x00, 0x21, 0x69, 0x56, 0xC8, 0x00, 0x40, 0x18
	.byte 0x80, 0x00, 0x40, 0x44, 0x11, 0x88, 0x40, 0x89, 0x09, 0x1A, 0x11, 0x80, 0x0F, 0x4A, 0xB9, 0x18
	.byte 0x01, 0x20, 0x08, 0x70, 0x0E, 0x48, 0x82, 0xF1, 0xC3, 0xFB, 0x38, 0x1C, 0xFF, 0xF7, 0x02, 0xFD
	.byte 0x09, 0xB0, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.byte 0x90, 0x16, 0x00, 0x00, 0x87, 0x17, 0x00, 0x00, 0x8A, 0x17, 0x00, 0x00, 0x68, 0x9E, 0xDA, 0x08
	.byte 0x54, 0x16, 0x00, 0x00, 0x5C, 0x16, 0x00, 0x00, 0xA0, 0x46, 0x00, 0x03, 0x58, 0x16, 0x00, 0x00
	.byte 0x11, 0x01, 0x00, 0x00

	thumb_func_start FUN_080bdf94
FUN_080bdf94: @ 0x080BDF94
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BDFC4 @ =0x000015D8
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BDFC8 @ =0x00001656
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BDFD0
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080bd57c
	ldr r1, _080BDFCC @ =0x080BDFE9
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080bcdf8
	b _080BDFE0
	.align 2, 0
_080BDFC4: .4byte 0x000015D8
_080BDFC8: .4byte 0x00001656
_080BDFCC: .4byte 0x080BDFE9
_080BDFD0:
	cmp r0, #0
	bne _080BDFE0
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bd964
_080BDFE0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BDFE8:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0x16, 0x49, 0x60, 0x18
	.byte 0xFB, 0xF7, 0x74, 0xFD, 0x00, 0x28, 0x23, 0xD0, 0x14, 0x49, 0x60, 0x18, 0x05, 0x78, 0x28, 0x1C
	.byte 0xFE, 0xF7, 0x30, 0xFF, 0x12, 0x4B, 0x1A, 0x68, 0x91, 0x21, 0x09, 0x01, 0x52, 0x18, 0x11, 0x88
	.byte 0x09, 0x18, 0x11, 0x80, 0x09, 0x04, 0x09, 0x14, 0x0E, 0x4A, 0x91, 0x42, 0x04, 0xDD, 0x18, 0x68
	.byte 0x91, 0x21, 0x09, 0x01, 0x40, 0x18, 0x02, 0x80, 0x28, 0x1C, 0x84, 0xF1, 0xED, 0xFD, 0x0A, 0x49
	.byte 0x60, 0x18, 0x01, 0x21, 0x01, 0x70, 0x09, 0x49, 0x20, 0x1C, 0x00, 0x22, 0xFE, 0xF7, 0xDC, 0xFE
	.byte 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x90, 0x16, 0x00, 0x00, 0x8A, 0x17, 0x00, 0x00
	.byte 0xA0, 0x46, 0x00, 0x03, 0x0F, 0x27, 0x00, 0x00, 0x59, 0x16, 0x00, 0x00, 0x61, 0xE0, 0x0B, 0x08

	thumb_func_start FUN_080be060
FUN_080be060: @ 0x080BE060
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080BE094 @ =0x0000168E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080BE074
	ldr r0, _080BE098 @ =0x00000276
	bl PlaySound_082406e0
_080BE074:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	bhi _080BE0B8
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BE0A0
	ldr r2, _080BE09C @ =0x00000C3A
	adds r1, r5, r2
	b _080BE0C0
	.align 2, 0
_080BE094: .4byte 0x0000168E
_080BE098: .4byte 0x00000276
_080BE09C: .4byte 0x00000C3A
_080BE0A0:
	ldrh r1, [r4]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x20
	subs r1, r1, r0
	ldr r2, _080BE0B4 @ =0x00000C3A
	adds r0, r5, r2
	strh r1, [r0]
	b _080BE0D2
	.align 2, 0
_080BE0B4: .4byte 0x00000C3A
_080BE0B8:
	cmp r1, #0xf
	bhi _080BE0CC
	ldr r0, _080BE0C8 @ =0x00000C3A
	adds r1, r5, r0
_080BE0C0:
	movs r0, #0x20
	strh r0, [r1]
	b _080BE0D2
	.align 2, 0
_080BE0C8: .4byte 0x00000C3A
_080BE0CC:
	adds r0, r5, #0
	bl FUN_080bd964
_080BE0D2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080be0d8
FUN_080be0d8: @ 0x080BE0D8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _080BE134 @ =0x00001784
	adds r5, r4, r0
	movs r0, #0x14
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #4
	movs r3, #0
	bl FUN_080b9ff8
	ldr r2, _080BE138 @ =0x00000EB8
	adds r1, r4, r2
	adds r0, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080bd940
	ldr r2, _080BE13C @ =0x0000168C
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080bd180
	adds r0, r4, #0
	bl FUN_080bd390
	adds r0, r4, #0
	bl FUN_080bd058
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080bd6d0
	ldr r1, _080BE140 @ =FUN_080bd9e8
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080bcdf8
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BE134: .4byte 0x00001784
_080BE138: .4byte 0x00000EB8
_080BE13C: .4byte 0x0000168C
_080BE140: .4byte FUN_080bd9e8

	thumb_func_start FUN_080be144
FUN_080be144: @ 0x080BE144
	push {r4, r5, lr}
	sub sp, #0x34
	adds r4, r0, #0
	ldr r0, _080BE1B0 @ =0x0000C091
	ldr r1, _080BE1B4 @ =0x00009F57
	bl GetFile
	adds r2, r0, #0
	ldr r0, _080BE1B8 @ =0x00001638
	adds r4, r4, r0
	str r2, [r4]
	movs r5, #0
	str r5, [sp, #0x30]
	str r5, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0x30
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	ldr r1, [r4]
	movs r0, #0
	movs r2, #4
	bl FUN_0822c398
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #3
	add r1, sp, #0xc
	bl FUN_08242b28
	add r0, sp, #0xc
	ldrb r0, [r0, #1]
	cmp r0, #4
	bne _080BE1A8
	ldr r0, _080BE1BC @ =0x03003ED0
	ldr r0, [r0, #0x2c]
	ldr r1, _080BE1C0 @ =0x00000392
	adds r0, r0, r1
	ldr r2, _080BE1C4 @ =0x0000F06E
	adds r1, r2, #0
	strh r1, [r0]
_080BE1A8:
	add sp, #0x34
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BE1B0: .4byte 0x0000C091
_080BE1B4: .4byte 0x00009F57
_080BE1B8: .4byte 0x00001638
_080BE1BC: .4byte 0x03003ED0
_080BE1C0: .4byte 0x00000392
_080BE1C4: .4byte 0x0000F06E

	thumb_func_start FUN_080be1c8
FUN_080be1c8: @ 0x080BE1C8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080BE1F0 @ =0x000092B3
	ldr r1, _080BE1F4 @ =0x0000A41A
	bl GetFile
	ldr r1, _080BE1F8 @ =0x0000163C
	adds r4, r4, r1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, _080BE1FC @ =0x030043F0
	ldr r2, _080BE200 @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE1F0: .4byte 0x000092B3
_080BE1F4: .4byte 0x0000A41A
_080BE1F8: .4byte 0x0000163C
_080BE1FC: .4byte 0x030043F0
_080BE200: .4byte 0x04000018

	thumb_func_start FUN_080be204
FUN_080be204: @ 0x080BE204
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r4, _080BE5E0 @ =0x0000CB05
	ldr r1, _080BE5E4 @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x38
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	movs r6, #0x38
	adds r6, r6, r7
	mov r8, r6
	mov r0, r8
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080BE5E8 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x18
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r7, #0
	adds r0, #0x18
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080BE5EC @ =0x0000414C
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x58
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r4, r5}
	stm r1!, {r4, r5}
	adds r6, r7, #0
	adds r6, #0x58
	adds r0, r6, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080BE5F0 @ =0xFFFF0000
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x78
	str r1, [sp]
	str r1, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x27
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r0, r7, #0
	adds r0, #0xd8
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x23
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x24
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r4, #0
	add r6, sp, #0x10
	mov sb, r4
	mov r5, r8
	str r5, [sp, #0x18]
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r5, r7, r0
_080BE2F0:
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r6, #2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r6]
	mov r1, sb
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r2, #0x68
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xf
	ble _080BE2F0
	movs r4, #0
	movs r2, #0x18
	adds r2, r2, r7
	mov sl, r2
	adds r3, r7, #0
	adds r3, #0x58
	str r3, [sp, #0x1c]
	add r6, sp, #0x10
	mov r8, r4
	movs r0, #0xf3
	lsls r0, r0, #3
	adds r5, r7, r0
_080BE344:
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r6, #2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r6]
	mov r1, r8
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x68
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xb
	ble _080BE344
	movs r6, #0
	ldr r2, _080BE5F4 @ =0x00000D38
	adds r5, r7, r2
	movs r4, #3
_080BE386:
	str r6, [sp]
	str r6, [sp, #4]
	movs r3, #0x3c
	mov sb, r3
	str r3, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x41
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE386
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	adds r6, r0, #0
	movs r0, #0x80
	strh r0, [r6, #2]
	ldr r1, _080BE5F8 @ =0x00000CD8
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0xd0
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0x78
	add r0, sp, #0x10
	strh r1, [r0]
	movs r5, #0x68
	strh r5, [r6, #2]
	ldr r3, _080BE5FC @ =0x00000C78
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0xcb
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r5, [r0]
	movs r3, #0x20
	mov r8, r3
	mov r5, r8
	strh r5, [r6, #2]
	ldr r0, _080BE600 @ =0x00000C18
	adds r5, r7, r0
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0xcc
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r5, #0
	bl FUN_080b95bc
	ldr r3, _080BE604 @ =0x00000F18
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r5, sb
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	mov r1, sl
	movs r2, #0x3c
	movs r3, #0x31
	bl FUN_0822f3fc
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	mov r2, r8
	strh r2, [r6, #2]
	ldr r3, _080BE608 @ =0x00000EB8
	adds r5, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r6, sb
	str r6, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x39
	movs r3, #0x30
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _080BE60C @ =0x000013F8
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0x18
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0xb
	add r1, sp, #0x10
	strh r0, [r1]
	adds r6, r1, #0
	ldr r3, _080BE610 @ =0x00001458
	adds r5, r7, r3
	mov r8, r4
	movs r4, #3
_080BE49A:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0x19
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #6
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE49A
	movs r1, #0x28
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x68
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r1, _080BE614 @ =0x00000F78
	adds r5, r7, r1
	movs r2, #0
	mov r8, r2
	movs r4, #2
_080BE4D8:
	mov r3, r8
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE4D8
	movs r1, #0x58
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x68
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r4, _080BE618 @ =0x00001098
	adds r5, r7, r4
	movs r0, #0
	mov r8, r0
	movs r4, #2
_080BE516:
	mov r1, r8
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE516
	movs r1, #0x28
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x70
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r2, _080BE61C @ =0x000011B8
	adds r5, r7, r2
	movs r3, #0
	mov r8, r3
	movs r4, #2
_080BE554:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE554
	movs r1, #0x58
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x70
	strh r0, [r1, #2]
	adds r6, r1, #0
	ldr r1, _080BE620 @ =0x000012D8
	adds r5, r7, r1
	movs r2, #0
	mov r8, r2
	movs r4, #2
_080BE592:
	mov r3, r8
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #0x3c
	mov sb, r0
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BE592
	movs r1, #0
	add r0, sp, #0x10
	strh r1, [r0]
	strh r1, [r0, #2]
	ldr r2, _080BE624 @ =0x000015D8
	adds r0, r7, r2
	str r1, [sp]
	str r1, [sp, #4]
	mov r3, sb
	str r3, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	mov r1, sl
	movs r2, #0x94
	movs r3, #0x11
	bl FUN_0822f3fc
	b _080BE628
	.align 2, 0
_080BE5E0: .4byte 0x0000CB05
_080BE5E4: .4byte 0x00005D04
_080BE5E8: .4byte 0x0000B343
_080BE5EC: .4byte 0x0000414C
_080BE5F0: .4byte 0xFFFF0000
_080BE5F4: .4byte 0x00000D38
_080BE5F8: .4byte 0x00000CD8
_080BE5FC: .4byte 0x00000C78
_080BE600: .4byte 0x00000C18
_080BE604: .4byte 0x00000F18
_080BE608: .4byte 0x00000EB8
_080BE60C: .4byte 0x000013F8
_080BE610: .4byte 0x00001458
_080BE614: .4byte 0x00000F78
_080BE618: .4byte 0x00001098
_080BE61C: .4byte 0x000011B8
_080BE620: .4byte 0x000012D8
_080BE624: .4byte 0x000015D8
_080BE628:
	ldr r5, _080BE648 @ =0x00001690
	adds r0, r7, r5
	bl FUN_080b99a0
	ldr r6, _080BE64C @ =0x000017B4
	adds r0, r7, r6
	bl FUN_080b9814
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BE648: .4byte 0x00001690
_080BE64C: .4byte 0x000017B4

	thumb_func_start FUN_080be650
FUN_080be650: @ 0x080BE650
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BE66A
	bl FUN_0823d340
	movs r2, #0xb2
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
_080BE66A:
	bl FUN_08049f5c
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	ldr r0, _080BE68C @ =0x0000A41A
	bl FUN_08047dc0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE68C: .4byte 0x0000A41A

	thumb_func_start FUN_080be690
FUN_080be690: @ 0x080BE690
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r0, #0x57
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BE6AC
	bl Script_GetValue
	adds r5, r0, #0
	b _080BE6AE
_080BE6AC:
	movs r5, #0
_080BE6AE:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BE75C
	movs r4, #0
	movs r6, #0
	movs r7, #0
	cmp r7, r5
	bge _080BE720
	ldr r0, _080BE6E4 @ =0x08DA9E68
	mov sb, r0
_080BE6C6:
	bl Script_GetValue
	adds r1, r0, #0
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, sb
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _080BE700
	cmp r0, #1
	bgt _080BE6E8
	cmp r0, #0
	beq _080BE6EE
	b _080BE71A
	.align 2, 0
_080BE6E4: .4byte 0x08DA9E68
_080BE6E8:
	cmp r0, #2
	beq _080BE710
	b _080BE71A
_080BE6EE:
	ldr r0, _080BE6FC @ =0x0000165C
	add r0, r8
	adds r0, r0, r4
	strb r1, [r0]
	adds r4, #1
	b _080BE71A
	.align 2, 0
_080BE6FC: .4byte 0x0000165C
_080BE700:
	ldr r0, _080BE70C @ =0x0000166C
	add r0, r8
	adds r0, r0, r6
	strb r1, [r0]
	adds r6, #1
	b _080BE71A
	.align 2, 0
_080BE70C: .4byte 0x0000166C
_080BE710:
	ldr r0, _080BE7A0 @ =0x0000167C
	add r0, r8
	adds r0, r0, r7
	strb r1, [r0]
	adds r7, #1
_080BE71A:
	subs r5, #1
	cmp r5, #0
	bne _080BE6C6
_080BE720:
	cmp r4, #0xb
	bgt _080BE734
	ldr r1, _080BE7A4 @ =0x0000165C
	add r1, r8
	movs r2, #0
_080BE72A:
	adds r0, r1, r4
	strb r2, [r0]
	adds r4, #1
	cmp r4, #0xb
	ble _080BE72A
_080BE734:
	cmp r6, #0xb
	bgt _080BE748
	ldr r1, _080BE7A8 @ =0x0000166C
	add r1, r8
	movs r2, #0
_080BE73E:
	adds r0, r1, r6
	strb r2, [r0]
	adds r6, #1
	cmp r6, #0xb
	ble _080BE73E
_080BE748:
	cmp r7, #0xb
	bgt _080BE75C
	ldr r1, _080BE7A0 @ =0x0000167C
	add r1, r8
	movs r2, #0
_080BE752:
	adds r0, r1, r7
	strb r2, [r0]
	adds r7, #1
	cmp r7, #0xb
	ble _080BE752
_080BE75C:
	movs r0, #0x77
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BE770
	bl FUN_0823d340
	ldr r1, _080BE7AC @ =0x00001644
	add r1, r8
	str r0, [r1]
_080BE770:
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BE794
	bl FUN_0823d340
	ldr r4, _080BE7B0 @ =0x00001648
	add r4, r8
	str r0, [r4]
	cmp r0, #0
	beq _080BE794
	bl VM_ParseStringRef
	adds r0, #1
	bl Textbox_LookupString
	str r0, [r4]
_080BE794:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BE7A0: .4byte 0x0000167C
_080BE7A4: .4byte 0x0000165C
_080BE7A8: .4byte 0x0000166C
_080BE7AC: .4byte 0x00001644
_080BE7B0: .4byte 0x00001648

	thumb_func_start FUN_080be7b4
FUN_080be7b4: @ 0x080BE7B4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x65
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080BE7D4
	bl Script_GetValue
	ldr r2, _080BE7D0 @ =0x00001894
	adds r1, r4, r2
	str r0, [r1]
	b _080BE7DA
	.align 2, 0
_080BE7D0: .4byte 0x00001894
_080BE7D4:
	ldr r2, _080BE7E0 @ =0x00001894
	adds r0, r4, r2
	str r1, [r0]
_080BE7DA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE7E0: .4byte 0x00001894

	thumb_func_start FUN_080be7e4
FUN_080be7e4: @ 0x080BE7E4
	push {lr}
	adds r2, r0, #0
	ldr r0, _080BE808 @ =0x0000168E
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BE802
	ldr r1, _080BE80C @ =FUN_080be810
	adds r0, r2, #0
	bl FUN_080bcdd4
_080BE802:
	pop {r0}
	bx r0
	.align 2, 0
_080BE808: .4byte 0x0000168E
_080BE80C: .4byte FUN_080be810

	thumb_func_start FUN_080be810
FUN_080be810: @ 0x080BE810
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080BE850 @ =0x00001655
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	beq _080BE90C
	adds r1, #5
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1d
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080BE854
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	b _080BE86C
	.align 2, 0
_080BE850: .4byte 0x00001655
_080BE854:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
_080BE86C:
	str r0, [r1]
	ldr r0, _080BE890 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080BE89C
	ldr r0, _080BE894 @ =0x00001654
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _080BE898
	movs r0, #2
	b _080BE8BE
	.align 2, 0
_080BE890: .4byte 0x030044E0
_080BE894: .4byte 0x00001654
_080BE898:
	subs r0, #1
	b _080BE8BE
_080BE89C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _080BE8D0
	ldr r0, _080BE8B8 @ =0x00001654
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #2
	bne _080BE8BC
	strb r2, [r1]
	b _080BE8C0
	.align 2, 0
_080BE8B8: .4byte 0x00001654
_080BE8BC:
	adds r0, #1
_080BE8BE:
	strb r0, [r1]
_080BE8C0:
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080be0d8
	b _080BE92A
_080BE8D0:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BE92A
	ldr r0, _080BE900 @ =0x00000119
	bl PlaySound_082406e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BE904 @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080BE908 @ =FUN_080be948
	adds r0, r4, #0
	bl FUN_080bcdd4
	b _080BE936
	.align 2, 0
_080BE900: .4byte 0x00000119
_080BE904: .4byte 0x0000FFFF
_080BE908: .4byte FUN_080be948
_080BE90C:
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080BE940 @ =0x0000165A
	adds r0, r4, r1
	strb r3, [r0]
_080BE92A:
	ldr r1, _080BE944 @ =0x0000189C
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080BE936:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BE940: .4byte 0x0000165A
_080BE944: .4byte 0x0000189C

	thumb_func_start FUN_080be948
FUN_080be948: @ 0x080BE948
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080BE9A0 @ =0x0000168E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BE998
	ldr r1, _080BE9A4 @ =0x00001894
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080BE992
	ldr r1, _080BE9A8 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	ldr r1, _080BE9AC @ =0x00001658
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp, #4]
	add r1, sp, #8
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_080BE992:
	adds r0, r4, #0
	bl KillEntity
_080BE998:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE9A0: .4byte 0x0000168E
_080BE9A4: .4byte 0x00001894
_080BE9A8: .4byte 0xFFFF0000
_080BE9AC: .4byte 0x00001658

	thumb_func_start FUN_080be9b0
FUN_080be9b0: @ 0x080BE9B0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080BE9D8 @ =0x00001657
	adds r5, r4, r0
	ldrb r0, [r5]
	bl FUN_080b94cc
	ldrb r0, [r5]
	bl FUN_080b9400
	ldr r1, _080BE9DC @ =0x00001898
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080BE9D8: .4byte 0x00001657
_080BE9DC: .4byte 0x00001898

	thumb_func_start FUN_080be9e0
FUN_080be9e0: @ 0x080BE9E0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x78
	movs r5, #0x39
_080BE9EA:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BE9EA
	ldr r1, _080BEA10 @ =0x00001690
	adds r0, r6, r1
	bl FUN_080b9a0c
	ldr r1, _080BEA14 @ =0x000017B4
	adds r0, r6, r1
	bl FUN_080b9894
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BEA10: .4byte 0x00001690
_080BEA14: .4byte 0x000017B4

	thumb_func_start FUN_080bea18
FUN_080bea18: @ 0x080BEA18
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_080be690
	adds r0, r4, #0
	bl FUN_080be144
	adds r0, r4, #0
	bl FUN_080be1c8
	adds r0, r4, #0
	bl FUN_080be204
	adds r0, r4, #0
	bl FUN_080be650
	adds r0, r4, #0
	bl FUN_080be7b4
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BEA8C @ =0x0000FFFF
	str r0, [sp, #4]
	movs r5, #0
	str r5, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080BEA90 @ =0x00001654
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_080be0d8
	ldr r1, _080BEA94 @ =0x00001658
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r5, [r0]
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080BEA98 @ =FUN_080be7e4
	adds r0, r4, #0
	bl FUN_080bcdd4
	movs r0, #0
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080BEA8C: .4byte 0x0000FFFF
_080BEA90: .4byte 0x00001654
_080BEA94: .4byte 0x00001658
_080BEA98: .4byte FUN_080be7e4
_080BEA9C:
	.byte 0x10, 0xB5, 0xC5, 0x21
	.byte 0x49, 0x01, 0x0B, 0x20, 0x72, 0xF1, 0x84, 0xF8, 0x04, 0x1C, 0x00, 0x2C, 0x12, 0xD0, 0x07, 0x49
	.byte 0x07, 0x4A, 0x72, 0xF1, 0xA1, 0xF8, 0x20, 0x1C, 0xFF, 0xF7, 0xAE, 0xFF, 0x00, 0x28, 0x09, 0xDA
	.byte 0x20, 0x1C, 0x72, 0xF1, 0xD3, 0xF8, 0x00, 0x20, 0x05, 0xE0, 0x00, 0x00, 0xB1, 0xE9, 0x0B, 0x08
	.byte 0xE1, 0xE9, 0x0B, 0x08, 0x20, 0x1C, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080beadc
FUN_080beadc: @ 0x080BEADC
	ldr r3, _080BEAEC @ =0x000010E8
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080BEAF0 @ =0x00000ECA
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080BEAEC: .4byte 0x000010E8
_080BEAF0: .4byte 0x00000ECA

	thumb_func_start FUN_080beaf4
FUN_080beaf4: @ 0x080BEAF4
	ldr r2, _080BEAFC @ =0x00000EC8
	adds r0, r0, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
_080BEAFC: .4byte 0x00000EC8

	thumb_func_start FUN_080beb00
FUN_080beb00: @ 0x080BEB00
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _080BEB20 @ =0x000010EC
	adds r0, r4, r3
	str r1, [r0]
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080beaf4
	ldr r0, _080BEB24 @ =0x00000ECA
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BEB20: .4byte 0x000010EC
_080BEB24: .4byte 0x00000ECA

	thumb_func_start FUN_080beb28
FUN_080beb28: @ 0x080BEB28
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_08049e5c
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xec
	lsls r0, r0, #4
	adds r4, r4, r0
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r5, #0
	bl FUN_08047a28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080beb6c
FUN_080beb6c: @ 0x080BEB6C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080BEB88 @ =0x00000FD1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BEB8C
	adds r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	bl GetValuableItemID
	adds r5, r0, #0
	b _080BEBB0
	.align 2, 0
_080BEB88: .4byte 0x00000FD1
_080BEB8C:
	cmp r0, #7
	bhi _080BEBAC
	ldr r1, _080BEBA4 @ =0x00000FD3
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, r4, r0
	ldr r1, _080BEBA8 @ =0x00000EBC
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	b _080BEBB0
	.align 2, 0
_080BEBA4: .4byte 0x00000FD3
_080BEBA8: .4byte 0x00000EBC
_080BEBAC:
	movs r5, #1
	rsbs r5, r5, #0
_080BEBB0:
	cmp r5, #0
	bge _080BEBCC
	movs r1, #0xb6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _080BEC10
_080BEBCC:
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BEC18 @ =0x00000EC4
	adds r4, r4, r1
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r5, #0
	bl FUN_08047a28
	ldr r0, [r4]
	bl VM_ParseStringRef
	adds r0, #0x4e
	adds r0, r0, r5
	bl Textbox_LookupString
	bl FUN_08049e30
_080BEC10:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BEC18: .4byte 0x00000EC4

	thumb_func_start FUN_080bec1c
FUN_080bec1c: @ 0x080BEC1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	movs r7, #0
	adds r0, #0x80
	str r0, [sp]
	movs r1, #0
	str r1, [sp, #8]
	mov sb, r1
_080BEC36:
	movs r2, #0
	mov r8, r2
	mov r1, sb
	adds r1, #1
	mov r0, sl
	adds r0, #0xd8
	ldr r2, [sp, #8]
	adds r6, r2, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, [sp]
	adds r5, r0, r1
_080BEC50:
	mov r1, sb
	add r1, r8
	adds r0, r1, #0
	bl GetValuableItemID
	adds r4, r0, #0
	cmp r4, #0
	blt _080BECA0
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r2, r4, #0
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r4, #0
	subs r0, #0x38
	cmp r0, #7
	bhi _080BEC94
	adds r0, r6, #0
	ldr r1, _080BEC90 @ =0x000002DF
	bl FUN_080b95bc
	b _080BECA8
	.align 2, 0
_080BEC90: .4byte 0x000002DF
_080BEC94:
	adds r0, r6, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BECA8
_080BECA0:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
_080BECA8:
	adds r5, #0x60
	adds r6, #0x60
	movs r2, #1
	add r8, r2
	mov r0, r8
	cmp r0, #3
	ble _080BEC50
	ldr r1, [sp, #8]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r1, r2
	str r1, [sp, #8]
	movs r0, #4
	add sb, r0
	adds r7, #1
	cmp r7, #3
	ble _080BEC36
	movs r7, #0
_080BECCC:
	movs r1, #0
	mov r8, r1
	lsls r2, r7, #2
	mov sb, r2
	adds r0, r7, #1
	str r0, [sp, #4]
	adds r2, #0x11
	lsls r0, r7, #3
	add r0, sb
	lsls r0, r0, #5
	movs r1, #0xdb
	lsls r1, r1, #3
	add r1, sl
	adds r6, r0, r1
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r1, [sp]
	adds r5, r0, r1
_080BECF2:
	mov r1, sb
	add r1, r8
	ldr r0, _080BED48 @ =0x00000ECC
	add r0, sl
	adds r0, r0, r1
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #0
	blt _080BED64
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r2, r4, #0
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	adds r1, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _080BED4C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r4, #4
	ldr r2, _080BED50 @ =0x08DAA8E4
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r1, r0
	bhs _080BED54
	adds r0, r6, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BED6C
	.align 2, 0
_080BED48: .4byte 0x00000ECC
_080BED4C: .4byte 0x030046A0
_080BED50: .4byte 0x08DAA8E4
_080BED54:
	adds r0, r6, #0
	ldr r1, _080BED60 @ =0x000002DF
	bl FUN_080b95bc
	b _080BED6C
	.align 2, 0
_080BED60: .4byte 0x000002DF
_080BED64:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
_080BED6C:
	adds r5, #0x60
	adds r6, #0x60
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #3
	ble _080BECF2
	ldr r7, [sp, #4]
	cmp r7, #2
	ble _080BECCC
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bed90
FUN_080bed90: @ 0x080BED90
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r1, _080BEDD4 @ =0x00000FD3
	adds r0, r5, r1
	ldrb r2, [r0]
	adds r0, r5, r2
	ldr r1, _080BEDD8 @ =0x00000EBC
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	blt _080BEDE4
	ldr r0, _080BEDDC @ =0x08DAA8D8
	lsls r1, r1, #4
	adds r0, #0xc
	adds r1, r1, r0
	ldr r4, [r1]
	add r0, sp, #4
	adds r1, r2, #0
	bl FUN_080b9938
	adds r0, r5, #0
	adds r0, #0x58
	ldr r2, _080BEDE0 @ =0x00000C78
	adds r1, r5, r2
	movs r2, #0
	str r2, [sp]
	add r2, sp, #4
	adds r3, r4, #0
	bl FUN_080b9658
	b _080BEDEC
	.align 2, 0
_080BEDD4: .4byte 0x00000FD3
_080BEDD8: .4byte 0x00000EBC
_080BEDDC: .4byte 0x08DAA8D8
_080BEDE0: .4byte 0x00000C78
_080BEDE4:
	ldr r1, _080BEDF4 @ =0x00000C78
	adds r0, r5, r1
	bl FUN_080b9724
_080BEDEC:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BEDF4: .4byte 0x00000C78

	thumb_func_start FUN_080bedf8
FUN_080bedf8: @ 0x080BEDF8
	push {r4, lr}
	movs r4, #0
_080BEDFC:
	adds r0, r4, #0
	bl GetValuableItemID
	subs r0, #0x38
	cmp r0, #7
	bhi _080BEE0C
	adds r0, r4, #0
	b _080BEE14
_080BEE0C:
	adds r4, #1
	cmp r4, #0xf
	ble _080BEDFC
	movs r0, #0x38
_080BEE14:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080bee1c
FUN_080bee1c: @ 0x080BEE1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	mov sb, r0
	bl FUN_080bedf8
	adds r6, r0, #0
	bl GetValuableItemID
	adds r4, r0, #0
	adds r1, r6, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	mov r5, sb
	adds r5, #0x80
	adds r0, r5, r0
	ldr r1, [r0]
	movs r2, #1
	mov r8, r2
	orrs r1, r2
	str r1, [r0]
	str r2, [sp, #0x2c]
	adds r0, r4, #0
	adds r0, #0x68
	str r0, [sp, #0x34]
	ldr r0, _080BEEE8 @ =0x000002DF
	mov sl, r0
	str r0, [sp, #0x3c]
	add r0, sp, #0xc
	adds r1, r6, #0
	bl FUN_080b9938
	add r7, sp, #0x1c
	subs r4, #0x28
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_080b9938
	ldr r2, _080BEEEC @ =0x00000FD6
	add r2, sb
	ldrb r1, [r2]
	adds r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r5, r5, r0
	ldr r0, [r5]
	mov r1, r8
	orrs r0, r1
	str r0, [r5]
	add r6, sp, #0x2c
	str r1, [r6, #4]
	ldrb r0, [r2]
	add r0, sb
	ldr r1, _080BEEF0 @ =0x00000EBC
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #0x68
	add r5, sp, #0x34
	str r0, [r5, #4]
	add r4, sp, #0x3c
	mov r0, sl
	str r0, [r4, #4]
	add r0, sp, #0x14
	ldrb r1, [r2]
	bl FUN_080b9938
	add r0, sp, #0x24
	ldr r1, _080BEEF4 @ =0x00000FD3
	add r1, sb
	ldrb r1, [r1]
	bl FUN_080b9938
	ldr r1, _080BEEF8 @ =0x00000EDC
	add sb, r1
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	mov r0, sb
	adds r1, r6, #0
	add r2, sp, #0xc
	adds r3, r7, #0
	bl FUN_080b9a28
	ldr r0, _080BEEFC @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BEEE8: .4byte 0x000002DF
_080BEEEC: .4byte 0x00000FD6
_080BEEF0: .4byte 0x00000EBC
_080BEEF4: .4byte 0x00000FD3
_080BEEF8: .4byte 0x00000EDC
_080BEEFC: .4byte 0x0000038A

	thumb_func_start FUN_080bef00
FUN_080bef00: @ 0x080BEF00
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	cmp r1, #0
	bne _080BEF1A
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080BEF80
_080BEF1A:
	movs r2, #0
	ldr r0, _080BEF30 @ =0x00000FD3
	adds r4, r5, r0
	adds r0, #3
	adds r1, r5, r0
	ldrb r0, [r4]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BEF34
	movs r2, #4
	b _080BEF56
	.align 2, 0
_080BEF30: .4byte 0x00000FD3
_080BEF34:
	ldr r1, _080BEF6C @ =0x00000FD1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BEF56
	ldrb r0, [r4]
	bl GetValuableItemID
	adds r6, r0, #0
	ldrb r4, [r4]
	bl FUN_080bedf8
	movs r2, #4
	cmp r4, r0
	beq _080BEF56
	asrs r0, r6, #0x1f
	ands r2, r0
_080BEF56:
	cmp r2, #4
	bne _080BEF70
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #7
	bl FUN_080b98c0
	b _080BEF80
	.align 2, 0
_080BEF6C: .4byte 0x00000FD1
_080BEF70:
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080BEF80:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bef88
FUN_080bef88: @ 0x080BEF88
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080BEFBC @ =0x00000FD3
	adds r5, r4, r0
	ldr r2, _080BEFC0 @ =0x00000FD6
	adds r1, r4, r2
	ldrb r0, [r5]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BEFC8
	bl FUN_080bedf8
	strb r0, [r5]
	movs r1, #3
	ands r1, r0
	ldr r2, _080BEFC4 @ =0x00000FD1
	adds r0, r4, r2
	strb r1, [r0]
	ldrb r0, [r5]
	lsrs r0, r0, #2
	adds r2, #1
	adds r1, r4, r2
	strb r0, [r1]
_080BEFB6:
	movs r0, #4
	b _080BEFEA
	.align 2, 0
_080BEFBC: .4byte 0x00000FD3
_080BEFC0: .4byte 0x00000FD6
_080BEFC4: .4byte 0x00000FD1
_080BEFC8:
	ldr r1, _080BEFF0 @ =0x00000FD1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BEFE8
	ldrb r0, [r5]
	bl GetValuableItemID
	adds r6, r0, #0
	ldrb r4, [r5]
	bl FUN_080bedf8
	cmp r4, r0
	beq _080BEFB6
	cmp r6, #0
	blt _080BEFB6
_080BEFE8:
	movs r0, #0
_080BEFEA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BEFF0: .4byte 0x00000FD1

	thumb_func_start FUN_080beff4
FUN_080beff4: @ 0x080BEFF4
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xc2
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xfd
	lsls r0, r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r0, _080BF050 @ =0x00000BB8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #0x1d
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FUN_080beb6c
	adds r0, r5, #0
	bl FUN_080bec1c
	adds r0, r5, #0
	bl FUN_080bed90
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bef00
	ldr r1, _080BF054 @ =FUN_080bf058
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080beb00
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BF050: .4byte 0x00000BB8
_080BF054: .4byte FUN_080bf058

	thumb_func_start FUN_080bf058
FUN_080bf058: @ 0x080BF058
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, _080BF0B0 @ =0x030044E0
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080BF0B8
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080beaf4
	ldr r1, _080BF0B4 @ =0x00000BB8
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BF08C
	b _080BF1B8
_080BF08C:
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r2, #0x87
	lsls r2, r2, #5
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080BF0A8
	b _080BF1B8
_080BF0A8:
	movs r0, #0
	strb r0, [r1]
	b _080BF1B8
	.align 2, 0
_080BF0B0: .4byte 0x030044E0
_080BF0B4: .4byte 0x00000BB8
_080BF0B8:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080beaf4
	ldr r0, _080BF11C @ =0x00000BB8
	adds r6, r5, r0
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r6, #0
	bl FUN_082372cc
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080BF18C
	ldr r1, _080BF120 @ =0x00000FD3
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r2, _080BF124 @ =0x00000EBC
	adds r0, r0, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r3, #1
	cmp r1, #0
	blt _080BF110
	ldr r0, _080BF128 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x91
	lsls r4, r4, #4
	adds r0, r0, r4
	movs r4, #0
	ldrsh r2, [r0, r4]
	ldr r0, _080BF12C @ =0x08DAA8D8
	lsls r1, r1, #4
	adds r0, #0xc
	adds r1, r1, r0
	ldr r0, [r1]
	cmp r2, r0
	bhs _080BF10C
	movs r3, #0
_080BF10C:
	cmp r3, #0
	bne _080BF130
_080BF110:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BF1B8
	.align 2, 0
_080BF11C: .4byte 0x00000BB8
_080BF120: .4byte 0x00000FD3
_080BF124: .4byte 0x00000EBC
_080BF128: .4byte 0x030046A0
_080BF12C: .4byte 0x08DAA8D8
_080BF130:
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0xfd
	lsls r0, r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fd8
	movs r1, #0xc2
	lsls r1, r1, #4
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080BF180 @ =0x00000C38
	adds r2, r5, r0
	ldr r1, _080BF184 @ =0x00000BD8
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r4, #0
	movs r1, #0x3c
	bl FUN_080b9d94
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bef00
	ldr r1, _080BF188 @ =0x080BF1C1
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080beb00
	b _080BF1B8
	.align 2, 0
_080BF180: .4byte 0x00000C38
_080BF184: .4byte 0x00000BD8
_080BF188: .4byte 0x080BF1C1
_080BF18C:
	movs r2, #0xfd
	lsls r2, r2, #4
	adds r4, r5, r2
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080BF1B8
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080beb6c
	adds r0, r5, #0
	bl FUN_080bed90
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bef00
_080BF1B8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BF1C0:
	.byte 0x70, 0xB5, 0x05, 0x1C, 0x17, 0x48, 0x41, 0x88, 0x01, 0x20, 0x08, 0x40, 0x00, 0x28, 0x38, 0xD0
	.byte 0x28, 0x1C, 0xFF, 0xF7, 0xD9, 0xFE, 0x04, 0x1C, 0x80, 0x21, 0x49, 0x01, 0x68, 0x18, 0x01, 0x22
	.byte 0x52, 0x42, 0x11, 0x1C, 0xFA, 0xF7, 0x6C, 0xFB, 0x04, 0x2C, 0x25, 0xD1, 0x0E, 0x48, 0x81, 0xF1
	.byte 0x77, 0xFA, 0x0E, 0x49, 0x68, 0x18, 0x02, 0x68, 0x28, 0x1C, 0x00, 0x21, 0x00, 0x23, 0xFF, 0xF7
	.byte 0x93, 0xFC, 0x0B, 0x49, 0x68, 0x18, 0x2C, 0x1C, 0x18, 0x34, 0x71, 0x31, 0x6A, 0x18, 0x21, 0x1C
	.byte 0x01, 0x23, 0xFA, 0xF7, 0x95, 0xFA, 0x07, 0x49, 0x28, 0x1C, 0x00, 0x22, 0xFF, 0xF7, 0x70, 0xFC
	.byte 0x32, 0xE0, 0x00, 0x00, 0xE0, 0x44, 0x00, 0x03, 0x07, 0x01, 0x00, 0x00, 0xC4, 0x0E, 0x00, 0x00
	.byte 0x58, 0x0E, 0x00, 0x00, 0x9D, 0xF2, 0x0B, 0x08, 0xC9, 0x20, 0x40, 0x00, 0x81, 0xF1, 0x50, 0xFA
	.byte 0x09, 0xE0, 0x02, 0x20, 0x08, 0x40, 0x00, 0x28, 0x08, 0xD0, 0xDE, 0x20, 0x81, 0xF1, 0x48, 0xFA
	.byte 0x28, 0x1C, 0xFF, 0xF7, 0xCF, 0xFE, 0x2C, 0x1C, 0x18, 0x34, 0x15, 0xE0, 0xFD, 0x20, 0x00, 0x01
	.byte 0x2E, 0x18, 0x30, 0x1C, 0xFA, 0xF7, 0x84, 0xFE, 0x2C, 0x1C, 0x18, 0x34, 0x00, 0x28, 0x0B, 0xD0
	.byte 0x09, 0x48, 0x29, 0x18, 0x30, 0x1C, 0xFA, 0xF7, 0xA5, 0xFE, 0x28, 0x1C, 0xFF, 0xF7, 0x76, 0xFC
	.byte 0x28, 0x1C, 0x01, 0x21, 0xFF, 0xF7, 0x3C, 0xFE, 0x03, 0x49, 0x68, 0x18, 0x21, 0x1C, 0x78, 0xF1
	.byte 0x1D, 0xF8, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0xB8, 0x0B, 0x00, 0x00

	thumb_func_start FUN_080bf29c
FUN_080bf29c: @ 0x080BF29C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BF2CC @ =0x00000E58
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BF2D0 @ =0x00000EC9
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BF2D8
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080bee1c
	ldr r1, _080BF2D4 @ =0x080BF2F1
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080beb00
	b _080BF2E8
	.align 2, 0
_080BF2CC: .4byte 0x00000E58
_080BF2D0: .4byte 0x00000EC9
_080BF2D4: .4byte 0x080BF2F1
_080BF2D8:
	cmp r0, #0
	bne _080BF2E8
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080beff4
_080BF2E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF2F0:
	.byte 0xF0, 0xB5, 0x47, 0x46, 0x80, 0xB4, 0x07, 0x1C, 0x21, 0x49, 0x78, 0x18, 0xFA, 0xF7, 0xEE, 0xFB
	.byte 0x00, 0x28, 0x37, 0xD0, 0xFF, 0xF7, 0x78, 0xFD, 0x06, 0x1C, 0x82, 0xF1, 0xB1, 0xFF, 0x80, 0x46
	.byte 0x1C, 0x49, 0x78, 0x18, 0x00, 0x78, 0x10, 0x38, 0x1B, 0x49, 0x7D, 0x18, 0x28, 0x18, 0x00, 0x24
	.byte 0x04, 0x57, 0x30, 0x1C, 0x82, 0xF1, 0xD4, 0xFF, 0x18, 0x49, 0x78, 0x18, 0x00, 0x78, 0x21, 0x1C
	.byte 0x82, 0xF1, 0xB4, 0xFF, 0x16, 0x48, 0x02, 0x68, 0x91, 0x20, 0x00, 0x01, 0x12, 0x18, 0x15, 0x48
	.byte 0x21, 0x01, 0x0C, 0x30, 0x09, 0x18, 0x09, 0x68, 0x10, 0x88, 0x40, 0x1A, 0x10, 0x80, 0x40, 0x46
	.byte 0x38, 0x38, 0x28, 0x18, 0x41, 0x46, 0x01, 0x70, 0x38, 0x3C, 0x2D, 0x19, 0xFF, 0x20, 0x28, 0x70
	.byte 0x0D, 0x48, 0x39, 0x18, 0x01, 0x20, 0x08, 0x70, 0x0C, 0x48, 0x81, 0xF1, 0xB9, 0xF9, 0x38, 0x1C
	.byte 0xFF, 0xF7, 0x40, 0xFE, 0x08, 0xBC, 0x98, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0xDC, 0x0E, 0x00, 0x00, 0xD6, 0x0F, 0x00, 0x00, 0xCC, 0x0E, 0x00, 0x00, 0xD3, 0x0F, 0x00, 0x00
	.byte 0xA0, 0x46, 0x00, 0x03, 0xD8, 0xA8, 0xDA, 0x08, 0xE1, 0x10, 0x00, 0x00, 0x11, 0x01, 0x00, 0x00

	thumb_func_start FUN_080bf3a0
FUN_080bf3a0: @ 0x080BF3A0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0xfd
	lsls r0, r0, #4
	adds r5, r4, r0
	movs r0, #0x1d
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #4
	movs r3, #0
	bl FUN_080b9ff8
	ldr r0, _080BF3F4 @ =0x00000BB8
	adds r1, r4, r0
	adds r0, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080bec1c
	adds r0, r4, #0
	bl FUN_080bed90
	adds r0, r4, #0
	bl FUN_080beb6c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080bef00
	ldr r1, _080BF3F8 @ =FUN_080bf058
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080beb00
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BF3F4: .4byte 0x00000BB8
_080BF3F8: .4byte FUN_080bf058

	thumb_func_start FUN_080bf3fc
FUN_080bf3fc: @ 0x080BF3FC
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080BF44C @ =0x0000C091
	ldr r1, _080BF450 @ =0x00009F57
	bl GetFile
	adds r2, r0, #0
	ldr r0, _080BF454 @ =0x00000EB8
	adds r4, r4, r0
	str r2, [r4]
	movs r5, #0
	str r5, [sp, #0xc]
	str r5, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	ldr r1, [r4]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BF44C: .4byte 0x0000C091
_080BF450: .4byte 0x00009F57
_080BF454: .4byte 0x00000EB8

	thumb_func_start FUN_080bf458
FUN_080bf458: @ 0x080BF458
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080BF480 @ =0x000092B3
	ldr r1, _080BF484 @ =0x0000A41A
	bl GetFile
	ldr r1, _080BF488 @ =0x00000EBC
	adds r4, r4, r1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, _080BF48C @ =0x030043F0
	ldr r2, _080BF490 @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF480: .4byte 0x000092B3
_080BF484: .4byte 0x0000A41A
_080BF488: .4byte 0x00000EBC
_080BF48C: .4byte 0x030043F0
_080BF490: .4byte 0x04000018

	thumb_func_start FUN_080bf494
FUN_080bf494: @ 0x080BF494
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r4, _080BF6E4 @ =0x0000CB05
	ldr r1, _080BF6E8 @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x38
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	movs r6, #0x38
	adds r6, r6, r7
	mov sb, r6
	mov r0, sb
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080BF6EC @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x18
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r7, #0
	adds r0, #0x18
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080BF6F0 @ =0x0000414C
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x58
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r4, r5}
	stm r1!, {r4, r5}
	adds r4, r7, #0
	adds r4, #0x58
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r1, _080BF6F4 @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x78
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r6, sp, #0x10
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0x29
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r4, #0
	add r6, sp, #0x10
	mov r8, r4
	mov sl, sb
	adds r5, r7, #0
	adds r5, #0xd8
_080BF54A:
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r6, #2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r6]
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r2, #0x68
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xf
	ble _080BF54A
	movs r4, #0
	adds r1, r7, #0
	adds r1, #0x18
	str r1, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x58
	str r2, [sp, #0x18]
	add r6, sp, #0x10
	mov sb, r4
	movs r3, #0xdb
	lsls r3, r3, #3
	adds r5, r7, r3
_080BF59E:
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r6, #2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r6]
	mov r0, sb
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0x3c
	mov r8, r1
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x68
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xb
	ble _080BF59E
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	adds r5, r0, #0
	movs r0, #0x80
	strh r0, [r5, #2]
	ldr r2, _080BF6F8 @ =0x00000B58
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, sl
	movs r2, #0xcf
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r6, _080BF6FC @ =0x00000C18
	adds r0, r7, r6
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0x3c
	movs r3, #0x31
	bl FUN_0822f3fc
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x20
	strh r0, [r5, #2]
	ldr r3, _080BF700 @ =0x00000BB8
	adds r5, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r6, r8
	str r6, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0x39
	movs r3, #0x30
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _080BF704 @ =0x00000C78
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x18
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0xb
	add r1, sp, #0x10
	strh r0, [r1]
	adds r6, r1, #0
	ldr r3, _080BF708 @ =0x00000CD8
	adds r5, r7, r3
	mov r8, r4
	movs r4, #3
_080BF678:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0x3c
	mov sb, r1
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x19
	movs r3, #0x30
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #6
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BF678
	movs r1, #0
	add r0, sp, #0x10
	strh r1, [r0]
	strh r1, [r0, #2]
	ldr r2, _080BF70C @ =0x00000E58
	adds r0, r7, r2
	str r1, [sp]
	str r1, [sp, #4]
	mov r3, sb
	str r3, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0x94
	movs r3, #0x11
	bl FUN_0822f3fc
	ldr r5, _080BF710 @ =0x00000EDC
	adds r0, r7, r5
	bl FUN_080b99a0
	movs r6, #0x80
	lsls r6, r6, #5
	adds r0, r7, r6
	bl FUN_080b9814
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BF6E4: .4byte 0x0000CB05
_080BF6E8: .4byte 0x00005D04
_080BF6EC: .4byte 0x0000B343
_080BF6F0: .4byte 0x0000414C
_080BF6F4: .4byte 0xFFFF0000
_080BF6F8: .4byte 0x00000B58
_080BF6FC: .4byte 0x00000C18
_080BF700: .4byte 0x00000BB8
_080BF704: .4byte 0x00000C78
_080BF708: .4byte 0x00000CD8
_080BF70C: .4byte 0x00000E58
_080BF710: .4byte 0x00000EDC

	thumb_func_start FUN_080bf714
FUN_080bf714: @ 0x080BF714
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BF72E
	bl FUN_0823d340
	movs r2, #0xec
	lsls r2, r2, #4
	adds r1, r4, r2
	str r0, [r1]
_080BF72E:
	bl FUN_08049f5c
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	ldr r0, _080BF750 @ =0x0000A41A
	bl FUN_08047dc0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF750: .4byte 0x0000A41A

	thumb_func_start FUN_080bf754
FUN_080bf754: @ 0x080BF754
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r0, #0x43
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BF76A
	bl Script_GetValue
	adds r5, r0, #0
	b _080BF76C
_080BF76A:
	movs r5, #0
_080BF76C:
	bl FUN_080bedf8
	bl GetValuableItemID
	adds r7, r0, #0
	movs r0, #0x4f
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BF7D2
	movs r4, #0
	cmp r4, r5
	bge _080BF7A8
_080BF786:
	bl Script_GetValue
	adds r1, r0, #0
	ldr r2, _080BF7EC @ =0x00000ECC
	adds r0, r6, r2
	adds r2, r0, r4
	strb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r7, r0
	bne _080BF7A2
	movs r0, #0xff
	orrs r1, r0
	strb r1, [r2]
_080BF7A2:
	adds r4, #1
	cmp r4, r5
	blt _080BF786
_080BF7A8:
	cmp r4, #0xb
	bgt _080BF7C0
	ldr r0, _080BF7EC @ =0x00000ECC
	adds r2, r6, r0
	movs r3, #0xff
_080BF7B2:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #0xb
	ble _080BF7B2
_080BF7C0:
	ldr r2, _080BF7F0 @ =0x00000ED4
	adds r1, r6, r2
	movs r4, #3
_080BF7C6:
	ldrb r0, [r1]
	strb r0, [r1, #4]
	adds r1, #1
	subs r4, #1
	cmp r4, #0
	bge _080BF7C6
_080BF7D2:
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BF7E6
	bl FUN_0823d340
	ldr r2, _080BF7F4 @ =0x00000EC4
	adds r1, r6, r2
	str r0, [r1]
_080BF7E6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BF7EC: .4byte 0x00000ECC
_080BF7F0: .4byte 0x00000ED4
_080BF7F4: .4byte 0x00000EC4

	thumb_func_start FUN_080bf7f8
FUN_080bf7f8: @ 0x080BF7F8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x65
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080BF818
	bl Script_GetValue
	ldr r2, _080BF814 @ =0x000010E4
	adds r1, r4, r2
	str r0, [r1]
	b _080BF81E
	.align 2, 0
_080BF814: .4byte 0x000010E4
_080BF818:
	ldr r2, _080BF824 @ =0x000010E4
	adds r0, r4, r2
	str r1, [r0]
_080BF81E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF824: .4byte 0x000010E4

	thumb_func_start FUN_080bf828
FUN_080bf828: @ 0x080BF828
	push {lr}
	adds r2, r0, #0
	ldr r0, _080BF84C @ =0x00000ECA
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BF846
	ldr r1, _080BF850 @ =FUN_080bf854
	adds r0, r2, #0
	bl FUN_080beadc
_080BF846:
	pop {r0}
	bx r0
	.align 2, 0
_080BF84C: .4byte 0x00000ECA
_080BF850: .4byte FUN_080bf854

	thumb_func_start FUN_080bf854
FUN_080bf854: @ 0x080BF854
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080BF898 @ =0x00000EC8
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080BF8AC
	ldr r0, _080BF89C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BF8AC
	ldr r0, _080BF8A0 @ =0x00000119
	bl PlaySound_082406e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BF8A4 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080BF8A8 @ =FUN_080bf8c4
	adds r0, r4, #0
	bl FUN_080beadc
	b _080BF8B8
	.align 2, 0
_080BF898: .4byte 0x00000EC8
_080BF89C: .4byte 0x030044E0
_080BF8A0: .4byte 0x00000119
_080BF8A4: .4byte 0x0000FFFF
_080BF8A8: .4byte FUN_080bf8c4
_080BF8AC:
	ldr r1, _080BF8C0 @ =0x000010EC
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080BF8B8:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF8C0: .4byte 0x000010EC

	thumb_func_start FUN_080bf8c4
FUN_080bf8c4: @ 0x080BF8C4
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080BF91C @ =0x00000ECA
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BF914
	ldr r1, _080BF920 @ =0x000010E4
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080BF90E
	ldr r1, _080BF924 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	ldr r1, _080BF928 @ =0x000010E1
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp, #4]
	add r1, sp, #8
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_080BF90E:
	adds r0, r4, #0
	bl KillEntity
_080BF914:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF91C: .4byte 0x00000ECA
_080BF920: .4byte 0x000010E4
_080BF924: .4byte 0xFFFF0000
_080BF928: .4byte 0x000010E1

	thumb_func_start FUN_080bf92c
FUN_080bf92c: @ 0x080BF92C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x87
	lsls r0, r0, #5
	adds r5, r4, r0
	ldrb r0, [r5]
	bl FUN_080b94cc
	ldrb r0, [r5]
	bl FUN_080b9400
	ldr r1, _080BF958 @ =0x000010E8
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080BF958: .4byte 0x000010E8

	thumb_func_start FUN_080bf95c
FUN_080bf95c: @ 0x080BF95C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x78
	movs r5, #0x25
_080BF966:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BF966
	ldr r1, _080BF990 @ =0x00000EDC
	adds r0, r6, r1
	bl FUN_080b9a0c
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r6, r1
	bl FUN_080b9894
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BF990: .4byte 0x00000EDC

	thumb_func_start Entity571D_Init
Entity571D_Init: @ 0x080BF994
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_080bf754
	adds r0, r4, #0
	bl FUN_080bf3fc
	adds r0, r4, #0
	bl FUN_080bf458
	adds r0, r4, #0
	bl FUN_080bf494
	adds r0, r4, #0
	bl FUN_080bf714
	adds r0, r4, #0
	bl FUN_080bf7f8
	ldr r1, _080BFA00 @ =0x000010E1
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080BFA04 @ =0x000010E2
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BFA08 @ =0x0000FFFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r4, #0
	bl FUN_080bf3a0
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080BFA0C @ =FUN_080bf828
	adds r0, r4, #0
	bl FUN_080beadc
	movs r0, #0
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080BFA00: .4byte 0x000010E1
_080BFA04: .4byte 0x000010E2
_080BFA08: .4byte 0x0000FFFF
_080BFA0C: .4byte FUN_080bf828

	thumb_func_start Entity571D_Create
Entity571D_Create: @ 0x080BFA10
	push {r4, lr}
	ldr r1, _080BFA3C @ =0x000010F0
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080BFA48
	ldr r1, _080BFA40 @ =FUN_080bf92c
	ldr r2, _080BFA44 @ =FUN_080bf95c
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity571D_Init
	cmp r0, #0
	bge _080BFA48
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080BFA4A
	.align 2, 0
_080BFA3C: .4byte 0x000010F0
_080BFA40: .4byte FUN_080bf92c
_080BFA44: .4byte FUN_080bf95c
_080BFA48:
	adds r0, r4, #0
_080BFA4A:
	pop {r4}
	pop {r1}
	bx r1
_080BFA50:
	.byte 0x01, 0x49, 0x00, 0x20, 0x08, 0x60, 0x70, 0x47, 0x58, 0x01, 0x00, 0x03

	thumb_func_start FUN_080bfa5c
FUN_080bfa5c: @ 0x080BFA5C
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080BFA70 @ =0x000005B6
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080BFA70: .4byte 0x000005B6

	thumb_func_start FUN_080bfa74
FUN_080bfa74: @ 0x080BFA74
	push {r4, r5, lr}
	movs r1, #0
	ldr r5, _080BFAA0 @ =0x03002BE0
	adds r4, r5, #0
	ldr r3, _080BFAA4 @ =0x0000040C
	movs r2, #0
_080BFA80:
	ldr r0, [r4]
	adds r0, r0, r3
	adds r0, r0, r1
	strb r2, [r0]
	adds r1, #1
	cmp r1, #0x1f
	ble _080BFA80
	ldr r0, [r5]
	ldr r1, _080BFAA8 @ =0x0000042E
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BFAA0: .4byte 0x03002BE0
_080BFAA4: .4byte 0x0000040C
_080BFAA8: .4byte 0x0000042E

	thumb_func_start FUN_080bfaac
FUN_080bfaac: @ 0x080BFAAC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r6, _080BFB24 @ =0x03002BE0
	ldr r1, [r6]
	movs r4, #1
	str r4, [r1, #0x1c]
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r2, #0
	movs r0, #0x20
	strb r0, [r1]
	ldr r0, [r6]
	ldr r1, _080BFB28 @ =0x0000037D
	adds r0, r0, r1
	strb r2, [r0]
	ldr r1, [r6]
	movs r7, #0
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r1, #0x2c]
	ldr r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #0x2e]
	ldr r1, [r6]
	movs r0, #0xb0
	lsls r0, r0, #3
	strh r0, [r1, #0x30]
	ldr r0, [r6]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #7
	strb r1, [r0]
	ldr r0, [r6]
	ldr r1, _080BFB2C @ =0x000002E6
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r6]
	adds r1, #1
	adds r0, r0, r1
	strb r4, [r0]
	bl FUN_080bfa74
	ldr r0, [r6]
	ldr r1, _080BFB30 @ =0x0000042C
	adds r0, r0, r1
	strh r4, [r0]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r5, r5, r0
	ldrh r0, [r5]
	cmp r0, #1
	beq _080BFB48
	cmp r0, #1
	bgt _080BFB34
	cmp r0, #0
	beq _080BFB3E
	b _080BFB6E
	.align 2, 0
_080BFB24: .4byte 0x03002BE0
_080BFB28: .4byte 0x0000037D
_080BFB2C: .4byte 0x000002E6
_080BFB30: .4byte 0x0000042C
_080BFB34:
	cmp r0, #2
	beq _080BFB58
	cmp r0, #3
	beq _080BFB62
	b _080BFB6E
_080BFB3E:
	ldr r0, [r6]
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x20
	b _080BFB6A
_080BFB48:
	ldr r0, [r6]
	ldr r1, _080BFB54 @ =0x0000042C
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x40
	b _080BFB6A
	.align 2, 0
_080BFB54: .4byte 0x0000042C
_080BFB58:
	ldr r0, [r6]
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x10
	b _080BFB6A
_080BFB62:
	ldr r0, [r6]
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x80
_080BFB6A:
	orrs r1, r2
	strh r1, [r0]
_080BFB6E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bfb74
FUN_080bfb74: @ 0x080BFB74
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0xb4
	ldrh r0, [r3]
	lsrs r0, r0, #3
	adds r1, r2, #0
	adds r1, #0x6c
	strh r0, [r1, #0x10]
	adds r0, r2, #0
	adds r0, #0xb6
	ldrh r0, [r0]
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080BFB9E
	movs r0, #0
	strh r0, [r3]
_080BFB9E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bfba4
FUN_080bfba4: @ 0x080BFBA4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080BFC08 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x86
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080BFBC6
	adds r1, r0, #0
	movs r0, #0x80
	bl Div
	adds r1, r0, #0
	cmp r1, #0
	bgt _080BFBC8
_080BFBC6:
	movs r1, #1
_080BFBC8:
	adds r2, r4, #0
	adds r2, #0x68
	ldrh r0, [r2]
	adds r1, r0, r1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _080BFBE0
	adds r0, r1, #0
	subs r0, #0xc
	strh r0, [r2]
_080BFBE0:
	ldrh r0, [r2]
	lsrs r0, r0, #2
	strh r0, [r4, #0x30]
	ldr r1, _080BFC0C @ =0x0000057C
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080BFC3C
	ldr r0, _080BFC08 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _080BFC10 @ =0x0000042E
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #1
	bhi _080BFC18
	ldr r0, _080BFC14 @ =0x0000023A
	bl PlaySound_082406e0
	b _080BFC3C
	.align 2, 0
_080BFC08: .4byte 0x03002BE0
_080BFC0C: .4byte 0x0000057C
_080BFC10: .4byte 0x0000042E
_080BFC14: .4byte 0x0000023A
_080BFC18:
	cmp r0, #3
	bhi _080BFC28
	ldr r0, _080BFC24 @ =0x0000023B
	bl PlaySound_082406e0
	b _080BFC3C
	.align 2, 0
_080BFC24: .4byte 0x0000023B
_080BFC28:
	cmp r0, #5
	bhi _080BFC36
	movs r0, #0x8f
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080BFC3C
_080BFC36:
	ldr r0, _080BFC58 @ =0x0000023D
	bl PlaySound_082406e0
_080BFC3C:
	ldr r0, _080BFC5C @ =0x0000057C
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _080BFC52
	movs r0, #0
	strh r0, [r1]
_080BFC52:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BFC58: .4byte 0x0000023D
_080BFC5C: .4byte 0x0000057C

	thumb_func_start FUN_080bfc60
FUN_080bfc60: @ 0x080BFC60
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _080BFCE0 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [sp, #0xc]
	mov r6, sp
	movs r3, #0xfe
	lsls r3, r3, #2
	adds r4, r7, r3
	movs r5, #3
_080BFCB8:
	ldm r6!, {r2}
	adds r2, #0x1e
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r3, #0xde
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BFCB8
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BFCE0: .4byte 0x030046A0

	thumb_func_start FUN_080bfce4
FUN_080bfce4: @ 0x080BFCE4
	push {lr}
	movs r3, #2
	rsbs r3, r3, #0
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #4
_080BFCF2:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080BFCF2
	pop {r0}
	bx r0

	thumb_func_start FUN_080bfd04
FUN_080bfd04: @ 0x080BFD04
	push {lr}
	movs r3, #1
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #4
_080BFD10:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080BFD10
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bfd24
FUN_080bfd24: @ 0x080BFD24
	push {lr}
	adds r1, r0, #0
	ldr r0, _080BFD44 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _080BFD48 @ =0x0000042E
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #3
	bls _080BFD4C
	movs r0, #0xb1
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	b _080BFD54
	.align 2, 0
_080BFD44: .4byte 0x03002BE0
_080BFD48: .4byte 0x0000042E
_080BFD4C:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r0, #0
_080BFD54:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bfd5c
FUN_080bfd5c: @ 0x080BFD5C
	push {lr}
	adds r2, r0, #0
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r3, _080BFD78 @ =0x0000058E
	adds r1, r2, r3
	ldrh r3, [r0]
	ldrh r1, [r1]
	cmp r3, r1
	bls _080BFD7C
	movs r0, #0xa
	b _080BFDA6
	.align 2, 0
_080BFD78: .4byte 0x0000058E
_080BFD7C:
	ldr r1, _080BFD8C @ =0x0000058C
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r3, r0
	bls _080BFD90
	movs r0, #5
	b _080BFDA6
	.align 2, 0
_080BFD8C: .4byte 0x0000058C
_080BFD90:
	ldr r1, _080BFDA0 @ =0x0000058A
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r3, r0
	bhi _080BFDA4
	movs r0, #1
	b _080BFDA6
	.align 2, 0
_080BFDA0: .4byte 0x0000058A
_080BFDA4:
	movs r0, #2
_080BFDA6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080bfdac
FUN_080bfdac: @ 0x080BFDAC
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrh r1, [r0]
	cmp r1, #1
	bne _080BFDE0
	movs r2, #0x30
	movs r1, #5
	ldr r4, _080BFDDC @ =0x0000034A
	adds r0, r3, r4
_080BFDC4:
	strh r2, [r0]
	subs r0, #0x2c
	subs r1, #1
	cmp r1, #0
	bge _080BFDC4
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #4
	strh r0, [r1]
	b _080BFE40
	.align 2, 0
_080BFDDC: .4byte 0x0000034A
_080BFDE0:
	cmp r1, #2
	bne _080BFDEE
	movs r2, #0x9f
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r0, #4
	b _080BFE08
_080BFDEE:
	cmp r1, #5
	bne _080BFDFC
	movs r4, #0x9f
	lsls r4, r4, #2
	adds r0, r3, r4
	strh r1, [r0, #0x10]
	b _080BFE0A
_080BFDFC:
	cmp r1, #0xa
	bne _080BFE0A
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #6
_080BFE08:
	strh r0, [r1, #0x10]
_080BFE0A:
	movs r7, #2
	rsbs r7, r7, #0
	adds r2, r3, #0
	movs r4, #0x94
	lsls r4, r4, #2
	adds r1, r3, r4
	adds r4, r3, #0
	adds r4, #0xdc
	ldr r6, _080BFE48 @ =0x0000026E
	movs r5, #0x38
_080BFE1E:
	ldr r0, [r1]
	ands r0, r7
	str r0, [r1]
	adds r0, r2, r6
	strh r5, [r0]
	adds r2, #0x2c
	adds r1, #0x2c
	cmp r2, r4
	ble _080BFE1E
	movs r1, #0xdd
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r1, #0xa
	strh r1, [r0]
	ldr r0, _080BFE4C @ =0x0000028B
	bl PlaySound_082406e0
_080BFE40:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BFE48: .4byte 0x0000026E
_080BFE4C: .4byte 0x0000028B

	thumb_func_start FUN_080bfe50
FUN_080bfe50: @ 0x080BFE50
	push {r4, r5, lr}
	adds r1, r0, #0
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r4, r1, r0
	ldrh r3, [r4]
	adds r2, r3, #0
	cmp r2, #0
	beq _080BFEEC
	movs r5, #0xb2
	lsls r5, r5, #3
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #1
	bne _080BFEAC
	subs r0, r3, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080BFE92
	movs r2, #1
	movs r0, #0x94
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r3, #5
_080BFE82:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080BFE82
	b _080BFEEC
_080BFE92:
	ldr r5, _080BFEA8 @ =0x0000026E
	adds r1, r1, r5
	movs r3, #5
_080BFE98:
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	adds r1, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080BFE98
	b _080BFEEC
	.align 2, 0
_080BFEA8: .4byte 0x0000026E
_080BFEAC:
	cmp r2, #3
	bls _080BFECC
	ldr r0, _080BFEC8 @ =0x0000026E
	adds r2, r1, r0
	movs r3, #5
_080BFEB6:
	ldrh r0, [r2]
	subs r0, #2
	strh r0, [r2]
	adds r2, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080BFEB6
	b _080BFEE0
	.align 2, 0
_080BFEC8: .4byte 0x0000026E
_080BFECC:
	ldr r5, _080BFEF4 @ =0x0000026E
	adds r2, r1, r5
	movs r3, #5
_080BFED2:
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
	adds r2, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080BFED2
_080BFEE0:
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_080BFEEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BFEF4: .4byte 0x0000026E

	thumb_func_start FUN_080bfef8
FUN_080bfef8: @ 0x080BFEF8
	push {lr}
	movs r3, #1
	movs r2, #0x94
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #5
_080BFF04:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _080BFF04
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bff18
FUN_080bff18: @ 0x080BFF18
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080BFF44 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080BFF48 @ =0x0000042E
	adds r0, r0, r1
	ldrh r2, [r0]
	cmp r2, #7
	ble _080BFF2C
	movs r2, #7
_080BFF2C:
	movs r1, #0
	cmp r1, r2
	bge _080BFF56
	movs r4, #1
	movs r3, #2
	movs r6, #0x80
	lsls r6, r6, #1
	adds r0, r5, r6
_080BFF3C:
	cmp r1, #3
	bgt _080BFF4C
	strh r4, [r0, #0x10]
	b _080BFF4E
	.align 2, 0
_080BFF44: .4byte 0x03002BE0
_080BFF48: .4byte 0x0000042E
_080BFF4C:
	strh r3, [r0, #0x10]
_080BFF4E:
	adds r0, #0x2c
	adds r1, #1
	cmp r1, r2
	blt _080BFF3C
_080BFF56:
	cmp r1, #6
	bgt _080BFF72
	movs r2, #0
	movs r0, #0x2c
	muls r0, r1, r0
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r0, r0, r5
_080BFF68:
	strh r2, [r0, #0x10]
	adds r0, #0x2c
	adds r1, #1
	cmp r1, #6
	ble _080BFF68
_080BFF72:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bff78
FUN_080bff78: @ 0x080BFF78
	push {lr}
	movs r3, #2
	rsbs r3, r3, #0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r2, #6
_080BFF86:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _080BFF86
	pop {r0}
	bx r0

	thumb_func_start FUN_080bff98
FUN_080bff98: @ 0x080BFF98
	push {lr}
	movs r3, #1
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r2, #6
_080BFFA4:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _080BFFA4
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bffb8
FUN_080bffb8: @ 0x080BFFB8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080bfce4
	adds r0, r4, #0
	bl FUN_080bff78
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bffcc
FUN_080bffcc: @ 0x080BFFCC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080bfd04
	adds r0, r4, #0
	bl FUN_080bfef8
	adds r0, r4, #0
	bl FUN_080bff98
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BFFE8:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0xFF, 0xF7, 0x5E, 0xFD
	.byte 0x20, 0x1C, 0xFF, 0xF7, 0xE1, 0xFF, 0x05, 0x48, 0x21, 0x18, 0x20, 0x20, 0x08, 0x80, 0x04, 0x49
	.byte 0x20, 0x1C, 0xFF, 0xF7, 0x2B, 0xFD, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x7A, 0x05, 0x00, 0x00
	.byte 0x49, 0x02, 0x0C, 0x08

	thumb_func_start FUN_080c0014
FUN_080c0014: @ 0x080C0014
	push {r4, lr}
	sub sp, #0xc
	adds r2, r0, #0
	ldr r1, _080C004C @ =0x000005AC
	adds r0, r2, r1
	ldr r3, [r0]
	cmp r3, #0
	beq _080C0044
	ldr r1, _080C0050 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r4, sp
	str r4, [r1, #4]
	ldr r4, _080C0054 @ =0x0000057E
	adds r0, r2, r4
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r3, #0
	bl Script_ExecById
_080C0044:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C004C: .4byte 0x000005AC
_080C0050: .4byte 0xFFFF0000
_080C0054: .4byte 0x0000057E

	thumb_func_start FUN_080c0058
FUN_080c0058: @ 0x080C0058
	push {lr}
	sub sp, #0xc
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080C0080
	ldr r1, _080C0088 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_080C0080:
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_080C0088: .4byte 0xFFFF0000

	thumb_func_start FUN_080c008c
FUN_080c008c: @ 0x080C008C
	push {r4, lr}
	ldr r0, _080C00C8 @ =0x03000158
	ldr r3, [r0]
	cmp r3, #0
	beq _080C00C2
	ldr r2, _080C00CC @ =0x080BFFE9
	movs r0, #0
	movs r1, #0
	bl FUN_080a6180
	ldr r4, _080C00D0 @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #7
	bl FUN_0807b910
	ldr r1, [r4]
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r1, #0x2c]
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #0x2e]
	ldr r1, [r4]
	movs r0, #0xb0
	lsls r0, r0, #3
	strh r0, [r1, #0x30]
_080C00C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C00C8: .4byte 0x03000158
_080C00CC: .4byte 0x080BFFE9
_080C00D0: .4byte 0x03002BE0

	thumb_func_start FUN_080c00d4
FUN_080c00d4: @ 0x080C00D4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, _080C00EC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080C00F0 @ =0x0000042E
	adds r0, r0, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne _080C00F4
	movs r7, #0
	b _080C0106
	.align 2, 0
_080C00EC: .4byte 0x03002BE0
_080C00F0: .4byte 0x0000042E
_080C00F4:
	cmp r1, #3
	bhi _080C00FC
	movs r7, #1
	b _080C0106
_080C00FC:
	ldrh r0, [r0]
	subs r7, r0, #2
	subs r0, #3
	muls r0, r7, r0
	asrs r7, r0, #1
_080C0106:
	adds r0, r4, #0
	bl FUN_080bfd5c
	adds r5, r0, #0
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r6, r4, r2
	ldrh r0, [r6]
	cmp r0, r5
	beq _080C0146
	ldr r3, _080C0190 @ =0x000005A4
	adds r0, r4, r3
	ldr r2, [r0]
	cmp r2, #0
	beq _080C013E
	ldr r1, _080C0194 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	str r5, [sp]
	adds r0, r2, #0
	bl Script_ExecById
_080C013E:
	strh r5, [r6]
	adds r0, r4, #0
	bl FUN_080bfdac
_080C0146:
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r2, #0xb6
	lsls r2, r2, #3
	adds r1, r4, r2
	muls r0, r7, r0
	ldrh r3, [r1]
	adds r2, r0, r3
	strh r2, [r1]
	ldr r0, _080C0198 @ =0x000005B2
	adds r5, r4, r0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	ldrh r3, [r5]
	cmp r0, r3
	blo _080C019C
	movs r4, #0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r3
	blo _080C018C
	adds r3, r1, #0
	adds r2, r5, #0
_080C0178:
	adds r4, #1
	ldrh r0, [r3]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r2]
	cmp r0, r1
	bhs _080C0178
_080C018C:
	adds r0, r4, #0
	b _080C019E
	.align 2, 0
_080C0190: .4byte 0x000005A4
_080C0194: .4byte 0xFFFF0000
_080C0198: .4byte 0x000005B2
_080C019C:
	movs r0, #0
_080C019E:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C01A8:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080c01ac
FUN_080c01ac: @ 0x080C01AC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, _080C0218 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0
	str r4, [r0]
	bl FUN_080bfa74
	movs r0, #0xb2
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r5, #0
	movs r0, #1
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r7, r1
	strh r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	bl FUN_08240630
	movs r0, #8
	bl FUN_0823bca8
	adds r0, r7, #0
	bl FUN_080bffcc
	ldr r2, _080C021C @ =0x03002BE0
	ldr r0, [r2]
	movs r1, #2
	str r1, [r0, #0x1c]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	strb r5, [r0]
	ldr r0, [r2]
	adds r1, #1
	adds r0, r0, r1
	strb r5, [r0]
	cmp r6, #0
	bne _080C0224
	ldr r2, _080C0220 @ =FUN_080c0014
	movs r0, #1
	movs r1, #0
	adds r3, r7, #0
	bl FUN_080a6180
	b _080C0230
	.align 2, 0
_080C0218: .4byte 0x030046A0
_080C021C: .4byte 0x03002BE0
_080C0220: .4byte FUN_080c0014
_080C0224:
	ldr r2, _080C0240 @ =FUN_080c0058
	movs r0, #1
	movs r1, #0
	adds r3, r7, #0
	bl FUN_080a6180
_080C0230:
	ldr r1, _080C0244 @ =0x080C01A9
	adds r0, r7, #0
	bl FUN_080bfa5c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C0240: .4byte FUN_080c0058
_080C0244: .4byte 0x080C01A9

	thumb_func_start FUN_080c0248
FUN_080c0248: @ 0x080C0248
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r4, _080C0294 @ =0x03002BE0
	ldr r3, [r4]
	ldr r0, _080C0298 @ =0x0000037D
	adds r5, r3, r0
	ldrb r2, [r5]
	cmp r2, #0
	beq _080C025E
	b _080C03F0
_080C025E:
	ldr r2, _080C029C @ =0x00000594
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080bfba4
	movs r5, #0
	ldr r2, [r4]
	ldr r1, _080C02A0 @ =0x0000042E
	adds r0, r2, r1
	ldrh r1, [r0]
	subs r1, #3
	ldrh r0, [r2, #0x2c]
	subs r0, r0, r1
	strh r0, [r2, #0x2c]
	ldr r1, [r4]
	movs r4, #0x2c
	ldrsh r2, [r1, r4]
	ldr r0, _080C02A4 @ =0x0000037F
	cmp r2, r0
	bgt _080C02A8
	adds r0, #1
	strh r0, [r1, #0x2c]
	b _080C02B2
	.align 2, 0
_080C0294: .4byte 0x03002BE0
_080C0298: .4byte 0x0000037D
_080C029C: .4byte 0x00000594
_080C02A0: .4byte 0x0000042E
_080C02A4: .4byte 0x0000037F
_080C02A8:
	ldr r0, _080C030C @ =0x000003FF
	cmp r2, r0
	ble _080C02B2
	strh r0, [r1, #0x2c]
	movs r5, #1
_080C02B2:
	cmp r5, #0
	beq _080C032C
	ldr r0, _080C0310 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080C0314 @ =0x0000037D
	adds r0, r0, r1
	movs r5, #0
	movs r4, #1
	strb r4, [r0]
	ldr r2, _080C0318 @ =0x0000057E
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _080C031C @ =0x0000023A
	bl sound_08240740
	ldr r0, _080C0320 @ =0x0000023B
	bl sound_08240740
	movs r0, #0x8f
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _080C0324 @ =0x0000023D
	bl sound_08240740
	ldr r1, _080C0328 @ =0x0000057C
	adds r0, r6, r1
	strh r5, [r0]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r4, [r0]
	movs r4, #0xb1
	lsls r4, r4, #3
	adds r0, r6, r4
	strh r5, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	bl FUN_08240630
	bl FUN_080bfa74
	b _080C03C8
	.align 2, 0
_080C030C: .4byte 0x000003FF
_080C0310: .4byte 0x03002BE0
_080C0314: .4byte 0x0000037D
_080C0318: .4byte 0x0000057E
_080C031C: .4byte 0x0000023A
_080C0320: .4byte 0x0000023B
_080C0324: .4byte 0x0000023D
_080C0328: .4byte 0x0000057C
_080C032C:
	adds r0, r6, #0
	bl FUN_080bfd24
	adds r0, r6, #0
	bl FUN_080c00d4
	adds r4, r0, #0
	ldr r0, _080C036C @ =0x0000059C
	adds r1, r6, r0
	ldr r0, [r1]
	adds r3, r0, r4
	str r3, [r1]
	ldr r0, _080C0370 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, r4
	bge _080C0378
	str r5, [r1]
	ldr r4, _080C0374 @ =0x0000057A
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _080C03C8
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080c01ac
	b _080C03C8
	.align 2, 0
_080C036C: .4byte 0x0000059C
_080C0370: .4byte 0x030046A0
_080C0374: .4byte 0x0000057A
_080C0378:
	ldr r1, _080C03A0 @ =0x00000594
	adds r0, r6, r1
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blt _080C03A4
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r3, r0
	blt _080C03A4
	adds r0, r6, #0
	movs r1, #1
	bl FUN_080c01ac
	b _080C03C8
	.align 2, 0
_080C03A0: .4byte 0x00000594
_080C03A4:
	ldr r0, _080C03E4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _080C03E8 @ =0x0000042E
	adds r0, r0, r2
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	bl FUN_08240630
	ldr r0, _080C03EC @ =0x030046A0
	ldr r1, [r0]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	subs r0, r0, r4
	str r0, [r1]
_080C03C8:
	adds r0, r6, #0
	bl FUN_080bfc60
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #1
	bls _080C04AE
	lsls r0, r0, #2
	bl FUN_0823b9cc
	b _080C04AE
	.align 2, 0
_080C03E4: .4byte 0x03002BE0
_080C03E8: .4byte 0x0000042E
_080C03EC: .4byte 0x030046A0
_080C03F0:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r0, [r0]
	ldr r1, _080C0418 @ =0xFFFFFF00
	ands r0, r1
	movs r1, #0x81
	lsls r1, r1, #9
	cmp r0, r1
	bne _080C0420
	movs r0, #4
	str r0, [sp]
	ldr r0, _080C041C @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #5
	movs r2, #4
	b _080C0472
	.align 2, 0
_080C0418: .4byte 0xFFFFFF00
_080C041C: .4byte 0x00001FFF
_080C0420:
	cmp r2, #3
	bne _080C048C
	ldr r2, _080C047C @ =0x0000037E
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r0, #0x1f
	bls _080C04AE
	movs r3, #0
	movs r2, #4
	strb r2, [r5]
	ldr r0, [r4]
	ldr r1, _080C047C @ =0x0000037E
	adds r0, r0, r1
	strh r3, [r0]
	ldr r1, [r4]
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r1, #0x2c]
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #0x2e]
	ldr r1, [r4]
	movs r0, #0xb0
	lsls r0, r0, #3
	strh r0, [r1, #0x30]
	ldr r0, [r4]
	ldr r1, _080C0480 @ =0x000002E6
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r4, _080C0484 @ =0x000002E7
	adds r0, r0, r4
	strb r1, [r0]
	str r2, [sp]
	ldr r0, _080C0488 @ =0x00001FFF
	str r0, [sp, #4]
	str r3, [sp, #8]
	movs r0, #0
	movs r1, #5
_080C0472:
	movs r3, #4
	bl FUN_0823ce68
	b _080C04AE
	.align 2, 0
_080C047C: .4byte 0x0000037E
_080C0480: .4byte 0x000002E6
_080C0484: .4byte 0x000002E7
_080C0488: .4byte 0x00001FFF
_080C048C:
	cmp r2, #4
	bne _080C04AE
	ldr r1, _080C04D0 @ =0x0000037E
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #0x1f
	bls _080C04AE
	movs r0, #0
	strb r0, [r5]
	ldr r1, [r4]
	ldr r2, _080C04D0 @ =0x0000037E
	adds r1, r1, r2
	strh r0, [r1]
	movs r4, #0xb1
	lsls r4, r4, #3
	adds r1, r6, r4
	strh r0, [r1]
_080C04AE:
	adds r0, r6, #0
	bl FUN_080bff18
	adds r0, r6, #0
	bl FUN_080bfe50
	ldr r0, _080C04D4 @ =0x0000057A
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080C04C8
	subs r0, #1
	strh r0, [r1]
_080C04C8:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C04D0: .4byte 0x0000037E
_080C04D4: .4byte 0x0000057A

	thumb_func_start FUN_080c04d8
FUN_080c04d8: @ 0x080C04D8
	push {lr}
	ldr r0, _080C04FC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080C0500 @ =0x0000042E
	adds r3, r0, r1
	ldrh r0, [r3]
	cmp r0, #3
	bhi _080C050C
	ldr r1, _080C0504 @ =0x04000050
	movs r0, #0xee
	strh r0, [r1]
	ldr r2, _080C0508 @ =0x04000054
	ldrh r1, [r3]
	movs r0, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	strh r0, [r2]
	b _080C051A
	.align 2, 0
_080C04FC: .4byte 0x03002BE0
_080C0500: .4byte 0x0000042E
_080C0504: .4byte 0x04000050
_080C0508: .4byte 0x04000054
_080C050C:
	ldr r1, _080C0524 @ =0x04000050
	movs r0, #0xae
	strh r0, [r1]
	adds r1, #4
	ldrh r0, [r3]
	subs r0, #4
	strh r0, [r1]
_080C051A:
	ldr r1, _080C0528 @ =0x04000052
	movs r0, #0
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080C0524: .4byte 0x04000050
_080C0528: .4byte 0x04000052

	thumb_func_start EntityB3D1_Update
EntityB3D1_Update: @ 0x080C052C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080bfb74
	adds r0, r4, #0
	bl FUN_080c04d8
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityB3D1_Destroy
EntityB3D1_Destroy: @ 0x080C0554
	.byte 0x70, 0xB5, 0x06, 0x1C, 0x20, 0x30, 0x69, 0xF1, 0xC1, 0xFF, 0x30, 0x1C
	.byte 0x6C, 0x30, 0x69, 0xF1, 0xBD, 0xFF, 0x30, 0x1C, 0xB8, 0x30, 0x69, 0xF1, 0xB9, 0xFF, 0xE6, 0x20
	.byte 0x80, 0x00, 0x35, 0x18, 0x04, 0x24, 0x28, 0x1C, 0x6E, 0xF1, 0x22, 0xFE, 0x60, 0x35, 0x01, 0x3C
	.byte 0x00, 0x2C, 0xF8, 0xDA, 0x80, 0x20, 0x40, 0x00, 0x35, 0x18, 0x06, 0x24, 0x28, 0x1C, 0x69, 0xF1
	.byte 0xA7, 0xFF, 0x2C, 0x35, 0x01, 0x3C, 0x00, 0x2C, 0xF8, 0xDA, 0x94, 0x20, 0x80, 0x00, 0x35, 0x18
	.byte 0x05, 0x24, 0x28, 0x1C, 0x69, 0xF1, 0x9C, 0xFF, 0x2C, 0x35, 0x01, 0x3C, 0x00, 0x2C, 0xF8, 0xDA
	.byte 0x00, 0x20, 0x04, 0x49, 0x08, 0x60, 0x04, 0x48, 0x80, 0xF1, 0xC2, 0xF8, 0x00, 0x20, 0x70, 0xBC
	.byte 0x02, 0xBC, 0x08, 0x47, 0x58, 0x01, 0x00, 0x03, 0x3E, 0x02
  .align 2, 0

	thumb_func_start FUN_080c05cc
FUN_080c05cc: @ 0x080C05CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r0, _080C06C8 @ =0x0000CB05
	ldr r1, _080C06CC @ =0x0000B343
	bl GetFile
	adds r1, r0, #0
	movs r0, #0xde
	lsls r0, r0, #2
	adds r4, r7, r0
	adds r2, r4, #0
	adds r0, r1, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl OpenSpriteSetFile
	ldr r2, _080C06D0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x90
	orrs r0, r1
	ldr r1, _080C06D4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	movs r2, #0
	movs r6, #0xe6
	lsls r6, r6, #2
	adds r0, r7, r6
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0x28
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r2, _080C06D8 @ =0x000003D2
	adds r0, r7, r2
	ldr r2, _080C06DC @ =0x000002A7
	strh r2, [r0]
	movs r5, #0xf8
	lsls r5, r5, #2
	adds r3, r7, r5
	ldr r0, _080C06E0 @ =0x03003584
	lsls r1, r2, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r3]
	add r0, sp, #0x10
	ldrh r0, [r0]
	adds r0, #8
	add r1, sp, #0x10
	strh r0, [r1]
	movs r6, #0
	mov sl, r6
	adds r5, r1, #0
	movs r0, #0x60
	mov r8, r0
	movs r1, #0xfe
	lsls r1, r1, #2
	adds r4, r7, r1
	mov sb, r2
_080C0670:
	movs r0, #1
	str r0, [sp]
	mov r2, sl
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r3, #0xde
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r2, #0x1e
	movs r3, #0x30
	bl FUN_0822f3fc
	mov r0, sb
	strh r0, [r4, #0x3a]
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r2, r7, r1
	add r2, r8
	ldr r0, _080C06E0 @ =0x03003584
	ldrh r1, [r4, #0x3a]
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	ldrh r0, [r5]
	adds r0, #8
	strh r0, [r5]
	movs r2, #0x60
	add r8, r2
	adds r4, #0x60
	adds r6, #1
	cmp r6, #3
	ble _080C0670
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C06C8: .4byte 0x0000CB05
_080C06CC: .4byte 0x0000B343
_080C06D0: .4byte 0xFFFF0000
_080C06D4: .4byte 0x0000FFFF
_080C06D8: .4byte 0x000003D2
_080C06DC: .4byte 0x000002A7
_080C06E0: .4byte 0x03003584

	thumb_func_start FUN_080c06e4
FUN_080c06e4: @ 0x080C06E4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r2, _080C0730 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r4
	movs r1, #0x84
	orrs r0, r1
	ldr r1, _080C0734 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #0xe
	adds r4, r0, #0
	orrs r4, r1
	ands r5, r2
	movs r0, #0xd6
	lsls r0, r0, #2
	add r0, r8
	ldr r1, _080C0738 @ =0x0000A8E7
	bl Video_GetActorSprite
	movs r7, #0
	movs r6, #0x94
	lsls r6, r6, #2
	add r6, r8
_080C0718:
	adds r0, r6, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x11
	bl FUN_0822a470
	cmp r7, #1
	bgt _080C073C
	adds r0, r7, #3
	b _080C073E
	.align 2, 0
_080C0730: .4byte 0xFFFF0000
_080C0734: .4byte 0x0000FFFF
_080C0738: .4byte 0x0000A8E7
_080C073C:
	adds r0, r7, #5
_080C073E:
	strh r0, [r6, #0x10]
	str r4, [r6, #0x1c]
	str r5, [r6, #0x20]
	movs r0, #1
	strb r0, [r6, #7]
	adds r1, r4, #0
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080C076C @ =0xFFFF0000
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	adds r6, #0x2c
	adds r7, #1
	cmp r7, #5
	ble _080C0718
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C076C: .4byte 0xFFFF0000

	thumb_func_start FUN_080c0770
FUN_080c0770: @ 0x080C0770
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r2, _080C0800 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r5
	movs r1, #0x80
	orrs r0, r1
	ldr r1, _080C0804 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xe0
	lsls r1, r1, #0xe
	adds r5, r0, #0
	orrs r5, r1
	ands r6, r2
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, _080C0808 @ =0x0000A8E7
	bl Video_GetActorSprite
	movs r3, #0
	movs r2, #0x80
	lsls r2, r2, #1
	mov r8, r2
_080C07A6:
	movs r0, #0x2c
	adds r4, r3, #0
	muls r4, r0, r4
	mov r1, r8
	adds r0, r4, r1
	adds r0, r7, r0
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r2, #0x10
	str r3, [sp]
	bl FUN_0822a470
	adds r0, r4, r7
	add r0, r8
	movs r1, #0
	strh r1, [r0, #0x10]
	adds r1, r7, r4
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r1, r2
	str r5, [r0]
	str r6, [r0, #4]
	ldr r0, _080C080C @ =0x00000107
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080C0800 @ =0xFFFF0000
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	ldr r3, [sp]
	adds r3, #1
	cmp r3, #6
	ble _080C07A6
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C0800: .4byte 0xFFFF0000
_080C0804: .4byte 0x0000FFFF
_080C0808: .4byte 0x0000A8E7
_080C080C: .4byte 0x00000107

	thumb_func_start EntityB3D1_Init
EntityB3D1_Init: @ 0x080C0810
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080C0832
	bl Script_GetValue
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r1, r7, r2
	strh r0, [r1]
	b _080C083A
_080C0832:
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	strh r1, [r0]
_080C083A:
	adds r5, r7, #0
	adds r5, #0x4c
	ldr r0, _080C08C0 @ =0x0000C046
	mov r8, r0
	adds r0, r5, #0
	mov r1, r8
	bl Video_GetActorSprite
	adds r4, r7, #0
	adds r4, #0x20
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	movs r6, #0
	strh r6, [r4, #0x10]
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r7, #0x3c]
	strh r6, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x40
	ldr r0, _080C08C4 @ =0x0000052C
	strh r0, [r1]
	adds r5, #0x4c
	adds r0, r5, #0
	mov r1, r8
	bl Video_GetActorSprite
	adds r4, #0x4c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	strh r6, [r4, #0x10]
	adds r2, r7, #0
	adds r2, #0x88
	ldr r0, [r7, #0x3c]
	ldr r1, [r7, #0x40]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r7, #0
	adds r1, #0x8c
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0x4e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C08E0
	bl Script_GetValue
	cmp r0, #3
	beq _080C08D0
	cmp r0, #3
	ble _080C08E0
	cmp r0, #4
	beq _080C08C8
	cmp r0, #0xa
	beq _080C08D8
	b _080C08E0
	.align 2, 0
_080C08C0: .4byte 0x0000C046
_080C08C4: .4byte 0x0000052C
_080C08C8:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #1
	b _080C08E6
_080C08D0:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #4
	b _080C08E6
_080C08D8:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #3
	b _080C08E6
_080C08E0:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #2
_080C08E6:
	strh r0, [r1]
	adds r5, r7, #0
	adds r5, #0xe4
	ldr r1, _080C095C @ =0x0000C046
	adds r0, r5, #0
	bl Video_GetActorSprite
	adds r4, r7, #0
	adds r4, #0xb8
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0
	strh r0, [r4, #0x10]
	adds r2, r7, #0
	adds r2, #0xd4
	ldr r0, [r7, #0x3c]
	ldr r1, [r7, #0x40]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r7, #0
	adds r1, #0xd8
	ldr r2, _080C0960 @ =0xFFFFFD00
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_080c05cc
	adds r0, r7, #0
	bl FUN_080bfc60
	ldr r1, _080C0964 @ =0x080C01A9
	adds r0, r7, #0
	bl FUN_080bfa5c
	adds r0, r7, #0
	bl FUN_080c0770
	adds r0, r7, #0
	bl FUN_080c06e4
	adds r0, r7, #0
	bl FUN_080bffcc
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C096C
	bl Script_GetValue
	ldr r2, _080C0968 @ =0x000005B2
	adds r1, r7, r2
	b _080C0974
	.align 2, 0
_080C095C: .4byte 0x0000C046
_080C0960: .4byte 0xFFFFFD00
_080C0964: .4byte 0x080C01A9
_080C0968: .4byte 0x000005B2
_080C096C:
	ldr r0, _080C09A0 @ =0x000005B2
	adds r1, r7, r0
	movs r0, #0x96
	lsls r0, r0, #1
_080C0974:
	strh r0, [r1]
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C09B0
	bl Script_GetValue
	ldr r2, _080C09A4 @ =0x0000058A
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080C09A8 @ =0x0000058C
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080C09AC @ =0x0000058E
	adds r1, r7, r2
	b _080C09C8
	.align 2, 0
_080C09A0: .4byte 0x000005B2
_080C09A4: .4byte 0x0000058A
_080C09A8: .4byte 0x0000058C
_080C09AC: .4byte 0x0000058E
_080C09B0:
	ldr r0, _080C09E4 @ =0x0000058A
	adds r1, r7, r0
	movs r0, #0xb4
	strh r0, [r1]
	ldr r2, _080C09E8 @ =0x0000058C
	adds r1, r7, r2
	adds r0, #0x78
	strh r0, [r1]
	ldr r0, _080C09EC @ =0x0000058E
	adds r1, r7, r0
	movs r0, #0x96
	lsls r0, r0, #2
_080C09C8:
	strh r0, [r1]
	movs r0, #0x62
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080C09F4
	bl Script_GetValue
	ldr r2, _080C09F0 @ =0x000005A4
	adds r1, r7, r2
	str r0, [r1]
	b _080C09FA
	.align 2, 0
_080C09E4: .4byte 0x0000058A
_080C09E8: .4byte 0x0000058C
_080C09EC: .4byte 0x0000058E
_080C09F0: .4byte 0x000005A4
_080C09F4:
	ldr r2, _080C0A7C @ =0x000005A4
	adds r0, r7, r2
	str r1, [r0]
_080C09FA:
	movs r0, #0xb2
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r5, #0
	movs r0, #1
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r7, r1
	strh r5, [r0]
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C0A22
	bl Script_GetValue
	ldr r2, _080C0A80 @ =0x000005AC
	adds r1, r7, r2
	str r0, [r1]
_080C0A22:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C0A50
	bl Script_GetValue
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r1, r7, r2
	str r0, [r1]
	bl Script_GetValue
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r1, r7, r2
	str r0, [r1]
	bl Script_GetValue
	movs r2, #0xb5
	lsls r2, r2, #3
	adds r1, r7, r2
	str r0, [r1]
_080C0A50:
	ldr r0, _080C0A84 @ =0x00000594
	adds r4, r7, r0
	str r5, [r4]
	ldr r1, _080C0A88 @ =0x0000059C
	adds r0, r7, r1
	str r5, [r0]
	ldr r0, _080C0A8C @ =0x0000023E
	bl PlaySound_082406e0
	ldr r2, _080C0A90 @ =0x0000057E
	adds r0, r7, r2
	strh r5, [r0]
	str r5, [r4]
	ldr r0, _080C0A94 @ =0x03000158
	str r7, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C0A7C: .4byte 0x000005A4
_080C0A80: .4byte 0x000005AC
_080C0A84: .4byte 0x00000594
_080C0A88: .4byte 0x0000059C
_080C0A8C: .4byte 0x0000023E
_080C0A90: .4byte 0x0000057E
_080C0A94: .4byte 0x03000158

	thumb_func_start EntityB3D1_Create
EntityB3D1_Create: @ 0x080C0A98
	push {r4, lr}
	ldr r0, _080C0ACC @ =0x03000158
	ldr r0, [r0]
	cmp r0, #0
	bne _080C0ADE
	ldr r1, _080C0AD0 @ =0x000005BC
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C0ADC
	ldr r1, _080C0AD4 @ =EntityB3D1_Update
	ldr r2, _080C0AD8 @ =EntityB3D1_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityB3D1_Init
	cmp r0, #0
	bge _080C0ADC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C0ADE
	.align 2, 0
_080C0ACC: .4byte 0x03000158
_080C0AD0: .4byte 0x000005BC
_080C0AD4: .4byte EntityB3D1_Update
_080C0AD8: .4byte EntityB3D1_Destroy
_080C0ADC:
	adds r0, r4, #0
_080C0ADE:
	pop {r4}
	pop {r1}
	bx r1

