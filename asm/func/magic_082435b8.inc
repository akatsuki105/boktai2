	push {r4, r5, lr}
	ldr r2, _082435F4 @ =0x030046A0
	ldr r1, [r2]
	movs r0, #0
	str r0, [r1, #0x54]
	movs r4, #0
	adds r5, r2, #0
	subs r0, #1
	adds r3, r0, #0
_082435CA:
	ldr r1, [r2]
	lsls r0, r4, #1
	adds r0, r0, r1
	adds r0, #0x68
	strh r3, [r0]
	adds r4, #1
	cmp r4, #3
	ble _082435CA
	ldr r0, [r5]
	adds r0, #0x5a
	movs r1, #0
	strh r1, [r0]
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _082435F8
	bl Script_GetValue
	adds r4, r0, #0
	b _082435FA
	.align 2, 0
_082435F4: .4byte 0x030046A0
_082435F8:
	movs r4, #0
_082435FA:
	cmp r4, #0
	ble _0824363C
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _0824361A
	cmp r4, #0
	ble _0824361A
_0824360C:
	bl Script_GetValue
	bl magic_082434f0
	subs r4, #1
	cmp r4, #0
	bne _0824360C
_0824361A:
	movs r0, #0x71
	bl prepare_08231510
	cmp r0, #0
	beq _0824363C
	movs r4, #0
	ldr r5, _08243644 @ =0x030046A0
_08243628:
	bl Script_GetValue
	ldr r2, [r5]
	lsls r1, r4, #1
	adds r1, r1, r2
	adds r1, #0x68
	strh r0, [r1]
	adds r4, #1
	cmp r4, #3
	ble _08243628
_0824363C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08243644: .4byte 0x030046A0
