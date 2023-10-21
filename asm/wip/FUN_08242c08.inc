	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _08242C3C @ =gWeaponDB
	bl FUN_08242b6c
	movs r2, #0
	ldr r5, _08242C40 @ =0x030046A0
	movs r0, #1
	rsbs r0, r0, #0
	adds r3, r0, #0
_08242C1C:
	ldr r0, [r5]
	lsls r1, r2, #1
	adds r1, r1, r0
	adds r1, #0x60
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, r4
	bne _08242C2E
	strh r3, [r1]
_08242C2E:
	adds r2, #1
	cmp r2, #3
	ble _08242C1C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08242C3C: .4byte gWeaponDB
_08242C40: .4byte 0x030046A0
