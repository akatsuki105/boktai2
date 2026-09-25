	push {r4, lr}
	adds r2, r0, #0
	ldr r0, _08241DC8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08241DE0
	ldr r0, _08241DCC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _08241DD0
	movs r0, #1
	rsbs r0, r0, #0
	b _08241DD4
	.align 2, 0
_08241DC8: .4byte 0x030047A4
_08241DCC: .4byte 0x03002C68
_08241DD0:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
_08241DD4:
	lsls r1, r0, #3
	ldr r0, _08241DDC @ =0x030044E0
	adds r0, r1, r0
	b _08241DE2
	.align 2, 0
_08241DDC: .4byte 0x030044E0
_08241DE0:
	ldr r0, _08241E10 @ =0x030044E0
_08241DE2:
	ldrh r1, [r0]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	ldr r4, _08241E14 @ =0x03004868
	cmp r0, #0
	beq _08241E38
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08241E18
	ldrh r0, [r2, #0x22]
	adds r0, #1
	strh r0, [r2, #0x22]
	ands r0, r3
	cmp r0, #0
	bne _08241E38
	ldrh r0, [r4]
	cmp r0, #0x8b
	bhi _08241E38
	adds r0, #1
	b _08241E36
	.align 2, 0
_08241E10: .4byte 0x030044E0
_08241E14: .4byte 0x03004868
_08241E18:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08241E38
	ldrh r0, [r2, #0x22]
	adds r0, #1
	strh r0, [r2, #0x22]
	ands r0, r3
	cmp r0, #0
	bne _08241E38
	ldrh r0, [r4]
	cmp r0, #0
	beq _08241E38
	subs r0, #1
_08241E36:
	strh r0, [r4]
_08241E38:
	ldrh r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
