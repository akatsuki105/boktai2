	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r1, _0808D0AC @ =0x0000FFFF
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r1, _0808D0B0 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r5, #0
	mov r8, r5
	movs r0, #0xaa
	lsls r0, r0, #4
	adds r4, r6, r0
	movs r7, #0
	ldr r3, _0808D0B4 @ =0x03003584
	mov sb, r3
_0808D04E:
	adds r1, r5, #0
	adds r1, #0xe
	lsls r1, r1, #0x13
	lsrs r1, r1, #0x10
	ldr r2, _0808D0B0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0x73
	ldr r3, _0808D0B8 @ =0x00010031
	bl MainSprite_Add
	mov r0, r8
	strh r0, [r4, #0x3a]
	ldr r3, _0808D0BC @ =0x00000AE8
	adds r2, r6, r3
	adds r2, r2, r7
	ldrh r1, [r4, #0x3a]
	lsls r1, r1, #5
	mov r3, sb
	ldr r0, [r3]
	adds r0, r0, r1
	str r0, [r2]
	adds r4, #0x60
	adds r7, #0x60
	adds r5, #1
	cmp r5, #1
	ble _0808D04E
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D0AC: .4byte 0x0000FFFF
_0808D0B0: .4byte 0xFFFF0000
_0808D0B4: .4byte 0x03003584
_0808D0B8: .4byte 0x00010031
_0808D0BC: .4byte 0x00000AE8
