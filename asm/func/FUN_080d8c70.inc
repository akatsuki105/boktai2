	push {lr}
	adds r3, r1, #0
	cmp r0, #5
	bhi _080D8CBC
	lsls r0, r0, #2
	ldr r1, _080D8C84 @ =_080D8C88
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D8C84: .4byte _080D8C88
_080D8C88: @ jump table
	.4byte _080D8CA0 @ case 0
	.4byte _080D8CAA @ case 1
	.4byte _080D8CB4 @ case 2
	.4byte _080D8CB4 @ case 3
	.4byte _080D8CAA @ case 4
	.4byte _080D8CAA @ case 5
_080D8CA0:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r3]
	subs r0, #0xb
	b _080D8CBA
_080D8CAA:
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r3]
	adds r0, #8
	b _080D8CBA
_080D8CB4:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r3]
_080D8CBA:
	str r0, [r2]
_080D8CBC:
	pop {r0}
	bx r0
