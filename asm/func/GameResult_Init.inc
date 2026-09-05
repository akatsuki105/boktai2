	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08222AE4
	bl Script_GetValue
	str r0, [r7, #0x44]
_08222AE4:
	movs r0, #0
	str r0, [r7, #0x40]
	str r0, [r7, #0x48]
	str r0, [r7, #0x4c]
	str r0, [r7, #0x50]
	str r0, [r7, #0x54]
	subs r0, #1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl FUN_082229ac
	adds r0, r7, #0
	bl FUN_082229e8
	adds r0, r7, #0
	bl FUN_08222a18
	ldr r5, _08222B78 @ =0x030046A0
	ldr r0, [r5]
	movs r4, #0xad
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r1, _08222B7C @ =0x00034BC0
	bl Div
	adds r6, r0, #0
	ldr r0, [r5]
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0xe1
	lsls r1, r1, #4
	bl Div
	lsls r1, r6, #4
	subs r1, r1, r6
	lsls r1, r1, #2
	subs r0, r0, r1
	mov r8, r0
	ldr r0, [r5]
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0x3c
	bl Div
	lsls r1, r6, #3
	subs r1, r1, r6
	lsls r1, r1, #5
	adds r1, r1, r6
	lsls r1, r1, #4
	subs r0, r0, r1
	mov r2, r8
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #2
	subs r4, r0, r1
	cmp r6, #0x63
	ble _08222B80
	adds r0, r7, #0
	adds r0, #0x64
	movs r1, #0x39
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #2
	movs r2, #0x35
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #2
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	b _08222BF8
	.align 2, 0
_08222B78: .4byte 0x030046A0
_08222B7C: .4byte 0x00034BC0
_08222B80:
	adds r0, r6, #0
	movs r1, #0xa
	bl Mod
	adds r0, #0x30
	adds r1, r7, #0
	adds r1, #0x65
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0xa
	bl Div
	adds r6, r0, #0
	movs r1, #0xa
	bl Mod
	adds r0, #0x30
	adds r1, r7, #0
	adds r1, #0x64
	strb r0, [r1]
	mov r0, r8
	movs r1, #0xa
	bl Mod
	adds r0, #0x30
	adds r1, r7, #0
	adds r1, #0x68
	strb r0, [r1]
	mov r0, r8
	movs r1, #0xa
	bl Div
	mov r8, r0
	movs r1, #0xa
	bl Mod
	adds r0, #0x30
	adds r1, r7, #0
	adds r1, #0x67
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0xa
	bl Mod
	adds r0, #0x30
	adds r1, r7, #0
	adds r1, #0x6b
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	adds r4, r0, #0
	movs r1, #0xa
	bl Mod
	adds r0, #0x30
	adds r1, r7, #0
	adds r1, #0x6a
	strb r0, [r1]
_08222BF8:
	adds r2, r7, #0
	adds r2, #0x69
	movs r1, #0
	movs r0, #0x3a
	strb r0, [r2]
	subs r2, #3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0x6c
	strb r1, [r0]
	ldr r0, _08222C40 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	ldr r0, _08222C44 @ =0x05F5E0FF
	cmp r5, r0
	ble _08222C20
	adds r5, r0, #0
_08222C20:
	movs r6, #9
	movs r2, #0x77
	adds r2, r2, r7
	mov r8, r2
	adds r4, r7, #0
	adds r4, #0x76
_08222C2C:
	cmp r5, #0
	bne _08222C4E
	cmp r6, #9
	bne _08222C48
	adds r1, r7, #0
	adds r1, #0x76
	movs r0, #0x30
	strb r0, [r1]
	b _08222C72
	.align 2, 0
_08222C40: .4byte 0x030046A0
_08222C44: .4byte 0x05F5E0FF
_08222C48:
	movs r0, #0x20
	strb r0, [r4]
	b _08222C72
_08222C4E:
	cmp r6, #2
	beq _08222C56
	cmp r6, #6
	bne _08222C5C
_08222C56:
	movs r0, #0x2c
	strb r0, [r4]
	b _08222C72
_08222C5C:
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	adds r0, #0x30
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
_08222C72:
	subs r4, #1
	subs r6, #1
	cmp r6, #0
	bge _08222C2C
	movs r0, #0
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08222a54
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
