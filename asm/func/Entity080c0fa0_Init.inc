	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r5, r1, #0
	mov sb, r2
	mov r8, r3
	adds r6, r7, #0
	adds r6, #0x18
	adds r4, r7, #0
	adds r4, #0x44
	ldr r1, _080C0F18 @ =0x0000210E
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r7, #0x60]
	str r1, [r7, #0x64]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	movs r0, #1
	strb r0, [r6, #7]
	adds r0, r4, #0
	mov r1, sb
	bl Video_SetAuxSpritePltt
	adds r0, r7, #0
	adds r0, #0x6a
	mov r1, r8
	strh r1, [r0]
	ldrh r0, [r0]
	strh r0, [r6, #0x10]
	adds r0, r7, #0
	adds r0, #0x6c
	mov r2, sp
	ldrh r2, [r2, #0x1c]
	strh r2, [r0]
	ldrh r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080C0F1C @ =0x085B0A08
	adds r0, r3, #0
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
	blt _080C0F20
	asrs r0, r0, #0xc
	b _080C0F26
	.align 2, 0
_080C0F18: .4byte 0x0000210E
_080C0F1C: .4byte 0x085B0A08
_080C0F20:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C0F26:
	rsbs r0, r0, #0
	adds r1, r7, #0
	adds r1, #0x6e
	strh r0, [r1]
	ldr r1, _080C0F44 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x20]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C0F48
	asrs r0, r0, #0xc
	b _080C0F4E
	.align 2, 0
_080C0F44: .4byte 0x085B0A08
_080C0F48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C0F4E:
	rsbs r1, r0, #0
	adds r0, r7, #0
	adds r0, #0x70
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x72
	ldr r0, [sp, #0x24]
	strh r0, [r2]
	adds r1, r7, #0
	adds r1, #0x74
	ldr r0, [sp, #0x28]
	strh r0, [r1]
	ldrh r0, [r2]
	cmp r0, #0
	beq _080C0F84
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	ldr r1, _080C0F80 @ =Entity080c0fa0_UpdateDelay
	adds r0, r7, #0
	bl Entity080c0fa0_SetUpdateCallback
	b _080C0F8C
	.align 2, 0
_080C0F80: .4byte Entity080c0fa0_UpdateDelay
_080C0F84:
	ldr r1, _080C0F9C @ =Entity080c0fa0_UpdateActive
	adds r0, r7, #0
	bl Entity080c0fa0_SetUpdateCallback
_080C0F8C:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C0F9C: .4byte Entity080c0fa0_UpdateActive
