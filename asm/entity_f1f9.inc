	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081d5820
FUN_081d5820: @ 0x081D5820
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d5834
FUN_081d5834: @ 0x081D5834
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	bics r2, r1
	strh r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d5848
FUN_081d5848: @ 0x081D5848
	push {lr}
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081D585C
	movs r0, #0
	b _081D585E
_081D585C:
	movs r0, #1
_081D585E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d5864
FUN_081d5864: @ 0x081D5864
	push {r4, r5, r6, r7, lr}
	movs r5, #0
	ldr r1, _081D588C @ =0x0000057C
	adds r2, r0, r1
	movs r3, #1
	movs r7, #0xac
	lsls r7, r7, #1
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r6, r0, r1
	adds r4, r0, #0
	adds r4, #0x1c
_081D587C:
	adds r1, r3, #0
	lsls r1, r5
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D5890
	movs r0, #1
	b _081D5892
	.align 2, 0
_081D588C: .4byte 0x0000057C
_081D5890:
	movs r0, #0
_081D5892:
	cmp r0, #0
	bne _081D58AE
	adds r1, r3, #0
	lsls r1, r5
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	adds r1, r7, #0
	bl ClearMemory
	strh r5, [r6]
	adds r0, r4, #0
	b _081D58BE
_081D58AE:
	movs r0, #0xac
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #3
	ble _081D587C
	movs r0, #0
_081D58BE:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d58c4
FUN_081d58c4: @ 0x081D58C4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _081D58D4 @ =0x03000198
	ldr r1, [r0]
	cmp r1, #0
	bne _081D58DC
	b _081D591A
	.align 2, 0
_081D58D4: .4byte 0x03000198
_081D58D8:
	adds r0, r1, #0
	b _081D591C
_081D58DC:
	movs r2, #0
	ldr r3, _081D58F8 @ =0x0000057C
	adds r0, r1, r3
	ldr r3, [r0]
	movs r5, #1
	adds r1, #0x1c
_081D58E8:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r3
	cmp r0, #0
	beq _081D58FC
	movs r0, #1
	b _081D58FE
	.align 2, 0
_081D58F8: .4byte 0x0000057C
_081D58FC:
	movs r0, #0
_081D58FE:
	cmp r0, #0
	beq _081D590E
	movs r6, #0xa8
	lsls r6, r6, #1
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, r4
	beq _081D58D8
_081D590E:
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r2, #1
	cmp r2, #3
	ble _081D58E8
_081D591A:
	movs r0, #0
_081D591C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d5924
FUN_081d5924: @ 0x081D5924
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	ldr r0, _081D59A8 @ =0x03000198
	ldr r6, [r0]
	cmp r6, #0
	bne _081D5944
	bl EntityF1F9_Create
	adds r6, r0, #0
	cmp r6, #0
	bne _081D5944
	b _081D5C9C
_081D5944:
	adds r0, r6, #0
	bl FUN_081d5864
	adds r5, r0, #0
	cmp r5, #0
	bne _081D5952
	b _081D5C9C
_081D5952:
	adds r7, r5, #0
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r1, _081D59AC @ =0x00009385
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	movs r4, #1
	strb r4, [r0]
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, #0x6d
	bl VM_GetKeywordValue
	movs r3, #0xa6
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_081d5848
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D59B0
	movs r0, #0xa4
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	b _081D59B8
	.align 2, 0
