	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Entity081f7de4_AllocElem
Entity081f7de4_AllocElem: @ 0x081F79CC
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r5, #1
_081F79D4:
	adds r0, r5, #0
	lsls r0, r2
	ldr r1, [r3, #0x38]
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _081F79E6
	movs r0, #1
	b _081F79E8
_081F79E6:
	movs r0, #0
_081F79E8:
	cmp r0, #0
	bne _081F7A04
	movs r0, #0x9c
	muls r0, r2, r0
	adds r0, #0x3c
	adds r0, r3, r0
	adds r1, r5, #0
	lsls r1, r2
	orrs r1, r4
	str r1, [r3, #0x38]
	adds r1, r0, #0
	adds r1, #0x97
	strb r2, [r1]
	b _081F7A0C
_081F7A04:
	adds r2, #1
	cmp r2, #1
	ble _081F79D4
	movs r0, #0
_081F7A0C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081f7de4_UpdateState0
Entity081f7de4_UpdateState0: @ 0x081F7A14
	bx lr
	.align 2, 0

	thumb_func_start Entity081f7de4_UpdateState1
Entity081f7de4_UpdateState1: @ 0x081F7A18
	push {r4, r5, r6, lr}
	mov ip, r1
	mov r3, ip
	adds r3, #0x9a
	ldrb r0, [r3]
	cmp r0, #0
	beq _081F7A32
	mov r0, ip
	adds r0, #0x98
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081F7A32:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081F7A8C @ =0x030047A4
	ldr r1, _081F7A90 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _081F7A48
	b _081F7B54
_081F7A48:
	movs r6, #4
	ldr r0, _081F7A94 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r6
	cmp r0, #0
	beq _081F7A56
	b _081F7B54
_081F7A56:
	mov r4, ip
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, ip
	ldr r1, [r2, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r2, #0x10]
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
	beq _081F7A98
	mov r1, ip
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	b _081F7AA4
	.align 2, 0
_081F7A8C: .4byte 0x030047A4
_081F7A90: .4byte 0x030047A0
_081F7A94: .4byte 0x03002BC0
_081F7A98:
	mov r2, ip
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
_081F7AA4:
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
	beq _081F7AC8
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081F7AD2
_081F7AC8:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F7AD2:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F7B0C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F7B44
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F7B10
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F7B04
	ldrb r0, [r4, #5]
_081F7B04:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F7B20
	.align 2, 0
_081F7B0C: .4byte 0x0000FFFF
_081F7B10:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F7B20
	strh r1, [r4, #8]
_081F7B20:
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
	bne _081F7B44
	movs r0, #1
	strb r0, [r4, #7]
_081F7B44:
	mov r1, ip
	ldrb r0, [r1, #6]
	adds r0, #8
	strb r0, [r1, #6]
	adds r1, #0x98
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081F7B54:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity081f7de4_UpdateState2
Entity081f7de4_UpdateState2: @ 0x081F7B5C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r2, r4, #0
	adds r2, #0x97
	movs r0, #0
	ldrsb r0, [r2, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r5, #0x38]
	bics r0, r1
	str r0, [r5, #0x38]
	movs r0, #0xff
	strb r0, [r2]
	adds r4, #0x96
	movs r0, #0
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity081f7de4_Spawn
Entity081f7de4_Spawn: @ 0x081F7B8C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	mov sl, r1
	ldr r0, _081F7C48 @ =0x03000204
	ldr r5, [r0]
	cmp r5, #0
	bne _081F7BB0
	bl Entity081f7de4_Create
	adds r5, r0, #0
	cmp r5, #0
	bne _081F7BB0
	b _081F7D10
_081F7BB0:
	adds r0, r5, #0
	bl Entity081f7de4_AllocElem
	mov sb, r0
	cmp r0, #0
	bne _081F7BBE
	b _081F7D10
_081F7BBE:
	adds r0, #0x96
	movs r1, #0
	mov r8, r1
	movs r6, #1
	strb r6, [r0]
	mov r1, sb
	adds r1, #0x90
	movs r0, #0x78
	str r0, [r1]
	mov r0, sb
	adds r0, #0x94
	mov r2, r8
	strh r2, [r0]
	adds r0, #6
	strb r6, [r0]
	mov r7, sb
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r0, _081F7C4C @ =0x0000922E
	ldr r1, _081F7C50 @ =0x00008DC7
	bl GetFile
	adds r4, r7, #0
	adds r4, #0x8c
	str r0, [r4]
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r7, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r5, r7, #0
	adds r5, #0x2c
	ldr r1, [r4]
	mov r0, r8
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r7, #0xc]
	ldr r1, _081F7C54 @ =0x00000275
	bl Video_SetAuxSpritePltt
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #4]
	adds r1, r6, #0
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r6
	cmp r1, r0
	beq _081F7C58
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081F7C60
	.align 2, 0
_081F7C48: .4byte 0x03000204
_081F7C4C: .4byte 0x0000922E
_081F7C50: .4byte 0x00008DC7
_081F7C54: .4byte 0x00000275
_081F7C58:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F7C60:
	str r0, [r7]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F7C86
	mov r1, sb
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081F7C90
_081F7C86:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F7C90:
	mov r2, sb
	str r0, [r2]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081F7CC8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _081F7D00
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F7CCC
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081F7CC2
	ldrb r0, [r5, #5]
_081F7CC2:
	subs r0, #1
	strh r0, [r5, #8]
	b _081F7CDC
	.align 2, 0
_081F7CC8: .4byte 0x0000FFFF
_081F7CCC:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081F7CDC
	strh r1, [r5, #8]
_081F7CDC:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F7D00
	movs r0, #1
	strb r0, [r5, #7]
_081F7D00:
	movs r0, #1
	strb r0, [r7, #7]
	ldr r0, [r7]
	ldr r1, _081F7D20 @ =0x00000202
	orrs r0, r1
	str r0, [r7]
	mov r0, sl
	strb r0, [r7, #6]
_081F7D10:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F7D20: .4byte 0x00000202

	thumb_func_start Entity081f7de4_Update
Entity081f7de4_Update: @ 0x081F7D24
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x3c
	ldr r0, [r5, #0x38]
	cmp r0, #0
	beq _081F7D72
	movs r4, #0
	ldr r7, _081F7D48 @ =0x085AE5B4
_081F7D36:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F7D4C
	movs r0, #1
	b _081F7D4E
	.align 2, 0
_081F7D48: .4byte 0x085AE5B4
_081F7D4C:
	movs r0, #0
_081F7D4E:
	cmp r0, #0
	beq _081F7D6C
	movs r0, #0x9c
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r6
	adds r0, r1, #0
	adds r0, #0x96
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081F7D6C:
	adds r4, #1
	cmp r4, #1
	ble _081F7D36
_081F7D72:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081f7de4_Destroy
Entity081f7de4_Destroy: @ 0x081F7D7C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_081F7D82:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F7D92
	movs r0, #1
	b _081F7D94
_081F7D92:
	movs r0, #0
_081F7D94:
	cmp r0, #0
	beq _081F7DA4
	movs r0, #0x9c
	muls r0, r4, r0
	adds r0, #0x3c
	adds r0, r5, r0
	bl AuxSprite_Remove
_081F7DA4:
	adds r4, #1
	cmp r4, #1
	ble _081F7D82
	ldr r1, _081F7DB8 @ =0x03000204
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081F7DB8: .4byte 0x03000204

	thumb_func_start Entity081f7de4_Init
Entity081f7de4_Init: @ 0x081F7DBC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	str r0, [r4, #0x38]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, _081F7DDC @ =0x0000354D
	bl Video_GetAuxSprite
	ldr r0, _081F7DE0 @ =0x03000204
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F7DDC: .4byte 0x0000354D
_081F7DE0: .4byte 0x03000204

	thumb_func_start Entity081f7de4_Create
Entity081f7de4_Create: @ 0x081F7DE4
	push {r4, lr}
	ldr r0, _081F7E1C @ =0x03000204
	ldr r0, [r0]
	cmp r0, #0
	bne _081F7E2A
	movs r1, #0xba
	lsls r1, r1, #1
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F7E28
	ldr r1, _081F7E20 @ =Entity081f7de4_Update
	ldr r2, _081F7E24 @ =Entity081f7de4_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f7de4_Init
	cmp r0, #0
	bge _081F7E28
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F7E2A
	.align 2, 0
_081F7E1C: .4byte 0x03000204
_081F7E20: .4byte Entity081f7de4_Update
_081F7E24: .4byte Entity081f7de4_Destroy
_081F7E28:
	adds r0, r4, #0
_081F7E2A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f7e30
FUN_081f7e30: @ 0x081F7E30
	ldr r1, _081F7E38 @ =0x03000204
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F7E38: .4byte 0x03000204

	thumb_func_start Entity081f7de4_RemoveAll
Entity081f7de4_RemoveAll: @ 0x081F7E3C
	push {lr}
	ldr r0, _081F7E64 @ =0x03000204
	ldr r0, [r0]
	cmp r0, #0
	beq _081F7E5E
	movs r3, #2
	adds r1, r0, #0
	adds r1, #0xd2
	movs r2, #1
_081F7E4E:
	ldrb r0, [r1]
	cmp r0, #1
	bne _081F7E56
	strb r3, [r1]
_081F7E56:
	adds r1, #0x9c
	subs r2, #1
	cmp r2, #0
	bge _081F7E4E
_081F7E5E:
	pop {r0}
	bx r0
	.align 2, 0
_081F7E64: .4byte 0x03000204
