	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081eeb80
FUN_081eeb80: @ 0x081EEB80
	bx lr
	.align 2, 0

	thumb_func_start FUN_081eeb84
FUN_081eeb84: @ 0x081EEB84
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	adds r5, r4, #0
	adds r1, #0x35
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _081EEB9C
	subs r0, r2, #1
	strb r0, [r1]
	b _081EEC14
_081EEB9C:
	cmp r0, #0
	bne _081EEBA6
	movs r0, #0xff
	orrs r0, r2
	strb r0, [r1]
_081EEBA6:
	ldrh r0, [r4, #0x38]
	adds r0, #1
	strh r0, [r4, #0x38]
	ldrh r0, [r4, #0x38]
	adds r1, r4, #0
	adds r1, #0x3d
	adds r6, r0, #0
	ldrb r1, [r1]
	asrs r6, r1
	cmp r6, #6
	bne _081EEBC6
	adds r1, r4, #0
	adds r1, #0x3c
	movs r0, #2
	strb r0, [r1]
	b _081EEC14
_081EEBC6:
	ldrh r1, [r4, #0x36]
	bl Mod
	cmp r0, #0
	beq _081EEBE0
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _081EEC14
	adds r0, r4, #0
	movs r1, #0
	bl Video_RemoveAuxSpriteFromDrawList
	b _081EEC14
_081EEBE0:
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _081EEBEE
	adds r0, r4, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
_081EEBEE:
	ldrh r2, [r5, #0x2c]
	ldrh r1, [r5, #0x1c]
	adds r0, r2, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x2e]
	ldrh r3, [r5, #0x1e]
	adds r0, r0, r3
	strh r0, [r5, #0x1e]
	ldrh r1, [r5, #0x30]
	ldrh r3, [r5, #0x20]
	adds r0, r1, r3
	strh r0, [r5, #0x20]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x11
	strh r2, [r5, #0x2c]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	strh r1, [r5, #0x30]
	strh r6, [r5, #0x10]
_081EEC14:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081eec1c
FUN_081eec1c: @ 0x081EEC1C
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _081EEC2C
	adds r0, r4, #0
	bl AuxSprite_Remove
_081EEC2C:
	adds r1, r4, #0
	adds r1, #0x3c
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0x40
	bl ClearMemory
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081eec44
FUN_081eec44: @ 0x081EEC44
	push {r4, lr}
	movs r3, #0
	movs r4, #1
	adds r1, r0, #0
	adds r1, #0x76
	adds r2, r0, #0
	adds r2, #0x38
_081EEC52:
	ldrb r0, [r1, #1]
	cmp r0, #1
	beq _081EEC60
	strb r3, [r1]
	strb r4, [r1, #1]
	adds r0, r2, #0
	b _081EEC6C
_081EEC60:
	adds r1, #0x40
	adds r2, #0x40
	adds r3, #1
	cmp r3, #0x7f
	ble _081EEC52
	movs r0, #0
_081EEC6C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081eec74
FUN_081eec74: @ 0x081EEC74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	adds r7, r3, #0
	cmp r0, #0
	bne _081EEC8C
	b _081EEDBC
_081EEC8C:
	ldr r0, _081EED40 @ =0x030001D8
	ldr r4, [r0]
	cmp r4, #0
	bne _081EECA0
	bl Entity081eee80_Create
	adds r4, r0, #0
	cmp r4, #0
	bne _081EECA0
	b _081EEDBC
_081EECA0:
	adds r0, r4, #0
	bl FUN_081eec44
	adds r6, r0, #0
	cmp r6, #0
	bne _081EECAE
	b _081EEDBC
_081EECAE:
	adds r5, r6, #0
	adds r1, r4, #0
	adds r1, #0x18
	adds r0, r5, #0
	movs r2, #0
	bl AuxSprite_Setup
	movs r2, #0
	strh r2, [r5, #0x10]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	mov r0, sb
	strb r0, [r5, #7]
	mov r3, r8
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	adds r1, r5, #0
	adds r1, #0x3c
	movs r0, #1
	strb r0, [r1]
	strh r2, [r5, #0x38]
	adds r0, r5, #0
	adds r0, #0x34
	strb r7, [r0]
	ldr r4, _081EED44 @ =0x0203B400
	ldr r2, _081EED48 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _081EED4C @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	add r0, sl
	adds r1, r5, #0
	adds r1, #0x35
	strb r0, [r1]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #1
	strh r0, [r5, #0x36]
	adds r3, r5, #0
	adds r3, #0x2c
	ldr r2, _081EED50 @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x20]
	muls r0, r2, r0
	cmp r0, #0
	blt _081EED54
	asrs r1, r0, #0xc
	b _081EED5A
	.align 2, 0
_081EED40: .4byte 0x030001D8
_081EED44: .4byte 0x0203B400
_081EED48: .4byte 0x030046B8
_081EED4C: .4byte 0x000003FF
_081EED50: .4byte gSineTable
_081EED54:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081EED5A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _081EED7C @ =gSineTable
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x20]
	muls r0, r2, r0
	cmp r0, #0
	blt _081EED80
	asrs r0, r0, #0xc
	b _081EED86
	.align 2, 0
_081EED7C: .4byte gSineTable
_081EED80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081EED86:
	strh r0, [r3, #4]
	ldr r2, _081EEDCC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081EEDD0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081EEDD4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	strh r0, [r6, #0x2e]
	adds r1, r6, #0
	adds r1, #0x3d
	ldr r0, [sp, #0x24]
	strb r0, [r1]
	ldr r0, [sp, #0x28]
	cmp r0, #0
	ble _081EEDBC
	ldr r0, [r5, #0xc]
	ldr r2, [sp, #0x28]
	ldr r3, _081EEDD8 @ =0x00000113
	adds r1, r2, r3
	bl Video_SetAuxSpritePltt
_081EEDBC:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EEDCC: .4byte 0x030046B8
_081EEDD0: .4byte 0x000003FF
_081EEDD4: .4byte 0x0203B400
_081EEDD8: .4byte 0x00000113

	thumb_func_start Entity081eee80_Update
Entity081eee80_Update: @ 0x081EEDDC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _081EEE20 @ =0x085AE4EC
	mov r8, r0
	adds r5, r6, #0
	adds r5, #0x38
	adds r4, r6, #0
	adds r4, #0x74
	movs r7, #0x7f
_081EEDF2:
	ldrb r0, [r4, #3]
	cmp r0, #1
	bne _081EEE08
	ldrb r0, [r4]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	bl _call_via_r2
_081EEE08:
	adds r5, #0x40
	adds r4, #0x40
	subs r7, #1
	cmp r7, #0
	bge _081EEDF2
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EEE20: .4byte 0x085AE4EC

	thumb_func_start Entity081eee80_Destroy
Entity081eee80_Destroy: @ 0x081EEE24
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r4, #0x38
	adds r5, r0, #0
	adds r5, #0x77
	movs r6, #0x7f
_081EEE30:
	ldrb r0, [r5]
	cmp r0, #1
	bne _081EEE42
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _081EEE42
	adds r0, r4, #0
	bl AuxSprite_Remove
_081EEE42:
	adds r4, #0x40
	adds r5, #0x40
	subs r6, #1
	cmp r6, #0
	bge _081EEE30
	movs r1, #0
	ldr r0, _081EEE5C @ =0x030001D8
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081EEE5C: .4byte 0x030001D8

	thumb_func_start Entity081eee80_Init
Entity081eee80_Init: @ 0x081EEE60
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _081EEE78 @ =0x00008639
	bl Video_GetAuxSprite
	ldr r0, _081EEE7C @ =0x030001D8
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081EEE78: .4byte 0x00008639
_081EEE7C: .4byte 0x030001D8

	thumb_func_start Entity081eee80_Create
Entity081eee80_Create: @ 0x081EEE80
	push {r4, lr}
	ldr r0, _081EEEB4 @ =0x030001D8
	ldr r0, [r0]
	cmp r0, #0
	bne _081EEEC6
	ldr r1, _081EEEB8 @ =0x00002038
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EEEC4
	ldr r1, _081EEEBC @ =Entity081eee80_Update
	ldr r2, _081EEEC0 @ =Entity081eee80_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081eee80_Init
	cmp r0, #0
	bge _081EEEC4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EEEC6
	.align 2, 0
_081EEEB4: .4byte 0x030001D8
_081EEEB8: .4byte 0x00002038
_081EEEBC: .4byte Entity081eee80_Update
_081EEEC0: .4byte Entity081eee80_Destroy
_081EEEC4:
	adds r0, r4, #0
_081EEEC6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081eeecc
FUN_081eeecc: @ 0x081EEECC
	ldr r1, _081EEED4 @ =0x030001D8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EEED4: .4byte 0x030001D8
