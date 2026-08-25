	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_080A822A:
	lsls r1, r5, #1
	adds r0, r6, #0
	adds r0, #0x68
	adds r0, r0, r1
	ldrh r4, [r0]
	adds r0, r5, #0
	bl GetWeaponSkillLevel
	cmp r4, r0
	beq _080A8242
	movs r0, #1
	b _080A824A
_080A8242:
	adds r5, #1
	cmp r5, #4
	ble _080A822A
	movs r0, #0
_080A824A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
