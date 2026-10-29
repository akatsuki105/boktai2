	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov sb, r0
	mov ip, r1
	mov r8, r2
	mov r5, sp
	mov r6, ip
	adds r6, #0xc
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805FC6A
	asrs r0, r0, #8
	b _0805FC70
_0805FC6A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805FC70:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805FC82
	asrs r0, r0, #8
	b _0805FC88
_0805FC82:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805FC88:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0805FC9C
	asrs r0, r0, #8
	b _0805FCA2
_0805FC9C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805FCA2:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0805FCF0 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	mov r2, ip
	adds r2, #0x14
	movs r4, #0
	mov r1, ip
	ldrb r0, [r1, #7]
	cmp r4, r0
	bge _0805FD16
	mov r5, sp
	ldr r7, _0805FCF4 @ =0x085ABA88
	ldr r6, _0805FCF8 @ =0x085B0AC8
	ldrh r3, [r5]
_0805FCD6:
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	subs r0, r3, r0
	strh r0, [r2, #0x18]
	movs r1, #0
	ldrsh r0, [r6, r1]
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805FCFC
	asrs r1, r0, #0xc
	b _0805FD02
	.align 2, 0
_0805FCF0: .4byte 0x030047C8
_0805FCF4: .4byte 0x085ABA88
_0805FCF8: .4byte 0x085B0AC8
_0805FCFC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805FD02:
	ldrh r0, [r5, #2]
	subs r0, r0, r1
	strh r0, [r2, #0x1a]
	subs r3, #5
	adds r4, #1
	adds r2, #0x28
	mov r1, ip
	ldrb r0, [r1, #7]
	cmp r4, r0
	blt _0805FCD6
_0805FD16:
	mov r1, ip
	ldrb r0, [r1, #5]
	adds r0, #1
	strb r0, [r1, #5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0805FD2E
	mov r0, sb
	mov r1, r8
	bl DamageNumberManager_ReleaseSlot
_0805FD2E:
	movs r0, #0
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
