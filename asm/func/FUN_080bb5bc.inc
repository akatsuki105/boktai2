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
