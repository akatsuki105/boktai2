	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x24
	ldrb r0, [r4]
	bl FUN_0820fedc
	mov r8, r0
	movs r0, #0x91
	lsls r0, r0, #3
	adds r5, r7, r0
	ldrb r0, [r4]
	bl WeaponDexMenu_GetPage1stEntry
	mov sb, r0
	movs r6, #0
	cmp r6, r8
	bge _08210C1C
_08210BDA:
	mov r3, sb
	adds r4, r3, r6
	adds r0, r4, #0
	bl IsWeaponAlreadyFound
	cmp r0, #0
	beq _08210C0C
	adds r0, r4, #0
	bl FUN_0820fee8
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r1, r7, r3
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r5, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _08210C12
_08210C0C:
	ldr r0, [r5, #8]
	movs r1, #1
	orrs r0, r1
_08210C12:
	str r0, [r5, #8]
	adds r5, #0x60
	adds r6, #1
	cmp r6, r8
	blt _08210BDA
_08210C1C:
	cmp r6, #0x13
	bgt _08210C30
	movs r1, #1
_08210C22:
	ldr r0, [r5, #8]
	orrs r0, r1
	str r0, [r5, #8]
	adds r5, #0x60
	adds r6, #1
	cmp r6, #0x13
	ble _08210C22
_08210C30:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
