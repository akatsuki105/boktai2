	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AF110 @ =0x00001336
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080AF1EC
	lsls r0, r0, #2
	ldr r1, _080AF114 @ =_080AF118
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080AF110: .4byte 0x00001336
_080AF114: .4byte _080AF118
_080AF118: @ jump table
	.4byte _080AF130 @ case 0
	.4byte _080AF14C @ case 1
	.4byte _080AF158 @ case 2
	.4byte _080AF180 @ case 3
	.4byte _080AF198 @ case 4
	.4byte _080AF1C0 @ case 5
_080AF130:
	ldr r2, _080AF140 @ =0x0000135C
	adds r1, r4, r2
	ldr r0, _080AF144 @ =FUN_080ae928
	str r0, [r1]
	ldr r0, _080AF148 @ =0x0000134A
	adds r1, r4, r0
	b _080AF170
	.align 2, 0
_080AF140: .4byte 0x0000135C
_080AF144: .4byte FUN_080ae928
_080AF148: .4byte 0x0000134A
_080AF14C:
	ldr r2, _080AF154 @ =0x0000135C
	adds r1, r4, r2
	b _080AF1F0
	.align 2, 0
_080AF154: .4byte 0x0000135C
_080AF158:
	bl FUN_0805d79c
	movs r2, #0x9b
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
	ldr r0, _080AF178 @ =0x0000135C
	adds r1, r4, r0
	ldr r0, _080AF17C @ =FUN_080aead8
	str r0, [r1]
	subs r2, #0x16
	adds r1, r4, r2
_080AF170:
	movs r0, #0xb4
	lsls r0, r0, #1
	strh r0, [r1]
	b _080AF1F4
	.align 2, 0
_080AF178: .4byte 0x0000135C
_080AF17C: .4byte FUN_080aead8
_080AF180:
	ldr r0, _080AF18C @ =0x0000135C
	adds r1, r4, r0
	ldr r0, _080AF190 @ =FUN_080aeb98
	str r0, [r1]
	ldr r2, _080AF194 @ =0x0000134A
	b _080AF1D8
	.align 2, 0
_080AF18C: .4byte 0x0000135C
_080AF190: .4byte FUN_080aeb98
_080AF194: .4byte 0x0000134A
_080AF198:
	ldr r1, _080AF1B4 @ =0x0000134E
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0x32
	bl FUN_0805b068
	movs r2, #0x9b
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
	ldr r0, _080AF1B8 @ =0x0000135C
	adds r1, r4, r0
	ldr r0, _080AF1BC @ =FUN_080aee18
	b _080AF1D4
	.align 2, 0
_080AF1B4: .4byte 0x0000134E
_080AF1B8: .4byte 0x0000135C
_080AF1BC: .4byte FUN_080aee18
_080AF1C0:
	movs r0, #0x5a
	bl Entity0805f2dc_Create
	movs r2, #0x9b
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
	ldr r0, _080AF1E4 @ =0x0000135C
	adds r1, r4, r0
	ldr r0, _080AF1E8 @ =FUN_080aefe8
_080AF1D4:
	str r0, [r1]
	subs r2, #0x16
_080AF1D8:
	adds r1, r4, r2
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	b _080AF1F4
	.align 2, 0
_080AF1E4: .4byte 0x0000135C
_080AF1E8: .4byte FUN_080aefe8
_080AF1EC:
	ldr r0, _080AF1FC @ =0x0000135C
	adds r1, r4, r0
_080AF1F0:
	movs r0, #0
	str r0, [r1]
_080AF1F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AF1FC: .4byte 0x0000135C
