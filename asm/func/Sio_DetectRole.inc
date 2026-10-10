	push {r4, r5, lr}
	ldr r4, _08238AD0 @ =0x030046CC
	movs r3, #1
	rsbs r3, r3, #0
	str r3, [r4]
	ldr r5, _08238AD4 @ =0x030046D4
	movs r0, #0
	str r0, [r5]
	ldr r0, _08238AD8 @ =0x04000128
	ldrh r0, [r0]
	adds r2, r0, #0
	movs r1, #0x88
	ands r0, r1
	cmp r0, #8
	beq _08238ADC
	str r3, [r5]
	b _08238AF8
	.align 2, 0
_08238AD0: .4byte 0x030046CC
_08238AD4: .4byte 0x030046D4
_08238AD8: .4byte 0x04000128
_08238ADC:
	movs r0, #4
	ands r2, r0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08238AEC
	str r0, [r4]
	b _08238AEE
_08238AEC:
	str r3, [r4]
_08238AEE:
	ldr r1, _08238B00 @ =0x0400012A
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r2, #0
	strh r0, [r1]
_08238AF8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08238B00: .4byte 0x0400012A
