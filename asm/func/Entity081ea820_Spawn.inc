	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov r8, r2
	mov sl, r3
	ldr r0, _081EA740 @ =0x030001BC
	ldr r7, [r0]
	cmp r7, #0
	bne _081EA6AC
	bl Entity081ea820_Create
	adds r7, r0, #0
	cmp r7, #0
	beq _081EA748
_081EA6AC:
	adds r0, r7, #0
	bl Entity081ea820_AllocElem
	adds r6, r0, #0
	cmp r6, #0
	beq _081EA748
	adds r0, #0xd2
	movs r4, #0
	movs r1, #1
	mov sb, r1
	mov r2, sb
	strb r2, [r0]
	mov r2, sp
	adds r2, #5
	adds r0, r5, #0
	add r1, sp, #4
	bl Entity081ea820_GetAnimVariant
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r6, #0x2c]
	str r1, [r6, #0x30]
	adds r0, r6, #0
	adds r0, #0xd0
	strh r4, [r0]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x34]
	str r1, [r6, #0x38]
	adds r0, r6, #0
	adds r0, #0x8c
	adds r1, r6, #0
	adds r1, #0x2c
	movs r2, #0
	bl ParticleShadow_Init
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	adds r1, r7, #0
	adds r1, #0x18
	adds r0, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #3
	strh r0, [r6, #0x10]
	ldr r0, [r6, #0xc]
	ldr r1, _081EA744 @ =0x00000243
	bl Video_SetAuxSpritePltt
	ldr r0, [r6]
	mov r1, sb
	orrs r0, r1
	str r0, [r6]
	movs r0, #2
	strb r0, [r6, #7]
	ldr r0, [sp, #0x30]
	str r0, [sp]
	adds r0, r6, #0
	mov r1, sl
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	bl Entity081ea820Elem_InitHitbox
	adds r0, r6, #0
	adds r0, #0xd3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b _081EA74C
	.align 2, 0
_081EA740: .4byte 0x030001BC
_081EA744: .4byte 0x00000243
_081EA748:
	movs r0, #1
	rsbs r0, r0, #0
_081EA74C:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
