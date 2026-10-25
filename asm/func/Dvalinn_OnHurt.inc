	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	adds r7, r4, #0
	movs r1, #0x10
	adds r0, r4, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081FF7D6
	ldr r1, _081FF7DC @ =0x00000802
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081FF7C4
	adds r0, r5, #0
	adds r1, r6, #0
	bl Hitbox_ApplyDamage
	ldrh r1, [r6, #0x3e]
	ldr r2, _081FF7E0 @ =0x000007D2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r1, [r5, #0x34]
	adds r0, r4, #0
	adds r0, #0xb4
	str r1, [r0]
	ldr r1, [r5, #0x38]
	adds r0, #4
	str r1, [r0]
_081FF7C4:
	movs r1, #4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081FF7D6
	ldr r0, _081FF7E4 @ =0x000007DE
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_081FF7D6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FF7DC: .4byte 0x00000802
_081FF7E0: .4byte 0x000007D2
_081FF7E4: .4byte 0x000007DE
