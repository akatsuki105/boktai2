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
_08242CFA:
	mov r0, r8
	adds r4, r0, r5
	adds r0, r4, #0
	bl GetWeaponID
	cmp r0, #0
	bne _08242D0C
	adds r6, #1
	b _08242D1C
_08242D0C:
	movs r0, #1
	add sl, r0
	cmp r6, #0
	ble _08242D1C
	subs r1, r4, r6
	adds r0, r4, #0
	bl SwapWeaponSlot
_08242D1C:
	adds r5, #1
	cmp r5, #0xf
	ble _08242CFA
	mov r0, sl
	cmp r0, #1
	ble _08242D6C
	movs r5, #0
	subs r0, #1
	str r0, [sp]
	cmp r5, r0
	bge _08242D6C
_08242D32:
	adds r6, r5, #0
	adds r0, r5, #1
	mov sb, r0
	cmp r5, sl
	bge _08242D64
	mov r0, r8
	adds r7, r0, r5
_08242D40:
	adds r0, r7, #0
	bl GetWeaponID
	adds r4, r0, #0
	mov r0, r8
	adds r5, r0, r6
	adds r0, r5, #0
	bl GetWeaponID
	cmp r4, r0
	ble _08242D5E
	adds r0, r7, #0
	adds r1, r5, #0
	bl SwapWeaponSlot
_08242D5E:
	adds r6, #1
	cmp r6, sl
	blt _08242D40
_08242D64:
	mov r5, sb
	ldr r0, [sp]
	cmp r5, r0
	blt _08242D32
_08242D6C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