_081D59A8: .4byte 0x03000198
_081D59AC: .4byte 0x00009385
_081D59B0:
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
_081D59B8:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D59D4
	bl Script_GetValue
	strh r0, [r7, #0x1c]
	bl Script_GetValue
	strh r0, [r7, #0x1e]
	bl Script_GetValue
	strh r0, [r7, #0x20]
_081D59D4:
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r2, r5, r3
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xa9
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x61
	bl VM_GetKeywordValue
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	str r0, [r1]
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _081D5A44 @ =0x0000013D
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D5AC2
	bl VM_GetPC
	cmp r0, #0
	beq _081D5A48
	bl Script_GetValue
	adds r1, r0, #0
	b _081D5A4A
	.align 2, 0
_081D5A44: .4byte 0x0000013D
_081D5A48:
	movs r1, #0
_081D5A4A:
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081D5A60
	bl Script_GetValue
	b _081D5A62
_081D5A60:
	movs r0, #0
_081D5A62:
	ldr r2, _081D5A78 @ =0x00000147
	adds r1, r5, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081D5A7C
	bl Script_GetValue
	b _081D5A7E
	.align 2, 0
_081D5A78: .4byte 0x00000147
_081D5A7C:
	movs r0, #0
_081D5A7E:
	movs r3, #0xa3
	lsls r3, r3, #1
	adds r1, r5, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081D5A94
	bl Script_GetValue
	b _081D5A96
_081D5A94:
	movs r0, #0
_081D5A96:
	mov sl, r0
	bl VM_GetPC
	cmp r0, #0
	beq _081D5AA8
	bl Script_GetValue
	mov sb, r0
	b _081D5AAC
_081D5AA8:
	movs r1, #0
	mov sb, r1
_081D5AAC:
	bl VM_GetPC
	cmp r0, #0
	beq _081D5ABC
	bl Script_GetValue
	mov r8, r0
	b _081D5AE6
_081D5ABC:
	movs r2, #0
	mov r8, r2
	b _081D5AE6
_081D5AC2:
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0x64
	strh r0, [r1]
	adds r0, #0xe3
	adds r1, r5, r0
	movs r0, #3
	strb r0, [r1]
	movs r2, #0xa3
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0
	mov sl, r3
	mov sb, r3
	mov r8, r3
_081D5AE6:
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	movs r3, #0xa1
	lsls r3, r3, #1
	adds r2, r5, r3
	strh r0, [r2]
	movs r2, #0
	ldrsh r0, [r1, r2]
	subs r3, #5
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r1, #1
	bl Div
	movs r2, #0x9d
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D5B32
	bl VM_GetPC
	cmp r0, #0
	beq _081D5B28
	bl Script_GetValue
	adds r1, r0, #0
	b _081D5B2A
_081D5B28:
	movs r1, #0
_081D5B2A:
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
_081D5B32:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_081d5848
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _081D5B76
	adds r0, r5, #0
	adds r0, #0xa8
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #0x60
	str r2, [sp]
	movs r2, #0x64
	str r2, [sp, #4]
	movs r2, #0xa0
	lsls r2, r2, #4
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	movs r2, #5
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	movs r2, #0
	str r2, [sp, #0x18]
	movs r2, #0x40
	movs r3, #0x10
	bl AuxShadow_Init
	movs r2, #0xa7
	lsls r2, r2, #1
	adds r1, r5, r2
	b _081D5BA6
_081D5B76:
	adds r0, r5, #0
	adds r0, #0xa8
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #0x80
	str r2, [sp]
	movs r2, #0x64
	str r2, [sp, #4]
	movs r2, #0xa0
	lsls r2, r2, #4
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	movs r2, #5
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r2, #0x40
	movs r3, #0x10
	bl AuxShadow_Init
	movs r3, #0xa7
	lsls r3, r3, #1
	adds r1, r5, r3
_081D5BA6:
	strb r0, [r1]
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r1, [r6, #0x18]
	movs r2, #0xa9
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
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
	beq _081D5BEE
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D5BF6
_081D5BEE:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D5BF6:
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
	beq _081D5C1A
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D5C22
_081D5C1A:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D5C22:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _081D5C58 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D5C90
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D5C5C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D5C52
	ldrb r0, [r4, #5]
_081D5C52:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D5C6C
	.align 2, 0
_081D5C58: .4byte 0x0000FFFF
_081D5C5C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D5C6C
	strh r1, [r4, #8]
_081D5C6C:
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
	bne _081D5C90
	movs r0, #1
	strb r0, [r4, #7]
_081D5C90:
	adds r0, r5, #0
	mov r1, sl
	mov r2, sb
	mov r3, r8
	bl FUN_081d66c0
_081D5C9C:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d5cac
FUN_081d5cac: @ 0x081D5CAC
	push {r4, lr}
	mov ip, r0
	mov r4, ip
	mov r2, ip
	adds r2, #0x9c
	ldrh r0, [r2]
	cmp r0, #0
	beq _081D5CCE
	mov r3, ip
	adds r3, #0x5e
	ldrh r0, [r3]
	movs r1, #4
	orrs r1, r0
	strh r1, [r3]
	ldrh r0, [r2]
	subs r0, #1
	b _081D5CD8
_081D5CCE:
	mov r2, ip
	adds r2, #0x5e
	ldrh r1, [r2]
	ldr r0, _081D5CF8 @ =0x0000FFFB
	ands r0, r1
_081D5CD8:
	strh r0, [r2]
	ldr r0, _081D5CFC @ =0x00000153
	adds r4, r4, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D5D00
	mov r1, ip
	ldr r0, [r1, #0xc]
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _081D5D0C
	.align 2, 0
_081D5CF8: .4byte 0x0000FFFB
_081D5CFC: .4byte 0x00000153
_081D5D00:
	mov r1, ip
	ldr r0, [r1, #0xc]
	movs r1, #0xbe
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
_081D5D0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d5d14
FUN_081d5d14: @ 0x081D5D14
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d5d18
FUN_081d5d18: @ 0x081D5D18
	push {r4, r5, lr}
	adds r4, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081D5D40
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	strb r2, [r3]
_081D5D40:
	adds r0, r4, #0
	bl FUN_081d5cac
	adds r0, r4, #0
	bl FUN_081d6444
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r5, r4, r0
	ldrh r1, [r5]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081D5D62
	adds r0, r4, #0
	bl FUN_081d6c24
_081D5D62:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d5d70
FUN_081d5d70: @ 0x081D5D70
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne _081D5D84
	b _081D5E88
_081D5D84:
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r3, #0
	movs r2, #0
	strh r2, [r0]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	strb r3, [r4]
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r5, r0
	str r2, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081D5DE0 @ =0x05000002
	bl CpuSet
	movs r0, #0x29
	strh r0, [r4]
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0x94
	strh r0, [r1]
	movs r0, #0
	ldrsh r3, [r4, r0]
	ldr r2, _081D5DE4 @ =0x085B0A08
	ldrb r0, [r5, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081D5DE8
	asrs r0, r0, #0xc
	b _081D5DEE
	.align 2, 0
_081D5DE0: .4byte 0x05000002
_081D5DE4: .4byte 0x085B0A08
_081D5DE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D5DEE:
	adds r6, r0, #0
	movs r2, #0x94
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r4, #0
	ldrsh r3, [r0, r4]
	ldr r1, _081D5E14 @ =0x085B0A08
	ldrb r2, [r5, #6]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r3, r0
	adds r7, r1, #0
	adds r4, r2, #0
	cmp r0, #0
	blt _081D5E18
	asrs r0, r0, #0xc
	b _081D5E1E
	.align 2, 0
_081D5E14: .4byte 0x085B0A08
_081D5E18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D5E1E:
	adds r6, r6, r0
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r4, #1
	adds r0, r0, r7
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _081D5E3E
	asrs r0, r0, #0xc
	b _081D5E42
_081D5E3E:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_081D5E42:
	adds r3, r0, #0
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r2, r0
	cmp r0, #0
	blt _081D5E68
	asrs r2, r0, #0xc
	b _081D5E6E
_081D5E68:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081D5E6E:
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r0, r0, r6
	strh r0, [r5, #0x1c]
	movs r4, #0x8c
	lsls r4, r4, #1
	adds r1, r5, r4
	adds r0, r3, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
_081D5E88:
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081D5F36
	adds r0, r5, #0
	bl FUN_081d6cb0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D5F36
	ldr r2, _081D5F24 @ =0x03002BE0
	ldr r0, [r2]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081D5F36
	ldr r0, _081D5F28 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _081D5EC6
	ldr r0, _081D5F2C @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #0
	bne _081D5EC6
	movs r1, #1
_081D5EC6:
	cmp r1, #0
	bne _081D5F36
	ldr r0, [r2]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _081D5F36
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r2, #0x98
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	beq _081D5F36
	subs r4, #0x10
	adds r1, r5, r4
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _081D5F36
	movs r0, #4
	strh r0, [r1]
	adds r4, #0x24
	adds r1, r5, r4
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _081D5F30
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #3
	strh r1, [r0]
	movs r2, #0xab
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _081D5F48
	.align 2, 0
_081D5F24: .4byte 0x03002BE0
_081D5F28: .4byte 0x03002B8C
_081D5F2C: .4byte 0x03002B60
_081D5F30:
	ldr r0, _081D5F50 @ =0x000003C9
	bl PlaySound_082406e0
_081D5F36:
	adds r0, r5, #0
	bl FUN_081d5f54
	movs r4, #0xaa
	lsls r4, r4, #1
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081D5F48:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D5F50: .4byte 0x000003C9

	thumb_func_start FUN_081d5f54
FUN_081d5f54: @ 0x081D5F54
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldrb r1, [r0, #6]
	cmp r1, #0x80
	ble _081D5F68
	ldr r0, _081D5F64 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081D5F76
	.align 2, 0
_081D5F64: .4byte 0xFFFFFF00
_081D5F68:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081D5F76
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081D5F76:
	adds r5, r1, #0
	cmp r5, #0
	bne _081D5F8C
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _081D5F8C
	b _081D60C0
_081D5F8C:
	movs r0, #0x92
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r4, [r0, r1]
	ldr r3, _081D5FBC @ =0x085B0A08
	mov r0, ip
	ldrb r2, [r0, #6]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	adds r4, r2, #0
	adds r6, r3, #0
	cmp r0, #0
	blt _081D5FC0
	asrs r0, r0, #0xc
	b _081D5FC6
	.align 2, 0
_081D5FBC: .4byte 0x085B0A08
_081D5FC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D5FC6:
	adds r2, r0, #0
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r4, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _081D5FE4
	asrs r0, r0, #0xc
	b _081D5FEA
_081D5FE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D5FEA:
	adds r7, r2, r0
	movs r0, #0x92
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r4, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _081D600A
	asrs r0, r0, #0xc
	b _081D600E
_081D600A:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_081D600E:
	adds r3, r0, #0
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _081D6034
	asrs r2, r0, #0xc
	b _081D603A
_081D6034:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081D603A:
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	adds r0, r0, r7
	mov r1, ip
	strh r0, [r1, #0x1c]
	movs r1, #0x8c
	lsls r1, r1, #1
	add r1, ip
	adds r0, r3, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, ip
	strh r0, [r2, #0x20]
	movs r1, #0x8e
	lsls r1, r1, #1
	add r1, ip
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne _081D6080
	cmp r5, #0
	ble _081D6076
	mov r1, ip
	ldrb r0, [r1, #6]
	subs r0, #1
	strb r0, [r1, #6]
	b _081D60C0
_081D6076:
	mov r2, ip
	ldrb r0, [r2, #6]
	adds r0, #1
	strb r0, [r2, #6]
	b _081D60C0
_081D6080:
	mov r3, ip
	ldrb r0, [r3, #6]
	adds r0, r2, r0
	strb r0, [r3, #6]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble _081D609A
	cmp r5, r0
	ble _081D60C0
	rsbs r0, r0, #0
	strh r0, [r1]
	b _081D60C0
_081D609A:
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r5, r0
	bge _081D60C0
	rsbs r0, r0, #0
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	blt _081D60B2
	asrs r1, r0, #1
	b _081D60B8
_081D60B2:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081D60B8:
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, ip
	strh r1, [r0]
_081D60C0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d60c8
FUN_081d60c8: @ 0x081D60C8
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r5, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081D618C
	adds r0, r5, #0
	adds r0, #0x1c
	ldrh r1, [r5, #0x1c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r6, r0, #0
	cmp r2, #0
	blt _081D6104
	cmp r1, #0
	blt _081D6104
	ldr r0, _081D6108 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D6104
	ldr r0, _081D610C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D6110
_081D6104:
	movs r4, #0
	b _081D611E
	.align 2, 0
_081D6108: .4byte 0x030046A8
_081D610C: .4byte 0x030046AC
_081D6110:
	ldr r0, _081D6130 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D611E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D6134
	adds r0, #4
	b _081D6140
	.align 2, 0
_081D6130: .4byte 0x030046A4
_081D6134:
	ldr r0, _081D6154 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D6140:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r3, r0, #8
	cmp r2, #1
	beq _081D6158
	cmp r2, #2
	beq _081D615C
	b _081D6160
	.align 2, 0
_081D6154: .4byte 0x030046A4
_081D6158:
	ldrb r0, [r6, #4]
	b _081D615E
_081D615C:
	ldrb r0, [r6]
_081D615E:
	subs r3, r3, r0
_081D6160:
	movs r2, #0x9f
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	movs r2, #0
	strh r3, [r1]
	movs r3, #0xab
	lsls r3, r3, #1
	adds r1, r5, r3
	strb r0, [r1]
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r1, r5, r0
	str r2, [sp, #0x20]
	add r0, sp, #0x20
	ldr r2, _081D6188 @ =0x05000002
	bl CpuSet
	b _081D61F6
	.align 2, 0
_081D6188: .4byte 0x05000002
_081D618C:
	movs r1, #0x8f
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r0, [r5, #0x1e]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r5, #0x1e]
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
	movs r2, #0x9f
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r1, [r0]
	movs r2, #0x1e
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt _081D61F6
	strh r1, [r5, #0x1e]
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #4
	strh r1, [r0]
	movs r0, #1
	strb r0, [r3]
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0x1c
	movs r5, #1
_081D61C8:
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r4, #5
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x40
	str r0, [sp, #0x10]
	str r5, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x1c]
	adds r0, r6, #0
	movs r1, #8
	movs r2, #0x10
	movs r3, #4
	bl FUN_081ee584
	adds r4, #1
	cmp r4, #7
	ble _081D61C8
_081D61F6:
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d6200
FUN_081d6200: @ 0x081D6200
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r5, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r8, r0
	ldrb r6, [r0]
	cmp r6, #0
	beq _081D627C
	adds r0, r5, #0
	bl FUN_081d6764
	ldr r1, _081D6270 @ =0x0000013D
	adds r6, r5, r1
	ldrb r0, [r6]
	movs r3, #0x9e
	lsls r3, r3, #1
	adds r4, r5, r3
	ldrb r1, [r4]
	subs r0, r0, r1
	cmp r0, #0
	blt _081D6238
	ldr r0, _081D6274 @ =0x000003C7
	bl PlaySound_082406e0
_081D6238:
	ldrb r1, [r6]
	ldrb r0, [r4]
	subs r1, r1, r0
	adds r0, r5, #0
	bl FUN_081d6ae8
	movs r0, #0xa7
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r1, #0
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081D6262
	adds r0, r5, #0
	adds r0, #0xa8
	bl AuxShadow_Remove
	movs r0, #0xff
	strb r0, [r4]
_081D6262:
	ldr r0, _081D6278 @ =0x000003C6
	bl PlaySound_082406e0
	movs r0, #0
	mov r1, r8
	strb r0, [r1]
	b _081D62B4
	.align 2, 0
_081D6270: .4byte 0x0000013D
_081D6274: .4byte 0x000003C7
_081D6278: .4byte 0x000003C6
_081D627C:
	ldr r0, [r5]
	movs r4, #1
	orrs r0, r4
	str r0, [r5]
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0x58
	bl Hitbox_Unregister
	movs r3, #0xa4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r6, [r0]
	movs r0, #0xa5
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r3, _081D62C0 @ =0x0000057C
	adds r1, r7, r3
	lsls r4, r0
	ldr r0, [r1]
	bics r0, r4
	str r0, [r1]
	ldr r0, _081D62C4 @ =0x0000FFFF
	strh r0, [r2]
_081D62B4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D62C0: .4byte 0x0000057C
_081D62C4: .4byte 0x0000FFFF

	thumb_func_start EntityF1F9_Update
EntityF1F9_Update: @ 0x081D62C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x1c
	ldr r1, _081D62F8 @ =0x0000057C
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081D632A
	movs r4, #0
	ldr r2, _081D62F8 @ =0x0000057C
	adds r6, r5, r2
	ldr r0, _081D62FC @ =0x085AE104
	mov r8, r0
_081D62E8:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D6300
	movs r0, #1
	b _081D6302
	.align 2, 0
_081D62F8: .4byte 0x0000057C
_081D62FC: .4byte 0x085AE104
_081D6300:
	movs r0, #0
_081D6302:
	cmp r0, #0
	beq _081D6324
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r7
	movs r2, #0xa4
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrh r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081D6324:
	adds r4, #1
	cmp r4, #3
	ble _081D62E8
_081D632A:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityF1F9_Destroy
EntityF1F9_Destroy: @ 0x081D6338
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r6, #0
	ldr r0, _081D6364 @ =0x0000057C
	adds r0, r0, r7
	mov r8, r0
	movs r2, #1
	rsbs r2, r2, #0
	mov sb, r2
_081D6350:
	movs r1, #1
	lsls r1, r6
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D6368
	movs r0, #1
	b _081D636A
	.align 2, 0
_081D6364: .4byte 0x0000057C
_081D6368:
	movs r0, #0
_081D636A:
	cmp r0, #0
	beq _081D63A0
	movs r0, #0xac
	lsls r0, r0, #1
	muls r0, r6, r0
	adds r0, #0x1c
	adds r4, r7, r0
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0x58
	bl Hitbox_Unregister
	movs r0, #0xa7
	lsls r0, r0, #1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, sb
	beq _081D63A0
	adds r0, r4, #0
	adds r0, #0xa8
	bl AuxShadow_Remove
	movs r0, #0xff
	strb r0, [r5]
_081D63A0:
	adds r6, #1
	cmp r6, #3
	ble _081D6350
	ldr r1, _081D63B8 @ =0x03000198
	movs r0, #0
	str r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D63B8: .4byte 0x03000198

	thumb_func_start EntityF1F9_Init
EntityF1F9_Init: @ 0x081D63BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081D63DC @ =0x0000922E
	ldr r1, _081D63E0 @ =0x000074C9
	bl GetFile
	str r0, [r4, #0x18]
	ldr r0, _081D63E4 @ =0x03000198
	str r4, [r0]
	ldr r0, _081D63E8 @ =0x0000057C
	adds r4, r4, r0
	movs r0, #0
	str r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081D63DC: .4byte 0x0000922E
_081D63E0: .4byte 0x000074C9
_081D63E4: .4byte 0x03000198
_081D63E8: .4byte 0x0000057C

	thumb_func_start EntityF1F9_Create
EntityF1F9_Create: @ 0x081D63EC
	push {r4, lr}
	ldr r0, _081D6424 @ =0x03000198
	ldr r0, [r0]
	cmp r0, #0
	bne _081D6432
	movs r1, #0xb0
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D6430
	ldr r1, _081D6428 @ =EntityF1F9_Update
	ldr r2, _081D642C @ =EntityF1F9_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityF1F9_Init
	cmp r0, #0
	bge _081D6430
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D6432
	.align 2, 0
_081D6424: .4byte 0x03000198
_081D6428: .4byte EntityF1F9_Update
_081D642C: .4byte EntityF1F9_Destroy
_081D6430:
	adds r0, r4, #0
_081D6432:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d6438
FUN_081d6438: @ 0x081D6438
	ldr r1, _081D6440 @ =0x03000198
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D6440: .4byte 0x03000198
