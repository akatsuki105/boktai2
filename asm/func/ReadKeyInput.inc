	push {r4, r5, r6, r7, lr}
	ldr r1, _082307F0 @ =0x03004508
	ldr r0, _082307F4 @ =0x04000130
	ldrh r2, [r0]
	strh r2, [r1]
	ldr r0, _082307F8 @ =0x030044D0
	ldr r0, [r0]
	cmp r0, #0
	bne _08230804
	ldr r1, _082307FC @ =0x000003FF
	adds r0, r1, #0
	eors r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r1, _08230800 @ =0x030044E0
	ldrh r2, [r1]
	strh r3, [r1]
	adds r0, r3, #0
	bics r0, r2
	strh r0, [r1, #2]
	bics r2, r3
	strh r2, [r1, #4]
	movs r3, #0
	adds r1, #8
	movs r4, #3
_082307DE:
	ldrh r2, [r1]
	strh r3, [r1]
	strh r3, [r1, #2]
	strh r2, [r1, #4]
	adds r1, #8
	subs r4, #1
	cmp r4, #0
	bge _082307DE
	b _08230858
	.align 2, 0
_082307F0: .4byte 0x03004508
_082307F4: .4byte 0x04000130
_082307F8: .4byte 0x030044D0
_082307FC: .4byte 0x000003FF
_08230800: .4byte 0x030044E0
_08230804:
	ldr r0, _08230828 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08230858
	movs r4, #0
	ldr r7, _0823082C @ =0x0000FFFF
	ldr r5, _08230830 @ =0x03004510
	ldr r0, _08230834 @ =0x000003FF
	adds r6, r0, #0
	ldr r1, _08230838 @ =0x030044E0
_0823081C:
	ldrh r0, [r5]
	cmp r0, r7
	bne _0823083C
	movs r3, #0
	b _08230840
	.align 2, 0
_08230828: .4byte 0x030044BC
_0823082C: .4byte 0x0000FFFF
_08230830: .4byte 0x03004510
_08230834: .4byte 0x000003FF
_08230838: .4byte 0x030044E0
_0823083C:
	adds r3, r6, #0
	eors r3, r0
_08230840:
	ldrh r2, [r1]
	strh r3, [r1]
	adds r0, r3, #0
	bics r0, r2
	strh r0, [r1, #2]
	bics r2, r3
	strh r2, [r1, #4]
	adds r5, #2
	adds r1, #8
	adds r4, #1
	cmp r4, #4
	ble _0823081C
_08230858:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
