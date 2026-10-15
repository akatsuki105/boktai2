	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080C1FA8
	ldr r1, _080C1FA0 @ =0x0000CFE1
	ldr r7, _080C1FA4 @ =0x0000ACBD
	movs r6, #0
	b _080C1FAE
	.align 2, 0
_080C1FA0: .4byte 0x0000CFE1
_080C1FA4: .4byte 0x0000ACBD
_080C1FA8:
	ldr r1, _080C2020 @ =0x0000A413
	ldr r7, _080C2024 @ =0x0000EFDA
	movs r6, #0xc
_080C1FAE:
	ldr r0, _080C2028 @ =0x0000C091
	bl GetFile
	adds r5, r0, #0
	movs r4, #0
	str r4, [sp, #0xc]
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	adds r2, r5, #0
	movs r3, #0
	bl Video_SetupBGLayout
	movs r0, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Video_SetBGLayer
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _080C202C @ =0x000092B3
	adds r1, r7, #0
	bl GetFile
	movs r1, #0xda
	lsls r1, r1, #1
	adds r3, r0, r1
	movs r1, #0xd
	ldr r5, _080C2030 @ =0x03004250
_080C1FFA:
	lsls r0, r1, #5
	adds r4, r1, #1
	adds r1, r0, r5
	movs r2, #0xf
_080C2002:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _080C2002
	adds r1, r4, #0
	cmp r1, #0xf
	ble _080C1FFA
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C2020: .4byte 0x0000A413
_080C2024: .4byte 0x0000EFDA
_080C2028: .4byte 0x0000C091
_080C202C: .4byte 0x000092B3
_080C2030: .4byte 0x03004250
