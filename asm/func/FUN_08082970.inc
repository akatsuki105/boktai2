	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x12
	beq _08082998
	ldr r0, _080829AC @ =0x00000366
	bl sound_08240740
	ldr r0, _080829B0 @ =0x0000036F
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #0
	bl FUN_08080e0c
_08082998:
	ldr r3, _080829B4 @ =0x0000037D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #1
	beq _08082A20
	cmp r0, #1
	bgt _080829B8
	cmp r0, #0
	beq _080829BE
	b _08082A88
	.align 2, 0
_080829AC: .4byte 0x00000366
_080829B0: .4byte 0x0000036F
_080829B4: .4byte 0x0000037D
_080829B8:
	cmp r0, #2
	beq _08082A70
	b _08082A88
_080829BE:
	movs r1, #0xf9
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08082A88
	movs r6, #0x99
	lsls r6, r6, #4
	adds r1, r5, r6
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08082A14 @ =0x0000098C
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldr r3, _08082A18 @ =0x00000474
	adds r2, r5, r3
	str r2, [sp]
	ldr r6, _08082A1C @ =0x00000472
	adds r2, r5, r6
	movs r3, #0
	ldrsh r2, [r2, r3]
	str r2, [sp, #4]
	movs r2, #0x96
	lsls r2, r2, #1
	str r2, [sp, #8]
	adds r2, #0x50
	str r2, [sp, #0xc]
	movs r2, #1
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #1
	bl FUN_08080e0c
	b _08082A88
	.align 2, 0
_08082A14: .4byte 0x0000098C
_08082A18: .4byte 0x00000474
_08082A1C: .4byte 0x00000472
_08082A20:
	ldr r6, _08082A68 @ =0x00000474
	adds r1, r5, r6
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _08082A88
	ldr r0, _08082A6C @ =0x0000098C
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	movs r6, #0x99
	lsls r6, r6, #4
	adds r2, r5, r6
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	movs r3, #0x96
	lsls r3, r3, #1
	str r3, [sp, #8]
	adds r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #2
	bl FUN_08080e0c
	b _08082A88
	.align 2, 0
_08082A68: .4byte 0x00000474
_08082A6C: .4byte 0x0000098C
_08082A70:
	ldr r1, _08082A90 @ =0x000001F7
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08082A88
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08082A88:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08082A90: .4byte 0x000001F7
