	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	ldr r0, _08051D30 @ =0x03000118
	ldr r2, [r0]
	cmp r2, #0
	bne _08051D34
	movs r0, #1
	rsbs r0, r0, #0
	b _08051DF2
	.align 2, 0
_08051D30: .4byte 0x03000118
_08051D34:
	lsls r0, r4, #5
	subs r0, r0, r4
	lsls r5, r0, #2
	movs r1, #0xb7
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r3, r2, r0
	ldrb r1, [r3, #3]
	cmp r1, #0
	beq _08051D56
	adds r0, r2, r5
	adds r0, #0xef
	ldrb r2, [r0]
	adds r1, r1, r2
	movs r2, #0
	strb r1, [r0]
	strb r2, [r3, #3]
_08051D56:
	adds r2, r7, #0
	strb r4, [r3, #2]
	cmp r2, #0xa
	ble _08051D62
	movs r2, #0xa
	b _08051D68
_08051D62:
	cmp r2, #0
	bge _08051D68
	movs r2, #0
_08051D68:
	movs r1, #0
	strb r2, [r3, #3]
	movs r0, #2
	strb r0, [r3]
	movs r0, #1
	strb r0, [r3, #1]
	str r1, [r3, #8]
	adds r5, r3, #0
	adds r5, #0xc
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08051D96
	asrs r0, r0, #8
	b _08051D9C
_08051D96:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08051D9C:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08051DAE
	asrs r0, r0, #8
	b _08051DB4
_08051DAE:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08051DB4:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08051DC8
	asrs r0, r0, #8
	b _08051DCE
_08051DC8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08051DCE:
	subs r2, r4, r0
	strh r2, [r5, #2]
	adds r4, r4, r0
	strh r4, [r5, #4]
	ldr r3, _08051DF8 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	movs r0, #0
_08051DF2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08051DF8: .4byte 0x030047C8
