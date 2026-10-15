	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r1, #2
	ldr r2, _081E3D00 @ =0x00001610
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E3D04
	movs r0, #1
	b _081E3D06
	.align 2, 0
_081E3D00: .4byte 0x00001610
_081E3D04:
	movs r0, #0
_081E3D06:
	cmp r0, #0
	beq _081E3D62
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r5, r7, r0
	ldr r0, [r5]
	ldr r1, _081E3D68 @ =0x000015F0
	adds r6, r7, r1
	ldr r1, [r6]
	bl TextPanel_SetScript
	ldr r0, [r5]
	movs r1, #0
	bl TextPanel_SetMessage
	ldr r2, _081E3D6C @ =0x00001604
	adds r4, r7, r2
	ldr r0, [r4]
	ldr r1, [r6]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #1
	bl TextPanel_SetMessage
	ldr r0, [r5]
	ldr r1, _081E3D70 @ =0x030046A0
	ldr r2, [r1]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	bl FUN_0804a40c
	ldr r0, [r4]
	ldr r1, _081E3D74 @ =0x00000BB8
	adds r2, r7, r1
	movs r1, #2
	bl FUN_0804a40c
	ldr r0, [r5]
	bl TextPanel_Start
	ldr r0, [r4]
	bl TextPanel_Start
_081E3D62:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E3D68: .4byte 0x000015F0
_081E3D6C: .4byte 0x00001604
_081E3D70: .4byte 0x030046A0
_081E3D74: .4byte 0x00000BB8
