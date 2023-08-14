	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	movs r0, #0
	mov sl, r0
	movs r6, #0
	movs r5, #0
_082432DE:
	mov r0, r8
	adds r4, r0, r5
	adds r0, r4, #0
	bl GetInventoryArmor
	cmp r0, #0
	bge _082432F0
	adds r6, #1
	b _08243300
_082432F0:
	movs r0, #1
	add sl, r0
	cmp r6, #0
	ble _08243300
	subs r1, r4, r6
	adds r0, r4, #0
	bl SwapArmorSlot
_08243300:
	adds r5, #1
	cmp r5, #0xf
	ble _082432DE
	mov r0, sl
	cmp r0, #1
	ble _08243350
	movs r5, #0
	subs r0, #1
	str r0, [sp]
	cmp r5, r0
	bge _08243350
_08243316:
	adds r6, r5, #0
	adds r0, r5, #1
	mov sb, r0
	cmp r5, sl
	bge _08243348
	mov r0, r8
	adds r7, r0, r5
_08243324:
	adds r0, r7, #0
	bl GetInventoryArmor
	adds r4, r0, #0
	mov r0, r8
	adds r5, r0, r6
	adds r0, r5, #0
	bl GetInventoryArmor
	cmp r4, r0
	ble _08243342
	adds r0, r7, #0
	adds r1, r5, #0
	bl SwapArmorSlot
_08243342:
	adds r6, #1
	cmp r6, sl
	blt _08243324
_08243348:
	mov r5, sb
	ldr r0, [sp]
	cmp r5, r0
	blt _08243316
_08243350:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
