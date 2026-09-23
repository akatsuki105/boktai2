	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081d8a04
FUN_081d8a04: @ 0x081D8A04
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, #0x6e
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d8a14
FUN_081d8a14: @ 0x081D8A14
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, #0x6e
	ldrh r2, [r0]
	bics r2, r1
	strh r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d8a24
FUN_081d8a24: @ 0x081D8A24
	push {lr}
	adds r0, #0x6e
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081D8A34
	movs r0, #0
	b _081D8A36
_081D8A34:
	movs r0, #1
_081D8A36:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d8a3c
FUN_081d8a3c: @ 0x081D8A3C
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r5, #0
	ldr r0, _081D8A58 @ =0x00000ECC
	adds r2, r3, r0
	movs r6, #1
_081D8A48:
	adds r1, r6, #0
	lsls r1, r5
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D8A5C
	movs r0, #1
	b _081D8A5E
	.align 2, 0
_081D8A58: .4byte 0x00000ECC
_081D8A5C:
	movs r0, #0
_081D8A5E:
	cmp r0, #0
	bne _081D8A88
	movs r0, #0xbc
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x1c
	adds r4, r3, r4
	adds r1, r6, #0
	lsls r1, r5
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	movs r1, #0xbc
	bl ClearMemory
	adds r0, r4, #0
	adds r0, #0x6c
	strh r5, [r0]
	adds r0, r4, #0
	b _081D8A90
_081D8A88:
	adds r5, #1
	cmp r5, #0x13
	ble _081D8A48
	movs r0, #0
_081D8A90:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d8a98
FUN_081d8a98: @ 0x081D8A98
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r0, _081D8B34 @ =0x030001A4
	ldr r6, [r0]
	cmp r6, #0
	bne _081D8AB0
	bl Entity8CC7_Create
	adds r6, r0, #0
	cmp r6, #0
	bne _081D8AB0
	b _081D8C78
_081D8AB0:
	adds r0, r6, #0
	bl FUN_081d8a3c
	adds r5, r0, #0
	cmp r5, #0
	bne _081D8ABE
	b _081D8C78
