	push {r4, r5, lr}
	adds r4, r0, #0
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _08091B2C
	ldr r5, _08091B0C @ =0x00003FAD
	adds r3, r4, r5
	strb r1, [r3]
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #5
	bne _08091B18
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08091B10
	movs r0, #2
	b _08091B16
	.align 2, 0
_08091B0C: .4byte 0x00003FAD
_08091B10:
	cmp r0, #2
	bne _08091B18
	movs r0, #0
_08091B16:
	strb r0, [r3]
_08091B18:
	ldr r1, _08091B34 @ =0x00003FAE
	adds r0, r4, r1
	strh r2, [r0]
	ldr r2, _08091B38 @ =0x00003FAC
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _08091B3C @ =0x00003AE4
	adds r0, r4, r3
	strb r1, [r0]
_08091B2C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08091B34: .4byte 0x00003FAE
_08091B38: .4byte 0x00003FAC
_08091B3C: .4byte 0x00003AE4
