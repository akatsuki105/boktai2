	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	str r1, [r5, #0x18]
	movs r2, #0
	strh r2, [r5, #0x1c]
	adds r0, #0x54
	strh r2, [r0]
	ldr r0, _0823CBB4 @ =0x030046A0
	ldr r1, [r0]
	ldrh r0, [r1, #0x30]
	adds r4, r5, #0
	adds r4, #0x58
	strh r0, [r4]
	ldrh r0, [r1, #0x32]
	adds r0, #0x96
	movs r3, #0x5a
	adds r3, r3, r5
	mov ip, r3
	strh r0, [r3]
	ldrh r0, [r1, #0x34]
	adds r3, r5, #0
	adds r3, #0x5c
	strh r0, [r3]
	adds r0, r5, #0
	adds r0, #0x8c
	strh r2, [r0]
	ldr r1, _0823CBB8 @ =0x03003540
	ldrh r2, [r4]
	strh r2, [r1]
	mov r4, ip
	ldrh r0, [r4]
	strh r0, [r1, #2]
	ldrh r0, [r3]
	strh r0, [r1, #4]
	ldr r6, _0823CBBC @ =0x030047C8
	adds r7, r1, #0
	lsls r2, r2, #0x10
	asrs r3, r2, #0x11
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	mov r8, r7
	mov ip, r6
	cmp r0, #0
	blt _0823CBC0
	asrs r0, r0, #8
	b _0823CBC6
	.align 2, 0
_0823CBB4: .4byte 0x030046A0
_0823CBB8: .4byte 0x03003540
_0823CBBC: .4byte 0x030047C8
_0823CBC0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823CBC6:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823CBD8
	asrs r0, r0, #8
	b _0823CBDE
_0823CBD8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823CBDE:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r7, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0823CBF2
	asrs r3, r0, #8
	b _0823CBF8
_0823CBF2:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r3, r0, #0
_0823CBF8:
	subs r0, r4, r3
	movs r2, #0
	movs r1, #0
	strh r0, [r6, #2]
	adds r0, r4, r3
	strh r0, [r6, #4]
	adds r0, r5, #0
	adds r0, #0x84
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	subs r0, #0xa
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	mov r6, ip
	mov r4, r8
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823CC46
	asrs r0, r0, #8
	b _0823CC4C
_0823CC46:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823CC4C:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823CC5E
	asrs r0, r0, #8
	b _0823CC64
_0823CC5E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823CC64:
	adds r2, r0, #0
	movs r3, #2
	ldrsh r1, [r4, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0823CC78
	asrs r1, r0, #8
	b _0823CC7E
_0823CC78:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0823CC7E:
	subs r0, r2, r1
	strh r0, [r6, #2]
	adds r0, r2, r1
	strh r0, [r6, #4]
	ldr r0, _0823CCB0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0823CCA0
	adds r0, r5, #0
	adds r0, #0x20
	ldr r1, [r5, #0x18]
	movs r2, #6
	bl FUN_080223f4
_0823CCA0:
	ldr r0, _0823CCB4 @ =gCamera
	str r5, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823CCB0: .4byte 0x030047A4
_0823CCB4: .4byte gCamera
