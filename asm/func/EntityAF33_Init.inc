	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	adds r6, r0, #0
	ldr r0, _080508F4 @ =0x030000F0
	str r6, [r0]
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0xc4
	str r0, [r1]
	movs r0, #0
	str r0, [r6, #0x68]
	str r0, [r6, #0x70]
	movs r0, #0x77
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08050906
	adds r7, r6, #0
	adds r7, #0x78
	adds r0, r6, #0
	adds r0, #0x2b
	str r0, [sp, #0x34]
	adds r1, r6, #0
	adds r1, #0x2c
	str r1, [sp, #0x38]
	adds r2, r6, #0
	adds r2, #0x2d
	str r2, [sp, #0x3c]
	adds r3, r6, #0
	adds r3, #0x33
	str r3, [sp, #0x44]
	adds r5, r6, #0
	adds r5, #0x32
	str r5, [sp, #0x40]
	subs r0, #3
	str r0, [sp, #0x2c]
	subs r1, #3
	str r1, [sp, #0x30]
	adds r2, #0xb
	str r2, [sp, #0x48]
	adds r4, r7, #0
_080508DC:
	bl VM_GetPC
	cmp r0, #0
	beq _080508F8
	bl Script_GetValue
	strh r0, [r4]
	ldr r0, [r6, #0x68]
	adds r0, #1
	str r0, [r6, #0x68]
	b _080508FA
	.align 2, 0
_080508F4: .4byte 0x030000F0
_080508F8:
	strh r0, [r4]
_080508FA:
	adds r4, #2
	adds r0, r7, #0
	adds r0, #0x1e
	cmp r4, r0
	ble _080508DC
	b _08050942
_08050906:
	adds r7, r6, #0
	adds r7, #0x78
	adds r3, r6, #0
	adds r3, #0x2b
	str r3, [sp, #0x34]
	adds r5, r6, #0
	adds r5, #0x2c
	str r5, [sp, #0x38]
	adds r0, r6, #0
	adds r0, #0x2d
	str r0, [sp, #0x3c]
	adds r1, r6, #0
	adds r1, #0x33
	str r1, [sp, #0x44]
	adds r2, r6, #0
	adds r2, #0x32
	str r2, [sp, #0x40]
	subs r3, #3
	str r3, [sp, #0x2c]
	subs r5, #3
	str r5, [sp, #0x30]
	adds r0, #0xb
	str r0, [sp, #0x48]
	adds r1, r7, #0
	movs r2, #0
	adds r0, #0x5e
_0805093A:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _0805093A
_08050942:
	ldr r1, [r6, #0x68]
	cmp r1, #0
	beq _080509BE
	ldr r0, _080509E8 @ =0x03002CF0
	ldrb r5, [r0]
	movs r2, #0
	mov r8, r2
	cmp r8, r1
	bhs _080509BE
	ldr r3, _080509EC @ =0x030046B8
	mov sl, r3
	mov sb, r7
_0805095A:
	movs r4, #0xf
	ands r4, r5
	movs r0, #1
	lsls r0, r4
	ldr r1, [r6, #0x70]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _08050980
	movs r7, #0xf
	movs r3, #1
_08050970:
	adds r4, r5, #0
	ands r4, r7
	adds r5, #1
	adds r0, r3, #0
	lsls r0, r4
	ands r0, r1
	cmp r0, #0
	bne _08050970
_08050980:
	movs r0, #1
	lsls r0, r4
	orrs r2, r0
	str r2, [r6, #0x70]
	mov r7, sb
	ldrh r0, [r7]
	bl FUN_0823d414
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08242b6c
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _080509F0 @ =0x000003FF
	ands r0, r1
	mov r2, sl
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080509F4 @ =0x0203B400
	adds r0, r0, r3
	ldrb r0, [r0]
	adds r5, r5, r0
	movs r7, #2
	add sb, r7
	movs r0, #1
	add r8, r0
	ldr r0, [r6, #0x68]
	cmp r8, r0
	blo _0805095A
_080509BE:
	movs r0, #0
	str r0, [r6, #0x6c]
	str r0, [r6, #0x74]
	movs r0, #0x6d
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08050A08
	add r4, sp, #0x10
_080509D0:
	bl VM_GetPC
	cmp r0, #0
	beq _080509F8
	bl Script_GetValue
	strb r0, [r4]
	ldr r0, [r6, #0x6c]
	adds r0, #1
	str r0, [r6, #0x6c]
	b _080509FA
	.align 2, 0
_080509E8: .4byte 0x03002CF0
_080509EC: .4byte 0x030046B8
_080509F0: .4byte 0x000003FF
_080509F4: .4byte 0x0203B400
_080509F8:
	strb r0, [r4]
_080509FA:
	adds r4, #1
	mov r0, sp
	adds r0, #0x1f
	cmp r4, r0
	ble _080509D0
	ldr r1, [r6, #0x6c]
	b _08050A1A
_08050A08:
	ldr r1, [r6, #0x6c]
	movs r2, #0
	mov r0, sp
	adds r0, #0x1f
_08050A10:
	strb r2, [r0]
	subs r0, #1
	add r3, sp, #0x10
	cmp r0, r3
	bge _08050A10
_08050A1A:
	cmp r1, #0
	beq _08050A9C
	ldr r0, _08050B64 @ =0x03002CF0
	ldrb r3, [r0]
	movs r5, #0
	mov r8, r5
	cmp r8, r1
	bhs _08050A9C
	movs r7, #1
	mov sl, r7
	adds r0, r6, #0
	adds r0, #0x98
	str r0, [sp, #0x28]
	ldr r1, _08050B68 @ =0x030046B8
	mov sb, r1
	add r2, sp, #0x10
	mov ip, r2
_08050A3C:
	movs r1, #0xf
	ands r1, r3
	mov r0, sl
	lsls r0, r1
	ldr r2, [r6, #0x74]
	ands r0, r2
	adds r4, r2, #0
	cmp r0, #0
	beq _08050A62
	movs r7, #0xf
	movs r5, #1
_08050A52:
	adds r1, r3, #0
	ands r1, r7
	adds r3, #1
	adds r0, r5, #0
	lsls r0, r1
	ands r0, r2
	cmp r0, #0
	bne _08050A52
_08050A62:
	mov r0, sl
	lsls r0, r1
	orrs r4, r0
	str r4, [r6, #0x74]
	lsls r0, r1, #1
	ldr r5, [sp, #0x28]
	adds r0, r5, r0
	mov r7, ip
	ldrb r1, [r7]
	strh r1, [r0]
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _08050B6C @ =0x000003FF
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _08050B70 @ =0x0203B400
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r3, r3, r0
	movs r7, #1
	add ip, r7
	movs r0, #1
	add r8, r0
	ldr r0, [r6, #0x6c]
	cmp r8, r0
	blo _08050A3C
_08050A9C:
	movs r0, #0
	str r0, [r6, #0x18]
	movs r1, #0
	strh r0, [r6, #0x1c]
	strh r0, [r6, #0x1e]
	str r0, [r6, #0x20]
	ldr r2, [sp, #0x34]
	strb r1, [r2]
	ldr r3, [sp, #0x38]
	strb r1, [r3]
	ldr r5, [sp, #0x3c]
	strb r1, [r5]
	ldr r7, [sp, #0x44]
	strb r1, [r7]
	movs r2, #1
	ldr r3, [sp, #0x40]
	strb r2, [r3]
	ldr r5, [sp, #0x2c]
	strb r1, [r5]
	ldr r7, [sp, #0x30]
	strb r2, [r7]
	str r0, [r6, #0x24]
	ldr r0, _08050B74 @ =FUN_0804f8ec
	ldr r1, _08050B78 @ =FUN_0804f82c
	ldr r2, _08050B7C @ =FUN_0804f950
	ldr r3, _08050B80 @ =FUN_0804f970
	bl FUN_0804e4dc
	movs r0, #0
	mov r8, r0
	movs r4, #0
	movs r5, #0x64
	adds r1, r6, #0
	adds r1, #0x40
	adds r3, r6, #0
	adds r3, #0x3c
_08050AE4:
	mov r7, r8
	adds r2, r3, r7
	movs r0, #3
_08050AEA:
	strb r4, [r2]
	subs r0, #1
	cmp r0, #0
	bge _08050AEA
	strb r5, [r1]
	strb r5, [r1, #1]
	strb r4, [r1, #2]
	strb r4, [r1, #3]
	str r4, [r1, #4]
	adds r1, #0xc
	adds r3, #0xc
	movs r0, #1
	add r8, r0
	mov r2, r8
	cmp r2, #1
	ble _08050AE4
	ldr r1, [sp, #0x48]
	movs r2, #0
	adds r0, r1, #3
_08050B10:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _08050B10
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0804fb04
	adds r0, r6, #0
	movs r1, #1
	bl FUN_0804fb04
	movs r0, #0
	movs r1, #0
	bl FUN_08051b70
	bl FUN_08052250
	str r0, [r6, #0x60]
	bl FUN_08052ffc
	str r0, [r6, #0x64]
	movs r0, #4
	movs r1, #0x18
	bl FUN_0804e9f4
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08050B5C
	bl FUN_0823d340
	adds r1, r6, #0
	adds r1, #0xb8
	str r0, [r1]
	cmp r0, #0
	bne _08050B84
_08050B5C:
	movs r0, #1
	rsbs r0, r0, #0
	b _08050C60
	.align 2, 0
_08050B64: .4byte 0x03002CF0
_08050B68: .4byte 0x030046B8
_08050B6C: .4byte 0x000003FF
_08050B70: .4byte 0x0203B400
_08050B74: .4byte FUN_0804f8ec
_08050B78: .4byte FUN_0804f82c
_08050B7C: .4byte FUN_0804f950
_08050B80: .4byte FUN_0804f970
_08050B84:
	adds r1, r6, #0
	adds r1, #0xc8
	movs r0, #0
	str r0, [r1]
	movs r0, #0x4d
	movs r1, #0xb
	bl VM_GetKeywordValue
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08050B5C
	movs r5, #0xd7
	lsls r5, r5, #1
	adds r4, r6, r5
	movs r7, #3
	mov r8, r7
_08050BB0:
	bl Script_GetValue
	strh r0, [r4]
	adds r4, #2
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _08050BB0
	ldr r0, _08050C10 @ =0x0000CB05
	ldr r1, _08050C14 @ =0x00005D04
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _08050B5C
	adds r4, r6, #0
	adds r4, #0xcc
	adds r1, r4, #0
	adds r0, r2, #0
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	movs r7, #0
	mov r8, r7
	mov sb, r4
	ldr r7, _08050C18 @ =0xFFFF0000
	add r5, sp, #0x20
	adds r4, #0x20
_08050BFA:
	mov r0, r8
	cmp r0, #0
	bne _08050C1C
	ldr r0, [sp, #0x20]
	ands r0, r7
	movs r1, #0x84
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r2, #0xd4
	b _08050C28
	.align 2, 0
_08050C10: .4byte 0x0000CB05
_08050C14: .4byte 0x00005D04
_08050C18: .4byte 0xFFFF0000
_08050C1C:
	ldr r0, [sp, #0x20]
	ands r0, r7
	movs r1, #0xdc
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r2, #0xd7
_08050C28:
	ldr r1, _08050C70 @ =0x0000FFFF
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x20]
	ldr r0, [r5, #4]
	ands r0, r7
	str r0, [r5, #4]
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	ldr r3, _08050C74 @ =0x00010010
	bl FUN_0822f3fc
	adds r4, #0x60
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #1
	ble _08050BFA
	movs r0, #0
_08050C60:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08050C70: .4byte 0x0000FFFF
_08050C74: .4byte 0x00010010