_081D8ABE:
	adds r7, r5, #0
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r1, _081D8B38 @ =0x00005A6E
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [r5, #0xc]
	ldr r1, _081D8B3C @ =0x0000014F
	bl Video_SetAuxSpritePltt
	adds r1, r5, #0
	adds r1, #0x68
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	strb r2, [r0]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D8B0A
	bl Script_GetValue
	strh r0, [r5, #0x1c]
	bl Script_GetValue
	strh r0, [r5, #0x1e]
	bl Script_GetValue
	strh r0, [r5, #0x20]
_081D8B0A:
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D8B40
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x60
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x62
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x64
	strh r0, [r1]
	b _081D8B52
	.align 2, 0
_081D8B34: .4byte 0x030001A4
_081D8B38: .4byte 0x00005A6E
_081D8B3C: .4byte 0x0000014F
_081D8B40:
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_081D8B52:
	movs r1, #0
	movs r0, #2
	strb r0, [r7, #7]
	adds r0, r5, #0
	adds r0, #0x6e
	strh r1, [r0]
	ldr r2, _081D8BB4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D8BB8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D8BBC @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #1
	ands r2, r0
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r1, [r6, #0x18]
	str r2, [sp]
	adds r0, r4, #0
	movs r2, #4
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8BC0
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D8BC8
	.align 2, 0
_081D8BB4: .4byte 0x030046B8
_081D8BB8: .4byte 0x000003FF
_081D8BBC: .4byte 0x0203B400
_081D8BC0:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D8BC8:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8BEC
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D8BF4
_081D8BEC:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D8BF4:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D8C2C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D8C64
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D8C30
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D8C24
	ldrb r0, [r4, #5]
_081D8C24:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D8C40
	.align 2, 0
_081D8C2C: .4byte 0x0000FFFF
_081D8C30:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D8C40
	strh r1, [r4, #8]
_081D8C40:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _081D8C64
	movs r0, #1
	strb r0, [r4, #7]
_081D8C64:
	adds r0, r5, #0
	adds r0, #0x7c
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #0
	bl ParticleShadow_Init
	adds r1, r5, #0
	adds r1, #0x79
	strb r0, [r1]
_081D8C78:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d8c80
FUN_081d8c80: @ 0x081D8C80
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	ble _081D8CA6
	movs r0, #1
	strb r0, [r2]
	movs r0, #3
	subs r0, r0, r1
	strb r0, [r3]
	b _081D8CAC
_081D8CA6:
	movs r0, #0
	strb r0, [r2]
	strb r1, [r3]
_081D8CAC:
	pop {r0}
	bx r0

	thumb_func_start FUN_081d8cb0
FUN_081d8cb0: @ 0x081D8CB0
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, _081D8D14 @ =0x03002BE0
	ldr r3, [r0]
	cmp r3, #0
	beq _081D8D18
	movs r0, #0x1c
	ldrsh r1, [r2, r0]
	movs r4, #0x2c
	ldrsh r0, [r3, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8CCC
	rsbs r1, r1, #0
_081D8CCC:
	adds r0, r2, #0
	adds r0, #0x60
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _081D8D18
	movs r0, #0x20
	ldrsh r1, [r2, r0]
	movs r4, #0x30
	ldrsh r0, [r3, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8CE8
	rsbs r1, r1, #0
_081D8CE8:
	adds r0, r2, #0
	adds r0, #0x64
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _081D8D18
	movs r0, #0x1e
	ldrsh r1, [r2, r0]
	movs r4, #0x2e
	ldrsh r0, [r3, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8D04
	rsbs r1, r1, #0
_081D8D04:
	adds r0, r2, #0
	adds r0, #0x62
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _081D8D18
	movs r0, #1
	b _081D8D1A
	.align 2, 0
_081D8D14: .4byte 0x03002BE0
_081D8D18:
	movs r0, #0
_081D8D1A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d8d20
FUN_081d8d20: @ 0x081D8D20
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080865c0
	adds r2, r0, #0
	cmp r2, #0
	beq _081D8D86
	movs r0, #0x1c
	ldrsh r1, [r4, r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8D3E
	rsbs r1, r1, #0
_081D8D3E:
	adds r0, r4, #0
	adds r0, #0x60
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _081D8D86
	movs r0, #0x20
	ldrsh r1, [r4, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8D5A
	rsbs r1, r1, #0
_081D8D5A:
	adds r0, r4, #0
	adds r0, #0x64
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _081D8D86
	movs r0, #0x1e
	ldrsh r1, [r4, r0]
	movs r3, #2
	ldrsh r0, [r2, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8D76
	rsbs r1, r1, #0
_081D8D76:
	adds r0, r4, #0
	adds r0, #0x62
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _081D8D86
	movs r0, #1
	b _081D8D88
_081D8D86:
	movs r0, #0
_081D8D88:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d8d90
FUN_081d8d90: @ 0x081D8D90
	push {lr}
	movs r2, #0xed
	lsls r2, r2, #4
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, #0
	beq _081D8DA6
	subs r0, #1
	str r0, [r1]
	movs r0, #0
	b _081D8DBA
_081D8DA6:
	movs r0, #0xe1
	lsls r0, r0, #4
	str r0, [r1]
	bl FUN_0823e1b0
	cmp r0, #2
	bgt _081D8DB8
	movs r0, #0
	b _081D8DBA
_081D8DB8:
	movs r0, #1
_081D8DBA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d8dc0
FUN_081d8dc0: @ 0x081D8DC0
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d8dc4
FUN_081d8dc4: @ 0x081D8DC4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	mov r8, r0
	adds r6, r1, #0
	adds r3, r6, #0
	adds r3, #0x74
	ldrb r0, [r3]
	cmp r0, #0
	bne _081D8DDC
	b _081D8F10
_081D8DDC:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r2, r6, #0
	adds r2, #0x72
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r3]
	ldr r5, _081D8E48 @ =0x0203B400
	ldr r2, _081D8E4C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D8E50 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r3, #1
	strb r0, [r3]
	ldrb r4, [r3]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r5, r6, #0
	adds r5, #0x58
	adds r7, r4, #0
	adds r1, #3
	mov ip, r1
	ldr r4, _081D8E54 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081D8E58
	asrs r1, r0, #0xc
	b _081D8E5E
	.align 2, 0
_081D8E48: .4byte 0x0203B400
_081D8E4C: .4byte 0x030046B8
_081D8E50: .4byte 0x000003FF
_081D8E54: .4byte 0x085B0A08
_081D8E58:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D8E5E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r7, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081D8E7A
	asrs r0, r0, #0xc
	b _081D8E80
_081D8E7A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D8E80:
	strh r0, [r5, #4]
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D8EC8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081D8ECC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #4
	adds r1, r6, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D8EC4
	cmp r1, #0
	blt _081D8EC4
	ldr r0, _081D8ED0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D8EC4
	ldr r0, _081D8ED4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D8ED8
_081D8EC4:
	movs r0, #0
	b _081D8EE6
	.align 2, 0
_081D8EC8: .4byte 0x000003FF
_081D8ECC: .4byte 0x0203B400
_081D8ED0: .4byte 0x030046A8
_081D8ED4: .4byte 0x030046AC
_081D8ED8:
	ldr r0, _081D8F40 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D8EE6:
	adds r2, r6, #0
	adds r2, #0x76
	strh r0, [r2]
	ldrb r0, [r3]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	adds r0, r6, #0
	adds r0, #0x2c
	mov r2, r8
	ldr r1, [r2, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #4
	bl FUN_08236fac
_081D8F10:
	adds r0, r6, #0
	bl FUN_081d8cb0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D8F5E
	adds r0, r6, #0
	bl FUN_081d8d20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D8F5E
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, _081D8F44 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _081D8F48 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D8F4C
	movs r0, #1
	b _081D8F4E
	.align 2, 0
_081D8F40: .4byte 0x030046A4
_081D8F44: .4byte 0x030046A0
_081D8F48: .4byte 0x00000934
_081D8F4C:
	movs r0, #0
_081D8F4E:
	cmp r0, #0
	bne _081D8F5E
	mov r0, r8
	bl FUN_081d8d90
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D8F6E
_081D8F5E:
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #3
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
	b _081D918E
_081D8F6E:
	adds r0, r6, #0
	adds r0, #0x1c
	ldrh r1, [r6, #0x1c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r5, r0, #0
	cmp r2, #0
	blt _081D8F98
	cmp r1, #0
	blt _081D8F98
	ldr r0, _081D8F9C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D8F98
	ldr r0, _081D8FA0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D8FA4
_081D8F98:
	movs r4, #0
	b _081D8FB2
	.align 2, 0
_081D8F9C: .4byte 0x030046A8
_081D8FA0: .4byte 0x030046AC
_081D8FA4:
	ldr r0, _081D8FC4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D8FB2:
	adds r7, r5, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D8FC8
	adds r0, #4
	b _081D8FD4
	.align 2, 0
_081D8FC4: .4byte 0x030046A4
_081D8FC8:
	ldr r0, _081D8FE8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D8FD4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081D8FEC
	cmp r2, #2
	beq _081D8FF0
	b _081D8FF4
	.align 2, 0
_081D8FE8: .4byte 0x030046A4
_081D8FEC:
	ldrb r0, [r7, #4]
	b _081D8FF2
_081D8FF0:
	ldrb r0, [r7]
_081D8FF2:
	subs r1, r1, r0
_081D8FF4:
	adds r7, r1, #0
	add r3, sp, #0xc
	adds r2, r6, #0
	adds r2, #0x58
	ldrh r1, [r6, #0x1c]
	ldrh r0, [r2]
	adds r1, r1, r0
	strh r1, [r3]
	ldrh r0, [r5, #2]
	ldrh r4, [r2, #2]
	adds r0, r0, r4
	strh r0, [r3, #2]
	ldrh r0, [r5, #4]
	ldrh r4, [r2, #4]
	adds r0, r0, r4
	strh r0, [r3, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _081D9034
	cmp r1, #0
	blt _081D9034
	ldr r0, _081D9038 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081D9034
	ldr r0, _081D903C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D9040
_081D9034:
	movs r1, #0
	b _081D904E
	.align 2, 0
_081D9038: .4byte 0x030046A8
_081D903C: .4byte 0x030046AC
_081D9040:
	ldr r0, _081D9064 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r4
_081D904E:
	adds r0, r6, #0
	adds r0, #0x76
	ldrh r0, [r0]
	cmp r0, r1
	bne _081D9068
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	b _081D9076
	.align 2, 0
_081D9064: .4byte 0x030046A4
_081D9068:
	movs r0, #0
	strh r0, [r2]
	adds r1, r6, #0
	adds r1, #0x5c
	strh r0, [r1]
	ldrh r0, [r3, #2]
	strh r0, [r6, #0x1e]
_081D9076:
	adds r1, r6, #0
	adds r1, #0x5a
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
	movs r1, #0x1e
	ldrsh r0, [r6, r1]
	cmp r7, r0
	blt _081D90B0
	strh r7, [r6, #0x1e]
	add r0, sp, #8
	movs r1, #0
	str r1, [sp, #8]
	adds r1, r2, #0
	ldr r2, _081D90AC @ =0x05000002
	bl CpuSet
	adds r1, r6, #0
	adds r1, #0x68
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x74
	strb r2, [r0]
	b _081D918E
	.align 2, 0
_081D90AC: .4byte 0x05000002
_081D90B0:
	adds r4, r6, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
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
	beq _081D90E0
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D90E8
_081D90E0:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D90E8:
	str r0, [r6]
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
	beq _081D910C
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D9114
_081D910C:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D9114:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D914C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D9184
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D9150
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D9144
	ldrb r0, [r4, #5]
_081D9144:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D9160
	.align 2, 0
_081D914C: .4byte 0x0000FFFF
_081D9150:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D9160
	strh r1, [r4, #8]
_081D9160:
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
	bne _081D9184
	movs r0, #1
	strb r0, [r4, #7]
_081D9184:
	adds r1, r6, #0
	adds r1, #0x72
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081D918E:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d919c
FUN_081d919c: @ 0x081D919C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r6, r1, #0
	adds r7, r6, #0
	adds r7, #0x74
	ldrb r0, [r7]
	cmp r0, #0
	beq _081D91F8
	ldr r5, _081D9228 @ =0x0203B400
	ldr r2, _081D922C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _081D9230 @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x5a
	adds r3, r6, #0
	adds r3, #0x70
	movs r1, #0
	strh r0, [r3]
	strb r1, [r7]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r7, r3, #0
	cmp r0, #0x17
	bgt _081D91F8
	adds r0, r6, #0
	movs r1, #1
	bl FUN_081d8a04
	ldrh r0, [r7]
	adds r0, #0x3c
	strh r0, [r7]
_081D91F8:
	adds r0, r6, #0
	bl FUN_081d8cb0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D924E
	adds r0, r6, #0
	bl FUN_081d8d20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D924E
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, _081D9234 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _081D9238 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D923C
	movs r0, #1
	b _081D923E
	.align 2, 0
_081D9228: .4byte 0x0203B400
_081D922C: .4byte 0x030046B8
_081D9230: .4byte 0x000003FF
_081D9234: .4byte 0x030046A0
_081D9238: .4byte 0x00000934
_081D923C:
	movs r0, #0
_081D923E:
	cmp r0, #0
	bne _081D924E
	mov r0, r8
	bl FUN_081d8d90
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D9256
_081D924E:
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #3
	b _081D939A
_081D9256:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_081d8a24
	lsls r0, r0, #0x18
	adds r7, r6, #0
	adds r7, #0x70
	adds r5, r6, #0
	adds r5, #0x2c
	cmp r0, #0
	beq _081D92A0
	ldrh r0, [r7]
	cmp r0, #0x28
	bhi _081D92A0
	adds r0, r6, #0
	adds r0, #0x75
	ldrb r0, [r0]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	mov r0, r8
	ldr r1, [r0, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #6
	bl FUN_08236fac
	adds r0, r6, #0
	movs r1, #1
	bl FUN_081d8a14
_081D92A0:
	adds r4, r5, #0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
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
	beq _081D92CE
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D92D6
_081D92CE:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D92D6:
	str r0, [r6]
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
	beq _081D92FA
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D9302
_081D92FA:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D9302:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D933C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D9382
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D9346
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D9340
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D935C
	.align 2, 0
_081D933C: .4byte 0x0000FFFF
_081D9340:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D935A
_081D9346:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D935A
	strh r1, [r4, #8]
	movs r2, #1
	b _081D935C
_081D935A:
	movs r2, #0
_081D935C:
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
	bne _081D9384
	movs r0, #1
	strb r0, [r4, #7]
	b _081D9384
_081D9382:
	movs r2, #0
_081D9384:
	ldrh r0, [r7]
	cmp r0, #0
	beq _081D9390
	subs r0, #1
	strh r0, [r7]
	b _081D93A2
_081D9390:
	cmp r2, #0
	beq _081D93A2
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #2
_081D939A:
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
_081D93A2:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d93b0
FUN_081d93b0: @ 0x081D93B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp, #0xc]
	adds r7, r1, #0
	adds r0, r7, #0
	adds r0, #0x74
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D93CC
	b _081D94F8
_081D93CC:
	movs r0, #0x75
	adds r0, r0, r7
	mov sl, r0
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	movs r6, #0
	mov r2, sl
	strb r0, [r2]
	ldr r4, _081D9480 @ =0x0203B400
	mov sb, r4
	ldr r5, _081D9484 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _081D9488 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	ldrb r2, [r2]
	adds r0, r0, r2
	mov r4, sl
	strb r0, [r4]
	ldrb r0, [r4]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	adds r0, r7, #0
	adds r0, #0x2c
	ldr r2, [sp, #0xc]
	ldr r1, [r2, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #7
	bl FUN_08236fac
	adds r0, r7, #0
	adds r0, #0x78
	strb r6, [r0]
	subs r0, #8
	strh r6, [r0]
	add r0, sp, #8
	adds r4, r7, #0
	adds r4, #0x58
	str r6, [sp, #8]
	adds r1, r4, #0
	ldr r2, _081D948C @ =0x05000002
	bl CpuSet
	mov r0, sl
	ldrb r2, [r0]
	ldr r0, [r5]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r3, r1, #2
	ldr r1, _081D9490 @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	movs r5, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081D9494
	asrs r1, r0, #0xc
	b _081D949A
	.align 2, 0
_081D9480: .4byte 0x0203B400
_081D9484: .4byte 0x030046B8
_081D9488: .4byte 0x000003FF
_081D948C: .4byte 0x05000002
_081D9490: .4byte 0x085B0A08
_081D9494:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D949A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _081D94B4 @ =0x085B0A08
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _081D94B8
	asrs r0, r0, #0xc
	b _081D94BE
	.align 2, 0
_081D94B4: .4byte 0x085B0A08
_081D94B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D94BE:
	movs r3, #0
	strh r0, [r4, #4]
	ldr r2, _081D9558 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D955C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _081D9560 @ =0x0203B400
	adds r0, r0, r4
	ldrh r2, [r0]
	ldr r0, _081D9564 @ =0x03002BE0
	ldr r1, [r0]
	movs r5, #0x80
	lsls r5, r5, #1
	adds r0, r5, #0
	ldrh r1, [r1, #0x2e]
	adds r0, r0, r1
	ldr r4, _081D9568 @ =0x000001FF
	adds r1, r4, #0
	ands r2, r1
	adds r0, r0, r2
	adds r1, r7, #0
	adds r1, #0x7a
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	strb r3, [r0]
_081D94F8:
	movs r5, #0x1e
	ldrsh r0, [r7, r5]
	adds r1, r7, #0
	adds r1, #0x7a
	ldrh r1, [r1]
	cmp r0, r1
	bge _081D956C
	adds r4, r7, #0
	adds r4, #0x70
	ldrh r0, [r4]
	movs r1, #4
	bl Mod
	mov sb, r4
	adds r1, r7, #0
	adds r1, #0x5a
	cmp r0, #0
	bne _081D9522
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
_081D9522:
	adds r0, r7, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrh r0, [r1]
	ldrh r4, [r7, #0x1e]
	adds r0, r0, r4
	strh r0, [r7, #0x1e]
	adds r0, r7, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r5, [r7, #0x20]
	adds r0, r0, r5
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	adds r0, #0x78
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _081D9588
	ldrh r0, [r7, #0x34]
	cmp r0, #5
	bne _081D9588
	b _081D957C
	.align 2, 0
_081D9558: .4byte 0x030046B8
_081D955C: .4byte 0x000003FF
_081D9560: .4byte 0x0203B400
_081D9564: .4byte 0x03002BE0
_081D9568: .4byte 0x000001FF
_081D956C:
	adds r1, r7, #0
	adds r1, #0x68
	movs r0, #4
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
	b _081D96A8
_081D957C:
	ldrh r0, [r7, #0x3a]
	cmp r0, #0
	bne _081D9588
	movs r0, #0xf6
	bl PlaySound_082406e0
_081D9588:
	adds r4, r7, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r4
	cmp r1, r0
	beq _081D95BA
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D95C2
_081D95BA:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D95C2:
	str r0, [r7]
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
	beq _081D95E6
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D95EE
_081D95E6:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D95EE:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D9628 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r4, #7]
	cmp r0, r5
	blo _081D966E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D9632
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D962C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D9648
	.align 2, 0
_081D9628: .4byte 0x0000FFFF
_081D962C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D9646
_081D9632:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D9646
	strh r1, [r4, #8]
	movs r2, #1
	b _081D9648
_081D9646:
	movs r2, #0
_081D9648:
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
	bne _081D9670
	movs r0, #1
	strb r0, [r4, #7]
	b _081D9670
_081D966E:
	movs r2, #0
_081D9670:
	cmp r2, #0
	beq _081D96A0
	adds r0, r7, #0
	adds r0, #0x75
	ldrb r0, [r0]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	ldr r5, [sp, #0xc]
	ldr r1, [r5, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	mov r0, r8
	movs r2, #1
	bl FUN_08236fac
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
_081D96A0:
	mov r1, sb
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081D96A8:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d96b8
FUN_081d96b8: @ 0x081D96B8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r5, r1, #0
	adds r1, #0x74
	ldrb r0, [r1]
	cmp r0, #0
	beq _081D978C
	movs r0, #0
	strb r0, [r1]
	adds r4, r5, #0
	adds r4, #0x75
	ldrb r3, [r4]
	ldr r2, _081D9714 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D9718 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D971C @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r6, r5, #0
	adds r6, #0x58
	adds r7, r1, #0
	adds r7, #0xc
	ldr r2, _081D9720 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _081D9724
	asrs r1, r0, #0xc
	b _081D972A
	.align 2, 0
_081D9714: .4byte 0x030046B8
_081D9718: .4byte 0x000003FF
_081D971C: .4byte 0x0203B400
_081D9720: .4byte 0x085B0A08
_081D9724:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D972A:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _081D9742
	asrs r1, r0, #0xc
	b _081D9748
_081D9742:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D9748:
	movs r0, #0
	strh r1, [r6, #4]
	adds r1, r5, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldrb r0, [r4]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	adds r0, r5, #0
	adds r0, #0x2c
	mov r2, r8
	ldr r1, [r2, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #0
	bl FUN_08236fac
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0x80
	lsls r1, r1, #4
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #1
	strb r0, [r5, #7]
_081D978C:
	adds r0, r5, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r1, [r5, #0x1c]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r2, [r5, #0x20]
	adds r0, r0, r2
	strh r0, [r5, #0x20]
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D97D4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D97DC
_081D97D4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D97DC:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D9800
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D9808
_081D9800:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D9808:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D9840 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D9878
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D9844
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D9838
	ldrb r0, [r4, #5]
_081D9838:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D9854
	.align 2, 0
_081D9840: .4byte 0x0000FFFF
_081D9844:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D9854
	strh r1, [r4, #8]
_081D9854:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _081D9878
	movs r0, #1
	strb r0, [r4, #7]
_081D9878:
	adds r0, r5, #0
	bl FUN_081d8cb0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D9892
	adds r1, r5, #0
	adds r1, #0x68
	movs r0, #5
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
_081D9892:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d98a0
FUN_081d98a0: @ 0x081D98A0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x74
	ldrb r0, [r5]
	cmp r0, #0
	beq _081D98E6
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0x79
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D98C8
	adds r0, r4, #0
	adds r0, #0x7c
	bl ParticleShadow_Remove
_081D98C8:
	adds r3, r4, #0
	adds r3, #0x6c
	movs r1, #0
	ldrsh r0, [r3, r1]
	ldr r1, _081D98FC @ =0x00000ECC
	adds r2, r6, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	ldr r0, _081D9900 @ =0x0000FFFF
	strh r0, [r3]
	movs r0, #0
	strb r0, [r5]
_081D98E6:
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #0
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D98FC: .4byte 0x00000ECC
_081D9900: .4byte 0x0000FFFF

	thumb_func_start Entity8CC7_Update
Entity8CC7_Update: @ 0x081D9904
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x1c
	ldr r1, _081D9934 @ =0x00000ECC
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081D9962
	movs r4, #0
	ldr r0, _081D9934 @ =0x00000ECC
	adds r6, r5, r0
	ldr r1, _081D9938 @ =0x085AE12C
	mov r8, r1
_081D9924:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D993C
	movs r0, #1
	b _081D993E
	.align 2, 0
_081D9934: .4byte 0x00000ECC
_081D9938: .4byte 0x085AE12C
_081D993C:
	movs r0, #0
_081D993E:
	cmp r0, #0
	beq _081D995C
	movs r0, #0xbc
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r7
	adds r0, r1, #0
	adds r0, #0x68
	ldrh r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081D995C:
	adds r4, #1
	cmp r4, #0x13
	ble _081D9924
_081D9962:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity8CC7_Destroy
Entity8CC7_Destroy: @ 0x081D9970
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r0, _081D998C @ =0x00000ECC
	adds r7, r6, r0
_081D997A:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D9990
	movs r0, #1
	b _081D9992
	.align 2, 0
_081D998C: .4byte 0x00000ECC
_081D9990:
	movs r0, #0
_081D9992:
	cmp r0, #0
	beq _081D99B6
	movs r0, #0xbc
	muls r0, r5, r0
	adds r0, #0x1c
	adds r4, r6, r0
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0x79
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D99B6
	adds r0, r4, #0
	adds r0, #0x7c
	bl ParticleShadow_Remove
_081D99B6:
	adds r5, #1
	cmp r5, #0x13
	ble _081D997A
	ldr r1, _081D99C8 @ =0x030001A4
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D99C8: .4byte 0x030001A4

	thumb_func_start Entity8CC7_Init
Entity8CC7_Init: @ 0x081D99CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081D99F8 @ =0x0000922E
	ldr r1, _081D99FC @ =0x00007B03
	bl GetFile
	str r0, [r4, #0x18]
	ldr r0, _081D9A00 @ =0x030001A4
	str r4, [r0]
	ldr r0, _081D9A04 @ =0x00000ECC
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	movs r0, #0xed
	lsls r0, r0, #4
	adds r4, r4, r0
	subs r0, #0xc0
	str r0, [r4]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081D99F8: .4byte 0x0000922E
_081D99FC: .4byte 0x00007B03
_081D9A00: .4byte 0x030001A4
_081D9A04: .4byte 0x00000ECC

	thumb_func_start Entity8CC7_Create
Entity8CC7_Create: @ 0x081D9A08
	push {r4, lr}
	ldr r0, _081D9A3C @ =0x030001A4
	ldr r0, [r0]
	cmp r0, #0
	bne _081D9A4E
	ldr r1, _081D9A40 @ =0x00000ED4
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D9A4C
	ldr r1, _081D9A44 @ =Entity8CC7_Update
	ldr r2, _081D9A48 @ =Entity8CC7_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity8CC7_Init
	cmp r0, #0
	bge _081D9A4C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D9A4E
	.align 2, 0
_081D9A3C: .4byte 0x030001A4
_081D9A40: .4byte 0x00000ED4
_081D9A44: .4byte Entity8CC7_Update
_081D9A48: .4byte Entity8CC7_Destroy
_081D9A4C:
	adds r0, r4, #0
_081D9A4E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d9a54
FUN_081d9a54: @ 0x081D9A54
	ldr r1, _081D9A5C @ =0x030001A4
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D9A5C: .4byte 0x030001A4
