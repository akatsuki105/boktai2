	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	adds r7, r1, #0
	str r2, [sp]
	movs r1, #0xa
	bl Mod
	mov sl, r0
	adds r0, r5, #0
	movs r1, #0x64
	bl Mod
	mov r1, sl
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	mov sb, r0
	movs r6, #0xfa
	lsls r6, r6, #2
	adds r0, r5, #0
	adds r1, r6, #0
	bl Mod
	mov r4, sl
	add r4, sb
	subs r0, r0, r4
	movs r1, #0x64
	bl Div
	mov r8, r0
	ldr r1, _0823DC3C @ =0x00002710
	adds r0, r5, #0
	bl Mod
	add r4, r8
	subs r0, r0, r4
	adds r1, r6, #0
	bl Div
	adds r4, r0, #0
	adds r0, r7, #0
	movs r1, #0xa
	bl Mod
	adds r6, r0, #0
	adds r0, r7, #0
	movs r1, #0x64
	bl Mod
	subs r0, r0, r6
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	ldr r0, [sp]
	movs r1, #0xa
	bl Mod
	adds r7, r0, #0
	ldr r0, [sp]
	movs r1, #0x64
	bl Mod
	subs r0, r0, r7
	movs r1, #0xa
	bl Div
	lsls r4, r4, #0x1c
	mov r1, r8
	lsls r1, r1, #0x18
	orrs r4, r1
	mov r1, sb
	lsls r1, r1, #0x14
	orrs r4, r1
	mov r1, sl
	lsls r1, r1, #0x10
	orrs r4, r1
	lsls r5, r5, #0xc
	orrs r4, r5
	lsls r6, r6, #8
	orrs r4, r6
	lsls r0, r0, #4
	orrs r4, r0
	orrs r4, r7
	adds r0, r4, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823DC3C: .4byte 0x00002710
