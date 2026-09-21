	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Entity0805f2dc_Update
Entity0805f2dc_Update: @ 0x0805F0F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	mov r5, r8
	adds r5, #0x54
	movs r7, #0
	movs r0, #1
	mov sl, r0
	adds r4, r5, #0
	movs r1, #3
	mov sb, r1
_0805F10C:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805F20C
	movs r2, #0x68
	adds r2, r2, r5
	mov ip, r2
	adds r6, r5, #0
	adds r6, #0x18
	ldr r0, [r4, #4]
	cmp r0, #0x13
	bhi _0805F14C
	cmp r0, #0
	bne _0805F12C
	movs r0, #2
	strh r0, [r2, #0x10]
	b _0805F168
_0805F12C:
	cmp r0, #5
	bne _0805F134
	mov r0, sl
	b _0805F146
_0805F134:
	cmp r0, #0xa
	bne _0805F140
	mov r2, sb
	mov r1, ip
	strh r2, [r1, #0x10]
	b _0805F168
_0805F140:
	cmp r0, #0xf
	bne _0805F168
	movs r0, #0
_0805F146:
	mov r3, ip
	strh r0, [r3, #0x10]
	b _0805F168
_0805F14C:
	adds r1, r0, #0
	subs r1, #0x14
	movs r0, #7
	ands r1, r0
	cmp r1, #3
	bne _0805F15E
	mov r0, ip
	strh r1, [r0, #0x10]
	b _0805F168
_0805F15E:
	cmp r1, #7
	bne _0805F168
	movs r0, #0
	mov r1, ip
	strh r0, [r1, #0x10]
_0805F168:
	mov r1, ip
	adds r1, #0x1c
	ldrh r0, [r4, #0x10]
	mov r2, ip
	ldrh r2, [r2, #0x1c]
	adds r0, r0, r2
	mov r3, ip
	strh r0, [r3, #0x1c]
	ldrh r0, [r4, #0x12]
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	ldrh r0, [r4, #0x14]
	ldrh r3, [r1, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
	mov r0, r8
	ldr r3, [r0, #0x50]
	adds r0, r3, #0
	subs r0, #0x1e
	ldr r2, [r4, #4]
	cmp r2, r0
	bhs _0805F1C4
	cmp r2, #5
	bls _0805F206
	ldr r0, _0805F1C0 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0805F1AE
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _0805F206
_0805F1AE:
	adds r0, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	bl FUN_08236400
	b _0805F206
	.align 2, 0
_0805F1C0: .4byte 0x03002BE0
_0805F1C4:
	adds r0, r3, #0
	subs r0, #0xf
	cmp r2, r0
	bhs _0805F1D6
	mov r3, sb
	ands r2, r3
	cmp r2, #0
	beq _0805F1E2
	b _0805F1EE
_0805F1D6:
	cmp r2, r3
	bhs _0805F1FC
	mov r0, sb
	ands r2, r0
	cmp r2, #1
	bhi _0805F1EE
_0805F1E2:
	mov r1, ip
	ldr r0, [r1]
	mov r2, sl
	orrs r0, r2
	str r0, [r1]
	b _0805F206
_0805F1EE:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
	b _0805F206
_0805F1FC:
	mov r0, r8
	adds r1, r5, #0
	adds r2, r7, #0
	bl FUN_0805f0c8
_0805F206:
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
_0805F20C:
	adds r7, #1
	adds r4, #0x94
	adds r5, #0x94
	cmp r7, #0xb
	bgt _0805F218
	b _0805F10C
_0805F218:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity0805f2dc_Destroy
Entity0805f2dc_Destroy: @ 0x0805F228
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x54
	movs r4, #0
_0805F232:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805f0c8
	adds r4, #1
	adds r5, #0x94
	cmp r4, #0xb
	ble _0805F232
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity0805f2dc_Init
Entity0805f2dc_Init: @ 0x0805F24C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	str r1, [r6, #0x50]
	cmp r1, #0x3b
	bhi _0805F260
	movs r0, #0x3c
	str r0, [r6, #0x50]
_0805F260:
	adds r7, r6, #0
	adds r7, #0x18
	movs r0, #0x34
	adds r0, r0, r6
	mov r8, r0
	movs r0, #0x54
	adds r0, r0, r6
	mov sb, r0
	adds r5, r7, #0
	movs r4, #1
_0805F274:
	adds r0, r5, #0
	ldr r1, _0805F2B8 @ =0x00005AFE
	bl Video_GetAuxSprite
	adds r5, #0x1c
	subs r4, #1
	cmp r4, #0
	bge _0805F274
	adds r0, r7, #0
	movs r1, #9
	bl Video_SetAuxSpritePltt
	mov r0, r8
	movs r1, #0x11
	bl Video_SetAuxSpritePltt
	mov r5, sb
	movs r4, #0
_0805F298:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805f00c
	adds r4, #1
	adds r5, #0x94
	cmp r4, #0xb
	ble _0805F298
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805F2B8: .4byte 0x00005AFE

	thumb_func_start FUN_0805f2bc
FUN_0805f2bc: @ 0x0805F2BC
	push {lr}
	adds r1, r0, #0
	adds r1, #0x54
	movs r2, #0
_0805F2C4:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0805F2CE
	adds r0, r1, #0
	b _0805F2D8
_0805F2CE:
	adds r2, #1
	adds r1, #0x94
	cmp r2, #0xb
	ble _0805F2C4
	movs r0, #0
_0805F2D8:
	pop {r1}
	bx r1

	thumb_func_start Entity0805f2dc_Create
Entity0805f2dc_Create: @ 0x0805F2DC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0805F30C @ =0x00000744
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805F318
	ldr r1, _0805F310 @ =Entity0805f2dc_Update
	ldr r2, _0805F314 @ =Entity0805f2dc_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity0805f2dc_Init
	cmp r0, #0
	bge _0805F318
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805F31A
	.align 2, 0
_0805F30C: .4byte 0x00000744
_0805F310: .4byte Entity0805f2dc_Update
_0805F314: .4byte Entity0805f2dc_Destroy
_0805F318:
	adds r0, r4, #0
_0805F31A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805f320
FUN_0805f320: @ 0x0805F320
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r1, #0
	mov r8, r2
	mov sl, r3
	adds r7, r0, #0
	cmp r7, #0
	beq _0805F34E
	adds r0, r7, #0
	bl FUN_0805f2bc
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x68
	movs r0, #0x18
	adds r0, r0, r5
	mov sb, r0
	cmp r5, #0
	bne _0805F354
_0805F34E:
	movs r0, #1
	rsbs r0, r0, #0
	b _0805F428
_0805F354:
	adds r3, r5, #0
	adds r3, #0x10
	ldr r2, _0805F378 @ =0x085B0A08
	adds r0, r4, #0
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
	blt _0805F37C
	asrs r1, r0, #0xc
	b _0805F382
	.align 2, 0
_0805F378: .4byte 0x085B0A08
_0805F37C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805F382:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805F3A2
	asrs r0, r0, #0xc
	b _0805F3A8
_0805F3A2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805F3A8:
	movs r4, #0
	strh r0, [r3, #4]
	movs r0, #2
	strh r0, [r6, #0x10]
	ldr r0, [sp, #0x38]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r0, r6, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	str r4, [sp]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #4]
	mov r0, sb
	mov r1, sl
	ldr r2, [sp, #0x28]
	movs r3, #0
	bl FUN_082364f8
	add r0, sp, #0x30
	ldrb r0, [r0]
	strb r0, [r5, #1]
	mov r1, sp
	ldrh r1, [r1, #0x34]
	strh r1, [r5, #8]
	mov r0, sp
	ldrh r0, [r0, #0x34]
	strh r0, [r5, #0xa]
	mov r1, sp
	ldrh r1, [r1, #0x34]
	strh r1, [r5, #0xc]
	mov r0, sp
	ldrh r0, [r0, #0x34]
	strh r0, [r5, #0xe]
	ldr r1, [sp, #0x30]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _0805F410
	adds r1, r7, #0
	adds r1, #0x18
	adds r0, r6, #0
	bl FUN_0822a4fc
	b _0805F41A
_0805F410:
	adds r1, r7, #0
	adds r1, #0x34
	adds r0, r6, #0
	bl FUN_0822a4fc
_0805F41A:
	movs r0, #0
	str r0, [r5, #4]
	movs r0, #1
	strb r0, [r5]
	ldr r0, _0805F438 @ =0x00000361
	bl PlaySound_082406e0
_0805F428:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805F438: .4byte 0x00000361
