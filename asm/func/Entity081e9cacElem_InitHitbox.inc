	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	adds r5, r7, #0
	adds r5, #0x14
	ldr r2, _081E8F14 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _081E8F18 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa4
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r4, #0
	str r4, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	adds r0, r7, #0
	adds r0, #0xea
	ldrh r1, [r0]
	ldr r2, _081E8F1C @ =0x00002301
	str r4, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r0, _081E8F20 @ =0x00004010
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0x10
	bl Hitbox_SetAttack
	adds r1, r7, #0
	adds r1, #0x80
	adds r0, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _081E8F24 @ =Entity081e9cacElem_OnHit
	adds r0, r5, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	ldrb r1, [r7, #2]
	adds r0, r7, #0
	adds r0, #0x56
	strb r1, [r0]
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E8F14: .4byte 0xFFFF0000
_081E8F18: .4byte 0x0000FFFF
_081E8F1C: .4byte 0x00002301
_081E8F20: .4byte 0x00004010
_081E8F24: .4byte Entity081e9cacElem_OnHit
