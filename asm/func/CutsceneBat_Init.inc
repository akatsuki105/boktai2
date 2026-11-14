	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r7, r1, #0
	movs r1, #0
	movs r6, #0
	strb r1, [r7, #1]
	movs r0, #1
	strb r0, [r7]
	strh r6, [r7, #4]
	strb r1, [r7, #6]
	adds r4, r7, #0
	adds r4, #0x6c
	ldr r1, _08011844 @ =0x0000DA6D
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	ldr r1, _08011848 @ =0x00000263
	bl Video_SetAuxSpritePltt
	ldr r0, _0801184C @ =0x00000CA8
	adds r5, r5, r0
	str r5, [r4, #0xc]
	adds r5, r7, #0
	adds r5, #0x40
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl AuxSprite_Add
	movs r0, #2
	strb r0, [r5, #7]
	adds r5, #0x1c
	str r6, [sp]
	mov r0, sp
	adds r1, r5, #0
	ldr r2, _08011850 @ =0x05000002
	bl CpuSet
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl ParticleShadow_Hide
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08011844: .4byte 0x0000DA6D
_08011848: .4byte 0x00000263
_0801184C: .4byte 0x00000CA8
_08011850: .4byte 0x05000002
