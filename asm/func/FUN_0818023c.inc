	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r0, _0818025C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08180260
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08180262
	.align 2, 0
_0818025C: .4byte 0x0000046D
_08180260:
	movs r0, #0
_08180262:
	cmp r0, #0
	beq _081802B4
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	asrs r1, r2, #0x10
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081802F4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r0, sp
	movs r1, #0
	bl Entity081f7de4_Spawn
	mov r0, sp
	movs r1, #0x80
	bl Entity081f7de4_Spawn
	adds r0, r5, #0
	movs r1, #0x10
	bl Enemy_PlayAnimNoFacing
	movs r2, #0x80
	lsls r2, r2, #0xd
	ldr r0, _081802F8 @ =0x00000898
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081802FC @ =0x000003CF
	bl PlaySound_082406e0
	ldr r0, _08180300 @ =0x000002D2
	bl PlaySound_082406e0
_081802B4:
	ldr r1, _08180304 @ =0x00000804
	adds r4, r6, r1
	adds r1, r5, #0
	adds r1, #8
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	ldr r1, _08180308 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081802EC
	bl Entity081f7de4_RemoveAll
	ldr r0, _081802F8 @ =0x00000898
	adds r2, r6, r0
	ldr r1, _0818030C @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _08180310 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_081802EC:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081802F4: .4byte 0x0000FFFF
_081802F8: .4byte 0x00000898
_081802FC: .4byte 0x000003CF
_08180300: .4byte 0x000002D2
_08180304: .4byte 0x00000804
_08180308: .4byte 0x0000046E
_0818030C: .4byte 0xFFEFFFFF
_08180310: .4byte 0x0000046B
