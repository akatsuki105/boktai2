	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r0, _081D4824 @ =0x03000194
	ldr r0, [r0]
	str r0, [sp, #8]
	cmp r0, #0
	bne _081D47CC
	b _081D4E72
_081D47CC:
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	bl ElevatorController_AllocSlot
	mov r8, r0
	cmp r0, #0
	bne _081D47DE
	b _081D4E72
_081D47DE:
	mov r4, r8
	adds r4, #0xb4
	mov r1, sp
	ldrh r1, [r1, #0xc]
	strh r1, [r4]
	mov r5, r8
	adds r5, #0xb8
	mov r2, sp
	ldrh r2, [r2, #0xc]
	strh r2, [r5]
	mov sb, r8
	movs r0, #0x72
	bl VM_SeekToNamedArg
	mov sl, r4
	str r5, [sp, #0x1c]
	mov r1, r8
	adds r1, #0xe4
	str r1, [sp, #0x20]
	mov r2, r8
	adds r2, #0xe5
	str r2, [sp, #0x10]
	adds r1, #2
	str r1, [sp, #0x14]
	cmp r0, #0
	beq _081D4862
	bl VM_GetPC
	cmp r0, #0
	beq _081D4828
	bl VM_GetValue
	adds r1, r0, #0
	b _081D482A
	.align 2, 0
_081D4824: .4byte 0x03000194
_081D4828:
	movs r1, #0
_081D482A:
	mov r5, r8
	adds r5, #0xe4
	movs r0, #0
	strb r1, [r5]
	mov r4, r8
	adds r4, #0xe5
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x20]
	str r4, [sp, #0x10]
	cmp r0, #0
	beq _081D484A
	bl VM_GetValue
	b _081D484C
_081D484A:
	movs r0, #0
_081D484C:
	mov r4, r8
	adds r4, #0xe6
	strb r0, [r4]
	mov r0, sb
	adds r0, #0x1c
	ldr r2, [sp, #0x20]
	ldrb r1, [r2]
	ldrb r2, [r4]
	bl FUN_08234f90
	str r4, [sp, #0x14]
_081D4862:
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r4, r8
	adds r4, #0xe7
	strb r0, [r4]
	movs r0, #0x59
	bl VM_SeekToNamedArg
	str r4, [sp, #0x18]
	cmp r0, #0
	beq _081D4900
	subs r4, #0x1b
	bl VM_GetPC
	adds r5, r4, #0
	cmp r0, #0
	beq _081D488E
	bl VM_GetValue
	b _081D4890
_081D488E:
	movs r0, #0
_081D4890:
	str r0, [r4]
	mov r4, r8
	adds r4, #0xd0
	bl VM_GetPC
	adds r6, r4, #0
	cmp r0, #0
	beq _081D48A6
	bl VM_GetValue
	b _081D48A8
_081D48A6:
	movs r0, #0
_081D48A8:
	str r0, [r4]
	bl VM_GetPC
	cmp r0, #0
	beq _081D48BA
	bl VM_GetValue
	adds r2, r0, #0
	b _081D48BC
_081D48BA:
	movs r2, #0
_081D48BC:
	ldr r0, [sp, #0x18]
	ldrb r1, [r0]
	cmp r1, #2
	bne _081D48F0
	ldr r0, [r5]
	cmp r2, r0
	bne _081D48DC
	mov r1, sb
	strh r2, [r1, #0x1e]
	movs r0, #3
	rsbs r0, r0, #0
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081D48F6
_081D48DC:
	ldr r0, [r6]
	cmp r2, r0
	bne _081D48F6
	mov r0, sb
	strh r2, [r0, #0x1e]
	mov r2, sl
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	b _081D48F6
_081D48F0:
	ldr r0, [r5]
	mov r1, sb
	strh r0, [r1, #0x1e]
_081D48F6:
	mov r2, sb
	ldrh r0, [r2, #0x1e]
	mov r1, r8
	adds r1, #0xfe
	strh r0, [r1]
_081D4900:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r6, r8
	adds r6, #0xd4
	strh r0, [r6]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r1, r8
	adds r1, #0xc0
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r1, r8
	adds r1, #0xc2
	strh r0, [r1]
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r1, r8
	adds r1, #0xc4
	strh r0, [r1]
	movs r0, #0x54
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r5, r8
	adds r5, #0xc8
	strh r0, [r5]
	mov r4, r8
	adds r4, #0x2c
	ldr r1, _081D4964 @ =0x0000B019
	adds r0, r4, #0
	bl Video_GetAuxSprite
	ldr r0, [sp, #0x18]
	ldrb r7, [r0]
	cmp r7, #1
	beq _081D4A1C
	cmp r7, #1
	bgt _081D4968
	cmp r7, #0
	beq _081D4974
	b _081D4B4E
	.align 2, 0
_081D4964: .4byte 0x0000B019
_081D4968:
	cmp r7, #2
	bne _081D496E
	b _081D4AA8
_081D496E:
	cmp r7, #3
	beq _081D49C8
	b _081D4B4E
_081D4974:
	mov r0, r8
	adds r0, #0xcc
	ldr r0, [r0]
	mov r1, sb
	strh r0, [r1, #0x1e]
	mov r1, r8
	adds r1, #0xb2
	movs r0, #1
	strh r0, [r1]
	adds r1, #0x26
	ldr r0, _081D49BC @ =FUN_081d3534
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D49C0 @ =FUN_081d3c24
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D49C4 @ =FUN_081d33f8
	str r0, [r1]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081D49B8
	mov r1, r8
	adds r1, #0xd6
	strh r0, [r1]
_081D49B8:
	strh r7, [r5]
	b _081D4B4E
	.align 2, 0
_081D49BC: .4byte FUN_081d3534
_081D49C0: .4byte FUN_081d3c24
_081D49C4: .4byte FUN_081d33f8
_081D49C8:
	mov r0, r8
	adds r0, #0xcc
	ldr r0, [r0]
	mov r1, sb
	strh r0, [r1, #0x1e]
	mov r1, r8
	adds r1, #0xb2
	movs r0, #1
	strh r0, [r1]
	adds r1, #0x26
	ldr r0, _081D4A10 @ =FUN_081d3534
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4A14 @ =FUN_081d3c24
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4A18 @ =FUN_081d33f8
	str r0, [r1]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081D4A9C
	mov r1, r8
	adds r1, #0xd6
	strh r0, [r1]
	b _081D4A9C
	.align 2, 0
_081D4A10: .4byte FUN_081d3534
_081D4A14: .4byte FUN_081d3c24
_081D4A18: .4byte FUN_081d33f8
_081D4A1C:
	mov r0, r8
	adds r0, #0xcc
	ldr r0, [r0]
	mov r1, sb
	strh r0, [r1, #0x1e]
	mov r0, r8
	adds r0, #0xb2
	strh r7, [r0]
	mov r1, r8
	adds r1, #0xd8
	ldr r0, _081D4A54 @ =FUN_081d36c0
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4A58 @ =FUN_081d3dd0
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4A5C @ =FUN_081d33f8
	str r0, [r1]
	movs r2, #2
	str r2, [sp, #0xc]
	ldrh r0, [r5]
	cmp r0, #1
	beq _081D4A70
	cmp r0, #1
	bgt _081D4A60
	cmp r0, #0
	beq _081D4A66
	b _081D4A84
	.align 2, 0
_081D4A54: .4byte FUN_081d36c0
_081D4A58: .4byte FUN_081d3dd0
_081D4A5C: .4byte FUN_081d33f8
_081D4A60:
	cmp r0, #2
	beq _081D4A7C
	b _081D4A84
_081D4A66:
	ldr r1, _081D4A6C @ =0x000001B9
	b _081D4A74
	.align 2, 0
_081D4A6C: .4byte 0x000001B9
_081D4A70:
	movs r1, #0xde
	lsls r1, r1, #1
_081D4A74:
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	b _081D4A84
_081D4A7C:
	ldr r1, _081D4AA4 @ =0x000001BD
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
_081D4A84:
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081D4A96
	mov r1, r8
	adds r1, #0xd6
	strh r0, [r1]
_081D4A96:
	ldrh r0, [r5]
	cmp r0, #2
	bls _081D4B4E
_081D4A9C:
	movs r0, #0
	strh r0, [r5]
	b _081D4B4E
	.align 2, 0
_081D4AA4: .4byte 0x000001BD
_081D4AA8:
	mov r1, r8
	adds r1, #0xb2
	movs r0, #4
	strh r0, [r1]
	adds r1, #0x26
	ldr r0, _081D4AD8 @ =FUN_081d38a4
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4ADC @ =FUN_081d3a8c
	str r0, [r1]
	adds r1, #4
	ldr r0, _081D4AE0 @ =FUN_081d33f8
	str r0, [r1]
	movs r0, #0
	str r0, [sp, #0xc]
	ldrh r0, [r5]
	cmp r0, #1
	beq _081D4AFC
	cmp r0, #1
	bgt _081D4AE4
	cmp r0, #0
	beq _081D4AEE
	b _081D4B20
	.align 2, 0
_081D4AD8: .4byte FUN_081d38a4
_081D4ADC: .4byte FUN_081d3a8c
_081D4AE0: .4byte FUN_081d33f8
_081D4AE4:
	cmp r0, #2
	beq _081D4B0C
	cmp r0, #3
	beq _081D4B18
	b _081D4B20
_081D4AEE:
	adds r0, r4, #0
	ldr r1, _081D4AF8 @ =0x000001B7
	bl Video_SetAuxSpritePltt
	b _081D4B20
	.align 2, 0
_081D4AF8: .4byte 0x000001B7
_081D4AFC:
	adds r0, r4, #0
	ldr r1, _081D4B08 @ =0x000001B9
	bl Video_SetAuxSpritePltt
	b _081D4B20
	.align 2, 0
_081D4B08: .4byte 0x000001B9
_081D4B0C:
	adds r0, r4, #0
	movs r1, #0xdf
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	b _081D4B20
_081D4B18:
	adds r0, r4, #0
	ldr r1, _081D4BA0 @ =0x000001BD
	bl Video_SetAuxSpritePltt
_081D4B20:
	movs r0, #0x6d
	movs r1, #1
	bl VM_GetNamedArgValue
	mov r1, r8
	adds r1, #0xd6
	strh r0, [r1]
	movs r0, #0x77
	movs r1, #0x78
	bl VM_GetNamedArgValue
	mov r7, r8
	adds r7, #0xbc
	strh r0, [r7]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081D4B4E
	ldrh r0, [r7]
	ldr r1, [sp, #0x1c]
	strh r0, [r1]
_081D4B4E:
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r4, r8
	adds r4, #0x48
	ldr r2, [sp, #8]
	ldr r1, [r2, #0x18]
	ldr r2, [sp, #0xc]
	ldrb r3, [r5]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	bl AuxAnim_SetAnim
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, r8
	ldr r1, [r2, #0x48]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, sb
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D4BA4
	mov r2, sb
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D4BB0
	.align 2, 0
_081D4BA0: .4byte 0x000001BD
_081D4BA4:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, sb
_081D4BB0:
	str r0, [r2]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D4BD6
	mov r1, sb
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D4BE0
_081D4BD6:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D4BE0:
	mov r2, sb
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D4C18 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D4C50
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D4C1C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D4C12
	ldrb r0, [r4, #5]
_081D4C12:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D4C2C
	.align 2, 0
_081D4C18: .4byte 0x0000FFFF
_081D4C1C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D4C2C
	strh r1, [r4, #8]
_081D4C2C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D4C50
	movs r0, #1
	strb r0, [r4, #7]
_081D4C50:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	movs r7, #0
	movs r0, #2
	strb r0, [r2, #7]
	mov r4, r8
	adds r4, #0xf4
	mov r0, r8
	adds r0, #0xb0
	ldr r2, _081D4D20 @ =0xFFFFD0E9
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r2, sb
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Mover_Init
	adds r0, r4, #0
	mov r1, sb
	bl Mover_SetAuxSprite
	mov r5, r8
	adds r5, #0xe8
	ldr r1, [sp, #0x20]
	ldrb r2, [r1]
	ldr r0, [sp, #0x10]
	ldrb r3, [r0]
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	bl Mover_SetPath
	str r7, [r4, #0x18]
	ldr r2, _081D4D24 @ =0xFFFFFF00
	adds r0, r2, #0
	mov r1, sb
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	mov r2, sb
	strh r0, [r2, #0x1c]
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r5
	cmp r0, #0
	beq _081D4CD6
	movs r0, #0x80
	mov r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D4CD6:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081D4CEE
	movs r0, #0x80
	lsls r0, r0, #5
	mov r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D4CEE:
	mov r1, r8
	adds r1, #0xb6
	movs r0, #0
	strb r0, [r1]
	mov r0, r8
	adds r0, #0xc6
	strh r7, [r0]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	cmp r5, #0
	bne _081D4D0C
	b _081D4E26
_081D4D0C:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1]
	cmp r0, #2
	beq _081D4D34
	cmp r0, #2
	bgt _081D4D28
	cmp r0, #0
	blt _081D4D3C
	b _081D4D2C
	.align 2, 0
_081D4D20: .4byte 0xFFFFD0E9
_081D4D24: .4byte 0xFFFFFF00
_081D4D28:
	cmp r0, #3
	bne _081D4D3C
_081D4D2C:
	mov r1, r8
	adds r1, #0xb2
	movs r0, #1
	b _081D4D3A
_081D4D34:
	mov r1, r8
	adds r1, #0xb2
	movs r0, #4
_081D4D3A:
	strh r0, [r1]
_081D4D3C:
	ldr r2, [sp, #8]
	ldr r0, _081D4DA0 @ =0x000012B0
	adds r4, r2, r0
	ldrh r0, [r4]
	movs r1, #0
	bl FUN_081d3fac
	ldrh r0, [r6]
	strh r0, [r4]
	ldr r4, _081D4DA4 @ =0x03002BE0
	ldr r0, [r4]
	ldrh r2, [r6]
	movs r1, #1
	bl FUN_0807a97c
	movs r0, #8
	mov r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, [r4]
	ldr r0, _081D4DA8 @ =0x0000060E
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #1
	orrs r0, r2
	strb r0, [r1]
	mov r1, r8
	adds r1, #0xfc
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	adds r7, r1, #0
	cmp r3, #0
	blt _081D4D9C
	cmp r2, #0
	blt _081D4D9C
	ldr r0, _081D4DAC @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081D4D9C
	ldr r0, _081D4DB0 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _081D4DB4
_081D4D9C:
	movs r2, #0
	b _081D4DC2
	.align 2, 0
_081D4DA0: .4byte 0x000012B0
_081D4DA4: .4byte 0x03002BE0
_081D4DA8: .4byte 0x0000060E
_081D4DAC: .4byte 0x030046A8
_081D4DB0: .4byte 0x030046AC
_081D4DB4:
	ldr r0, _081D4E84 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r3
_081D4DC2:
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, r8
	mov r1, r8
	adds r1, #0xfe
	ldrh r3, [r1]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x18
	movs r1, #0xff
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl FUN_08234270
	movs r0, #1
	mov r2, sl
	ldrh r1, [r2]
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _081D4E88 @ =0x03002BE0
	ldr r0, [r0]
	adds r1, r7, #0
	bl FUN_0807a91c
	cmp r5, #2
	bne _081D4E26
	adds r0, r7, #0
	bl FUN_08086a4c
	ldr r0, [sp, #8]
	ldr r1, _081D4E8C @ =0x000012B2
	adds r4, r0, r1
	ldrh r0, [r4]
	movs r1, #1
	bl FUN_081d3fac
	ldrh r0, [r6]
	strh r0, [r4]
	ldrh r1, [r6]
	movs r0, #3
	bl FUN_080869c8
	movs r0, #0x10
	mov r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D4E26:
	ldr r0, [sp, #8]
	mov r1, r8
	bl FUN_081d4704
	movs r0, #0x73
	movs r1, #6
	bl VM_GetNamedArgValue
	mov r2, r8
	adds r2, #0xba
	strh r0, [r2]
	ldr r0, [sp, #0x18]
	ldrb r4, [r0]
	cmp r4, #0
	blt _081D4E6A
	cmp r4, #1
	ble _081D4E4C
	cmp r4, #3
	bne _081D4E6A
_081D4E4C:
	mov r1, r8
	adds r1, #0xfc
	movs r0, #0
	ldrsh r3, [r2, r0]
	mov r0, sb
	adds r2, r3, #0
	bl FUN_081d2660
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D4E6A
	mov r1, r8
	adds r1, #0xb2
	movs r0, #3
	strh r0, [r1]
_081D4E6A:
	mov r1, r8
	adds r1, #0xb7
	movs r0, #0
	strb r0, [r1]
_081D4E72:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D4E84: .4byte 0x030046A4
_081D4E88: .4byte 0x03002BE0
_081D4E8C: .4byte 0x000012B2
