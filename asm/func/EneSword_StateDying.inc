	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x3c
	adds r7, r0, #0
	movs r0, #1
	adds r2, r7, #0
	adds r2, #0x45
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08197E18
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0x5a
	strb r1, [r0]
	movs r0, #1
	b _08197E1A
_08197E18:
	movs r0, #0
_08197E1A:
	movs r1, #0x58
	adds r1, r1, r7
	mov r8, r1
	cmp r0, #0
	beq _08197F06
	movs r2, #0x60
	adds r2, r2, r7
	mov sl, r2
	adds r3, r7, #0
	adds r3, #0x59
	str r3, [sp, #0x34]
	adds r0, r7, #0
	adds r0, #0x5c
	str r0, [sp, #0x38]
	movs r1, #1
	mov ip, r1
	movs r2, #5
	mov sb, r2
	ldr r3, _08197F9C @ =0x00000565
	adds r2, r7, r3
	ldr r0, _08197FA0 @ =0x0000053C
	adds r3, r7, r0
	movs r6, #0
	movs r5, #0xc6
	lsls r5, r5, #1
	movs r4, #3
_08197E4E:
	adds r0, r6, r7
	ldr r1, _08197FA4 @ =0x0000056A
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08197E6E
	mov r0, ip
	strb r0, [r2, #5]
	mov r1, sb
	strb r1, [r2, #6]
	ldrb r0, [r2]
	mov r1, ip
	orrs r1, r0
	strb r1, [r2]
	ldr r0, _08197FA8 @ =EneSword_SlaveStateDying
	str r0, [r3, #0x74]
_08197E6E:
	adds r2, r2, r5
	adds r3, r3, r5
	adds r6, r6, r5
	subs r4, #1
	cmp r4, #0
	bge _08197E4E
	movs r4, #0
	movs r6, #1
	movs r5, #4
	adds r3, r7, #0
_08197E82:
	movs r0, #0x2c
	muls r0, r4, r0
	mov r1, sl
	adds r2, r1, r0
	ldr r1, [r2]
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _08197EAE
	orrs r1, r6
	str r1, [r2]
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r3, r2
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
	ldr r0, _08197FAC @ =0x000002C6
	adds r1, r3, r0
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
_08197EAE:
	adds r3, #0x50
	adds r4, #1
	cmp r4, #3
	ble _08197E82
	ldr r2, _08197FB0 @ =0x00000B9A
	adds r1, r7, r2
	ldrh r0, [r1]
	movs r2, #4
	movs r3, #0
	movs r4, #0
	orrs r0, r2
	strh r0, [r1]
	ldr r0, _08197FB4 @ =0x00000BEA
	adds r1, r7, r0
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	ldr r1, _08197FB8 @ =0x00000C9E
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, _08197FBC @ =0x00000CCF
	adds r0, r7, r2
	strb r3, [r0]
	mov r0, r8
	strb r3, [r0]
	movs r0, #0x1e
	ldr r1, [sp, #0x34]
	strb r0, [r1]
	ldr r2, [sp, #0x38]
	ldrh r0, [r2]
	bl AddPlayerExp
	movs r3, #0xcd
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	movs r2, #0x3e
	ldrsh r1, [r7, r2]
	bl Player_AddWeaponExp
	ldr r3, _08197FC0 @ =0x00000CC4
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
_08197F06:
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08197F18
	adds r0, r7, #0
	bl _call_via_r1
_08197F18:
	ldr r2, _08197FB8 @ =0x00000C9E
	adds r0, r7, r2
	ldrh r0, [r0]
	movs r1, #2
	bl Mod
	adds r3, r0, #0
	cmp r3, #0
	beq _08197F2C
	b _08198218
_08197F2C:
	movs r0, #0xae
	lsls r0, r0, #4
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	mov r1, r8
	strb r3, [r1]
	adds r6, r7, #0
	adds r6, #0x59
	ldrb r0, [r6]
	subs r0, #1
	strb r0, [r6]
	ldr r2, _08197FC4 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _08197FC8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r2
	movs r1, #0x28
	orrs r0, r1
	str r0, [r4, #4]
	ldr r2, _08197FCC @ =0x00000AFC
	adds r0, r7, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	add r5, sp, #0x1c
	str r3, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _08197FD0 @ =0x05000002
	bl CpuSet
	ldr r3, _08197FBC @ =0x00000CCF
	adds r0, r7, r3
	ldrb r0, [r0]
	str r6, [sp, #0x34]
	mov sb, r4
	cmp r0, #4
	bhi _08198068
	lsls r0, r0, #2
	ldr r1, _08197FD4 @ =_08197FD8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08197F9C: .4byte 0x00000565
_08197FA0: .4byte 0x0000053C
_08197FA4: .4byte 0x0000056A
_08197FA8: .4byte EneSword_SlaveStateDying
_08197FAC: .4byte 0x000002C6
_08197FB0: .4byte 0x00000B9A
_08197FB4: .4byte 0x00000BEA
_08197FB8: .4byte 0x00000C9E
_08197FBC: .4byte 0x00000CCF
_08197FC0: .4byte 0x00000CC4
_08197FC4: .4byte 0xFFFF0000
_08197FC8: .4byte 0x0000FFFF
_08197FCC: .4byte 0x00000AFC
_08197FD0: .4byte 0x05000002
_08197FD4: .4byte _08197FD8
_08197FD8: @ jump table
	.4byte _08197FEC @ case 0
	.4byte _08198010 @ case 1
	.4byte _08198028 @ case 2
	.4byte _08198040 @ case 3
	.4byte _08198058 @ case 4
_08197FEC:
	ldr r1, _08198008 @ =0x0000FF88
	strh r1, [r5]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r0, _0819800C @ =0x00000CCF
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0xb7
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08198068
	.align 2, 0
_08198008: .4byte 0x0000FF88
_0819800C: .4byte 0x00000CCF
_08198010:
	ldr r1, _08198020 @ =0x0000FFB5
	strh r1, [r5]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r2, _08198024 @ =0x00000CCF
	adds r1, r7, r2
	b _0819804C
	.align 2, 0
_08198020: .4byte 0x0000FFB5
_08198024: .4byte 0x00000CCF
_08198028:
	ldr r1, _08198038 @ =0x0000FFE2
	strh r1, [r5]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r3, _0819803C @ =0x00000CCF
	adds r1, r7, r3
	b _0819804C
	.align 2, 0
_08198038: .4byte 0x0000FFE2
_0819803C: .4byte 0x00000CCF
_08198040:
	movs r1, #0xf
	strh r1, [r5]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r0, _08198054 @ =0x00000CCF
	adds r1, r7, r0
_0819804C:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08198068
	.align 2, 0
_08198054: .4byte 0x00000CCF
_08198058:
	movs r2, #0
	movs r1, #0x3c
	strh r1, [r5]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r1, _08198090 @ =0x00000CCF
	adds r0, r7, r1
	strb r2, [r0]
_08198068:
	movs r2, #0
	ldrsh r3, [r5, r2]
	ldr r2, _08198094 @ =gSineTable
	ldr r1, _08198098 @ =0x00000AE6
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r6, r2, #0
	cmp r0, #0
	blt _0819809C
	asrs r0, r0, #0xc
	b _081980A2
	.align 2, 0
_08198090: .4byte 0x00000CCF
_08198094: .4byte gSineTable
_08198098: .4byte 0x00000AE6
_0819809C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081980A2:
	adds r2, r0, #0
	movs r3, #4
	ldrsh r1, [r5, r3]
	ldr r3, _081980C0 @ =0x00000AE6
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _081980C4
	asrs r0, r0, #0xc
	b _081980CA
	.align 2, 0
_081980C0: .4byte 0x00000AE6
_081980C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081980CA:
	add r3, sp, #0x24
	adds r1, r2, r0
	ldrh r0, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08198100 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	movs r2, #0
	ldrsh r1, [r5, r2]
	ldr r2, _08198104 @ =0x00000AE6
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _08198108
	asrs r0, r0, #0xc
	b _0819810C
	.align 2, 0
_08198100: .4byte 0xFFFF0000
_08198104: .4byte 0x00000AE6
_08198108:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_0819810C:
	adds r4, r0, #0
	movs r0, #4
	ldrsh r2, [r5, r0]
	ldr r1, _08198130 @ =0x00000AE6
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _08198134
	asrs r0, r0, #0xc
	b _0819813A
	.align 2, 0
_08198130: .4byte 0x00000AE6
_08198134:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819813A:
	adds r1, r4, r0
	ldrh r2, [r3, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _081981E0 @ =0xFFFF0000
	mov r8, r0
	ldr r0, [r3, #4]
	mov r2, r8
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #0
	str r0, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	movs r5, #1
	str r5, [sp, #0xc]
	adds r0, r3, #0
	movs r1, #2
	mov r2, sb
	movs r3, #0
	bl EmitSmoke
	ldr r3, [sp, #0x34]
	ldrb r6, [r3]
	cmp r6, #0
	bne _08198230
	ldr r1, _081981E4 @ =0x00000B28
	adds r0, r7, r1
	bl AuxShadow_Hide
	adds r0, r7, #0
	adds r0, #0x4a
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r2, r7, #0
	adds r2, #0x45
	ldrb r1, [r2]
	adds r0, r5, #0
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r7, #0x18]
	ldr r0, [r0, #0x1c]
	cmp r0, #4
	beq _08198230
	ldr r2, _081981E8 @ =0x00000CD8
	adds r0, r7, r2
	ldr r2, [r0]
	cmp r2, #0
	beq _08198230
	ldr r0, [sp, #0x2c]
	mov r3, r8
	ands r0, r3
	orrs r0, r4
	str r0, [sp, #0x2c]
	ldr r1, _081981EC @ =0x00000CDC
	adds r0, r7, r1
	add r1, sp, #0x2c
	str r0, [r1, #4]
	adds r0, r2, #0
	bl VM_ExecByID
	ldr r2, _081981F0 @ =0x00000CC5
	adds r0, r7, r2
	ldrb r1, [r0]
	movs r0, #0xc
	bl EnemyDex_GetEntryIdx
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _081981F8
	ldr r0, _081981F4 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r1, r5, #0
	lsls r1, r3
	b _0819820A
	.align 2, 0
_081981E0: .4byte 0xFFFF0000
_081981E4: .4byte 0x00000B28
_081981E8: .4byte 0x00000CD8
_081981EC: .4byte 0x00000CDC
_081981F0: .4byte 0x00000CC5
_081981F4: .4byte 0x030046A0
_081981F8:
	ldr r0, _08198214 @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r5, #0
	lsls r1, r0
_0819820A:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	b _08198230
	.align 2, 0
_08198214: .4byte 0x030046A0
_08198218:
	movs r3, #0xae
	lsls r3, r3, #4
	adds r2, r7, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08198230:
	ldr r2, _0819824C @ =0x00000C9E
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	add sp, #0x3c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819824C: .4byte 0x00000C9E
