	push {r4, lr}
	adds r4, r0, #0
	subs r0, r1, #2
	cmp r0, #9
	bhi _0823D9E2
	lsls r0, r0, #2
	ldr r1, _0823D984 @ =_0823D988
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0823D984: .4byte _0823D988
_0823D988: @ jump table
	.4byte _0823D9B0 @ case 0
	.4byte _0823D9E2 @ case 1
	.4byte _0823D9DE @ case 2
	.4byte _0823D9E2 @ case 3
	.4byte _0823D9DE @ case 4
	.4byte _0823D9E2 @ case 5
	.4byte _0823D9E2 @ case 6
	.4byte _0823D9DE @ case 7
	.4byte _0823D9E2 @ case 8
	.4byte _0823D9DE @ case 9
_0823D9B0:
	adds r0, r4, #0
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0823D9C8
	adds r0, r4, #0
	movs r1, #0x64
	bl Mod
	cmp r0, #0
	bne _0823D9D6
_0823D9C8:
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r4, #0
	bl Mod
	cmp r0, #0
	bne _0823D9DA
_0823D9D6:
	movs r0, #0x1d
	b _0823D9E4
_0823D9DA:
	movs r0, #0x1c
	b _0823D9E4
_0823D9DE:
	movs r0, #0x1e
	b _0823D9E4
_0823D9E2:
	movs r0, #0x1f
_0823D9E4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
