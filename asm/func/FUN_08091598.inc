	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049fa8
	movs r0, #0
	movs r1, #0x12
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	ldr r0, _08091644 @ =0x0000402C
	adds r3, r6, r0
	ldr r2, _08091648 @ =0x085ACEC8
	ldr r5, _0809164C @ =0x030046A0
	ldr r1, [r5]
	movs r4, #0x95
	lsls r4, r4, #2
	adds r1, r1, r4
	movs r7, #0
	ldrsh r0, [r1, r7]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r3]
	ldr r0, _08091650 @ =0x00004030
	adds r3, r6, r0
	ldr r2, _08091654 @ =0x085ACF04
	movs r7, #0
	ldrsh r0, [r1, r7]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r3]
	ldr r0, _08091658 @ =0x00004034
	adds r3, r6, r0
	ldr r2, _0809165C @ =0x085ACF40
	movs r7, #0
	ldrsh r0, [r1, r7]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r3]
	adds r0, r6, #0
	bl FUN_0808b82c
	ldr r1, _08091660 @ =0x00000F56
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r6, #0
	bl FUN_0808b86c
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x18
	bl FUN_0808c61c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r0, [r5]
	adds r0, r0, r4
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0xe
	ble _08091664
	ldr r1, [r6, #0x18]
	ldr r0, [r6, #0x38]
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #5
	bl FUN_0808a3c4
	adds r0, r6, #0
	bl FUN_08091270
	b _0809167A
	.align 2, 0
_08091644: .4byte 0x0000402C
_08091648: .4byte 0x085ACEC8
_0809164C: .4byte 0x030046A0
_08091650: .4byte 0x00004030
_08091654: .4byte 0x085ACF04
_08091658: .4byte 0x00004034
_0809165C: .4byte 0x085ACF40
_08091660: .4byte 0x00000F56
_08091664:
	ldr r1, [r6, #0x18]
	ldr r0, [r6, #0x34]
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #5
	bl FUN_0808a3c4
	adds r0, r6, #0
	bl FUN_08090d54
_0809167A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
