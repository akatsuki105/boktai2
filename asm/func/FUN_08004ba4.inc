	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08004BD8 @ =0x03000020
	ldr r7, [r0]
	cmp r7, #0
	beq _08004BD2
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	cmp r1, #0
	beq _08004BD2
	adds r0, r7, #0
	bl FUN_08004694
	adds r5, r0, #0
	cmp r5, #0
	beq _08004BD2
	ldrb r0, [r5]
	cmp r0, #6
	beq _08004BDC
_08004BD2:
	movs r0, #1
	rsbs r0, r0, #0
	b _08004C68
	.align 2, 0
_08004BD8: .4byte 0x03000020
_08004BDC:
	adds r6, r5, #0
	adds r6, #0x8c
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x53
	movs r1, #1
	bl VM_GetKeywordValue
	mov r8, r0
	cmp r4, #0
	bne _08004C24
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq _08004C04
	cmp r0, #2
	bne _08004C14
_08004C04:
	movs r0, #2
	strh r0, [r5, #0x1a]
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #2
	bl Video_SetAuxSpritePltt
	b _08004C68
_08004C14:
	movs r0, #3
	strh r0, [r5, #0x1a]
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #3
	bl Video_SetAuxSpritePltt
	b _08004C68
_08004C24:
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq _08004C30
	cmp r0, #2
	bne _08004C44
_08004C30:
	movs r0, #4
	strh r0, [r5, #0x1a]
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #4
	bl Video_SetAuxSpritePltt
	adds r1, r7, #0
	adds r1, #0x30
	b _08004C56
_08004C44:
	movs r0, #5
	strh r0, [r5, #0x1a]
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #5
	bl Video_SetAuxSpritePltt
	adds r1, r7, #0
	adds r1, #0x50
_08004C56:
	str r1, [r5, #0x7c]
	movs r1, #1
	strb r1, [r7, #0x1f]
	mov r1, r8
	cmp r1, #0
	beq _08004C68
	ldr r0, _08004C74 @ =0x00000149
	bl PlaySound_082406e0
_08004C68:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08004C74: .4byte 0x00000149
