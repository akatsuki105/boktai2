	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809ef38
FUN_0809ef38: @ 0x0809EF38
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _0809EF98 @ =0x00000252
	adds r0, r4, r2
	movs r5, #0x2e
	ldrsh r1, [r3, r5]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bne _0809F024
	movs r5, #0x2c
	ldrsh r0, [r3, r5]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r2, r0, r1
	cmp r2, #0
	bge _0809EF6A
	rsbs r2, r2, #0
_0809EF6A:
	movs r1, #0x30
	ldrsh r0, [r3, r1]
	movs r5, #0x95
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	cmp r0, #0
	bge _0809EF80
	rsbs r0, r0, #0
_0809EF80:
	cmp r2, #0x80
	bgt _0809F024
	cmp r0, #0x80
	bgt _0809F024
	ldr r1, [r3, #0x1c]
	cmp r1, #1
	beq _0809EF9C
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r4, r2
	b _0809F02A
	.align 2, 0
_0809EF98: .4byte 0x00000252
_0809EF9C:
	movs r5, #0x98
	lsls r5, r5, #2
	adds r0, r4, r5
	strb r1, [r0]
	ldr r0, _0809F018 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _0809EFB8
	ldr r0, _0809F01C @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _0809EFB8
	movs r1, #1
_0809EFB8:
	cmp r1, #0
	bne _0809F02E
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r3, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _0809F02E
	cmp r0, #3
	beq _0809F02E
	cmp r0, #4
	beq _0809F02E
	movs r5, #0xe0
	lsls r5, r5, #2
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F02E
	adds r1, #0x34
	adds r0, r3, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809F02E
	adds r2, #0x24
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #7
	bne _0809F02E
	movs r5, #0x94
	lsls r5, r5, #2
	adds r1, r4, r5
	ldr r2, _0809F020 @ =0x00000262
	adds r0, r4, r2
	ldrh r2, [r0]
	adds r0, r3, #0
	bl FUN_0807a528
	adds r5, #0xe
	adds r1, r4, r5
	movs r0, #1
	b _0809F02C
	.align 2, 0
_0809F018: .4byte 0x03002B8C
_0809F01C: .4byte 0x03002B60
_0809F020: .4byte 0x00000262
_0809F024:
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r4, r0
_0809F02A:
	movs r0, #0
_0809F02C:
	strb r0, [r1]
_0809F02E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809f034
FUN_0809f034: @ 0x0809F034
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r0, #0x96
	lsls r0, r0, #2
	adds r6, r4, r0
	ldr r2, [r6]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _0809F090
	movs r1, #0x40
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809F0A2
	ldr r0, _0809F08C @ =0x030046A0
	ldr r0, [r0]
	movs r7, #0xef
	lsls r7, r7, #2
	adds r5, r0, r7
	ldr r3, [r5]
	cmp r3, #0
	ble _0809F0A2
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	subs r7, #0x52
	adds r1, r2, r7
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0809F0A2
	subs r0, r3, #1
	str r0, [r5]
	ldr r1, [r6]
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0809F0A2
	.align 2, 0
_0809F08C: .4byte 0x030046A0
_0809F090:
	adds r0, r4, #0
	adds r0, #0x44
	ldr r1, _0809F0B4 @ =0x0000013D
	bl Video_SetAuxSpritePltt
	ldr r7, _0809F0B8 @ =0x0000025E
	adds r1, r4, r7
	movs r0, #0
	strb r0, [r1]
_0809F0A2:
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809F0B4: .4byte 0x0000013D
_0809F0B8: .4byte 0x0000025E

	thumb_func_start FUN_0809f0bc
FUN_0809f0bc: @ 0x0809F0BC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x40
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809F138
	ldr r1, _0809F0EC @ =0x0000025F
	adds r0, r5, r1
	ldrb r0, [r0]
	lsrs r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	beq _0809F0FA
	cmp r1, #1
	bgt _0809F0F0
	cmp r1, #0
	beq _0809F10C
	b _0809F124
	.align 2, 0
_0809F0EC: .4byte 0x0000025F
_0809F0F0:
	cmp r1, #2
	beq _0809F10C
	cmp r1, #3
	beq _0809F11A
	b _0809F124
_0809F0FA:
	adds r0, r5, #0
	adds r0, #0x44
	ldr r1, _0809F108 @ =0x0000013F
	bl Video_SetAuxSpritePltt
	b _0809F124
	.align 2, 0
_0809F108: .4byte 0x0000013F
_0809F10C:
	adds r0, r5, #0
	adds r0, #0x44
	movs r1, #0x9f
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	b _0809F124
_0809F11A:
	adds r0, r5, #0
	adds r0, #0x44
	ldr r1, _0809F130 @ =0x0000013D
	bl Video_SetAuxSpritePltt
_0809F124:
	ldr r0, _0809F134 @ =0x0000025F
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0809F170
	.align 2, 0
_0809F130: .4byte 0x0000013D
_0809F134: .4byte 0x0000025F
_0809F138:
	ldr r1, _0809F160 @ =0x0000025F
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #4
	bls _0809F146
	movs r0, #4
	strb r0, [r4]
_0809F146:
	ldrb r6, [r4]
	cmp r6, #0
	beq _0809F164
	adds r0, r5, #0
	adds r0, #0x44
	movs r1, #0x9f
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _0809F170
	.align 2, 0
_0809F160: .4byte 0x0000025F
_0809F164:
	adds r0, r5, #0
	adds r0, #0x44
	ldr r1, _0809F178 @ =0x0000013D
	bl Video_SetAuxSpritePltt
	strb r6, [r4]
_0809F170:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809F178: .4byte 0x0000013D

	thumb_func_start FUN_0809f17c
FUN_0809f17c: @ 0x0809F17C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	movs r0, #0x98
	lsls r0, r0, #2
	add r0, r8
	ldrh r0, [r0]
	cmp r0, #0
	bne _0809F198
	b _0809F2E4
_0809F198:
	ldr r5, _0809F218 @ =0x030046A0
	ldr r0, [r5]
	movs r4, #0xef
	lsls r4, r4, #2
	adds r1, r0, r4
	ldr r0, [r1]
	ldr r2, _0809F21C @ =0x0000270F
	cmp r0, r2
	ble _0809F1AC
	str r2, [r1]
_0809F1AC:
	ldr r0, [r5]
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0xfa
	lsls r1, r1, #2
	bl Div
	str r0, [sp]
	ldr r2, [r5]
	adds r2, r2, r4
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r4, [r2]
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [sp, #0xc]
	add r5, sp, #0x10
	mov r6, r8
	adds r6, #0x34
	mov r1, r8
	ldrh r0, [r1, #0x34]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0809F220
	asrs r0, r0, #8
	b _0809F226
	.align 2, 0
_0809F218: .4byte 0x030046A0
_0809F21C: .4byte 0x0000270F
_0809F220:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0809F226:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0809F238
	asrs r0, r0, #8
	b _0809F23E
_0809F238:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0809F23E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0809F252
	asrs r0, r0, #8
	b _0809F258
_0809F252:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0809F258:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0809F2E0 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	mov r1, sp
	ldrh r0, [r1, #0x10]
	subs r0, #0x10
	add r1, sp, #0x10
	strh r0, [r1]
	ldrh r0, [r1, #2]
	subs r0, #0x2c
	strh r0, [r1, #2]
	movs r0, #0x60
	add r0, r8
	mov sl, r0
	mov r7, r8
	adds r7, #0xa0
	mov sb, sp
	mov r6, r8
	adds r6, #0x80
	mov r4, r8
	adds r4, #0x88
	movs r5, #3
_0809F29C:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r1, sb
	adds r1, #4
	mov sb, r1
	subs r1, #4
	ldm r1!, {r2}
	adds r2, #0x1e
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	movs r3, #1
	bl MainSprite_SetPose
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	str r0, [r7]
	str r1, [r7, #4]
	mov r1, sp
	ldrh r0, [r1, #0x10]
	adds r0, #8
	add r1, sp, #0x10
	strh r0, [r1]
	adds r7, #0x60
	adds r6, #0x60
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809F29C
	b _0809F2FA
	.align 2, 0
_0809F2E0: .4byte 0x030047C8
_0809F2E4:
	movs r2, #1
	mov r1, r8
	adds r1, #0x88
	movs r5, #3
_0809F2EC:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809F2EC
_0809F2FA:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809f30c
FUN_0809f30c: @ 0x0809F30C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	mov r1, sp
	bl FUN_08230f94
	adds r2, r0, #0
	subs r2, #1
	cmp r0, #0
	ble _0809F356
	ldr r0, _0809F340 @ =0x00000261
	adds r3, r4, r0
	ldr r1, [sp]
	movs r5, #1
	movs r4, #0
_0809F332:
	ldr r0, [r1, #4]
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809F344
	cmp r0, #1
	beq _0809F348
	b _0809F34A
	.align 2, 0
_0809F340: .4byte 0x00000261
_0809F344:
	strb r5, [r3]
	b _0809F34A
_0809F348:
	strb r4, [r3]
_0809F34A:
	adds r1, #8
	adds r0, r2, #0
	subs r2, #1
	cmp r0, #0
	bgt _0809F332
	str r1, [sp]
_0809F356:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EntityDC21_Update
EntityDC21_Update: @ 0x0809F360
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0809f30c
	ldr r1, _0809F378 @ =0x0000025E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809F37C
	cmp r0, #1
	beq _0809F384
	b _0809F38A
	.align 2, 0
_0809F378: .4byte 0x0000025E
_0809F37C:
	adds r0, r4, #0
	bl FUN_0809ef38
	b _0809F38A
_0809F384:
	adds r0, r4, #0
	bl FUN_0809f034
_0809F38A:
	adds r0, r4, #0
	bl FUN_0809f0bc
	adds r0, r4, #0
	bl FUN_0809f17c
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityDC21_Destroy
EntityDC21_Destroy: @ 0x0809F3A0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0x18
	bl AuxSprite_Remove
	adds r4, r6, #0
	adds r4, #0x80
	movs r5, #3
_0809F3B0:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809F3B0
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r6, r1
	bl Hitbox_Unregister
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start EntityDC21_InitSprite
EntityDC21_InitSprite: @ 0x0809F3D0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x18
	adds r4, #0x44
	ldr r1, _0809F40C @ =0x0000A47C
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0
	strh r0, [r5, #0x10]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809F410
	bl VM_GetValue
	strh r0, [r5, #0x1c]
	bl VM_GetValue
	strh r0, [r5, #0x1e]
	bl VM_GetValue
	b _0809F414
	.align 2, 0
_0809F40C: .4byte 0x0000A47C
_0809F410:
	strh r0, [r5, #0x1c]
	strh r0, [r5, #0x1e]
_0809F414:
	strh r0, [r5, #0x20]
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809F42A
	bl VM_GetValue
	cmp r0, #0
	beq _0809F42A
	movs r0, #4
_0809F42A:
	str r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EntityDC21_InitMainSprites
EntityDC21_InitMainSprites: @ 0x0809F434
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r0, _0809F4A4 @ =0x0000CB05
	ldr r1, _0809F4A8 @ =0x0000B343
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _0809F49A
	adds r1, r5, #0
	adds r1, #0x60
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r5, #0
	adds r4, #0x60
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _0809F4AC @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	adds r6, r4, #0
	adds r4, #0x20
	movs r5, #3
_0809F476:
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x1e
	movs r3, #0x31
	bl MainSprite_Add
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809F476
_0809F49A:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809F4A4: .4byte 0x0000CB05
_0809F4A8: .4byte 0x0000B343
_0809F4AC: .4byte 0xFFFF0000

	thumb_func_start FUN_0809f4b0
FUN_0809f4b0: @ 0x0809F4B0
	push {lr}
	adds r2, r0, #0
	movs r0, #0x94
	lsls r0, r0, #2
	adds r3, r2, r0
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r0, [r2, #0x18]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809F4D8
	adds r1, #0xfc
	adds r0, r1, #0
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	b _0809F4EA
_0809F4D8:
	movs r0, #0x95
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_0809F4EA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EntityDC21_InitHitbox
EntityDC21_InitHitbox: @ 0x0809F4F0
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0x80
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r2, _0809F570 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x64
	orrs r0, r3
	ldr r1, _0809F574 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x96
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _0809F578 @ =0x00004001
	movs r0, #0
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	adds r0, r5, #0
	movs r1, #0
	adds r2, r4, #0
	bl Hitbox_SetHandler
	adds r4, #0x34
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809F570: .4byte 0xFFFF0000
_0809F574: .4byte 0x0000FFFF
_0809F578: .4byte 0x00004001

	thumb_func_start EntityDC21_Init
EntityDC21_Init: @ 0x0809F57C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r2, r1, #0
	ldr r0, _0809F598 @ =0x03002BE0
	ldr r1, [r0]
	movs r3, #0x96
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	cmp r1, #0
	bne _0809F59C
	movs r0, #1
	rsbs r0, r0, #0
	b _0809F5FA
	.align 2, 0
_0809F598: .4byte 0x03002BE0
_0809F59C:
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r4, #0
	strh r2, [r0]
	adds r0, r5, #0
	bl EntityDC21_InitSprite
	adds r0, r5, #0
	bl FUN_0809f4b0
	adds r0, r5, #0
	bl EntityDC21_InitHitbox
	adds r0, r5, #0
	bl EntityDC21_InitMainSprites
	ldr r3, _0809F5EC @ =0x0000025E
	adds r0, r5, r3
	strb r4, [r0]
	movs r1, #0x98
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	subs r1, #1
	adds r0, r5, r1
	strb r4, [r0]
	ldr r0, [r5, #0x18]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809F5F0
	adds r3, #1
	adds r1, r5, r3
	movs r0, #7
	b _0809F5F6
	.align 2, 0
_0809F5EC: .4byte 0x0000025E
_0809F5F0:
	ldr r0, _0809F600 @ =0x00000262
	adds r1, r5, r0
	movs r0, #1
_0809F5F6:
	strh r0, [r1]
	movs r0, #0
_0809F5FA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809F600: .4byte 0x00000262

	thumb_func_start EntityDC21_Create
EntityDC21_Create: @ 0x0809F604
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x99
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809F644
	ldr r1, _0809F63C @ =EntityDC21_Update
	ldr r2, _0809F640 @ =EntityDC21_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl EntityDC21_Init
	cmp r0, #0
	bge _0809F644
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809F646
	.align 2, 0
_0809F63C: .4byte EntityDC21_Update
_0809F640: .4byte EntityDC21_Destroy
_0809F644:
	adds r0, r4, #0
_0809F646:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
