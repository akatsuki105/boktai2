	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	movs r3, #0
	ldrh r0, [r4, #0x1a]
	cmp r3, r0
	bge _0801FDDA
	ldr r7, _0801FDE8 @ =0x0000042C
	adds r6, r4, r7
	movs r0, #1
	mov r8, r0
	movs r5, #0
	ldr r7, _0801FDEC @ =FUN_080206b4
	mov ip, r7
	movs r1, #0
_0801FDB0:
	ldr r0, [r6]
	adds r2, r0, r1
	ldrh r0, [r2, #0x34]
	cmp r0, sb
	bne _0801FDD0
	adds r0, r2, #0
	adds r0, #0x37
	mov r7, r8
	strb r7, [r0]
	mov r0, ip
	str r0, [r2, #0x30]
	adds r0, r2, #0
	adds r0, #0x39
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
_0801FDD0:
	adds r1, #0x8c
	adds r3, #1
	ldrh r7, [r4, #0x1a]
	cmp r3, r7
	blt _0801FDB0
_0801FDDA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FDE8: .4byte 0x0000042C
_0801FDEC: .4byte FUN_080206b4
