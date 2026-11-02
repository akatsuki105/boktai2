	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0xe7
	lsls r0, r0, #2
	adds r6, r5, r0
	ldr r1, _081E0064 @ =0x0000A47C
	adds r0, r6, #0
	bl Video_GetAuxSprite
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r4, r5, r1
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r2, #0
	movs r3, #0
	strh r2, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #0x11
	orrs r0, r1
	str r0, [r4]
	ldr r1, _081E0068 @ =0x00000377
	adds r0, r5, r1
	strb r3, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r4, r5, r0
	str r2, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081E006C @ =0x05000002
	bl CpuSet
	movs r0, #0x79
	strh r0, [r4]
	ldr r1, _081E0070 @ =0x0000038E
	adds r5, r5, r1
	movs r0, #0x40
	strh r0, [r5]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E0064: .4byte 0x0000A47C
_081E0068: .4byte 0x00000377
_081E006C: .4byte 0x05000002
_081E0070: .4byte 0x0000038E
