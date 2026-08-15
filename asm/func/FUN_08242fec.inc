	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	movs r4, #0
	ldr r5, _08243050 @ =0x030046A0
	movs r3, #0x92
	lsls r3, r3, #4
	movs r2, #0
_08242FFA:
	ldr r1, [r5]
	lsls r0, r4, #2
	adds r0, r0, r1
	adds r0, r0, r3
	str r2, [r0]
	adds r4, #1
	cmp r4, #1
	ble _08242FFA
	movs r4, #0
_0824300C:
	adds r0, r4, #0
	ldr r1, _08243054 @ =gWeaponDB
	bl FUN_08242b6c
	adds r4, #1
	cmp r4, #0x2f
	ble _0824300C
	movs r4, #0
	ldr r5, _08243050 @ =0x030046A0
	adds r3, r5, #0
	movs r0, #1
	rsbs r0, r0, #0
	adds r2, r0, #0
_08243026:
	ldr r1, [r3]
	lsls r0, r4, #1
	adds r0, r0, r1
	adds r0, #0x60
	strh r2, [r0]
	adds r4, #1
	cmp r4, #3
	ble _08243026
	ldr r0, [r5]
	adds r0, #0x58
	movs r1, #0
	strh r1, [r0]
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08243058
	bl Script_GetValue
	adds r4, r0, #0
	b _0824305A
	.align 2, 0
_08243050: .4byte 0x030046A0
_08243054: .4byte gWeaponDB
_08243058:
	movs r4, #0
_0824305A:
	cmp r4, #0
	ble _082430C4
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _082430A2
	cmp r4, #0
	ble _082430A2
	ldr r6, _082430CC @ =gWeaponDB
	mov r5, sp
_08243070:
	bl Script_GetValue
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, sp
	adds r1, r1, r6
	ldm r1!, {r2, r3, r7}
	stm r0!, {r2, r3, r7}
	ldm r1!, {r2, r3, r7}
	stm r0!, {r2, r3, r7}
	ldm r1!, {r2, r3, r7}
	stm r0!, {r2, r3, r7}
	ldrb r0, [r5]
	bl IsSpecialWeapon
	cmp r0, #0
	bne _08243096
	strb r0, [r5, #0x18]
_08243096:
	mov r0, sp
	bl FUN_08242b88
	subs r4, #1
	cmp r4, #0
	bne _08243070
_082430A2:
	movs r0, #0x71
	bl prepare_08231510
	cmp r0, #0
	beq _082430C4
	movs r4, #0
	ldr r5, _082430D0 @ =0x030046A0
_082430B0:
	bl Script_GetValue
	ldr r2, [r5]
	lsls r1, r4, #1
	adds r1, r1, r2
	adds r1, #0x60
	strh r0, [r1]
	adds r4, #1
	cmp r4, #3
	ble _082430B0
_082430C4:
	add sp, #0x24
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082430CC: .4byte gWeaponDB
_082430D0: .4byte 0x030046A0
