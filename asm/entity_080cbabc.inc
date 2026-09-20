	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cb7b4
FUN_080cb7b4: @ 0x080CB7B4
	adds r1, r2, #0
	adds r1, #0xb8
	movs r0, #1
	str r0, [r1]
	adds r2, #0xbe
	movs r0, #0
	strh r0, [r2]
	bx lr

	thumb_func_start Entity080cbabc_Update
Entity080cbabc_Update: @ 0x080CB7C4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r6, #0
	adds r7, #0xb8
	ldr r0, [r7]
	mov r8, r0
	cmp r0, #0
	beq _080CB860
	adds r1, r6, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _080CB7F0
	movs r0, #4
	strh r0, [r6, #0x28]
	b _080CB8DC
_080CB7F0:
	cmp r0, #4
	bne _080CB854
	adds r0, r6, #0
	adds r0, #0xbc
	adds r4, r6, #0
	adds r4, #0x18
	ldrh r1, [r0]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _080CB80C
	movs r0, #7
	b _080CB81A
_080CB80C:
	asrs r0, r1, #1
	ands r0, r2
	cmp r0, #0
	beq _080CB818
	movs r0, #8
	b _080CB81A
_080CB818:
	movs r0, #6
_080CB81A:
	strh r0, [r4, #0x10]
	cmp r1, #2
	bgt _080CB828
	ldr r0, [r4]
	movs r1, #0xd
	rsbs r1, r1, #0
	b _080CB84E
_080CB828:
	cmp r1, #4
	bgt _080CB838
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #8
	b _080CB840
_080CB838:
	cmp r1, #5
	bgt _080CB846
	ldr r0, [r4]
	movs r1, #0xc
_080CB840:
	orrs r0, r1
	str r0, [r4]
	b _080CB8DC
_080CB846:
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	subs r1, #0xd
_080CB84E:
	ands r0, r1
	str r0, [r4]
	b _080CB8DC
_080CB854:
	cmp r0, #6
	bls _080CB8DC
	adds r0, r6, #0
	bl KillEntity
	b _080CB8DC
_080CB860:
	adds r0, r6, #0
	adds r0, #0xb0
	ldrh r0, [r0]
	ldrh r1, [r6, #0x34]
	adds r0, r0, r1
	strh r0, [r6, #0x34]
	adds r0, r6, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	ldrh r2, [r6, #0x38]
	adds r0, r0, r2
	strh r0, [r6, #0x38]
	adds r4, r6, #0
	adds r4, #0x60
	adds r5, r6, #0
	adds r5, #0x34
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	ldr r0, _080CB8BC @ =0x03002BE0
	ldr r2, [r0]
	ldr r1, _080CB8C0 @ =0x00080002
	ldr r0, [r2, #0x20]
	orrs r0, r1
	str r0, [r2, #0x20]
	adds r0, r5, #0
	bl FUN_082328ec
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0x36
	ldrsh r1, [r6, r2]
	cmp r0, r1
	ble _080CB8C4
	movs r0, #1
	str r0, [r7]
	adds r0, r6, #0
	adds r0, #0xbe
	mov r1, r8
	strh r1, [r0]
	b _080CB8DC
	.align 2, 0
_080CB8BC: .4byte 0x03002BE0
_080CB8C0: .4byte 0x00080002
_080CB8C4:
	adds r1, r6, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080CB8DC
	adds r0, r6, #0
	bl KillEntity
_080CB8DC:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity080cbabc_Destroy
Entity080cbabc_Destroy: @ 0x080CB8E8
	push {lr}
	adds r0, #0x18
	bl AuxSprite_Remove
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080cb8f8
FUN_080cb8f8: @ 0x080CB8F8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov sb, r1
	mov r8, r2
	adds r6, r3, #0
	adds r4, r7, #0
	adds r4, #0x44
	ldr r1, _080CB948 @ =0x0000210E
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r5, r7, #0
	adds r5, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r0, r8
	strh r0, [r5, #0x10]
	adds r6, #0x2c
	adds r0, r4, #0
	adds r1, r6, #0
	bl Video_SetAuxSpritePltt
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CB948: .4byte 0x0000210E

	thumb_func_start FUN_080cb94c
FUN_080cb94c: @ 0x080CB94C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	mov sl, r1
	mov r8, r2
	mov sb, r3
	ldr r6, [sp, #0x3c]
	ldr r7, [sp, #0x40]
	adds r5, r4, #0
	adds r5, #0x60
	ldr r2, _080CB9EC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x1e
	orrs r0, r3
	ldr r1, _080CB9F0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _080CB9F4 @ =0x00002101
	movs r0, #1
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0x10
	bl FUN_082364f8
	ldr r1, _080CB9F8 @ =FUN_080cb7b4
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r1, r4, #0
	adds r1, #0x34
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r4, #0xa2
	mov r0, sl
	strb r0, [r4]
	adds r0, r5, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CB9EC: .4byte 0xFFFF0000
_080CB9F0: .4byte 0x0000FFFF
_080CB9F4: .4byte 0x00002101
_080CB9F8: .4byte FUN_080cb7b4

	thumb_func_start Entity080cbabc_Init
Entity080cbabc_Init: @ 0x080CB9FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	ldr r4, [sp, #0x30]
	ldr r5, [sp, #0x34]
	bl FUN_080cb8f8
	str r4, [sp]
	str r5, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	bl FUN_080cb94c
	ldr r2, _080CBA48 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _080CBA4C
	asrs r2, r0, #0xc
	b _080CBA52
	.align 2, 0
_080CBA48: .4byte 0x085B0A08
_080CBA4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CBA52:
	adds r0, r7, #0
	adds r0, #0xb0
	movs r1, #0
	strh r2, [r0]
	adds r0, #2
	strh r1, [r0]
	ldr r1, _080CBA7C @ =0x085B0A08
	movs r0, #0xff
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _080CBA80
	asrs r3, r0, #0xc
	b _080CBA86
	.align 2, 0
_080CBA7C: .4byte 0x085B0A08
_080CBA80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080CBA86:
	adds r0, r7, #0
	adds r0, #0xb4
	movs r2, #0
	strh r3, [r0]
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	adds r1, r7, #0
	adds r1, #0xbc
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0xbe
	strh r2, [r0]
	movs r0, #0
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity080cbabc_Create
Entity080cbabc_Create: @ 0x080CBABC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r0, #8
	movs r1, #0xc0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080CBB1C
	ldr r1, _080CBB14 @ =Entity080cbabc_Update
	ldr r2, _080CBB18 @ =Entity080cbabc_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x30]
	str r0, [sp, #4]
	ldr r0, [sp, #0x34]
	str r0, [sp, #8]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x40]
	str r0, [sp, #0x14]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl Entity080cbabc_Init
	cmp r0, #0
	bge _080CBB1C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080CBB1E
	.align 2, 0
_080CBB14: .4byte Entity080cbabc_Update
_080CBB18: .4byte Entity080cbabc_Destroy
_080CBB1C:
	adds r0, r4, #0
_080CBB1E:
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
