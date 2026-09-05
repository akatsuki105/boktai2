	push {r4, r5, lr}
	sub sp, #0x24
	movs r0, #0x77
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _08242DA2
	movs r0, #0
	b _08242EA6
_08242DA2:
	ldr r4, _08242E54 @ =gWeaponDB
	bl Script_GetValue
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, sp
	adds r1, r1, r4
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	movs r0, #0x71
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08242DD0
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #8]
_08242DD0:
	movs r4, #0
	mov r0, sp
	ldrb r0, [r0]
	bl IsSpecialWeapon
	cmp r0, #0
	bne _08242DF6
	movs r0, #0x6f
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08242DEE
	bl Script_GetValue
	adds r4, r0, #0
_08242DEE:
	cmp r4, #0
	bne _08242DF6
	mov r0, sp
	strb r4, [r0, #0x18]
_08242DF6:
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08242E16
	add r4, sp, #4
	movs r5, #1
_08242E04:
	bl Script_GetValue
	cmp r0, #0
	ble _08242E0E
	strb r0, [r4, #0x18]
_08242E0E:
	adds r4, #4
	subs r5, #1
	cmp r5, #0
	bge _08242E04
_08242E16:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08242EA0
	bl Script_GetValue
	adds r4, r0, #0
	cmp r4, #0
	bne _08242E5C
	ldr r0, _08242E58 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r3, r0, r1
	movs r5, #0
	ldrb r2, [r3]
	add r1, sp, #0xc
	cmp r2, #0
	beq _08242E9A
	adds r4, r1, #0
_08242E40:
	adds r0, r4, r5
	strb r2, [r0]
	adds r3, #1
	adds r5, #1
	ldrb r2, [r3]
	cmp r2, #0
	beq _08242E9A
	cmp r5, #0xa
	ble _08242E40
	b _08242E9A
	.align 2, 0
_08242E54: .4byte gWeaponDB
_08242E58: .4byte 0x030046A0
_08242E5C:
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08242EA0
	bl FUN_0823d340
	adds r3, r0, #0
	cmp r3, #0
	beq _08242EA0
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	adds r3, r0, #0
	movs r5, #0
	ldrb r2, [r3]
	add r1, sp, #0xc
	cmp r2, #0
	beq _08242E9A
	adds r4, r1, #0
_08242E88:
	adds r0, r4, r5
	strb r2, [r0]
	adds r3, #1
	adds r5, #1
	ldrb r2, [r3]
	cmp r2, #0
	beq _08242E9A
	cmp r5, #0xa
	ble _08242E88
_08242E9A:
	adds r1, r1, r5
	movs r0, #0
	strb r0, [r1]
_08242EA0:
	mov r0, sp
	bl FUN_08242b88
_08242EA6:
	add sp, #0x24
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
