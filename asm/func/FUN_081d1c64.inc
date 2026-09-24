	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x80
	ldrh r1, [r6]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081D1CD2
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	ldr r1, _081D1CB4 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r6]
	adds r0, r5, #0
	bl FUN_081d1b34
	strh r4, [r5, #0x10]
	ldr r0, [r5, #0xc]
	ldr r1, _081D1CB8 @ =0x0000011F
	bl Video_SetAuxSpritePltt
	ldr r0, _081D1CBC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081D1CCA
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081D1CC4
	ldr r0, _081D1CC0 @ =0x00000389
	bl PlaySound_082406e0
	b _081D1CCA
	.align 2, 0
_081D1CB4: .4byte 0x0000FFFD
_081D1CB8: .4byte 0x0000011F
_081D1CBC: .4byte 0x030047A4
_081D1CC0: .4byte 0x00000389
_081D1CC4:
	ldr r0, _081D1CD8 @ =0x00000155
	bl PlaySound_082406e0
_081D1CCA:
	adds r1, r5, #0
	adds r1, #0x5a
	movs r0, #0
	strh r0, [r1]
_081D1CD2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D1CD8: .4byte 0x00000155
