	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r1, #0
	str r1, [sp]
	movs r1, #0x64
	movs r2, #0xe
	movs r3, #0xc
	bl FUN_0808b30c
	movs r2, #0
	mov sb, r2
	ldr r0, _08098B64 @ =0x000021C4
	adds r0, r0, r6
	mov r8, r0
	ldr r1, _08098B68 @ =0x00002164
	adds r7, r6, r1
	movs r5, #0
	ldr r2, _08098B6C @ =0x00004004
	adds r4, r6, r2
_08098B2A:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r3, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08098B70
	movs r0, #0xd7
	lsls r0, r0, #2
	adds r1, r3, r0
	adds r1, r1, r5
	subs r2, #0xec
	adds r0, r3, r2
	adds r0, r0, r5
	ldrb r2, [r0]
	ldrb r1, [r1]
	adds r2, r2, r1
	movs r1, #0x9d
	lsls r1, r1, #2
	adds r0, r3, r1
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r0, r0, r2
	strb r0, [r4]
	b _08098B94
	.align 2, 0
_08098B64: .4byte 0x000021C4
_08098B68: .4byte 0x00002164
_08098B6C: .4byte 0x00004004
_08098B70:
	movs r0, #0xd7
	lsls r0, r0, #2
	adds r2, r3, r0
	adds r2, r2, r5
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r0, r3, r1
	adds r0, r0, r5
	ldrb r1, [r0]
	ldrb r2, [r2]
	adds r1, r1, r2
	movs r2, #0x9d
	lsls r2, r2, #2
	adds r0, r3, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	strb r1, [r4]
_08098B94:
	ldrb r0, [r4]
	cmp r0, #0x63
	bls _08098B9E
	movs r0, #0x63
	strb r0, [r4]
_08098B9E:
	ldrb r0, [r4]
	ldr r2, _08098BD8 @ =0x00004008
	adds r1, r6, r2
	add r1, sb
	ldrb r1, [r1]
	mov r2, r8
	str r2, [sp]
	adds r2, r6, #0
	adds r2, #0x60
	adds r3, r7, #0
	bl FUN_08098a98
	movs r0, #0xc0
	add r8, r0
	adds r7, #0xc0
	adds r5, #2
	adds r4, #1
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #3
	ble _08098B2A
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098BD8: .4byte 0x00004008
