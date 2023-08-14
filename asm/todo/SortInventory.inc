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
_08242576:
	mov r0, r8
	adds r4, r0, r5
	adds r0, r4, #0
	bl GetNormalItemID
	cmp r0, #0
	bge _08242588
	adds r6, #1
	b _08242598
_08242588:
	movs r0, #1
	add sl, r0
	cmp r6, #0
	ble _08242598
	subs r1, r4, r6
	adds r0, r4, #0
	bl SwapNormalItem
_08242598:
	adds r5, #1
	cmp r5, #0xf
	ble _08242576
	mov r0, sl
	cmp r0, #1
	ble _082425E8
	movs r5, #0
	subs r0, #1
	str r0, [sp]
	cmp r5, r0
	bge _082425E8
_082425AE:
	adds r6, r5, #0
	adds r0, r5, #1
	mov sb, r0
	cmp r5, sl
	bge _082425E0
	mov r0, r8
	adds r7, r0, r5
_082425BC:
	adds r0, r7, #0
	bl GetNormalItemID
	adds r4, r0, #0
	mov r0, r8
	adds r5, r0, r6
	adds r0, r5, #0
	bl GetNormalItemID
	cmp r4, r0
	ble _082425DA
	adds r0, r7, #0
	adds r1, r5, #0
	bl SwapNormalItem
_082425DA:
	adds r6, #1
	cmp r6, sl
	blt _082425BC
_082425E0:
	mov r5, sb
	ldr r0, [sp]
	cmp r5, r0
	blt _082425AE
_082425E8:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
