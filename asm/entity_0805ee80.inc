	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805eaec
FUN_0805eaec: @ 0x0805EAEC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r2, r0, #0
	adds r4, r1, #0
	movs r5, #0
	strb r5, [r4, #1]
	movs r0, #1
	strb r0, [r4, #2]
	str r5, [r4, #0x14]
	adds r6, r4, #0
	adds r6, #0x20
	adds r2, #0x18
	adds r0, r6, #0
	adds r1, r2, #0
	movs r2, #1
	bl AuxSprite_Setup
	movs r0, #3
	strb r0, [r6, #7]
	adds r4, #0x3c
	str r5, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0805EB28 @ =0x05000002
	bl CpuSet
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805EB28: .4byte 0x05000002

	thumb_func_start FUN_0805eb2c
FUN_0805eb2c: @ 0x0805EB2C
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r2, r5, #0
	adds r2, #0x20
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805EB52
	movs r4, #0
	strb r4, [r5, #1]
	movs r1, #1
	strb r1, [r5, #2]
	str r4, [r5, #0x14]
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
	adds r0, r2, #0
	bl AuxSprite_Remove
	strb r4, [r5]
_0805EB52:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805eb58
FUN_0805eb58: @ 0x0805EB58
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805eb5c
FUN_0805eb5c: @ 0x0805EB5C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r5, #0
	adds r4, #0x20
	ldrb r0, [r5, #2]
	cmp r0, #0
	beq _0805EB7C
	movs r0, #0
	strb r0, [r5, #2]
	movs r0, #2
	strh r0, [r4, #0x10]
	movs r0, #0xd8
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0805EB7C:
	ldr r0, [r5, #0x14]
	cmp r0, #5
	bne _0805EB86
	movs r0, #1
	b _0805EB8C
_0805EB86:
	cmp r0, #0xa
	bne _0805EB8E
	movs r0, #0
_0805EB8C:
	strh r0, [r4, #0x10]
_0805EB8E:
	ldr r1, [r5, #0x14]
	cmp r1, #9
	bhi _0805EBA2
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _0805EBB4
	adds r1, r6, #0
	adds r1, #0x34
	b _0805EBB8
_0805EBA2:
	cmp r1, #0x13
	bhi _0805EBC0
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bhi _0805EBB4
	adds r1, r6, #0
	adds r1, #0x34
	b _0805EBB8
_0805EBB4:
	adds r1, r6, #0
	adds r1, #0x18
_0805EBB8:
	adds r0, r4, #0
	bl FUN_0822a568
	b _0805EBCA
_0805EBC0:
	adds r1, r6, #0
	adds r1, #0x34
	adds r0, r4, #0
	bl FUN_0822a568
_0805EBCA:
	ldr r0, [r5, #0x14]
	cmp r0, #0x1d
	bls _0805EBE8
	adds r1, r6, #0
	adds r1, #0x18
	adds r0, r4, #0
	bl FUN_0822a568
	movs r0, #3
	movs r1, #0
	strb r0, [r5, #1]
	movs r0, #1
	strb r0, [r5, #2]
	str r1, [r5, #0x14]
	b _0805EBEC
_0805EBE8:
	adds r0, #1
	str r0, [r5, #0x14]
_0805EBEC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805ebf4
FUN_0805ebf4: @ 0x0805EBF4
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #2]
	cmp r0, #0
	beq _0805EC02
	movs r0, #0
	strb r0, [r2, #2]
_0805EC02:
	ldr r0, [r2, #0x14]
	cmp r0, #0x32
	bne _0805EC16
	movs r0, #3
	movs r1, #0
	strb r0, [r2, #1]
	movs r0, #1
	strb r0, [r2, #2]
	str r1, [r2, #0x14]
	b _0805EC1A
_0805EC16:
	adds r0, #1
	str r0, [r2, #0x14]
_0805EC1A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805ec20
FUN_0805ec20: @ 0x0805EC20
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	adds r6, r7, #0
	adds r6, #0x20
	ldrb r0, [r7, #2]
	cmp r0, #0
	beq _0805EC32
	movs r0, #0
	strb r0, [r7, #2]
_0805EC32:
	ldr r0, [r7, #0x14]
	cmp r0, #9
	bhi _0805EC88
	ldr r0, [r7, #0x18]
	ldr r1, [r7, #0x1c]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	ldr r0, _0805EC7C @ =0x0203B400
	mov ip, r0
	ldr r3, _0805EC80 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r5, _0805EC84 @ =0x000003FF
	ands r1, r5
	str r1, [r3]
	lsls r0, r1, #1
	add r0, ip
	ldrh r2, [r0]
	ldrh r0, [r6, #0x1c]
	subs r0, #4
	movs r4, #7
	ands r2, r4
	adds r0, r0, r2
	strh r0, [r6, #0x1c]
	adds r1, #1
	ands r1, r5
	str r1, [r3]
	lsls r1, r1, #1
	add r1, ip
	ldrh r1, [r1]
	ldrh r0, [r6, #0x20]
	subs r0, #4
	ands r1, r4
	adds r0, r0, r1
	strh r0, [r6, #0x20]
	b _0805EC94
	.align 2, 0
_0805EC7C: .4byte 0x0203B400
_0805EC80: .4byte 0x030046B8
_0805EC84: .4byte 0x000003FF
_0805EC88:
	cmp r0, #0xa
	bne _0805EC94
	ldr r0, [r7, #0x18]
	ldr r1, [r7, #0x1c]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
_0805EC94:
	ldr r0, [r7, #0x14]
	cmp r0, #0x28
	bne _0805ECA8
	movs r0, #4
	movs r1, #0
	strb r0, [r7, #1]
	movs r0, #1
	strb r0, [r7, #2]
	str r1, [r7, #0x14]
	b _0805ECAC
_0805ECA8:
	adds r0, #1
	str r0, [r7, #0x14]
_0805ECAC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805ecb4
FUN_0805ecb4: @ 0x0805ECB4
	push {r4, r5, lr}
	sub sp, #0x14
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _0805ECE8
	movs r0, #0
	strb r0, [r4, #2]
	ldr r0, _0805ED5C @ =0x03002BE0
	ldr r2, [r0]
	cmp r2, #0
	beq _0805ECE8
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0x18
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	movs r3, #0x1c
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #3]
_0805ECE8:
	ldr r3, [r4, #0x14]
	movs r0, #0xf
	ands r3, r0
	cmp r3, #0xf
	bne _0805ED3A
	movs r1, #0xad
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0805ED3A
	ldr r2, _0805ED60 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805ED64 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0805ED68 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	ands r1, r3
	ldrb r3, [r4, #3]
	adds r1, r1, r3
	subs r1, #8
	ldrh r2, [r4, #6]
	ldrh r3, [r4, #4]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	ldrh r0, [r4, #0xc]
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r0, #0x18
	str r0, [sp, #0x10]
	adds r0, r5, #0
	bl FUN_0805f320
_0805ED3A:
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #4
	ldr r1, [r4, #0x14]
	cmp r1, r0
	bne _0805ED78
	ldrb r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0xe]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r4, #0xf]
	cmp r0, r2
	bhs _0805ED6C
	movs r0, #2
	b _0805ED6E
	.align 2, 0
_0805ED5C: .4byte 0x03002BE0
_0805ED60: .4byte 0x030046B8
_0805ED64: .4byte 0x000003FF
_0805ED68: .4byte 0x0203B400
_0805ED6C:
	movs r0, #5
_0805ED6E:
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4, #2]
	str r1, [r4, #0x14]
	b _0805ED7C
_0805ED78:
	adds r0, r1, #1
	str r0, [r4, #0x14]
_0805ED7C:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805ed84
FUN_0805ed84: @ 0x0805ED84
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r3, #0x20
	ldrb r0, [r1, #2]
	cmp r0, #0
	beq _0805ED98
	movs r0, #0
	strb r0, [r1, #2]
	strh r0, [r3, #0x10]
_0805ED98:
	ldr r0, [r1, #0x14]
	cmp r0, #5
	beq _0805EDAE
	cmp r0, #0xa
	bne _0805EDB2
	movs r0, #2
	strh r0, [r3, #0x10]
	adds r0, r4, #0
	bl FUN_0805eb2c
	b _0805EDB8
_0805EDAE:
	movs r0, #1
	strh r0, [r3, #0x10]
_0805EDB2:
	ldr r0, [r1, #0x14]
	adds r0, #1
	str r0, [r1, #0x14]
_0805EDB8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity0805ee80_Update
Entity0805ee80_Update: @ 0x0805EDC0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x54
	movs r5, #0
	ldr r7, _0805EDF4 @ =0x085ABA70
_0805EDCC:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805EDE4
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
_0805EDE4:
	adds r5, #1
	adds r4, #0x4c
	cmp r5, #7
	ble _0805EDCC
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805EDF4: .4byte 0x085ABA70

	thumb_func_start Entity0805ee80_Destroy
Entity0805ee80_Destroy: @ 0x0805EDF8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x54
	movs r4, #0
_0805EE02:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805eb2c
	adds r4, #1
	adds r5, #0x4c
	cmp r4, #7
	ble _0805EE02
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity0805ee80_Init
Entity0805ee80_Init: @ 0x0805EE1C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	str r1, [r6, #0x50]
	adds r5, r6, #0
	adds r5, #0x18
	movs r4, #1
_0805EE28:
	adds r0, r5, #0
	ldr r1, _0805EE7C @ =0x00005AFD
	bl Video_GetAuxSprite
	adds r5, #0x1c
	subs r4, #1
	cmp r4, #0
	bge _0805EE28
	adds r0, r6, #0
	adds r0, #0x18
	movs r1, #9
	bl Video_SetAuxSpritePltt
	adds r0, r6, #0
	adds r0, #0x34
	movs r1, #0xa
	bl Video_SetAuxSpritePltt
	adds r5, r6, #0
	adds r5, #0x54
	movs r4, #0
_0805EE52:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805eaec
	adds r4, #1
	adds r5, #0x4c
	cmp r4, #7
	ble _0805EE52
	ldr r0, [r6, #0x50]
	bl Entity0805f2dc_Create
	movs r2, #0xad
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805EE7C: .4byte 0x00005AFD

	thumb_func_start Entity0805ee80_Create
Entity0805ee80_Create: @ 0x0805EE80
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xae
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805EEBC
	ldr r1, _0805EEB4 @ =Entity0805ee80_Update
	ldr r2, _0805EEB8 @ =Entity0805ee80_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity0805ee80_Init
	cmp r0, #0
	bge _0805EEBC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805EEBE
	.align 2, 0
_0805EEB4: .4byte Entity0805ee80_Update
_0805EEB8: .4byte Entity0805ee80_Destroy
_0805EEBC:
	adds r0, r4, #0
_0805EEBE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805eec4
FUN_0805eec4: @ 0x0805EEC4
	push {lr}
	adds r1, r0, #0
	adds r1, #0x54
	movs r2, #0
_0805EECC:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0805EED6
	adds r0, r1, #0
	b _0805EEE0
_0805EED6:
	adds r2, #1
	adds r1, #0x4c
	cmp r2, #7
	ble _0805EECC
	movs r0, #0
_0805EEE0:
	pop {r1}
	bx r1

	thumb_func_start FUN_0805eee4
FUN_0805eee4: @ 0x0805EEE4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r2, #0
	mov r8, r3
	ldr r7, [sp, #0x30]
	cmp r0, #0
	beq _0805EF58
	bl FUN_0805eec4
	adds r6, r0, #0
	cmp r6, #0
	beq _0805EF58
	adds r0, #0x20
	movs r4, #1
	movs r1, #0
	strb r4, [r6, #1]
	strb r4, [r6, #2]
	str r1, [r6, #0x14]
	movs r1, #2
	movs r2, #0
	mov sb, r2
	strh r1, [r0, #0x10]
	ldr r1, [r7]
	ldr r2, [r7, #4]
	str r1, [r6, #0x18]
	str r2, [r6, #0x1c]
	ldr r1, [r7]
	ldr r2, [r7, #4]
	str r1, [r6, #0x3c]
	str r2, [r6, #0x40]
	ldr r1, [r6, #0x20]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r6, #0x20]
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	strh r5, [r6, #6]
	mov r0, r8
	strh r0, [r6, #4]
	ldr r0, [sp, #0x1c]
	strh r0, [r6, #8]
	ldr r0, [sp, #0x20]
	strh r0, [r6, #0xa]
	ldr r0, [sp, #0x24]
	strh r0, [r6, #0xc]
	ldr r0, [sp, #0x28]
	strb r0, [r6, #0x10]
	ldr r0, [sp, #0x2c]
	strb r0, [r6, #0xf]
	mov r2, sb
	strb r2, [r6, #0xe]
	strb r4, [r6]
	movs r0, #0
	b _0805EF5C
_0805EF58:
	movs r0, #1
	rsbs r0, r0, #0
_0805EF5C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805ef68
FUN_0805ef68: @ 0x0805EF68
	push {r4, lr}
	sub sp, #0x14
	adds r4, r1, #0
	cmp r0, #0
	beq _0805EF9E
	movs r1, #0xad
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0805EF9E
	ldr r0, [sp, #0x1c]
	str r0, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	ldr r0, [sp, #0x24]
	str r0, [sp, #8]
	ldr r0, [sp, #0x28]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x10]
	adds r0, r1, #0
	adds r1, r4, #0
	bl FUN_0805f320
	movs r0, #0
	b _0805EFA2
_0805EF9E:
	movs r0, #1
	rsbs r0, r0, #0
_0805EFA2:
	add sp, #0x14
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805efac
FUN_0805efac: @ 0x0805EFAC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r2, #0
	ldr r0, _0805EFE0 @ =0x03002BE0
	ldr r3, [r0]
	adds r4, r3, #0
	cmp r3, #0
	beq _0805F000
	ldrh r0, [r3, #0x24]
	ldrh r6, [r1, #4]
	cmp r0, r6
	bne _0805F000
	movs r6, #0xb6
	lsls r6, r6, #1
	adds r0, r3, r6
	cmp r0, r1
	bne _0805F000
	ldrb r0, [r2, #1]
	cmp r0, #0
	beq _0805EFE4
	adds r1, r0, #0
	adds r0, r3, #0
	bl FUN_0807ad60
	b _0805F000
	.align 2, 0
_0805EFE0: .4byte 0x03002BE0
_0805EFE4:
	ldr r0, _0805F008 @ =0x0000097C
	adds r3, r4, r0
	movs r1, #0x98
	lsls r1, r1, #4
	adds r0, r4, r1
	str r0, [sp]
	adds r0, r5, #0
	adds r0, #8
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #1
	movs r2, #0x1e
	bl MosaicFader_Start
_0805F000:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805F008: .4byte 0x0000097C

	thumb_func_start FUN_0805f00c
FUN_0805f00c: @ 0x0805F00C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r2, r0, #0
	adds r7, r1, #0
	adds r4, r7, #0
	adds r4, #0x68
	adds r2, #0x18
	adds r0, r4, #0
	adds r1, r2, #0
	movs r2, #1
	bl AuxSprite_Setup
	movs r6, #0
	movs r0, #1
	strb r0, [r4, #7]
	movs r0, #0x84
	adds r0, r0, r7
	mov r8, r0
	str r6, [sp, #0xc]
	add r0, sp, #0xc
	mov r1, r8
	ldr r2, _0805F0B4 @ =0x05000002
	bl CpuSet
	adds r5, r7, #0
	adds r5, #0x18
	ldr r2, _0805F0B8 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r4, #0x64
	orrs r0, r4
	ldr r1, _0805F0BC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	add r3, sp, #0x10
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	str r6, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805F0C0 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805F0C4 @ =FUN_0805efac
	adds r0, r5, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	str r6, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x32
	movs r2, #0x1e
	movs r3, #0
	bl Hitbox_SetAttack
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805F0B4: .4byte 0x05000002
_0805F0B8: .4byte 0xFFFF0000
_0805F0BC: .4byte 0x0000FFFF
_0805F0C0: .4byte 0x00002001
_0805F0C4: .4byte FUN_0805efac

	thumb_func_start FUN_0805f0c8
FUN_0805f0c8: @ 0x0805F0C8
	push {r4, lr}
	adds r4, r1, #0
	adds r2, r4, #0
	adds r2, #0x68
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805F0E8
	ldr r0, [r4, #0x68]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x68]
	adds r0, r2, #0
	bl AuxSprite_Remove
	movs r0, #0
	strb r0, [r4]
_0805F0E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
